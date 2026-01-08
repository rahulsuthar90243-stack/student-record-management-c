#include "student.h"

void search_student(Student *student){
    
    FILE *fp = fopen("student.dat", "rb");
    if(fp == NULL){
        printf("%s\nFile Opening Error!%s", RED, COLOR_END);
        return;
    }

    int id;
    int found = 0;
    printf("\nEnter student ID: ");
    scanf("%d", &id);
    getchar();

        printf("\n ID     Name     Course     Semester    GPA   ");
        printf("\n---------------------------------------------");
    while(fread(student, sizeof(Student), 1, fp) == 1){
        if(student->id == id){
        printf("\n%-4d %-12s %-12s %-8d %.1f",
                  student->id,student->name,
                  student->course,
                  student->semester,
                  student->gpa);
                  found = 1;
               
        }
    }
        if(found != 1){
        printf("%s\nStudent not found in this ID!!!%s", CYAN, COLOR_END);
        }
    fclose(fp);
}
