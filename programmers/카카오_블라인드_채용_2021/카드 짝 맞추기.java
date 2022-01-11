package 카카오_블라인드_채용_2021;

import java.util.*;

/*
    카드의 위치가 주어질 때, 모든 카드의 짝을 맞추는 가장 적은 커맨드 수를 구하는 문제.

    <나의 풀이>
    카드 종류가 최대 8개이고, 게임 보드도 4x4 크기이므로 완전 탐색으로 풀어도 괜찮은 문제이다.
    현재 보드에 등장하는 카드 종류들을 순서대로 선택하는 모든 경우의 수를 구하고, 각 경우의 수마다 그 순서에 맞게 카드를 뒤집어가며
    몇 개의 커맨드가 필요한지를 계산한다. 그렇게 구한 커맨드 개수 중 가장 적은 수가 정답이다.

    한 가지 문제점이 있다. 다음으로 뒤집을 카드 종류를 선택할 때, 두 개의 카드 중 현재 위치에서 가까운 카드를 먼저 뒤집는 방식을 사용했는데,
    만약 그 두 가지 거리가 같다면 두 가지 경우 모두 구해보아야 정확한 정답을 얻을 수 있다.
    현재 내 풀이는 이 점을 고려하지 않고 있다. 그래도 문제는 풀리지만, 완전한 풀이라고 볼 수는 없다.
 */

class CouplingCardPair {

    int[] dy = {-1,0,1,0};
    int[] dx = {0,1,0,-1};

    Map<Integer, List<Pos>> cardPositions;
    List<Integer> cards;
    boolean[] selected;
    int[][] gboard;
    int sy, sx, ans = Integer.MAX_VALUE;

    public int solution(int[][] board, int r, int c) {

        sy = r; sx = c;
        gboard = board;
        Set<Integer> set = new HashSet<>();
        cardPositions = new HashMap<>();
        for(int i=0; i<4; ++i) {
            for(int j=0; j<4; ++j) {
                if(board[i][j] > 0) {
                    set.add(board[i][j]);
                    if(board[i][j] > 0) {
                        if(!cardPositions.containsKey(board[i][j])) {
                            cardPositions.put(board[i][j], new ArrayList<>(2));
                        }
                        List<Pos> pos = cardPositions.get(board[i][j]);
                        pos.add(new Pos(i, j));
                    }
                }
            }
        }

        cards = new ArrayList<>(set);
        selected = new boolean[cards.size()];
        dfs(new ArrayList<>());

        return ans + cards.size() * 2;
    }

    public void dfs(List<Integer> order) {
        if(order.size() == cards.size()) {
            int move = play(order);
            ans = Math.min(ans, move);
            return;
        }

        for(int i=0; i<cards.size(); ++i) {
            if(!selected[i]) {
                selected[i] = true;
                order.add(cards.get(i));
                dfs(order);
                order.remove(order.size() - 1);
                selected[i] = false;
            }
        }
    }

    public int play(List<Integer> order) {
        int cy = sy, cx = sx;
        int[][] board = copyBoard();
        int totalDst = 0;
        for (int card : order) {
            List<Pos> pos = cardPositions.get(card);
            Pos targetPosA = pos.get(0);
            Pos targetPosB = pos.get(1);
            int dstA = getDist(cy, cx, targetPosA.y, targetPosA.x, board);
            int dstB = getDist(cy, cx, targetPosB.y, targetPosB.x, board);

            Pos firstPos, secondPos;
            int firstPosDst;
            if(dstA < dstB) {
                firstPos = targetPosA; secondPos = targetPosB;
                firstPosDst = dstA;
            } else {
                firstPos = targetPosB; secondPos = targetPosA;
                firstPosDst = dstB;
            }

            totalDst += firstPosDst;
            board[firstPos.y][firstPos.x] = 0;

            int secondPosDst = getDist(firstPos.y, firstPos.x, secondPos.y, secondPos.x, board);
            totalDst += secondPosDst;
            board[secondPos.y][secondPos.x] = 0;

            cy = secondPos.y;
            cx = secondPos.x;
        }
        return totalDst;
    }

    public int getDist(int sy, int sx, int ey, int ex, int[][] board) {

        Queue<PosAndDist> que = new LinkedList<>();
        int[][] dst = new int[4][4];
        for(int i=0; i<4; ++i) {
            for(int j=0; j<4; ++j) {
                dst[i][j] = 100;
            }
        }
        que.add(new PosAndDist(sy, sx, 0));
        dst[sy][sx] = 0;
        while(!que.isEmpty()) {
            PosAndDist cur = que.poll();
            int cy = cur.y;
            int cx = cur.x;
            int curDst = cur.dst;

            if(cy == ey && cx == ex) {
                continue;
            }

            for(int i=0; i<8; ++i) {
                int ny = cy, nx = cx;
                int nDst = curDst + 1;
                int dir = i % 4;
                ny += dy[dir];
                nx += dx[dir];
                if(ny < 0 || ny >= 4 || nx < 0 || nx >= 4) {
                    continue;
                }
                if(i < 4) {
                    if(i == 0) {
                        while(ny > 0 && board[ny][nx] == 0) {
                            ny += dy[i];
                        }
                    } else if(i == 1) {
                        while(nx < 3 && board[ny][nx] == 0) {
                            nx += dx[i];
                        }
                    } else if(i == 2) {
                        while(ny < 3 && board[ny][nx] == 0) {
                            ny += dy[i];
                        }
                    } else {
                        while(nx > 0 && board[ny][nx] == 0) {
                            nx += dx[i];
                        }
                    }
                }

                if(dst[ny][nx] <= nDst) {
                    continue;
                }
                dst[ny][nx] = nDst;
                que.add(new PosAndDist(ny, nx, nDst));
            }
        }
        return dst[ey][ex];
    }

    public int[][] copyBoard() {
        int[][] copy = new int[4][4];
        for(int i=0; i<4; ++i) {
            System.arraycopy(gboard[i], 0, copy[i], 0, 4);
        }
        return copy;
    }

    static class Pos {
        int y, x;
        public Pos(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }

    static class PosAndDist {
        int y, x;
        int dst;
        public PosAndDist(int y, int x, int dst) {
            this.y = y;
            this.x = x;
            this.dst = dst;
        }
    }
}