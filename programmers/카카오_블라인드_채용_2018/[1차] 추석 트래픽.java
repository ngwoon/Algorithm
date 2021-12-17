package 카카오_블라인드_채용_2018;

import java.util.ArrayList;
import java.util.Comparator;

/*
    추석 하루동안의 트래픽 로그가 주어질 때, 최대 TPS값을 구하는 문제.

    <나의 풀이>
    풀지 못해서 해설을 참고했다.

    이 문제와 비슷한 유형의 문제를 풀었었다. (프로그래머스 - 단속카메라)
    이렇게 여러 요소들이 가장 많이 겹치는 구간을 구하는 문제는, 각 요소의 시작점과 끝점을 구해놓고 "끝점" 기준으로 오름차순 정렬한 뒤
    푸는 방식을 사용한다.

    이 문제가 까다로운 점은 그 구간이 너무 많다는 것이다. 24시간을 ms구간으로 나누면 86400000개이고, 이 구간마다 모든 로그에 대해 포함 여부를 비교하면
    86400000 * n (최대2000) 이므로 시간초과가 난다.

    이 문제를 풀기 위한 핵심 포인트는, 로그 개수의 변화는 로그 시작점과 끝점에서만 발생한다는 것이다. 따라서 모든 로그의 시작점, 끝점을 오름차순으로 정렬해놓고,
    각 지점을 시작으로 1초 범위를 설정한 다음, 모든 로그에 대해 해당 범위에 포함되는지를 판단하는 방법을 사용했다.

    시간복잡도를 계산해보면, 로그의 모든 시작점, 끝점 = 2n이고, 각 지점마다 로그n개를 비교하므로, O(2n^2)가 된다.
    n <= 2000이므로 시간초과가 나지 않는다.
 */

class ThanksGivingTraffic {
    public int solution(String[] lines) {

        int n = lines.length;
        String[] times = new String[n];
        for (int i=0; i<n; ++i) {
            times[i] = lines[i].substring(11);
        }

        ArrayList<Pair> logs = new ArrayList<>(n);
        ArrayList<Double> timeStamps = new ArrayList<>(n*2);
        for (String time : times) {
            String[] splited = time.split(" ");
            double end = timeStrToSeconds(splited[0]);
            double start = end - Double.parseDouble(splited[1].replace("s", "")) + 0.001;
            logs.add(new Pair(start, end));
            timeStamps.add(start); timeStamps.add(end);
        }

        logs.sort((a, b) -> (int) (a.end - b.end));
        timeStamps.sort(Comparator.comparingDouble(Double::doubleValue));

        int ans = 0;
        for (double timeStamp : timeStamps) {
            double start = timeStamp;
            double end = timeStamp + 1;
            int tps = 0;
            for(int i=0; i<n; ++i) {
                Pair cur = logs.get(i);
                if(cur.start < end && start <= cur.end) {
                    ++tps;
                }
            }
            ans = Math.max(ans, tps);
        }

        return ans;
    }

    public double timeStrToSeconds(String time) {

        String[] splited = time.split(":");
        double ret = 0;

        ret += Double.parseDouble(splited[0]) * 3600;
        ret += Double.parseDouble(splited[1]) * 60;
        ret += Double.parseDouble(splited[2]);

        return ret;
    }

    static class Pair {
        double start, end;
        public Pair(double start, double end) {
            this.start = start;
            this.end = end;
        }
    }
}