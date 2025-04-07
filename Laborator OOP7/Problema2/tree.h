template<typename T>
class Tree {
	struct nod {
		T val;
		int nChilds;
		Tree* child[100];
	};

public:
	void add_node(const& T, *nod);
};