#include <stdio.h>
#include <string.h>

struct Employee {
    char name[50];
    char department[50];
    double salary;
};

void swap(struct Employee *a, struct Employee *b) {
    struct Employee temp = *a;
    *a = *b;
    *b = temp;
}

void sortEmployeesBySalary(struct Employee employees[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (employees[j].salary < employees[j + 1].salary) {
                swap(&employees[j], &employees[j + 1]);
            }
        }
    }
}

void printEmployees(struct Employee employees[], int n) {
    printf("Name       Department       Salary\n");
    printf("----------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%s %s %.2f\n", employees[i].name, employees[i].department, employees[i].salary);
    }
}

int main() {
    struct Employee employees[] = {
        {"Alvin     ", "Engineering     ",    75000.00},
        {"Certeza   ", "Marketing       ",    50000.00},
        {"Charlie   ", "Engineering     ",    82000.00},
        {"Diana     ", "Human Resources ",    47000.00},
        {"Eve       ", "Marketing       ",    60000.00}
    };

    int n = sizeof(employees) / sizeof(employees[0]);

    sortEmployeesBySalary(employees, n);
    printEmployees(employees, n);

    return 0;
}
