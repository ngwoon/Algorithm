package level3;

/*
    원형으로 서로 이어진 스티커가 있고, 어느 스티커를 떼면 인접한 스티커를 뗄 수 없을 때, 뗀 스티커에 적혀있는 값들의 합의 최대값을 구하는 문제.

    <나의 풀이>
    일단, 이렇게 여러 가지 경우의 수가 있고 그 중에서 최대 혹은 최소를 구하는 문제는 dp유형의 문제이다.
    그 중에서도 처음과 끝이 이어져 있고, 첫 요소를 선택하면 마지막 요소를 고를 수 없는 유형의 경우,
    첫 번째 요소를 골랐을 경우와 그렇지 않을 경우를 나누어서 계산하면 답이 나온다. (프로그래머스 - 도둑질 문제가 딱 이 유형과 동일한 문제이다.)
 */

class 문제1 {
    public int solution(int sticker[]) {

        int n = sticker.length;

        if(n == 1) {
            return sticker[0];
        } else if(n == 2) {
            return Math.max(sticker[0], sticker[1]);
        }

        int[] dp = new int[n];

        int ans = 0;

        // 첫 번째 스티커를 떼는 경우
        dp[0] = sticker[0];
        dp[1] = sticker[0];
        for (int i=2; i<n; ++i) {
            if(i == n-1) {
                dp[i] = dp[i-1];
            } else {
                dp[i] = Math.max(dp[i-1], dp[i-2] + sticker[i]);
            }
        }

        ans = Math.max(ans, dp[n-1]);

        dp[0] = 0;
        dp[1] = sticker[1];
        for(int i=2; i<n; ++i) {
            dp[i] = Math.max(dp[i-1], dp[i-2] + sticker[i]);
        }

        ans = Math.max(ans, dp[n-1]);

        return ans;
    }
}