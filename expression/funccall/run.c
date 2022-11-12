
#include <assert.h>

#include <debug.h>

#include <scope/new.h>
#include <scope/declare.h>
#include <scope/free.h>

#include <parameter/struct.h>

#include <value/lambda/struct.h>

#include <list/parameter/struct.h>

#include <list/value/struct.h>

#include <expression/evaluate.h>

/*#include "struct.h"*/
#include "run.h"

struct value* funccall_run(
	struct lambda_value* lambda,
	struct value_list* arguments)
{
	ENTER;
	
	struct scope* scope = new_scope(lambda->captured);
	
	assert(lambda->parameters->n == arguments->n);
	
	for (unsigned i = 0, n = arguments->n; i < n; i++)
	{
		struct parameter* parameter = lambda->parameters->data[i];
		struct value* value = arguments->data[i];
		
		assert(parameter->type == value->type);
		
		scope_declare(scope, parameter->name, value);
	}
	
	// evaluate inner expression
	struct value* retval = expression_evaluate(lambda->body, scope);
	
	free_scope(scope);
	
	EXIT;
	return retval;
}














