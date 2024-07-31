#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/utsname.h>
#include <sys/sysinfo.h>

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
        print_ascii_art("ASCII_art/logo/windows.txt");
    } else {
        print_ascii_art("ASCII_art/logo/nothing.txt");
    }

    printf("\n---------------------------------\n");
}

void print_user_info() {
    char *userName = getenv("USER");
    char *shellName = getenv("SHELL");
    printf(BOLD_PURPLE "\n\n 👤 USER: " WHITE "%s\n" RESET, userName);
    printf(BOLD_PURPLE " 📟 SHELL: " WHITE "%s\n" RESET, shellName);
}

void print_distro_info() {
    char *distroName = "Unknown"; // You can replace this with actual logic to get distro name
    printf(BOLD_PURPLE " 📦 DISTRO: " WHITE "%s" RESET, distroName);
}

void print_cpu_info() {
    char *cpuStats = "Intel Core i7"; // Placeholder, replace with actual logic to get CPU info
    printf(BOLD_PURPLE " 🗄️  CPU: " WHITE "%s" RESET, cpuStats);
}

void print_desktop_env() {
    char *desktop_Environment = getenv("XDG_CURRENT_DESKTOP");
    printf(BOLD_PURPLE " 🏙️  DE/WM: " WHITE "%s\n" RESET, desktop_Environment);
}

int main() {
    printf("Welcome to Tsukifetch!\n");

    // Display the ASCII art based on the OS
    show_os_art();

    // System information
    struct utsname uts;
    uname(&uts);
    printf(BOLD_PURPLE " 🌐 HOST: " WHITE "%s\n" RESET, uts.nodename);
    printf(BOLD_PURPLE " 💾 KERNEL: " WHITE "%s\n" RESET, uts.release);

    // Print user info, distro info, and CPU info
    print_user_info();
    print_distro_info();
    print_cpu_info();
    print_desktop_env();

    // Memory information
    print_memory_info();
    printf("---------------------------------\n");

    // Footer
    printf(CYAN "\n🭸🭸🭸🭬🭸🭸🭸🭬🭸🭸🭸🭬🭸🭸🭸🭬🭸🭸🭸🭬🭸🭸🭸🭬🭸🭸🭸🭬\n" RESET);
    printf(YELLOW "> tsukishima - built by tsukishima\n" RESET);
    return 0;
}
