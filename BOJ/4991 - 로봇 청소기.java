import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

import static java.lang.Integer.parseInt;

/*
    청소해야 하는 방의 상태와 로봇청소기의 위치가 주어질 때, 모든 먼지를 청소하는데 필요한 최소 이동 횟수를 구하는 문제.

    <나의 풀이>
    로봇 청소기와 먼지의 위치에 따라 어떤 먼지를 먼저 청소해야하는지가 달라진다. 즉, greedy하게 청소할 먼지를 결정할 수 없다.
    따라서 청소한 먼지의 순서를 완전탐색을 통해 결정해야 하고, 매번 먼지 사이의 거리를 계산하면 중복된 계산이 많이 발생하므로 미리 구해두는 것이 시간복잡도 측면에서 좋다.

    먼지의 개수가 최대 10개이므로, 로봇의 시작점을 포함해 최대 11개의 노드가 존재하는 그래프로 상상해볼 수 있다.
    각 노드 사이의 거리를 계산해줌으로써 각 노드 사이 간선을 연결해준다.
    노드 사이의 최단거리를 구하는 데에는 여러 가지 알고리즘이 있지만, 노드의 개수가 최대 11개로 매우 적기 때문에 플로이드 와샬을 고려해볼 수 있다.
    플로이드 와샬로 임의의 노드 a에서 b로 가는 최단경로를 모두 구해둔 뒤, 완전탐색을 통해 청소할 먼지의 순서를 정하고 그 순서대로 청소할 때 로봇이 얼마나 이동하는지를 계산하면 풀린다.
 */

class RobotCleaner {

    static int INF = 400;
    static int[] dx = {1,0,-1,0};
    static int[] dy = {0,1,0,-1};
    static char DIRTY = '*', FURNITURE = 'x', ROBOT = 'o';

    static char[][] floor;
    static int[][] adj;
    static Pos[] dirties;
    static int w, h, d;
    static long ans;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        while(true) {
            StringTokenizer stzr = new StringTokenizer(br.readLine());
            w = parseInt(stzr.nextToken());
            h = parseInt(stzr.nextToken());
            d = 0;

            if(w == 0 && h == 0) {
                break;
            }

            dirties = new Pos[11];
            floor = new char[h][w];
            int dIdx = 1;
            for(int i=0; i<h; ++i) {
                floor[i] = br.readLine().toCharArray();
                for(int j=0; j<w; ++j) {
                    if(floor[i][j] == DIRTY) {
                        dirties[dIdx++] = new Pos(i, j);
                        d += 1;
                    } else if(floor[i][j] == ROBOT) {
                        dirties[0] = new Pos(i, j);
                    }
                }
            }

            adj = new int[d+1][d+1];
            for(int i=0; i<=d; ++i) {
                for(int j=0; j<=d; ++j) {
                    adj[i][j] = i == j ? 0 : INF;
                }
            }
            for(int i=0; i<=d; ++i) {
                for(int j=i+1; j<=d; ++j) {
                    int dist = calcDist(dirties[i], dirties[j]);
                    adj[i][j] = dist;
                    adj[j][i] = dist;
                }
            }

            // 플로이드 와샬
            for(int i=0; i<=d; ++i) {
                for(int j=0; j<=d; ++j) {
                    for(int k=0; k<=d; ++k) {
                        if(adj[j][i] + adj[i][k] < adj[j][k]) {
                            adj[j][k] = adj[j][i] + adj[i][k];
                        }
                    }
                }
            }

            ans = INF;
            // 완전탐색으로 먼지 탐색 순서 정하기
            decideDirtyOrder(new int[d+1], 1, new boolean[d+1]);

            bw.write((ans >= INF ? -1 : ans) + "\n");
        }

        bw.flush();
    }

    public static void decideDirtyOrder(int[] order, int idx, boolean[] visited) {
        if(idx == d+1) {
            ans = Math.min(ans, cleaning(order));
            return;
        }

        for(int i=1; i<=d; ++i) {
            if(!visited[i]) {
                visited[i] = true;
                order[idx] = i;
                decideDirtyOrder(order, idx+1, visited);
                visited[i] = false;
            }
        }

    }

    public static long cleaning(int[] order) {
        long dst = 0;
        for(int i=0; i<d; ++i) {
            dst += adj[order[i]][order[i+1]];
        }
        return dst;
    }

    public static int calcDist(Pos a, Pos b) {
        return bfs(a.y, a.x, b.y, b.x);
    }

    public static int bfs(int sy, int sx, int ey, int ex) {
        boolean[][] visited = new boolean[h][w];
        Queue<Move> que = new LinkedList<>();
        que.add(new Move(sy, sx, 0));
        visited[sy][sx] = true;

        int dst = INF;
        while(!que.isEmpty()) {
            Move cur = que.poll();
            int cy = cur.y;
            int cx = cur.x;
            int cdst = cur.dst;

            if(cy == ey && cx == ex) {
                dst = cdst;
                break;
            }

            for(int i=0; i<4; ++i) {
                int ny = cy + dy[i];
                int nx = cx + dx[i];
                if(ny < 0 || ny >= h || nx < 0 || nx >= w) {
                    continue;
                }
                if(visited[ny][nx] || floor[ny][nx] == FURNITURE) {
                    continue;
                }

                visited[ny][nx] = true;
                que.add(new Move(ny, nx, cdst + 1));
            }
        }

        return dst;
    }

    static class Move {
        int y,x,dst;
        public Move(int y, int x, int dst) {
            this.y = y;
            this.x = x;
            this.dst = dst;
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