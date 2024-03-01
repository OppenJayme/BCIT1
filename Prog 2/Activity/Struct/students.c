// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 6

typedef char String[30];

typedef struct{
    String fname;
    String lname;
} StudentName, *NameList, NameArray[MAX];

typedef struct{
    int stud_id;
    StudentName stud_name;
    char sex; 
} Student, *StudentPtr, StudentList[MAX];

StudentName createName(String fname, String lname);
Student createStudent(int name, StudentName Name, char sex);
void addStudent(StudentList list, Student *studco, int *count);
void displayStudent(Student stud);
void displayList(StudentList list, int *count);
int countFem(StudentList list, int*count);
void displayFem(StudentList list, int*count);

int main() {
    int count = 0;
    StudentName name1 = {"Katherine", "Ang"};
    Student student1 = createStudent(1001,name1,'F');
    
    StudentName name2 = {"Christian", "Jayme"};
    Student student2 = createStudent(1002,name2,'M');
    
    StudentName name3 = {"Murakami", "Uzumaki"};
    Student student3 = createStudent(1003,name3,'F');
    
    StudentName name4 = {"Yousif", "Ratilla"};
    Student student4 = createStudent(1004,name4,'M');

    StudentName name5 = {"Kyle", "Castro"};
    Student student5 = createStudent(1005,name5,'M');

    StudentName name6 = {"Gwapa", "Ko"};
    Student student6 = createStudent(1006,name6,'F');

    StudentList list;

    addStudent(list, &student1, &count);
    addStudent(list, &student2, &count);
    addStudent(list, &student3, &count);
    addStudent(list, &student4, &count);
    addStudent(list, &student5, &count);
    addStudent(list, &student6, &count);

    displayList(list, &count);

    int fem= countFem(list, &count);

    if (fem == 1){
        printf("There is only %d female student in the list.", fem);
    } else {
        printf("There are %d female students in the list.", fem);
    }
    displayFem(list, &count);
    
    return 0;
}

StudentName createName(String fname, String lname){
    StudentName new;
    
    strcpy(new.fname, fname);
    strcpy(new.lname, fname);
    
    return new;
}
void displayStudent(Student stud){
    printf("ID: %d\n", stud.stud_id);
    printf("NAME: %s, %s\n", stud.stud_name.lname, stud.stud_name.fname);
    printf("SEX: %c\n\n", stud.sex);
}

void displayList(StudentList list, int *count){
    for (int i=0;i<*count;++i){
        printf("Student %d\n", i+1);
        printf("ID: %d\n", list[i].stud_id);
        printf("NAME: %s, %s\n", list[i].stud_name.lname, list[i].stud_name.fname);
        printf("SEX: %c\n\n", list[i].sex);
    }
}
Student createStudent(int id, StudentName name, char sex){
    Student createStud;
    createStud.stud_id = id;
    createStud.stud_name = name;
    createStud.sex = sex;
    
    return createStud;
}
void addStudent(StudentList list, Student *student, int *count){
    if (*count < MAX){
        list[*count] = *student;
        (*count)++;
    } else {
        printf("List is full\n");
    }
}
int countFem(StudentList list, int*count){
    int fem=0;
    for (int i=0;i<*count;++i){
        if (list[i].sex == 'F'){
            fem++;
        }
    }
    return fem;
}
void displayFem(StudentList list, int*count){
    for (int i = 0; i < *count; ++i) {
        if (list[i].sex == 'F') {
            printf("\nStudent No. %d\n", i + 1);
            printf("ID: %d\n", list[i].stud_id);
            printf("Name: %s, %s\n", list[i].stud_name.lname, list[i].stud_name.fname);
            printf("Sex: %c\n", list[i].sex);
        }
    }
}


