package 카카오_블라인드_채용_2018;

import java.util.HashMap;
import java.util.LinkedList;

/*
    문자열이 주어질 때, 압축 알고리즘에 맞게 문자열을 압축한 결과를 구하는 문제.

    <나의 풀이>
    특별한 알고리즘이 필요한 문제는 아니다.
    문제에서 제시한 압축 알고리즘에 맞게, 사전에 없는 문자열을 새로운 색인으로 추가해가며 문자열을 탐색하는 문제이다.
    문자열을 1번 탐색하고, 해시맵을 이용하여 해당 문자열이 있는지 확인하므로 시간복잡도는 O(n)이다.
 */

class Compression {

    HashMap<String, Integer> dictionary;

    public int[] solution(String msg) {

        dictionary = new HashMap<>();
        int idxNum = 1;
        for(char c='A'; c <='Z'; ++c) {
            dictionary.put(Character.toString(c), idxNum++);
        }


        int s=0, e=0;
        int lastIndex = -1;
        LinkedList<Integer> idxList = new LinkedList<>();
        while(e < msg.length()) {
            String sb = msg.substring(s, e+1);
            if(dictionary.containsKey(sb)) {
                lastIndex = dictionary.get(sb);
            } else {
                dictionary.put(sb, idxNum++);
                idxList.add(lastIndex);
                s = e;
            }
            ++e;
        }
        idxList.add(idxNum);

        int[] ans = new int[idxList.size()];
        int i = 0;
        for (int idx : idxList) {
            ans[i] = idx;
        }

        return ans;
    }
}