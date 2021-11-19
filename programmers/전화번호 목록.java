import java.util.Arrays;
import java.util.HashSet;

/*
    주어진 배열 요소 중 다른 요소의 접두어가 될 수 있는 요소가 존재하는지 판별하는 문제.

    <나의 풀이>
    먼저 주어진 배열을 길이의 내림차순으로 정렬한다. 이 배열을 차례로 순회할건데, 순회하면서 앞선 요소들의 접두어가 될 수 없다면
    현재 요소의 모든 가능한 접두어 후보를 HashSet에 저장하고 다음 요소로 넘어간다. 이를 반복하면서 HashSet내의 접두어와 일치하는
    요소가 등장한다면 false를 리턴한다.

    <더 나은 풀이>
    일단 접두어에 대한 문제이기 때문에 String 클래스의 startsWith 메서드의 활용을 고려해보았어야 했다.
    다른 이의 풀이 중, 주어진 배열을 사전순 정렬한 뒤, 배열을 순회하면서 인근 요소와의 비교만을 수행하는 방법이 있었다.
    다른 요소의 접두어가 되기 위해선 최대한 자신과 비슷한 요소와 비교하는것이 효율적이고, 이를 위해 사전순 배열을 활용한 점이
    인상깊었다.
 */

class PhoneBook {
    public boolean solution(String[] phoneBook) {
        boolean answer = true;

        Arrays.sort(phoneBook, (a, b) -> b.length() - a.length());

        HashSet<String> hs = new HashSet<>();

        for (String p : phoneBook) {
            if(hs.contains(p)) {
                answer = false;
                break;
            } else {
                for(int i=0; i<p.length(); ++i) {
                    String prefix = p.substring(0, i + 1);
                    hs.add(prefix);
                }
            }
        }

        return answer;
    }
}
