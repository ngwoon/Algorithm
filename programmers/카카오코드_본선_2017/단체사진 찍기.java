package 카카오코드_본선_2017;

import java.util.*;

/*
    각 사람들이 요구하는 촬영위치가 주어질 때, 모든 조건을 만족하면서 사람들이 나열하는 경우의 수를 구하는 문제.

    <나의 풀이>
    사람은 총 8명이므로, 모든 나열 경우의 수는 8!이다.
    아울러 조건의 최대 개수도 100이므로, 완전 탐색으로 충분히 풀 수 있다.
 */

class GroupPhoto {

    Map<Character, List<Node>> adj;
    List<Character> people;
    boolean[] selected;
    int[] indexes;
    int pSize, ans;

    public int solution(int n, String[] data) {

        initPeople();

        adj = new HashMap<>();
        for (String d : data) {
            char c = d.charAt(0);
            if(!adj.containsKey(c)) {
                adj.put(c, new LinkedList<>());
            }
            List<Node> nodes = adj.get(c);
            nodes.add(new Node(d.charAt(2), d.charAt(3), Integer.parseInt(String.valueOf(d.charAt(4)))));
        }

        pSize = people.size();
        selected = new boolean[pSize];
        indexes = new int[pSize];
        dfs(new StringBuilder());

        return ans;
    }

    public void initPeople() {
        people = new ArrayList<>(8);
        people.add('A');
        people.add('C');
        people.add('F');
        people.add('J');
        people.add('M');
        people.add('N');
        people.add('R');
        people.add('T');
    }

    public void dfs(StringBuilder sb) {
        if(sb.length() == pSize) {
            if(isAllConditionSatisfied(sb.toString())) {
                ++ans;
            }
            return;
        }

        for(int i=0; i<pSize; ++i) {
            if(!selected[i]) {
                selected[i] = true;
                sb.append(people.get(i));
                dfs(sb);
                sb.deleteCharAt(sb.length() - 1);
                selected[i] = false;
            }
        }
    }

    public boolean isAllConditionSatisfied(String line) {
        for(int i=0; i<line.length(); ++i) {
            char c = line.charAt(i);
            List<Node> nodes = adj.get(c);
            if(nodes == null) {
                continue;
            }
            for (Node node : nodes) {
                char target = node.c;
                int targetIdx = line.indexOf(target);
                int curGap = Math.max(i, targetIdx) - Math.min(i, targetIdx) - 1;
                switch(node.op) {
                    case '=':
                        if(curGap != node.gap) {
                            return false;
                        }
                        break;
                    case '<':
                        if(curGap >= node.gap) {
                            return false;
                        }
                        break;
                    case '>':
                        if(curGap <= node.gap) {
                            return false;
                        }
                        break;
                }
            }
        }

        return true;
    }

    static class Node {
        char c, op;
        int gap;
        public Node(char c, char op, int gap) {
            this.c = c;
            this.op = op;
            this.gap = gap;
        }
    }
}