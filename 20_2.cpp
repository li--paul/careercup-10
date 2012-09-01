/*
 *
 * shuffle card
 * by parker0203
 *
 */


#include <iostream>
#include <cstdlib>

using namespace std;

void swap_int(int &a, int &b){

	int temp = a;
	a = b;
	b = temp;
}

void shuffle(int card[], int size){

	for(int i = 0; i < size; ++i){
		int temp = rand() % (size - i) + i;
		swap_int(card[i], card[temp]);
	}
}

int main(){

	srand(time(NULL));
	int card[52];
	for(int i = 0; i < 52; ++i){
		card[i] = (i + 15) % 52;
	}
	shuffle(card, 52);

	for(int i = 0; i < 52; ++i){
		cout << card[i] << " ";
		if(i % 10 == 9){
			cout << endl;
		}
	}
	cout << endl;

	return 0;
}
