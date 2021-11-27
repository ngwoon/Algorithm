
/*
    선수들 간 우열이 주어지고, 선수의 수가 주어졌을 때, 순위를 확실히 말할 수 있는 선수의 수를 구하는 문제

    <나의 풀이>
    풀지 못해서 구글링을 통해 아이디어를 얻었다.
    이 문제의 핵심은 a선수가 b선수를 이기고, b선수가 c선수를 이길 때 a선수가 c선수를 이긴다는 것을 어떻게 코드화하느냐이다.
    이는 플로이드-와샬 알고리즘을 활용해 구현할 수 있다.
    플로이드-와샬 알고리즘은 3중 for문을 돌면서 j-i와 i-k의 관계가 있다면, j-k 사이의 관계가 있음을 기록하는 알고리즘이다.
 */

class Grade {

    public int solution(int n, int[][] results) {

        boolean [][] adj = new boolean[n+1][n+1];

        for (int[] result : results) {
            adj[result[0]][result[1]] = true;
        }

        for(int i=1; i<=n; ++i) {
            for(int j=1; j<=n; ++j) {
                for(int k=1; k<=n; ++k) {
                    if(adj[j][i] && adj[i][k]) {
                        adj[j][k] = true;
                    }
                }
            }
        }

        int ans = 0;
        for(int i=1; i<=n; ++i) {
            int connected = 0;
            for(int j=1; j<=n; ++j) {
                if(adj[i][j] || adj[j][i]) {
                    ++connected;
                }
            }
            if(connected == n-1) {
                ++ans;
            }
        }

        return ans;
    }
}