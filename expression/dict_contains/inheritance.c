
#include <debug.h>

#include "inheritance.h"
#include "print_source.h"
#include "evaluate.h"
#include "print.h"
#include "free.h"

struct expression_inheritance dict_contains_expression_inheritance = {
	.print_source = dict_contains_expression_print_source,
	.evaluate = dict_contains_expression_evaluate,
	.print = dict_contains_expression_print,
	.free = free_dict_contains_expression,
};

