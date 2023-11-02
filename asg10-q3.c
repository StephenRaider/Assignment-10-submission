#include <stdio.h>
#include <string.h>


struct student {
    char name[30];
    int marks[5];
};


int calculateTotalMarks(struct student s) {
    int total = 0;
    for (int i = 0; i < 5; i++) {
        total += s.marks[i];
    }
    return total;
}


float calculateAverageMarks(struct student s) {
    int total = calculateTotalMarks(s);
    return (float)total / 5.0;
}

int main() {
    struct student students[3]; 


    for (int i = 0; i < 3; i++) {
        printf("Enter name for student %d: ", i + 1);
        scanf("%s", students[i].name);

        printf("Enter marks for 5 subjects for student %d: ", i + 1);
        for (int j = 0; j < 5; j++) {
            scanf("%d", &students[i].marks[j]);
        }
    }

    char searchName[30];
    printf("Enter the name of the student you want to search: ");
    scanf("%s", searchName);

    int studentIndex = -1;
    // Find the student with the specified name
    for (int i = 0; i < 3; i++) {
        if (strcmp(students[i].name, searchName) == 0) {
            studentIndex = i;
            break;
        }
    }

    if (studentIndex != -1) {
        int totalMarks = calculateTotalMarks(students[studentIndex]);
        float averageMarks = calculateAverageMarks(students[studentIndex]);

        printf("Student Name: %s\n", students[studentIndex].name);
        printf("Total Marks: %d\n", totalMarks);
        printf("Average Marks: %.2f\n", averageMarks);
    } else {
        printf("Student with name '%s' not found.\n", searchName);
    }

    return 0;
}
