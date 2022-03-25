import java.io.*;

import static java.lang.Integer.parseInt;

/*
    각 요소에 강도 수치가 있는 2차원 배열 나무가 주어질 때, 문제 조건에 맞게 만든 부메랑들의 최대 강도 합을 구하는 문제.

    <나의 풀이>
    나무의 크기가 최대 5x5 이므로, 완전탐색으로 풀이 가능하다.
    2차원배열을 y=0, x=0부터 y=m-1, x=m-1까지 순차적으로 탐색한다. 탐색하는 배열 요소를 부메랑의 중심으로 잡고, 부메랑 모양 4가지를 모두 탐색한다.
    단, 현재 배열 요소를 중심으로 하는 부메랑을 만들지 않는 경우도 탐색해야 함을 주의하자.
 */

class WeaponEngineering {

    static int n, m;
    static int[][] woods;
    static boolean[][] used;
    static int ans;
    static int[][] dx = {
            {-1, 0},
            {-1, 0},
            {0, 1},
            {0, 1}
    };
    static int[][] dy = {
            {0, 1},
            {0, -1},
            {-1, 0},
            {1, 0}
    };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String varsLine = br.readLine();
        String[] varsStr = varsLine.split(" ");
        n = parseInt(varsStr[0]);
        m = parseInt(varsStr[1]);

        woods = new int[n][m];
        for(int i=0; i<n; ++i) {
            String row = br.readLine();
            String[] numsStr = row.split(" ");
            for(int j=0; j<m; ++j) {
                woods[i][j] = parseInt(numsStr[j]);
            }
        }

        used = new boolean[n][m];
        dfs(0, 0, 0);

        bw.write(String.valueOf(ans));
        bw.flush();
    }

    public static void dfs(int y, int x, int sum) {
        if(y == n) {
            ans = Math.max(ans, sum);
            return;
        }
        if(used[y][x]) {
            if(x == m - 1) {
                dfs(y + 1, 0, sum);
            } else {
                dfs(y, x + 1, sum);
            }
            return;
        }

        used[y][x] = true;

        int[][] usedTemp = new int[2][2];
        for(int i=0; i<4; ++i) {
            int nsum = sum + woods[y][x] * 2;
            boolean isUsable = true;
            for(int j=0; j<2; ++j) {
                int ny = y + dy[i][j];
                int nx = x + dx[i][j];
                if(ny < 0 || ny >= n || nx < 0 || nx >= m || used[ny][nx]) {
                    isUsable = false;
                    break;
                }

                usedTemp[j][0] = ny;
                usedTemp[j][1] = nx;
                nsum += woods[ny][nx];
            }
            if(isUsable) {
                for(int j=0; j<2; ++j) {
                    used[usedTemp[j][0]][usedTemp[j][1]] = true;
                }

                if(x == m - 1) {
                    dfs(y + 1, 0, nsum);
                } else {
                    dfs(y, x + 1, nsum);
                }

                for(int j=0; j<2; ++j) {
                    used[usedTemp[j][0]][usedTemp[j][1]] = false;
                }
            }
        }

        used[y][x] = false;
        if(x == m - 1) {
            dfs(y + 1, 0, sum);
        } else {
            dfs(y, x + 1, sum);
        }
    }
}