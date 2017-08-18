#define _CRT_SECURE_NO_WARNINGS 

//丢失的三个数
//#include <iostream>
//#include <vector>
//using namespace std;
//int arr[10001] = { 0 };
//int main()
//{
//	int ctl = 0;
//	int n;
//	while (cin >> n){
//		arr[n] = 1;
//	}
//	long number = 0;
//	for (size_t i = 10000; i>0; i--){
//		if (arr[i] == 0){
//			if (ctl != 0){
//				number = i*pow(10, ctl) + number;
//
//			}
//			else{
//				number += i;
//			}
//			if (i / 10000 != 0){
//				ctl += 5;
//			}
//			else if (i / 1000 != 0){
//				ctl += 4;
//			}
//			else if (i / 100 != 0){
//				ctl += 3;
//			}
//			else if (i / 10 != 0){
//				ctl += 2;
//			}
//			else{
//				ctl += 1;
//			}
//		}
//	}
//	cout << number % 7 << endl;
//	return 0;
//}


//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//int main()
//{
//
//	string s;
//	string str1, str2;
//	str1="1245";
//	str2="1245";
//	cout << (str1.c_str()[3] + str2.c_str()[3]) / 10 << endl;
//	//cin >> str1 >> str2;
//	//char ctl = 0;//记录下一位是否要向上一位进位
//	//size_t i = 1;
//	//int count = 0;
//	//while (i <= str1.size() && i <= str2.size())
//	//{
//	//	s.push_back(ctl + (str1.c_str()[str1.size() - i] + str2.c_str()[str2.size() - i]) % 10);
//	//	ctl = (str1.c_str()[str1.size() - i] + str2.c_str()[str2.size() - i]) / 10;
//	//	i++;
//	//}
//	//if (i == str1.size()){
//	//		while (i <= str2.size()){
//	//			if (count = 0){
//	//				s.push_back(str2.c_str()[str2.size() - i] + ctl);
//	//				count++;
//	//			}
//	//			else{
//	//				s.push_back(str2.c_str()[str2.size() - i]);
//	//			}
//	//			i++;
//	//		}
//	//}
//	//else{
//	//	while (i <= str1.size()){
//	//		if (count = 0){
//	//			s.push_back(str2.c_str()[str2.size() - i] + ctl);
//	//			count++;
//	//		}
//	//		else{
//	//			s.push_back(str2.c_str()[str2.size() - i]);
//	//		}
//	//		i++;
//	//	}
//	//}
//	//reverse(s.begin(), s.end());
//	//cout << s << endl;
//	return 0;
//}





//set统计字符出现否
//#include  <iostream>
//#include <set>
//#include <string>
//using namespace std;
//int main()
//{
//	set<string> countStr;
//	string str;
//	int count = 0;
//	while (cin >> str){
//		if (countStr.find(str) == countStr.end()){
//			count++;
//			countStr.insert(str);
//		}
//		else{
//			continue;
//		}
//	}
//	cout << count << endl;
//	return 0;
//}
//
//
//#include  <iostream>
//#include <map>
//#include <string>
//using namespace std;
//int main()
//{
//	map<string, int> countStr;
//	string str;
//	while (cin >> str){
//		countStr[str]++;
//	}
//	cout << countStr.size() << endl;
//	return 0;
//}


//查找子串问题
//#include <iostream>
//#include <vector>
//#include <string>
//#include <map>
//using namespace std;
//int main()
//{
//	string str1, str2;
//	vector<vector<int> > countChar(256);
//	cin >> str1 >> str2;
//	size_t Size = str1.size();
//	for (size_t i = 0; i < Size; i++){
//		countChar[str1[i]].push_back(i);
//	}
//	Size = str2.size();
//	bool flag = true;
//	int prev = -1;
//	for (size_t i = 0; i < Size; i++){
//		size_t j = 0;
//		for (; j<countChar[str2[i]].size(); j++){
//			if (countChar[str2[i]][j]>prev){
//				prev = countChar[str2[i]][j];
//				break;
//			}
//		}
//		if (j == countChar[str2[i]].size()){
//			flag = false;
//			break;
//		}
//	}
//	if (flag == false){
//		cout << "No" << endl;
//	}
//	else{
//		cout << "Yes" << endl;
//	}
//	return 0;
//}

