
#include <stdlib.h>

#include <assert.h>

#include <debug.h>

#include <defines/argv0.h>

#include <parse/parse.h>

#include <type/struct.h>
#include <type/print.h>

#include <expression/struct.h>
#include <expression/free.h>
#include <expression/print.h>

#include <expression/ternary/new.h>

#include "expression.h"
#include "implication.h"
#include "conditional.h"

struct expression* specialize_conditional_expression(
	struct type_cache* tcache,
	struct specialize_shared *sshared,
	struct zebu_conditional_expression* zexpression)
{
	struct expression* retval;
	ENTER;
	
	if (zexpression->qmark)
	{
		struct expression* conditional = specialize_implication_expression(tcache, sshared, zexpression->base);
		
		if (conditional->type->kind != tk_bool)
		{
			TODO;
			exit(1);
		}
		
		struct expression* true_case = specialize_expression(tcache, sshared, zexpression->true_case);
		
		struct expression* false_case = specialize_conditional_expression(tcache, sshared, zexpression->false_case);
		
		if (true_case->type != false_case->type)
		{
			fprintf(stderr, ""
				"%s: incompatiable data types in true and false case of ternary:"
				"\n\t("
			"", argv0);
			
			type_print(true_case->type);
			printf(") ");
			expression_print(true_case), printf(" and \n\t(");
			type_print(false_case->type);
			printf(") ");
			expression_print(false_case), puts(".");
			
			exit(1);
		}
		
		if (conditional->kind == ek_literal)
		{
			TODO;
		}
		else
		{
			retval = new_ternary_expression(true_case->type, conditional, true_case, false_case);
		}
		
		free_expression(conditional);
		free_expression(true_case);
		free_expression(false_case);
	}
	else
	{
		retval = specialize_implication_expression(tcache, sshared, zexpression->base);
	}
	
	EXIT;
	return retval;
}













