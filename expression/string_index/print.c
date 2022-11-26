
#include <stdio.h>
#include <assert.h>

#include <debug.h>

#include <stringtree/append_printf.h>
#include <stringtree/append_tree.h>
#include <stringtree/free.h>

#include "../print.h"

#include "struct.h"
#include "print.h"

struct stringtree* string_index_expression_print(
	struct expression* super)
{
	ENTER;
	
	assert(super->kind == ek_string_index);
	
	struct string_index_expression* this = (void*) super;
	
	struct stringtree* tree = expression_print2(this->string);
	
	stringtree_append_printf(tree, "[");
	
	struct stringtree* subtree = expression_print2(this->index);
	
	stringtree_append_tree(tree, subtree);
	
	stringtree_append_printf(tree, "]");
	
	free_stringtree(subtree);
	
	EXIT;
	return tree;
}

