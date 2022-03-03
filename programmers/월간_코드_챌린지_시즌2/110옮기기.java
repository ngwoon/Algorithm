package 월간_코드_챌린지_시즌2;

class Move110 {
    public String[] solution(String[] s) {
        String[] ans = new String[s.length];
        int ansIdx = 0;
        for (String num : s) {
            StringBuilder sb = new StringBuilder(num);
            int count = 0;
            int idx = -1;
            int start = 0;
            while((idx = indexOf110(sb, start)) != -1) {
                sb.delete(idx, idx + 3);
                start = Math.max(idx - 2, 0);
                ++count;
            }
            sb.append("11");

            int insertIdx = sb.length() - 2;
            for(int i=0; i<sb.length() - 2; ++i) {
                if(sb.charAt(i) == '1' && sb.charAt(i+1) == '1' && sb.charAt(i+2) == '1') {
                    insertIdx = i;
                    break;
                }
            }

            while(count-- > 0) {
                sb.insert(insertIdx, "110");
            }

            sb.delete(sb.length() - 2, sb.length());

            ans[ansIdx++] = sb.toString();
        }
        return ans;
    }

    public int indexOf110(StringBuilder sb, int start) {
        int idx = -1;
        for(int i=start; i<sb.length() - 2; ++i) {
            if(sb.charAt(i) == '1' && sb.charAt(i+1) == '1' && sb.charAt(i+2) == '0') {
                idx = i;
                break;
            }
        }
        return idx;
    }
}