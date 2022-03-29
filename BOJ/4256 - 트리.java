import java.io.*;
import java.util.*;

import static java.lang.Integer.parseInt;

/*
    트리의 전위순회, 중위순회가 주어졌을 때, 이 트리를 후위순회한 결과를 출력하는 문제.

    <나의 풀이>
    전위순회와 중위순회 로그를 보고 어떤 정보를 얻을 수 있는지를 먼저 파악해야한다.

    전위순회를 통해서 해당 트리의 루트 노드가 무엇인지를 알 수 있다.
    예를 들어, 3 2 1 4 라는 전위순회가 주어지면, 이 트리의 루트 노드는 3이다.

    트리의 루트와 중위순회를 알고 있다면, 루트 번호를 기준으로 왼쪽 서브트리를 구성하는 노드들과 오른쪽 서브트리를 구성하는 노드들을 알 수 있다.
    예를 들어, 3 2 1 4 5 라는 중위순회와 루트 노드가 1이라는 정보를 알고 있다면, 이 트리의 왼쪽 서브 트리 노드들은 3, 2이며, 오른쪽 서브 트리 노드들은 4, 5이다.

    따라서 이 문제는 전위 순회와 중위 순회를 분할정복하는 방식으로 풀 수 있다.
        1. 먼저 전위 순회를 보고 현재 트리의 루트 노드 번호를 알아낸다.
        2. 중위 순회에서 루트 노드를 기준으로 왼쪽 서브 트리와 오른쪽 서브 트리로 나눈다.
        3. 왼쪽 서브 트리, 오른쪽 서브 트리 각각 재귀를 통해 1 - 2번 로직을 반복한다.
    재귀함수에서 parent 인자를 받도록 해서, 재귀 함수에 들어올 때 마다 (= 서브 트리를 분할정복 할 때 마다) parent노드와 현재 서브 트리의 루트 노드를 연결해줌으로써 트리를 완성시킬 수 있다.

    이렇게 만들어진 트리를 후위 탐색한 결과가 정답이 된다.
 */

class TreeOrder {

    static List<List<Integer>> adj;
    static List<Integer> preOrderHistory;
    static List<Integer> inOrderHistory;
    static int n;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int t = parseInt(br.readLine());

        while(t-- > 0) {
            n = parseInt(br.readLine());
            String historyLine = br.readLine();

            String[] historyStrs = historyLine.split(" ");
            preOrderHistory = new ArrayList<>(n);
            for (String historyStr : historyStrs) {
                preOrderHistory.add(parseInt(historyStr));
            }

            historyLine = br.readLine();
            historyStrs = historyLine.split(" ");
            inOrderHistory = new ArrayList<>(n);
            for (String historyStr : historyStrs) {
                inOrderHistory.add(parseInt(historyStr));
            }

            adj = new ArrayList<>(n+1);
            for(int i=0; i<=n; ++i) {
                adj.add(new ArrayList<>());
            }

            divConq(0, n-1, 0, n-1, 0);

            int root = preOrderHistory.get(0);
            List<Integer> postOrderHistory = new ArrayList<>(n);
            postOrder(root, postOrderHistory);
            for (int node : postOrderHistory) {
                bw.write(node + " ");
            }
            bw.write("\n");
        }

        bw.flush();
    }

    public static void divConq(int preLeft, int preRight, int inLeft, int inRight, int parent) {
        int root = preOrderHistory.get(preLeft);
        if(parent != 0) {
            adj.get(parent).add(root);
        }

        if(preLeft == preRight) {
            return;
        }

        int inOrderRootIdx = -1;
        for(int i=inLeft; i<=inRight; ++i) {
            int inOrderCur = inOrderHistory.get(i);
            if(root == inOrderCur) {
                inOrderRootIdx = i;
                break;
            }
        }

        Set<Integer> leftSubTreeSet = null;
        Set<Integer> rightSubTreeSet = null;
        int leftSubTreeSize = inOrderRootIdx - inLeft;
        int rightSubTreeSize = inRight - inOrderRootIdx;
        if(leftSubTreeSize > 0) {
            leftSubTreeSet = new HashSet<>(inOrderHistory.subList(inLeft, inOrderRootIdx));
        }
        if(rightSubTreeSize > 0) {
            rightSubTreeSet = new HashSet<>(inOrderHistory.subList(inOrderRootIdx + 1, inRight + 1));
        }

        // inOrderHistory에서 추출한 leftsubtree 집합과 동일한 집합을 preOrderHistory에서 찾기
        if(leftSubTreeSet != null) {
            for(int i=preLeft+1; i<=preRight-leftSubTreeSize+1; ++i) {
                boolean isAllContained = true;
                int j;
                for(j=0; j<leftSubTreeSize; ++j) {
                    if(!leftSubTreeSet.contains(preOrderHistory.get(i+j))) {
                        isAllContained = false;
                        break;
                    }
                }
                if(isAllContained) {
                    divConq(i, i+j-1, inLeft, inOrderRootIdx-1, root);
                    break;
                }
            }
        }

        if(rightSubTreeSet != null) {
            // inOrderHistory에서 추출한 rightsubtree 집합과 동일한 집합을 preOrderHistory에서 찾기
            for(int i=preLeft+1; i<=preRight-rightSubTreeSize+1; ++i) {
                boolean isAllContained = true;
                int j;
                for(j=0; j<rightSubTreeSize; ++j) {
                    if(!rightSubTreeSet.contains(preOrderHistory.get(i+j))) {
                        isAllContained = false;
                        break;
                    }
                }
                if(isAllContained) {
                    divConq(i, i+j-1, inOrderRootIdx+1, inRight, root);
                    break;
                }
            }
        }
    }

    public static void postOrder(int cur, List<Integer> history) {
        for(int i=0; i<adj.get(cur).size(); ++i) {
            postOrder(adj.get(cur).get(i), history);
        }
        history.add(cur);
    }
}