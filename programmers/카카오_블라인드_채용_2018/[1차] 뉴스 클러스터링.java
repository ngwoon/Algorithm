package 카카오_블라인드_채용_2018;

import java.util.HashMap;
import java.util.Map;

/*
    문자열 2개가 주어졌을 때, 두 문자열의 자카드 유사도를 구하는 문제.

    <나의 풀이>
    특별한 알고리즘이 필요한 문제는 아니다. 문제의 조건에 맞게 부분문자열로 이루어진 집합을 구하고, 교집합과 합집합을 구하여 자카드 유사도를 구하면 된다.
    단, 교집합과 합집합이 0인 경우 자카드 유사도는 1임을 유의하자.
 */

class NewsClustering {
    public int solution(String str1, String str2) {

        char[] chars1 = str1.toCharArray();
        char[] chars2 = str2.toCharArray();

        String filteredStr1 = toLower(chars1);
        String filteredStr2 = toLower(chars2);

        HashMap<String, Integer> hm1 = new HashMap<>();
        HashMap<String, Integer> hm2 = new HashMap<>();

        calcSubString(filteredStr1, hm1);
        calcSubString(filteredStr2, hm2);

        int intersection = 0;
        int union = 0;
        for (Map.Entry<String, Integer> entry : hm1.entrySet()) {
            String key = entry.getKey();
            Integer val = entry.getValue();
            if(hm2.containsKey(key)) {
                intersection += Math.min(val, hm2.get(key));
            }
            union += val;
        }

        for (int val : hm2.values()) {
            union += val;
        }

        union -= intersection;

        double jaccard = intersection == 0 && union == 0 ? 1.0 : intersection / (double) union;
        return (int) (jaccard * 65536);
    }

    public String toLower(char[] chars) {

        StringBuilder sb = new StringBuilder();
        for (char c : chars) {
            if(65 <= c && c <= 90) {
                sb.append((char)(c + 32));
            } else {
                sb.append(c);
            }
        }

        return sb.toString();
    }

    public void calcSubString(String str, HashMap<String, Integer> hm) {

        for(int i=0; i<str.length()-1; ++i) {
            String sub = str.substring(i, i+2);
            if(isAlpha(sub.charAt(0)) && isAlpha(sub.charAt(1))) {
                hm.put(sub, hm.getOrDefault(sub, 0) + 1);
            }
        }
    }

    public boolean isAlpha(char c) {
        return 97 <= c && c <= 122;
    }
}