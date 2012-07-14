#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *reverse_str(char *str){
	char temp;
	size_t left, right;
	size_t lenth = strlen(str);

	left = 0;
	right = lenth -1;

	while(left < right){
		temp = str[left];
		str[left++] = str[right];
		str[right--] = temp;
	}
//	printf("%d", (int)strlen(str));
//	end +=(int)strlen(str) - 1;
//	printf("%s", end);
//	int i = 4;
//	while(i--){
//		temp = str[0];
//		str = (*end);
//		*end-- = temp;
//	}
	return str;

}

int main(int argc, char **argv){
	char *result = reverse_str(argv[1]);
//	char *str = "hello";
//	char *result = "abcde";
//	result = reverse_str(str);
	printf("%s\n", result);
	return 0;
}
