#include "student.h"

void dashboard_output(int total_students, float avg_gpa, float highest_gpa, CourseStat stats[], int course_total){

     printf("\n========== STATISTICS DASHBOARD ==========");
     printf("\n\n");
     printf("Total_Student   :%d", total_students);
     printf("\nAverage GPA     :%.2f", avg_gpa);
     printf("\nHighest GPA     :%.2f", highest_gpa);

     printf("\n\nCourse-wise Student Count:");
      
     for(int i = 0; i < course_total; i++){
        printf("\n%s   :%d", stats[i].course, stats[i].count);
     }

    printf("\n=========================================\n");
}