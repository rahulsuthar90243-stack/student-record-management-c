#include "student.h"

int is_id_exists(int id){
    FILE *fp = fopen("student.dat", "rb");
    Student temp;
    if(fp == NULL){
        printf("%s\nFile Opening Error!%s", RED, COLOR_END);
        return 0;
    }

    while(fread(&temp, sizeof(Student), 1, fp)){
        if(temp.id == id){
            return 1;
        }
    }
    fclose(fp);
    return 0;
}