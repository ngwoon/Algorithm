package KAKAO_BLIND_RECRUITMENT_2022;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

/*
    양과 늑대가 있는 이진 트리가 주어질 때, 양의 개수가 늑대 개수보다 많은 상태로 가장 많인 모을 수 있는 양의 개수를 구하는 문제.

    <나의 풀이>
    풀지 못해서 구글링을 통해 아이디어를 얻었다.
    이 문제는 dfs로 풀 수 있는데, 단순히 dfs로는 풀 수 없다.
    이 문제는 현재 모은 양, 늑대, 현재 위치, 현재 위치에서 가볼 수 있는 노드들 이 네 가지 변수가 존재한다.
    즉, 위 네 변수 중 하나라도 다르면 dfs를 진행해보아야 알 수 있다는 뜻이다.

    임의의 노드 n에 도착했을 때, 방문 가능 여부를 양과 늑대의 개수를 비교해 판단한다.
    방문 가능하다면, 양과 늑대의 개수를 갱신하고 현재 노드의 자식 노드를 방문 가능한 노드 배열에 넣는다.
    그리고 현재 방문 가능한 노드들을 순차적으로 dfs 탐색한다.

    주의할 점이 두 가지가 있다.
        1. 방문 가능한 노드를 탐색할 때, 이제 방문할 노드를 방문 가능한 노드 배열에서 제거한 뒤 방문해야 한다.
        2. 만약 dfs 수행할 때 새로 배열을 만들어서 인자로 넘겨주지 않고 매개변수로 받은 배열을 그대로 사용한다면, 모든 방문 가능한 노드를 방문해본 후에는
            아까 추가했던 자식 노드들을 없애주어야 한다.
 */

class SheepAndWolf {

    List<List<Integer>> adj;
    int[] ginfo;
    int tsheep, twolf;

    public int solution(int[] info, int[][] edges) {

        ginfo = info;
        int n = info.length;
        adj = new ArrayList<>(n);
        for(int i=0; i<n; ++i) {
            adj.add(new LinkedList<>());
        }
        for (int[] edge : edges) {
            adj.get(edge[0]).add(edge[1]);
        }

        dfs(0, 0, 0, new ArrayList<>());

        return tsheep;
    }

    public void dfs(int num, int sheep, int wolf, List<Integer> nodes) {
        int cs = sheep + (ginfo[num] ^ 1);
        int cw = wolf + ginfo[num];

        if(cs > cw) {
            if(tsheep < cs) {
                tsheep = cs;
                twolf = cw;
            }
            nodes.addAll(adj.get(num));
            for (int i=0; i<nodes.size(); ++i) {
                int node = nodes.remove(i);
                dfs(node, cs, cw, nodes);
                nodes.add(i, node);
            }
            nodes.removeAll(adj.get(num));
        }
    }
}