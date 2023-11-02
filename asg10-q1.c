#include <stdio.h>


struct Student {
    int rollNo;
    char name[50];
    int age;
};

int main() {

    struct Student students[5];


    for (int i = 0; i < 5; i++) {
        students[i].rollNo = i+1;
        printf("Enter name for student %d: ", i + 1);
        scanf("%s", students[i].name);
        printf("Enter age for student %d: ", i + 1);
        scanf("%d", &students[i].age);
    }


    int targetRollNo = 2;
    for (int i = 0; i < 5; i++) {
        if (students[i].rollNo == targetRollNo) {
            printf("Details of student with roll number %d:\n", targetRollNo);
            printf("Name: %s\n", students[i].name);
            printf("Age: %d\n", students[i].age);
            break;
        }
    }

    return 0;
}
