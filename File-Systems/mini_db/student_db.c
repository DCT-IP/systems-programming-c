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
#include <string.h>
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
    FILE *ptr;
    ptr = fopen("Student_DB.bin", "ab");
    if(ptr == NULL){
        printf("ERR: The File couldn't be opened!!\n");
        return;
    } else {
        student stu;
        printf("Give Details of the student:-\n");
        printf("NAME: "); scanf(" %49[^\n]", stu.name);;
        printf("ID: "); scanf("%d", &stu.id);
        printf("Age: "); scanf("%d", &stu.age);
        fwrite(&stu,sizeof(student),1,ptr);
        printf("\nStudent Added Succesfully :3\n");
        fclose(ptr);
    }

}

void view_students(void)
{
    FILE *ptr;
    ptr = fopen("Student_DB.bin", "rb");
    if(ptr == NULL){
        printf("ERR: The File couldn't be opened!!\n");
        return;
    } else {
        printf("DataBase Found!!!\n");
        student stu_read;
        int count = 0;
        printf("\n============STUDENTS============\n");
        while(fread(&stu_read,sizeof(student),1,ptr)){
            printf("ID:   %d\n", stu_read.id);
            printf("Name: %s\n", stu_read.name);
            printf("Age:  %d\n", stu_read.age);
            count++;
        }
        if(count==0){
            printf("\nTHE DATABASE is Empty!!\n");
        }
        printf("\n================================\n");
    }
    fclose(ptr);
}

void search_student(void)
{
    FILE *ptr;
    ptr = fopen("Student_DB.bin", "rb");
    if(ptr==NULL){
        printf("ERR: The File couldn't be opened!!\n");
        return;
    } else {
        int id_find;
        student stu_search;
        int found = 0;
        printf("Enter the ID of the student you wanted to find: ");scanf("%d",&id_find);
        printf("\nStarting the search....\n");
        while(fread(&stu_search, sizeof(student),1,ptr) == 1){
            if(stu_search.id == id_find){
                
                break;
            }
        }
        if (found)
        {
            printf("\nID:   %d\n", stu_search.id);
            printf("Name: %s\n", stu_search.name);
            printf("Age:  %d\n", stu_search.age);
        } else {
            printf("\nNo such Student Found!!!\n");
        }
        
    }
    fclose(ptr);
}

void update_student(void)
{
    FILE *ptr = fopen("Student_DB.bin", "rb+");
    if(ptr == NULL)
    {
        printf("Database not found.\n");
        return;
    }
    int id;
    int found = 0;
    student stu;
    printf("Enter Student ID to update: ");
    scanf("%d", &id);
    while(fread(&stu, sizeof(student), 1, ptr) == 1)
    {
        if(stu.id == id)
        {
            found = 1;
            printf("Enter New Name: ");
            scanf(" %49[^\n]", stu.name);
            printf("Enter New Age: ");
            scanf("%d", &stu.age);
            fseek(ptr, -(long)sizeof(student), SEEK_CUR);
            fwrite(&stu, sizeof(student), 1, ptr);
            printf("Student Updated Successfully.\n");
            break;
        }
    }
    if(!found)
        printf("Student Not Found.\n");
    fclose(ptr);
}

void delete_student(void)
{
    FILE *ptr = fopen("Student_DB.bin", "rb");
    if(ptr == NULL)
    {
        printf("Database not found.\n");
        return;
    }
    FILE *temp = fopen("temp.bin", "wb");
    student stu;
    int id;
    int found = 0;
    printf("Enter Student ID to delete: ");
    scanf("%d", &id);
    while(fread(&stu, sizeof(student), 1, ptr) == 1)
    {
        if(stu.id == id)
        {
            found = 1;
            continue;
        }
        fwrite(&stu, sizeof(student), 1, temp);
    }
    fclose(ptr);
    fclose(temp);
    remove("Student_DB.bin");
    rename("temp.bin", "Student_DB.bin");
    if(found)
        printf("Student Deleted Successfully.\n");
    else
        printf("Student Not Found.\n");
}
