
#include <assert.h>
#include <debug.h>

/*#include <expression/inc.h>*/

/*#include <type_cache/get_type/int.h>*/

/*#include <type/free.h>*/

#include <list/expression/inc.h>

#include "../new.h"
#include "../inc.h"

#include "inheritance.h"
#include "struct.h"
#include "new.h"

struct expression* new_reduce_form_expression(
	struct type* type,
	struct expression* lambda,
	struct expression* list,
	struct expression* initial)
{
	ENTER;
	
	TODO;
	#if 0
	struct reduce_form_expression* this = (void*) new_expression(
		ek_reduce_form,
		&reduce_form_expression_inheritance,
		type,
		sizeof(*this));
	
	this->lambda = inc_expression(lambda);
	
	this->arguments = inc_expression_list(arguments);
	
	EXIT;
	return (void*) this;
	#endif
}

