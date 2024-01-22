#include <stdio.h>

int main(void){
        int size, i, arr[100], j, k, n;

        printf("Enter size of array: ");
        scanf("%d", &size);
       printf("Enter elements in array: \n");
       for (i = 0; i < size; i++){
            scanf("%d", &arr[i]);
       }

        for (j = 0; j < size; j++){
            for (k = j+1; k < size; k++){ //let say that arr[] = {1,2,2,3,4}
                if (arr[j] == arr[k]){
                    for (n = k; n < size - 1; n++){
                        arr[n] = arr[n + 1];
                    }
                    size--;
                    k--;        
                }
            }
            
        }
        printf("\nArray elements after deleting duplicates: ");
            for (j = 0; j < size; j++){
                printf("%d ", arr[j]);
            }
    return 0;
}
// n = index3, size - 1 = 4, arr[n + 1] = arr[4] = 4