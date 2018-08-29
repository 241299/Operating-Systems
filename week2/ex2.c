#include <stdio.h>

int main() {
	char s[1024];

	// Inputting data
	printf("Please, enter the text: ");
	scanf("%s", s);

	// Reversing
	{
		int length = strlen(s);
		char swap;
		for (int i = 0; i < length / 2; i++) {
			swap = s[i];
			s[i] = s[length - i - 1];
			s[length - i - 1] = swap;
		}
	}

	// Outputting the result
	printf("%s", s);
	return 0;
}