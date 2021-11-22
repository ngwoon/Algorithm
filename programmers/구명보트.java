import java.util.Arrays;

/*
    사람의 몸무게와 구명보트의 무게 제한이 주어질 때, 사람들을 구출하는데 사용될 구명보트의 최소개수를 구하는 문제

    <나의 풀이>
    자바의 Arrays에 primitive 자료형의 내림차순 정렬이 없으므로, 몸무게를 오름차순 정렬하고 뒤에서부터 역순으로 탐색한다.
    구명보트를 최소한으로 사용할 수 있는 방법은 현재 남아있는 사람들 중 가장 무거운 사람과 가벼운 사람을 태우는 그리디한 방법이다.
    이 규칙에 따라 풀이하면 시간복잡도 O(n)으로 문제해결이 가능하다.
 */

class LifeBoat {
    public int solution(int[] people, int limit) {
        int answer = 0;

        Arrays.sort(people);

        int s = 0, e = people.length - 1;
        while(s <= e) {
            int sum = people[e];

            if(s != e && sum + people[s] <= limit) {
                ++s;
            }

            --e;
            ++answer;
        }

        return answer;
    }
}