
struct structinfo;
struct reductioninfo;
struct out_shared;
struct stringtree;

void reductioninfo_print_source(
	struct stringtree* tree,
	struct reductioninfo* this,
	struct structinfo* structinfo,
	struct out_shared* shared,
	struct string* grammar);
