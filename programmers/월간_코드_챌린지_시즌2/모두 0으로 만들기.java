package 월간_코드_챌린지_시즌2;

import java.util.ArrayList;

/*
    각 노드에 가중치가 있는 트리가 주어질 때, 가중치를 옮겨서 모든 노드의 가중치를 0으로 만드는 문제.

    <나의 풀이>
    이 문제의 핵심은 그래프가 항상 "트리" 형식으로 주어진다는 점이다.
    모든 노드의 가중치를 0으로 만들 수 있느냐 없느냐는, 주어진 트리의 모든 노드의 가중치의 합이 0인지 아닌지를 통해 알 수 있다.
    모든 노드의 가중치의 합이 0이라면, 하나의 노드를 루트 노드로 잡고, 나머지 노드의 가중치를 루트로 보내는 방법을 생각해볼 수 있다.
    그렇다면 어떤 노드를 루트 노드로 골라야, 모든 노드의 가중치를 0으로 만드는 최소 횟수를 구할 수 있을까?
    결론은 "어느 노드든 상관없다" 이다. 트리 특성상 서로 다른 두 노드 간 경로는 오직 하나이므로, 어느 노드를 루트로 잡든 결과는 동일하다.

    가중치 이동 횟수를 구하는 방법은 간단하다. dfs를 통해 리프 노드를 찾고, 리프 노드에서 부모 노드로 자신의 가중치의 절댓값을 더해준 뒤, 부모 노드의 가중치에
    자신의 가중치를 더해주면 된다. 이 때, 문제에서 주어진 a배열은 int형이지만 가중치를 더하는 과정에서 int 범위를 넘어설 수 있으므로, long형 배열을 따로 선언해서
    이 배열에 연산을 수행해야 한다.
 */

class MakeAllZero {

    ArrayList<Integer>[] adj;
    boolean[] visited;
    long[] weights;
    long ans = 0;

    public long solution(int[] a, int[][] edges) {

        int n = a.length;

        long sum = 0;
        weights = new long[n];
        adj = new ArrayList[n];
        for (int i=0; i<n; ++i) {
            sum += a[i];
            weights[i] = a[i];
            adj[i] = new ArrayList<>();
        }
        if(sum != 0) {
            return -1;
        }

        for (int i=0; i<edges.length; ++i) {
            adj[edges[i][0]].add(edges[i][1]);
            adj[edges[i][1]].add(edges[i][0]);
        }

        visited = new boolean[n];
        dfs(0);

        return ans;
    }

    public long dfs(int node) {
        visited[node] = true;
        for (int i=0; i<adj[node].size(); ++i) {
            int nNode = adj[node].get(i);
            if (!visited[nNode]) {
                weights[node] += dfs(nNode);
            }
        }
        ans += Math.abs(weights[node]);
        return weights[node];
    }
}