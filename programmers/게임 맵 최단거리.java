import java.util.LinkedList;
import java.util.Queue;

/*
    맵이 주어질 때, 좌측 상단에서 우측 하단까지의 최단거리를 구하는 문제.

    <나의 풀이>
    간단한 bfs 문제이다.
 */

class ShortestPath {

    int[] dx = {0,1,0,-1};
    int[] dy = {-1,0,1,0};

    public int solution(int[][] maps) {
        return bfs(maps);
    }

    public int bfs(int[][] maps) {

        int n = maps.length;
        int m = maps[0].length;

        Queue<Info> que = new LinkedList();
        boolean[][] visited = new boolean[n][m];
        visited[0][0] = true;
        que.add(new Info(0,0,1));
        while(!que.isEmpty()) {
            Info cur = que.poll();
            int cy = cur.y;
            int cx = cur.x;
            int move = cur.move;

            if(cy == n-1 && cx == m-1) {
                return move;
            }

            for(int i=0; i<4; ++i) {
                int ny = cy + dy[i];
                int nx = cx + dx[i];

                if(ny < 0 || ny >= n || nx < 0 || nx >= m) {
                    continue;
                }
                if(visited[ny][nx] || maps[ny][nx] == 0) {
                    continue;
                }

                que.add(new Info(ny, nx, move + 1));
                visited[ny][nx] = true;
            }
        }

        return -1;
    }

    static class Info {
        int y, x;
        int move;
        public Info(int y, int x, int move) {
            this.y = y;
            this.x = x;
            this.move = move;
        }
    }
}