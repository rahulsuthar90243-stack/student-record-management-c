#include "student.h"

void restore_data(){

    FILE *src = fopen("student_backup.dat", "rb");
    FILE *dest = fopen("student.dat", "wb");

    Student student;

    if(src == NULL){
        printf("%s\nFile Opening Error!%s", RED, COLOR_END);
    }

    if(dest == NULL){
        printf("%s\nBackup file creation failed!%s", RED, COLOR_END);
        fclose(src);
        return;
    }

    while(fread(&student, sizeof(Student), 1, src)){
        fwrite(&student, sizeof(Student), 1, dest);
    }

    fclose(src);
    fclose(dest);

    printf("%s\nBackup created successfully (student_backup.dat)%s", GREEN, COLOR_END);
}