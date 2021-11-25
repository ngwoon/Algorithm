
/*
    도둑질을 할 집에 있는 돈 리스트가 주어졌을 때, 인접한 집을 털지 않으면서 훔칠 수 있는 최대 금액을 구하는 문제.

    <나의 풀이>
    이 문제의 핵심은 인접한 집을 털면 안된다는 것이다. 일반적인 힙색 풀이방식으로 풀면 마지막 집과 첫 번째 집이 동시에 털릴 수도 있으므로 이 점을 주의해야 한다.
    따라서 이 문제는 두 가지 경우를 구해야 한다. 첫 번째 집을 털고 마지막 집을 털지 않는 경우와, 첫 번째 집을 털지 않고 마지막 집을 터는 경우이다.

    <더 나은 풀이>
    풀이 방법은 동일하나, dp 2차원 배열을 이용해 더 깔끔하게 풀이한 코드가 있어서 기록해둔다.
    public int solution(int[] money) {
        int[][] pick = new int[2][money.length];

        pick[0][0] = money[0];
        pick[0][1] = money[0];
        pick[1][0] = 0;
        pick[1][1] = money[1];

        for(int i=2; i<money.length; i++) {
            pick[0][i] = Math.max(pick[0][i-2] + money[i], pick[0][i-1]);
            pick[1][i] = Math.max(pick[1][i-2] + money[i], pick[1][i-1]);
        }

        return Math.max(pick[0][pick[0].length-2], pick[1][pick[1].length-1]);
    }
 */

class Theif {
    public int solution(int[] money) {

        int answer = 0;

        int n = money.length;
        int[] dp = new int[n];

        dp[0] = money[0];
        dp[1] = money[0];
        for(int i=2; i<n; ++i) {
            dp[i] = Math.max(dp[i-2] + money[i], dp[i-1]);
            if(i == n-1) {
                dp[i] = dp[i-1];
            }
        }
        answer = dp[n-1];

        dp[0] = 0;
        dp[1] = money[1];
        for(int i=2; i<n; ++i) {
            dp[i] = Math.max(dp[i-2] + money[i], dp[i-1]);
            if(i == n-1) {
                dp[i] = dp[i-2] + money[i];
            }
        }
        answer = Math.max(answer, dp[n-1]);

        return answer;
    }
}