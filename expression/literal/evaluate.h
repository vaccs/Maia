
struct expression;
struct scope;

struct value* literal_expression_evaluate(
	struct expression* super,
	struct scope* scope);
