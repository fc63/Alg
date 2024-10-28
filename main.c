#include "h/functions.h"

int main() {
    int i = 0, j = 0;

    printf("1. Sort\n2. Btr\n\nYour choice:");
    scanf("%d",&i);
    switch(i) {
        case 1:
        printf("1. Bubble Sort\n2. Insertion Sort\n3. Merge Sort\n4. Quick Sort\n5. Heap Sort\n6. Counting Sort\n\nYour choice:");
        scanf("%d",&j);
        printf("\n");
        switch(j) {
            case 1:
                return bs();
            case 2:
                return is();
            case 3:
                return ms();
            case 4:
                return qs();
            case 5:
                return hs();
            case 6:
                return cs();
        }
        case 2:
            return bt();
    }
    return 0;
}