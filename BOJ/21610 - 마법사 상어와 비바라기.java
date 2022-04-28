import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

import static java.lang.Integer.parseInt;

/*
    문제 조건에 맞게 비바라기 마법을 부릴 때, 마법이 다 끝난 뒤 모든 바구니에 담겨있는 빗물의 양의 합을 구하는 문제.

    <나의 풀이>
    시뮬레이션 문제이므로, 문제에서 제시한 알고리즘을 얼마나 잘 구현하는가가 관건이다.

    필자는 구름의 위치를 2차원배열이 아닌 List<Pos>로 관리했다. 2차원배열로 관리하게되면, 구름을 옮길 때 구름끼리 겹쳐서 이동시키지 못한 구름이 발생할 수 있기 때문이다.
    아울러 문제에서 3번 과정이 "구름을 지운다" 이지만, 이후 4번과 5번 과정에서 이전 구름의 위치가 필요하므로 지우지 않고 5번 과정을 수행하면서 구름 위치를 갱신했다.
 */

class MagicianSharkAndRain {

    static int[] dx = {-1,-1,0,1,1,1,0,-1};
    static int[] dy = {0,-1,-1,-1,0,1,1,1};
    static int n, m;
    static int[][] map;
    static Magic[] magics;
    static List<Pos> clouds;

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

        magics = new Magic[m];
        for(int i=0; i<m; ++i) {
            stzr = new StringTokenizer(br.readLine());
            magics[i] = new Magic(parseInt(stzr.nextToken())-1, parseInt(stzr.nextToken()));
        }

        doRainyMagic();

        // 정답 구하기
        int ans = 0;
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                ans += map[i][j];
            }
        }
        bw.write(String.valueOf(ans));
        bw.flush();
    }

    public static void doRainyMagic() {
        clouds = new ArrayList<>(n*n);
        clouds.add(new Pos(n-1, 0));
        clouds.add(new Pos(n-1, 1));
        clouds.add(new Pos(n-2, 0));
        clouds.add(new Pos(n-2, 1));

        for (Magic magic : magics) {
            int dir = magic.dir;
            int dist = magic.dist;

            // 모든 구름 이동
            while(dist-- > 0) {
                moveCloud(dir);
            }

            // 구름 아래의 바구니 물 양 증가
            for (Pos cloud : clouds) {
                map[cloud.y][cloud.x] += 1;
            }

            // 구름 사라짐 단계이나, 마지막 단계에서 구름 생성할 때 현재 구름 자리에는 구름을 생성하지 않아야 하므로 일단 clear하지 않음.

            // 물복사버그
            copyWater();

            // 구름 생성하고, 해당 자리 물 양 2 감소
            createCloud();
        }
    }

    public static void moveCloud(int dir) {
        for (Pos cloud : clouds) {
            cloud.x = cloud.x + dx[dir];
            if(cloud.x == -1) {
                cloud.x = n-1;
            } else if(cloud.x == n) {
                cloud.x = 0;
            }

            cloud.y = cloud.y + dy[dir];
            if(cloud.y == -1) {
                cloud.y = n-1;
            } else if(cloud.y == n) {
                cloud.y = 0;
            }
        }
    }

    public static void copyWater() {
        for (Pos cloud : clouds) {
            int y = cloud.y;
            int x = cloud.x;

            int copyCount = 0;
            for(int i=1; i<8; i+=2) {
                int dgy = y + dy[i];
                int dgx = x + dx[i];
                if(dgy < 0 || dgy >= n || dgx < 0 || dgx >= n) {
                    continue;
                }

                copyCount += map[dgy][dgx] > 0 ? 1 : 0;
            }

            map[y][x] += copyCount;
        }
    }

    public static void createCloud() {
        boolean[][] xCloudMap = new boolean[n][n];
        for (Pos cloud : clouds) {
            xCloudMap[cloud.y][cloud.x] = true;
        }

        clouds.clear();
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                if(map[i][j] >= 2 && !xCloudMap[i][j]) {
                    clouds.add(new Pos(i, j));
                    map[i][j] -= 2;
                }
            }
        }
    }

    static class Magic {
        int dir, dist;
        public Magic(int dir, int dist) {
            this.dir = dir;
            this.dist = dist;
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