package 카카오_블라인드_채용_2018;
/*
    다트 문자열이 주어졌을 때, 문제 조건에 맞게 다트 게임 점수를 계산하는 문제

    <나의 풀이>
    특별한 알고리즘이 필요한 문제는 아니다.
    순차적으로 문자열을 탐색하면서, 숫자와 보너스, 옵션을 잘 구분하여 각각의 효과를 적용하면 된다.
 */

class DartGame {

    public int solution(String dartResult) {

        int[] nums = new int[3];
        int size = 0;
        for(int i=0; i<dartResult.length(); ++i) {
            char c = dartResult.charAt(i);
            if('0' <= c && c <= '9') {
                if(c == '1') {
                    if(i != dartResult.length() - 1 && dartResult.charAt(i+1) == '0') {
                        nums[size++] = 10;
                        ++i;
                    } else {
                        nums[size++] = c-'0';
                    }
                } else {
                    nums[size++] = c-'0';
                }
            }
        }

        int numIdx = -1;
        for(int i=0; i<dartResult.length(); ++i) {
            char c = dartResult.charAt(i);
            if(c == 'S' || c == 'D' || c == 'T') {
                if(c != 'S') {
                    nums[numIdx] = (int) Math.pow(nums[numIdx], c == 'D' ? 2 : 3);
                }
            } else if(c == '*' || c == '#') {
                if(c == '*') {
                    nums[numIdx] *= 2;
                    if(numIdx > 0) {
                        nums[numIdx-1] *= 2;
                    }
                } else {
                    nums[numIdx] = -nums[numIdx];
                }
            } else {
                ++numIdx;
                if(i != dartResult.length() - 1 && dartResult.charAt(i+1) == '0') {
                    ++i;
                }
            }
        }

        int ans = 0;
        for(int i=0; i<size; ++i) {
            ans += nums[i];
        }

        return ans;
    }
}