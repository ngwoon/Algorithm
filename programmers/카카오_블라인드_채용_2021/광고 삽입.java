package 카카오_블라인드_채용_2021;

import static java.lang.Integer.parseInt;

/*
    동영상 플레이 타임과 삽입할 광고 플레이 타임, 각 시청자의 시청 시간 로그들이 주어질 때, 누적 시청 시간이 가장 높아지는 광고 삽입 시각을 찾는 문제.

    <나의 풀이>
    풀지 못해서 구글링을 통해 아이디어를 얻었다.

    시간 구간 문제이길래 가장 많이 겹치는 구간 찾는 문제인 줄 알았으나, 누적 시청시간이 가장 높아지는 광고 삽입 시각을 찾는 문제였다.
    문제 조건을 보면 동영상 플레이 타임이 초 단위로 0 ~ 360000이므로, 배열을 사용하여 구간합 알고리즘으로 풀 수 있는 문제다.
    크기 360000의 int 배열을 선언하고, 시청 로그를 순회하면서 시청된 시각 배열 요소에 +1을 하면 각 초별로 몇 명의 시청자가 시청했는지를 구할 수 있다.
    이후에는 0부터 360000까지 광고 플레이 타임에 속하는 요소를 더해서 가장 높은 시청 시간일 때 해당 시각이 정답이 된다.
    단, 광고 플레이 타임과 동영상 플레이 타임을 일일이 다 비교하면, O(NM)의 시간복잡도를 가지므로 시간초과가 날 수 있다.
    따라서 투 포인터 알고리즘을 활용해 처음에만 일일이 구하고, 그 뒤부터는 이전 광고 플레이 타임의 시작 시각을 빼고, 새로 비교할 구간에서 가장 마지막 시각을 더하는 방식으로 풀어야 한다.
 */

class AdInsertion {

    int[] video;

    public String solution(String playTime, String advTime, String[] logs) {

        video = new int[360000];
        for(String log : logs) {
            String[] startEnd = log.split("-");
            String start = startEnd[0];
            String end = startEnd[1];
            int startSec = hhmmssToSec(start);
            int endSec = hhmmssToSec(end);
            for(int i=startSec; i<endSec; ++i) {
                video[i] += 1;
            }
        }

        int playTimeInt = hhmmssToSec(playTime);
        int advTimeInt = hhmmssToSec(advTime);
        int s = 0;
        long time = -1;
        long maxTime = -1, maxS = -1;
        while(s + advTimeInt <= playTimeInt) {
            if(time == -1) {
                time = 0;
                for(int i=s; i<s + advTimeInt; ++i) {
                    time += video[i];
                }
            } else {
                time -= video[s-1];
                time += video[s + advTimeInt-1];
            }

            if(maxTime < time) {
                maxTime = time;
                maxS = s;
            }

            ++s;
        }

        return secToHhmmss(maxS);
    }

    public int hhmmssToSec(String time) {
        String[] splited = time.split(":");
        return parseInt(splited[0]) * 3600 + parseInt(splited[1]) * 60 + parseInt(splited[2]);
    }

    public String secToHhmmss(long time) {
        int hour = (int) time / 3600;
        time %= 3600;
        int min = (int) time / 60;
        time %= 60;
        int sec = (int) time;
        return String.format("%02d:%02d:%02d", hour, min, sec);
    }
}