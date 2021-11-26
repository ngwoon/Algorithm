import java.util.Arrays;

/*
    심사관이 심사하는 시간과 입국객의 수가 주어졌을 때, 모든 입국객이 심사를 받는 가장 짧은 시간을 구하는 문제.

    <나의 풀이>
    심사하는데 걸리는 시간을 mid로 하는 이분 탐색 문제이다.
    가장 오래 걸리는 심사 시간은 심사 시간이 가장 짧은 심사관이 모든 입국객을 심사하는 경우이므로,
    low를 0, high를 times[0] * n으로 잡고 이분탐색을 수행하는 방법으로 풀었다.
 */

class Immigration {
    public long solution(int n, int[] times) {

        Arrays.sort(times);
        long ans = 0;
        long low = 0;
        long high = (long) times[0] * n;
        while(low <= high) {
            long mid = (low + high) / 2;

            long judges = 0;
            for (int time : times) {
                judges += mid / time;
            }

            if(judges >= n) {
                ans = mid;
                high = mid - 1;
            } else if(judges < n) {
                low = mid + 1;
            }
        }

        return ans;
    }
}