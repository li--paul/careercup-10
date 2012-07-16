#include <stdio.h>
#include <string.h>

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

	remove_dupchar(argv[1]);
	printf("%s\n", argv[1]);

	return 0;
}
