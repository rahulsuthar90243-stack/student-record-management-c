#include "student.h"

void dashboard_output(int total_students, float avg_gpa, float highest_gpa, CourseStat stats[], int course_total){

     printf("%s\n========== STATISTICS DASHBOARD ==========%s",  CYAN, COLOR_END);
     printf("\n\n");
     printf("Total_Student   :%d", total_students);
     printf("\nAverage GPA     :%.2f", avg_gpa);
     printf("\nHighest GPA     :%.2f", highest_gpa);

     printf("%s\n\nCourse-wise Student Count:%s", CYAN, COLOR_END);
      
     for(int i = 0; i < course_total; i++){
        printf("\n%-10s   :%d", stats[i].course, stats[i].count);
     }

    printf("%s\n=========================================\n%s", CYAN, COLOR_END);
}