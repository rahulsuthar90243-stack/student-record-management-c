#include<stdio.h>
#include<string.h>

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

}Student;

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
    
    return 0;

}



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
                update_view(student);
                break;
            case 2:
                update_name(student, course_choice);
                update_view(student);
                break;
            case 3:
                update_course(student, course_choice);
                update_view(student);
                break;
            case 4:
                update_semester(student, course_choice);
                update_view(student);
                break;
            case 5:
                update_gpa(student, course_choice);
                update_view(student);
                break;
            case 0:
                return;        
            default:
                printf("%s\nInvalid Option Press!%s", CYAN, COLOR_END);
        }

    }

}
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


void update_gpa(Student *student, char course_choice[]){
   FILE *fp = fopen("student.dat", "r+b");
    if(fp == NULL){
        printf("%s\nFile Opening Error!%s", RED, COLOR_END);
        return;
    }

    int id, found = 0;
    printf("\nEnter student current ID: ");
    scanf("%d", &id);
    getchar();

    while (fread(student, sizeof(Student), 1, fp)){
        if(student->id == id && strcmp(student->course, course_choice) == 0){
         
            printf("\nEnter student new gpa: ");
            scanf("%f", &student->gpa);

            fseek(fp, -sizeof(Student), SEEK_CUR);
            fwrite(student, sizeof(Student), 1, fp);
            found = 1;
            printf("%s\nGPA updated successfully.%s", GREEN, COLOR_END);
            break;
        }
    }

    if(found == 0){
        printf("%s\nStudent not found in this course!!!%s", CYAN, COLOR_END);
    }

    fclose(fp);    
}


void update_semester(Student *student, char course_choice[]){
    FILE *fp = fopen("student.dat", "r+b");
    if(fp == NULL){
        printf("%s\nFile Opening Error!%s", RED, COLOR_END);
        return;
    }

    int id, found = 0;
    printf("\nEnter student current ID: ");
    scanf("%d", &id);
    getchar();

    while (fread(student, sizeof(Student), 1, fp)){
        if(student->id == id && strcmp(student->course, course_choice) == 0){
         
            printf("\nEnter student new semester: ");
            scanf("%d", &student->semester);

            fseek(fp, -sizeof(Student), SEEK_CUR);
            fwrite(student, sizeof(Student), 1, fp);
            found = 1;
            printf("%s\nSemester updated successfully.%s", GREEN, COLOR_END);
            break;
        }
    }

    if(found == 0){
        printf("%s\nStudent not found in this course!!!%s", CYAN, COLOR_END);
    }

    fclose(fp);
    
}

void update_course(Student *student, char course_choice[]){

 FILE *fp = fopen("student.dat", "r+b");
 if(fp == NULL){
    printf("%s\nFile Opening Error!%s", RED, COLOR_END);
    return ;
 }

 int id, found = 0;
 printf("\nEnter student current ID: ");
 scanf("%d", &id);
 getchar();

 while (fread(student, sizeof(Student), 1, fp)){
    if(student->id == id && strcmp(student->course, course_choice) == 0){
      
        printf("Enter student new course: ");
        scanf("%s", student->course);

        fseek(fp, -sizeof(Student), SEEK_CUR);
        fwrite(student, sizeof(Student), 1, fp);

        found = 1;
        printf("%s\nCourse updated successfully.%s", GREEN, COLOR_END);
        break;
    }
 }
 
 if(found == 0){
    printf("%s\nStudent not found in this course!!!%s", CYAN, COLOR_END);
 }

 fclose(fp);

}


void update_name(Student *student, char course_choice[]){

 FILE *fp = fopen("student.dat", "r+b");
 if(fp == NULL){
    printf("%s\nFile Opening Error!%s", RED, COLOR_END);
    return ;
 }

 int id, found = 0;
 char new_name[50];
 printf("\nEnter student current ID: ");
 scanf("%d", &id);
 getchar();

 while (fread(student, sizeof(Student), 1, fp)){
     if(student->id == id && strcmp(student->course, course_choice) == 0){
      
        printf("Enter student new name: ");
        fgets(new_name, sizeof(new_name), stdin);
        new_name[strcspn(new_name, "\n")] = 0;

        strcpy(student->name, new_name);

        fseek(fp, -sizeof(Student), SEEK_CUR);
        fwrite(student, sizeof(Student), 1, fp);

        found = 1;
        printf("%s\nName updated successfully.%s", GREEN, COLOR_END);
        break;
     }
 }
 
 if(found == 0){
    printf("%s\nStudent not found in this course!!!%s", CYAN, COLOR_END);
 }

 fclose(fp);

}

void update_id(Student *student, char course_choice[]){
    FILE *fp = fopen("student.dat", "r+b");
    if(fp == NULL){
        printf("%s\nFile Opening Error!%s", RED, COLOR_END);
        return;
    }

    int id, found = 0;
    printf("\nEnter student ID: ");
    scanf("%d", &id);

    while (fread(student, sizeof(Student), 1, fp)){
        if(student->id == id && strcmp(student->course, course_choice) == 0){

            printf("\nEnter student new ID: ");
            scanf("%d", &student->id);

            fseek(fp, -sizeof(Student), SEEK_CUR);
            fwrite(student, sizeof(Student), 1, fp);

            found = 1;
            printf("%s\nID updated successfully.\n%s", GREEN, COLOR_END);
            break;
        }
    }

    if(found == 0){
        printf("%s\nStudent not found in this course!!!%s", CYAN, COLOR_END);
    }

    fclose(fp);
}

