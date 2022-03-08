package 월간_코드_챌린지_시즌1;

import java.util.*;

/*
    수열이 주어질 때, 이 수열의 부분수열로 만들 수 있는 가장 긴 스타수열의 길이를 구하는 문제.

    <나의 풀이>
    수열의 최대 길이가 50만이므로, 모든 부분수열을 구해서 이것이 스타 수열인지 확인하는 방법은 불가능하다.
    스타 수열의 조건을 살펴보면, 길이가 2의 배수여야 하고, 스타 수열을 길이 2의 부분집합들로 나누었을 때 그들의 교집합 크기가 1 이상이어야 한다.
    여기서 힌트를 얻어, 수열에서 가장 많이 등장하는 수를 포함하는 스타수열을 만들면 그것의 길이가 정답이라고 예상했다.

    하지만 단지 수열에서 가장 많이 등장하는 수를 선택한다면, 아래와 같은 코너케이스가 문제가 된다.
    [ 1 1 1 1 2 0 2 0 2 ]
    가장 많이 등장한 수는 1이지만, 가장 긴 스타 수열은 [1 2 0 2 0 2] 가 된다.
    이 이유는, 숫자가 3번 이상 연속해서 등장하면 그 중간에 있는 숫자는 스타 수열을 구성할 때 사용하지 못하는 수가 되어버리기 때문이다.
    따라서 가장 많이 등장하는 숫자를 구하기 전에 세 번 이상 연속된 숫자를 두 개만 남겨주는 작업이 필요하다.
 */

class StarSequence {
    public int solution(int[] a) {

        // 연속된 요소의 중복 제거
        List<Integer> seq = new ArrayList<>(a.length);
        for (int i : a) {
            if(seq.size() < 2) {
                seq.add(i);
            } else {
                int pp = seq.get(seq.size() - 2);
                int p = seq.get(seq.size() - 1);
                if(pp != p || p != i) {
                    seq.add(i);
                }
            }
        }

        // 중복 제거된 수열에서 숫자 - 빈도 쌍 구하기
        Map<Integer, Integer> freqMap = new HashMap<>();
        for (int num : seq) {
            freqMap.put(num, freqMap.getOrDefault(num, 0) + 1);
        }

        List<Pair> maxFreqList = new ArrayList<>(freqMap.size());
        for (int num : freqMap.keySet()) {
            maxFreqList.add(new Pair(num, freqMap.get(num)));
        }
        Collections.sort(maxFreqList);

        int maxFreq = maxFreqList.get(0).freq;
        int ans = 0;
        for (Pair pair : maxFreqList) {
            if(pair.freq < maxFreq) {
                break;
            }
            ans = Math.max(ans, makeStarSeq(pair.num, a));
        }

        return ans;
    }

    public int makeStarSeq(int num, int[] seq) {
        int idx = 0;
        int len = 0;
        while(idx + 1 < seq.length) {
            int a = seq[idx];
            int b = seq[idx + 1];
            if((a != num && b == num) || (a == num && b != num)) {
                len += 2;
                idx += 2;
            } else {
                idx += 1;
            }
        }
        return len;
    }

    static class Pair implements Comparable<Pair> {
        int num, freq;
        public Pair(int num, int freq) {
            this.num = num;
            this.freq = freq;
        }

        @Override
        public int compareTo(Pair o) {
            return o.freq - this.freq;
        }
    }
}