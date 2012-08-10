#include <iostream>

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
//		void remove(T);

};

bi_search_tree::bi_search_tree(){

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
		cout << "no any element in tree" << endl;
	}
	else{
		print_tree(t->left);
		cout << t->item << endl;
		print_tree(t->right);
	}

}

int main(){

	bi_search_tree my_tree;
	my_tree.insert(10, my_tree.root);
	
	cout << "main" << my_tree.root->item << endl;

	my_tree.print_tree(my_tree.root);

	return 0;
}
