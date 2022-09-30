
struct type;

struct type_inheritance
{
	int (*compare)(const struct type*, const struct type*);
	
	void (*print)(struct type*);
	
	void (*free)(struct type*);
};
