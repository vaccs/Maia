
struct value;

struct value_inheritance
{
	int (*compare)(const struct value*, const struct value*);
	
	void (*print)(struct value*);
	
	void (*free)(struct value*);
};
