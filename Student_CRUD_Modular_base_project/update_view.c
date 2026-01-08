# include "student.h"

void update_view(Student *student){
    int num;
    printf("\n\nPress 1 to view students | Press 0 to return: "); 
    scanf("%d", &num);
    if(num == 1){
        view_all_student(student);
    }else if(num == 2){
        return;
    }else{
        printf("%s\nInvalid choice!%s", CYAN, COLOR_END);
    }
}
