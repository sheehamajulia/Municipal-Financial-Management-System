//Employee Management
#include <stdio.h>
#include <string.h>

#include "EmployeeManagement.h"


#define MAX_EMPLOYEES 100
#define STR_LEN 50

//Global Arrays
char employeeID[MAX_EMPLOYEES][10];
char employeeName[MAX_EMPLOYEES][STR_LEN];
char employeeDept[MAX_EMPLOYEES][STR_LEN];
double basicSalary[MAX_EMPLOYEES];
double houseAllowance[MAX_EMPLOYEES];
double transportAllowance[MAX_EMPLOYEES];




int employeeCount = 0;

//Function Prototype
void employeeMenu(void);
void addEmployee(void);
void displayEmployee(void);
void searchEmployee(void);
void calculateSalary();
//displayInfo();




void employeeMenu (void) {

    char choice;

    do {

    puts("==============================================");
    puts("               EMPLOYEE MANAGEMENT            ");
    puts("==============================================");

    puts("1. Add an employee");
    puts("2. Display employee");
    puts("3. Search an employee");
    puts("4. Calculate employee salary");
    puts("5. Exit the system");

    printf("\nEnter a choice: ");
    scanf(" %c", &choice);
     
    switch (choice) {
        case '1':
            addEmployee();
            break;
        case '2':
           displayEmployee();
            break;
        case '3':
           searchEmployee();
            break;
        case '4':
           calculateSalary();
            break;
        case '5':
        //Exit the system
          puts("Exiting the system");
            break;
        default:
            puts("[!] Invalid choice, select between 1 to 5 [!]");
    }  
    
    } while (choice != '5');
}

void addEmployee (void) {

    if (employeeCount >= MAX_EMPLOYEES) {
        printf("!!! Database is full, can't add more employees.\n");
        return;
    }

    printf("\n-------Add Employee-------\n");
    
    //1. employeeID
    printf("Enter Employee ID: ");
    scanf("%s", employeeID[employeeCount]);

    getchar();
    
    //2. Full Name
    printf("Enter Full Name: ");
    fgets(employeeName[employeeCount], sizeof(employeeName[employeeCount]), stdin);

    //remove the "\n"
    employeeName[employeeCount][strcspn(employeeName[employeeCount], "\n")] = '\0';

    //3. Department
    printf("Enter Department: ");
    fgets(employeeDept[employeeCount], sizeof(employeeDept[employeeCount]), stdin);

    employeeDept[employeeCount][strcspn(employeeDept[employeeCount], "\n")] = '\0';

    //4. Basic Salary
    printf("Enter Basic Salary (N$): ");
    scanf("%lf", &basicSalary[employeeCount]);

    //5. House Allowance
    printf("Enter House Allowance (N$): ");
    scanf("%lf", &houseAllowance[employeeCount]);

    //6.Transport Allowance
    printf("Enter Transport Allowance (N$): ");
    scanf("%lf", &transportAllowance[employeeCount]);

    printf("\nEmployee %s is added succeccfully\n" ,employeeName[employeeCount]);
    printf("\n\n");

    employeeCount++;
    
}

void displayEmployee(void) {

    if (employeeCount == 0) {
        puts("");
        printf("No employees registered in the system\n");
        return;
    }

    puts("Employees in the system");
    puts("============================================");

    for (int i = 0; i < employeeCount; i++) {

        printf("No:              %d\n", i+1);
        printf("ID:              %s\n", employeeID[i]);
        printf("Name:            %s\n", employeeName[i]);
        printf("Department:      %s\n", employeeDept[i]);
        printf("Basic Salary:N$  %.2f\n", basicSalary[i]);
    
        puts("******************************************");
    }

}

void searchEmployee (void) {
    //if No employee is in the system
    if (employeeCount == 0) {
        puts("No employee registered in the system");
        return;
    }
   //variable
    char searchKey[STR_LEN];
    int found = 0;

    while (getchar() != '\n'); //clear the newline character from the previuos scanf

    //user input the the value to search
    printf("\n--------- Search Employee ---------\n");

    printf("Enter the Employee ID or Name to search: ");
    fgets(searchKey, sizeof(searchKey),stdin);

    //replace the newline character with the null terminate
    searchKey[strcspn(searchKey, "\n")] = '\0';

    for (int i = 0; i < employeeCount; i++) {

        //compare two the entered valued with the value in the array database

        if (strcmp(employeeID[i], searchKey) == 0 || strcmp(employeeName[i], searchKey) == 0) {
            //if value is found, it display this
            puts("Employee found: ");
            printf("ID:              %s\n", employeeID[i]);
            printf("Name:            %s\n", employeeName[i]);
            printf("Department:      %s\n", employeeDept[i]);
            printf("Basic Salary: N$ %.2f\n", basicSalary[i]);
            puts("------------------------------------------");

            //if a value is found, the variable found becomes 1
            found = 1;
            break;  ///break out of the loop
        }

    }
        //if value is not found
        if (!found) {
            printf("\nNo employee found matching ID or Name%s.\n", searchKey);
        }
    
}

void calculateSalary (void) {
