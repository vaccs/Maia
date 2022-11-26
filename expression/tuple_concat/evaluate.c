
#include <assert.h>

#include <debug.h>

#include <value/struct.h>
#include <value/free.h>

#include "../evaluate.h"

#include "run.h"
#include "struct.h"
#include "evaluate.h"

struct value* tuple_concat_expression_evaluate(
	struct type_cache* tcache,
	struct expression* super,
	struct value* environment)
{
	ENTER;
	
	struct tuple_concat_expression* this = (void*) super;
	
	struct value* left = expression_evaluate(tcache, this->left, environment);
	
	struct value* right = expression_evaluate(tcache, this->right, environment);
	
	assert(left->kind == vk_tuple);
	
	assert(right->kind == vk_tuple);
	
	struct value* value = tuple_concat_run(
		super->type,
		(struct tuple_value*) left,
		(struct tuple_value*) right);
	
	free_value(left);
	
	free_value(right);
	
	EXIT;
	return value;
}













