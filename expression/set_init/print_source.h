
struct expression;
struct out_shared;
struct environment_type;

struct stringtree* set_init_expression_print_source(
	struct expression* super,
	struct out_shared* shared,
	struct type* environment);
