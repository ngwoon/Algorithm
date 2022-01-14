package KAKAO_BLIND_RECRUITMENT_2022;

import java.util.*;

/*
    아이디 목록, 신고자 목록과 신고 기준이 주어졌을 때, 신고 결과 이메일을 받는 유저의 수를 구하는 문제.

    <나의 풀이>
    신고 누적이 K 이상일 때 신고가 접수되므로, a유저가 b유저를 신고한 내역을 b를 key로 하는 해시맵에 기록한다.
    이후 해시맵을 순회하면서 value의 크기가 k이상이면 해당 key유저는 신고되었다고 여길 수 있으므로, value에 저장되있는 유저들에게 이메일이 날아가야 한다.
    즉, value에 저장되어있는 유저들의 이메일 카운트를 늘려가면서 풀면 된다.
 */

class ReportResult {

    Map<String, Set<String>> reportedAndReporter;
    Map<String, Integer> resultMailCount;

    public int[] solution(String[] idList, String[] report, int k) {
        reportedAndReporter = new HashMap<>();
        resultMailCount = new HashMap<>();

        for (String id : idList) {
            reportedAndReporter.put(id, new HashSet<>());
            resultMailCount.put(id, 0);
        }

        for (String r : report) {
            String[] s = r.split(" ");
            Set<String> reporters = reportedAndReporter.get(s[1]);
            reporters.add(s[0]);
        }

        for (String id : idList) {
            Set<String> reporters = reportedAndReporter.get(id);
            if(reporters.size() >= k) {
                for (String reporter : reporters) {
                    resultMailCount.put(reporter, resultMailCount.get(reporter) + 1);
                }
            }
        }

        int[] ans = new int[idList.length];
        int idx = 0;
        for (String id : idList) {
            ans[idx++] = resultMailCount.get(id);
        }

        return ans;
    }
}