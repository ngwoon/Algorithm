package 카카오_블라인드_채용_2019;

import java.util.*;

/*
    각 플레이어가 도달했으나 클리어하지 못한 스테이지들이 주어졌을 때, 실패율이 높은 순으로 스테이지 번호를 정렬하는 문제.

    <나의 풀이>
    특별한 알고리즘이 필요한 문제는 아니다.
    문제에서 제시한 실패율의 정의에 맞게 실패율을 구하고, 내림차순으로 정렬하면 된다.
 */

class FailureRate {
    public int[] solution(int N, int[] drifts) {

        List<Stage> stages = new ArrayList<>(N+1);
        stages.add(new Stage(0));
        for(int i=1; i<=N; ++i) {
            stages.add(new Stage(i));
        }

        Arrays.sort(drifts);
        int clear = 0;
        for(int i=0; i<drifts.length; ++i) {
            if(drifts[i] <= N) {
                ++stages.get(drifts[i]).drift;
            } else {
                ++clear;
            }
        }

        for(int i=N; i>0; --i) {
            clear += stages.get(i).drift;
            stages.get(i).clear = clear;
        }

        stages.remove(0);
        Collections.sort(stages);
        int[] ans = new int[N];
        for(int i=0; i<N; ++i) {
            ans[i] = stages.get(i).num;
        }

        return ans;
    }

    static class Stage implements Comparable<Stage> {
        int num;
        int clear;
        int drift;
        public Stage(int num) {
            this.num = num;
            this.clear = 0;
            this.drift = 0;
        }

        @Override
        public int compareTo(Stage o) {
            double thisFail = this.clear == 0 ? 0 : this.drift / (double) this.clear;
            double oFail = o.clear == 0 ? 0 : o.drift / (double) o.clear;

            if(thisFail == oFail) {
                return this.num - o.num;
            }
            return (oFail - thisFail) == 0 ? 0 : ((oFail - thisFail) < 0 ? -1 : 1);
        }
    }
}