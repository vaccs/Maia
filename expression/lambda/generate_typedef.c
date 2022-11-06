
#include <debug.h>

#include <type/struct.h>

#include <type_check/unresolved/foreach.h>

#include <out/type_queue/submit.h>

#include <list/capture/foreach.h>

#include "struct.h"
#include "generate_typedef.h"

struct stringtree* lambda_expression_generate_generate_typedef(
	struct lambda_expression* this,
	struct subtype_queue* stqueue,
	struct type_queue* tqueue)
{
	ENTER;
	
	struct stringtree* tree = new_stringtree();
	
	// type_queue_submit(shared->stqueue, this);
	
	unsigned super_id = this->super.type->id;
	
	unsigned lambda_id = this->id;
	
	stringtree_append_printf(tree, ""
		"struct subtype_%u"
		"{"
			"struct type_%u super;"
	"", lambda_id, super_id);
	
	capture_list_foreach(this->captured, ({
		void runme(struct capture* capture)
		{
			TODO;
			#if 0
			dpvs(name);
			
			type_queue_submit(tqueue, type);
			
			stringtree_append_printf(tree, ""
				"struct type_%u* $%.*s;"
			"", type->id, name->len, name->chars);
			#endif
		}
		runme;
	}));
	
	stringtree_append_printf(tree, ""
		"};"
	"");
	
	EXIT;
	return tree;
}









