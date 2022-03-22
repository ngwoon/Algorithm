import java.io.*;
import java.util.ArrayList;
import java.util.List;

/*
    선생님들의 위치와 학생들의 위치가 정사각형 격자 맵 위에 주어질 때, 장애물을 3개 설치하여 선생님의 감시를 피할 수 있는지 구하는 문제.

    <나의 풀이>
    n의 크기가 작으므로, 설치할 장애물 위치 세 곳을 완전탐색으로 선택해도 무방하다.
 */

class AvoidTeacher {

    static int[] dx = {1,0,-1,0};
    static int[] dy = {0,1,0,-1};
    static int n;
    static char[][] halls;
    static List<Pos> teachers;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        n = Integer.parseInt(br.readLine());

        halls = new char[n][n];
        int hIdx = 0;
        for(int i=0; i<n; ++i) {
            String line = br.readLine();
            String replaced = line.replaceAll(" ", "");
            halls[hIdx++] = replaced.toCharArray();
        }

        // 선생님 위치 기억
        teachers = new ArrayList<>(5);
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                if(halls[i][j] == 'T') {
                    teachers.add(new Pos(i, j));
                }
            }
        }

        String ans = "NO";
        // 장애물 설치할 세 위치 선택
        loop:
        for(int i=0; i<n*n-2; ++i) {
            int iy = i/n, ix = i%n;
            if(halls[iy][ix] != 'X') {
                continue;
            }
            halls[iy][ix] = 'O';

            for(int j=i+1; j<n*n-1; ++j) {
                int jy = j/n, jx = j%n;
                if(halls[jy][jx] != 'X') {
                    continue;
                }
                halls[jy][jx] = 'O';

                for(int k=j+1; k<n*n; ++k) {
                    int ky = k/n, kx = k%n;
                    if(halls[ky][kx] != 'X') {
                        continue;
                    }
                    halls[ky][kx] = 'O';

                    if(isSafe()) {
                        ans = "YES";
                        break loop;
                    }

                    halls[ky][kx] = 'X';
                }

                halls[jy][jx] = 'X';
            }

            halls[iy][ix] = 'X';
        }

        bw.write(ans);
        bw.flush();
    }

    public static boolean isSafe() {
        for (Pos teacher : teachers) {
            int ty = teacher.y;
            int tx = teacher.x;
            for(int i=0; i<4; ++i) {
                int sy = ty, sx = tx;
                while(true) {
                    int ny = sy + dy[i];
                    int nx = sx + dx[i];
                    if(ny < 0 || ny >= n || nx < 0 || nx >= n) {
                        break;
                    }
                    if(halls[ny][nx] == 'O') {
                        break;
                    } else if(halls[ny][nx] == 'S') {
                        return false;
                    }

                    sy = ny; sx = nx;
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