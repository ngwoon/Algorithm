import java.io.*;
import java.util.ArrayList;
import java.util.List;

import static java.lang.Integer.parseInt;

/*
    체크포인트 좌표들과 스킵할 수 있는 체크포인트의 개수 k가 주어질 때, 문제 조건에 맞게 마라톤을 할 때 최소 이동 거리를 구하는 문제.
    <나의 풀이>
    풀지 못해서 구글링을 통해 아이디어를 얻었다.
    이 문제는 체크포인트가 skewed tree 형태이므로, 경로는 항상 1 -> 2 -> ... -> N 순서이다.
    따라서 dp를 통해 최적화할 수 있다.

    dp[a][b]가 의미하는 바는 아래와 같다.
     -> 1번째 노드에서 a번째 노드까지 b번 스킵하여 도달할 수 있는 경우의 수 중에 가장 짧은 경로의 길이.
    예를 들어 dp[4][2]은 1번째 노드에서 4번째 노드까지 2번 스킵하여 도달할 수 있는 경우의 수 중 가장 짧은 경로의 길이를 저장한다.
    이 dp의 점화식은 다음과 같다.
    dp[a][b] = min(dp[a-1][b] + dst[a-1][a], dp[a-2][b-1] + dst[a-2][a], ... , dp[a-i][b-i+1] + dst[a-i][a]) (b >= i-1)
 */

class Marathon2 {

    static int INF = Integer.MAX_VALUE;
    static List<Node> nodes;
    static int[][] dst;
    static int[][] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String varsLine = br.readLine();
        String[] varsStr = varsLine.split(" ");
        int n = parseInt(varsStr[0]);
        int k = parseInt(varsStr[1]);

        nodes = new ArrayList<>(n+1);
        nodes.add(new Node(0,0));
        for(int i=0; i<n; ++i) {
            String posLine = br.readLine();
            String[] posStr = posLine.split(" ");
            nodes.add(new Node(parseInt(posStr[1]), parseInt(posStr[0])));
        }

        dst = new int[n+1][n+1];
        for(int i=1; i<=n; ++i) {
            for(int j=1; j<=n; ++j) {
                dst[i][j] = getDst(nodes.get(i), nodes.get(j));
                dst[j][i] = dst[i][j];
            }
        }

        dp = new int[n+1][k+1];
        for(int i=0; i<n; ++i) {
            for(int j=0; j<=k; ++j) {
                dp[i][j] = 0;
            }
        }

        bw.write(String.valueOf(solve(n, k)));
        bw.flush();
    }

    public static int solve(int n, int k) {
        if(dp[n][k] != 0) {
            return dp[n][k];
        }
        if(n == 1) {
            return 0;
        }

        dp[n][k] = INF;
        for(int i=0; i<=k; ++i) {
            if(n-i-1 > 0) {
                dp[n][k] = Math.min(solve(n-i-1, k-i) + dst[n-i-1][n], dp[n][k]);
            }
        }
        return dp[n][k];
    }

    public static int getDst(Node a, Node b) {
        return Math.abs(a.y - b.y) + Math.abs(a.x - b.x);
    }

    static class Node {
        int y, x;

        public Node(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
}