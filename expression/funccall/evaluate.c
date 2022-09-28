
#include <debug.h>

/*#include <value/struct.h>*/
/*#include <value/integer/new.h>*/
/*#include <value/free.h>*/

/*#include <mpz/add.h>*/
/*#include <mpz/subtract.h>*/
/*#include <mpz/multiply.h>*/
/*#include <mpz/free.h>*/

#include "../evaluate.h"

#include "struct.h"
#include "evaluate.h"

struct value* funccall_expression_evaluate(
	struct expression* super,
	struct scope* scope)
{
	ENTER;
	
	struct funccall_expression* this = (void*) super;
	
	TODO;
	#if 0
	struct value* funccall = expression_evaluate(this->funccall, scope);
	
	assert(funccall->kind == vk_funccall);
	
	struct funccall_value* spef_funccall = (void*) spef_funccall;
	
	struct mpz* number;
	
	switch (this->kind)
	{
		case imek_add:
			number = new_mpz_from_add(spef_left->integer, spef_right->integer);
			break;
		
		case imek_subtract:
			number = new_mpz_from_subtract(spef_left->integer, spef_right->integer);
			break;
		
		case imek_multiply:
			number = new_mpz_from_multiply(spef_left->integer, spef_right->integer);
			break;
	}
	
	struct value* value = new_integer_value(super->type, number);
	
	free_value(left), free_value(right);
	
	free_mpz(number);
	
	EXIT;
	return value;
	#endif
}













