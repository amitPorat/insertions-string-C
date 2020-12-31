#include <stdio.h>
#include "insertion.h"

int a[size]={0};

void shift_element(int* arr, int i){
    int temp = *(arr+i);
    while (0<i) {
        *(arr+i) = *(arr+i-1);
        --i;
    }
    *arr = temp;
}

void insertion_sort(int* arr, int len){
    for (int i=1;i<len;i++) {
        for (int j=i-1;j>=0;j--){
            if (*(arr+j+1)<*(arr+j)) {
                shift_element(arr+j,1);
            }else break;
        }
    }
}