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
 
while(fread(student, sizeof(Student), 1, fp)){
    total_student++;
    total_gpa += student->gpa;

    if(student->gpa > highest_gpa){
        highest_gpa == student->gpa;
    }

}

}