#include "student.h"

void print_menu(){
    printf("%s\n\n[1]  Add New Student%s",YELLOW, COLOR_END);
    printf("%s\n[2]  View All Students%s", YELLOW, COLOR_END);
    printf("%s\n[3]  Search Student Record%s", YELLOW, COLOR_END);
    printf("%s\n[4]  Update Student Record%s", YELLOW, COLOR_END);
    printf("%s\n[5]  Delete Student Record%s", YELLOW, COLOR_END);
    printf("%s\n[6]  View Statistical Summary%s", YELLOW, COLOR_END);
    printf("%s\n[7]  Backup Student Database%s", YELLOW, COLOR_END);
    printf("%s\n[8]  Restore Student Database%s", YELLOW, COLOR_END);
    printf("%s\n[9]  View Search History Log%s", YELLOW, COLOR_END);
    printf("%s\n[0]  Exit Application%s", YELLOW, COLOR_END);
}