// C Header Files
#include <sys/utsname.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ANSI colour codes
#define RED "\e[0;31m"
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

// ASCII art print func
char printASCII_Logo(const char *distro_name)
{

    if (strncmp(distro_name, "ubuntu", 3) == 0)
    {
        // ubuntu ASCII art
        printf("   __  __   __                         __          \n");
        printf("  / / / /  / /_     __  __   ____     / /_   __  __\n");
        printf(" / / / /  / __ \\   / / / /  / __ \\   / __/  / / / /\n");
        printf("/ /_/ /  / /_/ /  / /_/ /  / / / /  / /_   / /_/ / \n");
        printf("\\____/  /_.___/   \\__,_/  /_/ /_/   \\__/   \\__,_/  \n");
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
        printf("    __               __                         __          \n");
        printf("   / /__   __  __   / /_     __  __   ____     / /_   __  __\n");
        printf("  / //_/  / / / /  / __ \\   / / / /  / __ \\   / __/  / / / /\n");
        printf(" / ,<    / /_/ /  / /_/ /  / /_/ /  / / / /  / /_   / /_/ / \n");
        printf("/_/|_|   \\__,_/  /_.___/   \\__,_/  /_/ /_/   \\__/   \\__,_/  \n");
    }

    else if (strncmp(distro_name, "fedora", 3) == 0)
    {
        // fedora ASCII art
        printf("    ____               __                         \n");
        printf("   / __/  ___     ____/ /  ____     _____   ____ _\n");
        printf("  / /_   / _ \\   / __  /  / __ \\   / ___/  / __ `/\n");
        printf(" / __/  /  __/  / /_/ /  / /_/ /  / /     / /_/ / \n");
        printf("/_/     \\___/   \\__,_/   \\____/  /_/      \\__,_/  \n");
    }

    else if (strncmp(distro_name, "debian", 3) == 0)
    {
        // debian ASCII art
        printf("       __           __       _                 \n");
        printf("  ____/ /  ___     / /_     (_)  ____ _   ____ \n");
        printf(" / __  /  / _ \\   / __ \\   / /  / __ `/  / __ \\\n");
        printf("/ /_/ /  /  __/  / /_/ /  / /  / /_/ /  / / / /\n");
        printf("\\__,_/   \\___/  /_.___/  /_/   \\__,_/  /_/ /_/ \n");
    }

    else if (strncmp(distro_name, "arch", 3) == 0)
    {
        // arch ASCII art
        printf("     ___                       __ \n");
        printf("    /   |     _____   _____   / /_\n");
        printf("   / /| |    / ___/  / ___/  / __ \\\n");
        printf("  / ___ |   / /     / /__   / / / /\n");
        printf(" /_/  |_|  /_/      \\___/  /_/ /_/ \n");
    }

    else if (strncmp(distro_name, "linuxmint", 3) == 0)
    {
        // linux mint ASCII art
        printf("    __   _                                  __  ___   _             __ \n");
        printf("   / /  (_)  ____     __  __   _  __       /  |/  /  (_)  ____     / /_\n");
        printf("  / /  / /  / __ \\   / / / /  | |/_/      / /|_/ /  / /  / __ \\   / __/\n");
        printf(" / /  / /  / / / /  / /_/ /  _>  <       / /  / /  / /  / / / /  / /_  \n");
        printf("/_/  /_/  /_/ /_/   \\__,_/  /_/|_|      /_/  /_/  /_/  /_/ /_/   \\__/  \n");
        printf("                                                                        \n");
    }

    else
    {
        // none of this matched then tsukifetch printed
        printf("   __                      __      _            __       _                      \n");
        printf("  / /_   _____   __  __   / /__   (_)  _____   / /_     (_)  ____ ___     ____ _\n");
        printf(" / __/  / ___/  / / / /  / //_/  / /  / ___/  / __ \\   / /  / __ `__ \\   / __ `/\n");
        printf(" / /_   (__  )  / /_/ /  / ,<    / /  (__  )  / / / /  / /  / / / / / /  / /_/ / \n");
        printf("\\__/  /____/   \\__,_/  /_/|_|  /_/  /____/  /_/ /_/  /_/  /_/ /_/ /_/   \\__,_/  \n");
    }
}

// Read distro name
char *readDistroName()
{
    char *distro;
    FILE *infoFile;
    char *line = NULL;
    size_t n = 0;

    infoFile = fopen("/etc/os-release", "r");

    if (infoFile == NULL)
    {
        perror("Error in opening /etc/os-release");
        return NULL;
    }

    while (getline(&line, &n, infoFile) != -1)
    {
        if (strncmp(line, "ID=", 3) == 0)
        {
            distro = line + 3;
            break;
        }
    }

    fclose(infoFile);
    return distro;
}

// Read CPU info

int main(int argc, char const *argv[])
{
    // uname struct declaration
    struct utsname uts;
    uname(&uts);
    char *userName = getenv("USER");
    char *shellName = getenv("SHELL");
    char *distroName = readDistroName();
    // char *cpuStats = ;

    // ASCII art print
    printASCII_Logo(distroName);

    // info printing
    printf(RED "\n🭸🭸🭸🭬🭸🭸🭸🭬🭸🭸🭸🭬🭸🭸🭸🭬🭸🭸🭸🭬🭸🭸🭸🭬🭸🭸🭸🭬\n\n" RESET);
    printf(BOLD_PURPLE " 👤 USER: " WHITE "%s\n" RESET, userName);
    printf(BOLD_PURPLE " 📦 DISTRO: " WHITE "%s" RESET, distroName);
    printf(BOLD_PURPLE " 🌐 HOST: " WHITE "%s\n" RESET, uts.nodename);
    printf(BOLD_PURPLE " 📟 SHELL: " WHITE "%s\n" RESET, shellName);
    printf(BOLD_PURPLE " 💾 KERNEL: " WHITE "%s\n" RESET, uts.release);
    printf(BOLD_PURPLE " 🗄️  CPU: \n");
    // Desktop Env getenv() lib func
    char *desktop_Enviorment = getenv("XDG_CURRENT_DESKTOP");
    printf(BOLD_PURPLE " 🏙️  DE/WM: " WHITE "%s\n" RESET, desktop_Enviorment);

    printf(RED "\n🭸🭸🭸🭬🭸🭸🭸🭬🭸🭸🭸🭬🭸🭸🭸🭬🭸🭸🭸🭬🭸🭸🭸🭬🭸🭸🭸🭬\n" RESET);
    printf(BOLD_RED "> tsukishima - built by tsukixp\n" RESET);
    return 0;
}
