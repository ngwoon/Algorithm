import java.io.*;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;

import static java.lang.Integer.parseInt;

/*
    미친 아두이노의 위치와 종수의 위치가 주어지고, 종수의 이동 명령이 주어질 때, 게임 결과를 구하는 문제.

    <나의 풀이>
    구현 문제로써, 문제에서 제시한 게임 순서를 얼마나 잘 구현하는지를 보는 문제이다.
    종수가 미친 아두이노의 좌표로 이동하거나, 미친 아두이노가 종수의 위치로 이동하면 그대로 게임이 종료되며, 지금까지 종수가 이동한 횟수를 출력한다.

    주의할 점은, 종수가 아두이노의 좌표로 이동한 횟수도 어쨌든 종수가 이동한 횟수로 여겨야 된다.
    아울러 미친 아두이노가 같은 좌표에 2개 이상 위치하면 폭파해야하는데, 폭파하기 전에 종수와 같은 위치인지를 먼저 확인해야 한다.
    마지막으로 미친 아두이노의 위치를 따로 관리하지 않고 map을 순차적으로 탐색하면서 미친 아두이노의 위치를 찾아서 이동시킨다면, 이미 이동한 미친 아두이노를 중복해서
    이동시키는 잘못된 로직이 발생할 수 있다.
 */

class CrazyArduino {

    static int r, c;
    static int[] dx = {-1,0,1,-1,0,1,-1,0,1};
    static int[] dy = {1,1,1,0,0,0,-1,-1,-1};
    static int[][] map;
    static List<Pos> robots;
    static String moves;
    static int jy, jx;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String varsLine = br.readLine();
        String[] varsStr = varsLine.split(" ");
        r = parseInt(varsStr[0]);
        c = parseInt(varsStr[1]);

        robots = new LinkedList<>();
        map = new int[r][c];
        for(int i=0; i<r; ++i) {
            char[] row = br.readLine().toCharArray();
            for(int j=0; j<c; ++j) {
                if(row[j] == 'I') {
                    map[i][j] = -1;
                    jy = i; jx = j;
                } else if(row[j] == 'R') {
                    map[i][j] = 1;
                    robots.add(new Pos(i, j));
                } else {
                    map[i][j] = 0;
                }
            }
        }

        moves = br.readLine();
        int movCount = simulate();
        if(movCount == moves.length()) {
            for(int i=0; i<r; ++i) {
                for(int j=0; j<c; ++j) {
                    if(map[i][j] == -1) {
                        bw.write('I');
                    } else if(map[i][j] == 1) {
                        bw.write('R');
                    } else {
                        bw.write(".");
                    }
                }
                bw.write("\n");
            }
        } else {
            bw.write("kraj " + movCount);
        }
        bw.flush();
    }

    public static int simulate() {
        int movCount = 0;
        for (int i = 0; i < moves.length(); ++i) {
            int order = (moves.charAt(i) - '0') - 1;

            // 종수 움직임
            int ny = jy + dy[order];
            int nx = jx + dx[order];
            ++movCount;

            if (map[ny][nx] > 0) { // 로봇이 있는 곳으로 움직였으면, 게임 종료
                break;
            }
            map[jy][jx] = 0;
            map[ny][nx] = -1;
            jy = ny;
            jx = nx;

            // 로봇들 움직임
            for (Pos robot : robots) {
                int ry = robot.y;
                int rx = robot.x;
                int closestDst = Integer.MAX_VALUE;
                int cry = ry, crx = rx;
                
                // 종수와 가장 가까워지는 좌표 탐색
                for (int m = 0; m < 9; ++m) {
                    int nry = ry + dy[m];
                    int nrx = rx + dx[m];
                    if (nry < 0 || nry >= r || nrx < 0 || nrx >= c) {
                        continue;
                    }

                    int dst = calcDst(jy, jx, nry, nrx);
                    if(dst < closestDst) {
                        closestDst = dst;
                        cry = nry; crx = nrx;
                    }
                }

                // 종수가 있는 곳으로 움직였다면, 게임 종료
                if(cry == jy && crx == jx) {
                    return movCount;
                }

                map[ry][rx] -= 1;
                map[cry][crx] += 1;
                robot.y = cry;
                robot.x = crx;
            }

            // 로봇들 움직인 후, 두 개 이상 겹쳐있는 로봇들 폭파
            for(int j=0; j<r; ++j) {
                for(int k=0; k<c; ++k) {
                    if(map[j][k] > 1) {
                        map[j][k] = 0;
                        Iterator<Pos> iter = robots.iterator();
                        while (iter.hasNext()) {
                            Pos robot = iter.next();
                            if(robot.y == j && robot.x == k) {
                                iter.remove();
                            }
                        }
                    }
                }
            }
        }

        return movCount;
    }

    public static int calcDst(int ay, int ax, int by, int bx) {
        return Math.abs(ay - by) + Math.abs(ax - bx);
    }

    static class Pos {
        int y, x;
        public Pos(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
}