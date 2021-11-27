import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

/*
    노드 개수와 연결 상태가 주어졌을 때, 1번 노드에서 가장 멀리 떨어진 노드의 개수를 구하는 문제.

    <나의 풀이>
    기본적인 bfs 문제이다.
    bfs를 사용하면 queue를 활용해서 1번 노드와 같은 거리에 있는 모든 노드를 탐색할 수 있으므로,
    마지막 사이클에 탐색한 노드들의 개수가 정답이 된다.
 */

class MostFarNode {

    List<List<Integer>> adj;

    public int solution(int n, int[][] edge) {

        adj = new ArrayList<>(n + 1);
        for (int i=0; i<=n; ++i) {
            adj.add(new LinkedList<>());
        }

        for (int[] e : edge) {
            adj.get(e[0]).add(e[1]);
            adj.get(e[1]).add(e[0]);
        }

        return bfs(1);
    }

    public int bfs(int start) {

        Queue<Integer> que = new LinkedList<>();
        boolean[] visited = new boolean[adj.size()];

        que.add(start);
        visited[start] = true;

        int ans;
        while(true) {
            Queue<Integer> tmp = new LinkedList<>();
            ans = 0;
            while(!que.isEmpty()) {
                int cur = que.poll();

                ++ans;

                List<Integer> relatedNodes = adj.get(cur);
                for(int i=0; i<relatedNodes.size(); ++i) {
                    int next = relatedNodes.get(i);
                    if(!visited[next]) {
                        visited[next] = true;
                        tmp.add(next);
                    }
                }
            }
            if(tmp.isEmpty()) {
                return ans;
            } else {
                que = tmp;
            }
        }
    }
}