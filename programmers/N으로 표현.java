import java.util.ArrayList;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;

/*
    N과 number가 주어졌을 때, 가장 적은 개수의 N으로만 이루어진 수식으로 number를 만드는 문제.

     <나의 풀이>
     풀지 못해서 구글링을 통해 아이디어를 얻었다.

     이 문제를 푸는 방법의 핵심은 k개의 N으로 만들어낼 수 있는 수들을 기억해서, 재활용하는 것이다.
     예를 들어, N = 5라면
        1. 1개의 N으로 만들 수 있는 숫자는 5이다.
        2. 2개의 N으로 만들 수 있는 숫자는 55, 10, 0, 1, 25이다. (단순 나열, 덧셈, 뺄셈, 나눗셈, 곱셈 연산으로 인한 결과)
        3. 3개의 N으로 만들 수 있는 숫자는 1번과 2번의 결과의 모든 가능한 사칙연산 결과이다.
        4. ...
     이를 점화식으로 나타내보면, k개의 N으로 만들 수 있는 숫자를 a(k)이라 할 때,
     a(k) = { a(k-1) (사칙연산) a(1) } U { a(k-2) (사칙연산) a(2) } ... U { a(1) (사칙연산) a(k-1) }
     와 같은 식으로 표현된다.
 */

class ExpressAsN {
    public int solution(int N, int number) {

        if(N == number) {
            return 1;
        }

        int limit = 8;

        List<HashSet<Integer>> list = new ArrayList<>(limit);
        for(int i=0; i<limit; ++i) {
            HashSet<Integer> poss = new HashSet<>();
            int numSize = (int) Math.pow(10, i);
            int seqNum = 0;
            while(numSize > 0) {
                seqNum += N * numSize;
                numSize /= 10;
            }

            poss.add(seqNum);
            list.add(poss);
        }

        for(int i=1; i<limit; ++i) {
            HashSet<Integer> poss = list.get(i);

            for(int j=0; j<=i-1; ++j) {
                Iterator<Integer> aiter = list.get(j).iterator();


                while(aiter.hasNext()) {
                    Iterator<Integer> biter = list.get(i - j - 1).iterator();
                    int a = aiter.next();

                    while(biter.hasNext()) {
                        int b = biter.next();

                        System.out.println("a = " + a + " b = " + b);

                        int[] result = new int[4];
                        result[0] = a + b;
                        result[1] = a - b;
                        result[2] = a * b;
                        result[3] = b == 0 ? -1 : a / b;

                        for(int k=0; k<4; ++k) {
                            if(result[k] >= 0) {
                                poss.add(result[k]);
                            }
                        }
                    }
                }
            }
        }

        for(int i=0; i<limit; ++i) {
            HashSet<Integer> set = list.get(i);
            if(set.contains(number)) {
                return i + 1;
            }
        }

        return -1;
    }
}