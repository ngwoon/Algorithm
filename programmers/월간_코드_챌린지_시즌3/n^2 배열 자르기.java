package 월간_코드_챌린지_시즌3;

import java.util.ArrayList;
import java.util.List;

/*
    문제의 규칙대로 2차원 배열을 만들고 이를 1차원으로 변환했을 때, left ~ right 범위의 배열을 잘라내는 문제.

    <나의 풀이>
    n의 크기에 따라 일정한 규칙이 있다.
        * n = 1
            1
        * n = 2
            1 2   2 2
        * n = 3
            1 2 3   2 2 3   3 3 3
        * n = 4
            1 2 3 4   2 2 3 4   3 3 3 4   4 4 4 4
    k번째 행의 첫 번째 요소는 k로 시작하며, m번째 열까지는 그 값이 유지되고, 그 이후로 1씩 증가한다는 규칙을 찾을 수 있다.
    따라서 left가 속한 행의 첫 번째 요소값을 구하면 left 요소의 값을 구할 수 있고, 1씩 증가시키며 right 요소까지 배열을 만들면 된다.
    단, 행이 바뀌는 시점 (요소 값이 n보다 커지는 시점) 에는 해당 행의 시작값으로 초기화한 뒤 다시 유지 or 1증가 규칙을 따라야 한다.
 */

class DivideArray {
    public int[] solution(int n, long left, long right) {
        List<Integer> list = new ArrayList<>();
        int arrIdx = (int) (left / n) + 1;
        int inArrIdx = (int) ((left % n) + 1);
        while(left <= right) {
            list.add(Math.max(inArrIdx, arrIdx));
            inArrIdx += 1;
            if(inArrIdx % n == 1) {
                inArrIdx = 1; arrIdx += 1;
            }
            left += 1;
        }

        int[] ans = new int[list.size()];
        int idx = 0;
        for (int num : list) {
            ans[idx++] = num;
        }
        return ans;
    }
}