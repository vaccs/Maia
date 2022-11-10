
#include <debug.h>

#include "inheritance.h"
#include "generate_typedef.h"
#include "generate_new_func.h"
#include "generate_free_func.h"
#include "compare.h"
#include "print.h"
#include "free.h"

struct type_inheritance dict_type_inheritance = {
	.generate_typedef = dict_type_generate_typedef,
	.generate_new_func = dict_type_generate_new_func,
	.generate_free_func = dict_type_generate_free_func,
	.compare = compare_dict_type,
	.print = dict_type_print,
	.free = free_dict_type,
};
