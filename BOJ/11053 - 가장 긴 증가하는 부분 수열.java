import java.io.*;

/*
    수열이 주어졌을 때, 가장 긴 증가하는 부분 수열의 크기를 구하는 문제

    <나의 풀이>
    처음에는 dp[k]를 첫 번째 항부터 k항까지의 가장 긴 증가하는 부분 수열의 크기로 생각했는데,
    가장 긴 증가하는 부분 수열은 시작점이 계속 달라질 수 있다는 문제점이 있었다.
    따라서 반대로 dp[k]를 k번째 항부터 마지막 항까지의 가장 긴 증가하는 부분 수열의 크기로 여기고, 아래와 같은 점화식을 세웠다.
    i > k이고, seq[i] > seq[k] 일 때, dp[k] = max(dp[k], dp[i] + 1)
 */

class 가장_긴_증가하는_부분_수열 {

    static int[] seq;
    static int[] dp;
    static int n;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());
        String line = br.readLine();
        String[] splited = line.split(" ");
        seq = new int[n];
        for(int i=0; i<n; ++i) {
            seq[i] = Integer.parseInt(splited[i]);
        }

        dp = new int[n];

        int ans = 0;
        for(int i=n-1; i>=0; --i) {
            ans = Math.max(ans, solve(i));
        }

        bw.write(String.valueOf(ans));
        bw.flush();
    }

    public static int solve(int idx) {

        if(dp[idx] == 0) {
            for (int i = idx + 1; i < n; ++i) {
                if (seq[idx] < seq[i]) {
                    dp[idx] = Math.max(dp[idx], solve(i) + 1);
                }
            }
            if(dp[idx] == 0) {
                dp[idx] = 1;
            }
        }

        return dp[idx];
    }
}