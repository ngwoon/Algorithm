package 카카오_블라인드_채용_2021;

import java.util.*;

/*
    손님들이 주문했던 메뉴 조합과, 주인이 만들고 싶은 코스메뉴의 길이가 주어질 때, 문제 조건에 맞게 코스메뉴들을 구하는 문제.

    <나의 풀이>
    손님들이 주문했던 메뉴 조합의 부분 문자열들을 구한 뒤, 길이 2 이상이고 제시된 코스메뉴의 길이에 맞는 부분문자열 중 가장 다양한 손님들에게서 주문된 메뉴구성을 구하면 된다.
    주의할 점은, 부분문자열을 구할 때 알파벳 순서가 달라도 구성만 같다면 같은 부분문자열로 취급해야 한다.
 */

class MenuRenewal {

    Map<String, Integer> menu;

    public String[] solution(String[] orders, int[] course) {

        menu = new HashMap<>();
        for (String order : orders) {
            for(int i=2; i<=order.length(); ++i) {
                calcSubString(order, i, 0, new StringBuilder());
            }
        }

        List<String> ansList = new LinkedList<>();
        for (int courseCount : course) {
            int maxCount = 0;
            for (String key : menu.keySet()) {
                if (key.length() == courseCount && menu.get(key) > 1 && menu.get(key) > maxCount) {
                    maxCount = menu.get(key);
                }
            }

            for (String key : menu.keySet()) {
                if (key.length() == courseCount && menu.get(key) == maxCount) {
                    ansList.add(key);
                }
            }
        }

        Collections.sort(ansList);

        String[] ans = new String[ansList.size()];
        int idx = 0;
        for (String s : ansList) {
            ans[idx++] = s;
        }

        return ans;
    }

    public void calcSubString(String order, int len, int idx, StringBuilder sb) {

        if(len == sb.length()) {
            String temp = sb.toString();
            char[] chars = temp.toCharArray();
            Arrays.sort(chars);
            String substring = new String(chars);

            menu.put(substring, menu.getOrDefault(substring, 0) + 1);
            return;
        }

        for(int i=idx; i<order.length(); ++i) {
            sb.append(order.charAt(i));
            calcSubString(order, len, i+1, sb);
            sb.deleteCharAt(sb.length() - 1);
        }
    }
}
