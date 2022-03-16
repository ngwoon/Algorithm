import java.io.*;
import java.util.*;

class CowCross6 {

    static boolean[][] visited;
    static boolean[][] farm;
    static List<Integer> cows;
    static Set<String> roads;
    static int[] dx = {1,0,-1,0};
    static int[] dy = {0,1,0,-1};
    static int n, k, r;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String varsLine = br.readLine();
        String[] vars = varsLine.split(" ");
        n = Integer.parseInt(vars[0]);
        k = Integer.parseInt(vars[1]);
        r = Integer.parseInt(vars[2]);

        roads = new HashSet<>();
        for(int i=0; i<r; ++i) {
            String road = br.readLine();
            roads.add(road);

            String[] pos = road.split(" ");
            roads.add(pos[2] + " " + pos[3] + " " + pos[0] + " " + pos[1]);
        }

        farm = new boolean[n+1][n+1];
        for(int i=0; i<k; ++i) {
            String line = br.readLine();
            String[] pos = line.split(" ");
            farm[Integer.parseInt(pos[0])][Integer.parseInt(pos[1])] = true;
        }

        visited = new boolean[n+1][n+1];
        cows = new ArrayList<>();
        for(int i=1; i<=n; ++i) {
            for(int j=1; j<=n; ++j) {
                if(!visited[i][j]) {
                    bfs(i, j);
                }
            }
        }

        long pairs = 0;
        for(int i=0; i<cows.size()-1; ++i) {
            for(int j=i+1; j<cows.size(); ++j) {
                pairs += ((long) cows.get(i) * cows.get(j));
            }
        }

        bw.write(String.valueOf(pairs));
        bw.flush();
    }

    public static void bfs(int y, int x) {
        Queue<Pos> que = new LinkedList<>();
        que.add(new Pos(y, x));
        visited[y][x] = true;
        int cowCount = 0;
        while(!que.isEmpty()) {
            Pos cur = que.poll();
            int cy = cur.y;
            int cx = cur.x;

            if(farm[cy][cx]) {
                ++cowCount;
            }

            for(int i=0; i<4; ++i) {
                int ny = cy + dy[i];
                int nx = cx + dx[i];
                if(ny < 1 || ny > n || nx < 1 || nx > n) {
                    continue;
                }
                if(visited[ny][nx]) {
                    continue;
                }
                if(roads.contains(ny + " " + nx + " " + cy + " " + cx)) {
                    continue;
                }

                visited[ny][nx] = true;
                que.add(new Pos(ny, nx));
            }
        }

        if(cowCount != 0) {
            cows.add(cowCount);
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