# include <stdio.h>

int main() {
	int x, y;
	
	// Inputting two numbers
	printf("Please, enter two numbers (a, b): ");
	scanf("%d, %d", &x, &y);

	// Before call
	printf("First: %d\nSecond: %d\n", x, y);
	
	// Calling function to swap values
	swap(&x, &y);

	// After call
	printf("\n");
	printf("After the swap:\n\tfirst: %d\n\tsecond: %d", x, y);

	return 0;
}

void swap(int *px, int *py) {
	*px += *py;
	*py = *px - *py;
	*px -= *py;
}