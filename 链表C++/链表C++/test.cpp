//#include "List.cpp"
#include <iostream>
using namespace std;
#include<stack>
#include <map>
#include <vector>
#include "list.hpp"
int main()
{
	//两个栈实现一个队列
	//Solution a;
	//a.push(0);
	//a.push(1);
	//a.push(2);
	//a.push(3);
	//a.push(4);
	//a.push(5);
	//a.push(6);
	//cout << a.pop() << endl;
	//cout << a.pop() << endl;
	//cout << a.pop() << endl;
	//cout << a.pop() << endl;
	//cout << a.pop() << endl;

	//得到栈的最小元素
	//Solution a;
	//a.push(1);
	//a.push(3);
	//a.push(5);
	//cout << a.min() << endl;
	//a.push(8);
	//a.push(7);
	//a.push(6);
	//a.push(9);
	//cout << a.min() << endl;
	//a.push(2);
	//a.push(0);
	//cout << a.min() << endl;
	//a.push(-2);
	//a.push(-1);
	//cout << a.min() << endl;



	ListNode* pHead = new ListNode(6);
	ListNode* cur = new ListNode(6);
	pHead->next = cur;
	ListNode* cur1 = new ListNode(5);
	cur->next = cur1;
	ListNode* cur2 = new ListNode(5);
	cur1->next = cur2;
	ListNode* cur3 = new ListNode(4);
	cur2->next = cur3;
	ListNode* cur4 = new ListNode(4);
	cur3->next = cur4;
	ListNode* cur5 = new ListNode(3);
	cur4->next = cur5;
	ListNode* cur6 = new ListNode(2);
	cur5->next = cur6;
	ListNode* cur7 = new ListNode(1);
	cur6->next = cur7;
	Solution a;
	ListNode* head = a.deleteDuplication(pHead);
	while (head!=NULL)
	{
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
	return 0;
}