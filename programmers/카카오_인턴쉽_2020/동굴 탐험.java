package 카카오_인턴쉽_2020;

import java.util.*;

/*
    동굴 속 각 방이 연결된 상태와 방 탐험 선행조건이 주어졌을 때, 해당 조건에 맞게 탐색 가능한지를 반환하는 문제.

    <나의 풀이>
    "선행 조건" 이라는 단어를 통해 위상정렬과 관련된 문제라는 것을 알 수 있다.
    위상정렬 알고리즘은 DAG 내에서 변의 방향에 어긋나지 않게 모든 노드를 나열할 수 있는지 판단하는 알고리즘이다.
    위상정렬 알고리즘을 적용하기 전 고려해야할 사항이 한 가지가 있다.
        * 문제에서 제시하는 path 2차원 배열은 단순히 두 방이 연결된 상태임만을 알려준다.
          위상정렬 알고리즘을 적용하기 위해선 DAG이어야 하므로, 두 방의 연결상태가 주어졌을 때 어느 방이 ROOT (방 번호 0) 와 가까운지를 알아야 한다.
    따라서 주어진 path에 따라 양방향 그래프 adj를 만든 뒤, bfs를 한 번 수행하면서 자식 -> 부모로 연결된 간선을 지워준다.
    그 뒤에 주어진 선행 조건을 간선으로 하여 adj에 추가하고, 이 그래프가 위상정렬이 가능한지를 검토하면 문제를 해결할 수 있다.
 */

class ExploreCave {

    List<List<Integer>> adj;
    List<Integer> entrance;
    int nSize;

    public boolean solution(int n, int[][] path, int[][] order) {

        nSize = n;

        adj = new ArrayList<>();
        entrance = new ArrayList<>(n);
        for(int i=0; i<n; ++i) {
            adj.add(new LinkedList<>());
            entrance.add(0);
        }

        for (int[] p : path) {
            adj.get(p[0]).add(p[1]);
            adj.get(p[1]).add(p[0]);
            entrance.set(p[0], entrance.get(p[0]) + 1);
            entrance.set(p[1], entrance.get(p[1]) + 1);
        }
        bfs();

        for (int[] o : order) {
            adj.get(o[0]).add(o[1]);
            entrance.set(o[1], entrance.get(o[1]) + 1);
        }

        return topologySort();
    }

    public boolean topologySort() {

        Queue<Integer> que = new LinkedList<>();
        que.add(0);

        while(!que.isEmpty()) {
            int cur = que.poll();

            List<Integer> related = adj.get(cur);
            for(int next : related) {
                entrance.set(next, entrance.get(next) - 1);
                if(entrance.get(next) == 0) {
                    que.add(next);
                }
            }
        }

        boolean isAllVisited = true;
        for(int i=0; i<nSize; ++i) {
            if(entrance.get(i) != 0) {
                isAllVisited = false;
                break;
            }
        }

        return isAllVisited;
    }

    public void bfs() {

        Queue<Integer> que = new LinkedList<>();
        boolean[] visited = new boolean[nSize];
        que.add(0);
        visited[0] = true;

        while(!que.isEmpty()) {
            int cur = que.poll();

            List<Integer> related = adj.get(cur);
            Iterator<Integer> iter = related.iterator();
            while(iter.hasNext()) {
                int next = iter.next();
                if(visited[next]) {
                    entrance.set(next, entrance.get(next) - 1);
                    iter.remove();
                } else {
                    visited[next] = true;
                    que.add(next);
                }
            }
        }
    }
}