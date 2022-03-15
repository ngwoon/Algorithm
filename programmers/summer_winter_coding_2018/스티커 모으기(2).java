package summer_winter_coding_2018;

/*
    첫 번째 원소와 마지막 원소가 이어진 원형 형태의 배열이 주어졌을 때, 문제 조건에 따라 스티커를 떼어내 만들 수 있는 최대 합을 구하는 문제.

    <나의 풀이>
    첫 번째 원소와 마지막 원소가 이어져 있으므로, 첫 번째 스티커를 뗀 경우와 떼지 않은 경우를 나눠 생각해야 한다.
    따라서 dp 2차원 배열을 만들고, 첫 번째 행은 첫 번째 스티커를 뗀 경우, 두 번째 행은 떼지 않은 경우로 구분해서 dp를 계산했다.
 */

class StickerCollection {
    public int solution(int sticker[]) {
        int n = sticker.length;

        if(n == 1) {
            return sticker[0];
        }

        int[][] dp = new int[2][n];
        dp[0][0] = 0;
        dp[0][1] = sticker[1];
        dp[1][0] = sticker[0];
        dp[1][1] = dp[1][0];

        for(int i=2; i<n-1; ++i) {
            dp[0][i] = Math.max(dp[0][i-2] + sticker[i], dp[0][i-1]);
            dp[1][i] = Math.max(dp[1][i-2] + sticker[i], dp[1][i-1]);
        }

        if(n > 2) {
            dp[0][n-1] = Math.max(dp[0][n-3] + sticker[n-1], dp[0][n-2]);
            dp[1][n-1] = dp[1][n-2];
        }

        return Math.max(dp[0][n-1], dp[1][n-1]);
    }
}