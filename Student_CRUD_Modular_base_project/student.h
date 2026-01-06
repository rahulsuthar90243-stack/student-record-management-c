#ifndef STUDENT_H
#define STUDENT_H

const char* COLOR_END = "\033[0m";
const char* RED ="\033[1;31m";   //.
const char* GREEN ="\033[1;32m";  //.
const char* YELLOW ="\033[1;33m";   //.
const char* BLUE ="\033[1;34m";   //.
const char* MAGENTA = "\033[0;35m";  //.
const char* CYAN = "\033[0;36m";  //.

typedef struct Student{
    int id;
    char name[50];
    char course[50];
    float gpa;
    int semester;
} Student;

void print_menu();
void add_student(Student *student);
void search_student(Student *student);
void delete_student(Student *student);
void view_all_student(Student *student);

// update 
void update_student(Student *student);
void update_menu();
void update_id(Student *student, char course_choice[]);
void update_name(Student *student, char course_choice[]);
void update_course(Student *student, char course_choice[]);
void update_semester(Student *student, char course_choice[]);
void update_gpa(Student *student, char course_choice[]);
void update_view(Student *student);



#endif