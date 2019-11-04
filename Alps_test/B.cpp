//#include <iostream>
//
//using namespace std;
//
//int slTable[1001][1001]; // 행 : 학생 번호, 열 : 과목 번호 (student lectrue table)
//int limit[1001]; // 제한 인원
//int now[1001];
//
//int main(void)
//{
//	int pSize, lSize;
//
//	cin >> pSize >> lSize;
//
//	for (int i = 1; i < pSize + 1; i++)
//	{
//		for (int j = 1; j < lSize + 1; j++)
//			slTable[i][j] = 0;
//	}
//
//	for (int i = 1; i < lSize + 1; i++)
//		cin >> limit[i];
//
//	//1차, 2차 수강바구니
//	int lec; // 신청 과목
//	for (int i = 1; i < 3; i++)
//	{
//		for(int j=1; j<pSize + 1; j++)
//		{
//			while (true)
//			{
//				cin >> lec;
//				if (lec == -1)
//					break;
//
//				slTable[j][lec] = i;
//
//				now[lec]++;
//			}
//		}
//
//		//인원 초과 확인
//		//1차 때 초과 시 1로 표기된 테이블 해당 열 0으로
//		//2차 때 초과 시 2로 표기된 테이블 해당 열 0으로
//		for (int j = 1; j < lSize + 1; j++)
//		{
//			if (now[j] > limit[j])
//			{
//				for (int k = 1; k < pSize + 1; k++)
//				{
//					if (slTable[k][j] == i)
//						slTable[k][j] = 0;
//				}
//			}
//		}
//
//		/*cout << "===============" << endl;
//		cout << i << "차 수강바구니 끝" << endl;
//		for (int i = 1; i < pSize + 1; i++)
//		{
//			for (int j = 1; j < lSize + 1; j++)
//				cout << slTable[i][j] << " ";
//
//			cout << endl << endl;
//		}*/
//	}
//
////	cout << "<Result>" << endl;
//	int flag = 0;
//	for (int i = 1; i < pSize + 1; i++)
//	{
//		for (int j = 1; j < lSize + 1; j++)
//		{
//			if (slTable[i][j] != 0)
//			{
//				cout << j << " ";
//				flag = 1;
//			}
//		}
//		if (flag == 0)
//			cout << "망했어요";
//
//		cout << endl;
//		flag = 0;
//	}
//
//	system("pause");
//
//	return 0;
//}