package 카카오_채용연계형_인턴쉽_2021;

import java.util.*;

/*
    노드의 연결관계, 가중치, 트랩 노드가 주어졌을 때, 시작 노드에서 도착 노드까지의 경로 중 가장 작은 가중치를 구하는 문제.

    <나의 풀이>
    풀지 못해서 구글링을 통해 아이디어를 얻었다.
    이 문제의 핵심은 트랩 노드로 인한 간선의 변화이다.
    보통의 그래프에서 시작 노드에서 도착 노드로의 최소 가중치 경로를 구하는 문제였다면, 간단히 PQ와 가중치배열을 사용한 다익스트라 알고리즘으로 풀면 된다.
    하지만, 트랩 노드에 의해 간선의 방향이 바뀔 수 있다는 점이 큰 변수이다. 이 문제를 해결하기 위해 아래와 같은 아이디어를 적용했다.
        * 주어진 간선이 a->b라면, b->a 간선도 만들어서 저장한다.
        * 이 때, 원래 주어진 간선과 이를 뒤집은 간선을 표시한다. isOriginal이라는 플래그로 표시했다.
        * 핵심적인 아이디어는 다익스트라 알고리즘을 수행하면서 각 탐색노드와 더불어 해당 노드를 탐색할 시점의 트랩의 상태를 저장해야한다는 것이다.
          트랩은 10개 이하로 주어지므로, 비트마스킹으로 트랩의 상태를 저장한다. (0 ~ 2^10)
        * PQ에 현재 노드 번호, 현재까지의 가중치, 트랩의 상태 이렇게 3가지 정보를 저장하면서 다익스트라 알고리즘을 수행하면 문제를 풀 수 있다.

    아이디어를 얻은 레퍼런스 주소 : https://yabmoons.tistory.com/683
 */

class MazeEscaping {

    List<List<Edge>> adj;
    HashMap<Integer, Integer> hstraps;
    int ans = Integer.MAX_VALUE;

    public int solution(int n, int start, int end, int[][] roads, int[] traps) {

        adj = new ArrayList<>(n);
        for(int i=0; i<n; ++i) {
            adj.add(new LinkedList<>());
        }

        for(int i=0; i<roads.length; ++i) {
            int a = roads[i][0] - 1;
            int b = roads[i][1] - 1;
            int c = roads[i][2];
            adj.get(a).add(new Edge(b, c, true));
            adj.get(b).add(new Edge(a, c, false));
        }

        hstraps = new HashMap<>();
        int idx = 0;
        for (int trap : traps) {
            hstraps.put(trap-1, idx++);
        }

        dijkstra(start-1, end-1, n);

        return ans;
    }

    public void dijkstra(int start, int end, int n) {

        PriorityQueue<SearchNode> pq = new PriorityQueue<>();

        int maxState = (int) Math.pow(2, 10);
        int[][] dst = new int[n][maxState];
        for(int i=0; i<n; ++i) {
            for(int j=0; j<maxState; ++j) {
                dst[i][j] = Integer.MAX_VALUE;
            }
        }

        pq.add(new SearchNode(start, 0, 0));
        while(!pq.isEmpty()) {
            SearchNode cur = pq.poll();
            int node = cur.node;
            int cost = cur.cost;
            int state = cur.state;

            if(node == end) {
                ans = Math.min(ans, cost);
            }

            int curBinaryIdx = hstraps.getOrDefault(node, -1);
            int curToBinary = curBinaryIdx == -1 ? 0 :  (int) Math.pow(2, curBinaryIdx);
            int curMask = state & curToBinary;

            List<Edge> edges = adj.get(node);
            for(int i=0; i<edges.size(); ++i) {
                Edge edge = edges.get(i);
                int next = edge.node;
                int ncost = cost + edge.cost;
                boolean isOriginal = edge.isOriginal;

                int binaryIdx = hstraps.getOrDefault(next, -1);
                int nextToBinary = binaryIdx == -1 ? 0 : (int) Math.pow(2, binaryIdx);
                int nextMask = state & nextToBinary;
                if((isOriginal && ((curMask > 0 && nextMask > 0) || (curMask == 0 && nextMask == 0)))
                    || (!isOriginal && (curMask == 0 && nextMask > 0 || curMask > 0 && nextMask == 0))) {

                    int nstate = hstraps.containsKey(next) ? (state ^ nextToBinary) : state;
                    if(dst[next][nstate] > ncost) {
                        dst[next][nstate] = ncost;
                        pq.add(new SearchNode(next, ncost, nstate));
                    }
                }
            }
        }
    }

    static class Edge {
        int node, cost;
        boolean isOriginal;
        public Edge(int node, int cost, boolean isOriginal) {
            this.node = node;
            this.cost = cost;
            this.isOriginal = isOriginal;
        }
    }

    static class SearchNode implements Comparable<SearchNode> {
        int node, cost, state;
        public SearchNode(int node, int cost, int state) {
            this.node = node;
            this.cost = cost;
            this.state = state;
        }

        @Override
        public int compareTo(SearchNode o) {
            return this.cost - o.cost;
        }
    }
}