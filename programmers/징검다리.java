import java.util.*;

/*
    시작점과 도착점, 그 사이의 바위들의 위치와 제거할 바위의 개수가 주어졌을 때, 각 지점의 간격의 최솟값의 최대값을 구하는 문제.

    <나의 풀이>
    풀지 못해서 다른 이의 풀이를 참고했다.

    이 문제에서 이분 탐색을 사용할 때, "간격의 최솟값" 을 이분탐색의 기준으로 삼아야 했다.
    mid를 정하면, 이 mid보다 모든 간격이 넓어지도록 바위를 제거한다.
    이렇게 제거한 바위의 개수가 n개 초과이면 간격 최솟값이 이보다 작아야 함을 의미한다. 즉, high를 줄여서 다시 시도한다.
    제거한 바위의 개수가 n개 이하이면, 간격이 더 넓어질 수 있으므로 low를 올려서 다시 시도한다.
 */

class SteppingStone {
    public static int solution(int distance, int[] rocks, int n) {

        Arrays.sort(rocks);

        int low = 1;
        int high = distance;
        int ans = 0;
        while (low <= high) {
            int mid = (low + high) / 2;

            int removeCount = 0;
            int before = 0;
            for (int i = 0; i < rocks.length; ++i) {
                int gap = rocks[i] - before;
                if (gap < mid) {
                    ++removeCount;
                } else {
                    before = rocks[i];
                }
            }

            if (removeCount > n) {
                high = mid - 1;
            } else {
                ans = mid;
                low = mid + 1;
            }
        }

        return ans;
    }
}