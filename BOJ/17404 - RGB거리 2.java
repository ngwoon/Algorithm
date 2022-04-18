import java.io.*;
import java.util.StringTokenizer;

import static java.lang.Integer.parseInt;

/*
    집들을 색칠할 때, 인접한 집을 같은 색으로 칠하지 않으면서 모든 집을 색칠할 때 필요한 최소 비용을 구하는 문제.

    <나의 풀이>
    0번째 집과 마지막 집이 이어져있어서 조금 더 어려워진 문제이다.
    0번째 집부터 N-2번째 집까지는 자신의 앞 집의 색만 고려하면 되지만, N-1번째 집은 0번째 집의 색을 고려해야 한다.
    따라서 0번째 집에 어떤 색을 칠하는지에 따라 경우를 구분할 필요가 있다.
    
    dp는 3차원 배열을 사용했다. dp의 의미는 아래와 같다.
    dp[a][b][c] = 0번째 집에 a 색을 칠하고, b번째 집까지 색을 칠하고 b번째 집에 c 색을 칠할 때 필요한 최소 비용

    dp의 점화식은 n-1번째 집의 dp와 그 외 경우로 구분했다.
    1. n-1미만 집일 때
        for j = 0 -> 2 (RED to BLUE)
            dp[j][i][RED] = Math.min(dp[j][i-1][GREEN] + cost[i][RED], dp[j][i-1][BLUE] + cost[i][RED]);
            dp[j][i][GREEN] = Math.min(dp[j][i-1][RED] + cost[i][GREEN], dp[j][i-1][BLUE] + cost[i][GREEN]);
            dp[j][i][BLUE] = Math.min(dp[j][i-1][RED] + cost[i][BLUE], dp[j][i-1][GREEN] + cost[i][BLUE]);

    2. n-1번째 집일 때
        dp[RED][i][GREEN] = Math.min(dp[RED][i-1][BLUE] + cost[i][GREEN], dp[RED][i-1][RED] + cost[i][GREEN]);
        dp[RED][i][BLUE] = Math.min(dp[RED][i-1][RED] + cost[i][BLUE], dp[RED][i-1][GREEN] + cost[i][BLUE]);
        dp[GREEN][i][RED] = Math.min(dp[GREEN][i-1][BLUE] + cost[i][RED], dp[GREEN][i-1][GREEN] + cost[i][RED]);
        dp[GREEN][i][BLUE] = Math.min(dp[GREEN][i-1][RED] + cost[i][BLUE], dp[GREEN][i-1][GREEN] + cost[i][BLUE]);
        dp[BLUE][i][RED] = Math.min(dp[BLUE][i-1][GREEN] + cost[i][RED], dp[BLUE][i-1][BLUE] + cost[i][RED]);
        dp[BLUE][i][GREEN] = Math.min(dp[BLUE][i-1][RED] + cost[i][GREEN], dp[BLUE][i-1][BLUE] + cost[i][GREEN]);
 */

class RGBDistance2 {

    static int INF = 1000001;
    static int RED = 0, GREEN = 1, BLUE = 2;
    static int[][][] dp;
    static int[][] cost;
    static int n;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = parseInt(br.readLine());
        cost = new int[n][3];
        for(int i=0; i<n; ++i) {
            StringTokenizer stzr = new StringTokenizer(br.readLine());
            cost[i][RED] = parseInt(stzr.nextToken());
            cost[i][GREEN] = parseInt(stzr.nextToken());
            cost[i][BLUE] = parseInt(stzr.nextToken());
        }

        // dp[a][b][c] = 첫번째 집을 a로 칠했을 때, b번째 집까지 색을 칠하고, b번째 집을 c로 칠했을 때 최소 비용
        dp = new int[3][n][3];
        for(int i=0; i<3; ++i) {
            for(int j=0; j<n; ++j) {
                for(int k=0; k<3; ++k) {
                    dp[i][j][k] = INF;
                }
            }
        }
        dp[RED][0][RED] = cost[0][RED];
        dp[GREEN][0][GREEN] = cost[0][GREEN];
        dp[BLUE][0][BLUE] = cost[0][BLUE];

        for(int i=1; i<n; ++i) {
            if(i == n-1) {
                dp[RED][i][GREEN] = Math.min(dp[RED][i-1][BLUE] + cost[i][GREEN], dp[RED][i-1][RED] + cost[i][GREEN]);
                dp[RED][i][BLUE] = Math.min(dp[RED][i-1][RED] + cost[i][BLUE], dp[RED][i-1][GREEN] + cost[i][BLUE]);
                dp[GREEN][i][RED] = Math.min(dp[GREEN][i-1][BLUE] + cost[i][RED], dp[GREEN][i-1][GREEN] + cost[i][RED]);
                dp[GREEN][i][BLUE] = Math.min(dp[GREEN][i-1][RED] + cost[i][BLUE], dp[GREEN][i-1][GREEN] + cost[i][BLUE]);
                dp[BLUE][i][RED] = Math.min(dp[BLUE][i-1][GREEN] + cost[i][RED], dp[BLUE][i-1][BLUE] + cost[i][RED]);
                dp[BLUE][i][GREEN] = Math.min(dp[BLUE][i-1][RED] + cost[i][GREEN], dp[BLUE][i-1][BLUE] + cost[i][GREEN]);
            } else {
                for(int j=0; j<3; ++j) {
                    dp[j][i][RED] = Math.min(dp[j][i-1][GREEN] + cost[i][RED], dp[j][i-1][BLUE] + cost[i][RED]);
                    dp[j][i][GREEN] = Math.min(dp[j][i-1][RED] + cost[i][GREEN], dp[j][i-1][BLUE] + cost[i][GREEN]);
                    dp[j][i][BLUE] = Math.min(dp[j][i-1][RED] + cost[i][BLUE], dp[j][i-1][GREEN] + cost[i][BLUE]);
                }
            }
        }

        int ans = INF;
        for(int i=0; i<3; ++i) {
            for(int j=0; j<3; ++j) {
                if(i != j) {
                    ans = Math.min(ans, dp[i][n-1][j]);
                }
            }
        }

        bw.write(String.valueOf(ans));
        bw.flush();
    }
}