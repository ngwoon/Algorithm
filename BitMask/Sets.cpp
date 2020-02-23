// #include <stdio.h>
// #include <stdbool.h>
// #include <string.h>

// using namespace std;

// bool sets[21] = {false, };
// int T;

// int main(void) {
//     scanf("%d", &T);

//     for(int i=0; i<T; i++) {
//         char order[7];
//         int num;

//         scanf("%s", order);
//         if(strcmp(order, "all") && strcmp(order, "empty")) scanf(" %d", &num);

//         if(!strcmp(order, "add")) sets[num] = true;
//         else if(!strcmp(order, "remove")) sets[num] = false;
//         else if(!strcmp(order, "check")) printf("%d\n", sets[num]);
//         else if(!strcmp(order, "toggle")) sets[num] = !sets[num];
//         else if(!strcmp(order, "all")) memset(sets, true, 21);
//         else memset(sets, false, 21);
//     }   
// }

#include <cstdio>
#include <cstring>

int T;
int stat=0;

int main(void) {
    scanf("%d", &T);

    for(int i=0; i<T; i++) {
        char order[7];
        int num;

        scanf("%s", order);
        if(strcmp(order, "all") && strcmp(order, "empty")) scanf(" %d", &num);

        num -= 1;
        int numToBinary = (1<<num);
        if(order[0] == 'a' && order[1] == 'd') stat |= numToBinary;
        else if(order[0] == 'r') stat &= (~numToBinary);
        else if(order[0] == 'c') printf("%d\n", (stat & numToBinary) ? 1 : 0);
        else if(order[0] == 't') stat ^= numToBinary;
        else if(order[0] == 'a') stat = (1<<20) - 1;
        else stat = 0;
    }
}

