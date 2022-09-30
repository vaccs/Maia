
#include <debug.h>

#include <gegex/nfa_to_dfa.h>
#include <gegex/simplify_dfa.h>
#include <gegex/combine_structinfos.h>
#include <gegex/free.h>

#include <yacc/structinfo/free.h>

#include <named/grammar/new.h>

#include <named/type/new.h>

#include <type_cache/get_type/grammar.h>
#include <type_cache/get_type/list.h>

#include <type/free.h>

#include "grammar/3.root.h"

#include "parse.h"
#include "grammar.h"

void process_grammar(
	struct lex* lex,
	struct avl_tree_t* grammar,
	struct avl_tree_t* types,
	struct avl_tree_t* declares,
	struct type_cache* tcache,
	struct zebu_grammar_rule* rule)
{
	ENTER;
	
	assert(rule->grammar);
	
	struct string* name = new_string_from_token(rule->name);
	
	dpvs(name);
	
	if (avl_search(grammar, &name) || avl_search(declares, &name))
	{
		TODO;
		exit(1);
	}
	
	struct gbundle nfa = read_grammar_root(lex, rule->grammar);
	
	struct gegex* dfa = gegex_nfa_to_dfa(nfa);
	
	struct gegex* simp = gegex_simplify_dfa(dfa);
	
	struct structinfo* structinfo = gegex_combine_structinfos(simp);
	
	struct type* type = type_cache_get_grammar_type(tcache, structinfo);
	
	struct type* list = type_cache_get_list_type(tcache, type);
	
	avl_insert(grammar, new_named_grammar(name, simp));
	
	avl_insert(types, new_named_type(name, list));
	
	free_structinfo(structinfo);
	
	free_gegex(nfa.start);
	
	free_string(name);
	
	free_gegex(dfa);
	
	free_type(list);
	
	free_type(type);
	
	EXIT;
}













