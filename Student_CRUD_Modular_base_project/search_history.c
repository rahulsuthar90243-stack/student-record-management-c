#include "student.h"

void log_search(int id, int found){

    FILE *hf = fopen("search_log.txt", "a");

    if(hf == NULL){
        printf("%s\nFile Opening Error!%s", RED, COLOR_END);
    }

    time_t now = time(NULL);

    char *time_str = ctime(&now);
    time_str[strcspn(time_str, "\n")] = 0;

    fprintf(hf, "[%s] Search ID: %d | %s\n",
            time_str,
            id,
            found ? "FOUND" : "NOT FOUND");

    fclose(hf);

}