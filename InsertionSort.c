#include <stdio.h>
#include <assert.h>
#include <math.h>

int insertionsort(int* x, int size){
    int i,j,temp,stop=0,count=0;
    for (i=0; i<size; i++) {
        j=i;
        while (j>0 && stop==0){ 
            if (x[j] < x[j-1]) {
                temp = x[j];
                x[j] = x[j-1];
                x[j-1] = temp;
                count++;
            } else{
                stop==1;
                count++;
                break; 
            }
            j--;
        }
    }

    return count;

}

int main () {
    int nums[]= {548, 845, 731, 258, 809, 522, 73, 385, 906, 891, 988, 289, 808, 128};
    int* ptr;
    ptr=&nums[0];
    printf("%d\n",insertionsort(ptr,14));
    return 0;
}