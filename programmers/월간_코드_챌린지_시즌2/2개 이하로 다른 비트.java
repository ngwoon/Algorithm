package 월간_코드_챌린지_시즌2;

class DiffAtMost2Bits {

    public long[] solution(long[] numbers) {
        long[] ans = new long[numbers.length];
        int ansIdx = 0;
        for (long number : numbers) {
            long next = number + 1;
            String numB = Long.toBinaryString(number);
            String nextB = Long.toBinaryString(next);
            int diff = calcDiff(numB, nextB);

            if(diff <= 2) {
                ans[ansIdx] = next;
            } else {
                ans[ansIdx] = calcLowerBaseNum(numB, nextB, diff);
            }

            ++ansIdx;
        }

        return ans;
    }

    public int calcDiff(String a, String b) {
        int diff = 0;
        int aIdx = a.length() - 1;
        int bIdx = b.length() - 1;
        while(aIdx >= 0 && bIdx >= 0) {
            if(a.charAt(aIdx) != b.charAt(bIdx)) {
                ++diff;
            }
            --aIdx; --bIdx;
        }

        return a.length() < b.length() ? diff + 1 : diff;
    }

    public long calcLowerBaseNum(String a, String b, int diff) {
        char[] bcharr = b.toCharArray();
        int idx = b.length() - 1;
        while(diff > 2) {
            bcharr[idx--] = '1';
            --diff;
        }
        return Long.parseLong(String.valueOf(bcharr), 2);
    }
}