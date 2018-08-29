#include <limits.h>
#include <float.h>

int a;
float b;
double c;

int main() {
	a = INT_MAX;
	b = FLT_MAX;
	c = DBL_MAX;

	printf("Values: \na = %d\nb = %f\nc = %f\n", a, b, c);
	printf("Sizes: \na => %d\nb => %f\nc => %f", sizeof a, sizeof b, sizeof c);
	return 0;
}