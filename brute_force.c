//naive brute force approach to string matching prolem

#include <stdio.h>


int naive_brute_force(char* text, char* pattern)
{
	int i; // to loop through the text
	int j; // to loop through the pattern
	int pos;
	for (i=0; i<26; i++)
	{
		for (j=0; j <=j-ı; (i+j)<26; j++)
			if (text[i+j] != pattern[j])
				break;
				//mismatch found, break the inner loop with j
		if (j==4)
			pos = i+j;
			return pos;
	}
	return -1;
}

int main()
{
	//3+2+3+4+10+4=8+4+14=12+14=26
	char* text = "SDU is the best university";
	char* pattern = "best";
	int pos;
	pos = naive_brute_force(text, pattern);
	if (pos != -1)
		printf("The match has been found at %d\n", pos);
	else
		printf("No match found :( ! \n");
	return 0;
}

