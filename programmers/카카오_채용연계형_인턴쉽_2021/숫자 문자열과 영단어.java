package 카카오_채용연계형_인턴쉽_2021;

import java.util.HashMap;

/*
    일부가 영문으로 바뀐 숫자 문자열이 주어졌을 때, 이 문자열의 원래 정수값을 구하는 문제.

    <나의 풀이>
    hashmap에 영문에 대응하는 숫자 쌍을 저장해두고, string.replaceAll() 메서드를 활용하면 쉽게 풀 수 있다.
    단, hs.keySet()을 탐색할 때 숫자의 순서가 보장되지 않는다는 점을 기억해야 한다.
 */

class WordAndNumber {

    HashMap<String, Integer> hs;

    public int solution(String s) {

        init();

        for (String key : hs.keySet()) {
            s = s.replaceAll(key, String.valueOf(hs.get(key)));
        }

        return Integer.parseInt(s);
    }

    public void init() {
        hs = new HashMap<>();
        hs.put("zero", 0);
        hs.put("one", 1);
        hs.put("two", 2);
        hs.put("three", 3);
        hs.put("four", 4);
        hs.put("five", 5);
        hs.put("six", 6);
        hs.put("seven", 7);
        hs.put("eight", 8);
        hs.put("nine", 9);
    }
}