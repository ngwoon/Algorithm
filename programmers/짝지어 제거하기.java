import java.util.Stack;

/*
    문자열이 주어질 때, 짝지어 제거할 수 있는지 여부를 검사하는 문제.

    <나의 풀이>
    스택을 사용하면 어떤 인덱스에 인접한 문자들이 동일한 문자인지 아닌지를 쉽게 판별할 수 있다.
    문자열의 최대 길이가 100만이므로, 앞에서부터 문자열을 검사하면서 문자 비교 후 제거해나가는 방식은 문자열의 조작이 필요하므로 시간초과가 난다.
    그 대신, 문자열을 앞에서부터 문자 하나씩 스택에 넣으면서, 스택의 top과 비교하며 만약 같은 문자이면 스택 top을 제거하고, 그렇지 않으면 스택에 넣는 방법으로 문제를 풀 수 있다.
 */

class DeletePairs {
    public int solution(String s) {
        Stack<Character> stk = new Stack<>();
        for(int i=0; i<s.length(); ++i) {
            char c = s.charAt(i);
            if(stk.empty() || stk.peek() != c) {
                stk.push(c);
            } else {
                if(stk.peek() == c) {
                    stk.pop();
                }
            }
        }
        return stk.empty() ? 1 : 0;
    }
}