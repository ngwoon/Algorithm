import java.io.*;
import java.util.ArrayList;
import java.util.List;

import static java.lang.Integer.parseInt;

/*
    동영상의 연관 관계가 주어졌을 때, 동영상 v와 연관 정도가 k 이상인 동영상의 개수를 출력하는 문제.

    <나의 풀이>
    임의의 동영상 a와 b의 연관정도는 a 비디오에서 b 비디오로 갈 수 있는 경로 중 가장 낮은 연관성을 따른다.
    따라서 a 비디오에서 dfs를 수행하여, b 비디오에 도달할 때까지 거친 경로 중 가장 낮은 연관성이 k보다 같거나 큰지 여부를 판단하면 된다.
 */

class MooTube {

    static int MIN_USADO = Integer.MIN_VALUE;
    static List<List<Node>> adj;
    static int n, q;
    static boolean[] visited;
    static int usaVideoCount;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String varsLine = br.readLine();
        String[] varsStr = varsLine.split(" ");
        n = parseInt(varsStr[0]);
        q = parseInt(varsStr[1]);

        adj = new ArrayList<>(n+1);
        for(int i=0; i<=n; ++i) {
            adj.add(new ArrayList<>());
        }

        for(int i=0; i<n-1; ++i) {
            varsLine = br.readLine();
            varsStr = varsLine.split(" ");
            int a = parseInt(varsStr[0]);
            int b = parseInt(varsStr[1]);
            int c = parseInt(varsStr[2]);
            adj.get(a).add(new Node(b, c));
            adj.get(b).add(new Node(a, c));
        }

        visited = new boolean[n+1];
        for(int i=0; i<q; ++i) {
            varsLine = br.readLine();
            varsStr = varsLine.split(" ");
            int k = parseInt(varsStr[0]);
            int v = parseInt(varsStr[1]);

            usaVideoCount = 0;
            dfs(v, k, MIN_USADO);
            bw.write(usaVideoCount + "\n");
        }

        bw.flush();
    }

    public static void dfs(int cur, int k, int minUsado) {
        visited[cur] = true;
        if(minUsado >= k) {
            usaVideoCount += 1;
        }

        for(int i=0; i<adj.get(cur).size(); ++i) {
            Node nextNode = adj.get(cur).get(i);
            if(visited[nextNode.num]) {
                continue;
            }
            dfs(nextNode.num, k, (minUsado == MIN_USADO ? nextNode.usado : Math.min(nextNode.usado, minUsado)));
        }

        visited[cur] = false;
    }

    static class Node {
        int num, usado;
        public Node(int num, int usado) {
            this.num = num;
            this.usado = usado;
        }
    }
}