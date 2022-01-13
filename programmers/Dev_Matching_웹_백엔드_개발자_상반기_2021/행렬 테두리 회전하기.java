package Dev_Matching_웹_백엔드_개발자_상반기_2021;

/*
    행과 열, 회전할 직사각형의 왼쪽 상단, 오른쪽 하단 꼭짓점 좌표들이 주어질 때, 회전된 수들 중 가장 작은 수를 구하는 문제.

    <나의 풀이>
    단순한 시뮬레이션 문제이다. 2차원 배열의 회전만 신경써서 구현하면 어렵지 않게 풀 수 있다.
 */

class RotateMatrix {

    int[] dx = {1,0,-1,0};
    int[] dy = {0,1,0,-1};
    int[][] board;

    public int[] solution(int rows, int columns, int[][] queries) {
        board = new int[rows][columns];
        for(int i=0; i<rows; ++i) {
            for(int j=0; j<columns; ++j) {
                board[i][j] = (i*columns) + j + 1;
            }
        }

        int[] ans = new int[queries.length];
        int idx = 0;
        for (int[] query : queries) {
            ans[idx++] = rotate(query[0] - 1, query[1] - 1, query[2] - 1, query[3] - 1);
        }

        return ans;
    }

    public int rotate(int ly, int lx, int ry, int rx) {

        int cy = ly, cx = lx;
        int dir = 0;
        int cur = board[cy][cx];
        int minVal = cur;
        int next;
        while(true) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];
            if(ny < ly || ny > ry || nx < lx || nx > rx) {
                dir += 1;
                if(dir > 3) {
                    break;
                } else {
                    continue;
                }
            }

            next = board[ny][nx];
            board[ny][nx] = cur;
            cur = next;

            minVal = Math.min(cur, minVal);
            cy = ny; cx = nx;
        }

        return minVal;
    }
}