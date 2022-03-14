package 월간_코드_챌린지_시즌1;

import java.util.LinkedList;
import java.util.List;

/*
    문제 조건에 따라 1차원 배열에 수를 채우는 문제.

    <나의 풀이>
    문제 조건에 따라 수를 채울 2차원 배열과, 수를 채워갈 세 가지 방향을 먼저 선언한다. (dx, dy 배열)
    2차원 배열의 크기를 벗어나지 않게 y와 x를 이동시키면서, 끝지점에 닿았을 땐 방향을 바꾸어 수를 채워간다.
 */

class TriangleSnail {

    int[] dx = {0,1,-1};
    int[] dy = {1,0,-1};

    public int[] solution(int n) {
        int[][] triangle = new int[n][n];
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                triangle[i][j] = 0;
            }
        }

        int mov = n;
        int dir = 0;
        int y = 0, x = 0;
        int num = 1;
        while(mov > 0) {
            for(int i=0; i<mov; ++i) {
                triangle[y][x] = num++;
                if(i == mov - 1) {
                    dir = (dir + 1) % 3;
                }
                y += dy[dir];
                x += dx[dir];
            }
            --mov;
        }

        List<Integer> ansList = new LinkedList<>();
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                if(triangle[i][j] != 0) {
                    ansList.add(triangle[i][j]);
                } else {
                    break;
                }
            }
        }

        int[] ans = new int[ansList.size()];
        int aIdx = 0;
        for (int a : ansList) {
            ans[aIdx++] = a;
        }

        return ans;
    }
}