import java.util.HashMap;
import java.util.Map;
import java.util.Stack;

/*
    수가 주어졌을 때, 문제에서 제시된 규칙에 맞게 수를 변형시키는 문제.

    <나의 풀이>
    124 나라는 수를 3가지 사용하므로 3진법과 유사하다.
    1 % 3 = 1, 2 % 3 = 2, 3 % 3 = 0이므로, 1은 1, 2는 2, 0은 4에 대응된다.
    진법 변환 공식에 따라 주어진 수를 3으로 나누면서 나머지와 몫을 이어붙이면 답이 된다.
    단, 나눴을 때 나머지가 0이면 n-1을 해주어야 한다.
    ex) 5를 124나라의 수로 변환하면
        6 % 3 = 2 ... 0 (4로 변환, 2에서 1을 뺌)
        1 % 3 = 0 ... 1 (1로 변환)
        124 나라의 수는 14
 */

class NumberOf124Country {
    public String solution(int n) {

        Map<Integer, Integer> numMap = new HashMap<>();
        numMap.put(1, 1);
        numMap.put(2, 2);
        numMap.put(0, 4);

        StringBuilder sb = new StringBuilder();
        Stack<Integer> stk = new Stack<>();
        while(n > 0) {
            int rest = n % 3;
            stk.push(numMap.get(rest));
            n /= 3;

            if(rest == 0) {
                --n;
            }
        }

        while(!stk.isEmpty()) {
            sb.append(stk.pop());
        }

        return sb.toString();
    }
}