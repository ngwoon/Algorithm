import java.io.*;
import java.util.StringTokenizer;

import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;

/*
    노드가 N개인 K진 완전 트리가 있을 때, 두 노드 x와 y 사이의 거리를 구하는 문제.

    <나의 풀이>
    이진 트리는 배열로 표현 가능하다. m번 노드의 자식 노드는 배열 인덱스 2m 과 2m + 1에 위치한다.
    이 특성을 k진 트리에 적용해보면, k진 트리의 m번 노드의 자식 노드는 배열 인덱스 km-k+2, km-k+3 ... km, km + 1 에 위치한다.

    이 문제는 두 노드 간 거리를 구하는 문제이므로, 두 노드의 최소 공통 부모가 어디인지를 찾으면 된다.
    최소 공통 부모를 p라고 할 때, 두 노드 x, y 간 거리는 (p - x 사이 간선의 수) + (p - y 사이 간선의 수) 로 나타낼 수 있다.

    필자는 두 노드 x, y 각각에 대해 해당 노드부터 root 노드까지의 path를 먼저 구했다.
    x의 path를 px, y의 path를 py라고 할 때, px와 py 배열의 마지막 인덱스에 root 노드가 저장되어있을 것이다.
    따라서 이 배열들의 마지막 인덱스부터 인덱스 크기를 줄이는 방향으로 순차 탐색하면서, 두 배열 요소가 달라지는 시점의 직전 노드가 두 노드의 최소 공통 부모라고 인식하여 문제를 풀었다.
    path 배열의 크기는 k진 트리의 최대 높이, logN으로 잡으면 된다.

    주의할 점이 하나 있는데, k=1일 경우 skewed tree 형태가 된다.
    이 때는 위와 같은 방법을 사용하면 부모를 구하는 시간복잡도가 O(n)이 되므로, 시간초과 혹은 메모리초과가 난다.
    따라서 k=1일 경우는 코너 케이스로 빼서, 단순히 거리를 구하고자 하는 두 노드의 차를 구해주면 된다.
 */

class KTree {

    static long n;
    static int k, q;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer stzr = new StringTokenizer(br.readLine());
        n = parseLong(stzr.nextToken());
        k = parseInt(stzr.nextToken());
        q = parseInt(stzr.nextToken());

        long[] ap = new long[51];
        long[] bp = new long[51];
        for(int i=0; i<q; ++i) {
            stzr = new StringTokenizer(br.readLine());
            long a = parseLong(stzr.nextToken());
            long b = parseLong(stzr.nextToken());

            if(k == 1) {
                bw.write(Math.abs(a - b) + "\n");
                continue;
            }

            int apSize = seek(a, ap);
            int bpSize = seek(b, bp);

            int aIdx = apSize-1, bIdx = bpSize-1;
            while(aIdx >= 0 && bIdx >= 0 && ap[aIdx] == bp[bIdx]) {
                aIdx -= 1; bIdx -= 1;
            }
            aIdx += 1; bIdx += 1;

            int ans = aIdx + bIdx;
            bw.write(ans + "\n");
        }
        bw.flush();
    }

    public static int seek(long node, long[] history) {
        int hIdx = 0;
        while(node > 1) {
            history[hIdx++] = node;
            long rest = node % k;
            if(rest == 1) {
                node -= 1;
            } else if(rest > 1){
                node += (k - rest);
            }
            node /= k;
        }
        history[hIdx++] = node;

        return hIdx;
    }
}