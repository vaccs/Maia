
#include <debug.h>

#include <expression/inc.h>

#include <type_cache/get_type/int.h>

#include <type/free.h>

#include "../new.h"

#include "inheritance.h"
#include "struct.h"
#include "new.h"

struct expression* new_len_form_expression(
	struct type_cache* tcache,
	struct expression* object)
{
	ENTER;
	
	struct type* type = type_cache_get_int_type(tcache);
	
	struct len_form_expression* this = (void*) new_expression(
		ek_len_form,
		&len_form_expression_inheritance,
		type,
		sizeof(*this));
	
	this->object = inc_expression(object);
	
	EXIT;
	return (void*) this;
}

