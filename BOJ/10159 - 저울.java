import java.io.*;

import static java.lang.Integer.parseInt;

/*
    물건들의 무게 대소관계 쌍이 일부 주어질 때, 임의의 물건과 무게 비교를 할 수 없는 물건의 개수를 구하는 문제.

    <나의 풀이>
    주어진 무게 대소쌍을 통해 방향 그래프로 만들 수 있다.
    이렇게 만들어진 방향 그래프에서 임의의 두 노드 간 경로가 있다는 뜻은, 두 물건의 대소관계를 정의할 수 있음을 뜻한다.
    즉, 임의의 물건과 무게 대소관계를 정의할 수 없는 물건은, 방향 그래프에서 해당 물건의 노드에서 도달할 수 없는 노드들이 된다.
    이 문제는 n의 크기가 최대 100으로 매우 작다. 즉, 노드 간 거리를 구하는 알고리즘 중 "플로이드-와샬"을 사용해도 무방하다.
 */

class Scale {

    static int INF = 2001;
    static int n, m;
    static int[][] adj;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = parseInt(br.readLine());
        m = parseInt(br.readLine());

        adj = new int[n+1][n+1];
        for(int i=1; i<=n; ++i) {
            for(int j=1; j<=n; ++j) {
                adj[i][j] = i == j ? 1 : INF;
            }
        }

        for(int i=0; i<m; ++i) {
            String pairLine = br.readLine();
            String[] pairStr = pairLine.split(" ");
            int a = parseInt(pairStr[0]);
            int b = parseInt(pairStr[1]);
            adj[a][b] = 1;
        }

        for(int i=1; i<=n; ++i) {
            for(int j=1; j<=n; ++j) {
                for(int k=1; k<=n; ++k) {
                    if(adj[j][i] == 1 && adj[i][k] == 1) {
                        adj[j][k] = 1;
                    }
                }
            }
        }

        for(int i=1; i<=n; ++i) {
            int count = 0;
            for(int j=1; j<=n; ++j) {
                if (i != j && adj[i][j] == INF && adj[j][i] == INF) {
                    count += 1;
                }
            }
            bw.write(count + "\n");
        }
        bw.flush();
    }
}