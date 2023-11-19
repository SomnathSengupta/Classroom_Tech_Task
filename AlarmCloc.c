#include<stdio.h>
#include<time.h>
#include<unistd.h>
#include<stdlib.h>
#include<windows.h>

int main()
{
    int hour1, minute1, pause;

    // Taking the current time from the user:
    int current_hour, current_minute, current_second;
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    current_hour = tm_info->tm_hour;
    current_minute = tm_info->tm_min;
    current_second = tm_info->tm_sec;

    printf("\nEnter the alarm hour:");
    scanf("%d", &hour1);
    printf("Enter the alarm minute:");
    scanf("%d", &minute1);
    printf("\nAlarm has been set...\n");

    while (1) {
        int time_until_alarm = (hour1 - current_hour) * 3600 + (minute1 - current_minute) * 60 - current_second;

        system("cls"); // Clearing the output screen

        if (time_until_alarm == 30) {
            printf("Alarm will ring after %d seconds\n", time_until_alarm);
        }

        printf("%02d : %02d : %02d", current_hour, current_minute, current_second);
        fflush(stdout); // Clearing the output buffer

        current_second++;

        if (current_second == 60) {
            current_minute++;
            current_second = 0;
        }

        if (current_minute == 60) {
            current_hour++;
            current_minute = 0;
        }

        if (current_hour == 24) {
            current_hour = 0;
            current_minute = 0;
            current_second = 0;
        }

        if (current_hour == hour1 && current_minute == minute1) {
            while (1) {
                printf("\nAlarm is ringing....");
                Beep(2000, 3000);
                printf("\nEnter 1 to snooze for one minute and 2 for Pause:");
                scanf("%d", &pause);

                if (pause == 1) {
                    minute1 = minute1 + 1;
                    if (minute1 == 60) {
                        minute1 = 0;
                        hour1 = (hour1 + 1) % 24;
                    }
                    break;
                }

                if (pause == 2) {
                    printf("Alarm has been ended.");
                    exit(0);
                }
            }
        }

        pause = 0;
        sleep(1); // wait for 1 second
    }

    return 0;
}
