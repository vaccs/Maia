
#include <assert.h>

#include <debug.h>

#include <stringtree/new.h>
#include <stringtree/append_printf.h>

#include "struct.h"
#include "generate_new_func.h"

struct stringtree* char_type_generate_new_func(
	struct type* super,
	unsigned func_id,
	struct function_queue* flookup)
{
	ENTER;
	
	assert(super->kind == tk_char);
	
	unsigned type_id = super->id;
	
	struct stringtree* text = new_stringtree();
	
	stringtree_append_printf(text, ""
		"struct type_%u* func_%u(unsigned code) {"
			"struct type_%u* this = malloc(sizeof(*this));"
			"this->code = code;"
			"this->refcount = 1;"
			"return this;"
		"}"
	"", type_id, func_id, type_id);
	
	EXIT;
	return text;
}

