#include <stdio.h>
#include <assert.h>
#include <math.h>


int bubblesort(int* x, int size){
    int i=0, j=0, temp, count=0;
    for (i=0; i<size; i++) {
        for (j=0; j<size-i-1; j++) {
            if (x[j] > x[j+1]){
               temp = x[j];
               x[j] = x[j+1];
               x[j+1] = temp;
               count++;
            }
        }
    }
    return count;
}


int main () {
    int nums[]= {548, 845, 731, 258, 809, 522, 73, 385, 906, 891, 988, 289, 808, 128};
    int* ptr;
    ptr=&nums[0];
    printf("%d\n",bubblesort(ptr,14));
    return 0;
}