package 위클리_챌린지;

import java.util.HashMap;
import java.util.Map;

/*
    각 던전의 입장 필요 피로도와 소모 피로도가 주어질 때, 최대한 많은 던전을 돌고자 할 때 돌 수 있는 던전의 개수를 구하는 문제.

    <나의 풀이>
    던전의 크기가 작으므로, 던전을 탐험하는 모든 순서쌍을 구하는 완전탐색으로 풀이가 가능하다.
    각 경우의 수 마다 탐험할 수 있는 던전의 개수를 구하고, 그 중 최대값이 답이 된다.
 */

class Fatigue {

    int fatigue, n, ans;
    int[][] dungeonInfo;

    public int solution(int k, int[][] dungeons) {
        n = dungeons.length;
        fatigue = k;
        dungeonInfo = dungeons;

        dfs(0, new HashMap<>());

        return ans;
    }

    public void dfs(int idx, Map<Integer, Integer> dungeonIdxes) {
        if(idx == n) {
            ans = Math.max(ans, calc(dungeonIdxes));
            return;
        }

        for(int i=0; i<n; ++i) {
            if(!dungeonIdxes.containsKey(i)) {
                dungeonIdxes.put(i, idx);
                dfs(idx + 1, dungeonIdxes);
                dungeonIdxes.remove(i);
            }
        }
    }

    public int calc(Map<Integer, Integer> dungeonIdxes) {
        int k = fatigue;
        int exploration = 0;
        for(int i=0; i<n; ++i) {
            int idx = dungeonIdxes.get(i);
            if(k >= dungeonInfo[idx][0]) {
                ++exploration;
                k -= dungeonInfo[idx][1];
            } else {
                break;
            }
        }
        return exploration;
    }
}