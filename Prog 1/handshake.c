#include <stdio.h>

int main() {
    int students, handshakes;
    scanf("%d", &students);

    if (students >= 0 && students <= 2000){
        handshakes = students * (students - 1) / 2; 
        printf("%d", handshakes);
    }

    return 0;
}