// #include <stdio.h>
// #include <string.h>
// #define MAX_SIZE 100001

// void reverseStr(char* str, int* s, int* e) {
//     int sv = *s;
//     int ev = *e;
//     if(sv != -1) {
//         int std = sv+ev;
//         int m = std/2;
//         for(int i=sv; i<=m; ++i) {
//             int counter = std-i;
//             char temp = str[i];
//             str[i] = str[counter];
//             str[counter] = temp; 
//         }
//         *s = -1; *e = -1;
//     }
// }

// int main(void) {
//     char str[100002];
//     fgets(str, MAX_SIZE, stdin);
//     str[strlen(str) - 1] = '\0';

//     int idx = 0;
//     int s = -1, e = -1;
//     while(str[idx] != '\0') {
//         if(str[idx] == '<') {
//             reverseStr(str, &s, &e);
//             while(str[idx] != '>')
//                 ++idx;
//         } else if(str[idx] == ' ')
//             reverseStr(str, &s, &e);
//         else {
//             if(s == -1) {
//                 s = idx; e = idx;
//             } else
//                 ++e;
//         }
//         ++idx;
//     }
//     reverseStr(str, &s, &e);
//     printf("%s", str);
// }

#include <bits/stdc++.h>
using namespace std;

void reverseStr(string& str, int* s, int* e) {
    int sv = *s;
    int ev = *e;
    if(sv != -1) {
        int std = sv+ev;
        int m = std/2;
        for(int i=sv; i<=m; ++i) {
            int counter = std-i;
            char temp = str[i];
            str[i] = str[counter];
            str[counter] = temp; 
        }
        *s = -1; *e = -1;
    }
}

int main(void) {
    string str;
    getline(cin, str);

    int s = -1, e = -1;
    int len = str.length();
    for(int i=0; i<len; ++i) {
        if(str[i] == ' ')
            reverseStr(str, &s, &e);
        else if(str[i] == '<') {
            reverseStr(str, &s, &e);
            while(str[i] != '>')
                ++i;
        } else {
            if(s == -1) {
                s = i; e = i;
            } else
                ++e;
        }
    }
    reverseStr(str, &s, &e);
    cout << str;
}