#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE* file = fopen("/mnt/ouichefs/test", "w");
    if (file == NULL) {
        perror("fopen failed");
        exit(EXIT_FAILURE);
    }

    char buffer[5000];
    memset(buffer, 'a', sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';
    fwrite(buffer, 1, sizeof(buffer) - 1, file);
    fseek(file, 3, SEEK_SET);
    fwrite("suite", 1, 5, file);
    fclose(file);
    return EXIT_SUCCESS;
}
