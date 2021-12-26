package 카카오_블라인드_채용_2019;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/*
    노드들의 좌표가 주어졌을 때, 해당 노드들로 이루어진 트리의 전위, 후위순회를 구하는 문제.

    <나의 풀이>
    풀지 못해서 구글링을 통해 아이디어를 얻었다.
    문제에서 이진트리라는 힌트를 줬으므로, y좌표를 트리의 level, x좌표를 좌,우 자식 노드 판별에 사용할 수 있다.
    좌표를 이용해 트리를 만들 땐, root부터 시작해서 부모보다 x좌표가 작으면 왼쪽 자식 노드로 이동해서 탐색하고, 반대의 경우 오른쪽 자식 노드로 이동해서 탐색하는
    방식으로 트리를 만들 수 있다.
 */

class FindingRouteGame {

    List<Node> nodes;
    int idx;

    public int[][] solution(int[][] nodeInfo) {

        nodes = new ArrayList<>(nodeInfo.length + 1);
        int num = 1;
        for (int[] node : nodeInfo) {
            nodes.add(new Node(num++, node[1], node[0]));
        }

        Collections.sort(nodes);

        Node root = nodes.get(0);
        for(int i=1; i<nodes.size(); ++i) {
            insert(root, nodes.get(i));
        }

        int[][] ans = new int[2][nodes.size()];
        idx = 0;
        preOrder(root, ans[0]);
        idx = 0;
        postOrder(root, ans[1]);
        return ans;
    }

    public void insert(Node parent, Node child) {

        if(parent.x > child.x) {
            if(parent.left == null) {
                parent.left = child;
            } else {
                insert(parent.left, child);
            }
        } else {
            if(parent.right == null) {
                parent.right = child;
            } else {
                insert(parent.right, child);
            }
        }
    }

    public void preOrder(Node cur, int[] arr) {
        if(cur != null) {
            arr[idx++] = cur.num;
            preOrder(cur.left, arr);
            preOrder(cur.right, arr);
        }
    }

    public void postOrder(Node cur, int[] arr) {
        if(cur != null) {
            postOrder(cur.left, arr);
            postOrder(cur.right, arr);
            arr[idx++] = cur.num;
        }
    }

    static class Node implements Comparable<Node> {
        int num, y, x;
        Node left, right;
        public Node(int num, int y, int x) {
            this.num = num;
            this.y = y;
            this.x = x;
            left = null; right = null;
        }

        public void setLeft(Node left) {
            this.left = left;
        }

        public void setRight(Node right) {
            this.right = right;
        }

        @Override
        public int compareTo(Node o) {
            if(this.y == o.y) {
                return this.x - o.x;
            }
            return o.y - this.y;
        }
    }

    public static void main(String[] args) {

    }
}