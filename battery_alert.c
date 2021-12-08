#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned short int battery_capacity(char *battery)
{
    FILE *fp;
    char battery_perc[3];
    char sys_path[] = "/sys/class/power_supply/";
    strcat(sys_path, battery);
    strcat(sys_path, "/capacity");

    fp = fopen(sys_path, "r");
    if(fp == NULL)
    {
        printf("File cannot be read \n");
        exit(1);
    }

    if (fgets(battery_perc, 3, fp) == NULL)
    {
        printf("Fail to get file contents\n");
        exit(1);
    }

    fclose(fp);

    return atoi(battery_perc);
}


int main(int argc, char **argv)
{
    int perc = 0;
    char *battery_name = "BAT0";
    perc = battery_capacity(battery_name);
    printf("%d%%\n", perc);

    return 0;
}

