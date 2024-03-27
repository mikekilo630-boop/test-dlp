#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure definition
typedef struct {
    char name[50];
    int age;
    float salary;
} Employee;

// Function prototypes
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
float divide(int a, int b);
void reverseString(char *str);
void sortArray(int arr[], int size);
void readFile(char *filename);
void writeFile(char *filename, Employee *employees, int numEmployees);

int main() {
    // Arithmetic operations
    int num1 = 10, num2 = 5;
    printf("Addition: %d\n", add(num1, num2));
    printf("Subtraction: %d\n", subtract(num1, num2));
    printf("Multiplication: %d\n", multiply(num1, num2));
    printf("Division: %.2f\n", divide(num1, num2));

    // String manipulation
    char str[] = "Hello, world!";
    printf("Original string: %s\n", str);
    reverseString(str);
    printf("Reversed string: %s\n", str);

    // Array sorting
    int arr[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nSorted array: ");
    sortArray(arr, size);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // File I/O
    char filename[] = "employees.txt";
    Employee employees[] = {
        {"John", 30, 50000.0},
        {"Alice", 25, 45000.0},
        {"Bob", 35, 55000.0}
    };
    int numEmployees = sizeof(employees) / sizeof(employees[0]);
    writeFile(filename, employees, numEmployees);
    printf("Contents of file '%s':\n", filename);
    readFile(filename);

    return 0;
}

// Function definitions

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

float divide(int a, int b) {
    if (b != 0) {
        return (float)a / b;
    } else {
        printf("Error: Division by zero\n");
        return 0;
    }
}

void reverseString(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void sortArray(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void readFile(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file) {
        char line[100];
        while (fgets(line, sizeof(line), file)) {
            printf("%s", line);
        }
        fclose(file);
    } else {
        printf("Error: Unable to open file '%s'\n", filename);
    }
}

void writeFile(char *filename, Employee *employees, int numEmployees) {
    FILE *file = fopen(filename, "w");
    if (file) {
        for (int i = 0; i < numEmployees; i++) {
            fprintf(file, "Name: %s, Age: %d, Salary: %.2f\n",
                    employees[i].name, employees[i].age, employees[i].salary);
        }
        fclose(file);
    } else {
        printf("Error: Unable to open file '%s' for writing\n", filename);
    }
}

