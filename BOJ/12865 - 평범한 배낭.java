import java.io.*;
import java.util.StringTokenizer;

import static java.lang.Integer.parseInt;

/*
    여행에 사용할 가방의 무게, 각 물건의 무게와 가치가 주어질 때, 즐거운 여행을 하기 위해 배낭에 넣을 수 있는 물건들의 가치의 최댓값을 구하는 문제.

    <나의 풀이>
    전형적인 냅색 문제이다.
    냅색 문제 설명은 백준 > 7579 - 앱.java 파일을 참고
 */

class NormalBag {

    static int n, k;
    static int[] value;
    static int[] weight;
    static int[][] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer stzr = new StringTokenizer(br.readLine());
        n = parseInt(stzr.nextToken());
        k = parseInt(stzr.nextToken());

        value = new int[n+1];
        weight = new int[n+1];
        for(int i=1; i<=n; ++i) {
            stzr = new StringTokenizer(br.readLine());
            weight[i] = parseInt(stzr.nextToken());
            value[i] = parseInt(stzr.nextToken());
        }

        dp = new int[n+1][k+1];
        for(int i=1; i<=n; ++i) {
            for(int j=0; j<=k; ++j) {
                if(weight[i] <= j) {
                    dp[i][j] = Math.max(dp[i-1][j-weight[i]] + value[i], dp[i-1][j]);
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        bw.write(String.valueOf(dp[n][k]));
        bw.flush();
    }
}