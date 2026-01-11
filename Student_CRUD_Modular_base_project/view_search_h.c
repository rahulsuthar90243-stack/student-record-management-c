#include "student.h"

    void view_search_history() {
    FILE *hf = fopen("search_log.txt", "r");
    char line[200];

    if (hf == NULL) {
        printf("%s\nNo search history available\n%s", RED, COLOR_END);
        return;
    }

    printf("%s\n---- SEARCH HISTORY ----\n%s", CYAN, COLOR_END);
    while (fgets(line, sizeof(line), hf)) {
        printf("%s", line);
    }

    fclose(hf);
}