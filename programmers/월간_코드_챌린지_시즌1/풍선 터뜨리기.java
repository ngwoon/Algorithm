package 월간_코드_챌린지_시즌1;

import java.util.*;

/*
    풍선을 주어진 규칙에 따라 터뜨릴 때, 마지막까지 유지될 수 있는 풍선의 개수를 구하는 문제.

    <나의 풀이>
    greedy 알고리즘으로 풀 수 있는 문제이다.
    k번째 풍선의 유지 가능 여부를 판단할 때, 이 풍선을 기준으로 좌, 우로 나눠야 한다.
    왼쪽에 있는 풍선들 중 가장 작은 값을 m이라 하고, 오른쪽에 있는 풍선들 중 가장 작은 값을 z이라고 하며, k번째 풍선의 값을 s라고 할 때,
    m, z, s 중 s가 가장 크지만 않으면 k번째 풍선은 마지막까지 유지될 수 있다.
 */

class PoppingBalloon {

    public int solution(int[] a) {
        int lmin = 100000001;
        int rmin = 100000001;
        List<Integer> minList = new ArrayList<>(a.length);
        List<Boolean> used = new ArrayList<>(a.length);
        for(int i=0; i<a.length; ++i) {
            rmin = Math.min(rmin, a[i]);
            minList.add(a[i]);
            used.add(false);
        }

        Collections.sort(minList);

        int ans = 0;
        int rIdx = 0;
        for(int i=0; i<a.length; ++i) {
            int num = a[i];

            if(lmin >= num || rmin >= num) {
                ++ans;
            }

            int usedIdx = Collections.binarySearch(minList, num);
            used.set(usedIdx, true);

            while(rIdx + 1 < minList.size() && used.get(rIdx)) {
                ++rIdx;
            }
            rmin = minList.get(rIdx);

            lmin = Math.min(lmin, num);
        }

        return ans;
    }
}