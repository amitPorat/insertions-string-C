#include <stdio.h>
#include "insertion.h"

int main() {
    int* aptr=a;
    for (int i=0;i<size;i++) {
        scanf("%d", (aptr+i));
    }
    insertion_sort(aptr, size);
    for (int i=0;i<size;i++) {
        if (i!=49) {
            printf("%d,",*(aptr+i));
        }else printf("%d\n",*(aptr+i));
    }
    return 0;
}