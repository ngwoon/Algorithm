import java.io.*;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

import static java.lang.Integer.parseInt;

/*
    앱의 개수 n과 확보해야 할 메모리 크기 m, 각 앱을 비활성화 했을 때 소모되는 비용이 주어질 때, 메모리 m을 확보하기 위해 들여야 하는 최소 비용을 구하는 문제.

    <나의 풀이>
    풀지 못해서 구글링을 통해 아이디어를 얻었다.

    이 문제는 dp 중 냅색 문제의 응용이다.
    냅색 문제란, 도둑이 무게 w를 수용할 수 있는 가방을 메고 왔을 때, 진열된 보석 n개를 훔쳐갈 수 있을 만큼 훔칠 때 벌 수 있는 금액 중 가장 높은 금액을 구하는 문제이다.
    냅색 문제의 dp 의미는 아래와 같다.
        dp[i][w] = i개의 보석이 있고 배낭의 무게 한도가 w일 때 도둑이 얻을 수 있는 최적의 이익
    냅색 문제의 점화식은 아래와 같다.
        * 만약 i번째 보석의 무게가 w보다 무거우면, 가방에 넣을 수 없으므로 dp[i][w] = dp[i-1][w] 이다.
        * 만약 i번째 보석의 무게각 w보다 가벼우면, dp[i][w] = max(dp[i-1][w-weight[i]] + cost[i], dp[i-1][w]) 이다.

    이 냅색 알고리즘을 현재 문제에 적용해보자.
    보석 = 앱, 비활성화 비용 = 가방 무게, 메모리 = 보석 가치 으로 해석해볼 수 있다.
    dp 의미는 아래와 같이 해석 가능하다.
        dp[i][c] = i개의 앱이 있고 비활성화 비용의 한도를 c로 정했을 때, 확보할 수 있는 최대 메모리의 크기
    점화식은 아래와 같이 쓸 수 있을 것이다.
        * 만약 i번째 앱의 비활성화 비용이 c보다 무거우면, 조건을 만족할 수 없으므로 dp[i][c] = dp[i-1][c] 이다.
        * 만약 i번째 앱의 비활성화 비용이 c보다 가벼우면, dp[i][c] = max(dp[i-1][c-cost[i]] + memory[i], dp[i-1][c]) 이다.
 */

class App {

    static int n, m;
    static int[][] dp;
    static int[] cost, memory;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer stzr = new StringTokenizer(br.readLine());
        n = parseInt(stzr.nextToken());
        m = parseInt(stzr.nextToken());

        memory = new int[n+1];
        stzr = new StringTokenizer(br.readLine());
        for(int i=1; i<=n; ++i) {
            memory[i] = parseInt(stzr.nextToken());
        }

        int costSum = 0;
        cost = new int[n+1];
        stzr = new StringTokenizer(br.readLine());
        for(int i=1; i<=n; ++i) {
            cost[i] = parseInt(stzr.nextToken());
            costSum += cost[i];
        }

        dp = new int[n+1][costSum+1]; // 앱의 개수는 최대 100개, 비활성화 비용은 최대 100 * 100
        for(int i=1; i<=n; ++i) {
            for(int j=0; j<=costSum; ++j) {
                if(cost[i] <= j) {
                    dp[i][j] = Math.max(dp[i][j], dp[i-1][j-cost[i]] + memory[i]);
                }
                dp[i][j] = Math.max(dp[i][j], dp[i-1][j]);
            }
        }

        for(int i=0; i<=costSum; ++i) {
            if(dp[n][i] >= m) {
                bw.write(String.valueOf(i));
                bw.flush();
                return;
            }
        }
    }
}