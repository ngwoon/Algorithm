#include <bits/stdc++.h>
using namespace std;

/*
    16742번 - 고냥이
    
    주어진 알파벳 종류 제한 내에서 문자열 내의 가장 긴 부분문자열을 찾는 문제이다.
    특별한 알고리즘이 쓰였다기보단, 문자열을 0 ~ N-1 인덱스까지 훑으면서 현재 범위 내의 알파벳 갯수를 센다.
    알파벳 갯수가 제한을 넘기면, 부분문자열 내 가장 앞에 등장한 알파벳을 지우고 새로 등장한 알파벳을 추가하는
    형식으로 구현한다.
*/

int alpha[26];
string str;
int n,ans;

int main(void) {
    cin.sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> str;

    memset(alpha, -1, sizeof(alpha));

    int s=0, e=0;
    int cnt=0;
    for(;e<str.size();) {
        if(cnt < n) {
            if(alpha[str[e]-'a'] == -1) {
                alpha[str[e]-'a'] = e;
                ++cnt;
            }
            ++e;
        }
        else if(cnt == n) {
            ans = max(ans, e-s);
            if(alpha[str[e]-'a'] == -1) {
                if(alpha[str[s]-'a'] == s) {
                    --cnt;
                    alpha[str[s]-'a'] = -1;
                }
                ++s;
            }
            else {
                alpha[str[e]-'a'] = e;
                ++e;
            }
        }
    }
    ans = max(ans, e-s);
    cout << ans;
}