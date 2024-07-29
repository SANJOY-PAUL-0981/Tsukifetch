#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "system_info.h"

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
char *CPU_info(void)
{
    char *cp;
    FILE *cpuInfo;
    char *line = NULL;
    size_t n = 0;
    cpuInfo = fopen("/proc/cpuinfo", "r");
    if (cpuInfo == NULL)
    {
        perror("Error opening /proc/cpuinfo");
        return NULL;
    }
    while (getline(&line, &n, cpuInfo) != -1)
    {
        if (strncmp(line, "model name :", 10) == 0)
        {
            cp = line + 13;
            break;
        }
    }

    fclose(cpuInfo);
    return cp;
}