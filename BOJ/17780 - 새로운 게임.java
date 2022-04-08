import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

import static java.lang.Integer.parseInt;

/*
    체스판의 상태와 체스말의 위치, 방향이 주어질 때, 게임이 몇 번째 턴에 종료되는지를 구하는 문제.

    <나의 풀이>
    시뮬레이션 문제이므로, 문제에서 제시한 조건을 잘 살펴야 한다.
    일단 이 문제를 풀기 위해 필요한 데이터는 두 가지로 요약해볼 수 있다.
        1. 각 체스말의 현 위치
        2. 체스말들이 겹쳐진 상태
    1번 데이터를 표현하기 위해 Piece 배열을 사용했고, 2번 데이터를 표현하기 위해 List형 2차원 배열을 사용했다.
    List형 2차원 배열은 각 칸에 위치한 체스말들의 번호를 저장한다. 만약 1,1 위치에 체스말 2,3번이 겹쳐있다면, pieceMap[1][1]의 List는 { 2, 3 } 상태일 것이다.

    이 문제를 차근히 풀어가기 위해서 파란 칸으로 이동할 경우, 빨간 칸으로 이동할 경우, 흰 칸으로 이동할 경우를 각각 다른 메서드로 나누었다.
    파란 칸으로 이동할 경우 방향을 바꾼 뒤 다시 한 번 다음 칸의 색을 확인하고 이동하므로, 나눠둔 메서드를 재활용하여 코드 중복을 줄일 수 있다.
 */

class NewGame {

    static final int WHITE = 0, RED = 1, BLUE = 2;
    static final int LEFT = 1, RIGHT = 0, UP = 2, DOWN = 3;
    static int[] dx = {1,-1,0,0};
    static int[] dy = {0,0,-1,1};
    static int n, k;
    static int[][] map;
    static List<Integer>[][] piecesMap;
    static Piece[] pieces;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer stzr = new StringTokenizer(br.readLine());
        n = parseInt(stzr.nextToken());
        k = parseInt(stzr.nextToken());

        map = new int[n][n];
        for(int i=0; i<n; ++i) {
            stzr = new StringTokenizer(br.readLine());
            for(int j=0; j<n; ++j) {
                map[i][j] = parseInt(stzr.nextToken());
            }
        }

        pieces = new Piece[k];
        piecesMap = new ArrayList[n][n];
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                piecesMap[i][j] = new ArrayList<>();
            }
        }
        for(int i=0; i<k; ++i) {
            stzr = new StringTokenizer(br.readLine());
            int py = parseInt(stzr.nextToken()) - 1;
            int px = parseInt(stzr.nextToken()) - 1;
            int pdir = parseInt(stzr.nextToken()) - 1;
            pieces[i] = new Piece(new Pos(py, px), pdir);
            piecesMap[py][px].add(i);
        }

        int turn = 1;
        while(simulate() && turn++ <= 1000);
        if(turn > 1000) {
            bw.write("-1");
        } else {
            bw.write(String.valueOf(turn));
        }
        bw.flush();
    }

    public static boolean simulate() {
        // 0번 말부터 k-1번 말까지 차례로 이동시키기
        for(int i=0; i<k; ++i) {
            Piece piece = pieces[i];
            int py = piece.pos.y;
            int px = piece.pos.x;
            List<Integer> list = piecesMap[py][px];
            // 맨 아래 말이 자신이어야만 움직일 수 있음
            if(list.get(0) == i) {
                int ny = py + dy[piece.dir];
                int nx = px + dx[piece.dir];

                // 다음 위치가 파란색 칸일 경우
                if(ny < 0 || ny >= n || nx < 0 || nx >= n || map[ny][nx] == BLUE) {
                    moveToBlue(i);
                }
                // 다음 위치가 빨간 칸일 경우
                else if(map[ny][nx] == RED) {
                    moveToRed(py, px, ny, nx);
                }
                // 다음 위치가 흰 칸일 경우
                else {
                    moveToWhite(py, px, ny, nx);
                }
            }
        }

        // 네 개 이상 겹쳐진 말이 있는지 확인
        for(int i=0; i<k; ++i) {
            List<Integer> list = piecesMap[pieces[i].pos.y][pieces[i].pos.x];
            if(list.size() >= 4) {
                return false;
            }
        }
        return true;
    }

    public static void moveToBlue(int pieceNum) {
        Piece piece = pieces[pieceNum];
        switch (piece.dir) {
            case LEFT: piece.dir = RIGHT; break;
            case RIGHT: piece.dir = LEFT; break;
            case UP: piece.dir = DOWN; break;
            case DOWN: piece.dir = UP; break;
        }
        int py = piece.pos.y;
        int px = piece.pos.x;
        int ny = py + dy[piece.dir];
        int nx = px + dx[piece.dir];

        // 다음 위치가 파란색 칸일 경우
        if(ny < 0 || ny >= n || nx < 0 || nx >= n || map[ny][nx] == BLUE) {
        }
        // 다음 위치가 빨간 칸일 경우
        else if(map[ny][nx] == RED) {
            moveToRed(py, px, ny, nx);
        }
        // 다음 위치가 흰 칸일 경우
        else {
            moveToWhite(py, px, ny, nx);
        }
    }

    public static void moveToRed(int py, int px, int ny, int nx) {
        Collections.reverse(piecesMap[py][px]);
        moveToWhite(py, px, ny, nx);
    }

    public static void moveToWhite(int py, int px, int ny, int nx) {
        List<Integer> list = piecesMap[py][px];
        for (int pieceNum : list) {
            pieces[pieceNum].pos.y = ny;
            pieces[pieceNum].pos.x = nx;
        }
        piecesMap[ny][nx].addAll(list);
        piecesMap[py][px].clear();
    }

    static class Pos {
        int y, x;
        public Pos(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }

    static class Piece {
        Pos pos;
        int dir;
        public Piece(Pos pos, int dir) {
            this.pos = pos;
            this.dir = dir;
        }
    }
}