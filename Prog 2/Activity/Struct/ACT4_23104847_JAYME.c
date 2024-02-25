
#include <stdio.h>
#include<string.h>
#include <stdbool.h>

typedef struct {
    int day;
    int month;
    int year;
} Birthdate;

void display(Birthdate myDate);
int getAge(Birthdate myDate);
char* zodiac(char month[], int age, Birthdate myDate);

int main() {
   Birthdate myDate;
   int age;
   char *zod;
   char *month[13] = {"JAN", "FEB", "MAR", "APR", "MAY","JUN","JUL", "AUG", "SEP","OCT","NOV", "DEC"};
   
   printf("Enter your birthmonth: ");
   scanf("%d", &myDate.month);
   printf("Enter your birthday: ");
   scanf("%d", &myDate.day);
   printf("Enter your birthyear: ");
   scanf("%d", &myDate.year);
    
    display(myDate);
    age = getAge(myDate);
    printf("You are: %d years old \n", age);
    zod = zodiac(month[myDate.month - 1], age, myDate);
    printf("Your Zodiac is: %s", zod);
    
    

    return 0;
}
//current date - birthyear
void display(Birthdate myDate){
    char *month[13] = {"JAN", "FEB", "MAR", "APR", "MAY","JUN","JUL", "AUG", "SEP","OCT","NOV", "DEC"};
    printf("%02d %s %04d\n", myDate.day, month[myDate.month-1], myDate.year);
}

//CURRENT DATE IS SET TO 15/02/2024
//How do we calculate age?
//Find the difference between the current year and the year of 
//birth to determine the years.
int getAge(Birthdate myDate){
    Birthdate myAge = {15,2,2024};
    int age;
    age = myAge.year - myDate.year;
    
    bool birthdayPassed = (myDate.month < myAge.month) || (myDate.month == myAge.month && myDate.day <= myAge.day);
    
    if (!birthdayPassed){
        age--;
    }
    return age;
}
char *zodiac(char month[], int age, Birthdate myDate){
    char *zodiac[] = {"Aquarius", "Pisces", "Aries", "Taurus", "Gemini", "Cancer", "Leo", "Virgo", "Libra", "Scorpio", "Sagittarius", "Capricorn"};
    int i;
     Birthdate zodiacDate[] = {{20, 1, 0}, {19, 2, 0}, {20, 3, 0}, {20, 4, 0}, {21, 5, 0}, {21, 6, 0},
        {22, 7, 0}, {23, 8, 0}, {23, 9, 0}, {23, 10, 0}, {22, 11, 0}, {22, 12, 0}};
        
     for (int i = 0; i < 11; ++i){
        if ((myDate.month == zodiacDate[i].month && myDate.day >= zodiacDate[i].day) || (myDate.month == zodiacDate[i+1].month && myDate.day < zodiacDate[i+1].day)){
            return zodiac[i];
        }
    }
    return zodiac[11];
}