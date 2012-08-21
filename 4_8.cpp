/*
 *
 * find a path sum up to a value
 * by parker0203
 *
 */



#include <iostream>
#include <vector>

using namespace std;

struct tree_node{

	int item;
	tree_node *left;
	tree_node *right;
	tree_node(int new_item, tree_node *l, tree_node *r):
		item(new_item), left(l), right(r){}
};

void tree_insert(int new_item, tree_node * & t){

	if(t == NULL){
		t = new tree_node(new_item, NULL, NULL);
	}
	else if(new_item < t->item){
		tree_insert(new_item, t->left);
	}
	else if(new_item > t->item){
		tree_insert(new_item, t->right);
	}
	else{
		cout << "duplicated item, just return" << endl;
	}
	
}

void tree_print(tree_node *t){

	if(t == NULL){
		return;
	}
	else{
		tree_print(t->left);
		cout << t->item << " ";
		tree_print(t->right);
	}
}

void min_height_tree(int sorted_array[], int first, int last, tree_node * & t){

	if(first > last) return;

	int mid = (first + last) / 2;
	tree_insert(sorted_array[mid], t);
	min_height_tree(sorted_array, first, mid - 1, t->left);
	min_height_tree(sorted_array, mid + 1, last, t->right);

}

int tree_max_depth(tree_node *t){

	if(t == NULL) return 0;

	return 1 + max(tree_max_depth(t->left), tree_max_depth(t->right));

}

void print_vec(vector<int> vec){
	
	for(int i = 0; i < vec.size(); ++i){
		cout << vec[i] << " ";
	}
	cout << endl;
}

void find_sum(tree_node *t, int sum, vector<int> vec){

	if(t == NULL) return;
	int tmp = sum;
	vec.push_back(t->item);
	for(int i = 0; i < vec.size(); ++i){
		tmp -= vec[i];
	}
	if(tmp == 0) print_vec(vec);
	vector<int> c1(vec);
	vector<int> c2(vec);
	find_sum(t->left, sum, c1);
	find_sum(t->right, sum, c2);
}


int main(){

	int a[31];
	tree_node *root = NULL;
	for(int i = 0; i < 31; ++i){
		a[i] = i;
	}
	min_height_tree(a, 0, 30, root);
	cout << tree_max_depth(root) << endl;
	tree_print(root);
	cout << endl;

	vector<int> vec;
	find_sum(root->left, 11, vec);

	return 0;
}

