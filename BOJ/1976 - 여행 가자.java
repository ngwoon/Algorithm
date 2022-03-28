import java.io.*;
import java.util.HashSet;
import java.util.Set;

import static java.lang.Integer.parseInt;

/*
    도시의 연결 상태와 도시 여행 경로가 주어질 때, 주어진 도시 여행 경로대로 도시를 탐색할 수 있는지를 구하는 문제.

    <나의 풀이>
    한 번 방문한 도시를 다시 거쳐서 다른 도시를 방문하는것이 허용되기 때문에, 도시 경로로 주어진 도시들이 서로 다른 그룹에 존재하는 경우가 아닌 한 여행 가능하다.
    따라서 주어진 도시들을 순차탐색하면서, 아직 방문하지 않은 도시에서 dfs를 수행하여 해당 dfs로 방문한 도시들의 집합을 구한 뒤, 그 집합이 도시 여행 경로 집합을 포함하고 있는지
    여부로 답을 구했다.
 */

class LetsGoTravel {

    static int n, m;
    static boolean[][] adj;
    static boolean[] visited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = parseInt(br.readLine());
        m = parseInt(br.readLine());

        adj = new boolean[n][n];
        for(int i=0; i<n; ++i) {
            String[] connInfo = br.readLine().split(" ");
            for(int j=0; j<connInfo.length; ++j) {
                adj[i][j] = connInfo[j].equals("1");
            }
        }

        String travelRouteLine = br.readLine();
        String[] travelRouteStr = travelRouteLine.split(" ");
        Set<Integer> travelCities = new HashSet<>();
        for(String str : travelRouteStr) {
            travelCities.add(parseInt(str) - 1);
        }

        visited = new boolean[n];
        String ans = "NO";
        for(int i=0; i<n; ++i) {
            if(!visited[i]) {
                Set<Integer> group = new HashSet<>();
                dfs(i, group);
                if(group.containsAll(travelCities)) {
                    ans = "YES";
                    break;
                }
            }
        }

        bw.write(ans);
        bw.flush();
    }

    public static void dfs(int cur, Set<Integer> group) {
        visited[cur] = true;
        group.add(cur);

        for(int i=0; i<n; ++i) {
            if(adj[cur][i] && !group.contains(i)) {
                dfs(i, group);
            }
        }
    }
}