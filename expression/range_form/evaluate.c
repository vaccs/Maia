
#include <assert.h>

#include <debug.h>

#include "../evaluate.h"

#include "struct.h"
#include "evaluate.h"

struct value* range_form_expression_evaluate(
	struct expression* super,
	struct scope* scope)
{
	ENTER;
	
	TODO;
	#if 0
	assert(super->kind == ek_range_form);
	
	struct range_form_expression* this = (void*) super;
	
	struct value* result = expression_evaluate(this->expression, scope);
	
	EXIT;
	return result;
	#endif
}