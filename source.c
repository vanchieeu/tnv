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

    int index = 0, max, index1 = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] != a[i+1]) 
            index1 = 1;
        else 
            index1++;
        if (index1 >= index) {
            index = index1;
            max = a[i];
        }
    }

    printf("%d %d", max, index);
    return 0;
}