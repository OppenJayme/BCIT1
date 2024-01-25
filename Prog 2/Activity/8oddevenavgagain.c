#include <stdio.h>

//Function prototypes.
void getOdd(int arr[], int size);
void getEven(int arr[], int size);

int main(){
	int size, i, j;
	int odd, even;

	//gets the size of the array.
	printf("Enter the size of the array: ");
		if (scanf("%d", &size) != 1 || size <= 0){
				printf("Invalid");
				return 0;
			} 

	//Makes the elements of the array equal to the size.	
	int arr[size];
	
    //Elements of the array and prints invalid if a non-integer is inputted..
	printf("Enter the elements of the array: \n");
	for(j = 0; j < size; j++){
		if (scanf("%d", &arr[j]) != 1){
            printf("Invalid");
            return 1;
        }
	}
	
    //Prints out the odd and even elements including their average.
	printf("The odd elements of the array: {");
    	getOdd(arr, size);  
	printf("The Even elements of the array is: {");
		getEven(arr, size);
	
	return 0;
}
//Function for getting the odd elements.
void getOdd(int arr[], int size){
	int odd = 0,i;
	float avg;
	int count = 0;
	for (i = 0; i < size; ++i) {
		if (arr[i] % 2 != 0){
            if (count > 0){
                printf(",");
            }
			printf("%d", arr[i]);
				odd += arr[i];
				    count++;
		}
	}
    printf("}");
    
    //If there is no odd number, it will print out that there is no odd number.
    if (count != 0){
        avg = odd / count;
	    printf("\nThe average is %.2f\n", avg);
    } else {
        printf("\nThere is no odd number\n");
    }
}

//Function for getting the even elements.
void getEven(int arr[], int size){
		int even = 0,i;
		int count = 0;
		float avg;
	for (i = 0; i < size; ++i) {
		if (arr[i] % 2 == 0){
            if (count > 0){
                printf(",");
            }
			        printf("%d", arr[i]);
				        even += arr[i];
					        count++;
		}
	}
    printf("}");

    //If there is no even number, it will print out that there is no even number.
	if (count != 0){
        avg = even / count;
	    printf("\nThe average is %.2f\n", avg);
    } else {
        printf("\nThere is no even number\n");
    }
}