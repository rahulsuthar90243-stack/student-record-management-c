#include "student.h"

void view_statistics(Student *student){
FILE *fp = fopen("student.dat", "rb");
if(fp == NULL){
   printf("%s\nFile Opening Error!%s", RED, COLOR_END);
}

int total_student = 0;
float total_gpa = 0;
float highest_gpa = 0;

 // Course counters
 CourseStat starts[30];
 int course_total = 0;
 int found;
 
while(fread(student, sizeof(Student), 1, fp)){
    total_student++;
    total_gpa += student->gpa;

    if(student->gpa > highest_gpa){
        highest_gpa == student->gpa;
    }

    found = 0;
    for(int i = 0; i < course_total; i++){
        if(strcmp(starts[i].course, student ->course) == 0){
            starts[i].count++;
            found = 1;
            break;
        }
    }

    if(found = 0 && course_total < 30){
        if(strcpy(starts[course_total].course, student->course)){
            starts[course_total].count++;
            course_total++;
        }
    }

}
fclose(fp);

}