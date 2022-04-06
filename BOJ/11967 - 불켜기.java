import java.io.*;
import java.util.*;

import static java.lang.Integer.parseInt;

/*
    다른 방의 불을 켜거나 끌 수 있는 스위치가 어느 방에 위치하는지 정보가 주어질 때, 방을 돌아다니면서 켤 수 있는 방 불의 최대 개수를 구하는 문제.

    <나의 풀이>
    bfs를 사용해 풀었다.
        1. 1,1에서 시작해서, 이동 가능한 방으로 이동한다.
        2. 이동한 방에서 켤 수 있는 방의 불을 켠다.
        3. 위 bfs를 수행한 뒤, 만약 새로운 방의 불을 켰다면, bfs를 한 번 더 수행한다.
    위 과정을 새로운 방의 불을 켜지 못할 때 까지 반복한 뒤, 켜진 방 불의 개수를 구하면 정답이다.
 */

class SwitchOnOff {

    static int n, m;
    static boolean[][] rooms;
    static Map<String, List<Pos>> posSwitch;

    static int[] dx = {1,0,-1,0};
    static int[] dy = {0,1,0,-1};


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String varsLine = br.readLine();
        String[] varsStr = varsLine.split(" ");
        n = parseInt(varsStr[0]);
        m = parseInt(varsStr[1]);

        posSwitch = new HashMap<>();
        for(int i=0; i<m; ++i) {
            String line = br.readLine();
            String[] poses = line.split(" ");
            String key = poses[1] + " " + poses[0];
            List<Pos> switches = posSwitch.getOrDefault(key, new ArrayList<>());
            switches.add(new Pos(parseInt(poses[3]), parseInt(poses[2])));
            posSwitch.put(key, switches);
        }

        rooms = new boolean[n+1][n+1];
        rooms[1][1] = true;

        while(bfs());

        int count = 0;
        for(int i=1; i<=n; ++i) {
            for(int j=1; j<=n; ++j) {
                if(rooms[i][j]) {
                    ++count;
                }
            }
        }

        bw.write(String.valueOf(count));
        bw.flush();
    }

    public static boolean bfs() {
        boolean[][] visited = new boolean[n+1][n+1];
        Queue<Pos> que = new LinkedList<>();
        visited[1][1] = true;
        que.add(new Pos(1,1));

        boolean isSwitchClicked = false;
        while(!que.isEmpty()) {
            Pos cur = que.poll();

            List<Pos> switches = posSwitch.get(posToString(cur.y, cur.x));
            if(switches != null) {
                for (Pos pos : switches) {
                    if(!rooms[pos.y][pos.x]) {
                        isSwitchClicked = true;
                        rooms[pos.y][pos.x] = true;
                    }
                }
            }

            for(int i=0; i<4; ++i) {
                int ny = cur.y + dy[i];
                int nx = cur.x + dx[i];
                if(ny <= 0 || ny > n || nx <= 0 || nx > n) {
                    continue;
                }
                if(visited[ny][nx] || !rooms[ny][nx]) {
                    continue;
                }

                visited[ny][nx] = true;
                que.add(new Pos(ny, nx));
            }
        }

        return isSwitchClicked;
    }

    public static String posToString(int y, int x) {
        return y + " " + x;
    }

    static class Pos {
        int y, x;
        public Pos(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
}