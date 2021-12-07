package 카카오_개발자_겨울_인턴쉽_2019;

import java.util.HashMap;

/*
    방 번호의 최대값과 손님들이 선택한 방 번호 목록이 주어졌을 때, 각 손님이 배정받는 방 번호 배열을 구하는 문제.

    <나의 풀이>
    풀지 못해서 구글링으로 해결방법을 참고했다.

    이 문제는 방 번호가 최대 1조 이므로, 이미 배정받은 방을 선택했을 때 다음 방 번호를 빠르게 찾는 것이 핵심이다.
    핵심 알고리즘으로는 유니온 파인드가 쓰였다.
    해시맵 hm의 key는 이미 배정받은 방 번호를 의미하고, value는 해당 방 번호보다 큰 번호 중 가장 작은 방 번호를 의미한다.
    만약 k=6이고, 손님들이 [1,1,1,1,1,1] 으로 방을 선택했다면, 아래와 같은 흐름으로 hm이 변화한다.
        1. hm에 (1,2) 쌍이 추가된다.
        2. hm에 (2,3) 쌍이 추가되고, (1,2) 쌍은 (1,3)으로 갱신된다.
        3. hm에 (3,4) 쌍이 추가되고, (2,3) -> (2,4)로, (1,3) -> (1,4)로 갱신된다.
        ...
 */

class HotelRoom {

    HashMap<Long, Long> hm;

    public long[] solution(long k, long[] roomNumber) {

        hm = new HashMap<>();

        long[] ans = new long[roomNumber.length];
        int idx = 0;
        for (long num : roomNumber) {
            ans[idx++] = find(num);
        }

        return ans;
    }

    public long find(long num) {
        Long next = hm.get(num);
        if(next == null) {
            hm.put(num, num + 1);
            next = num + 1;
        } else {
            next = find(next);
            hm.put(num, next);
        }
        return next;
    }
}