import java.util.ArrayList;
import java.util.PriorityQueue;

/*
    섬의 개수와 섬 사이 다리를 짓는 비용이 주어졌을 때, 모든 섬이 통행 가능하도록 다리를 짓는 최소 비용을 구하는 문제.

    <나의 풀이>
    MST 알고리즘 문제이다. 나는 프림 알고리즘을 사용해 문제를 해결했다.
    프림 알고리즘이란?
    주어진 노드들이 각각 하나씩의 간선만으로 연결되어있다면, 모든 노드 간 통신이 가능한 성질을 이용해서
    시작 노드를 잡고, 해당 노드부터 탐색하며 노드와 연결된 간선들을 pq에 넣으면서 최소 비용 간선만 선택해나가는 알고리즘
 */


class ConnectIsland {
    public int solution(int n, int[][] costs) {
        int answer = 0;

        ArrayList<ArrayList<Edge>> adj = new ArrayList<>();
        for(int i=0; i<n; ++i) {
            adj.add(new ArrayList<>());
        }

        for(int i=0; i<costs.length; ++i) {
            int s = costs[i][0];
            int e = costs[i][1];
            int c = costs[i][2];

            adj.get(s).add(new Edge(e, c));
            adj.get(e).add(new Edge(s, c));
        }

        PriorityQueue<Edge> pq = new PriorityQueue<>();
        pq.add(new Edge(0,0));

        boolean[] visited = new boolean[n];
        int cnt = 0;
        while(!pq.isEmpty()) {
            Edge cur = pq.poll();

            if(visited[cur.dest]) {
                continue;
            }

            int v = cur.dest;
            int cost = cur.cost;
            answer += cost;
            visited[v] = true;
            cnt += 1;

            if(cnt == n) {
                break;
            }

            ArrayList<Edge> edges = adj.get(v);
            pq.addAll(edges);
        }

        return answer;
    }

    static class Edge implements Comparable<Edge> {
        int dest;
        int cost;

        public Edge(int num, int cost) {
            this.dest = num;
            this.cost = cost;
        }

        @Override
        public int compareTo(Edge o) {
            return this.cost - o.cost;
        }
    }
}