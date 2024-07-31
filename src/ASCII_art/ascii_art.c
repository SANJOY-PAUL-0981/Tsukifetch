#include <stdio.h>
#include <string.h>
#include "ascii_art.h"

// ANSI colour codes
#define RED "\e[0;31m"
#define LIGHT_RED "\033[1;31m"
#define CYAN "\033[1;36m"
#define BLUE "\033[1;34m"
#define YELLOW "\033[1;33m"
#define GREEN "\033[0;32m"
#define WHITE "\033[1;37m"
#define LIGHT_GRAY "\033[0;37m"
#define RESET "\033[0m"
#define PURPLE "\e[0;35m"
#define BOLD_RED "\e[1;31m"
#define BOLD_PURPLE "\e[1;35m"
#define ORANGE "\033[38;5;202m"
#define PINK "\033[38;5;206m"

// File Scan
void logoFile(const char *filename, const char *color_code) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char ch;
    printf("%s", color_code);
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    printf(RESET);
    fclose(file);
}

// ASCII art print func
void printASCII_Logo(const char *distro_name)
{
    char filename[100];

    switch (distro_name[0])
    {
    case 'u':
        if (strncmp(distro_name, "ubuntu", 6) == 0)
        {
            strcpy(filename, "usr/local/bin/tsukifetch/src/ASCII_art/logo/ubuntu.txt");
            logoFile(filename, ORANGE);
        }
        break;
    
    case 'p':
        if (strncmp(distro_name, "pop", 3) == 0)
        {
            //printf("pop"); //(use for debugging)
            strcpy(filename, "usr/local/bin/tsukifetch/src/ASCII_art/logo/pop.txt");
            logoFile(filename, GREEN);
        }
        break;

    case 'm':
        if (strncmp(distro_name, "mac", 3) == 0)
        {
            strcpy(filename, "src/ASCII_art/logo/mac.txt");
            logoFile(filename, LIGHT_GRAY);
        }
        break;

    case 'l':
        if (strncmp(distro_name, "linuxmint", 5) == 0)
        {
            strcpy(filename, "src/ASCII_art/logo/linux_mint.txt");
            logoFile(filename, CYAN);
        }
        break;
        
    case 'k':
        if (strncmp(distro_name, "kubuntu", 7) == 0)
        {
            strcpy(filename, "src/ASCII_art/logo/kubuntu.txt");
            logoFile(filename, BLUE);
        }
        break;
    
    case 'f':
        if (strncmp(distro_name, "fedora", 5) == 0)
        {
            strcpy(filename, "src/ASCII_art/logo/fedora.txt");
            logoFile(filename, PURPLE);
        }
        break;
    
    case 'd':
        if (strncmp(distro_name, "debian", 5) == 0)
        {
            strcpy(filename, "src/ASCII_art/logo/debian.txt");
            logoFile(filename, RED);
        }
        break;

    case 'a':
        if (strncmp(distro_name, "arch", 4) == 0)
        {
            strcpy(filename, "src/ASCII_art/logo/arch.txt");
            logoFile(filename, PURPLE);
        }
        break;
            
    default:
        strcpy(filename, "src/ASCII_art/logo/nothing.txt");
        logoFile(filename, YELLOW);
        break;
    }
}
