
#include <assert.h>

#include <debug.h>

/*#include <scope/lookup.h>*/

#include "struct.h"
#include "evaluate.h"

struct value* implication_expression_evaluate(
	struct type_cache* tcache,
	struct expression* super,
	struct value* environment)
{
	ENTER;
	
	TODO;
	#if 0
	struct implication_expression* this = (void*) super;
	
	struct value* value = scope_lookup(scope, this->name);
	
	EXIT;
	return value;
	#endif
}
