package 카카오_블라인드_채용_2018;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

import static java.lang.Integer.parseInt;

/*
    셔틀 시간표와 각 크루가 대기열에 도착하는 시간이 주어졌을 때, 셔틀버스를 탈 수 있는 가장 늦은 시각을 구하는 문제.

    <나의 풀이>
    특별한 알고리즘이 필요한 문제는 아니었다. 문제의 조건에 맞게 사람들을 셔틀에 태우면서, 각 셔틀마다 탈 수 있는 최대 늦은 시각을 갱신해가면서 풀었다.
 */

class ShuttleBus {
    public String solution(int n, int t, int m, String[] timetable) {

        List<Integer> times = new ArrayList<>(timetable.length);
        for (String time : timetable) {
            times.add(hhmmToMin(time));
        }

        times.sort(Comparator.comparingInt(Integer::intValue));

        int cur = 540; // 9시
        int idx = 0; // 다음에 탈 사람 인덱스
        int ans = times.get(0) < cur ? times.get(0) - 1 : 539;
        while(n-- > 0) {
            int onBoard = 0, lastBoard = -1;
            while(idx < timetable.length && times.get(idx) <= cur && onBoard < m) {
                lastBoard = idx;
                ++idx; ++onBoard;
            }

            if(onBoard < m) {
                ans = cur;
            } else if(lastBoard != -1) {
                ans = times.get(lastBoard) - 1;
            }

            cur += t;
        }

        return minToHhmm(ans);
    }

    public int hhmmToMin(String time) {
        String[] splited = time.split(":");
        return parseInt(splited[0]) * 60 + parseInt(splited[1]);
    }

    public String minToHhmm(int time) {
        int hour = time / 60;
        int min = time % 60;
        return String.format("%02d:%02d", hour, min);
    }
}