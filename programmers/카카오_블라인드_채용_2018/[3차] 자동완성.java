package 카카오_블라인드_채용_2018;

import java.util.HashMap;

/*
    자동완성기능을 위한 학습 단어 데이터가 주어지고, 이 단어들을 학습시킨 뒤 순서대로 검색했을 때, 입력해야하는 총 알파벳 개수를 구하는 문제.

    <나의 풀이>
    Trie 자료구조를 이용해서 풀었다.
    주어진 학습 단어들로 Trie를 만든 후, 학습 단어들을 순차적으로 탐색하면서 현재 알파벳 노드의 wordCount가 1이거나,
    단어의 끝 알파벳이라면 현재까지의 알파벳 개수를 ans 변수에 더해주는 방식으로 풀 수 있다.
 */

class AutoCompletion {

    Node root;
    int ans = 0;

    public int solution(String[] words) {

        root = new Node('A');
        for (String word : words) {
            Node cur = root;
            int idx=0;
            while(idx < word.length()) {
                char c = word.charAt(idx);
                if(!cur.child.containsKey(c)) {
                    cur.child.put(c, new Node(c));
                }

                cur = cur.child.get(c);
                cur.wordCount += 1;
                ++idx;
            }
        }

        for(String word : words) {
            Node cur = root.child.get(word.charAt(0));
            int idx=0;
            while(cur != null) {
                if(cur.wordCount == 1 || idx+1 == word.length()) {
                    ans += (idx+1);
                    break;
                }
                ++idx;
                cur = cur.child.get(word.charAt(idx));
            }
        }

        return ans;
    }

    static class Node {
        char c;
        HashMap<Character, Node> child;
        int wordCount;
        public Node(char c) {
            this.c = c;
            child = new HashMap<>();
            wordCount = 0;
        }
    }
}