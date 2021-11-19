import java.util.HashMap;

/*
    옷 카테고리와 각 카테고리에 속한 옷들이 주어졌을 때, 아무것도 입지 않는 경우를 제외한 모든 경우의 수를 구하는 문제.

    <나의 풀이>
    옷 카테고리당 몇 개의 옷이 속해 있는지가 중요하므로, HashMap을 활용하여 각 카테고리의 옷 개수를 저장해둔다.
    이후 순열조합의 기본 개념을 활용해 HashMap의 value를 순회하며 (카테고리에 속한 옷의 개수 + 1) 들을 곱해준 뒤,
    아무것도 입지 않는 경우의 수 1가지를 빼준다.

    <더 나은 풀이>
    풀이 개념은 똑같으나, stream과 람다를 활용한 아주 심플한 정답이 있어서 여기에 적어둔다.
    public int solution(String[][] clothes) {
        return Arrays.stream(clothes)
                .collect(groupingBy(p -> p[1], mapping(p -> p[0], counting())))
                .values()
                .stream()
                .collect(reducing(1L, (x, y) -> x * (y + 1))).intValue() - 1;
    }
 */

class Camouflage {
    public int solution(String[][] clothes) {

        HashMap<String, Integer> hm = new HashMap<>();

        for (String[] cloth : clothes) {
            hm.put(cloth[1], hm.getOrDefault(cloth[1], 0) + 1);
        }

        int answer = 1;
        for (int count : hm.values()) {
            answer *= (count + 1);
        }

        return answer - 1;
    }
}