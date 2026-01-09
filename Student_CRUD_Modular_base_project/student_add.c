#include "student.h"

void add_student(Student *student){

    FILE * fp = fopen("student.dat", "ab");
    if(fp == NULL){
        printf("%s\nFile Opening Error!%s", RED, COLOR_END);
        return;
    }

    printf("\nAdd Student Recorde");
    printf("\nPlease, enter student Name: ");
    fgets(student->name, sizeof(student->name), stdin);
    student->name[strcspn(student->name, "\n")] = 0;


    
   
    do{
       printf("\nEnter student ID: ");
       scanf("%d", &student->id);

       if(is_id_exists(student->id)){
        printf("%s\nThis ID already exists. Please enter a different ID.%s", RED, COLOR_END);
       }

    }while(is_id_exists(student->id));

    getchar();

    printf("\nEnter student course: ");
    fgets(student->course, sizeof(student->course), stdin);
    student->course[strcspn(student->course, "\n")] = 0;


    printf("\nEnter student gpa: ");
    scanf("%f", &student->gpa);
    getchar();

    printf("\nEnter student semester: ");
    scanf("%d", &student->semester);
    getchar();

    fwrite(student, sizeof(Student), 1, fp);
    fclose(fp);

    printf("%s\nStudent record added successfully.%s\n", GREEN, COLOR_END);
}
