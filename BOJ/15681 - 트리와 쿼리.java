import java.io.*;
import java.util.ArrayList;
import java.util.List;

import static java.lang.Integer.parseInt;

/*
    트리의 연결 상태와 노드의 개수, 루트 노드 번호, 쿼리 개수가 주어질 때, 쿼리로 주어진 노드를 루트로 하는 서브 트리에 속한 노드 개수를 출력하는 문제.

    <나의 풀이>
    트리의 연결 상태가 주어졌으므로, 그 정보를 바탕으로 트리를 만들고, 트리르 한 번 dfs로 탐색하여 각 노드의 자식 노드 개수를 구하면 된다.
 */

class TreeAndQuery {

    static int n, r, q;
    static Node[] nodes;
    static List<List<Node>> tree;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String varsLine = br.readLine();
        String[] varsStr = varsLine.split(" ");
        n = parseInt(varsStr[0]);
        r = parseInt(varsStr[1]);
        q = parseInt(varsStr[2]);

        nodes = new Node[n+1];
        tree = new ArrayList<>(n+1);
        for(int i=0; i<=n; ++i) {
            nodes[i] = new Node(i);
            tree.add(new ArrayList<>());
        }

        for(int i=0; i<n-1; ++i) {
            String nodesLine = br.readLine();
            String[] nodesStr = nodesLine.split(" ");
            int a = parseInt(nodesStr[0]);
            int b = parseInt(nodesStr[1]);
            tree.get(a).add(nodes[b]);
            tree.get(b).add(nodes[a]);
        }

        calcSubTreeSize(r, new boolean[n+1]);

        for(int i=0; i<q; ++i) {
            bw.write(String.valueOf(nodes[parseInt(br.readLine())].subTreeSize));
            bw.write("\n");
        }
        bw.flush();
    }

    public static int calcSubTreeSize(int cur, boolean[] visited) {
        visited[cur] = true;

        for(int i=0; i<tree.get(cur).size(); ++i) {
            Node child = tree.get(cur).get(i);
            if(visited[child.num]) {
                continue;
            }

            nodes[cur].subTreeSize += calcSubTreeSize(child.num, visited);
        }

        return nodes[cur].subTreeSize;
    }

    static class Node {
        int num, subTreeSize;
        public Node(int num) {
            this.num = num;
            subTreeSize = 1;
        }
    }
}