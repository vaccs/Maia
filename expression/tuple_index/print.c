
#include <stdio.h>
#include <assert.h>

#include <debug.h>

#include "../print.h"

#include "struct.h"
#include "print.h"

void tuple_index_expression_print(
	struct expression* super)
{
	ENTER;
	
	TODO;
	#if 0
	assert(super->kind == ek_tuple_index);
	
	struct tuple_index_expression* this = (void*) super;
	
	expression_print(this->list);
	
	printf("[");
	
	expression_print(this->index);
	
	printf("]");
	#endif
	
	EXIT;
}
