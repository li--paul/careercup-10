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

int main(){

	char str[] = "Hello World";
	node *head = NULL;
	head = add_sample_char(str);
	print_list(head);

	return 0;

}
