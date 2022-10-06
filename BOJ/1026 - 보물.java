import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Collections;
import java.util.PriorityQueue;

import static java.lang.Integer.parseInt;

class sfdf {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    int n = parseInt(br.readLine());
    String[] aSplited = br.readLine().split(" ");
    String[] bSplited = br.readLine().split(" ");

    int[] a = new int[n];
    int[] b = new int[n];

    for (int i=0; i<n; ++i) {
      a[i] = parseInt(aSplited[i]);
      b[i] = parseInt(bSplited[i]);
    }

    PriorityQueue<Integer> apq = new PriorityQueue<>(Collections.reverseOrder());
    PriorityQueue<Integer> bpq = new PriorityQueue<>();

    for (int i=0; i<n; ++i) {
      apq.add(a[i]);
      bpq.add(b[i]);
    }

    int sum = 0;
    while(!apq.isEmpty()) {
      sum += apq.poll() * bpq.poll();
    }

    bw.write(String.valueOf(sum));
    bw.flush();
  }
}