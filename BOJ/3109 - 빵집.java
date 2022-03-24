import java.io.*;

import static java.lang.Integer.parseInt;

/*
    다른 빵집들과 나의 빵집 사이 건물들의 위치가 주어질 때, 문제 조건에 맞게 연결할 수 있는 파이프라인의 최대 개수를 구하는 문제.

    <나의 풀이>
    이 문제의 핵심은, 파이프의 방향이 오른쪽, 오른쪽 위 대각선, 오른쪽 아래 대각선 이렇게 세 가지 방향만 가능하다는 점이다.
    i번째 상대 빵집에서 파이프를 연결해서, i+1번째 행에 도착한 상황을 상상해보자.
    이 때 i+1번째 상대 빵집에서 파이프를 연결해서 i+1 이하의 행에 도착할 수 있을까?
    도착할 수 없다. 이 특징을 이해했다면, 최대로 파이프를 많이 연결하기 위해선 i번째 상대 빵집은 최대한 i이하 행으로 도착해야 한다.
    즉, 파이프 연결 시도할 때 오른쪽 위 대각선, 오른쪽, 오른쪽 아래 대각선 순으로 연결을 시도해봐야 한다는 뜻이다.

    탐색은 dfs로 하면 된다. 단, 한가지 주의할 점이 있다.
    열의 크기가 최대 500이고, 각 블럭마다 시도해봐야 할 파이프의 개수가 3개이므로 최악의 경우 3^500번 시도하게 된다.
    즉, 일반적인 dfs (방문(시도) 해보고, 아니면 방문 취소) 로 풀면 TLE가 발생한다. 여기서 한 가지 아이디어가 필요하다.

    이전에 임의의 경로를 거쳐서 A블럭에 도달했고, dfs로 이어서 탐색을 시도했지만 마지막 열에 도달하지 못했다고 가정하자.
    이후 다른 경로를 거쳐서 A블럭에 다시 도달했을때, 이 블럭에서 다시 dfs를 해야할까? 그렇지 않다.
    이 아이디어를 접목해서, dfs를 시도한 뒤 정답이 아니더라도 visited 배열의 값을 false로 바꾸지 않는다면 TLE를 피할 수 있다.
 */

class Bakery {

    static int r, c;
    static char[][] map;
    static int ans;
    static boolean[][] visited;
    static int[] dx = {1, 1, 1};
    static int[] dy = {-1, 0, 1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String varsLine = br.readLine();
        String[] varsStr = varsLine.split(" ");
        r = parseInt(varsStr[0]);
        c = parseInt(varsStr[1]);

        map = new char[r][c];
        for(int i=0; i<r; ++i) {
            map[i] = br.readLine().toCharArray();
        }

        ans = 0;
        visited = new boolean[r][c];
        for(int i=0; i<r; ++i) {
            dfs(i, 0);
        }

        bw.write(String.valueOf(ans));
        bw.flush();
    }

    public static boolean dfs(int y, int x) {
        visited[y][x] = true;
        if(x == c-1) {
            ans += 1;
            return true;
        }

        for(int i=0; i<3; ++i) {
            int ny = y  + dy[i];
            int nx = x  + dx[i];
            if(ny < 0 || ny >= r || nx >= c) {
                continue;
            }
            if(map[ny][nx] == 'x' || visited[ny][nx]) {
                continue;
            }
            if(dfs(ny, nx)) {
                return true;
            }
        }

        return false;
    }
}