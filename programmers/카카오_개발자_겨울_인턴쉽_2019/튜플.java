import java.util.*;

class Tuple {
    public int[] solution(String s) {

        LinkedList<String> elements = new LinkedList<>();
        for(int i=1; i<s.length(); ++i) {
            char cur = s.charAt(i);
            if(cur == '{') {
                int tmp = i+1;
                while(s.charAt(tmp) != '}') {
                    ++tmp;
                }

                elements.add(s.substring(i+1, tmp));
            }
        }

        elements.sort(Comparator.comparingInt(String::length));

        LinkedList<Integer> order = new LinkedList<>();
        HashMap<Integer, Boolean> exist = new HashMap<>();

        for (String element : elements) {
            String[] splited = element.split(",");
            for (String cur : splited) {
                int curInt = Integer.parseInt(cur);
                if(!exist.containsKey(curInt)) {
                    order.add(curInt);
                    exist.put(curInt, true);
                }
            }
        }

        int[] ans = new int[order.size()];
        int idx = 0;
        for (int integer : order) {
            ans[idx++] = integer;
        }

        return ans;
    }
}