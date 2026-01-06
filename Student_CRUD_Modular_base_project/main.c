 #include "student.h"

 int main(){
 Student student; 
      printf("%s\n\n------------------------------------%s", CYAN, COLOR_END);
      printf("%s\n|      Student Record System       |%s", CYAN, COLOR_END);
      printf("%s\n------------------------------------%s", CYAN, COLOR_END);
    while (1){
      int choice;
        print_menu();
        printf("\n\nPlease,Enter Your Choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice){
        case 1:
            add_student(&student);
            break;
        case 2:
            view_all_student(&student);
            break;    
        case 3:
            search_student(&student);
            break;
        case 4:
            update_student(&student);
            break;  
        case 5:
            delete_student(&student);
            break;
        case 0:
            printf("%s\nProgram terminated successfully. Thank you for visiting.%s", CYAN, COLOR_END);
            printf("%s\n\n------------------------------%s", CYAN, COLOR_END);
            printf("%s\n|     Developed by Rahul     |%s", CYAN, COLOR_END);
            printf("%s\n------------------------------%s", CYAN, COLOR_END);
            return 0;          
        default:
            if(choice > 5){
            printf("%s\nInvalid Choice%s", CYAN, COLOR_END);
            }
        }

     }
    }