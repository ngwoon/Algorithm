import java.io.*;
import java.util.StringTokenizer;

import static java.lang.Integer.parseInt;

/*
    C의 위치 두 곳과 맵의 상태가 주어질 때, 두 위치의 C가 서로 레이저로 통신하기 위해 필요한 거울의 최소 개수를 구하는 문제.

    <나의 풀이>
    이 문제를 다르게 해석하면, 한 위치의 C에서 다른 위치의 C까지 가는 경로 중 "방향 전환"을 최소로 하여 가는 경로를 구하는 문제이다.
    즉, dfs와 같은 탐색 알고리즘을 사용할 수 있다.
    단, 구해야 하는 경로가 최소 거리가 아닌 최소 방향 전환이므로, visited 배열을 boolean 형이 아닌 int 형을 사용했다.
    visited[a][b]는 a, b 좌표까지 이동 가능한 경로들 중 사용한 거울의 최소 개수를 의미한다.

    한 가지 주의해야 할 점이 있다.
    이전에 어떤 임의의 경로로 2개의 거울을 사용해 a,b 좌표에 진입했었다고 가정할 때, 이전과는 다른 경로로 2개의 거울을 사용해 a,b 좌표에 진입했다면 그 경우도 탐색해 보아야 한다.
    현재 진행중인 방향으로 a,b좌표를 거쳤을 때, 최종적으로 방향 전환을 덜 수행하여 도착점에 도달할 수도 있기 때문이다.
 */

class RaserCommunication {

    static int INF = Integer.MAX_VALUE;
    static int w, h;
    static char[][] map;
    static Pos[] poses;
    static int ans;
    static int[][] visited;
    static int[] dx = {1,0,-1,0};
    static int[] dy = {0,1,0,-1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer stzr = new StringTokenizer(br.readLine());
        w = parseInt(stzr.nextToken());
        h = parseInt(stzr.nextToken());

        map = new char[h][w];
        poses = new Pos[2];
        int pIdx = 0;
        for(int i=0; i<h; ++i) {
            map[i] = br.readLine().toCharArray();
            for(int j=0; j<w; ++j) {
                if(map[i][j] == 'C') {
                    poses[pIdx++] = new Pos(i, j);
                }
            }
        }

        visited = new int[h][w];
        for(int i=0; i<h; ++i) {
            for(int j=0; j<w; ++j) {
                visited[i][j] = INF;
            }
        }
        visited[poses[0].y][poses[0].x] = 0;
        ans = INF;
        dfs(poses[0].y, poses[0].x, -1, -1);

        bw.write(String.valueOf(ans));
        bw.flush();
    }

    public static void dfs(int y, int x, int dir, int turn) {
        if(y == poses[1].y && x == poses[1].x) {
            ans = Math.min(ans, turn);
            return;
        }

        for(int i=0; i<4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            int nturn = i == dir ? turn : turn + 1;
            if(ny < 0 || ny >= h || nx < 0 || nx >= w) {
                continue;
            }
            if(visited[ny][nx] < nturn || map[ny][nx] == '*') {
                continue;
            }

            visited[ny][nx] = nturn;
            dfs(ny, nx, i, nturn);
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