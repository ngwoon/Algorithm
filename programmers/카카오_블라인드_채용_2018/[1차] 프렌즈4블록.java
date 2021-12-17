package 카카오_블라인드_채용_2018;

import java.util.HashSet;

/*
    캐릭터들이 쌓여있는 맵이 주어졌을 때, 조건대로 블록을 터뜨렸을 때 터지는 블록의 개수를 구하는 문제.

    <나의 풀이>
    별다른 알고리즘이 필요한 문제는 아니다. 단순 시뮬레이션 문제이다.
    나는 맵의 모든 2x2구역을 탐색하면서, 해당 구역에 같은 캐릭터만 존재한다면 그 좌표 4개를 hashSet에 저장해두고, 맵 탐색이 끝나면 터뜨렸다.
    캐릭터의 중첩을 허용하기 때문에, 탐색 즉시 터뜨리면 원래 터져야 할 구역이 터지지 않을 수 있음에 유의한다.
 */

class Friends4Block {

    char[][] map;
    int ans = 0;
    HashSet<String> hs;

    public int solution(int m, int n, String[] board) {

        map = new char[m][n];
        for(int i=0; i<m; ++i) {
            map[i] = board[i].toCharArray();
        }

        hs = new HashSet<>();
        solve(m, n);

        return ans;
    }

    public void solve(int m, int n) {

        while(true) {

            boolean isBoom = false;
            for(int i=0; i<m-1; ++i) {
                for(int j=0; j<n-1; ++j) {
                    char cur = map[i][j];
                    if(cur != 'X') {
                        if(cur == map[i+1][j] && cur == map[i][j+1] && cur == map[i+1][j+1]) {
                            hs.add(i + " " + j);
                            hs.add((i+1) + " " + j);
                            hs.add(i + " " + (j+1));
                            hs.add((i+1) + " " + (j+1));
                            isBoom = true;
                        }
                    }
                }
            }

            if(!isBoom) {
                break;
            }

            boom();
            drop(m, n);
            ans += hs.size();
            hs.clear();
        }
    }

    public void boom() {

        for (String pos : hs) {
            String[] yx = pos.split(" ");
            int y = Integer.parseInt(yx[0]);
            int x = Integer.parseInt(yx[1]);
            map[y][x] = 'X';
        }
    }

    public void drop(int m, int n) {

        for(int j=0; j<n; ++j) {
            int bottom = -1;
            for(int i=m-1; i>=0; --i) {
                if(bottom == -1) {
                    if(map[i][j] == 'X') {
                        bottom = i;
                    }
                } else {
                    if(map[i][j] != 'X') {
                        map[bottom][j] = map[i][j];
                        map[i][j] = 'X';
                        --bottom;
                    }
                }
            }
        }
    }
}