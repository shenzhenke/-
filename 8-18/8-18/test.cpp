#define _CRT_SECURE_NO_WARNINGS


//#include <iostream>
//#include <string>
//#include <map>
//#include <vector>
//using namespace std;
//string str;
//map<char, vector<int>> countChar;
//int main()
//{
//	cin >> str;
//	cout << str.size() << endl;
//	int ctl;
//	cin >> ctl;
//	for (size_t i = 0; i < str.size(); i++)
//	{
//		countChar[str[i]].push_back(i); //�����±�
//	}
//	map<char, vector<int>>::iterator it = countChar.begin();
//	size_t j = 0;
//	while (ctl != 0 && it != countChar.end())
//	{
//
//		if (j < (*it).second.size())
//		{
//			str[(*it).second[j]] = '#';
//			j++;
//			ctl--;
//		}
//		else
//		{
//			it++;
//			j = 0;
//		}
//	}
//	string::iterator itStr = str.begin();
//	while (itStr != str.end())
//	{
//		if (*itStr == '#')
//			itStr = str.erase(itStr);
//		else
//			itStr++;
//	}
//	cout << str << endl;
//
//	cout << endl;
//	cout << endl;
//	cout << endl;
//	cout << endl;
//	cout << endl;
//	cout << str.size() << endl;
//
//	return 0;
//}






//����,�����������ְ���С��������
#include  <iostream>
#include  <string> 
#include  <vector>
#include <algorithm>
using namespace std;
//struct Compare
//{
//	bool operator()(const string& s1, const string& s2)
//	{
//		size_t i = 0;
//		if (s1[i] != s2[i])
//		{  //�����һ���ַ���һ����ֱ�ӿ����жϴ�С
//			if (s1[i] > s2[i])
//				return true;
//			else
//				return false;
//		}
//		while (i < s1.size() && i<s2.size() && s1[i] == s2[i])
//		{  //һֱȥ�ң��ҵ����߲�һ��Ϊֹ�������ҵ�ĳ�����ݽ�β
//			i++;
//		}
//		if (i != s1.size() && i != s2.size()) //֤��û�����ֽ�β 654 656
//		{
//			if (s1[i] > s2[i])
//				return true;
//			else
//				return false;
//		}
//		if (i == s1.size() && i == s2.size())  //���ַ��ȳ�  ����7     7
//			return true;
//		if (i == s1.size())
//		{
//			if (s2[i] > s1[i - 1])  //����     7    78
//				return false;
//			else if (s2[i] < s1[i - 1]) //���� 7    76
//				return true;
//			else{
//				size_t j = i;
//				while (j<s2.size() && s2[j] == s1[i - 1]){
//					j++;
//				}
//				if (s2.size() == j)//���� 7           7777777
//					return true;
//				else if (s1[i - 1]>s2[j]) //����7        7777776665
//					return true;
//				else
//					return false;  //����7         77777777778
//			}
//
//		}
//		else
//		{
//			if (s1[i] > s2[i - 1])
//				return true;
//			else if (s1[i] < s2[i - 1])
//				return false;
//			else{
//				size_t j = i;
//				while (j<s1.size() && s1[j] == s2[i - 1]){
//					j++;
//				}
//				if (s1.size() == j)
//					return true;
//				else if (s2[i - 1]>s1[j])
//					return false;
//				else
//					return true;
//			}
//		}
//	}
//};

struct Compare
{
	bool operator()(const string &s1, const string &s2)
	{
		size_t i = 0;
		while (i < s1.size() && i < s2.size() && s1[i] == s2[i])
		{
			i++;
		}
		if (i != s1.size() && i != s2.size())   //���� 785     784��
		{
			if (s1[i] > s2[i])
				return true;
			else
				return false;
		}
		if (i == s1.size() && i == s2.size())  //���� 93 93
			return true;
		if (i == s1.size())  //����93 93....
		{
			size_t j = i;
			i = 0;
			while (j<s2.size())
			{
				if (s1[i] > s2[j])  //����93 935
					return true;
				else if (s1[i] < s2[j]) //����39 399
					return false;
				else               //����93   9399
				{
					i++;
					j++;
					if (i == s1.size())
						i = 0;
				}
			}
			return true;
		}
		else
		{
			size_t j = i;
			i = 0;
			while (j<s1.size())
			{
				if (s2[i] > s1[j])
					return false;
				else if (s2[i] < s1[j])
					return true;
				else
				{
					i++;
					j++;
					if (i == s2.size())
						i = 0;
				}
			}
			return true;
		}
	}
	
};
void SortString(vector<string>& sortString)
{
	if (sortString.size() <= 1)
		return;
	sort(sortString.begin(), sortString.end(), Compare());
}
int main()
{
	vector<string> sortString1;
	int n;
	cin >> n;
	string s;
	while (n&&cin >> s){
		sortString1.push_back(s);
		n--;
	}
	SortString(sortString1);
	string s1 = "";
	for (size_t i = 0; i < sortString1.size(); i++){
		s1 += sortString1[i];
	}
	cout << s1 << endl;
	return 0;
}


