
#include <debug.h>

#include <parse/parse.h>

#include "exclusive_or.h"
#include "inclusive_or.h"

struct expression* specialize_inclusive_or_expression(
	struct type_cache* tcache,
	struct zebu_inclusive_or_expression* zexpression)
{
	struct expression* retval;
	ENTER;
	
	if (zexpression->base)
	{
		retval = specialize_exclusive_or_expression(tcache, zexpression->base);
	}
	else if (zexpression->left)
	{
		TODO;
	}
	else
	{
		TODO;
	}
	
	EXIT;
	return retval;
}
