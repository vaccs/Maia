
#include <assert.h>

#include <debug.h>

#include <parse/parse.h>

#include <type_cache/get_bool_type.h>

#include "inclusive_or.h"
#include "logical_and.h"

struct type* determine_type_of_logical_and_expression(
	struct zebu_logical_and_expression* expression,
	struct type_cache* tcache,
	struct type_check_scope* scope)
{
	struct type* type;
	ENTER;
	
	if (expression->left)
	{
		type = type_cache_get_bool_type(tcache);
	}
	else
	{
		type = determine_type_of_inclusive_or_expression(expression->base, tcache, scope);
	}
	
	EXIT;
	return type;
}

