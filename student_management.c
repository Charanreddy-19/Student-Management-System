#include <stdio.h>
#include <string.h>

#define MAX 100

struct Student {
    int id;
    char name[50];
    float marks;
};

struct Student students[MAX];
int count = 0;

void addStudent() {
    if (count >= MAX) {
        printf("Student limit reached!\n");
        return;
    }

    printf("\nEnter Student ID: ");
    scanf("%d", &students[count].id);

    printf("Enter Student Name: ");
    scanf(" %[^\n]", students[count].name);

    printf("Enter Marks: ");
    scanf("%f", &students[count].marks);

    count++;
    printf("Student added successfully!\n");
}

void displayStudents() {
    int i;

    if (count == 0) {
        printf("\nNo student records found.\n");
        return;
    }

    printf("\n--- Student Records ---\n");

    for (i = 0; i < count; i++) {
        printf("\nID: %d", students[i].id);
        printf("\nName: %s", students[i].name);
        printf("\nMarks: %.2f\n", students[i].marks);
    }
}

void searchStudent() {
    int id, i, found = 0;

    printf("\nEnter Student ID to search: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("\nStudent Found!\n");
            printf("ID: %d\n", students[i].id);
            printf("Name: %s\n", students[i].name);
            printf("Marks: %.2f\n", students[i].marks);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Student not found.\n");
}

void updateStudent() {
    int id, i, found = 0;

    printf("\nEnter Student ID to update: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("Enter New Name: ");
            scanf(" %[^\n]", students[i].name);

            printf("Enter New Marks: ");
            scanf("%f", &students[i].marks);

            printf("Student updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Student not found.\n");
}

void deleteStudent() {
    int id, i, j, found = 0;

    printf("\nEnter Student ID to delete: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (students[i].id == id) {
            for (j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }

            count--;
            printf("Student deleted successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Student not found.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n===== STUDENT MANAGEMENT SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                updateStudent();
                break;

            case 5:
                deleteStudent();
                break;

            case 6:
                printf("Thank you!\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
