
#include <stdbool.h>
#include <stdio.h>
#include <assert.h>

#include <debug.h>

#include <list/expression/foreach.h>

#include <stringtree/new.h>
#include <stringtree/append_printf.h>
#include <stringtree/append_tree.h>
#include <stringtree/free.h>

#include "../print.h"

#include "struct.h"
#include "print.h"

struct stringtree* set_init_expression_print(
	struct expression* super)
{
	ENTER;
	
	assert(super->kind == ek_set_init);
	
	struct stringtree* tree = new_stringtree();
	
	struct set_init_expression* this = (void*) super;
	
	stringtree_append_printf(tree, "{");
	
	bool first = true;
	
	expression_list_foreach(this->elements, ({
		void runme(struct expression* element)
		{
			if (first)
				first = false;
			else
				stringtree_append_printf(tree, ", ");
			
			struct stringtree* subtree = expression_print2(element);
			
			stringtree_append_tree(tree, subtree);
			
			free_stringtree(subtree);
		}
		runme;
	}));
	
	if (first)
	{
		TODO;
	}
	
	stringtree_append_printf(tree, "}");
	
	EXIT;
	return tree;
}
















