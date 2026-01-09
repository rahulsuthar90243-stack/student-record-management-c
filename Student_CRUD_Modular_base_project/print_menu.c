#include "student.h"

void print_menu(){
    printf("%s\n\n1.Add Student%s", YELLOW, COLOR_END);
    printf("%s\n2.View All Student%s" , YELLOW, COLOR_END);
    printf("%s\n3.Search Student%s" , YELLOW, COLOR_END);
    printf("%s\n4.Update Student%s ", YELLOW, COLOR_END);
    printf("%s\n5.Delete Student%s" , YELLOW, COLOR_END);
    printf("%s\n6.view statistics%s", YELLOW, COLOR_END);
    printf("%s\n0.Exit%s" , YELLOW, COLOR_END);
}