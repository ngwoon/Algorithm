package 카카오_블라인드_채용_2018;

import java.util.HashMap;
import java.util.Stack;

/*
    진법과 주인공이 미리 알고싶은 숫자 개수, 게임에 참여하는 인원, 주인공의 순서가 주어질 때, 미리 알고싶은 숫자를 모은 문자열을 구하는 문제.

    <나의 풀이>
    특별한 알고리즘이 필요한 문제는 아니다.
    게임 규칙대로 숫자를 늘려가면서, 해당 숫자를 n진법으로 바꾸고 각 숫자 자리를 탐색하면서 주인공이 말해야 할 숫자를 저장, 반환했다.
 */

class NNumberGame {

    Stack<Integer> stk = new Stack<>();
    HashMap<Integer, String> hm = new HashMap<>();

    public String solution(int n, int t, int m, int p) {

        hm.put(10, "A");
        hm.put(11, "B");
        hm.put(12, "C");
        hm.put(13, "D");
        hm.put(14, "E");
        hm.put(15, "F");

        int num = 0;
        int turn = 0;
        boolean notOver = true;
        StringBuilder ans = new StringBuilder();
        while(notOver) {
            String numStr = tenToN(num, n);
            int idx = 0;
            while(idx < numStr.length()) {
                if(turn == p - 1) {
                    ans.append(numStr.charAt(idx));
                    if(ans.length() == t) {
                        notOver = false;
                        break;
                    }
                }
                ++idx;
                turn = (turn + 1) % m;
            }
            ++num;
        }

        return ans.toString();
    }

    public String tenToN(int num, int n) {

        if(n == 10) {
            return String.valueOf(num);
        }

        while(num > 0) {
            stk.push(num % n);
            num /= n;
        }

        if(stk.empty()) {
            stk.push(0);
        }

        StringBuilder sb = new StringBuilder();
        while(!stk.empty()) {
            int top = stk.pop();
            sb.append(top >= 10 ? hm.get(top) : top);
        }

        return sb.toString();
    }
}