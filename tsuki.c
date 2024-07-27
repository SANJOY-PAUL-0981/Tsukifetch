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
#define BOLD_PURPLE "\e[1;35m"

int main(int argc, char const *argv[])
{
    // uname struct declaration
    struct utsname uts;
    uname(&uts);

    // ASCII art print

    // info printing
    printf(RED"\n🭸🭸🭸🭬🭸🭸🭸🭬🭸🭸🭸🭬🭸🭸🭸🭬🭸🭸🭸🭬🭸🭸🭸🭬🭸🭸🭸🭬\n\n" RESET);
    return 0;
}



