
struct type_cache;
struct value;
struct expression;
struct scope;

struct value* dict_math_expression_evaluate(
	struct type_cache* tcache,
	struct expression* super,
	struct value* environment);
