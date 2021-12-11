package 네이버_라인_핀테크;

class A {
    public int solution(int[] arr) {
        long sum = 0;
        int ans = 0;
        for (int i : arr) {
            sum += i;
            if(sum > 0) {
                ++ans;
            }
        }
        return ans;
    }
}