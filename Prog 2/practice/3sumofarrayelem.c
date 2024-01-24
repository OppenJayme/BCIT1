#include <stdio.h>

int main(){
    int size, sum = 0, j,i;

        printf("Enter size of array: ");
        if (scanf("%d", &size) != 1 || size <= 0){
            printf("Invalid input\n");
            return 1;
        }
    int arr[size];
        printf("Enter elements in array: \n");
        for (i = 0; i < size; i++){
            if (scanf("%d", &arr[i]) != 1){
                printf("Invalid input\n");
                return 1;
            };
        }

        for (j = 0; j < size; j++){
            sum += arr[j];
        }
        printf("Sum of array elements: %d", sum);

    return 0;
}