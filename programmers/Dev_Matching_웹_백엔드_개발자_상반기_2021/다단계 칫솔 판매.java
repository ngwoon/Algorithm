package Dev_Matching_웹_백엔드_개발자_상반기_2021;

import java.util.HashMap;
import java.util.Map;

/*
    다단계 조직도와 조직원 별 판매량이 주어질 때, 조직원들의 수익을 계산하는 문제.

    <나의 풀이>
    이 문제는 수익이 자식에서 부모 노드로 전파되는 방식이므로, 자식 - 부모 쌍을 저장하는 Map을 활용했다.
    어느 자식 노드가 칫솔을 판매하여 수익을 냈다면, 그 수익을 문제 조건에 따라 10%씩 부모에게 전파하는 방식이다.

    주의할 점은, 수익을 분배하는 과정에서 소수점 아래 원을 버림하기 때문에, seller 배열에서 중복된 이름이 있더라도 따로 계산을 해야 한다.
    이를 함께 묶어서 한 번에 계산하게되면 10%를 계산하는 과정에서 문제 의도와는 다른 수익 분배가 이루어질 수 있다.
 */

class MultiLevelToothBrushSales {

    Map<String, String> organization;
    Map<String, Integer> revenue;

    public int[] solution(String[] enroll, String[] referral, String[] seller, int[] amount) {
        organization = new HashMap<>();
        revenue = new HashMap<>();

        for(int i=0; i<enroll.length; ++i) {
            organization.put(enroll[i], referral[i]);
            revenue.put(enroll[i], 0);
        }

        for(int i=0; i<seller.length; ++i) {
            distribute(seller[i], amount[i] * 100);
        }

        int[] ans = new int[enroll.length];
        for(int i=0; i<enroll.length; ++i) {
            ans[i] = revenue.get(enroll[i]);
        }
        return ans;
    }

    public void distribute(String person, int money) {
        if("-".equals(person) || money == 0) {
            return;
        }

        int toSuperior = (int) (money * 0.1);
        int mine = money - toSuperior;
        revenue.put(person, revenue.get(person) + mine);
        distribute(organization.get(person), toSuperior);
    }
}