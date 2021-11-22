import java.util.*;

/*
    주어진 숫자 문자열에서 k개의 수를 제외해서 만들 수 있는 수 중 가장 큰 수를 구하는 문제

    <나의 풀이>
    처음에 많이 헤맸지만, 최대한 높은 자리수에서 작은 수들을 제거하는 greedy한 방법이 정답일거라는 추측과 함께,
    문자열을 차례로 순회하다가 이전 숫자보다 큰 수를 마주하면 그 지점의 수보다 앞에있는 수들 중 작은 수들을 모두 제거하는 방법을 생각했다.
    가장 시간복잡도가 좋게 해결하는 방법은 Stack을 이용하는 방법이고, 이 방법으로 해결했다.
 */

class CreateBigNumber {
    public static String solution(String number, int k) {

        Stack<Character> stk = new Stack<>();

        for (char c : number.toCharArray()) {
            while(!stk.empty() && k > 0) {
                Character last = stk.peek();
                if(last < c) {
                    stk.pop(); --k;
                } else {
                    break;
                }
            }
            stk.push(c);
        }

        while(k-- > 0) {
            stk.pop();
        }

        StringBuilder sb = new StringBuilder();
        while(!stk.empty()) {
            sb.append(stk.pop());
        }
        sb.reverse();

        return sb.toString();
    }

    public static void main(String[] args) {
        System.out.println(solution("01010", 2));
    }
}