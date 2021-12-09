package 카카오_인턴쉽_2020;

import java.util.PriorityQueue;

/*
    경주로를 건설할 수 있는 평면 nxn이 주어질 때,(0,0) 에서 (n-1,n-1) 까지 도달할 수 있게 경주로를 건설하는 경우 중
    가장 비용이 적게드는 경우의 비용을 구하는 문제.

    <나의 풀이>
    처음에 dfs로 풀었다가 시간초과가 나서, A* 알고리즘을 적용했다.
    A* 알고리즘은 다익스트라 알고리즘의 확장판으로, 아래와 같은 로직으로 수행된다.
        * 기본적인 동작 방식은 다익스트라와 유사하다.
        * A* 알고리즘은 우선순위큐를 활용해 다음에 탐색할 노드를 선택한다. 노드 선택 기준은 아래와 같다.
            * 각 노드는 가중치 f(x)를 갖는다.
            * f(x) = g(x) + h(x)이다. 여기서 g(x)는 현재 노드까지의 cost, h(x)는 현재 노드에서 도착점까지의 예상 가중치이다.
            * f(x)값이 낮은 노드가 우선적으로 탐색된다.
        * 현재 노드에서 갈 수 있는 노드는 상,하,좌,우 네 가지이다. 단, 다음 노드의 g(x)를 미리 계산해봤을 때, 이전에 해당 노드를 탐색한 적이 있고
          그 때의 g(x)가 현재 계산한 g(x)보다 작다면, 이미 더 효율적인 길이 있다고 판단하고 우선순위큐에 넣지 않는다.
 */

class BuildingRacingRoad {

    int[] dx = {1,0,-1,0};
    int[] dy = {0,1,0,-1};
    PriorityQueue<Pos> pq;
    int n;
    int[][][] gboard;
    int ans = Integer.MAX_VALUE;

    public int solution(int[][] board) {

        n = board.length;
        gboard = new int[n][n][4];
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                for(int k=0; k<4; ++k) {
                    gboard[i][j][k] = board[i][j] == 1 ? -1 : Integer.MAX_VALUE;
                }
            }
        }

        pq = new PriorityQueue<>();
        pq.add(new Pos(0,0,0, 2*n-2, -1));
        gboard[0][0][0] = 0;
        gboard[0][0][1] = 0;
        gboard[0][0][2] = 0;
        gboard[0][0][3] = 0;

        aStar();

        return ans;
    }

    public void aStar() {

        while(!pq.isEmpty()) {
            Pos pos = pq.poll();
            int cost = pos.cost;
            int prevDir = pos.prevDir;
            int cy = pos.y;
            int cx = pos.x;

            if(cy == n-1 && cx == n-1) {
                ans = Math.min(ans, cost);
                continue;
            }

            for(int i=0; i<4; ++i) {
                int ny = cy + dy[i];
                int nx = cx + dx[i];
                if(ny < 0 || ny >= n || nx < 0 || nx >= n) {
                    continue;
                }
                if(gboard[ny][nx][i] == -1) {
                    continue;
                }

                int ncost;
                if(prevDir == -1 || i == prevDir) {
                    ncost = cost + 100;
                } else {
                    ncost = cost + 600;
                }

                if(gboard[ny][nx][i] < ncost) {
                    continue;
                }

                int nhdst = ((n-1-ny) + (n-1-nx)) * 100;
                gboard[ny][nx][i] = ncost;
                pq.add(new Pos(ny, nx, ncost, nhdst, i));
            }
        }
    }

    static class Pos implements Comparable<Pos> {
        int y, x;
        int hdst;
        int cost;
        int prevDir;
        public Pos(int y, int x, int cost, int hdst, int prevDir) {
            this.y = y;
            this.x = x;
            this.cost = cost;
            this.hdst = hdst;
            this.prevDir = prevDir;
        }

        @Override
        public int compareTo(Pos o) {
            return (this.cost + this.hdst) - (o.cost + o.hdst);
        }
    }
}