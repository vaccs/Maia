
struct out_shared;
struct declaration_list;

void declare_queue_process(
	struct declare_queue* this,
	struct declaration_list* declarations,
	struct out_shared* shared);