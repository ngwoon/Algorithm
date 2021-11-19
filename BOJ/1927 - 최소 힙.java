import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

class MinHeap {

    static class Heap {
        private final long[] arr;
        private final int capacity;
        private int idx;

        Heap(int capacity) {
            this.capacity = capacity;
            arr = new long[capacity +1];
            idx = 0;
            for(int i = 1; i <= capacity; ++i)
                arr[i] = Long.MAX_VALUE;
        }

        public void add(long num) {
            arr[++idx] = num;
            int childIdx = idx;
            while(childIdx > 1) {
                int parentIdx = childIdx / 2;
                if(arr[childIdx] < arr[parentIdx]) {
                    long temp = arr[childIdx];
                    arr[childIdx] = arr[parentIdx];
                    arr[parentIdx] = temp;
                    childIdx /= 2;
                } else
                    break;
            }
        }

        public long poll() {
            if(idx == 0)
                return 0L;
            else {
                long ret = arr[1];

                arr[1] = arr[idx--];

                int targetIdx = 1;
                while(capacity >= targetIdx * 2 && targetIdx < idx) {
                    long left = arr[targetIdx * 2];
                    long right = targetIdx * 2 + 1 > capacity ? Long.MAX_VALUE : arr[targetIdx * 2 + 1];

                    long smaller = Math.min(left, right);
                    int smallerIdx = left == smaller ? targetIdx * 2 : targetIdx * 2 + 1;

                    if(smaller == Long.MAX_VALUE)
                        break;

                    if(smaller < arr[targetIdx]) {
                        long temp = arr[targetIdx];
                        arr[targetIdx] = arr[smallerIdx];
                        arr[smallerIdx] = temp;
                        targetIdx = smallerIdx;
                    } else
                        break;
                }

                return ret;
            }
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());

        Heap heap = new Heap(n);
        for(int i=0; i<n; ++i) {
            long num = Long.parseLong(br.readLine());
            if(num == 0) {
                bw.write(String.valueOf(heap.poll()));
                bw.write("\n");
            } else {
                heap.add(num);
            }
        }
        bw.flush();
    }
}