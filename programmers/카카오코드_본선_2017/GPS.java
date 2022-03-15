package 카카오코드_본선_2017;

/*
    시간별로 택시가 이동한 로그가 주어질 때, 해당 로그대로 택시가 이동할 수 없다면
    그 잘못된 로그를 올바론 로그로 고칠 수 있는 최소의 수정 횟수를 구하는 문제.

    <나의 풀이>
    풀지 못해서 구글링을 통해 아이디어를 얻었다.

    이 문제는 dp 알고리즘으로 푸는 문제이다. dfs로 풀었었지만, 시간초과를 피할 순 없었다.
    문제에서 제시한 로그 배열 (이하 문제 로그 배열) 을 토대로
    dp[i][j]가 의미하는 바는 다음과 같다.
        " 올바른 로그 배열을 만들 때, i번째 인덱스에 노드 j를 위치시키는 경우 문제 로그 배열과 다른 로그의 개수 "
    dp[i][j]의 점화식은 다음과 같다.
        dp[i][j] = Math.min(dp[i-1][j], dp[i-1][z], dp[i-1][y], ... , dp[i-1][x]) + (gps_log[i] != j ? 1 : 0)
        (z, y, ... , x 는 j와 간선이 연결된 인접 노드)

    dp배열 구성에 대한 자세한 설명은 아래 블로그를 참고하면 좋다.
    https://eno1993.tistory.com/80
 */

class GPS {

    int INF = 99999999;
    public int solution(int n, int m, int[][] edge_list, int k, int[] gps_log) {
        int[][] road = new int[n + 1][n + 1]; //i와 j가 연결되어 있다면 1 아니면 0
        for (int i = 0; i < edge_list.length; i++) {
            int s = edge_list[i][0], e = edge_list[i][1];
            road[s][e] = 1;
            road[e][s] = 1;
        }

        int[][] dp = new int[k][n + 1]; //최솟값을 구해야 하므로 모든 값 INF 초기화
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < n + 1; j++) {
                dp[i][j] = INF;
            }
        }

        // 맨 첫번째 값은 정해진 값이기 때문에 0번째 인덱스에는 gps_log[0]의 값이 들어가야 한다.
        dp[0][gps_log[0]] = 0;

        // 인덱스 1에서 부터 인덱스 k-1까지 순차적으로 확인
        for (int i = 1; i < k; i++) {
            // 1노드부터 n노드 까지 하나하나씩 확인
            for (int j = 1; j < n + 1; j++) {
                // 이동을 하지 않을 경우 먼저 확인
                dp[i][j] = Math.min(dp[i][j], dp[i - 1][j]);
                // 이동을 할 경우
                for (int node = 1; node < n + 1; node++) {
                    if (road[j][node] == 1) {
                        // j노드와 연결된 노드를 확인하고 그 노드들로부터 j로 가는 모든 경우 확인
                        dp[i][j] = Math.min(dp[i][j], dp[i - 1][node]);
                    }
                }
                //j노드가 gps_log[i]와 다르다면
                // gps_log를 수정해야 하기 때문에 값을 더해줌
                if (j != gps_log[i]) {
                    dp[i][j]++;
                }
            }
        }

        if (dp[k - 1][gps_log[k - 1]] < INF) {
            return dp[k - 1][gps_log[k - 1]];
        } else {
            return -1;
        }
    }
}