void delete_student(Student *student){
    FILE *fp = fopen("student.dat", "rb");
    FILE *temp = fopen("Temp.dat", "wb");

    if(fp == NULL || temp == NULL){
        printf("%s\nFile Opening Error!%s", RED, COLOR_END);
        return;
    }

    char course_copy[50];
    int id, found = 0, deleted = 0;

    printf("\nPlease, enter specific course: ");
    scanf("%s", course_copy);

    printf("\n ID     Name        Course       Semester    GPA");
    printf("\n-----------------------------------------------");

    while (fread(student, sizeof(Student), 1, fp)){
        if(strcmp(student->course, course_copy) == 0){
            printf("\n%-4d %-12s %-12s %-8d %.1f",
                   student->id,
                   student->name,
                   student->course,
                   student->semester,
                   student->gpa);
            found = 1;
        }
    }

    if(!found){
        printf("%s\nStudent not found in this course!!!%s", CYAN, COLOR_END);
        fclose(fp);
        fclose(temp);
        return;
    }

    rewind(fp);   
    printf("\n\nEnter student ID to delete: ");
    scanf("%d", &id);

    while (fread(student, sizeof(Student), 1, fp)){
        if(student->id == id && strcmp(student->course, course_copy) == 0){
            deleted = 1;  
        } else {
            fwrite(student, sizeof(Student), 1, temp);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("student.dat");
    rename("Temp.dat", "student.dat");

    if(deleted)
        printf("%s\nStudent Delete successfully.%s", GREEN, COLOR_END);
    else
        printf("%s\nStudent ID not found!%s", CYAN, COLOR_END);
}


void view_all_student(Student *student){
    
    FILE *fp = fopen("student.dat", "rb");
    if(fp == NULL){
        printf("%s\nFile Opening Error!%s", RED, COLOR_END);
        return;
    }

    int found = 0;
    char course_copy[50];
    int num;
    printf("Press 1 for all students, 2 for a specific course: ");
    scanf("%d",&num);

    if(num == 2){
    printf("Enter specific course: ");
    scanf("%s", course_copy);
    }
        printf("\n ID     Name     Course     Semester    GPA   ");
        printf("\n---------------------------------------------");

    while(fread(student, sizeof(Student), 1, fp)){
        if(num == 1){
            printf("\n%-4d %-12s %-12s %-8d %.1f",
               student->id,student->name,
               student->course,
               student->semester,
               student->gpa);
               found = 1;
            
   
        }else if(num == 2){
            if(strcmp(student->course , course_copy)== 0){
               printf("\n%-4d %-12s %-12s %-8d %.1f",
               student->id,student->name,
               student->course,
               student->semester,
               student->gpa);
               found = 1; 
            }
        }  
    }

    if(!found){
    printf("%s\nStudent not found in this course!!!%s", CYAN, COLOR_END);
    }
    fclose(fp);
}
void search_student(Student *student){
    
    FILE *fp = fopen("student.dat", "rb");
    if(fp == NULL){
        printf("%s\nFile Opening Error!%s", RED, COLOR_END);
        return;
    }

    int id;
    int found = 0;
    printf("\nEnter student ID: ");
    scanf("%d", &id);
    getchar();

        printf("\n ID     Name     Course     Semester    GPA   ");
        printf("\n---------------------------------------------");
    while(fread(student, sizeof(Student), 1, fp) == 1){
        if(student->id == id){
        printf("\n%-4d %-12s %-12s %-8d %.1f",
                  student->id,student->name,
                  student->course,
                  student->semester,
                  student->gpa);
                  found = 1;
               
        }
    }
        if(found != 1){
        printf("%s\nStudent not found in this ID!!!%s", CYAN, COLOR_END);
        }
    fclose(fp);
}


void add_student(Student *student){

    FILE * fp = fopen("student.dat", "ab");
    if(fp == NULL){
        printf("%s\nFile Opening Error!%s", RED, COLOR_END);
        return;
    }

    printf("\nAdd Student Recorde");
    printf("\nPlease, enter student Name: ");
    fgets(student->name, sizeof(student->name), stdin);
    student->name[strcspn(student->name, "\n")] = 0;


    printf("\nEnter student ID: ");
    scanf("%d", &student->id);
    getchar();

    printf("\nEnter student course: ");
    fgets(student->course, sizeof(student->course), stdin);
    student->course[strcspn(student->course, "\n")] = 0;


    printf("\nEnter student gpa: ");
    scanf("%f", &student->gpa);
    getchar();

    printf("\nEnter student semester: ");
    scanf("%d", &student->semester);
    getchar();

    fwrite(student, sizeof(Student), 1, fp);
    fclose(fp);

    printf("%s\nStudent record added successfully.%s\n", GREEN, COLOR_END);
}

void update_menu(){
    printf("%s\n\nPress 1. to update student ID%s", YELLOW, COLOR_END);
    printf("%s\nPress 2. to update student name%s", YELLOW, COLOR_END);
    printf("%s\nPress 3. to update student course%s", YELLOW, COLOR_END);
    printf("%s\nPress 4. to update student semester%s", YELLOW, COLOR_END);
    printf("%s\nPress 5. to update student GPA%s", YELLOW, COLOR_END);
    printf("%s\nPress 0. go to back%s", YELLOW, COLOR_END);
}


void print_menu(){
    printf("%s\n\n1.Add Student%s",YELLOW, COLOR_END);
    printf("%s\n2.View All Student%s", YELLOW, COLOR_END);
    printf("%s\n3.Search Student%s", YELLOW, COLOR_END);
    printf("%s\n4.Update Student%s", YELLOW, COLOR_END);
    printf("%s\n5.Delete Student%s", YELLOW, COLOR_END);
    printf("%s\n0.Exit%s", YELLOW, COLOR_END);
}