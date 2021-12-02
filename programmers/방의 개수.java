import java.util.*;

/*
    좌표의 이동 방향들이 주어지고, 이 방향들에 따라 움직였을 때 만들어지는 선이 만드는 방의 개수를 구하는 문제.

    <나의 풀이>
    이 문제의 핵심은 방이 만들어지는 상황이 무엇인지를 알아야 한다. 나는 아래와 같은 조건을 만족하면 하나의 방이 만들어진다고 생각했다.
        * 화살표 움직임으로 인해 임의의 좌표 cy, cx로 이동했을 때, 이 좌표에 이 방위에서 처음으로 진입해야 한다. (이전에 이 방위에서 이 좌표로 이동한 경력이 있으면 안된다.)
        * 현재 움직임으로 인해 생성된 선을 포함해서, 이동한 좌표는 2개 이상의 선과 연결되어 있어야 한다.
    위 조건을 만족하면 방의 개수 (변수 ans) 를 하나 증가시켰다.

    단, 여기서 주의해야할 점이 있는데, 대각선으로 선이 교차된 경우 좌표 진입 방위로 판단할 수가 없기 때문에 다른 방법이 필요했다.
    이를 위해 기본 이동 거리를 2로 잡아서, 대각선이 서로 교차할 시에도 그 교차점이 좌표 위가 될 수 있도록 했다.
    이렇게 하면 대각선이 교차할 경우에도 좌표의 진입 방위를 통해 해당 교차점에 연결된 선의 개수를 파악할 수 있다.
 */

class RoomCount {

    int[] dx = { 0, 1, 1, 1, 0, -1, -1, -1 };
    int[] dy = { -1, -1, 0, 1, 1, 1, 0, -1 };

    public int solution(int[] arrows) {

        HashMap<String, HashSet<Integer>> visited = new HashMap<>();
        int cx = 0, cy = 0;
        visited.put(posToString(cy, cx), new HashSet<>());

        int ans = 0;
        for (int arrow : arrows) {

            HashSet<Integer> curDirs = visited.get(posToString(cy, cx));
            curDirs.add(arrow);

            int j=2;
            while(j-- > 0) {
                cx += dx[arrow]; cy += dy[arrow];
                HashSet<Integer> nextDirs = visited.get(posToString(cy, cx));
                if(nextDirs == null) {
                    HashSet<Integer> ns = new HashSet<>();
                    visited.put(posToString(cy, cx), ns);
                    nextDirs = ns;
                }

                int nextArrow = arrow > 3 ? arrow - 4 : arrow + 4;
                if(!nextDirs.contains(nextArrow)) {
                    nextDirs.add(nextArrow);
                    if(nextDirs.size() >= 2) {
                        ++ans;
                    }
                }
            }
        }

        return ans;
    }

    public String posToString(int y, int x) {
        return y + " " + x;
    }
}