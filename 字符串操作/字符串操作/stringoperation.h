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







//��һ���ַ���(1 <= �ַ������� <= 10000��ȫ������ĸ���)
//���ҵ���һ��ֻ����һ�ε��ַ�, ����������λ��

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



//���磬��student.a am I������������ʶ������һ�ԭ���Ѿ��ӵ��ʵ�˳��ת�ˣ�
//��ȷ�ľ���Ӧ���ǡ�I am a student.����
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


//��ʵ��һ�����������ҳ��ַ����е�һ��ֻ����һ�ε��ַ������磬�����ַ�����ֻ����ǰ�����ַ�"go"ʱ��
//��һ��ֻ����һ�ε��ַ���"g"�����Ӹ��ַ����ж���ǰ�����ַ���google"ʱ����һ��ֻ����һ�ε��ַ���"l"�� 
//�������:
//�����ǰ�ַ���û�д��ڳ���һ�ε��ַ�������#�ַ���


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