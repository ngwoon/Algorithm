package 월간_코드_챌린지_시즌3;

import java.util.*;

/*
    주어진 맵에 빛을 쏘았을 때, 가능한 모든 순환 경로의 길이를 구하는 문제.

    <나의 풀이>
    사이클을 구하기 위해선 좌표의 방문 여부가 아니라, 간선의 방문 여부를 확인해야 한다.
    임의의 간선부터 탐색을 시작하면서, 이미 방문한 간선을 한 번 더 지나게 된다면 사이클이 있다고 판단한다.
    단, 사이클이 있다고 판단할 땐 누적된 간선의 방문 여부가 아니라, 현재 턴의 방문 여부만을 갖고 판단해야 한다.
 */

class LightPathCycle {

    int[] dx = {1, 0, -1, 0};
    int[] dy = {0, 1, 0, -1};
    int n, m;
    List<Integer> ansList;

    public int[] solution(String[] grid) {
        m = grid[0].length();
        n = grid.length;
        boolean[][][] visited = new boolean[n][m][4];

        ansList = new LinkedList<>();
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                for(int d=0; d<4; ++d) {
                    if(!visited[i][j][d]) {
                        explore(grid, visited, i, j, d);
                    }
                }
            }
        }

        Collections.sort(ansList);

        int[] ans = new int[ansList.size()];
        int aIdx = 0;
        for (int dist : ansList) {
            ans[aIdx++] = dist;
        }
        return ans;
    }

    public void explore(String[] grid, boolean[][][] visited, int y, int x, int dir) {

        Set<String> curVisited = new HashSet<>();
        int dist = 0;
        while(true) {
            String condStr = conditionsToString(y, x, dir);
            if(curVisited.contains(condStr)) {
                ansList.add(dist);
                break;
            } else if(visited[y][x][dir]) {
                break;
            }
            visited[y][x][dir] = true;
            curVisited.add(condStr);

            int ny = y + dy[dir];
            int nx = x + dx[dir];

            if(ny < 0) ny = n-1;
            else if(ny >= n) ny = 0;
            if(nx < 0) nx = m-1;
            else if(nx >= m) nx = 0;

            y = ny; x = nx;

            char c = grid[y].charAt(x);
            switch(c) {
                case 'L': dir = (dir + 3) % 4; break;
                case 'R': dir = (dir + 1) % 4; break;
            }

            ++dist;
        }
    }

    public String conditionsToString(int y, int x, int d) {
        return y + " " + x + " " + d;
    }
}