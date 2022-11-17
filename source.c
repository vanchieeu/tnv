#include <stdio.h>

void swap(long *a, long *b) {
    long temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(long *a, int l, int r) {
    long p = a[(l+r)/2];

    int i = l, j = r;
    while (i < j) {
        while (a[i] < p)
            i++;
        
        while (a[j] > p) 
            j--;

        if (i <= j) {
            swap(a+i, a+j);
            
            i++;
            j--;
        }
    }

    if (i < r) 
        quickSort(a, i, r);
    if (j > l)
        quickSort(a, l, j);
}

int main() {
    int n;
    do {
        scanf("%d", &n);
    } while (n < 1);

    long a[n];
    for (int i = 0; i < n; i++)
        scanf("%ld", &a[i]);

    quickSort(a, 0, n-1);


    int b[a[n-1]+1];
    for (int i = 0; i < a[n-1]+1; i++)
        b[i] = 0;
    for (int i = 0; i < n; i++)
        b[a[i]]++;
    
    int max = 0;
    int index = 0;
    for (int i = 0; i < a[n-1]+1; i++)
        if (b[i] != 0) 
            if (b[i] > index) {
                max = i;
                index = b[i];
            }

    printf("%d %d", max, index);
    return 0;
}