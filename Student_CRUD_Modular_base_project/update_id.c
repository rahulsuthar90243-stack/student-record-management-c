#include "student.h"

void update_id(Student *student, char course_choice[]){
    FILE *fp = fopen("student.dat", "r+b");
    if(fp == NULL){
        printf("%s\nFile Opening Error!%s", RED, COLOR_END);
        return;
    }

    int id, found = 0;
    printf("\nEnter student ID: ");
    scanf("%d", &id);

    while (fread(student, sizeof(Student), 1, fp)){
        if(student->id == id && strcmp(student->course, course_choice) == 0){

            printf("\nEnter student new ID: ");
            scanf("%d", &student->id);

            fseek(fp, -sizeof(Student), SEEK_CUR);
            fwrite(student, sizeof(Student), 1, fp);

            found = 1;
            printf("%s\nID updated successfully.\n%s", GREEN, COLOR_END);
            break;
        }
    }

    if(found == 0){
        printf("%s\nStudent not found in this course!!!%s", CYAN, COLOR_END);
    }

    fclose(fp);
}