package Dev_Matching_웹_백엔드_개발자_상반기_2021;

import java.util.*;
import java.util.stream.Collectors;

/*
    로또 번호들과 정답 번호들이 주어질 때, 최고 순위와 최저 순위를 구하는 문제.

    <나의 풀이>
    특별한 알고리즘이 필요한 문제는 아니다.
    불확실한 번호 (0) 의 개수와 맞춘 번호 개수를 구해둔 뒤, 불확실한 번호가 다 맞았을 경우가 최고 순위, 다 틀렸을 경우가 최저 순위이다.
 */

class Lotto {
    public int[] solution(int[] lottos, int[] winNums) {
        Set<Integer> winNumSet = Arrays.stream(winNums).boxed().collect(Collectors.toSet());
        int unknown = 0;
        int correct = 0;
        for (int lotto : lottos) {
            if(winNumSet.contains(lotto)) {
                ++correct;
            } else if(lotto == 0) {
                ++unknown;
            }
        }

        int[] ans = new int[2];
        ans[0] = Math.min(7 - (correct + unknown), 6);
        ans[1] = Math.min(7 - correct, 6);
        return ans;
    }
}