package 카카오_채용연계형_인턴쉽_2021;

import java.util.ArrayList;
import java.util.List;

/*
    시험장의 연결 상태와 각 시험장의 트래픽이 주어졌을 때, 시험장을 그룹핑한 뒤 최대 트래픽을 갖는 그룹의 최소 트래픽을 구하는 문제.

    <나의 풀이>
    풀지 못하여 구글링을 통해 아이디어를 얻었다.

    이 문제를 통해 새로운 두 가지 개념을 접했다.

    첫 번째로 트리dp이다. 트리도 그래프의 일종이므로 dp를 활용할 수 있다.
    일반적으로 k번 노드를 포함한 값을 dp[k]로 나타내며, k번 노드의 자식과의 관계를 점화식으로 표현한다.

    두 번째는 파라메트릭 서치이다. 이분탐색의 개념을 응용한 것이다. 참고한 블로그에 따르면
    파라메트릭 서치는 "최적화" 문제를 "결정" 문제로 바꾸어 풀이할 수 있게 하는 효과가 있다.
    ex) 어떠한 범위 내에서 특정 값 k를 찾는 문제는 이분탐색으로 풀이한다.
        만약 어떠한 범위 내에서 최대값의 최소값이 k이하가 되도록 하는 범위를 찾는다면, 이 때 파라메트릭 서치를 활용하여
        k를 이분탐색의 mid와 같이 생각하고, 각 mid에 대해 "어떠한 범위 내에서 최대값의 최소값이 mid이하가 될 수 있는가?" 를 판단한다.

    이 문제도 트래픽이 최대인 그룹의 트래픽의 최솟값을 찾는 문제이므로, "최적화" 문제라고 볼 수 있다. 이를 파라메트릭 서치를 활용해 "결정" 문제로 바꾼다.
    아울러 트리 dp를 활용하는데, 2차원 배열을 사용한다.
    dp[k][0] = k번 노드를 루트로 하는 서브트리 내의 그룹 개수
    dp[k][1] = k번 노드를 포함하는 그룹의 트래픽 합

    점화식은 아래와 같다.
        1. 왼쪽(j), 오른쪽(i) 자식 모두 있다면, dp[k][1] = traffic[k] + dp[j][1] + dp[i][1] 이고,
            dp[k][0] = dp[j][0] + dp[i][0] - 1이다. (단, mid보다 크면 안된다.)
        2. 1번이지만 그 값이 mid보다 크거나, 왼쪽, 오른쪽 중 하나만 있다면, dp[k][1] = traffic[k] + min(dp[j][1], dp[i][1]) 이고,
            dp[k][0] = dp[i or j][1] 이다. (단, mid보다 크면 안된다.)
        3. 2번이지만 그 값이 mid보다 크거나, 자식이 없다면 dp[k][1] = traffic[k]이고, dp[k][0] = 1이다. (단, mid보다 크면 안된다.)
        4. 만약 3번까지 해당하지 않는다면, 현재 설정된 mid가 최대 트래픽의 최솟값이 될 수 없음을 의미한다. 즉, mid의 재설정이 필요하다.

    파라메트릭 서치로 mid를 설정하면서, 매번 설정된 mid에 대해 트리를 후위 탐색하면서 위와 같은 방식으로 dp를 채우고, 가능 여부를 판단하여 문제를 풀 수 있다.
 */

class DividingExamRoom {

    List<Node> tree;
    int[][] dp;
    int n, gk;
    int IMP = Integer.MAX_VALUE;
    int ans = IMP;

    public int solution(int k, int[] num, int[][] links) {

        n = num.length; gk = k;
        tree = new ArrayList<>(n);
        boolean[] checkRoot = new boolean[n];
        int sum = 0;
        for (int i=0; i<n; ++i) {
            int left = links[i][0];
            int right = links[i][1];
            if(left != -1) {
                checkRoot[left] = true;
            }
            if(right != -1) {
                checkRoot[right] = true;
            }
            int traffic = num[i];
            tree.add(new Node(traffic, left, right));
            sum += traffic;
        }

        int root = -1;
        for(int i=0; i<n; ++i) {
            if(!checkRoot[i]) {
                root = i;
                break;
            }
        }

        dp = new int[n][2];

        int low = sum / k;
        int high = sum;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(postOrder(root, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }

    public boolean postOrder(int cur, int traffic) {

        Node node = tree.get(cur);
        int left = node.left;
        int right = node.right;
        int curTraffic = node.traffic;

        boolean childResult = true;
        if(left != -1) {
            childResult = childResult & postOrder(left, traffic);
        }
        if(right != -1) {
            childResult = childResult & postOrder(right, traffic);
        }
        if(!childResult) {
            return false;
        }

        if(left == -1 && right == -1) {
            if(curTraffic > traffic) {
                return false;
            } else {
                dp[cur][1] = curTraffic;
                dp[cur][0] = 1;
            }
        } else if(left == -1 || right == -1) {
            int child = left != -1 ? left : right;
            int res = twoNode(cur, child, traffic);
            if(res == IMP) {
                if(curTraffic > traffic) {
                    return false;
                } else {
                    dp[cur][1] = curTraffic;
                    dp[cur][0] = dp[child][0] + 1;
                }
            } else {
                dp[cur][0] = dp[child][0];
            }
        } else {
            int res = threeNode(cur, left, right, traffic);
            if(res == IMP) {
                int smallerChild = dp[left][1] < dp[right][1] ? left : right;
                res = twoNode(cur, smallerChild, traffic);
                if(res == IMP) {
                    if(curTraffic > traffic) {
                        return false;
                    } else {
                        dp[cur][1] = curTraffic;
                        dp[cur][0] = dp[left][0] + dp[right][0] + 1;
                    }
                } else {
                    dp[cur][0] = dp[left][0] + dp[right][0];
                }
            } else {
                dp[cur][0] = dp[left][0] + dp[right][0] - 1;
            }
        }

        return dp[cur][0] <= gk;
    }

    public int threeNode(int parent, int left, int right, int traffic) {
        int parentTraffic = tree.get(parent).traffic;
        if(parentTraffic + dp[left][1] + dp[right][1] <= traffic) {
            return dp[parent][1] = parentTraffic + dp[left][1] + dp[right][1];
        } else {
            return dp[parent][1] = IMP;
        }
    }

    public int twoNode(int parent, int child, int traffic) {
        int parentTraffic = tree.get(parent).traffic;
        if(parentTraffic + dp[child][1] <= traffic) {
            return dp[parent][1] = parentTraffic + dp[child][1];
        } else {
            return IMP;
        }
    }

    static class Node {
        int traffic, left, right;
        public Node(int traffic, int left, int right) {
            this.traffic = traffic;
            this.left = left;
            this.right = right;
        }
    }
}