
struct environment_type;
struct out_shared;
struct expression;

struct stringtree* sum_form_expression_print_source(
	struct expression* super,
	struct out_shared* shared,
	struct environment_type* environment);
