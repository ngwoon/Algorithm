//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//char str[101];
//char leftkey[] = { 'q','w','e','r','t','y','a','s','d','f','g','z','x','c','v','b' };
//char rightkey[] = { 'u','i','o','p','h','j','k','l','n','m' };
//
//int main(void)
//{
//	char c;
//	int temp = 0;
//	while (true)
//	{
//		c = getchar();
//		if (c == '\n')
//			break;
//
//		str[temp++] = c;
//	}
//	str[temp] = '\0';
//
//	int sCnt = 0;
//	int lhand = 0, rhand = 0;
//	int i = 0;
//	while (str[i] != '\0')
//	{
//		if (str[i] == ' ')
//		{
//			sCnt++;
//			i++;
//			continue;
//		}
//		if (isupper(str[i]))
//			sCnt++;
//
//		//check left
//		for (int j = 0; j < 16; j++)
//		{
//			if (tolower(str[i]) == leftkey[j])
//				lhand++;
//		}
//		for (int j = 0; j < 10; j++)
//		{
//			if (tolower(str[i]) == rightkey[j])
//				rhand++;
//		}
//
//		i++;
//	}
//
//	while (true)
//	{
//		if (sCnt == 0)
//			break;
//		if (rhand > lhand)
//		{
//			sCnt--;
//			lhand++;
//		}
//		else if(rhand < lhand)
//		{
//			sCnt--;
//			rhand++;
//		}
//		else
//		{
//			sCnt--;
//			lhand++;
//		}
//	}
//
//	cout << lhand << " " << rhand;
//		
//	system("pause");
//
//	return 0;
//}