import java.io.*;

import static java.lang.Integer.parseInt;

/*
    고객의 원하는 피자 크기와, 두 피자 A, B의 조각들이 주어질 때, 고객의 요청에 맞는 피자 크기를 제공할 수 있는 경우의 수를 구하는 문제.

    <나의 풀이>
    피자 A, B의 조각들을 고객에게 제공할 때, 반드시 연속된 조각을 조합해서 고객이 원하는 피자 크기를 맞춰야 한다.
    피자 조각의 개수가 각각 최대 1000이므로, 누적합을 활용해 각 피자의 연속된 피자 조각들의 크기를 구하는 방법으로 풀 수 있다.
    주의해야 할 점은, 누적합을 사용하지 않고 이전에 했던 덧셈 연산을 반복한다면, 시간복잡도가 O(n^3)이 되므로 시간초과가 난다.
 */

class SalesPizza {

    static int pizza;
    static int n, m;
    static int[] pa, pb;
    static int[] paSeq, pbSeq;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        pizza = parseInt(br.readLine());

        String varsLine = br.readLine();
        String[] varsStr = varsLine.split(" ");
        m = parseInt(varsStr[0]);
        n = parseInt(varsStr[1]);

        pa = new int[m];
        pb = new int[n];

        int paSum = 0, pbSum = 0;
        for(int i=0; i<m; ++i) {
            pa[i] = parseInt(br.readLine());
            paSum += pa[i];
        }
        for(int i=0; i<n; ++i) {
            pb[i] = parseInt(br.readLine());
            pbSum += pb[i];
        }

        paSeq = new int[1000001];
        pbSeq = new int[1000001];
        calcSeqSlices(m, paSeq, pa);
        calcSeqSlices(n, pbSeq, pb);
        paSeq[0] = 1; pbSeq[0] = 1;
        paSeq[paSum] = 1; pbSeq[pbSum] = 1;

        int ans = 0;
        for(int paCand=0; paCand<=pizza; ++paCand) {
            int pbCand = pizza-paCand;
            ans += paSeq[paCand] * pbSeq[pbCand];
        }

        bw.write(String.valueOf(ans));
        bw.flush();
    }

    public static void calcSeqSlices(int pSize, int[] seq, int[] slices) {
        for(int i=0; i<pSize; ++i) {
            int sum = 0;
            for(int j=0; j<pSize-1; ++j) {
                sum += slices[(i+j) % pSize];
                seq[sum] += 1;
            }
        }
    }
}