
#include <debug.h>

#include <named/expression/struct.h>

#include <expression/struct.h>
#include <expression/print_source.h>

#include <type/struct.h>

#include <declaration/struct.h>

#include <list/declaration/struct.h>

#include "../shared.h"
#include "../type_queue/submit.h"
#include "../function_queue/submit_free.h"

#include "struct.h"
#include "process.h"

void declare_queue_process(
	struct declare_queue* this,
	struct declaration_list* declarations,
	struct out_shared* shared)
{
	ENTER;
	
	this->init_text = new_stringtree();
	
	this->assign_text = new_stringtree();
	
	this->uninit_text = new_stringtree();
	
	for (unsigned i = 0, n = declarations->n; i < n; i++)
	{
		struct declaration* declaration = declarations->data[i];
		
		dpvs(declaration->name);
		
		struct string* name = declaration->name;
		
		struct expression* expression = declaration->expression;
		
		struct type* type = expression->type;
		
		type_queue_submit(shared->tqueue, type);
		
		unsigned type_id = type->id;
		
		stringtree_append_printf(this->init_text, ""
			"struct type_%u* $%.*s = NULL;"
		"", type_id, name->len, name->chars);
		
		stringtree_append_printf(this->assign_text, ""
			"$%.*s = "
		"", name->len, name->chars);
		
		struct stringtree* subtext = expression_print_source(expression, shared);
		
		stringtree_append_tree(this->assign_text, subtext);
		
		stringtree_append_printf(this->assign_text, ""
			";"
		"");
		
		unsigned free_id = function_queue_submit_free(shared->fqueue, type);
		
		stringtree_append_printf(this->uninit_text, ""
			"func_%u($%.*s);"
		"", free_id, name->len, name->chars);
		
		free_stringtree(subtext);
	}
	
	EXIT;
}

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
