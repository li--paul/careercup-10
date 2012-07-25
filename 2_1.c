#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	char data;
	struct node *next;
}node;

node* add_sample_char(char *str){

	node *temp = NULL;
	node *head = NULL;
	printf("%s\n", str);
	for(int i = strlen(str) - 1; i >= 0; --i){
		head = (node *)malloc(sizeof(node));
		head->data = str[i];
		head->next = temp;
		temp = head;
	}
	return head;
}

void print_list(node *head){

	node *temp = head;
	while(temp){
		printf("%c", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void remove_dup_hash(node *head){

	node *temp = head;
	node *temp_next = NULL;
	int hash_table[256];
	memset(hash_table, 0, sizeof(hash_table));
	hash_table[head->data] = 1;
	while(temp->next){
		if(hash_table[temp->next->data] == 1){
			temp_next = temp->next;
			temp->next = temp->next->next;
			free(temp_next);
		}
		else{
			hash_table[temp->next->data] = 1;
			temp = temp->next;
		}
	}
}

int main(){

	char str[] = "Hello WHorld";
	node *head = NULL;
	head = add_sample_char(str);
	remove_dup_hash(head);
	print_list(head);

	return 0;

}
