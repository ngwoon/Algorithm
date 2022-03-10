package 월간_코드_챌린지_시즌2;

import java.util.Stack;

/*
    연속된 괄호들이 문자열로 주어질 때, 이 문자열을 왼쪽 시프트하여 만들 수 있는 올바른 괄호 문자열의 개수를 구하는 문제.

    <나의 풀이>
    문제 조건 그대로 풀면 된다.
    올바른 괄호 문자열인지 판단하는 방법은, 스택을 활용하면 된다.
    문자열을 앞에서부터 순차 탐색하면서, 열린 괄호를 만나면 스택에 넣고, 닫힌 괄호를 만나면 스택의 top과 쌍이 맞는지 확인한다.
    쌍이 맞지 않은 경우가 있거나, 작업 후 스택에 열린 괄호가 남아있다면 올바르지 않은 괄호 문자열이다.
 */

class RotateParenthesis {
    public int solution(String s) {
        int len = s.length();
        int ans = 0;
        while(len-- > 0) {
            String shifted = leftShift(s);
            if(isRightParentheses(s)) {
                ++ans;
            }
            s = shifted;
        }

        return ans;
    }

    public String leftShift(String s) {
        StringBuilder sb = new StringBuilder(s);
        char c = sb.charAt(0);
        sb.deleteCharAt(0);
        sb.append(c);
        return sb.toString();
    }

    public boolean isRightParentheses(String p) {
        Stack<Character> stk = new Stack<>();
        for(int i=0; i<p.length(); ++i) {
            char c = p.charAt(i);
            if(stk.isEmpty() || isOpen(c)) {
                stk.add(c);
            } else {
                char o = stk.pop();
                if(!(o == '(' && c == ')') && !(o == '[' && c == ']') && !(o == '{' && c == '}')) {
                    return false;
                }
            }
        }

        return stk.isEmpty();
    }
    public boolean isOpen(char c) {
        return c == '(' || c == '[' || c == '{';
    }
}