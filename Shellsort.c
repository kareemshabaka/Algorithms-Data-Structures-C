#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>


int shellsort (int *array, int size, int *h_gaps, int (*subsort)(int* array, int size));
int bubblesort(int* x, int size);


int bubblesort(int* x, int size) {
    int temp;
    int swaps = 0;
    for (int i = 0; i < size; i ++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (x[j] > x[j+1]) {
                temp = x[j];
                x[j] = x[j + 1];
                x[j+1] = temp;
                swaps ++;
            }
        }
    }
    return swaps;
}

int shellsort (int *array, int size, int *h_gaps, int (*subsort)(int* array, int size)){
    int swaps=0;
    for (int i=0;h_gaps[i]>=1;i++) {
        for (int j=0;j<=h_gaps[i];j++) {
            int subcount=0;
            int resort=0;
            int *subarr = (int*) malloc(size/h_gaps[i]*sizeof(int));
            for (int k=j;k<size;k+=h_gaps[i]+1) {
                    subarr[subcount]=array[k];
                    subcount++;
            }
            swaps+=(*subsort)(subarr,subcount);
            for (int l=j;l<size;l+=h_gaps[i]+1) {
                array[l]=subarr[resort];
                resort++;
            }
        }
    }
    swaps+=(*subsort)(array,size);
    return swaps;
}

int main () {
    int arr[]={44, 79, 8, 53, 93, 21, 70, 79, 82, 49, 25, 2, 62, 26, 29, 54, 89, 57, 74, 39};
    //int arr[]={135, 529, 81, 54, 46, 605, 47, 793, 278, 323, 306, 430, 973, 286, 712, 962, 461, 81, 57,325, 711, 995, 833, 222, 284, 293, 153, 224, 126, 643, 425, 400, 420, 309, 831, 6, 496, 347, 185, 583}; 
    int hgaps[]= {10,4,1};
    int *ptr= arr;
    int *hptr=hgaps;
    int (*bubble)(int*,int)=bubblesort;
    printf("%d\n",shellsort(ptr,20,hptr,bubble));
    for (int i=0;i<20;i++) {
        printf("%d ",arr[i]);
    }
    return 0;
}