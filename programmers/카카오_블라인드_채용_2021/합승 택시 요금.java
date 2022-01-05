package 카카오_블라인드_채용_2021;

/*
    출발노드와 a,b의 도착노드, 노드의 개수와 각 노드 간 비용이 주어질 때, 최소 택시 비용을 구하는 문제.

    <나의 풀이>
    이 문제의 핵심은 a,b가 어느 노드까지 합승하고, 그 노드부터 각자의 도착점까지 가는 비용을 구해야 한다는 점이다.
    즉, 택시를 타고 같이 도착할 노드 i, i노드서부터 a,b 노드까지의 비용을 구해야 하므로 모든 노드에서부터 모든 노드까지의 최소 비용을 구할 수 있는 플로이드-와샬 알고리즘을 활용할 수 있다.
    문제에서 제시한 노드의 최대 개수가 200이므로, O(n^3) 시간복잡도를 커버할 수 있다.
 */

class TaxiFares {

    int[][] dst;

    public int solution(int n, int s, int a, int b, int[][] fares) {

        int IMP = 10000000;
        dst = new int[n+1][n+1];
        for(int i=1; i<=n; ++i) {
            for(int j=1; j<=n; ++j) {
                dst[i][j] = i == j ? 0 : IMP;
            }
        }
        for (int[] fare : fares) {
            dst[fare[0]][fare[1]] = fare[2];
            dst[fare[1]][fare[0]] = fare[2];
        }

        floydWarshall(n);
        int max = IMP;
        for(int i=1; i<=n; ++i) {
            int share = dst[s][i];
            int acost = dst[i][a];
            int bcost = dst[i][b];
            if(share > -1 && acost > -1 && bcost > -1) {
                max = Math.min(share + acost + bcost, max);
            }
        }

        return max;
    }

    public void floydWarshall(int n) {

        for(int k=1; k<=n; ++k) {
            for(int i=1; i<=n; ++i) {
                for(int j=1; j<=n; ++j) {
                    int cost = dst[i][k] + dst[k][j];
                    if(cost < dst[i][j]) {
                        dst[i][j] = cost;
                    }
                }
            }
        }
    }
}