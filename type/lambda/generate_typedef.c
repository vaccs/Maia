
#include <debug.h>

#include <stringtree/new.h>
#include <stringtree/append_printf.h>

#include <out/shared.h>
/*#include <out/type_lookup/lookup.h>*/
#include <out/type_queue/submit.h>

#include <list/type/struct.h>

#include "struct.h"
#include "generate_typedef.h"

struct stringtree* lambda_type_generate_typedef(
	struct type* super,
	struct type_queue* tlookup)
{
	ENTER;
	
	assert(super->kind == tk_lambda);
	
	struct lambda_type* this = (void*) super;
	
	struct stringtree* tree = new_stringtree();
	
	dpv(super->id);
	
	stringtree_append_printf(tree, ""
		"typedef struct {"
	"");
	
	type_queue_submit(tlookup, this->rettype);
	
	stringtree_append_printf(tree, ""
		"type_%u (*funcptr)("
	"", this->rettype->id);
	
	for (unsigned i = 0, n = this->parameters->n; i < n; i++)
	{
		struct type* t = this->parameters->data[i];
		
		type_queue_submit(tlookup, t);
		
		stringtree_append_printf(tree, "type_%u", t->id);
		
		if (i + 1 < n)
			stringtree_append_printf(tree, ", ");
	}
	
	stringtree_append_printf(tree, ""
			");"
		"} type_%u;"
	"", super->id);
	
	EXIT;
	return tree;
}




















