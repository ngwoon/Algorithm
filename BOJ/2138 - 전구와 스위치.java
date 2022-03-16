import java.io.*;

/*
    현재 전구의 상태와 목표 전구 상태가 주어질 때, 현재 전구 상태를 목표 전구 상태로 만드는데 필요한 최소 클릭 수를 구하는 문제.

    <나의 풀이>
    풀지 못해서 구글링을 통해 아이디어를 얻었다.

    i번째 전구의 스위치를 클릭하면, i-1, i, i+1 번째 전구의 상태가 모두 바뀐다.
    따라서 전구를 앞에서부터 순회할 때, i번째를 탐색 기준으로 삼되 i-1번째 전구의 상태 변화에 집중해야 한다.
    (그래야 현재 인덱스 i 이전의 전구 상태가 목표 전구 상태와 동일한 상태를 유지할 수 있다.)

    i번째 전구 스위치를 클릭하면서 i-1번째 전구의 상태를 체크해 나갈 것인데, 이 방법으로는 첫 번째 전구 스위치를 클릭하는 경우를 체크할 수 없다.
    따라서 첫 번째 전구 스위치를 클릭한 경우(이하 A)와 그렇지 않은 경우(이하 B), 이렇게 두 가지 상태를 만들어 두고 두 상태 모두 순차탐색하는 방법으로 풀면 된다.

    순차탐색은 A, B 모두 n-1번째 전구 스위치를 클릭해서 n-2번째 전구의 상태까지 맞춰주고, n-1번째 전구의 상태가 목표 전구 상태와 동일한지 확인한다.
    동일하다면 A, B 둘 중 횟수가 작은 경우가 정답이 되고, A, B 둘 다 동일하지 않으면 불가능한 경우이므로 -1를 출력한다.
 */

class BulbAndSwitch {

    static int INF = Integer.MAX_VALUE;
    static int cans = 1, ncans = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        String input = br.readLine();
        String target = br.readLine();

        StringBuilder clickStat = new StringBuilder(input).append("1");
        StringBuilder nonClickStat = new StringBuilder(input).append("1");
        clickStat.setCharAt(0, clickStat.charAt(0) == '1' ? '0' : '1');
        clickStat.setCharAt(1, clickStat.charAt(1) == '1' ? '0' : '1');

        for (int i = 1; i < n; ++i) {
            click(clickStat, target, i, true);
            click(nonClickStat, target, i, false);
        }

        if (clickStat.charAt(n-1) != target.charAt(n-1)) {
            cans = INF;
        }
        if(nonClickStat.charAt(n-1) != target.charAt(n-1)) {
            ncans = INF;
        }

        int ans;
        if(cans == INF && ncans == INF) {
            ans = -1;
        } else {
            ans = Math.min(cans, ncans);
        }
        bw.write(String.valueOf(ans));
        bw.flush();
    }

    public static void click(StringBuilder sb, String target, int i, boolean isClickStat) {
        if (sb.charAt(i - 1) != target.charAt(i - 1)) {
            sb.setCharAt(i - 1, sb.charAt(i - 1) == '1' ? '0' : '1');
            sb.setCharAt(i, sb.charAt(i) == '1' ? '0' : '1');
            sb.setCharAt(i + 1, sb.charAt(i + 1) == '1' ? '0' : '1');
            if(isClickStat) {
                ++cans;
            } else {
                ++ncans;
            }
        }
    }
}