package 카카오_블라인드_채용_2020;
/*
    "균형잡힌 괄호 문자열"이 주어졌을 때, 문제 조건에 맞게 "올바른 괄호 문자열" 로 변환하는 문제.

    <나의 풀이>
    문제에서 알고리즘을 제시했기 때문에, 그 알고리즘을 그대로 코드로 나타내면 되는 문제이다.
 */

class ParenthesisConversion {

    public String solution(String p) {

        return convert(p);
    }

    public String convert(String str) {

        if(str.length() == 0) {
            return str;
        }

        int open = 0, close = 0;
        boolean isBalanced = true;
        int uIdx = 0;
        for(int i=0; i<str.length(); ++i) {
            if(str.charAt(i) == '(') {
                ++open;
            } else {
                ++close;
            }
            if(open == close) {
                uIdx = i;
                break;
            } else if(open < close) {
                isBalanced = false;
            }
        }

        String u = str.substring(0, uIdx+1);
        String v = str.substring(uIdx+1);
        if(isBalanced) {
            return u + convert(v);
        } else {
            return "(" + convert(v) + ")" + reverseParentheses(u.substring(1, u.length() - 1));
        }
    }

    public String reverseParentheses(String str) {

        StringBuilder sb = new StringBuilder();
        for(int i=0; i<str.length(); ++i) {
            if(str.charAt(i) == '(') {
                sb.append(")");
            } else {
                sb.append("(");
            }
        }
        return sb.toString();
    }
}