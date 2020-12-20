#include <bits/stdc++.h>
using namespace std;

/*
    5052번 - 전화번호 목록

    문자열 정렬 아이디어가 중요 포인트였던 문제.
    문자열 정렬은 첫째 자리부터 마지막 자리까지 각각 비교하므로 오름차순 정렬 시 앞 자리가 클수록, 길이가 길수록 뒤로 배치된다.
    문제에서 말하는 일관성이 없는 경우는 어떤 전화번호가 다른 전화번호의 부분 문자열이 되는가 이므로,
    서로 인접한 문자열 끼리만 비교하여 만약 부분문자열이 되면 NO를, 전부 탐색했을 때 그런 경우가 없으면 YES를 출력하면 된다.

    여담으로 이 문제는 Trie 알고리즘으로도 해결이 가능하다. 나중에 꼭 한 번 Trie 방식으로 풀어보자.
*/

vector<string> phone;
vector<vector<int>> pi;
string ans;
int t,s;

int main(void) {
    cin.sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;

    for(int k=0; k<t; ++k) {
        cin >> s;
        phone.resize(s);
        for(int i=0; i<s; ++i) cin >> phone[i];

        sort(phone.begin(), phone.end());

        bool printNo=false;
        for(int i=0; i<s-1; ++i) {
            string& s1 = phone[i];
            string& s2 = phone[i+1];

            if(s1.length() > s2.length()) continue;

            int s1Index=0, s2Index=0;
            bool notcs=true; // 일관성이 없는가를 저장하는 변수. true이면 일관성 없는, 즉 NO를 출력해야 한다.
            while(s1Index < s1.length() && s2Index < s2.length()) {
                if(s1[s1Index] != s2[s2Index]) { notcs=false; break; }
                ++s1Index; ++s2Index;
            }
            if(notcs) { printNo=true; break; }
        }
        if(printNo) ans.append("NO\n");
        else ans.append("YES\n");
    }
    cout << ans;
}