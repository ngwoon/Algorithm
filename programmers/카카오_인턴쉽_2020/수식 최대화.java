package 카카오_인턴쉽_2020;

import java.util.*;

/*
    수식이 주어질 때, 연산자의 우선순위를 조정하여 구할 수 있는 값들 중 절댓값이 가장 큰 값을 구하는 문제.

    <나의 풀이>
    수식을 계산하기 전, 연산자의 우선순위를 먼저 정해야 한다.
    연산자의 우선순위는 완전 탐색으로 가능한 모든 우선순위를 탐색한다. 수식에 등장하는 각 연산자의 종류에 대해 우선순위를 정했으면, 정해진 우선순위대로
    수식의 계산을 시작한다. 수식의 계산은 스택을 활용하여 수행한다.
        * 먼저 수식의 피연산자를 피연산자를 저장하는 스택(이하 nums)에, 연산자를 연산자를 저장하는 스택(이하 ops)에 저장한다.
        * "-" 연산같은 경우 피연산자의 순서에 따라 값이 달라지므로, 수식의 역순으로 탐색하면서 저장해야한다.
        * 수식 계산은 정해진 연산자 우선순위대로 수행되어야 하므로, for문으로 현재 계산할 우선순위를 카운팅하면서 아래 로직이 진행된다.
            1. nums에서 피연산자 2개를 꺼내고, ops에서 연산자 하나를 꺼낸다.
            2-1. ops에서 꺼낸 연산자가 현재 우선순위에 해당한다면, 계산하고 nums에 다시 집어넣는다.
            2-2. ops에서 꺼낸 연산자가 현재 우선순위에 해당하지 않는다면, 계산하지 않고 tmpNums과 tmpOps라는 임시 스택에 넣는다.
                 단, 두 번째로 꺼낸 피연산자는 nums에 넣는다.
            3. 위 과정을 ops 스택이 빌 때까지 수행한다.
            4. 반복문이 끝났다면, nums스택에 피연산자 하나가 들어있는 상태이다. 이를 tmpNums에 옮겨준 뒤, tmpNums와 tmpOps에 임시저장된
               피연산자와 연산자들을 다시 nums와 ops로 돌려놓는다.
            5. 우선순위 카운팅하는 for문이 끝나면 자연스럽게 수식의 결과가 완성된다.
 */

class MaximizeExpression {

    HashMap<String, Integer> hm;
    List<String> exp;
    String operators;
    long ans = 0;

    public long solution(String expression) {

        StringBuilder sb = new StringBuilder();
        if(expression.contains("*")) {
            sb.append("*");
        }
        if(expression.contains("+")) {
            sb.append("+");
        }
        if(expression.contains("-")) {
            sb.append("-");
        }
        operators = sb.toString();

        exp = new ArrayList<>();
        int eidx = 0;
        int sidx = 0;
        while(eidx < expression.length()) {
            if(operators.contains(expression.substring(eidx, eidx + 1))) {
                exp.add(expression.substring(sidx, eidx));
                exp.add(expression.substring(eidx, eidx + 1));
                sidx = eidx + 1;
            }
            ++eidx;
        }
        exp.add(expression.substring(sidx, eidx));

        hm = new HashMap<>();
        bruteForce(0);

        return ans;
    }

    public void bruteForce(int priority) {
        if(priority == operators.length()) {
            long result = calcExpression();
            ans = Math.max(ans, result);
            return;
        }

        for(int i=0; i<operators.length(); ++i) {
            String op = operators.substring(i, i+1);
            if(!hm.containsKey(op)) {
                hm.put(op, priority);
                bruteForce(priority + 1);
                hm.remove(op);
            }
        }
    }

    public long calcExpression() {

        Stack<Long> nums = new Stack<>();
        Stack<String> ops = new Stack<>();
        for(int i=exp.size()-1; i>=0; --i) {
            String s = exp.get(i);
            if (s.equals("*") || s.equals("+") || s.equals("-")) {
                ops.add(s);
            } else {
                nums.add(Long.parseLong(s));
            }
        }

        Stack<Long> tmpNums = new Stack<>();
        Stack<String> tmpOps = new Stack<>();
        for(int p=0; p<hm.keySet().size(); ++p) {
            while(!ops.isEmpty()) {
                Long a = nums.pop();
                Long b = nums.pop();
                String op = ops.pop();

                if(hm.get(op) == p) {
                    long res;
                    if(op.equals("*")) {
                        res = a * b;
                    } else if(op.equals("+")) {
                        res = a + b;
                    } else {
                        res = a - b;
                    }
                    nums.add(res);
                } else {
                    tmpNums.add(a);
                    nums.add(b);
                    tmpOps.add(op);
                }
            }
            tmpNums.add(nums.pop());

            while(!tmpNums.isEmpty()) {
                nums.add(tmpNums.pop());
            }
            while(!tmpOps.isEmpty()) {
                ops.add(tmpOps.pop());
            }
        }

        return Math.abs(nums.pop());
    }
}