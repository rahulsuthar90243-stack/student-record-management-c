#include "student.h"

void delete_student(Student *student){
    FILE *fp = fopen("student.dat", "rb");
    FILE *temp = fopen("Temp.dat", "wb");

    if(fp == NULL || temp == NULL){
        printf("%s\nFile Opening Error!%s", RED, COLOR_END);
        return;
    }

    char course_copy[50];
    int id, found = 0, deleted = 0;

    printf("\nPlease, enter specific course: ");
    scanf("%s", course_copy);
    normalize_course(course_copy, sizeof(course_copy));

    printf("\n ID     Name        Course       Semester    GPA");
    printf("\n-----------------------------------------------");

    while (fread(student, sizeof(Student), 1, fp)){
        if(strcmp(student->course, course_copy) == 0){
            printf("\n%-4d %-12s %-12s %-8d %.1f",
                   student->id,
                   student->name,
                   student->course,
                   student->semester,
                   student->gpa);
            found = 1;
        }
    }

    if(!found){
        printf("%s\nStudent not found in this course!!!%s", CYAN, COLOR_END);
        fclose(fp);
        fclose(temp);
        return;
    }

    rewind(fp);   
    printf("\n\nEnter student ID to delete: ");
    scanf("%d", &id);

    while (fread(student, sizeof(Student), 1, fp)){
        if(student->id == id && strcmp(student->course, course_copy) == 0){
            deleted = 1;  
        } else {
            fwrite(student, sizeof(Student), 1, temp);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("student.dat");
    rename("Temp.dat", "student.dat");

    if(deleted)
        printf("%s\nStudent Delete successfully.%s", GREEN, COLOR_END);
    else
        printf("%s\nStudent ID not found!%s", CYAN, COLOR_END);
}