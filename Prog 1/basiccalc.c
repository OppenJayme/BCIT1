#include <stdio.h>

int main(){
    char op;
    float num1, num2, answer;
    
    printf("Enter what operator: ");
    scanf("%c", &op);
    printf("Enter first number: ");
    scanf("%f", &num1);
    printf("Enter second number: ");
    scanf("%f", &num2);
    
    

    switch (op) {
        case '+':
            answer = num1 + num2;
            printf("The answer is: %.2f", answer);
            break;
        case '-':
            answer = num1 - num2;
            printf("The answer is: %.2f", answer);
            break;
        case '*':
            answer = num1 * num2;
            printf("The answer is: %.2f", answer);
            break;
        case '/':
            answer = num1 / num2;
            printf("The answer is: %.2f", answer);
            break;
        default:
            printf("Invalid operator");
    }
   
    return 0;
}