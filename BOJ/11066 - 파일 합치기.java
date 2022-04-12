import java.io.*;
import java.util.*;

import static java.lang.Integer.parseInt;

/*
    파일의 크기들이 주어질 때, 이 파일을 합칠 때 들여야 되는 최소 비용을 구하는 문제.

    <나의 풀이>
    이 문제는 최적화 문제이다. 따라서 dp를 고려해볼 수 있다.
    2차원 배열 dp[][]를 선언한다. dp[a][b]는 아래와 같은 정의를 갖는다.
    dp[a][b] = a번째 파일부터 b번째 파일까지 합칠 때, 들여야 하는 여러 가지 경우의 비용 중 가장 작은 비용.
    점화식은 아래와 같다.
        * a == b이면, dp[a][b] = 0 이다.
        * a != b이면, a <= k < b인 모든 k에 대해 dp[a][b] = Math.min(dp[a][k] + dp[k+1][b] + 누적합[a][b]) 이다.

    파일을 합칠 때 인접한 파일끼리만 합칠 수 있음에 유의하자.
 */

class FileMerge {

    static int INF = Integer.MAX_VALUE;
    static int k;
    static int[][] dp;
    static int[][] accSum;
    static int[] files;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int t = parseInt(br.readLine());

        while(t-- > 0) {
            k = parseInt(br.readLine());

            accSum = new int[k][k];
            files = new int[k];
            dp = new int[k][k];
            StringTokenizer stzr = new StringTokenizer(br.readLine());
            for(int i=0; i<k; ++i) {
                files[i] = parseInt(stzr.nextToken());
            }

            for(int i=0; i<k; ++i) {
                for(int j=i; j<k; ++j) {
                    accSum[i][j] = i == j ? files[i] : accSum[i][j - 1] + files[j];
                }
            }

            for(int i=0; i<k; ++i) {
                for(int j=0; j<k; ++j) {
                    dp[i][j] = i == j ? 0 : INF;
                }
            }

            bw.write(solve(0, k-1) + "\n");
        }
        bw.flush();
    }

    public static int solve(int s, int e) {
        if(dp[s][e] == INF) {
            for(int i=s; i<e; ++i) {
                int a = solve(s, i);
                int b = solve(i+1, e);
                int totalCost = a + b + accSum[s][e];
                dp[s][e] = Math.min(dp[s][e], totalCost);
            }
        }
        return dp[s][e];
    }
}