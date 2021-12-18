package 카카오_블라인드_채용_2018;

import java.util.HashMap;

/*
    캐시 크기와 검색 문자열들이 주어졌을 때, 총 검색 시간을 구하는 문제.

    <나의 풀이>
    특별한 알고리즘이 필요한 문제는 아니다. 문제 조건에 맞게 LRU 캐시 교체 정책에 따라 캐시를 갱신하면서 검색 시간을 구하면 된다.
    단, 주어진 캐시 크기가 0일 경우에는 캐시를 사용할 수 없으므로, 문자열 개수 * 5를 정답으로 리턴하면 된다.
 */

class Cache {
    public int solution(int cacheSize, String[] cities) {

        HashMap<String, Integer> cache = new HashMap<>();
        int ans = 0;
        int time = 0;

        if(cacheSize == 0) {
            ans = cities.length * 5;
        } else {
            for (String city : cities) {
                city = city.toLowerCase();

                if(cache.containsKey(city)) {
                    ans += 1;
                } else {
                    ans += 5;

                    if(cache.size() == cacheSize) {
                        String replacedKey = "";
                        int minUsed = 100000;
                        for (String key : cache.keySet()) {
                            if (cache.get(key) < minUsed) {
                                replacedKey = key;
                                minUsed = cache.get(key);
                            }
                        }
                        cache.remove(replacedKey);
                    }
                }

                cache.put(city, time);

                ++time;
            }
        }

        return ans;
    }
}