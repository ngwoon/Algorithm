//#include <iostream>
//#include <vector>
//
///*
//스타트팀 기준으로 dp를 만든다.
//
//dp[i][j]에서 i는 뽑은 팀원 수를 의미, j는 i번째 사람을 j번 사람을 뽑을 때를 의미한다.
//즉, dp[2][2]는 2명의 팀원을 뽑을 때, 2번 사람이 마지막에 뽑힐 경우 양 팀 전력의 최솟값이다.
//
//풀이 방법
//(k=1, k<=i, k++) sum += dp[k][m] (단, m != j)
//dp[i][j] = min(sum)
//*/
//
//using namespace std;
//
//#define INF 100000
//
//typedef struct data {
//	vector<int> picked;
//	int value;
//}DATA;
//
//int status[21][21];
//DATA dp[21][21];
//
//int main(void)
//{
//	int pSize;
//	int min = INF;
//	cin >> pSize;
//
//	for (int i = 1; i < pSize + 1; i++)
//	{
//		for (int j = 1; j < pSize + 1; j++)
//		{
//			cin >> status[i][j];
//			
//			if (i == 1)
//				dp[i][j].picked.push_back(i);
//
//			dp[i][j].value = 0;
//		}
//	}
//
//	//dp 쌓기 시작
//	int sub; // 스타트팀 선택 시 생기는 시너지 - 링크팀 시너지
//	for (int i = 2; i < pSize + 1; i++)
//	{
//		for (int j = 1; j < pSize + 1; j++)
//		{
//			// dp[i][j] 차례 때 dp[i-1]행 확인
//			int k;
//			for (k = 1; k < pSize + 1; k++)
//			{
//				for (int m = 0; m < dp[i][k].picked.size(); m++)
//				{
//					if (dp[i - 1][k].picked.at(m) == j)
//						continue;
//					
//					sub = 
//				}
//			}
//		}
//	}
//}