/* If two strings are anagrams or not
 * 
 * by parker0203
 *
 */

#include <stdio.h>
#include <string.h>

void swap(char *a, char *b){
	char temp = *a;
	*a = *b;
	*b = temp;
}

char median(char a, char b, char c){
	if((a <= b && b <= c) || (a >= b && b >= c)) return b;
	if((b <= a && a <= c) || (b >= a && a >= c)) return a;
	if((a <= c && c <= b) || (a >= c && c >= b)) return c;
	return -1;
}

void quick_sort(char *str, size_t left, size_t right){
	if(left < right){
		char pivot = median(str[left], str[(left + right) / 2], str[right]);
		int i = left - 1;
		int j = right + 1;
		while(1){
			while(str[++i] < pivot){}
			while(str[--j] > pivot){}
			if(i < j)
				swap(&str[i], &str[j]);
			else 
				break;

		}
		//	swap(&str[i], &str[right - 1]);
			quick_sort(str, left, i - 1);
			quick_sort(str, i + 1, right);

	}
}

int anagram(char *str1, char *str2){
	quick_sort(str1, 0, strlen(str1) - 1);
	quick_sort(str2, 0, strlen(str2) - 1);
	return strcmp(str1, str2);
}

int main(){

	char str1[] = "abcdefg";
	char str2[] = "gfedcab";

//	int result = 0;
//	str1[3] = 'k';
	int result = anagram(str1, str2);
//	quick_sort(str2, 0, strlen(str2) - 1);
//	printf("%s\n", str2);
//	printf("%s\n", str2);

	printf("%d\n", result);

	return 0;
}
