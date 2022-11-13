
#include <debug.h>

#include <expression/free.h>

#include "struct.h"
#include "free.h"

void free_list_contains_expression(
	struct expression* super)
{
	struct list_contains_expression* const this = (void*) super;
	ENTER;
	
	free_expression(this->element);
	
	free_expression(this->list);
	
	EXIT;
}

