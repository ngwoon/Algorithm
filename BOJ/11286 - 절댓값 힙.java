import java.io.*;

class AbsoluteHeap {
    static class ABHeap {
        private int[] arr;
        private int idx;

        public ABHeap(int size) {
            arr = new int[size];
            idx = 0;
        }

        public void add(int num) {
            arr[++idx] = num;

            int childIdx = idx;
            while(childIdx > 1) {
                int parentIdx = childIdx / 2;
                int parent = arr[parentIdx];
                int child = arr[childIdx];
                int parentAbs = Math.abs(parent);
                int childAbs = Math.abs(child);
                if(parentAbs > childAbs || (parentAbs == childAbs && parent > child)) {
                    int temp = arr[childIdx];
                    arr[childIdx] = arr[parentIdx];
                    arr[parentIdx] = temp;
                    childIdx = childIdx / 2;
                } else
                    break;
            }
        }

        public int poll() {
            if(idx < 1)
                return 0;

            int ret = arr[1];
            arr[1] = arr[idx--];

            int parentIdx = 1;
            while(parentIdx < idx) {
                int parent = arr[parentIdx];
                int parentAbs = Math.abs(parent);
                int leftIdx = parentIdx * 2;
                int rightIdx = parentIdx * 2 + 1;

                if(leftIdx > idx)
                    break;
                else if(rightIdx > idx) {
                    int left = arr[leftIdx];
                    int leftAbs = Math.abs(left);

                    if(parentAbs > leftAbs || (parentAbs == leftAbs && parent > left)) {
                        int temp = arr[parentIdx];
                        arr[parentIdx] = arr[leftIdx];
                        arr[leftIdx] = temp;
                        parentIdx = leftIdx;
                    } else
                        break;
                } else {
                    int left = arr[leftIdx];
                    int right = arr[rightIdx];
                    int leftAbs = Math.abs(left);
                    int rightAbs = Math.abs(right);
                    int smaller, smallerAbs, smallerIdx;
                    if(leftAbs < rightAbs) {
                        smaller = left; smallerAbs = leftAbs; smallerIdx = leftIdx;
                    } else if(leftAbs > rightAbs) {
                        smaller = right; smallerAbs = rightAbs; smallerIdx = rightIdx;
                    } else {
                        if(left <= right) {
                            smaller = left; smallerAbs = leftAbs; smallerIdx = leftIdx;
                        } else {
                            smaller = right; smallerAbs = rightAbs; smallerIdx = rightIdx;
                        }
                    }

                    if(parentAbs > smallerAbs || (parentAbs == smallerAbs && parent > smaller)) {
                        int temp = arr[parentIdx];
                        arr[parentIdx] = smaller;
                        arr[smallerIdx] = temp;
                        parentIdx = smallerIdx;
                    } else
                        break;
                }
            }

            return ret;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());
        ABHeap heap = new ABHeap(n);

        for(int i=0; i<n; ++i) {
            int num = Integer.parseInt(br.readLine());
            if(num != 0) {
                heap.add(num);
            } else {
                bw.write(String.valueOf(heap.poll()) + "\n");
            }
        }

        bw.flush();
    }
}