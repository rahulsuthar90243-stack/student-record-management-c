#include "student.h"

void view_all_student(Student *student){
    
    FILE *fp = fopen("student.dat", "rb");
    if(fp == NULL){
        printf("%s\nFile Opening Error!%s", RED, COLOR_END);
        return;
    }

    int found = 0;
    char course_copy[50];
    int num;
    printf("Press 1 for all students, 2 for a specific course: ");
    scanf("%d",&num);

    if(num == 2){
    printf("Enter specific course: ");
    scanf("%s", course_copy);
    }
        printf("\n ID     Name     Course     Semester    GPA   ");
        printf("\n---------------------------------------------");

    while(fread(student, sizeof(Student), 1, fp)){
        if(num == 1){
            printf("\n%-4d %-12s %-12s %-8d %.1f",
               student->id,student->name,
               student->course,
               student->semester,
               student->gpa);
               found = 1;
            
   
        }else if(num == 2){
            if(strcmp(student->course , course_copy)== 0){
               printf("\n%-4d %-12s %-12s %-8d %.1f",
               student->id,student->name,
               student->course,
               student->semester,
               student->gpa);
               found = 1; 
            }
        }  
    }

    if(!found){
    printf("%s\nStudent not found in this course!!!%s", CYAN, COLOR_END);
    }
    fclose(fp);
}