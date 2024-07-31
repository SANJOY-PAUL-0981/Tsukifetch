#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/utsname.h>
#include <sys/sysinfo.h>

void print_ascii_art(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    fclose(file);
}

void print_system_info() {
    struct utsname uts;
    if (uname(&uts) < 0) {
        perror("uname");
        return;
    }
    printf("OS: %s %s\n", uts.sysname, uts.release);
}

void print_memory_info() {
    struct sysinfo info;
    if (sysinfo(&info) < 0) {
        perror("sysinfo");
        return;
    }
    printf("Memory: %ld MB / %ld MB\n", (info.totalram - info.freeram) / 1024 / 1024, info.totalram / 1024 / 1024);
}

void show_os_art() {
    struct utsname uts;
    if (uname(&uts) < 0) {
        perror("uname");
        return;
    }

    printf("Displaying ASCII Art:\n");
    printf("---------------------------------\n");

    if (strcmp(uts.sysname, "Linux") == 0) {
        if (strstr(uts.release, "arch") != NULL) {
            print_ascii_art("ASCII_art/logo/arch.txt");
        } else if (strstr(uts.release, "debian") != NULL) {
            print_ascii_art("ASCII_art/logo/debian.txt");
        } else if (strstr(uts.release, "fedora") != NULL) {
            print_ascii_art("ASCII_art/logo/fedora.txt");
        } else if (strstr(uts.release, "kubuntu") != NULL) {
            print_ascii_art("ASCII_art/logo/kubuntu.txt");
        } else if (strstr(uts.release, "linuxmint") != NULL) {
            print_ascii_art("ASCII_art/logo/linux_mint.txt");
        } else if (strstr(uts.release, "ubuntu") != NULL) {
            print_ascii_art("ASCII_art/logo/ubuntu.txt");
        } else {
            print_ascii_art("ASCII_art/logo/nothing.txt");
        }
    } else if (strcmp(uts.sysname, "Darwin") == 0) {
        print_ascii_art("ASCII_art/logo/mac.txt");
    } else if (strcmp(uts.sysname, "Windows") == 0) {
        print_ascii_art("ASCII_art/logo/windows.txt"); // Example, ensure you have this file
    } else {
        print_ascii_art("ASCII_art/logo/nothing.txt");
    }

    printf("\n---------------------------------\n");
}

int main() {
    printf("Welcome to Tsukifetch!\n");

    // Display the ASCII art based on the OS
    show_os_art();

    // Print system information
    print_system_info();
    printf("---------------------------------\n");
    print_memory_info();
    printf("---------------------------------\n");

    return 0;
}
