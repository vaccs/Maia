
#include <debug.h>

#include "struct.h"
#include "submit.h"

void declare_queue_submit(
	struct declare_queue* this,
	struct string* name)
{
	ENTER;
	
	TODO;
	#if 0
	if (stringset_add(this->queued, name))
	{
		quack_append(this->todo, name);
	}
	#endif
	
	EXIT;
}
