//class Solution {
//public:
//	void replaceSpace(char *str, int length)
//	{
//		vector<string> v;
//		string s = "";
//		for (int i = 0; i < length; i++)
//		{
//			s = "";
//			s.push_back(str[i]);
//			v.push_back(s);
//		}
//		for (int i = 0; i < length; i++)
//		{
//			if (v[i] == " ")
//				v[i] = "%20";
//		}
//		s = "";
//		for (int i = 0; i < length; i++)
//		{
//			s += v[i];
//		}
//		for (size_t i = 0; i < s.size(); i++)
//		{
//			str[i] = s[i];
//		}
//	}
//};


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
//class Solution {
//public:
//	string LeftRotateString(string str, int n) {
//		vector<char> v;
//		int k = str.size();
//		if (k == 0)
//			return str;
//		int m = n%k;
//		if (m == 0)
//			return str;
//		for (int i = 0; i<m; i++)
//		{
//			v.push_back(str[i]);
//		}
//		str.erase(0, m);
//		for (int i = 0; i<m; i++)
//		{
//			str.push_back(v[i]);
//		}
//		return str;
//	}
//};







//在一个字符串(1 <= 字符串长度 <= 10000，全部由字母组成)
//中找到第一个只出现一次的字符, 并返回它的位置

//class Solution {
//public:
//	int FirstNotRepeatingChar(string str) {
//		map<char, pair<int, int>> countChar;
//		vector<int> v;
//		map<int,int> index;
//		int k = str.size();
//		for (int i = 0; i<k; i++)
//		{
//			countChar[str[i]].second++;
//			countChar[str[i]].first = i;
//		}
//		map<char, pair<int,int>>::iterator it = countChar.begin();
//		while (it != countChar.end())
//		{
//			if (it->second.second == 1)
//				//	return	str[str.find(it->first)];
//				v.push_back(it->second.first);
//			it++;
//		}
//		if (v.size() != 0)
//		{
//			sort(v.begin(), v.end());
//			return v[0];
//		}
//		return -1;
//	}
//};



//例如，“student.a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，
//正确的句子应该是“I am a student.”。
//class Solution 
//{
//public:
//	string ReverseSentence(string str) 
//	{
//		reverse(str.begin(), str.end());
//		string::iterator begin = str.begin();
//		string::iterator it = str.begin();
//		string::iterator end = str.end();
//		while (it != str.end())
//		{
//			if (*it == ' ')
//			{
//				end = it;
//				reverse(begin, end);
//				end += 1;
//				begin = end;
//			}
//			it += 1;
//		}
//		reverse(begin, str.end());
//		return str;
//	}
//};


//请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个字符"go"时，
//第一个只出现一次的字符是"g"。当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。 
//输出描述:
//如果当前字符流没有存在出现一次的字符，返回#字符。


class Solution
{
private:
	string str;
public:
	//Insert one char from stringstream
	void Insert(char ch)
	{
		if (ch >= 0 && ch<128)
		{
			str.push_back(ch);
		}
		else
		{
			printf("Insert invaild\n");
		}
	}
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{
		map<char,pair<int,int>> countChar;
		int k = str.size();
		if (k == 0)
			return '#';
		for (int i = 0; i<k; i++)
		{
			countChar[str[i]].first++;
			countChar[str[i]].second = i;
		}
		map<char, pair<int, int>>::iterator it = countChar.begin();
		while (it != countChar.end())
		{
			if (it->second.first == 1)
			{
				if (it->second.second < k)
					k = it->second.second;
			}
			it++;
		}
		if (k == str.size())
			return str[k];
		else
			return '#';
	}
};