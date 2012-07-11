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

int main(int argc, char **argv)
{
	if(argc != 2){
		printf("number of para should be 2\n");
		return 0;
	}
//	int result = brute_force(argv[1]);
	int result = hash_table(argv[1]);
	printf("%d\n", result);

	return 0;
}
