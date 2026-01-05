#include <stdio.h>
#include <unistd.h>
#define LENGTH 19

void printArray(int arr[], int length, int l, int r, int pivot, int high, int low);
void swap(int arr[], int index1, int index2);
void sort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void printFound(int arr[], int length, int foundl, int foundr);

int main(void) {

int arr[] = {10,5,6,1,19,12,3,15,20,7,10,5,6,1,19,12,3,15,20};
printf("\033[?25l");

sort(arr, 0, 18);
 
printArray(arr, 19, -1, -1, -1, 18, 0);
printf("\033[?25h");

}

void swap(int arr[], int index1, int index2) {
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
    //printf("swapped %d with %d\n", arr[index1], arr[index2]);
}

void sort(int* arr, int low, int high) {
    
    if (high - low +1 < 2) return;
    printf("\033[1;1H\033[K");
    printf("length: %d\n", LENGTH);

    int split = partition(arr, low, high);

    

        sort(arr, low, split);
    
    
        sort(arr, split + 1, high);
    

}

int partition(int arr[], int low, int high) {
    
    int pivot = arr[(low + high)/2];
    printf("\033[1;14H\033[K");

    printf("pivot: \033[33m%d\033[0m\n", pivot);

    int r = high +1 ;
    int l = low -1;
    
    printArray(arr, LENGTH, l, r, pivot, high, low);

    while(1) {
        sleep(1);
        do {
            l++;
            printArray(arr, LENGTH, l , r, pivot, high, low);
            sleep(1);
        } while(arr[l] < pivot);
        printFound(arr, LENGTH, l, -1);
        
        printArray(arr, LENGTH, l , r, pivot, high, low);
        sleep(1);
        printf("\033[3;1H\033[K");

        do {
             r--;
            printArray(arr, LENGTH, l , r, pivot, high, low);
            sleep(1);
        } while(arr[r] > pivot);

        printFound(arr, LENGTH, l, r);
        
        printArray(arr, LENGTH, l , r, pivot, high, low);
        sleep(1);
        printf("\033[3;1H\033[K");

        if (l < r) {
            
            printArray(arr,LENGTH, l, r, pivot, high, low);
            printf("\033[2;1H\033[K");
            printf("swapping %d and %d\n", arr[l], arr[r]);
            sleep(1);
            printf("\033[2;1H\033[K");


            if (arr[l] != arr[r]) swap(arr, l, r);
           
            
        } else {
            printf("\033[3;1H\033[K");
            printf("crossed l: %d r: %d\n", arr[l], arr[r]);
            sleep(1);
            printf("\033[3;1H\033[K");
            printArray(arr,LENGTH, l, r, pivot, high, low);

            break;
        }
        
    }
    return r;
}


void printArray(int arr[], int length, int l, int r, int pivot, int high, int low) {
    printf("\033[4;1H\033[K");
    for(int i=0; i < LENGTH; i++) {
        
        if (i > high || i < low) {
            printf("\033[90m %d \033[0m", arr[i]);
        } else {
            if (i == l) { 
                if (arr[i] < pivot && l < r || arr[i] > pivot && l >= r) {
                    printf("(\033[32m%d\033[0m)", arr[i]);      
                } else if (arr[i] > pivot && l < r) {
                    printf("(\033[31m%d\033[0m)", arr[i]);
                } else {
                    printf("(\033[33m%d\033[0m)", arr[i]);
                }
            } else if (i == r) { 
                if (arr[i] < pivot && r > l || arr[i] < pivot && r <= l) {
                    printf("(\033[31m%d\033[0m)", arr[i]);      
                } else if (arr[i] > pivot && r > l) {
                    printf("(\033[32m%d\033[0m)", arr[i]);
                } else {
                    printf("(\033[33m%d\033[0m)", arr[i]);
                }
            
            } else if (arr[i] == pivot) {
                printf("\033[33m %d \033[0m", arr[i]); 
            } else {
                if ( i < l || i > r) {
                    printf("\033[32m %d \33[0m", arr[i]);
                } else {
                    printf("\033[37m %d \033[0m", arr[i]);
                }
              
            }
        }
    }
    printf("\n");

     fflush(stdout);
}

void printFound(int arr[], int length, int foundl, int foundr) {
    printf("\033[3;1H\033[K");
    for (int i = 0; i < LENGTH; i++) {
        if (i != foundl && i != foundr) {
            if (arr[i] < 10) {
                printf("   ");

            } else {
                printf("    ");
            }
            
        } else {
            if (arr[i] < 10) {

                printf(" ! ");
            } else {
                printf("  ! ");
            }
        }
    }
}
