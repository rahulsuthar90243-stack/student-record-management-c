#include "student.h"

void update_course(Student *student, char course_choice[]){

 FILE *fp = fopen("student.dat", "r+b");
 if(fp == NULL){
    printf("%s\nFile Opening Error!%s", RED, COLOR_END);
    return ;
 }

 int id, found = 0;
 printf("\nEnter student current ID: ");
 scanf("%d", &id);
 getchar();

 while (fread(student, sizeof(Student), 1, fp)){
    if(student->id == id && strcmp(student->course, course_choice) == 0){
      
        printf("Enter student new course: ");
        scanf("%s", student->course);

        fseek(fp, -sizeof(Student), SEEK_CUR);
        fwrite(student, sizeof(Student), 1, fp);

        found = 1;
        printf("%s\nCourse updated successfully.%s", GREEN, COLOR_END);
        break;
    }
 }
 
 if(found == 0){
    printf("%s\nStudent not found in this course!!!%s", CYAN, COLOR_END);
 }

 fclose(fp);

}
