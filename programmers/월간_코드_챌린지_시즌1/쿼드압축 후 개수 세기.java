package 월간_코드_챌린지_시즌1;

import java.util.LinkedList;
import java.util.Queue;

/*
    2차원 배열이 주어질 때, 문제 조건에 맞게 압축한 뒤 0과 1의 개수를 구하는 문제.

    <나의 풀이>
    처음에 주어진 정사각형 범위에서, 압축이 불가능하면 4개로 쪼개서 다시 검사하는 방식으로 풀었다.
    이 과정에서 하나의 정사각형을 왼쪽 상단, 오른쪽 하단 좌표의 쌍으로 표현했고, 검사해야할 정사각형들을 Queue에 넣어서 순차적으로 검사했다.
 */

class QuadCompact {

    public int[] solution(int[][] arr) {
        int n = arr.length;
        Queue<SquarePos> que = new LinkedList<>();

        que.add(new SquarePos(0, 0, n-1, n-1));

        int[] ans = new int[2];
        while(!que.isEmpty()) {
            SquarePos pos = que.poll();
            if(isAbleToCompact(pos, arr)) {
                ans[arr[pos.ly][pos.lx] == 0 ? 0 : 1] += 1;
            } else {
                divSquare(pos.ly, pos.lx, pos.ry, pos.rx, que);
            }
        }

        return ans;
    }

    public boolean isAbleToCompact(SquarePos pos, int[][] arr) {
        int val = arr[pos.ly][pos.lx];
        for(int i=pos.ly; i<=pos.ry; ++i) {
            for(int j=pos.lx; j<=pos.rx; ++j) {
                if(val != arr[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }

    public void divSquare(int ly, int lx, int ry, int rx, Queue<SquarePos> que) {
        int mx = (lx + rx) / 2 + 1;
        int my = (ly + ry) / 2 + 1;

        que.add(new SquarePos(ly, lx, my-1, mx-1));
        que.add(new SquarePos(ly, mx, my-1, rx));
        que.add(new SquarePos(my, lx, ry, mx-1));
        que.add(new SquarePos(my, mx, ry, rx));
    }

    static class SquarePos {
        int ly, lx, ry, rx;
        public SquarePos(int ly, int lx, int ry, int rx) {
            this.ly = ly;
            this.lx = lx;
            this.ry = ry;
            this.rx = rx;
        }
    }
}