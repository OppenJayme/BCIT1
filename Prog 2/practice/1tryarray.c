#include <stdio.h>
#include <string.h>
int main(){
    /*int num[] = {1,2,3,4,5,6};

for (int i = 0; i < sizeof(num)/sizeof(num[0]); i++){
    printf("%d", num[i]);
}
*/

char x[] = "ivan", "john";
char y[] = "katherine", "jane";
char temp[50]; 

strcpy(temp, x);
strcpy(x, y);
strcpy(y, temp);

printf("%s ", x);
printf("%s", y);

return 0;
}
