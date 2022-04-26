import java.io.*;
import java.util.*;

import static java.lang.Integer.parseInt;

/*
    문제 조건에 맞게 학생들의 자리를 배치했을 때, 학생들의 총 만족도를 구하는 문제.

    <나의 풀이>
    구현 문제이다.

    학생들의 자리를 배정할 땐 문제 입력 순서대로 앉히고, 다 앉힌 후에 각 학생들의 만족도를 구해 그 합을 구하면 된다.
 */

class SharkElementarySchool {

    static int[] dx = {1,0,-1,0};
    static int[] dy = {0,1,0,-1};
    static int[] satisfaction = {0,1,10,100,1000};
    static Map<Integer, Set<Integer>> favorites;
    static int n;
    static int[][] room;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer stzr = new StringTokenizer(br.readLine());

        n = parseInt(stzr.nextToken());
        room = new int[n][n];
        favorites = new HashMap<>();

        for(int i=0; i<n*n; ++i) {
            stzr = new StringTokenizer(br.readLine());
            int snum = parseInt(stzr.nextToken());
            Set<Integer> fset = new HashSet<>(4);
            for(int j=0; j<4; ++j) {
                fset.add(parseInt(stzr.nextToken()));
            }

            favorites.put(snum, fset);
            sit(snum);
        }

        bw.write(String.valueOf(getTotalSatisfaction()));
        bw.flush();
    }

    public static void sit(int snum) {

        int maxFavorCount = 0;
        int maxEmptyCount = 0;
        Pos maxFavorPos = new Pos(-1, -1);
        Set<Integer> fset = favorites.get(snum);

        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                if(room[i][j] != 0) {
                    continue;
                }

                int emptyCount = 0;
                int favorCount = 0;

                for(int k=0; k<4; ++k) {
                    int ny = i + dy[k];
                    int nx = j + dx[k];

                    if(ny < 0 || ny >= n || nx < 0 || nx >= n) {
                        continue;
                    }

                    if(room[ny][nx] == 0) {
                        emptyCount += 1;
                    } else {
                        if(fset.contains(room[ny][nx])) {
                            favorCount += 1;
                        }
                    }
                }

                if(maxFavorCount < favorCount) {
                    maxFavorCount = favorCount;
                    maxEmptyCount = emptyCount;
                    maxFavorPos.y = i; maxFavorPos.x = j;
                } else if(maxFavorCount == favorCount) {
                    if(maxEmptyCount < emptyCount) {
                        maxEmptyCount = emptyCount;
                        maxFavorPos.y = i; maxFavorPos.x = j;
                    } else if(maxEmptyCount == emptyCount && maxFavorPos.y == -1) {
                        maxFavorPos.y = i; maxFavorPos.x = j;
                    }
                }
            }
        }

        room[maxFavorPos.y][maxFavorPos.x] = snum;
    }

    public static int getTotalSatisfaction() {

        int totalSatisfaction = 0;
        for(int snum=1; snum<=n*n; ++snum) {
            for(int i=0; i<n; ++i) {
                for(int j=0; j<n; ++j) {
                    if(room[i][j] == snum) {
                        Set<Integer> fset = favorites.get(snum);
                        int favCount = 0;

                        for(int k=0; k<4; ++k) {
                            int ny = i + dy[k];
                            int nx = j + dx[k];
                            if(ny < 0 || ny >= n || nx < 0 || nx >= n) {
                                continue;
                            }
                            if(fset.contains(room[ny][nx])) {
                                favCount += 1;
                            }
                        }

                        totalSatisfaction += satisfaction[favCount];
                    }
                }
            }
        }

        return totalSatisfaction;
    }

    static class Pos {
        int y, x;
        public Pos(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
}