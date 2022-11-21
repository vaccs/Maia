
#include <debug.h>

#include <expression/free.h>

#include "struct.h"
#include "free.h"

void free_list_sublist_expression(
	struct expression* super)
{
	ENTER;
	
	struct list_sublist_expression* this = (void*) super;
	
	free_expression(this->list);
	
	free_expression(this->startindex);
	
	free_expression(this->endindex);
	
	EXIT;
}

