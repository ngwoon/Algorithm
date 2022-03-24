import java.io.*;

import static java.lang.Integer.parseInt;

/*
    행, 열의 크기와 경로의 길이가 주어질 때, 주어진 경로 길이와 동일한 길이로 시작 - 끝 지점을 잇는 경로의 개수를 구하는 문제.

    <나의 풀이>
    시작점 (왼쪽 하단) 부터, 끝점 (우측 상단) 까지 dfs를 수행하면서, 끝점에 도달했을 때의 길이가 문제에서 주어진 길이라면 정답으로 체크한다.
 */

class ComeBackHome {

    static int sy, sx, ey, ex;
    static boolean[][] visited;
    static int r, c, k;
    static int ans;
    static char[][] map;
    static int[] dx = {1,0,-1,0};
    static int[] dy = {0,1,0,-1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String varsLine = br.readLine();
        String[] varsStr = varsLine.split(" ");

        r = parseInt(varsStr[0]);
        c = parseInt(varsStr[1]);
        k = parseInt(varsStr[2]);

        map = new char[r][c];
        for(int i=0; i<r; ++i) {
            map[i] = br.readLine().toCharArray();
        }

        sy = r-1; sx = 0; ey = 0; ex = c-1;
        visited = new boolean[r][c];
        dfs(sy, sx, 1);

        bw.write(String.valueOf(ans));
        bw.flush();
    }

    public static void dfs(int cy, int cx, int dst) {
        visited[cy][cx] = true;
        if(dst == k && cy == ey && cx == ex) {
            ans += 1;
            return;
        }

        for(int i=0; i<4; ++i) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if(ny < 0 || ny >= r || nx < 0 || nx >= c) {
                continue;
            }
            if(visited[ny][nx]) {
                continue;
            }

            int ndst = dst + 1;
            if(ndst > k) {
                continue;
            }

            if(map[ny][nx] == 'T') {
                continue;
            }

            dfs(ny, nx, ndst);
            visited[ny][nx] = false;
        }
    }
}