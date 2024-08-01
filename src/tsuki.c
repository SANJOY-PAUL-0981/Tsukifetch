// header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/utsname.h>
#include <sys/sysinfo.h>
#include "sys_info/system_info.h"
#include "ASCII_art/ascii_art.h"

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

//Absolute Path
#define LOGO_PATH "/usr/local/share/tsukifetch/logos/"

int main(int argc, char const *argv[])
{
    // uname struct declaration
    struct utsname uts;
    struct sysinfo sys_info;
    uname(&uts);
    char *userName = getenv("USER");
    char *shellName = getenv("SHELL");
    char *distroName = readDistroName();
    char *cpuStats = CPU_info();

    // Check sysinfo call
    if (sysinfo(&sys_info) != 0) {
        perror("sysinfo");
        return -1;
    }

    // ASCII art print
    printf("\n\n");
    printASCII_Logo(distroName);

    // info printing
    printf(BOLD_PURPLE "\n\n 👤 USER: " WHITE "%s\n" RESET, userName);
    printf(BOLD_PURPLE " 📦 DISTRO: " WHITE "%s" RESET, distroName);
    printf(BOLD_PURPLE " 🌐 HOST: " WHITE "%s\n" RESET, uts.nodename);
    printf(BOLD_PURPLE " 📟 SHELL: " WHITE "%s\n" RESET, shellName);
    printf(BOLD_PURPLE " 💾 KERNEL: " WHITE "%s\n" RESET, uts.release);

    // Desktop Env getenv() lib func
    char *desktop_Enviorment = getenv("XDG_CURRENT_DESKTOP");
    printf(BOLD_PURPLE " 🏙️  DE/WM: " WHITE "%s\n" RESET, desktop_Enviorment);
    printf(BOLD_PURPLE " 🗄️  CPU: " WHITE "%s" RESET, cpuStats);
    printf(BOLD_PURPLE " 🗂  RAM: " WHITE "%ld/%ld" RESET, sys_info.freeram / 1024 / 1024, sys_info.totalram / 1024 / 1024);

    printf(RED "\n🭸🭸🭸🭬🭸🭸🭸🭬🭸🭸🭸🭬🭸🭸🭸🭬🭸🭸🭸🭬🭸🭸🭸🭬🭸🭸🭸🭬\n" RESET);
    printf(YELLOW "> tsukishima - built by tsukixp\n" RESET);
    return 0;
}