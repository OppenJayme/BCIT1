
void add(int *num1, int *num2, float *result);
void subtract(int *num1, int *num2, float *result);
void multiply(int *num1, int *num2, float *result);
void divide(int *num1, int *num2, float *result);
void resultAdd(int *num, float *result);
void resultSubtract(int *num, float *result);
void resultMultiply(int *num, float *result);
void resultDivide(int *num, float*result);
void initialOperation(int *num1, int *num2, float *result, char *op);

#include <stdio.h>

int main(){
    int num1, num2;
    float result;
    char op;
    int num =1;
    initialOperation(&num1, &num2, &result, &op);

    while (num != 0){
    printf("Choose an operator(+,-,*,/): ");
    scanf(" %c", &op);  // Add a space before %c
    if (op == 0){
        initialOperation(&num1, &num2, &result, &op);
    }
    printf("\nEnter new number: ");
    scanf("%d", &num);

     if (num == 0){
        printf("Program closed.");
        break;
    } 
        switch(op){
        case '+':
            resultAdd(&num, &result);
            break;
        case '-':
            resultSubtract(&num, &result);
            break;
        case '*':
             resultMultiply(&num, &result);
            break;
        case '/':
             resultDivide(&num, &result);
            break;
        default:
            printf("Invalid operator");
    }
    }


    return 0;



}
void add(int *num1, int *num2, float *result){
    *result = *num1 + *num2;
    printf("The answer is: %.2f\n", *result);
} 
void subtract(int *num1, int *num2, float *result){
    *result = *num1 - *num2;
    printf("The answer is: %.2f\n", *result);
}
void multiply(int *num1, int *num2, float *result){
    *result = *num1 * *num2;
   printf("The answer is: %.2f\n", *result);
}
void divide(int *num1, int *num2, float *result){
    *result = *num1 / *num2;
    printf("The answer is: %.2f\n", *result);
}
//-------------------------------------------------------
void resultAdd(int *num, float *result){
    *result += *num;
    printf("The answer is: %.2f\n", *result);
}
void resultSubtract(int *num,float *result){
    *result -= *num;
    printf("The answer is: %.2f\n", *result);
}
void resultMultiply(int *num, float *result){
    *result *= *num;
    printf("The answer is: %.2f\n", *result);
}

void resultDivide(int *num, float *result){
    *result /= *num;
    printf("The answer is: %.2f\n", *result);
}

//-------------------------------------------------------
void initialOperation(int *num1, int *num2, float *result, char *op) {
    printf("Choose an operator(+,-,*,/): ");
    scanf(" %c", op);  // Add a space before %c
    printf("Enter first number: ");
    scanf("%d", num1);
    printf("Enter second number: ");
    scanf("%d", num2);

    switch(*op){
        case '+':
            add(num1, num2, result);
            break;
        case '-':
            subtract(num1, num2, result);
            break;
        case '*':
            multiply(num1, num2, result);
            break;
        case '/':
            divide(num1, num2, result);
            break;
        default:
        
            printf("Invalid operator");
    }
}