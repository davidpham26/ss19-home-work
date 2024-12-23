#include <stdio.h>

struct Student {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
};

void deleteStudent(int id, struct Student students[], int *currentLength) {
    int found = 0;
    for (int i = 0; i < *currentLength; i++) {
        if (students[i].id == id) {
            found = 1;
            for (int j = i; j < *currentLength - 1; j++) {
                students[j] = students[j + 1];
            }
            (*currentLength)--;
            printf("Student with ID %d has been deleted.\n", id);
            return;
        }
    }
    if (!found) {
        printf("Student with ID %d not found.\n", id);
    }
}

void printStudents(struct Student students[], int currentLength) {
    for (int i = 0; i < currentLength; i++) {
        printf("ID: %d, Name: %s, Age: %d, Phone Number: %s\n", students[i].id, students[i].name, students[i].age, students[i].phoneNumber);
    }
}

int main() {
    struct Student students[5] = {
        {1, "Pham Minh Phong", 20, "0886551556"},
        {2, "Ph?m Ğinh Sang", 21, "0987654321"},
        {3, "pham van truong", 22, "1122334455"},
        {4, "Nguyen Huy Sáng", 23, "5566778899"},
        {5, "Ğinh Viet Hoàng", 24, "6677889900"}
    };
    int currentLength = 5;

    printf("Initial list of students:\n");
    printStudents(students, currentLength);

    int idToDelete;
    printf("Enter the ID of the student to delete: ");
    scanf("%d", &idToDelete);

    deleteStudent(idToDelete, students, &currentLength);

    printf("Updated list of students:\n");
    printStudents(students, currentLength);

    return 0;
}

