
//�ַ����е�һ��ֻ����һ�ε��ַ�
//class Solution
//{
//private:
//	string str;
//public:
//	//Insert one char from stringstream
//	void Insert(char ch)
//	{
//		if (ch >= 0 && ch<128)
//		{
//			str.push_back(ch);
//		}
//		else
//		{
//			printf("Insert invaild\n");
//		}
//	}
//	//return the first appearence once char in current stringstream
//	char FirstAppearingOnce()
//	{
//		map<char, int> countChar;
//		int k = str.size();
//		for (int i = 0; i<k; i++)
//		{
//			countChar[str[i]]++;
//		}
//		map<char, int>::iterator it = countChar.begin();
//		while (it != countChar.end())
//		{
//			if (it->second == 1)
//				//	return	str[str.find(it->first)];
//				return it->first;
//			it++;
//		}
//		return '#';
//	}
//};

//����һ���������ַ�����S���������ѭ������Kλ������������
//���磬�ַ�����S = ��abcXYZdef��, Ҫ�����ѭ������3λ��Ľ��������XYZdefabc����
class Solution {
public:
	string LeftRotateString(string str, int n) {
		vector<char> v;
		int k = str.size();
		if (k == 0)
			return str;
		int m = n%k;
		if (m == 0)
			return str;
		for (int i = 0; i<m; i++)
		{
			v.push_back(str[i]);
		}
		str.erase(0, m);
		for (int i = 0; i<m; i++)
		{
			str.push_back(v[i]);
		}
		return str;
	}
};