
#include <debug.h>

#include <quack/new.h>
#include <quack/append.h>
#include <quack/pop.h>
#include <quack/is_nonempty.h>
#include <quack/free.h>

#include <regex/struct.h>
#include <regex/new.h>

#include <set/ptr/new.h>
#include <set/ptr/add.h>
#include <set/ptr/foreach.h>
#include <set/ptr/compare.h>
#include <set/ptr/inc.h>
#include <set/ptr/is_nonempty.h>
#include <set/ptr/free.h>

#include "nfa_to_dfa.h"

struct mapping
{
	struct ptrset* stateset; // must be the first
	
	struct regex* combined_state;
};

static struct mapping* new_mapping(
	struct ptrset* stateset,
	struct regex* state)
{
	ENTER;
	
	struct mapping* this = smalloc(sizeof(*this));
	
	this->stateset = inc_ptrset(stateset);
	
	this->combined_state = state;
	
	EXIT;
	return this;
}

static int compare_mappings(const void* a, const void* b)
{
	const struct mapping *A = a, *B = b;
	
	return compare_ptrsets(A->stateset, B->stateset);
}

static void free_mapping(void* a)
{
	struct mapping* this = a;
	ENTER;
	
	free_ptrset(this->stateset);
	
	free(this);
	
	EXIT;
}

static void add_lambda_states(struct ptrset* set, struct regex* ele)
{
	ENTER;
	
	if (ptrset_add(set, ele))
	{
		for (unsigned i = 0, n = ele->lambdas.n; i < n; i++)
		{
			add_lambda_states(set, ele->lambdas.data[i]);
		}
	}
	
	EXIT;
}

struct regex* regex_nfa_to_dfa(struct rbundle nfa)
{
	ENTER;
	
	nfa.accept->accepts = true;
	
	struct quack* todo = new_quack();
	
	struct avl_tree_t* mappings = avl_alloc_tree(compare_mappings, free_mapping);
	
	struct regex* new_start = new_regex();
	
	{
		struct ptrset* start_set = new_ptrset();
		
		add_lambda_states(start_set, nfa.start);
		
		struct mapping* mapping = new_mapping(start_set, new_start);
		
		quack_append(todo, mapping);
		
		avl_insert(mappings, mapping);
		
		free_ptrset(start_set);
	}
	
	while (quack_is_nonempty(todo))
	{
		struct mapping* const mapping = quack_pop(todo);
		
		struct ptrset* const stateset = mapping->stateset;
		
		struct regex* const state = mapping->combined_state;
		
		// set this as accepting if any states in list are accepting:
		{
			bool accepts = false;
			
			ptrset_foreach(stateset, ({
				void runme(void* ptr) {
					struct regex* ele = ptr;
					if (ele->accepts) {
						accepts = true;
					}
				}
				runme;
			}));
			
			state->accepts = accepts;
			
			dpvb(accepts);
		}
		
		for (unsigned i = 0, n = 256; i < n; i++)
		{
			struct ptrset* subptrset = new_ptrset();
			
			ptrset_foreach(stateset, ({
				void runme(void* ptr)
				{
					struct regex* const ele = ptr;
					struct regex* const to = ele->transitions[i];
					if (to) add_lambda_states(subptrset, to);
				}
				runme;
			}));
			
			if (ptrset_is_nonempty(subptrset))
			{
				struct avl_node_t* node = avl_search(mappings, &subptrset);
				
				if (node)
				{
					struct mapping* old = node->item;
					
					state->transitions[i] = old->combined_state;
				}
				else
				{
					struct regex* substate = new_regex();
					
					struct mapping* new = new_mapping(subptrset, substate);
					
					state->transitions[i] = substate;
					
					quack_append(todo, new);
					
					avl_insert(mappings, new);
				}
			}
			
			free_ptrset(subptrset);
		}
		
		// EOF transitions?
		{
			struct ptrset* subptrset = new_ptrset();
			
			ptrset_foreach(stateset, ({
				void runme(void* ptr)
				{
					struct regex* const ele = ptr;
					struct regex* const to = ele->EOF_transition_to;
					if (to) add_lambda_states(subptrset, to);
				}
				runme;
			}));
			
			if (ptrset_is_nonempty(subptrset))
			{
				TODO;
				#if 0
				struct avl_node_t* node = avl_search(mappings, &subptrset);
				
				if (node)
				{
					struct mapping* old = node->item;
					
					state->EOF_transition_to = old->combined_state;
				}
				else
				{
					struct regex* substate = new_regex();
					
					struct mapping* new = new_mapping(subptrset, substate);
					
					state->EOF_transition_to = substate;
					
					quack_append(todo, new);
					
					avl_insert(mappings, new);
				}
				#endif
			}
			
			free_ptrset(subptrset);
		}
	}
	
	avl_free_tree(mappings);
	
	free_quack(todo);
	
	EXIT;
	return new_start;
}


