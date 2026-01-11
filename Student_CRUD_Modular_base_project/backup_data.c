#include "student.h"

void backup_data(){
    FILE *src = fopen("student.dat", "rb");
    FILE *dest = fopen("student_backup.dat", "wb");

    Student student;

    if(src == NULL || dest == NULL){
        printf("%s\nFile Opening Error!%s", RED, COLOR_END);
        return;
    }


    while(fread(&student, sizeof(Student), 1, src)){
       fwrite(&student, sizeof(Student), 1, dest);
    }

   fclose(src);
   fclose(dest);

    printf("%s\nData restored successfully from backup.%s", GREEN, COLOR_END);

}