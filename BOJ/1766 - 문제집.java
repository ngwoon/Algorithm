import java.io.*;
import java.util.*;

import static java.lang.Integer.parseInt;

/*
    풀어야 할 문제들과 먼저 풀면 좋은 문제 정보가 주어질 때, 문제 조건에 맞게 모든 문제를 푸는 순서를 구하는 문제.

    <나의 풀이>
    이 문제는 문제 해석이 애매해서 어려웠던 문제였다.
    1 2 3 4 5 문제가 존재하는 문제집과, 5번 문제를 1번 문제보다 먼저 풀어야 한다는 조건이 주어졌을 때,
    정답은 5 1 2 3 4 가 아닌 2 3 4 5 1 이 되어야 한다.

    노드의 순서를 결정하는 문제라는 점에서 위상정렬 알고리즘을 떠올렸다.
    b번 문제를 a번 문제보다 먼저 풀어야 한다는 조건은, b -> a 의존성으로 생각할 수 있다.

    여기에 더해, 일반적인 위상정렬은 그냥 큐를 쓰지만, 이 문제에서는 문제 번호가 낮은 문제를 가능한 한 먼저 풀어야하므로 우선순위 큐를 활용했다.

    진입 차수가 0인 노드들을 우선순위 큐에 넣고, 순차적으로 꺼내면서 그 노드와 연결된 간선들을 삭제 (연결된 노드의 진입 차수를 1 감소) 한다.
    연결되어 있던 노드의 진입 차수가 방금 작업으로 0이 되었다면, 우선순위 큐에 넣어주는 방식으로 문제를 풀면 풀린다.
 */

class WorkBook {

    static List<List<Integer>> adj;
    static int[] indegree;
    static int n, m;
    static List<Integer> ans;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer stzr = new StringTokenizer(br.readLine());
        n = parseInt(stzr.nextToken());
        m = parseInt(stzr.nextToken());

        adj = new ArrayList<>(n+1);
        for(int i=0; i<=n; ++i) {
            adj.add(new ArrayList<>());
        }

        indegree = new int[n+1];
        for(int i=0; i<m; ++i) {
            stzr = new StringTokenizer(br.readLine());
            int a = parseInt(stzr.nextToken());
            int b = parseInt(stzr.nextToken());
            adj.get(a).add(b);
        }

        for(int i=1; i<=n; ++i) {
            Collections.sort(adj.get(i));
        }

        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for(int i=1; i<=n; ++i) {
            if(indegree[i] == 0) {
                pq.add(i);
            }
        }

        ans = new ArrayList<>(n);
        while(!pq.isEmpty()) {
            int pNum = pq.poll();
            ans.add(pNum);

            for(int i=0; i<adj.get(pNum).size(); ++i) {
                int neighbor = adj.get(pNum).get(i);
                indegree[neighbor] -= 1;
                if(indegree[neighbor] == 0) {
                    pq.add(neighbor);
                }
            }
        }

        for(int i=0; i<ans.size(); ++i) {
            bw.write(String.valueOf(ans.get(i)));
            if(i < ans.size() - 1) {
                bw.write(" ");
            }
        }
        bw.flush();
    }
}