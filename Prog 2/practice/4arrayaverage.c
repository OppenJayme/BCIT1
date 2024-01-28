#include <stdio.h>

void calculate_average(int size, int arr[]);

int main(){
    int size, i,j;

    printf("Size of the array: ");
        scanf("%d", &size);
    int arr[size];
    printf("Input elements of the array: \n");
        for (i = 0; i < size; i++){
            scanf("%d", &arr[i]);
        }
    calculate_average(size, arr);


    return 0;
}

void calculate_average(int size, int arr[]){
    int avg = 0, sum = 0,j;
printf("Array elements: {");
    for (j = 0; j < size; j++){
        printf("%d", arr[j]);
        if (j < size-1) {
            printf(",");
        }
    }
    printf("}");
    
        for (j = 0; j < size; j++){
            sum += arr[j];
        }
        avg = sum / size;

    printf("\nSum of array elements: %d\n", sum);
    printf("Average size of the array: %d\n", avg); 
}