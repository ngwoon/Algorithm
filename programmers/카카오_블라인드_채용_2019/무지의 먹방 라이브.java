package 카카오_블라인드_채용_2019;

import java.util.*;

/*
    음식을 먹는데 걸리는 시간 배열과 네트워크 지연 시작 시각이 주어질 때, 네트워크 지연 이후 몇 번째 음식을 먹어야 하는지 구하는 문제.

    <나의 풀이>
    이 문제는 k의 최대값이 2*10^13이므로 시간을 1씩 늘려가면서 k와 foodTimes를 비교하는 방법으로 풀 수 없다. foodTimes배열 내의 최솟값을 기준으로 풀어야 한다.
    foodTimes배열 내의 최솟값을 a라고 할 때, foodTimes.length * a초 후에는 foodTimes 배열 내의 a값을 갖는 요소들은 전부 0이 된다는 것이 핵심이다.
    즉, k를 한 번에 foodTimes.length * a 만큼 줄여가면서, k가 foodTimes.length * a 보다 작던가, 아직 0이 되지 않은 foodTime이 없던가 둘 중 하나의 경우를 마주할 때 까지
    위 과정을 반복하고, 음식이 먼저 소진된다면 -1이 정답이 되고, 그렇지 않으면 남아있는 음식 중 k % 남아있는 음식.length 번째 음식의 인덱스가 정답이 된다.

    주의해야 할 점은, k가 long 타입이므로 k와 관련된 연산들은 모두 이를 신경써주어야 한다. 나도 마지막에 int rest = (int) (k % idxList.size()) 연산에서 괄호를 빼먹었다가
    효율성테스트 2번에서 런타임 에러가 났다.
 */

class Mukbang {

    public static int solution(int[] foodTimes, long k) {

        PriorityQueue<Pair> timePq = new PriorityQueue<>(Comparator.comparingInt(a -> a.time));
        for(int i=0; i<foodTimes.length; ++i) {
            timePq.add(new Pair(i+1, foodTimes[i]));
        }

        int prev = 0;
        while(!timePq.isEmpty()) {
            Pair pair = timePq.poll();
            int curFoodTime = pair.time;
            long cycle = ((long) (curFoodTime - prev)) * (timePq.size() + 1);

            if(cycle <= k) {
                k -= cycle;
                prev = curFoodTime;
                while(!timePq.isEmpty()) {
                    if(timePq.peek().time == curFoodTime) {
                        timePq.poll();
                    } else {
                        break;
                    }
                }
            } else {
                timePq.add(pair);
                break;
            }
        }

        int ans;
        if(timePq.isEmpty()) {
            ans = -1;
        } else {
            List<Pair> idxList = new ArrayList<>(timePq.size());
            while(!timePq.isEmpty()) {
                idxList.add(timePq.poll());
            }

            idxList.sort(Comparator.comparingInt(a -> a.idx));
            int rest = (int) (k % idxList.size());
            ans = idxList.get(rest).idx;
        }

        return ans;
    }

    static class Pair {
        int time, idx;
        public Pair(int idx, int time) {
            this.idx = idx;
            this.time = time;
        }
    }

    public static void main(String[] args) {
        int[] foodTimes = {10000000,9182938,12313,12122,2,1231231,1313131,123141,111,11,1,123123};
        int solution = solution(foodTimes, 10000000000L);
        System.out.println(solution);
    }
}