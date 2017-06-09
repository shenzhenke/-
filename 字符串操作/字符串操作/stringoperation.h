
//字符流中第一个只出现一次的字符
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

//对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。
//例如，字符序列S = ”abcXYZdef”, 要求输出循环左移3位后的结果，即“XYZdefabc”。
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