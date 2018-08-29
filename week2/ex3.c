# include <stdio.h>

int main(int argc, char* argv[]) {
	int N;
	
	if (argc > 1) {
		// Getting input from parameters
		N = atoi(argv[1]);
	} else {
		// Inputting data via console
		printf("Please, enter N: ");
		scanf("%d", &N);
		printf("\n");
	}

	// Declaring and filling buffer with whitespace
	char* buffer = malloc(2 * N);
	for (int i = 0; i < (N<<1) - 1; i++) buffer[i] = ' ';

	// Printing the triangle in O(n)
	// Idea: start from middle of the buffer string and add 
	// 		For first line (i = 0), distance is 0 → only middle is *
	// 		For n-th, distance is n → adds * to the (middle - n) and (middle + n)
	// middle = N

	for (int i = 0; i < N; i++) {
		buffer[N - i] = '*';
		buffer[N + i] = '*';

		// Outputting the result
		printf("%s\n", buffer);
	}

	return 0;
}