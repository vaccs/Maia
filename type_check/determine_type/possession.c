
#include <assert.h>

#include <debug.h>

#include <parse/parse.h>

#include "inclusion.h"
#include "possession.h"

struct type* determine_type_of_possession_expression(
	struct zebu_possession_expression* expression,
	struct type_cache* tcache,
	struct avl_tree_t* grammar_types,
	struct avl_tree_t* name_to_type)
{
	struct type* type;
	ENTER;
	
	if (expression->has)
	{
		TODO;
	}
	else
	{
		type = determine_type_of_inclusion_expression(expression->base, tcache, grammar_types, name_to_type);
	}
	
	EXIT;
	return type;
}

