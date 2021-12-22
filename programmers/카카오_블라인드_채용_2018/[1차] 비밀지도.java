package 카카오_블라인드_채용_2018;

/*
    암호화된 두 지도가 주어질 때, 문제 조건에 맞게 두 지도를 합친 원래 지도를 반환하는 문제.

    <나의 풀이>
    특별한 알고리즘이 필요한 문제는 아니다.
    문제 조건을 보면, 두 지도를 합칠 때 규칙이 있다.
        * 0 + 0 -> 0
        * 1 + 0 or 0 + 1 -> 1
        * 1 + 1 -> 1
    위 규칙은 or 연산과 동일하므로, 두 지도의 같은 행을 or 연산한 결과를 갖고 문자열로 변환한 결과를 쌓으면 답이 된다.
 */

class SecretMap {
    public String[] solution(int n, int[] arr1, int[] arr2) {

        String[] ans = new String[n];
        for(int i=0; i<n; ++i) {
            String binaryLine = Integer.toBinaryString(arr1[i] | arr2[i]);
            StringBuilder sb = new StringBuilder(binaryLine);
            while(sb.length() < n) {
                sb.insert(0, "0");
            }

            StringBuilder ansSb = new StringBuilder();
            for(int j=0; j<n; ++j) {
                ansSb.append(sb.charAt(j) == '0' ? " " : "#");
            }

            ans[i] = ansSb.toString();
        }

        return ans;
    }
}