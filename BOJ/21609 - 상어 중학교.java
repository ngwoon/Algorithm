import java.io.*;
import java.util.*;

import static java.lang.Integer.parseInt;

/*
    문제 조건에 맞춰 그룹을 지웠을 때, 획득할 수 있는 점수를 구하는 문제.

    <나의 풀이>
    구현 문제이므로, 문제에서 제시한 알고리즘 그대로 구하면 된다.
    한 가지 주의할 점은, 그룹을 구하기 위해 bfs를 사용하고, 여기서 visited 배열을 사용할 때 무지개 블록에 체크된 방문 플래그를 false로 원복해놔야 한다.
    다른 일반 블록에서 bfs를 시작할 때, 이전의 체크했던 무지개 블록을 그룹으로 취급할 수 있기 때문이다.
 */

class SharkMiddleSchool {

    static int BLACK = -1, RAINBOW = 0, EMPTY = -2;
    static int[] dx = {1,0,-1,0};
    static int[] dy = {0,1,0,-1};
    static int n, m;
    static int[][] map;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer stzr = new StringTokenizer(br.readLine());

        n = parseInt(stzr.nextToken());
        m = parseInt(stzr.nextToken());

        map = new int[n][n];
        for(int i=0; i<n; ++i) {
            stzr = new StringTokenizer(br.readLine());
            for(int j=0; j<n; ++j) {
                map[i][j] = parseInt(stzr.nextToken());
            }
        }

        // 오토플레이 시작
        int ans = 0;
        while(true) {
            Group group = findGroup();
            if(group.members.isEmpty()) {
                break;
            }
            
            // 그룹 삭제 및 점수 집계
            ans += Math.pow(group.members.size(), 2);
            for (Pos member : group.members) {
                map[member.y][member.x] = EMPTY;
            }

            // 중력 -> 반시계 회전 -> 중력
            pullDown();
            rotateCounterClock();
            pullDown();
        }

        bw.write(String.valueOf(ans));
        bw.flush();
    }

    public static Group findGroup() {
        Group biggestGroup = new Group(new Pos(-1, -1), 0, new ArrayList<>(0));
        boolean[][] visited = new boolean[n][n];
        for(int y=0; y<n; ++y) {
            for(int x=0; x<n; ++x) {
                if(map[y][x] == BLACK || map[y][x] == RAINBOW || map[y][x] == EMPTY) {
                    continue;
                }

                Group res = bfs(y, x, visited);
                if(res.members.size() < 2) {
                    continue;
                }

                if(res.members.size() > biggestGroup.members.size()) {
                    biggestGroup = res;
                } else if(res.members.size() == biggestGroup.members.size()) {
                    if(biggestGroup.rainbowCount <= res.rainbowCount) {
                        biggestGroup = res;
                    }
                }
            }
        }

        return biggestGroup;
    }

    public static Group bfs(int sy, int sx, boolean[][] visited) {
        Queue<Pos> que = new LinkedList<>();
        List<Pos> members = new ArrayList<>();
        Pos start = new Pos(sy, sx);
        int rainbowCount = 0;
        int stdColor = map[sy][sx];

        visited[sy][sx] = true;
        members.add(start);
        que.add(start);

        while(!que.isEmpty()) {
            Pos cur = que.poll();
            int cy = cur.y;
            int cx = cur.x;

            if(map[cy][cx] == RAINBOW) {
                rainbowCount += 1;
            }

            for(int i=0; i<4; ++i) {
                int ny = cy + dy[i];
                int nx = cx + dx[i];
                if(ny < 0 || ny >= n || nx < 0 || nx >= n) {
                    continue;
                }
                if(visited[ny][nx] || (map[ny][nx] != RAINBOW && map[ny][nx] != stdColor)) { // black, empty도 두 번째 조건에 걸리므로 따로 체크 안함
                    continue;
                }

                Pos next = new Pos(ny, nx);
                members.add(next);
                visited[ny][nx] = true;
                que.add(next);
            }
        }

        // rainbow블록은 다른 일반 블록에서 그룹으로 여길 수도 있으므로, visietd를 false로 다 바꿔준다.
        for (Pos member : members) {
            if(map[member.y][member.x] == RAINBOW) {
                visited[member.y][member.x] = false;
            }
        }

        return new Group(start, rainbowCount, members);
    }

    public static void rotateCounterClock() {
        int[][] afterRotate = new int[n][n];
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                afterRotate[n-1-j][i] = map[i][j];
            }
        }
        map = afterRotate;
    }

    public static void pullDown() {
        for(int j=0; j<n; ++j) {
            for(int i=n-2; i>=0; --i) {
                if(map[i][j] == BLACK || map[i][j] == EMPTY) {
                    continue;
                }

                int ci = i;
                while(ci < n-1 && map[ci + 1][j] == EMPTY) {
                    ci += 1;
                }

                if(ci > i) {
                    map[ci][j] = map[i][j];
                    map[i][j] = EMPTY;
                }
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

    static class Group {
        Pos stdPos;
        int rainbowCount;
        List<Pos> members;
        public Group(Pos stdPos, int rainbowCount, List<Pos> members) {
            this.stdPos = stdPos;
            this.rainbowCount = rainbowCount;
            this.members = members;
        }
    }
}