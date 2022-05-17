import java.io.*;

import static java.lang.Integer.parseInt;

/*
    방의 상태가 주어졌을 때, 한 쪽 문에서 다른 한 쪽 문을 볼 수 있게 거울을 설치할 때 그 최솟값을 구하는 문제.

    <나의 풀이>
    거울은 두 가지 방법으로 설치할 수 있으므로, 거울을 설치하는 모든 방법을 다 해 보아야 최소 개수를 구할 수 있다.
    단, visited 배열을 통해 중복된 경로 탐색을 하지 않게 만드는 것이 중요하다.

    visited 배열은 3차원 배열로, 1, 2차원은 방의 구조를 나타내고, 3차원은 빛이 들어오는 방향을 의미한다.
    예를 들어, 1, 2 좌표에 남쪽으로 빛이 들어왔었어도, 이후에 1, 2 좌표에 북쪽으로 빛이 들어오면 방문하지 않았던 것으로 여기고 경로 탐색을 이어간다.
    3차원으로 관리하지 않으면 정답 경로를 찾지 못하는 코너케이스가 존재한다. (아래 참조)

    9
    .!*......
    ..!.!*!.!
    #.!*.*.*.
    !!.*!.!*.
    .*.......
    .#......!
    .........
    .........
    !.......!
 */

class InstallingMirror {

    static int[] dx = {1,0,-1,0};
    static int[] dy = {0,1,0,-1};
    static int n;
    static char[][] room;
    static int[][][] visited;
    static Pos[] doors;
    static int ans = 2501;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        n = parseInt(br.readLine());

        room = new char[n][n];
        doors = new Pos[2];
        int dIdx = 0;
        for(int i=0; i<n; ++i) {
            room[i] = br.readLine().toCharArray();
            for(int j=0; j<n; ++j) {
                if(room[i][j] == '#') {
                    doors[dIdx++] = new Pos(i, j);
                }
            }
        }

        visited = new int[n][n][4];
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                for(int k=0; k<4; ++k) {
                    visited[i][j][k] = Integer.MAX_VALUE;
                }
            }
        }
        int sy = doors[0].y, sx = doors[0].x;
        for(int i=0; i<4; ++i) {
            dfs(sy, sx, i, 0);
        }

        bw.write(String.valueOf(ans));
        bw.flush();
    }

    public static void dfs(int y, int x, int dir, int mirrors) {
        if(y == doors[1].y && x == doors[1].x) {
            ans = Math.min(ans, mirrors);
            return;
        }

        visited[y][x][dir] = mirrors;

        for(int i=-1; i<=1; ++i) {
            if((room[y][x] == '.' || room[y][x] == '#') && i != 0) {
                continue;
            }

            int ndir = dir + i;
            if(ndir < 0) {
                ndir = 3;
            } else if(ndir > 3) {
                ndir = 0;
            }

            int ny = y + dy[ndir];
            int nx = x + dx[ndir];
            int nMirrors = i == 0 ? mirrors : mirrors + 1;
            if(ny >= 0 && ny < n && nx >= 0 && nx < n && room[ny][nx] != '*' && visited[ny][nx][ndir] > nMirrors) { // 거울의 개수가 더 적을때만?
                dfs(ny, nx, ndir, nMirrors);
            }
        }
    }

    static class Pos {
        int y, x;
        public Pos(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
}