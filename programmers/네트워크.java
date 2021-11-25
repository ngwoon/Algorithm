import java.util.LinkedList;
import java.util.Queue;

/*
    컴퓨터의 연결 상태가 주어졌을 때, 네트워크의 개수를 구하는 문제.

    <나의 풀이>
    기본적인 dfs, bfs 문제이다.
    노드 번호를 순회하면서, 방문 체크가 되지 않은 노드를 시작점으로 bfs를 수행하고, 이를 하나의 네트워크로 간주하는 방법으로 풀었다.
 */

class Network {

    public void bfs(int start, boolean[] visited, int[][] computers, int n) {

        Queue<Integer> que = new LinkedList<>();
        que.add(start);
        visited[start] = true;

        while(!que.isEmpty()) {
            int cur = que.poll();

            for(int i=0; i<n; ++i) {
                if(computers[cur][i] == 1) {
                    if(!visited[i]) {
                        que.add(i);
                        visited[i] = true;
                    }
                }
            }
        }
    }

    public int solution(int n, int[][] computers) {

        boolean[] visited = new boolean[n];

        int ans = 0;
        for(int i=0; i<n; ++i) {
            if(!visited[i]) {
                bfs(i, visited, computers, n);
                ++ans;
            }
        }

        return ans;
    }
}