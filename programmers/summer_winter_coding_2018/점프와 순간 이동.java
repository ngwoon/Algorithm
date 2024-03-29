package summer_winter_coding_2018;

/*
    도달해야할 위치 n이 주어질 때, 0부터 n까지 이동하는 경우의 수 중 배터리를 최소한으로 사용하는 경우의 배터리 소모량을 구하는 문제.

    <나의 풀이>
    배터리를 최소한으로 소모하려면, 점프가 가능한 곳에서는 반드시 점프를 해야한다.
    점프는 현재 좌표 * 2로 이동하므로, 점프 후의 좌표는 반드시 짝수이다.
    따라서 도착지점 n에서부터 거꾸로 시작해서, 현재 좌표가 짝수면 점프로 도달한 좌표임을 짐작할 수 있고, 홀수라면 전진을 통해 도달했다고 짐작할 수 있다.
    즉, 현재 좌표가 짝수이면 n /= 2 를 하고, 홀수이면 n -= 1을 한다. 아울러 홀수이면 전진을 해서 도달했다는 뜻이므로 ans += 1 또한 수행해준다.
 */

class JumpAndTeleporation {

    public int solution(int n) {
        int ans = 0;
        while(n > 0) {
            if(n % 2 == 1) {
                ans++;
                n -=1;
            }
            while(n > 0 && n % 2 == 0) {
                n /= 2;
            }
        }

        return ans;
    }
}