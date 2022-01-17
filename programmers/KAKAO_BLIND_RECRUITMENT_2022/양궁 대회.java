package KAKAO_BLIND_RECRUITMENT_2022;

/*
    상대의 양궁 결과와 화살 개수가 주어질 때, 상대를 가장 큰 점수차로 이기는 경우 중 가장 낮은 점수를 맞춘 화살의 개수가 가장 많은 경우를 구하는 문제.

    <나의 풀이>
    풀지 못해서 구글링을 통해 아이디어를 얻었다.
    단순히 완전 탐색으로 풀려고 하면, 0~10점까지 총 n개의 화살을 꽂는 경우의 수는 최대 11^10이므로 시간초과가 난다.
    다만, 특정 점수판에 상대보다 1개 더 많은 화살을 꽂으면 점수를 얻고, 그렇지 않으면 점수를 얻지 못하므로 각 점수마다
        * 상대보다 1개 더 많이 꽂거나
        * 아예 꽂지 않거나
    두 가지 경우로 경우의 수를 줄일 수 있다.
    즉, 총 경우의 수는 2^11이므로, 시간초과 없이 풀 수 있다.

    문제 목표는
        1. 상대와의 점수 차가 가장 많이 나는 경우를 구한다.
        2. 그러한 경우가 여러가지일 경우, 가장 낮은 점수를 가장 많이 맞춘 경우를 반환한다.
    이다. 이 조건에 맞게 정답 배열을 갱신해주면 된다. (화살이 남을 경우 0점에 몰아서 쏴버리면 됨)
 */

class Archery {

    int[] ginfo;
    int[] ans;
    int ansScoreGap;

    public int[] solution(int n, int[] info) {

        ginfo = new int[11];
        for(int i=0; i<11; ++i) {
            ginfo[i] = info[10-i];
        }
        ans = new int[11];

        dfs(0, n, new int[11]);
        if(ansScoreGap == 0) {
            ans = new int[1];
            ans[0] = -1;
        } else {
            for(int i=0; i<5; ++i) {
                int temp = ans[i];
                ans[i] = ans[10-i];
                ans[10-i] = temp;
            }
        }
        return ans;
    }

    public void dfs(int idx, int n, int[] target) {
        if(idx == 11) {
            if(n > 0) {
                target[0] += n;
            }

            int myScore = 0;
            int yourScore = 0;
            for(int i=0; i<11; ++i) {
                if(ginfo[i] < target[i]) {
                    myScore += i;
                } else if(ginfo[i] > 0) {
                    yourScore += i;
                }
            }

            int scoreGap = myScore - yourScore;

            if(scoreGap > 0) {
                if(scoreGap > ansScoreGap) {
                    renewAns(target);
                    ansScoreGap = scoreGap;
                } else if(scoreGap == ansScoreGap) {
                    for(int i=0; i<11; ++i) {
                        if(ans[i] > target[i]) {
                            break;
                        } else if(ans[i] < target[i]) {
                            renewAns(target);
                            break;
                        }
                    }
                }
            }

            if(n > 0) {
                target[0] -= n;
            }
            return;
        }

        dfs(idx+1, n, target);
        if(n > ginfo[idx]) {
            target[idx] = ginfo[idx] + 1;
            dfs(idx+1, n-target[idx], target);
            target[idx] = 0;
        }
    }

    public void renewAns(int[] target) {
        for(int i=0; i<11; ++i) {
            ans[i] = target[i];
        }
    }
}