#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#ifdef _WIN32
#include<windows.h>
#define CLEAR() system("cls")
#define SLEEP(x) Sleep(x * 1000)
#else
#include <unistd.h>
#define CLEAR() system("clear")
#define SLEEP(x) sleep(x)
#endif

int main() {
    int choice;
    printf("Welcome to digital clock : ");
    printf("\n---------------------------------\n");
    printf("Choose time format : \n");
    printf("1. 12 - Hour time Format.\n");
    printf("2. 24 - Hour time Format.\n");
    printf("Enter your choice : 1 or 2.\n");
    scanf("%d", &choice);
    if(choice < 1 || choice > 2) {
        printf("Invalid choice");
        return 1;
    }
    while(1) {
        time_t now;
        struct tm *currentTime;
        time(&now);
        currentTime = localtime(&now);
        int hour = currentTime->tm_hour;
        int minute = currentTime->tm_min;
        int second = currentTime->tm_sec;
        CLEAR();
        if(choice == 1) {
            char *ampm= "AM";
            if(hour >= 12) {
                ampm = "PM";
                if(hour > 12)
                hour -= 12;
            }
            if(hour == 0) 
                hour = 12;
                printf("Time : %02d:%02d:%02d %s\n", hour, minute, second, ampm);
        } else {
            printf("Time : %02d:%02d:%02d\n", hour, minute, second);
        }
        SLEEP(1);
    }
    return 0;
}