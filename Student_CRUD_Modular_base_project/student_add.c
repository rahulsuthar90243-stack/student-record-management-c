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


    printf("\nEnter student ID: ");
    scanf("%d", &student->id);
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
