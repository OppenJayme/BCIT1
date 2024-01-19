#include <stdio.h>
#include <stdlib.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void main() {
	float prvread, presread, elcbill1, elcbill2, currbilljune, rdg1, rdg2, contri, contri2, contri3;
	
	printf("ELECTRICITY CONSUMPTION\n");
	
	printf("What's your previous meter reading?: ");
	scanf("%f", &prvread);
	printf("What's your present meter reading?: ");
	scanf("%f", &presread);
	
	rdg1 = presread - prvread;
	printf("Diff Rdg: %.2f\n", rdg1);
	
	printf("What's your previous reading of the electricity bill?: ");
	scanf("%f", &elcbill1);
	printf("What's your present reading of the electricity bill?: ");
	scanf("%f", &elcbill2);
	
	rdg2 = elcbill2 - elcbill1;
	printf("Diff Rdg %.2f\n", rdg2);
	
	printf("Total Amount Due: ");
	scanf("%f", &currbilljune);
	
	// solve
	
	contri = currbilljune / rdg2;
	printf("PHP %f\n", contri);
	
	contri2 = rdg1 * contri; 
	printf("PHP %f\n", contri2);
	
	printf("The actual amount for the contribution for the electricity bill is:\nPHP%f\n", contri2);
	
	contri3 = ceil(contri2 / 1000) * 1000;
	
	printf("The rounded amount for the contribution for the electricity bill in thousands is:\nPHP%f", contri3);
	
	
}


