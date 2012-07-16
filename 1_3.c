#include <stdio.h>
#include <string.h>

void remove_dup_hash(char *str){

	if(str == NULL) return;
	size_t len = strlen(str);
	if(len == 2) return;

	int hash_table[256];
	memset(hash_table, 0, sizeof(hash_table));

	int tail = 0;

	for(int i = 0; i < len; ++i){
		if(hash_table[(int)str[i]] == 0){
			hash_table[(int)str[i]] = 1;
			str[tail] = str[i];
			++tail;
		}
	}
	str[tail] = 0;
}
void remove_dupchar(char *str){

	if(str == NULL) return;
	size_t len = strlen(str);
	if(len == 2) return;

	int tail = 1;

	for(int i = 1; i < len; i++){
		int j = 0;
		for(j = 0; j < tail; j++){
			if(str[i] == str[j]) break;
		}
		
		if(j == tail){
			str[tail] = str[i];
			++tail;
		}
	}
	str[tail] = 0;
}

int main(int argc, char **argv){

	if(argc != 2){
		printf("please input 2 para");
		return 0;
	}

	remove_dup_hash(argv[1]);
	printf("%s\n", argv[1]);

	return 0;
}
