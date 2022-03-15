package 위클리_챌린지;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

/*
    전력망 트리가 주어질 때, 간선 하나를 제거하여 두 개의 트리로 분리할 때 가장 적은 트리의 노드 개수 차이를 구하는 문제.

    <나의 풀이>
    전력망 트리의 노드 개수의 최대 크기가 100개이므로, 간선의 개수는 최대 99개이다.
    따라서 모든 간선을 한 번씩 잘라서 생기는 두 개의 트리의 노드 개수를 각각 구해, 그 차이를 구하는 완전 탐색 기법을 사용해도 시간초과가 나지 않는다.
    시간복잡도는 O(n-1) * O(n) => O(n^2) 이다.
 */

class DivideNetwork {

    static List<List<Integer>> adj;

    public static int solution(int n, int[][] wires) {
        adj = new ArrayList<>(n+1);
        for(int i=0; i<=n; ++i) {
            adj.add(new LinkedList<>());
        }

        for (int[] wire : wires) {
            adj.get(wire[0]).add(wire[1]);
            adj.get(wire[1]).add(wire[0]);
        }

        int ans = 100;
        for(int[] wire : wires) {
            adj.get(wire[0]).remove(adj.get(wire[0]).indexOf(wire[1]));
            adj.get(wire[1]).remove(adj.get(wire[1]).indexOf(wire[0]));

            // wire[0]랑 wire[1]이 나뉘어져 있음을 알 수 있기 때문에, for문을 사용해서 모든 노드를 탐색하기보다
            // wire[0]와 wire[1]에 대해 bfs를 수행하는게 더 효율적이다.
            boolean[] visited = new boolean[n+1];
            int[] group = new int[2];
            group[0] = bfs(wire[0], visited);
            group[1] = bfs(wire[1], visited);

            ans = Math.min(ans, Math.abs(group[0] - group[1]));

            adj.get(wire[0]).add(wire[1]);
            adj.get(wire[1]).add(wire[0]);
        }

        return ans;
    }

    public static int bfs(int start, boolean[] visited) {
        Queue<Integer> que = new LinkedList<>();
        que.add(start);
        visited[start] = true;
        int cnt = 0;
        while(!que.isEmpty()) {
            int cur = que.poll();
            cnt += 1;

            for(int i=0; i<adj.get(cur).size(); ++i) {
                int next = adj.get(cur).get(i);
                if(!visited[next]) {
                    visited[next] = true;

                    que.add(next);
                }
            }
        }

        return cnt;
    }
}