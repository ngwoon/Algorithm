import java.util.Arrays;

/*
   주어진 0 - 1000 범위의 정수 배열을 조합하여 만들 수 있는 가장 큰 수를 구하는 문제

   <나의 풀이>
   정수 배열을 문자열 배열로 바꾸고, 이를 일련의 규칙에 의거하여 정렬한 뒤 차례로 append한 값을 정답으로 리턴했다.
   여기서 일련의 규칙을 어떻게 규정할것인지가 중요한데, 처음에는 일반 문자열 정렬기준을 그대로 사용해보았다.
   일반적인 문자열 내림차순 정렬을 사용하면 아래와 같은 규칙으로 정렬된다.
       1. 길이가 짧은 문자열(이하 s)을 기준으로 첫 번째 문자부터 마지막까지 비교하며 큰 숫자가 먼저 나오는 문자열이 우선순위가 높다.
       2. 만약 s를 전부 순회했는데 동일했다면, 길이가 긴 문자열이 우선순위가 높다.
   위와 같은 정렬 방식을 그대로 따른다면, "321"과 "3"을 비교했을 때 "321"이 앞으로 오게 되므로 "3213"이 만들어진다. 하지만 "3321"이 더 큰 숫자이므로, 잘못된 값임을 알 수 있다.

   이를 방지하기 위해 커스텀 comparator를 만들어 정렬해야했다. 커스텀 comparator는 아래와 같은 정렬 규칙을 갖는다.
        1. 정렬할 두 문자열 a,b가 있을 때, a + b과 b + a를 정수로 치환한 값을 비교한다.
        2. a + b이 더 크다면 순서를 바꾸지 않고, b + a가 더 크다면 두 문자열의 순서를 바꾼다.

   주의해야 할 점은, 정수 배열의 모든 원소가 0일 경우, "000..." 과 같이 모든 자리수가 0인 문자열이 만들어질 수 있다. 이 경우는 따로 처리해주어야 한다.
 */

class LargestNumber {
    public static String solution(int[] numbers) {

        String[] numStrs = new String[numbers.length];
        int idx = 0;
        for (int number : numbers) {
            numStrs[idx++] = String.valueOf(number);
        }

        Arrays.sort(numStrs, (a, b) -> (b+a).compareTo(a+b));

        if(numStrs[0].equals("0")) {
            return "0";
        } else {
            StringBuilder sb = new StringBuilder();
            for (String numStr : numStrs) {
                System.out.println(numStr);
                sb.append(numStr);
            }

            return sb.toString();
        }
    }

    public static void main(String[] args) {
        int[] numbers = {290, 10, 90, 29};

        String solution = solution(numbers);
        System.out.println(solution);
    }
}