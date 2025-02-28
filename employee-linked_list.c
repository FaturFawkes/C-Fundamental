#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_POSITION_LENGTH 50

// Struktur untuk menyimpan data karyawan
typedef struct Employee {
    int id;
    char name[MAX_NAME_LENGTH];
    char birthplace[MAX_NAME_LENGTH];
    char birthdate[11]; // Format "DD-MM-YYYY"
    char position[MAX_POSITION_LENGTH];
    struct Employee* next;
} Employee;

// Pointer ke head linked list
Employee* head = NULL;

// Fungsi untuk menampilkan data karyawan
void showEmployee() {
    Employee* current = head;
    if (current == NULL) {
        printf("❌ Data karyawan kosong!\n");
    } else {
        printf("Employee List\n");
        printf("ID\tName\tBirthplace\tBirthdate\tPosition\n");
        while (current != NULL) {
            printf("%d\t%s\t%s\t%s\t%s\n", current->id, current->name, current->birthplace, current->birthdate, current->position);
            current = current->next;
        }
    }
}

// Fungsi untuk menghapus data karyawan berdasarkan ID
void deleteEmployee() {
    int id;
    printf("Input Employee ID: ");
    scanf("%d", &id);
    
    struct Employee* current = head;
    struct Employee* prev = NULL;
    while (current != NULL) {
        if (current->id == id) {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("✅ Data karyawan berhasil dihapus!\n");
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("❌ Data karyawan tidak ditemukan!\n");
}

// Fungsi untuk menghapus semua data karyawan
void deleteAllEmployees() {
    if (head == NULL) {
        printf("\n⚠ Tidak ada data karyawan yang perlu dihapus!\n");
        return;
    }

    Employee* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    printf("✅ Semua data karyawan berhasil dihapus!\n");
}

// Fungsi untuk membuat node baru
Employee* createEmployee(int id, char name[], char birthplace[], char birthdate[], char position[]) {
    Employee* newEmployee = (Employee*) malloc(sizeof(Employee));
    newEmployee->id = id;
    strcpy(newEmployee->name, name);
    strcpy(newEmployee->birthplace, birthplace);
    strcpy(newEmployee->birthdate, birthdate);
    strcpy(newEmployee->position, position);
    newEmployee->next = NULL;
    return newEmployee;
    free(newEmployee);
}

// Fungsi untuk menambahkan data karyawan
void pushEmployee() {
    Employee employee;

    printf("Input Employee ID (Max 5 number): ");
    scanf("%d", &employee.id);
    printf("Input Employee Name: ");
    scanf("%s", employee.name);
    printf("Input Employee Birthplace: ");
    scanf("%s", employee.birthplace);
    printf("Input Employee Birthdate (Format DD-MM-YYYY): ");
    scanf("%s", employee.birthdate);
    printf("Input Employee Position: ");
    scanf("%s", employee.position);

    // Membuat node baru
    Employee* newEmployee = createEmployee(employee.id, employee.name, employee.birthplace, employee.birthdate, employee.position);

    // Menambahkan secara terurut berdasarkan Employee ID
    if (head == NULL) {
        head = newEmployee;
    } else {
        Employee* current = head;
        current->next = newEmployee;
        newEmployee->next = NULL;
    }

    printf("✅ Data karyawan berhasil ditambahkan!\n");
}

void showMenu() {
    int choice;
    do {
        printf("Employee Management System\n");
        printf("1. Add Employee\n");
        printf("2. Show Employee\n");
        printf("3. Delete Employee\n");
        printf("4. Delete All Employees\n");
        printf("5. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                pushEmployee();
                break;
            case 2:
                showEmployee();
                break;
            case 3:
                deleteEmployee();
                break;
            case 4:
                deleteAllEmployees();
                break;
            case 5:
                printf("Exit\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(choice != 4);

}

int main() {
    
    showMenu();
    return 0;
}

