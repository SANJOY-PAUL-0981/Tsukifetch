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

// ASCII art print func
void printASCII_Logo(const char *distro_name)
{

    if (strncmp(distro_name, "ubuntu", 3) == 0)
    {
        // ubuntu ASCII art
        printf(LIGHT_RED "   __  __   __                         __          \n");
        printf(LIGHT_RED "  / / / /  / /_     __  __   ____     / /_   __  __\n");
        printf(LIGHT_RED " / / / /  / __ \\   / / / /  / __ \\   / __/  / / / /\n");
        printf(LIGHT_RED "/ /_/ /  / /_/ /  / /_/ /  / / / /  / /_   / /_/ / \n");
        printf(LIGHT_RED "\\____/  /_.___/   \\__,_/  /_/ /_/   \\__/   \\__,_/  \n");
    }

    else if (strncmp(distro_name, "pop", 3) == 0)
    {
        // pop OS ASCII art
        printf(GREEN "    ____                 __   ____  _____\n");
        printf(GREEN "   / __ \\____  ____     / /  / __ \\/ ___/\n");
        printf(GREEN "  / /_/ / __ \\/ __ \\   / /  / / / /\\__ \\ \n");
        printf(GREEN " / ____/ /_/ / /_/ /  /_/  / /_/ /___/ / \n");
        printf(GREEN "/_/    \\____/ .___/  (_)   \\____//____/  \n");
        printf(GREEN "           /_/                            \n");
    }

    else if (strncmp(distro_name, "kubuntu", 3) == 0)
    {
        // kubuntu ASCII art
        printf(BLUE "    __               __                         __          \n");
        printf(BLUE "   / /__   __  __   / /_     __  __   ____     / /_   __  __\n");
        printf(BLUE "  / //_/  / / / /  / __ \\   / / / /  / __ \\   / __/  / / / /\n");
        printf(BLUE " / ,<    / /_/ /  / /_/ /  / /_/ /  / / / /  / /_   / /_/ / \n");
        printf(BLUE "/_/|_|   \\__,_/  /_.___/   \\__,_/  /_/ /_/   \\__/   \\__,_/  \n");
    }

    else if (strncmp(distro_name, "fedora", 3) == 0)
    {
        // fedora ASCII art
        printf(PURPLE "    ____               __                         \n");
        printf(PURPLE "   / __/  ___     ____/ /  ____     _____   ____ _\n");
        printf(PURPLE "  / /_   / _ \\   / __  /  / __ \\   / ___/  / __ `/\n");
        printf(PURPLE " / __/  /  __/  / /_/ /  / /_/ /  / /     / /_/ / \n");
        printf(PURPLE "/_/     \\___/   \\__,_/   \\____/  /_/      \\__,_/  \n");
    }

    else if (strncmp(distro_name, "debian", 3) == 0)
    {
        // debian ASCII art
        printf(RED "       __           __       _                 \n");
        printf(RED "  ____/ /  ___     / /_     (_)  ____ _   ____ \n");
        printf(RED " / __  /  / _ \\   / __ \\   / /  / __ `/  / __ \\\n");
        printf(RED "/ /_/ /  /  __/  / /_/ /  / /  / /_/ /  / / / /\n");
        printf(RED "\\__,_/   \\___/  /_.___/  /_/   \\__,_/  /_/ /_/ \n");
    }

    else if (strncmp(distro_name, "arch", 3) == 0)
    {
        // arch ASCII art
        printf(PURPLE "     ___                       __ \n");
        printf(PURPLE "    /   |     _____   _____   / /_\n");
        printf(PURPLE "   / /| |    / ___/  / ___/  / __ \\\n");
        printf(PURPLE "  / ___ |   / /     / /__   / / / /\n");
        printf(PURPLE " /_/  |_|  /_/      \\___/  /_/ /_/ \n");
    }

    else if (strncmp(distro_name, "linuxmint", 3) == 0)
    {
        // linux mint ASCII art
        printf(CYAN "    __   _                                  __  ___   _             __ \n");
        printf(CYAN "   / /  (_)  ____     __  __   _  __       /  |/  /  (_)  ____     / /_\n");
        printf(CYAN "  / /  / /  / __ \\   / / / /  | |/_/      / /|_/ /  / /  / __ \\   / __/\n");
        printf(CYAN " / /  / /  / / / /  / /_/ /  _>  <       / /  / /  / /  / / / /  / /_  \n");
        printf(CYAN "/_/  /_/  /_/ /_/   \\__,_/  /_/|_|      /_/  /_/  /_/  /_/ /_/   \\__/  \n");
        printf(CYAN "                                                                        \n");
    }

    else if (strncmp(distro_name, "macos", 3) == 0)
    {
        // macOS ASCII art
        printf(LIGHT_GRAY "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⠀⠀⠀⠀⠀⠀\n");
        printf(LIGHT_GRAY "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⡿⠀⠀⠀⠀⠀⠀\n");
        printf(LIGHT_GRAY "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⣿⣿⠟⠁⠀⠀⠀⠀⠀⠀\n");
        printf(LIGHT_GRAY "⠀⠀⠀⢀⣠⣤⣤⣤⣀⣀⠈⠋⠉⣁⣠⣤⣤⣤⣀⡀⠀⠀\n");
        printf(LIGHT_GRAY "⠀⢠⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⡀\n");
        printf(LIGHT_GRAY "⣠⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠋⠀\n");
        printf(LIGHT_GRAY "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡏⠀⠀⠀\n");
        printf(LIGHT_GRAY "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀\n");
        printf(LIGHT_GRAY "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⠀⠀⠀\n");
        printf(LIGHT_GRAY "⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣤⣀\n");
        printf(LIGHT_GRAY "⠀⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠁\n");
        printf(LIGHT_GRAY "⠀⠀⠙⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠁⠀\n");
        printf(LIGHT_GRAY "⠀⠀⠀⠈⠙⢿⣿⣿⣿⠿⠟⠛⠻⠿⣿⣿⣿⡿⠋⠀⠀⠀\n");
    }

    else
    {
        // none of this matched then tsukifetch printed
        printf(YELLOW "   __                      __      _            __       _                      \n");
        printf(YELLOW "  / /_   _____   __  __   / /__   (_)  _____   / /_     (_)  ____ ___     ____ _\n");
        printf(YELLOW " / __/  / ___/  / / / /  / //_/  / /  / ___/  / __ \\   / /  / __ `__ \\   / __ `/\n");
        printf(YELLOW " / /_   (__  )  / /_/ /  / ,<    / /  (__  )  / / / /  / /  / / / / / /  / /_/ / \n");
        printf(YELLOW "\\__/  /____/   \\__,_/  /_/|_|  /_/  /____/  /_/ /_/  /_/  /_/ /_/ /_/   \\__,_/  \n");
    }
}
