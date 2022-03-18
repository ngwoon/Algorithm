import java.io.*;

import static java.lang.Integer.parseInt;

/*
    폭탄 위치와 제한 시간이 주어질 때, 제한 시간 이후 폭탄의 상태를 구하는 문제.

    <나의 풀이>
    단순 구현 문제이다.
    한 턴에 놓여진 폭탄은 그 턴 3초 이후에 터지므로, 폭턴 설치 시 폭탄에 위치에 숫자 3을 넣어둔다.
    이후 턴이 흐를때마다, 폭탄의 수를 1 감소시키고, 0이 된 폭탄 영역을 폭파시키는 방법으로 풀었다.
 */

class Boomberman {

    static int[] dx = {1,0,-1,0};
    static int[] dy = {0,1,0,-1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String varsLine = br.readLine();
        String[] varsStr = varsLine.split(" ");
        int r = parseInt(varsStr[0]);
        int c = parseInt(varsStr[1]);
        int n = parseInt(varsStr[2]);

        int[][] map = new int[r][c];
        for(int i=0; i<r; ++i) {
            String row = br.readLine();
            for(int j=0; j<c; ++j) {
                map[i][j] = row.charAt(j) == 'O' ? 2 : -1;
            }
        }

        boolean[][] isBoom = new boolean[r][c];
        n -= 1;
        while(n-- > 0) {
            // 폭탄 설치
            for(int i=0; i<r; ++i) {
                for(int j=0; j<c; ++j) {
                    if(map[i][j] == -1) {
                        map[i][j] = 3;
                    } else {
                        map[i][j] -= 1;
                    }
                }
            }

            // 폭탄 터질 곳 체크
            for(int i=0; i<r; ++i) {
                for(int j=0; j<c; ++j) {
                    if(map[i][j] == 0) {
                        isBoom[i][j] = true;
                        for(int k=0; k<4; ++k) {
                            int ny = i + dy[k];
                            int nx = j + dx[k];
                            if(ny < 0 || ny >= r || nx < 0 || nx >= c) {
                                continue;
                            }
                            isBoom[ny][nx] = true;
                        }
                    }
                }
            }

            // 폭탄 터짐
            for(int i=0; i<r; ++i) {
                for(int j=0; j<c; ++j) {
                    if(isBoom[i][j]) {
                        map[i][j] = -1;
                    }
                    isBoom[i][j] = false; // 초기화
                }
            }
        }

        for(int i=0; i<r; ++i) {
            for(int j=0; j<c; ++j) {
                if(map[i][j] == -1) {
                    bw.write(".");
                } else {
                    bw.write("O");
                }
            }
            if(i < r - 1) {
                bw.write("\n");
            }
        }
        bw.flush();
    }
}