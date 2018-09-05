#include <stdio.h>

/**
    A procedure that takes the addresses of the beginning and of the end of the array (as in built-in C++)
*/
void bubbleSort(int *pArrst, int *pArrend)
{
    // Looping as usual, bla-bla-bla
    for (int *i = pArrst; i < pArrend; i++)
    {
        for (int *j = i; j <= pArrend; j++)
        {
            if (*i > *j)
            {
                *i += *j;
                *j = *i - *j;
                *i -= *j;
            }
        }
    }

    // Adding support for method overloading
	#define bubbleSort(arr) bubbleSort(&arr[0], &arr[0] + (sizeof(arr)/sizeof(int)) - 1)
}

int main()
{
    // Call on static array
    int ns[10] = {10, 9, 7, 8, 5, 3, 2, 4, 1, 6};
    bubbleSort(ns);
    printf("%d, %d", ns[0], ns[9]);

    // Haven't figured out how to use the original function after (ﾉಥ益ಥ）ﾉ彡
    
    return 0;
}