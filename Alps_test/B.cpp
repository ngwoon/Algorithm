//#include <iostream>
//
//using namespace std;
//
//int slTable[1001][1001]; // �� : �л� ��ȣ, �� : ���� ��ȣ (student lectrue table)
//int limit[1001]; // ���� �ο�
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
//	//1��, 2�� �����ٱ���
//	int lec; // ��û ����
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
//		//�ο� �ʰ� Ȯ��
//		//1�� �� �ʰ� �� 1�� ǥ��� ���̺� �ش� �� 0����
//		//2�� �� �ʰ� �� 2�� ǥ��� ���̺� �ش� �� 0����
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
//		cout << i << "�� �����ٱ��� ��" << endl;
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
//			cout << "���߾��";
//
//		cout << endl;
//		flag = 0;
//	}
//
//	system("pause");
//
//	return 0;
//}