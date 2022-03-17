import java.io.*;
import java.util.*;

import static java.lang.Integer.parseInt;

/*
    컴퓨터의 개수, 컴퓨터를 연결할 수 있는 케이블들의 정보, 각 케이블의 가격, 무료로 설치할 수 있는 케이블 수가 주어졌을 때, 케이블 설치 시 필요한 최소 금액을 구하는 문제.

    <나의 풀이>
    풀지 못해서 구글링을 통해 아이디어를 얻었다.
    이 문제는 1번 컴퓨터와 N번 컴퓨터를 주어진 케이블을 조합해 연결하는 문제이다.
    각 케이블은 고유의 가격이 있으며, 설치회사에서 무료로 k개의 케이블을 설치해준다.

    이 문제는 "결정 문제" 이다. 즉, 가격 A를 들여서 조건을 만족하게끔 케이블을 설치할 수 있는지 여부를 확인하는 문제이다.
    보통 이러한 결정 문제에는 "이분 탐색"이 사용된다. 이분 탐색으로 가격 A를 설정하고, 그 가격으로 케이블을 설치할 수 있는지를 확인해야 한다.
    케이블 설치 가능 여부는 "다익스트라 알고리즘" 으로 판단할 수 있다. 일반적인 다익스트라는 시작점에서 모든 노드까지의 최소 가중치를 구하는 알고리즘이지만,
    여기서는 이를 약간 변형하여, 시작점에서 각 노드까지 도달할 때 거쳐야 할 가격 A보다 높은 케이블의 개수를 구하는 역할을 한다.

    dst[i]는 0번 컴퓨터 (시작점) 에서 i번 컴퓨터까지 도달할 때, 거쳐야 하는 가격 A를 초과하는 케이블의 최소 개수가 저장된다.
    한 번 다익스트라 알고리즘을 수행한 뒤, dst[n-1]에 담긴 값이 k보다 크면 가격 A는 정답이 될 수 없고, k 이하이면 정답이 될 수 있다.
 */

class InternetInstallation {

    static int INF = 1000001;
    static int n, p, k, ans = INF;
    static List<List<Edge>> adj;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String varsLine = br.readLine();
        String[] varsStr = varsLine.split(" ");
        n = parseInt(varsStr[0]);
        p = parseInt(varsStr[1]);
        k = parseInt(varsStr[2]);

        adj = new ArrayList<>(n);
        for(int i=0; i<n; ++i) {
            adj.add(new ArrayList<>());
        }

        int maxCost = 0;
        for(int i=0; i<p; ++i) {
            String edgeLine = br.readLine();
            String[] edgeStr = edgeLine.split(" ");
            int v1 = parseInt(edgeStr[0]) - 1;
            int v2 = parseInt(edgeStr[1]) - 1;
            int cost = parseInt(edgeStr[2]);
            adj.get(v1).add(new Edge(v2, cost));
            adj.get(v2).add(new Edge(v1, cost));
            maxCost = Math.max(maxCost, cost);
        }

        int low = 0, high = maxCost;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(dijkstra(mid)) {
                high = mid - 1;
                ans = Math.min(ans, mid);
            } else {
                low = mid + 1;
            }
        }

        bw.write(ans == INF ? "-1" : String.valueOf(ans));
        bw.flush();
    }

    public static boolean dijkstra(int minCost) {
        int[] dst = new int[n];
        dst[0] = 0;
        for(int i=1; i<n; ++i) {
            dst[i] = INF;
        }
        PriorityQueue<MoveInfo> pq = new PriorityQueue<>();
        pq.add(new MoveInfo(0, 0));
        while(!pq.isEmpty()) {
            MoveInfo moveInfo = pq.poll();
            int cur = moveInfo.node;
            int count = moveInfo.count;

            List<Edge> edges = adj.get(cur);
            for(int i=0; i<edges.size(); ++i) {
                Edge edge = edges.get(i);
                int next = edge.node;
                int cost = edge.cost;

                if(cost <= minCost && count < dst[next]) {
                    dst[next] = count;
                    pq.add(new MoveInfo(next, count));
                } else if(cost > minCost && count + 1 < dst[next]) {
                    dst[next] = count + 1;
                    pq.add(new MoveInfo(next, count + 1));
                }
            }
        }

        return dst[n-1] <= k;
    }

    static class MoveInfo implements Comparable<MoveInfo> {
        int node, count;
        public MoveInfo(int node, int count) {
            this.node = node;
            this.count = count;
        }

        @Override
        public int compareTo(MoveInfo o) {
            return this.count - o.count;
        }
    }

    static class Edge {
        int node, cost;
        public Edge(int node, int cost) {
            this.node = node;
            this.cost = cost;
        }
    }
}