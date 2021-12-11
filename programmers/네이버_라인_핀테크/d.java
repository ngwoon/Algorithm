package 네이버_라인_핀테크;

import java.util.HashMap;

class D {

    int n;
    int ans;
    int[][] gneeds;
    HashMap<Integer, Integer> needsBinary;

    public int solution(int[][] needs, int r) {

        n= needs[0].length; // 부품의 종류 개수
        gneeds = needs;
        needsBinary = new HashMap<>();

        for(int i=0; i<needs.length; ++i) {
            int binary = 0;
            for(int j=0; j<n; ++j) {
                if(needs[i][j] == 1) {
                    binary += Math.pow(2, j);
                }
            }
            needsBinary.put(binary, needsBinary.getOrDefault(binary, 0) + 1);
        }

        bruteForce(0, r, 0);

        return ans;
    }

    public void bruteForce(int idx, int r, int status) {

        if(idx == n || r == 0) {
            int selected = 0;
            for (int binary : needsBinary.keySet()) {
                if((binary & status) == binary) {
                    selected += needsBinary.get(binary);
                }
            }

            ans = Math.max(selected, ans);
            return;
        }

        for(int i=idx; i<=n-r; ++i) {
            bruteForce(i+1, r-1, status + (int) Math.pow(2, i));
        }
    }
}