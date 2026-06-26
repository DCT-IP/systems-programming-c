/*
We are building a database system, with a student database as our model reference
it has 
1. Data Model
    Student struct
    Constants

2. Database Operations
    add_student()
    view_students()
    search_student()
    update_student()
    delete_student()

3. User Interface
    menu()
    main()
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 50

//Data Type made to store informations
typedef struct {
    int id;
    char name[MAX];
    int age;
} student;

//Prototypes for our functions
void add_student(void);
void view_students(void);
void search_student(void);
void update_student(void);
void delete_student(void);
void menu(void);

//Main Function
int main(void){
    int choice;
    while(1){
        menu(); 
        printf("\nEnter your choice: "); scanf("%d", &choice);
        switch(choice){
            case 1: add_student(); break;
            case 2: view_students(); break;
            case 3: search_student(); break;
            case 4: update_student(); break;
            case 5: delete_student(); break;
            case 6: printf("Exiting..."); return 0;
            default: printf("Invalid Choice!!\n");
        }
    }
}// main end

void menu(void){
    printf("\n\n================Menu================\n");
    printf(" 1. Add a new Students \n");
    printf(" 2. View All Students  \n");
    printf(" 3. Search for a student  \n");
    printf(" 4. Update Details of a student \n");
    printf(" 5. Delete a Student's Detail  \n");
    printf(" 6. Exit the system\n");
    printf("======================================\n");
}

void add_student(void)
{
    printf("ok\n");
}

void view_students(void)
{
    printf("ok\n");
}

void search_student(void)
{
    printf("ok\n");
}

void update_student(void)
{
    printf("ok\n");
}
void delete_student(void)
{
    printf("ok\n");
}