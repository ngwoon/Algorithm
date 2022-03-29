import java.io.*;
import java.util.ArrayList;
import java.util.List;

import static java.lang.Integer.parseInt;

/*
    수식이 주어질 때, 괄호를 추가해 얻을 수 있는 수식의 결과값 중 최대값을 구하는 문제.

    <나의 풀이>
    수식에 등장할 수 있는 최대 피연산자의 개수는 10개, 연산자의 개수는 9개이다.
    괄호를 어느 곳에 두느냐에 따라 계산 결과값이 달라지기 때문에, 모든 경우의 수를 다 해보긴 해야한다.
    단, 이전에 계산했던 결과를 다시 계산하는 일을 없애야 한다. 그렇기에 dp 알고리즘이 필요하다.

    나는 3차원 dp배열을 사용해 문제를 풀었다.
    dp[a][b][c]라고 할 때, dp[a][b]는 "a번째 피연산자부터 b번째 피연산자까지를 계산한 결과" 를 의미하고, 마지막 차원은 그것의 최댓값, 최솟값을 의미한다.
    계산 결과값의 최댓값을 구하는 문제에서 3차원이 왜 필요한지 의문이 들 수 있다. 이것은 아래와 같은 경우를 고려해야 하기 때문이다.

        주어진 수식이 1-9-1-9-1-9-1-9 일 때, dp[0][3]에는 어떤 값이 들어가야 하는가?
        0번째 피연산자부터 3번째 피연산자까지를 계산할 때, 괄호로 묶는 세 가지 경우의 수가 있다.
            * (1-9-1-9)
            * 1-(9-1-9)
            * 1-9-(1-9)
        직관적으로 풀어보면, dp[0][3]에 들어가야 할 수는 1-9-(1-9) 의 결과값인 0이다.
        하지만 dp를 구할 때 최댓값만 찾게 되면, 괄호 내부의 계산 결과값이 -1인 1-(9-1-9)의 계산 결과값을 따르게 될 것이다.

    이처럼 경우에 따라 최댓값, 최솟값을 구해야 할 때가 달라지므로 dp배열을 3차원으로 선언하고, 각 괄호 계산 결과값의 최댓값, 최솟값을 모두 구해야 한다.
 */

class AddParenthesis {

    static int MIN_INF = Integer.MIN_VALUE;
    static int MAX_INF = Integer.MAX_VALUE;
    static int MAX = 0;
    static int MIN = 1;
    static int[][][] dp;
    static int operandSize;
    static List<Integer> operands;
    static List<Character> operators;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = parseInt(br.readLine());
        String mathExpression = br.readLine();

        operandSize = (n+1)/2;
        operands = new ArrayList<>(operandSize);
        operators = new ArrayList<>(operandSize - 1);

        for(int i=0; i<n; ++i) {
            if(i % 2 == 0) {
                operands.add(mathExpression.charAt(i) - '0');
            } else {
                operators.add(mathExpression.charAt(i));
            }
        }

        dp = new int[operandSize][operandSize][2];
        for(int i=0; i<operandSize; ++i) {
            for(int j=0; j<operandSize; ++j) {
                dp[i][j][MAX] = MIN_INF;
                dp[i][j][MIN] = MAX_INF;
            }
        }
        for(int i=0; i<operandSize; ++i) {
            calcRange(0, i, MAX);
        }

        bw.write(String.valueOf(dp[0][operandSize-1][MAX]));
        bw.flush();
    }

    public static int calcRange(int aIdx, int bIdx, int type) {
        if((type == MIN && dp[aIdx][bIdx][type] != MAX_INF) ||
            (type == MAX && dp[aIdx][bIdx][type] != MIN_INF)
        ) {
            return dp[aIdx][bIdx][type];
        }

        if(bIdx == aIdx) {
            dp[aIdx][bIdx][MIN] = operands.get(aIdx);
            dp[aIdx][bIdx][MAX] = operands.get(aIdx);
            return dp[aIdx][bIdx][MIN];
        }

        int mIdx = aIdx;
        while(mIdx < bIdx) {
            if(operators.get(mIdx) == '-') {
                dp[aIdx][bIdx][MAX] = Math.max(dp[aIdx][bIdx][MAX], calc(calcRange(aIdx, mIdx, MAX), calcRange(mIdx+1, bIdx, MIN), operators.get(mIdx)));
                dp[aIdx][bIdx][MIN] = Math.min(dp[aIdx][bIdx][MIN], calc(calcRange(aIdx, mIdx, MIN), calcRange(mIdx+1, bIdx, MAX), operators.get(mIdx)));
            } else if(operators.get(mIdx) == '*') {
                dp[aIdx][bIdx][MAX] = Math.max(dp[aIdx][bIdx][MAX], calc(calcRange(aIdx, mIdx, MAX), calcRange(mIdx+1, bIdx, MAX), operators.get(mIdx)));
                dp[aIdx][bIdx][MAX] = Math.max(dp[aIdx][bIdx][MAX], calc(calcRange(aIdx, mIdx, MIN), calcRange(mIdx+1, bIdx, MIN), operators.get(mIdx)));

                dp[aIdx][bIdx][MIN] = Math.min(dp[aIdx][bIdx][MIN], calc(calcRange(aIdx, mIdx, MIN), calcRange(mIdx+1, bIdx, MIN), operators.get(mIdx)));
                dp[aIdx][bIdx][MIN] = Math.min(dp[aIdx][bIdx][MIN], calc(calcRange(aIdx, mIdx, MIN), calcRange(mIdx+1, bIdx, MAX), operators.get(mIdx)));
                dp[aIdx][bIdx][MIN] = Math.min(dp[aIdx][bIdx][MIN], calc(calcRange(aIdx, mIdx, MAX), calcRange(mIdx+1, bIdx, MIN), operators.get(mIdx)));
            } else {
                dp[aIdx][bIdx][MAX] = Math.max(dp[aIdx][bIdx][MAX], calc(calcRange(aIdx, mIdx, MAX), calcRange(mIdx+1, bIdx, MAX), operators.get(mIdx)));
                dp[aIdx][bIdx][MIN] = Math.min(dp[aIdx][bIdx][MIN], calc(calcRange(aIdx, mIdx, MIN), calcRange(mIdx+1, bIdx, MIN), operators.get(mIdx)));
            }
            ++mIdx;
        }

        return dp[aIdx][bIdx][type];
    }

    public static int calc(int a, int b, char op) {
        int res = 0;
        switch(op) {
            case '+': res = a + b; break;
            case '-': res = a - b; break;
            case '*': res = a * b; break;
        }
        return res;
    }
}