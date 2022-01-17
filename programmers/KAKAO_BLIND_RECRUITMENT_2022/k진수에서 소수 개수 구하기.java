package KAKAO_BLIND_RECRUITMENT_2022;

import java.util.Stack;

/*
    10진수와 k진수로 변환할 k가 주어질 때, 변환된 k진수에서 문제 조건에 맞는 소수의 개수를 구하는 문제.

    <나의 풀이>
    10진수를 k진수로 변환하고, 0+을 기준으로 파싱한 뒤 각 수가 10진수의 소수인지 판별하면 된다.
    단, 변환된 수가 int 범위를 넘을 수 있으므로 이 점을 주의해야 한다.
 */

class CountingPrimeNum {
    public int solution(int n, int k) {
        StringBuilder sb = new StringBuilder();
        Stack<Integer> stk = new Stack<>();
        while(n > 0) {
            int rest = n % k;
            stk.push(rest);
            n /= k;
        }
        while(!stk.isEmpty()) {
            sb.append(stk.pop());
        }

        String converted = sb.toString();
        String[] splited = converted.split("0+");
        int ans = 0;
        for (String s : splited) {
            if(isPrime(Long.parseLong(s))) {
                ++ans;
            }
        }

        return ans;
    }

    public boolean isPrime(long num) {
        if(num == 1) {
            return false;
        } else if(num == 2) {
            return true;
        }

        long limit = (long) Math.sqrt(num);
        for(long i=2; i<=limit; ++i) {
            if(num % i == 0) {
                return false;
            }
        }
        return true;
    }
}