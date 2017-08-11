#define _CRT_SECURE_NO_WARNINGS 


//�ҳ��ַ����е�һ�γ������ε��ַ�
//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string str;
//	getline(cin, str);
//	int hashtable[256] = { 0 };
//	size_t Size = str.size();
//	for (size_t i = 0; i<Size; i++){
//		if ((str[i] >= 'a'&&str[i] <= 'z') || (str[i] <= 'Z'&&str[i] >= 'A'))
//			hashtable[str[i]]++;
//		if (hashtable[str[i]] == 3){
//			cout << str[i] << endl;
//			break;
//		}
//	}
//	return 0;
//}


//���֤��6 8 4����
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//int main()
//{
//	vector<string>  v;
//	string str;
//	while (getline(cin, str)){
//		v.push_back(str);
//		a++;
//	}
//	int Size = v.size();
//	for (size_t i = 0; i<Size; i++){
//		if (v[i].size()>6 && v[i][6] != ' '){
//			v[i].insert(6, 1, ' ');
//		}
//		if (v[i].size()>15 && v[i][15] != ' '){
//			v[i].insert(15, 1, ' ');
//		}
//	}
//	for (size_t i = 0; i < Size; i++)
//	{
//		cout << v[i] << endl;
//	}
//	return 0;
//}


//�����������1��5��10��20��50��100Ԫ��ֽ�ң�
//����ÿ�ֱ�ֵ���������㹻�࣬��д���������NԱ��NΪ0 - 10000�ķǸ��������Ĳ�ͬ��ϵĸ�����

#include <iostream>
#include <vector>
using namespace std;
int main()
{
	size_t aim;
	int arr[] = { 1, 5, 10, 20, 50, 100 };
	cin >> aim;
	vector<vector<int> > dp(sizeof(arr) / sizeof(arr[0]));
	for (size_t i = 0; i < dp.size(); i++)
	{
		dp[i].resize(aim + 1);
	}
	for (size_t i = 0; i < dp.size(); i++)
	{
		dp[i][0] = 1;
	}
	for (size_t i = 1; arr[0] * i <= aim; i++)
	{
		dp[0][arr[0] * i] = 1;
	}
	for (int i = 1; i < dp.size(); i++)
	{
		for (int j = 1; j <= aim; j++)
		{
			dp[i][j] = dp[i - 1][j];
			dp[i][j] += j - arr[i] >= 0 ? dp[i][j - arr[i]] : 0;
		}
	}
	cout << dp[dp.size() - 1][aim] << endl;
	return 0;
}