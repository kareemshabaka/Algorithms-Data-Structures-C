#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>


int insertionsort(int* x, int size, int (*compare)(int a, int b));
int ascending (int a, int b);
int descending (int a, int b);
void swap (int* num1, int* num2);

void swap (int* num1, int* num2){
    int temp;
    temp= *num1;
    *num1=*num2;
    *num2=temp;
}

int ascending (int a, int b) {
    if (a<b) {
        return true;
    } else {
        return false;
    }
}

int descending (int a, int b) {
    if (a>b) {
        return true;
    } else {
        return false;
    }
}


int insertionsort(int* x, int size, int (*compare)(int a, int b)){
    int j;
    int count=0;
    for (int i=0; i<size; i++) {
        bool run = true;
        j=i;
        while (j>0 && run) {
            if ((*compare)(x[j],x[j-1])) {
                swap(&x[j],&x[j-1]);
                count++;
            } else {
                run=false;
                count++;
                break;
            }
            j--;
        }  
    }
    return count;
}

int main () {
    int arr[]={548, 845, 731, 258, 809, 522, 73, 385, 906, 891, 988, 289, 808, 128};
    int *ptr=arr;
    int (*ascend_ptr)(int,int)=ascending;
    int (*decend_ptr)(int,int)=descending;
    printf("%d\n",insertionsort(arr,14,decend_ptr));
    for (int i=0;i<14;i++) {
        printf("%d,",arr[i]);
    }

    return 0;
}