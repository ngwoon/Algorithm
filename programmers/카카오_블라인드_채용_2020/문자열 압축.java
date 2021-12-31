package 카카오_블라인드_채용_2020;

import java.util.ArrayList;
import java.util.List;

/*
    문자열이 주어질 때, 문제 조건에 맞게 문자열을 압축하여 만들 수 있는 가장 짧은 압축 문자열의 길이를 구하는 문제.

    <나의 풀이>
    문자열의 최대 길이가 1000이므로, 완전탐색으로 풀 수 있다.
    압축 문자열 길이를 1부터 문자열 길이의 절반까지 설정하면서, 각 경우마다 압축 문자열을 만들고 이를 압축한 결과 문자열의 길이를 측정하면 된다.
 */

class StringCompression {

    public int solution(String s) {

        int ans = 1001;
        int n = s.length();
        int divLen = 1;
        int maxLen = n / 2 + 1;
        while(divLen <= maxLen) {
            List<String> subStrs = new ArrayList<>();
            for(int i=0; i<s.length(); i+=divLen) {
                subStrs.add(s.substring(i, Math.min(i+divLen, s.length())));
            }

            int count = 1;
            StringBuilder result = new StringBuilder();
            for (int i=0; i<subStrs.size() - 1; ++i) {
                String cur = subStrs.get(i);
                String next = subStrs.get(i+1);
                if(cur.equals(next)) {
                    ++count;
                } else {
                    if(count > 1) {
                        result.append(count);
                        count = 1;
                    }
                    result.append(cur);
                }
            }
            if(count > 1) {
                result.append(count);
            }
            result.append(subStrs.get(subStrs.size() - 1));

            ans = Math.min(ans, result.length());
            ++divLen;
        }

        return ans;
    }
}