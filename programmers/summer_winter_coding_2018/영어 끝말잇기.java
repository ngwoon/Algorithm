package summer_winter_coding_2018;

import java.util.HashSet;
import java.util.Set;

/*
    끝말잇기 게임 과정이 주어질 때, 탈락한 사람의 번호와 몇 번째 턴에서 탈락했는지를 구하는 문제.

    <나의 풀이>
    끝말잇기에서 탈락하는 경우는 두 가지이다.
        * 잘못된 끝말을 제시한 경우
        * 이미 제시한 단어를 제시한 경우
    문제에서 제공하는 배열을 순차 탐색하면서, 이미 제시한 단어인지 검사하기 위해 set을 사용하고, 매 턴마다 이전 단어와 현재 단어의 알파벳을 비교하여 풀 수 있다.
 */
class EnglishEndTalk {
    public int[] solution(int n, String[] words) {
        Set<String> usedWord = new HashSet<>();
        String prev = words[0];
        usedWord.add(words[0]);
        int[] ans = {0, 0};
        for (int i=1; i<words.length; ++i) {
            String cur = words[i];
            if(prev.charAt(prev.length()-1) != cur.charAt(0) || usedWord.contains(cur)) {
                ans[0] = (i % n) + 1;
                ans[1] = (i / n) + 1;
                break;
            } else {
                prev = cur;
                usedWord.add(cur);
            }
        }

        return ans;
    }
}