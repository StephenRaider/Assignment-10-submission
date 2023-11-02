#include <stdio.h>


struct Time {
    int hours;
    int minutes;
    int seconds;
};


struct Time calculateTimeDifference(struct Time t1, struct Time t2) {
    struct Time difference;
    int totalSeconds1 = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
    int totalSeconds2 = t2.hours * 3600 + t2.minutes * 60 + t2.seconds;
    int diffInSeconds = totalSeconds1 - totalSeconds2;

    // Handle negative differences by adding 24 hours
    if (diffInSeconds < 0) {
        diffInSeconds += 24 * 3600;
    }

    difference.hours = diffInSeconds / 3600;
    difference.minutes = (diffInSeconds % 3600) / 60;
    difference.seconds = (diffInSeconds % 3600) % 60;

    return difference;
}

int main() {
    struct Time time1, time2, timeDiff;

    printf("Enter the first time period (hh:mm:ss): ");
    scanf("%d:%d:%d", &time1.hours, &time1.minutes, &time1.seconds);

    printf("Enter the second time period (hh:mm:ss): ");
    scanf("%d:%d:%d", &time2.hours, &time2.minutes, &time2.seconds);

    timeDiff = calculateTimeDifference(time1, time2);

    printf("Time difference: %02d:%02d:%02d\n", timeDiff.hours, timeDiff.minutes, timeDiff.seconds);

    return 0;
}
