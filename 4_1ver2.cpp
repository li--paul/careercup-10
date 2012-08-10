#include <iostream>
#include <algorithm>

using namespace std;


struct bi_node{
	int item;
	bi_node *left;
	bi_node *right;
	bi_node(int new_item, bi_node *l, bi_node *r):
		item(new_item), left(l), right(r){}

};

// assume no duplicated element in the tree
class bi_search_tree{


	public:
		bi_node *root;
		bi_search_tree();
//		~bi_search_tree();

//		T find_min();
//		T find_max();
//		bool is_empty();
		void print_tree(bi_node * & t);
		void insert(int, bi_node * & t);
		int max_depth(bi_node * t);
		int min_depth(bi_node * t);
//		void remove(T);

};

bi_search_tree::bi_search_tree(){

	root = NULL;
}

void bi_search_tree::insert(int new_item, bi_node * & t){

	if(t == NULL){
		t = new bi_node(new_item, NULL, NULL);
	}
	else if(new_item < t->item){
		insert(new_item, t->left);
	}
	else if(new_item > t->item){
		insert(new_item, t->right);
	}
	else{
		cout << "duplicated item, just return" << endl;
	}
}

void bi_search_tree::print_tree(bi_node * & t){

	if(t == NULL){
//		cout << "no any element in tree" << endl;
		return;
	}
	else{
		print_tree(t->left);
		cout << t->item << endl;
		print_tree(t->right);
	}

}

int bi_search_tree::max_depth(bi_node *t){

	if(t == NULL) return 0;

	return 1 + max(max_depth(t->left), max_depth(t->right));
}

int bi_search_tree::min_depth(bi_node *t){

	if(t == NULL) return 0;

	return 1 + min(min_depth(t->left), min_depth(t->right));
}

int main(){

	bi_search_tree my_tree;
	my_tree.insert(10, my_tree.root);
	my_tree.insert(7, my_tree.root);
	my_tree.insert(14, my_tree.root);
	my_tree.insert(2, my_tree.root);
	my_tree.insert(1, my_tree.root);

	
//	cout << "main" << my_tree.root->item << endl;
	cout << "max depth is:" << my_tree.max_depth(my_tree.root) << endl;
	cout << "min depth is:" << my_tree.min_depth(my_tree.root) << endl;

	my_tree.print_tree(my_tree.root);

	return 0;
}
