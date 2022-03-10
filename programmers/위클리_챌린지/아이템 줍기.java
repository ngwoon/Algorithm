package 위클리_챌린지;

import java.util.LinkedList;
import java.util.Queue;

/*
    직사각형들의 위치와 플레이어의 시작점, 아이템 위치가 주어질 때, 아이템을 주울 수 있는 최단 이동 거리를 구하는 문제.

    <나의 풀이>
    이 문제의 핵심은 주어진 직사각형들의 테두리만 따라서 이동하는 것이다.
    직사각형 좌표의 크기가 크지 않으므로 (최대 50), map 배열을 만들어서 여기에 모든 직사각형의 선분들을 그린다.
    이후, 직사각형의 테두리만 남기기 위해 각 직사각형의 내부에 그려진 선분을 모두 지운다.
    이후에는 bfs 알고리즘으로 아이템까지의 최단 거리를 구하면 된다.

    주의할 점이 있는데, 하나의 선분 길이를 1로 잡고 직사각형을 그리게 되면 특정 상황에서 문제가 발생한다.
    경로 중 오목하게 파인 경로가 있다면, 본래는 꺾어야 할 지점에서 다른 곳으로 점프하는 경로를 탐색하게 된다.
    이를 방지하기 위해 선분 하나의 길이를 2로 잡고, 배열의 크기도 51이 아닌 102이상으로 잡아야 한다.
 */

class PickItem {

    boolean[][] map = new boolean[104][104];
    boolean[][] visited = new boolean[104][104];
    int[] dx = {2,0,-2,0};
    int[] dy = {0,2,0,-2};

    public int solution(int[][] rectangle, int cx, int cy, int ix, int iy) {

        for(int[] rect : rectangle) {
            rect[0] *= 2;
            rect[1] *= 2;
            rect[2] *= 2;
            rect[3] *= 2;
        }
        cx *= 2; cy *= 2; ix *= 2; iy *= 2;

        // map에 직사각형 그려넣기
        for (int[] rect : rectangle) {
            int lx = rect[0];
            int ly = rect[1];
            int rx = rect[2];
            int ry = rect[3];

            for(int i=lx; i<=rx; ++i) {
                map[ly][i] = true;
                map[ry][i] = true;
            }
            for(int i=ly; i<=ry; ++i) {
                map[i][lx] = true;
                map[i][rx] = true;
            }
        }

        // 직사각형 내부의 선들 지우기
        for(int[] rect : rectangle) {
            int lx = rect[0];
            int ly = rect[1];
            int rx = rect[2];
            int ry = rect[3];

            for(int i=ly+1; i<=ry-1; ++i) {
                for(int j=lx+1; j<=rx-1; ++j) {
                    map[i][j] = false;
                }
            }
        }

        return bfs(cy, cx, iy, ix);
    }

    public int bfs(int y, int x, int iy, int ix) {

        Queue<Status> que = new LinkedList<>();
        que.add(new Status(y, x,  0));
        visited[y][x] = true;

        while(!que.isEmpty()) {
            Status cur = que.poll();
            int cy = cur.y;
            int cx = cur.x;
            int mov = cur.mov;

            if(cy == iy && cx == ix) {
                return mov;
            }

            for(int i=0; i<4; ++i) {
                int npy = cy + dy[i]/2;
                int npx = cx + dx[i]/2;
                int ny = cy + dy[i];
                int nx = cx + dx[i];

                if(ny < 0 || ny >= 104 || nx < 0 || nx >= 104) {
                    continue;
                }
                if(!map[npy][npx] || !map[ny][nx] || visited[ny][nx]) {
                    continue;
                }

                visited[ny][nx] = true;
                que.add(new Status(ny, nx, mov+1));
            }
        }

        return -1;
    }

    public void printMap(int y, int x, int cy, int cx, int iy, int ix) {
        for(int i=0; i<50; ++i) {
            for(int j=0; j<50; ++j) {
                if(i == y && j == x) {
                    System.out.print("S");
                } else if(i == cy && j == cx) {
                    System.out.print("C");
                } else if(i == iy && j == ix) {
                    System.out.print("I");
                } else if(map[i][j]) {
                    System.out.print("*");
                } else {
                    System.out.print(".");
                }
            }
            System.out.println();
        }
        System.out.println();
    }

    static class Status {
        int y, x, mov;
        public Status(int y, int x, int mov) {
            this.y = y;
            this.x = x;
            this.mov = mov;
        }
    }
}