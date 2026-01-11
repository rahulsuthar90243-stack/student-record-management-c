#include "student.h"

void normalize_course(char course[], int size){
    for(int i = 0; i < size && course[i] != '\0'; i++){
        if(course[i] >= 'a' && course[i] <= 'z'){
            course[i] -= 32;
        }
    }
}