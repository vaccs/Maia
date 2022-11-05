
#include <debug.h>

#include <parse/parse.h>

#include "implication.h"
#include "conditional.h"

struct type* determine_type_of_conditional_expression(
	struct zebu_conditional_expression* expression,
	struct type_cache* tcache,
	struct avl_tree_t* grammar_types,
	struct avl_tree_t* name_to_type)
{
	struct type* type;
	ENTER;
	
	if (expression->true_case)
	{
		TODO;
	}
	else
	{
		type = determine_type_of_implication_expression(expression->base, tcache, grammar_types, name_to_type);
	}
	
	EXIT;
	return type;
}
