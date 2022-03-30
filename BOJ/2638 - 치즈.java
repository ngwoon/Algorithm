import java.io.*;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

import static java.lang.Integer.parseInt;

/*
    초기 치즈 상태가 주어질 때, 치즈가 몇 시간 이후 전부 녹는지 구하는 문제.

    <나의 풀이>
    bfs를 활용하면 쉽게 풀릴 듯 하나, 치즈에 둘러싸여 있는 영역에는 공기가 없다는 특이점이 있는 문제였다.

    문제를 두 단계로 나눠서 생각했다.
        1. 공기가 퍼진다.
        2. 한 시간동안, 공기와 두 면 이상 맞닿아있는 치즈가 녹는다.

    좌표 0, 0은 치즈로 둘러싸일 수 없는, 반드시 공기인 구간이기에 공기가 퍼지는 과정을 0, 0좌표에서 시작하는 bfs로 구했고,
    이번 시간에 녹을 치즈를 구하기 위해 map[i][j] == CHEESE인 좌표에서 bfs를 수행하여, 두 면 이상이 AIR와 맞닿아있는 좌표들을 구한 뒤 녹였다.
    위 두 과정을 반복하여 모든 좌표가 AIR가 되면 종료한다.
 */

class Cheese {

    static int AIR = -1, CHEESE = 1, NONE = 0;
    static int n, m;
    static int[][] map;
    static int[] dx = {1,0,-1,0};
    static int[] dy = {0,1,0,-1};

    static List<Pos> airs;
    static List<Pos> meltCheese;
    static boolean[][] visited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String varsLine = br.readLine();
        String[] varsStr = varsLine.split(" ");
        n = parseInt(varsStr[0]);
        m = parseInt(varsStr[1]);

        map = new int[n][m];
        for(int i=0; i<n; ++i) {
            String line = br.readLine();
            String[] elements = line.split(" ");
            for(int j=0; j<m; ++j) {
                map[i][j] = parseInt(elements[j]);
            }
        }

        airs = new ArrayList<>();
        meltCheese = new ArrayList<>();
        visited = new boolean[n][m];
        int time = 0;
        while (!isAllMelted()) {
            bfs(0, 0, AIR, airs);
            spreadAir();
            resetVisited();

            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (map[i][j] == CHEESE && !visited[i][j]) {
                        bfs(i, j, CHEESE, meltCheese);
                    }
                }
            }
            meltCheese();

            airs.clear();
            meltCheese.clear();
            resetVisited();
            time += 1;
        }

        bw.write(String.valueOf(time));
        bw.flush();
    }

    public static void bfs(int y, int x, int target, List<Pos> poses) {
        Queue<Pos> que = new LinkedList<>();
        visited = new boolean[n][m];
        que.add(new Pos(y, x));
        visited[y][x] = true;

        while(!que.isEmpty()) {
            Pos cur = que.poll();
            int cy = cur.y;
            int cx = cur.x;

            if(target == CHEESE)  {
                int airContactCount = 0;
                for(int j=0; j<4; ++j) {
                    if(map[cy + dy[j]][cx + dx[j]] == AIR) {
                        airContactCount += 1;
                    }
                }
                if(airContactCount >= 2) {
                    poses.add(new Pos(cy, cx));
                }
            } else {
                if(map[cy][cx] == NONE) {
                    poses.add(new Pos(cy, cx));
                }
            }

            for(int i=0; i<4; ++i) {
                int ny = cy + dy[i];
                int nx = cx + dx[i];
                if(ny < 0 || ny >= n || nx < 0 || nx >= m) {
                    continue;
                }
                if(visited[ny][nx]) {
                    continue;
                }
                if(target == CHEESE && map[ny][nx] != CHEESE) {
                    continue;
                }
                if(target == AIR && map[ny][nx] == CHEESE) {
                    continue;
                }

                que.add(new Pos(ny, nx));
                visited[ny][nx] = true;
            }
        }
    }

    public static void meltCheese() {
        for (Pos cheese : meltCheese) {
            map[cheese.y][cheese.x] = AIR;
        }
    }

    public static void spreadAir() {
        for (Pos air : airs) {
            map[air.y][air.x] = AIR;
        }
    }

    public static void resetVisited() {
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                visited[i][j] = false;
            }
        }
    }

    public static boolean isAllMelted() {
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                if(map[i][j] == CHEESE) {
                    return false;
                }
            }
        }
        return true;
    }

    static class Pos {
        int y, x;
        public Pos(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
}