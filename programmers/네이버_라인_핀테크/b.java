package 네이버_라인_핀테크;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;

class B {

    int n, e;

    public int solution(int[] x, int[] y) {

        n = x.length;
        e = n * (n-1) / 2; // 간선의 개수
        ArrayList<Edge> edgeList = new ArrayList<>(e);
        HashSet<String> visited = new HashSet<>();
        for(int i=0; i<n-1; ++i) {
            for(int j=i+1; j<n; ++j) {
                int dst = (int) Math.ceil(Math.sqrt(Math.pow(y[j] - y[i], 2) + Math.pow(x[j] - x[i], 2)));
                Edge edge = new Edge(y[j], x[j], y[i], x[i], dst);
                edgeList.add(edge);
            }
        }

        Collections.sort(edgeList);

        int ans = 0 ;
        for (Edge edge : edgeList) {
            String a = edge.ay + " " + edge.ax;
            String b = edge.by + " " + edge.by;
            if(!visited.contains(a) || !visited.contains(b)) {
                ans = edge.dst;
                visited.add(a); visited.add(b);
            }
        }

        return ans;
    }

    static class Edge implements Comparable<Edge> {
        int ay, ax, by, bx, dst;
        public Edge(int ay, int ax, int by, int bx, int dst) {
            this.ay = ay;
            this.ax = ax;
            this.by = by;
            this.bx = bx;
            this.dst = dst;
        }

        @Override
        public int compareTo(Edge o) {
            return this.dst - o.dst;
        }
    }
}