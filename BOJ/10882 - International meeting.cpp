#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int n;
    scanf("%d", &n);
    
    char time[6], utc[8];
    int ntimes[50];
    scanf("%s %s", time, utc);

    char chour[3], cmin[3], utcGap[5];
    strncpy(chour, time, 2); chour[2] = '\0';
    strncpy(cmin, time + 3, 2); cmin[2] = '\0';
    strcpy(utcGap, utc + 3);

    int hour = atoi(chour);
    int min = atoi(cmin);
    int minTime = hour*60 + min;

    float gap = atof(utcGap);

    minTime -= gap*60;
    if(minTime < 0)
        minTime += 1440;
    else if(minTime >= 1440)
        minTime -= 1440;

    for(int i=0; i<n; ++i) {
        memset(utc, '\0', 8);
        memset(utcGap, '\0', 5);

        scanf(" %s", utc);

        printf("utc : %s\n", utc);

        strcpy(utcGap, utc + 3);
        gap = atof(utcGap);

        ntimes[i] = minTime + gap*60;

        if(ntimes[i] < 0)
            ntimes[i] += 1440;
        else if(ntimes[i] >= 1440)
            ntimes[i] -= 1440;
    }

    for(int i=0; i<n; ++i)
        printf("%02d:%02d\n", ntimes[i]/60, ntimes[i]%60);
}