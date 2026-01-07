#include "student.h"

void update_student(Student *student){
    FILE *fp = fopen("student.dat", "rb");
    if(fp == NULL){
        printf("%s\nFile Opening Error!%s", RED, COLOR_END);
        return;
    }

    char course_choice[50];
    int press, found = 0;

    printf("\n\nUpdate student records");
    printf("\nPlease, enter specific course: ");
    scanf("%s", course_choice);

    printf("\n ID     Name        Course       Semester    GPA");
    printf("\n-----------------------------------------------");

    while (fread(student, sizeof(Student), 1, fp)){
        if(strcmp(student->course, course_choice) == 0){
            printf("\n%-4d %-12s %-12s %-8d %.1f",
                   student->id,
                   student->name,
                   student->course,
                   student->semester,
                   student->gpa);
            found = 1;
        }
    }
    fclose(fp);

    if(!found){
        printf("%s\nStudent not found in this course!!!%s", CYAN, COLOR_END);
        return;
    }

    while (1){
        update_menu();
        printf("\n\nPress option: ");
        scanf("%d", &press);

        switch (press){
            case 1:
                update_id(student, course_choice);
                break;
            case 2:
                update_name(student, course_choice);
                break;
            case 3:
                update_course(student, course_choice);
                break;
            case 4:
                update_semester(student, course_choice);
                break;
            case 5:
                update_gpa(student, course_choice);
                break;
            case 0:
                return;        
            default:
                printf("%s\nInvalid Option Press!%s", CYAN, COLOR_END);
        }

        update_view(student);

    }

}