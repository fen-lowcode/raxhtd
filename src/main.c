#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <limits.h>
#include "banner.h"

// Command-Line Interface (CLI) Design Pattern.
#define CLI_DESIGN \
    printf("~ ● -- ❯❯❯ ");



void traverse_dir(const char *path, int depth) {

    DIR *dir = opendir(path);
    if (!dir) {
        perror(path);
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // This skipps traversal methods
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char full[PATH_MAX];
        snprintf(full, sizeof(full), "%s/%s", path, entry->d_name);

        /* lstat so symlinks are not followed (avoids infinite loops) */
        struct stat st;
        if (lstat(full, &st) == -1) {
            perror(full);
            continue;
        }

        printf("%s\n", entry->d_name);
    }

    closedir(dir);
}


const char cmd_list[2][10] = {"help", "start"};


__attribute__((always_inline))
inline void showHelper() {
    printf("Type %s to list commands\n\n", cmd_list[0]);
}

__attribute__((always_inline))
inline void inputListener() {
    char cmd[100];
    while(1) {
        CLI_DESIGN
        if (fgets(cmd, sizeof(cmd), stdin) != NULL) {
             // finds \n from fgets because fgets includes \n and the replaces it  with \0
            cmd[strcspn(cmd, "\n")] = '\0';
        }

        if(strcmp(cmd, cmd_list[0]) == 0) {
            printf("type \"start\" - a file index.html at ./sites will be hosted\n");
        }

        if(strcmp(cmd, cmd_list[1]) == 0) {
            printf("Hosting site at ./sites - visit 127.0.0.1:8080\n");
            traverse_dir("./sites", 1 );
        }
    }   
}

__attribute__((always_inline))
inline void cliLoop() {

    printf(banner);
    showHelper();
    inputListener();

}

int main() {
    cliLoop();
}