//#include  <iostream>
//#include <map>
//#include <vector>
//#include <string>
//using namespace std;
//
//int main()
//{
//	string str1;
//	string str2;
//	map<char, vector<int>> countChar;
//	cin >> str1 >> str2;
//	for (size_t i = 0; i < str1.size(); i++)
//	{
//		countChar[str1[i]].push_back(i);
//	}
//	int prev = -1;
//	bool flag = true;
//	for (size_t i = 0; i < str2.size(); i++)
//	{
//		size_t j = 0;
//		for (; j < countChar[str2[i]].size(); j++)
//		{
//			if (countChar[str2[i]][j] > prev){
//				prev = countChar[str2[i]][j];
//				break;
//			}
//		}
//		if (j == countChar[str2[i]].size()){
//			flag = false;
//		}
//	}
//	if (flag == false)
//		cout << "No" << endl;
//	else
//		cout << "Yes" << endl;
//	return 0;
//}

////进制转化
//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//	vector<int> v;
//	int m, n;
//	cin >> m >> n;
//	while (m){
//		int number = m%n;
//		v.push_back(number);
//		m = m / n;
//	}
//	for (int i = v.size()-1; i >=0 ; i--)
//	{
//		if (v[i] <= 9)
//			cout << v[i];
//		else
//			cout << (char)('A' + v[i] - 10);
//	}
//	cout << endl;
//	return 0;
//}



//bfs
//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//	vector<int> vX;
//	vector<int> vY;
//	int count;
//	cin >> count;
//	int num;
//	for (int i = 0; i < count; i++){
//		cin >> num;
//		vX.push_back(num);
//	}
//	for (int i = 0; i < count; i++){
//		cin >> num;
//		vY.push_back(num);
//	}
//	int seconds = 0;
//	int minSeconds = -1;
//	for (size_t i = 0; i<vX.size(); i++){
//		if ((vX[i] + vY[i]) % 2 == 0)
//			seconds = ((vX[i] + vY[i]) / 2 - 1) * 2;
//		else
//			seconds = ((vX[i] + vY[i]) / 2 - 1) * 2 + 1;
//		if (minSeconds == -1)
//			minSeconds = seconds;
//		minSeconds = minSeconds > seconds ? seconds : minSeconds;
//	}
//	cout << minSeconds << endl;
//	return 0;
//}



//求树的高度
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int main()
//{
//	int countNode;
//	cin >> countNode;
//	vector<int>  v;
//	v.resize(countNode, 0);
//	vector<int>  count;
//	count.resize(countNode, 0);
//	v[0] = 1;
//	int num;
//	int parent;
//	int mark = 1;
//	while (cin >> num)
//	{
//		if (mark == 1){
//			parent = num;
//			mark = 0;
//			count[parent]++;
//		}
//		else{
//			if (count[parent] != 3)
//				v[num] = v[parent] + 1;
//			mark = 1;
//		}
//	}
//	cout << *max_element(v.begin(), v.end()) << endl;
//	return 0;
//}



//树的高度终极版
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int countNode;
	cin >> countNode;
	vector<int>  v;
	v.resize(countNode, 0);
	vector<int>  count;
	count.resize(countNode, 0);
	v[0] = 1;
	int num;
	int parent;
	int mark = 1;
	pair<int, int> number;
	vector<pair<int, int>> countIndex;
	while (cin >> num)
	{
		if (mark == 1){
			number.first = num;
			parent = num;
			mark = 0;
			count[parent]++;
		}
		else{
			number.second = num;
			if (count[parent] < 3)
				countIndex.push_back(number);
			mark = 1;
		}
	}
	struct Compare
	{
		bool operator()(pair<int, int> v1, pair<int, int> v2)
		{
			return v1.first < v2.first;
		}
	};
	sort(countIndex.begin(), countIndex.end(), Compare());
	vector<pair<int, int>>::iterator it = countIndex.begin();
	while (it != countIndex.end())
	{
		v[it->second] = v[it->first] + 1;
		it++;
	}
	cout << *max_element(v.begin(), v.end()) << endl;
	return 0;
}
