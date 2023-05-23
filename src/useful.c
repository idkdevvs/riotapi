#include <stdio.h>
#include <string.h> // Add this line
#include "useful.h"

bool safe_user_input(char *buffer, int size){
    if (fgets(buffer, size, stdin) == NULL) {
        return false;
    }
    
    char* newline = strchr(buffer, '\n');
    if (newline){
        *newline = '\0';
    }
    return true;
}
