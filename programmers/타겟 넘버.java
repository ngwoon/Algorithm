
/*
    숫자 배열이 주어졌을 때, 이들을 적절히 더하거나 빼서 타겟 숫자를 만드는 경우의 수를 구하는 문제.

    <나의 풀이>
    dfs를 활용한 완전탐색 문제이다. 재귀 함수를 통해 숫자 배열을 순회하면서 현재 숫자를 더하거나 뺀 값을 누적하고, 마지막에 타겟 숫자가 만들어졌는지 비교하는 방법으로 풀었다.
 */

class TargetNumber {

    int answer = 0;

    public void dfs(int[] numbers, int idx, int cur, int target) {

        if(idx == numbers.length) {
            if(cur == target) {
                ++answer;
            }
            return;
        }

        dfs(numbers, idx + 1, cur + numbers[idx], target);
        dfs(numbers, idx + 1, cur - numbers[idx], target);
    }

    public int solution(int[] numbers, int target) {
        dfs(numbers, 0, 0, target);

        return answer;
    }
}