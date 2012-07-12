#include <stdio.h>
#include <string.h>

int brute_force(char *string)
{
	int i, j;
	int len = strlen(string);
	for(i = 0; i < len ; ++i)
		for(j = i + 1; j < len; ++j)
		{
			if(string[i] == string[j])
				return 1;
		}
	return 0;
}

int hash_table(char *string)
{
	int i;
	int len = strlen(string);
	int hash[256];
	memset(hash, 0, sizeof(hash));
	for(i = 0; i < len; ++i)
		if(hash[(int)string[i]] != 0)
			return 1;
		else
			hash[(int)string[i]]++;

	return 0;
}

void swap(char *ch1, char *ch2){
	char temp = *ch1;
	*ch1 = *ch2;
	*ch2 = temp;
}

int quick_sort(char *str, int left, int right){
	if(left < right){
		char pivot = str[left];
		int i = left;
		int j = i + 1;

		for( ; j <= right; ++j){
			if(pivot > str[j]){
				swap(&str[i + 1], &str[j]);
				++i;
			} 

		if(pivot == str[j])
		return 1;
		} 
		
		swap(&str[left], &str[i]);
		if(quick_sort(str, left, i - 1)) return 1;
		if(quick_sort(str, i + 1, right)) return 1;
	}
	return 0;
}

int main(int argc, char **argv)
{
	if(argc != 2){
		printf("number of para should be 2\n");
		return 0;
	}
//	int result = brute_force(argv[1]);
//	int result = hash_table(argv[1]);
	int result = quick_sort(argv[1], 0, strlen(argv[1]) - 1);
	printf("%d\n", result);
//	printf("%s\n", argv[1]);

	return 0;
}
