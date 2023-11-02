#include <stdio.h>
#include <string.h>


struct Student {
    int regNo;
    char name[30];
    char branch[20];
    float cgpa;
};


void searchStudentByRegNo(struct Student students[], int n, int regNo) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (students[i].regNo == regNo) {
            printf("Student Found:\n");
            printf("Registration Number: %d\n", students[i].regNo);
            printf("Name: %s\n", students[i].name);
            printf("Branch: %s\n", students[i].branch);
            printf("CGPA: %.2f\n", students[i].cgpa);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Student with registration number %d not found.\n", regNo);
    }
}

// Function to perform a bubble sort on students based on registration number
void sortStudentsByRegNo(struct Student students[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].regNo > students[j + 1].regNo) {
                // Swap the students if they are out of order
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main() {
    struct Student students[10];
    int n = 10;

    // Input details for 10 students
    for (int i = 0; i < n; i++) {
        printf("Enter Registration Number for student %d: ", i + 1);
        scanf("%d", &students[i].regNo);

        printf("Enter Name for student %d: ", i + 1);
        scanf("%s", students[i].name);

        printf("Enter Branch for student %d: ", i + 1);
        scanf("%s", students[i].branch);

        printf("Enter CGPA for student %d: ", i + 1);
        scanf("%f", &students[i].cgpa);
    }

    int searchRegNo;
    printf("Enter the Registration Number of the student you want to search: ");
    scanf("%d", &searchRegNo);
    searchStudentByRegNo(students, n, searchRegNo);


    sortStudentsByRegNo(students, n);

    printf("Students sorted by Registration Number:\n");
    for (int i = 0; i < n; i++) {
        printf("Registration Number: %d, Name: %s, Branch: %s, CGPA: %.2f\n",
            students[i].regNo, students[i].name, students[i].branch, students[i].cgpa);
    }

    return 0;
}
