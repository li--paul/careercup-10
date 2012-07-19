#include <stdio.h>
#include <string.h>

int isSubstring(char *str1, char *str2){

	int i = 0, j = 0;
	int len1 = strlen(str1);
	int len2 = strlen(str2);

	while(i < len1 && j < len2){
		if(str1[i] == str2[j]){++i, ++j;}
		else{
			i = i - j + 1;
			j = 0;
		}
	}
	return j == len2;
}

int main(){

	char str1[] = "helloworldmynameisparker0203";
	char str2[] = "mynamke";

	int isSub = isSubstring(str1, str2);

	printf("%d\n", isSub);

	return 0;
}
