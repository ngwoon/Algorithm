import java.util.Arrays;

/*
    어느 과학자의 각 논문의 인용 횟수가 주어졌을 때, h-index를 구하는 문제.

    <나의 풀이>
    citations의 오름차순 정렬 + 이중 이진 탐색으로 문제를 해결했다.

    1. h를 찾는 이진 탐색
    citations의 가장 작은 원소와 가장 큰 원소를 low, high로 하는 이진 탐색.
    mid를 h로 여기고 2번 과정의 결과에 따라 low, high를 조정하며 h의 최대값을 찾는다.

    2. citations내에서 h의 lower bound를 찾는 이진 탐색
    1번 과정에서 구한 h를 갖고, citations내에서 h보다 크거나 같으면서 가장 작은 값이 위치한 인덱스를 찾아 리턴해준다.

    3. h로써의 조건을 만족하는지 검사
    h-index가 되기 위해서는 h와 크거나 같은 인용횟수가 h개 이상이고, 나머지 논문의 인용횟수가 h보다 작거나 같아야 한다.
    2번 과정에서 구한 인덱스를 기준으로 이를 비교할 수 있다.
    조건에 만족하면 h의 최대값을 갱신해두고 low = h + 1로 설정하여 더 높은 h가 있는지 확인한다.
    조건에 부합하지 않으면 high = h - 1로 설정하여 더 낮은 h값은 가능한지 확인한다.


    <더 나은 풀이>
    나의 풀이 방식을 살펴보면,
    - 오름차순 정렬 = O(NlogN)
    - 이중 이진 탐색 = O(NlogN + logN * logK) (K = 인용 횟수)
    - 전체적인 시간복잡도 = O(2NlogN + logN * logK) 이다.

    다른 사람의 풀이 중, 오름차순 정렬 이후 앞에서부터 순차적으로 탐색했을 때, h의 최대값이 증가하다가 어느 순간 h의 조건에 맞지 않는 인용횟수가
    등장한다는 특성을 살려서 풀이한 방법이 있었다.
    시간복잡도를 생각해본다면, O(NlogN + N) 이므로 나의 풀이보다 더 효율적인 풀이라고 볼 수 있다.
 */

class HIndex {
    public int solution(int[] citations) {

        Arrays.sort(citations);

        int answer = citations[0];

        int citeSize = citations.length;
        int low = 0, high = citations[citeSize - 1];
        while(low <= high) {
            int h = (low + high) / 2;
            int idx = lowerBound(citations, h);
            if(citeSize - idx + 1 >= h && idx + 1 <= h) {
                answer = h;
                low = h + 1;
            } else {
                high = h - 1;
            }
        }

        return answer;
    }

    public int lowerBound(int[] citations, int std) {
        int low = 0, high = citations.length - 1;
        int ret = -1;
        while(low <= high) {
            int mid = (low + high) / 2;
            int midVal = citations[mid];
            if(midVal < std) {
                low = mid + 1;
            } else {
                ret = mid;
                high = mid - 1;
            }
        }

        return ret;
    }
}