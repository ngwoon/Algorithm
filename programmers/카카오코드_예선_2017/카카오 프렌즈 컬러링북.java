package 카카오코드_예선_2017;

import java.util.LinkedList;
import java.util.Queue;

/*
    그림책이 주어질 때, 서로 구분된 영역의 개수와 최대 크기를 갖는 영역의 크기를 구하는 문제.

    <나의 풀이>
    bfs를 활용하여 한 영역을 간단히 구할 수 있다.
 */

class KakaoFreindsColoringBook {

    boolean[][] visited;

    int[] dy = {0,0,1,-1};
    int[] dx = {1,-1,0,0};

    public int[] solution(int m, int n, int[][] picture) {

        visited = new boolean[m][n];
        int numOfArea = 0;
        int maxNumOfArea = 0;
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                if(picture[i][j] > 0 && !visited[i][j]) {
                    ++numOfArea;
                    maxNumOfArea = Math.max(maxNumOfArea, bfs(m, n, i, j, picture));
                }
            }
        }

        int[] ans = new int[2];
        ans[0] = numOfArea;
        ans[1] = maxNumOfArea;
        return ans;
    }

    public int bfs(int m, int n, int sy, int sx, int[][] picture) {

        Queue<Pos> que = new LinkedList<>();
        visited[sy][sx] = true;
        que.add(new Pos(sy, sx));

        int color = picture[sy][sx];
        int numOfArea = 1;
        while(!que.isEmpty()) {
            Pos cur = que.poll();
            int cy = cur.y;
            int cx = cur.x;

            for(int i=0; i<4; ++i) {
                int ny = cy + dy[i];
                int nx = cx + dx[i];
                if(ny < 0 || ny >= m || nx < 0 || nx >= n) {
                    continue;
                }
                if(visited[ny][nx] || picture[ny][nx] != color) {
                    continue;
                }
                visited[ny][nx] = true;
                que.add(new Pos(ny, nx));
                ++numOfArea;
            }
        }

        return numOfArea;
    }

    static class Pos {
        int y, x;
        public Pos(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
}