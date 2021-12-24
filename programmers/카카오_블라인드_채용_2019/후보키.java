package 카카오_블라인드_채용_2019;

import java.util.*;

/*
    DB의 레코드들이 주어질 때, 후보키가 될 수 있는 컬럼의 조합 개수를 구하는 문제.

    <나의 문제>
    이 문제의 핵심은 컬럼의 조합을 구하는 방법이다.
    컬럼 조합을 적은 개수부터 시도하면서, 문제에서 제시한 최소성을 확인할 수 있도록 했다.
    아울러 컬럼의 개수가 최대 8개이므로, 컬럼 조합 상태를 비트열로 표현하여 시간복잡도와 공간복잡도를 줄일 수 있다.
 */

class CandidateKey {

    HashSet<Integer> pickedHs;
    String[][] grelation;
    int rn, cn, ans;

    public int solution(String[][] relation) {

        rn = relation.length;
        cn = relation[0].length;
        grelation = relation;

        pickedHs = new HashSet<>();

        for(int i=1; i<=cn; ++i) {
            pickCandidateKey(-1, 0, 0, i);
        }

        return ans;
    }

    public void pickCandidateKey(int idx, int pb, int pc, int target) {

        if(pc == target) {
            if(checkIsCandidateKey(pb)) {
                pickedHs.add(pb);
                ++ans;
            }
            return;
        }

        for(int i=idx+1; i<cn; ++i) {
            int nb = pb + (int) Math.pow(2, i);
            Iterator<Integer> iter = pickedHs.iterator();
            boolean isExist = false;
            while(iter.hasNext()) {
                Integer next = iter.next();
                if((next & nb) == next) {
                    isExist = true;
                    break;
                }
            }
            if(!isExist) {
                pickCandidateKey(i, pb + (int) Math.pow(2, i), pc + 1, target);
            }
        }
    }

    public boolean checkIsCandidateKey(int pb) {

        HashSet<String> hs = new HashSet<>();
        for (String[] record : grelation) {
            StringBuilder sb = new StringBuilder();
            for(int i=0; i<cn; ++i) {
                int cb = (int) Math.pow(2, i);
                if((cb & pb) == cb) {
                    sb.append(record[i]).append(" ");
                }
            }

            String key = sb.toString();
            if(hs.contains(key)) {
                return false;
            } else {
                hs.add(key);
            }
        }

        return true;
    }
}