package 카카오_인턴쉽_2020;

import java.util.*;

/*
    보석 진열대의 진열된 보석 배열이 주어질 때, 진열대에 놓여진 모든 보석 종류를 포함하는 가장 짧은 연속된 구간을 찾는 문제.

    <나의 풀이>
    슬라이딩 윈도우 기법을 활용해서 풀었다.
    시작 인덱스인 s, 끝 인덱스인 e변수를 둔다.
    문제를 푸는 핵심적인 생각은 아래와 같다.
        * 모든 종류의 보석을 포함하는 것이 최우선이므로, s부터 e까지 포함된 각 보석 종류들의 개수를 기억해야한다.
        * e를 증가시키면서 진열장 범위를 늘려간다. 단, 증가시킨 e에 존재하는 보석이 이미 현재 범위에 두 개 이상 있다면, s를 증가시키면서 한 개 이상 존재하는
          보석들은 범위에서 제외한다.
        * 모든 종류의 보석의 개수가 1 이상이면, 정답이 될 수 있으므로 이전에 정답처리한 ans[0], ans[1] 간격과 현재 s, e 간격을 비교해서 더 짧은
          간격을 정답으로 갱신한다.
 */

class GemShopping {

    HashMap<String, Integer> hm;

    public int[] solution(String[] gems) {

        int[] ans = {1, gems.length};

        hm = new HashMap<>();
        for (String gem : gems) {
            hm.put(gem, 0);
        }

        int s = 0, e = 0;
        int kinds = 0;
        while(e < gems.length) {
            hm.put(gems[e], hm.get(gems[e]) + 1);
            if(hm.get(gems[e]) == 1) {
                ++kinds;
            }

            if(hm.get(gems[e]) > 1) {
                while(s < e) {
                    if(hm.get(gems[s]) > 1) {
                        hm.put(gems[s], hm.get(gems[s]) - 1);
                        ++s;
                    } else {
                        break;
                    }
                }
            }
            if(kinds == hm.size() && (e-s < ans[1] - ans[0])) {
                ans[0] = s + 1; ans[1] = e + 1;
            }
            ++e;
        }

        return ans;
    }
}

//import java.util.*;
//
//class Solution {
//
//    Map<String, Integer> gemCnt;
//
//    public int[] solution(String[] gems) {
//        gemCnt = new HashMap<>();
//
//        Set<String> gemCategories = new HashSet<>(Arrays.asList(gems));
//
//        int s = 0, e = 0;
//        int ansMin = 100001;
//        int[] ans = new int[2];
//        while(e < gems.length) {
//            gemCnt.put(gems[e], gemCnt.getOrDefault(gems[e], 0) + 1);
//            while(true) {
//                int cnt = gemCnt.getOrDefault(gems[s], 0);
//                if(cnt > 1) {
//                    gemCnt.put(gems[s], cnt - 1);
//                    ++s;
//                } else {
//                    break;
//                }
//            }
//
//            if(gemCnt.keySet().size() == gemCategories.size() && (e-s+1) < ansMin) {
//                ansMin = (e-s+1);
//                ans[0] = s+1; ans[1] = e+1;
//            }
//
//            ++e;
//        }
//
//        return ans;
//    }
//}