//#include <iostream>
//#include <vector>
//
///*
//��ŸƮ�� �������� dp�� �����.
//
//dp[i][j]���� i�� ���� ���� ���� �ǹ�, j�� i��° ����� j�� ����� ���� ���� �ǹ��Ѵ�.
//��, dp[2][2]�� 2���� ������ ���� ��, 2�� ����� �������� ���� ��� �� �� ������ �ּڰ��̴�.
//
//Ǯ�� ���
//(k=1, k<=i, k++) sum += dp[k][m] (��, m != j)
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
//	//dp �ױ� ����
//	int sub; // ��ŸƮ�� ���� �� ����� �ó��� - ��ũ�� �ó���
//	for (int i = 2; i < pSize + 1; i++)
//	{
//		for (int j = 1; j < pSize + 1; j++)
//		{
//			// dp[i][j] ���� �� dp[i-1]�� Ȯ��
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