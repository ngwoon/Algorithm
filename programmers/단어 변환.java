import java.util.*;

class ChangeWord {

    public int calcDiff(String a, String b) {

        int diff = 0;
        for(int i=0; i<a.length(); ++i) {
            if(a.charAt(i) != b.charAt(i)) {
                ++diff;
            }
        }

        return diff;
    }

    public int bfs(String start, String target, List<String> wordList, Map<String, List<String>> adj) {

        Queue<Pair> que = new LinkedList<>();
        Map<String, Boolean> visited = new HashMap<>();

        for (String word : wordList) {
            visited.put(word, false);
        }
        que.add(new Pair(start, 0));
        visited.put(start, true);

        while(!que.isEmpty()) {
            Pair cur = que.poll();
            String word = cur.word;
            int count = cur.count;

            if(word.equals(target)) {
                return count;
            }

            List<String> list = adj.get(word);
            for (String related : list) {
                if(!visited.get(related)) {
                    visited.put(related, true);
                    que.add(new Pair(related, count + 1));
                }
            }
        }

        return 0;
    }

    public int solution(String begin, String target, String[] words) {

        List<String> wordList = new LinkedList<>(Arrays.asList(words));

        if(!wordList.contains(target)) {
            return 0;
        }

        wordList.add(begin);
        Map<String, List<String>> adj = new HashMap<>();
        for (String word : wordList) {
            adj.put(word, new LinkedList<>());
        }

        for(int i=0; i<wordList.size(); ++i) {
            String cur = wordList.get(i);
            for(int j=i+1; j<wordList.size(); ++j) {
                String t = wordList.get(j);
                if(calcDiff(cur, t) == 1) {
                    adj.get(cur).add(t);
                    adj.get(t).add(cur);
                }
            }
        }

        return bfs(begin, target, wordList, adj);
    }

    static class Pair {

        String word;
        int count;

        Pair(String word, int count) {
            this.word = word;
            this.count = count;
        }
    }
}