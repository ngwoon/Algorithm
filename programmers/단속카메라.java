import java.util.ArrayList;
import java.util.Collections;

/*
    자동차들의 고속도로 진입점과 나간 지점이 주어졌을 때, 모든 자동차가 단속 카메라에 찍힐 수 있게 하는 카메라의 최소 개수를 구하는 문제.

    <나의 풀이>
    풀지 못해서 구글링을 통해 해답을 구했다.

    이 문제의 포인트는 최대한 많은 자동차들이 겹치는 구간에 카메라를 설치하는 것이다.
    따라서 주어진 자동차의 정보를 나간 지점 오름차순으로 정렬하고, 나간 지점을 min 변수에 저장한 뒤 min과 다음 자동차의 진입점을 비교한다.
    만약 진입점이 min보다 작다면, 두 자동차의 공통 부분이 있으므로 카메라 한 대로 충분하다. 즉, 카메라의 개수를 늘리지 않고 다음 자동차로 넘어간다.
    만약 진입점이 min보다 크다면, 두 자동차의 공통 부분이 없으므로 새로운 카메라를 설치해야한다. 즉, 카메라의 개수를 늘리고 min을 현재 자동차의 나간 지점으로 갱신한다.
 */

class SpeedCamera {
    public int solution(int[][] routes) {

        ArrayList<Pos> posList = new ArrayList<Pos>(routes.length);

        for (int[] route : routes) {
            posList.add(new Pos(route[0], route[1]));
        }

        Collections.sort(posList);

        int min = posList.get(0).e;
        int camera = 1;
        for(int i=1; i<posList.size(); ++i) {
            Pos pos = posList.get(i);
            if(min < pos.s) {
                min = pos.e;
                ++camera;
            }
        }

        return camera;
    }

    static class Pos implements Comparable<Pos> {
        int s, e;

        public Pos(int s, int e) {
            this.s = s;
            this.e = e;
        }

        @Override
        public int compareTo(Pos o) {
            return this.e - o.e;
        }
    }
}