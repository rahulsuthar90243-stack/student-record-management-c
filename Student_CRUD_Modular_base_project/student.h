#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <string.h>


extern const char* COLOR_END;
extern const char* RED;
extern const char* GREEN;
extern const char* YELLOW;
extern const char* CYAN;

typedef struct Student{
    int id;
    char name[50];
    char course[50];
    float gpa;
    int semester;
} Student;

typedef struct {
    char course[30];
    int count;
}CourseStat;

void print_menu();

void add_student(Student *student);
// Duplocate ID Detection
int is_id_exists(int id);
// Course Normalizetion
void normalize_course(char course[], int size);

void search_student(Student *student);
void log_search(int id, int found);

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

// Statistics Dashboard
void view_statistics(Student *student);
void dashboard_output(int total_students, float avg_gpa, float highest_gpa, CourseStat stats[], int course_total);


// Backup data and Restore data
void backup_data();
void restore_data();

#endif