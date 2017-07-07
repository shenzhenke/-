


//����ջ��ʵ��һ������

//class Solution
//{
//public:
//	void push(int node)
//	{
//		if (stack1.size() == 0)
//		{
//			for (size_t i = 0; i < stack2.size();)
//			{
//				stack1.push(stack2.top());
//				stack2.pop();
//			}
//			stack2.push(node);
//			for (size_t i = 0; i < stack1.size();)
//			{
//				stack2.push(stack1.top());
//				stack1.pop();
//			}
//		}
//	}
//
//	int pop()
//	{
//		if (stack2.size() != 0)
//		{
//			int result = stack2.top();
//			stack2.pop();
//			return result;
//		}
//		return false;
//	}
//private:
//	stack<int> stack1;
//	stack<int> stack2;
//};



//�����ж���һ���������Ƿ����һ������ĳ�ַ��������ַ���·����
//·�����ԴӾ����е�����һ�����ӿ�ʼ��ÿһ�������ھ������������ң����ϣ������ƶ�һ�����ӡ�
//���һ��·�������˾����е�ĳһ�����ӣ����·�������ٽ���ø��ӡ�
//���� a b c e s f c s a d e e �����а���һ���ַ���"bcced"��·����
//���Ǿ����в�����"abcb"·������Ϊ�ַ����ĵ�һ���ַ�bռ���˾����еĵ�һ�еڶ�������֮��
//·�������ٴν���ø��ӡ�
class Solution {
public:
	bool hasPath(char* matrix, int rows, int cols, char* str)
	{
		if (matrix == NULL || str == NULL)
			return false;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (matrix[i*j + j] == str[0])
				{
					if (_hasPath(matrix, i, j, str) == true)
						return true;
				}
			}
		}
		return false;
	}
private:
	bool _hasPath(char* matrix, int rows, int cols, char* str)
	{
		int pos = 0;
		stack<char*> s;
		stack<char*> v;
		int i = rows;
		int j = cols;	
		if (matrix[i*j + j] == str[pos])
			s.push(&matrix[i*j + j]);
		v.push(&matrix[i*j + j]);
		while (s.size() != NULL&&str[pos] != '/0'&&pos >= 0)
		{
			//��·�ʺ�
			if (matrix[i*j + j + 1] == str[pos] && v.top() != &matrix[i*j + j + 1])
			{
				s.push(&matrix[i*j + j]);
				pos++;
			}
			//��·
			else if (matrix[i*j + j - 1] == str[pos] && v.top() != &matrix[i*j + j - 1])
			{
				s.push(&matrix[i*j + j]);
				pos++;
			}
			//��·�ʺ�
			else	 if (matrix[(i - 1)*j + j] == str[pos] && v.top() != &matrix[(i - 1)*j + j])
			{
				s.push(&matrix[i*j + j]);
				pos++;
			}
			//��·�ʺ�
			else if (matrix[(i + 1)*j + j] == str[pos] && v.top() != &matrix[(i + 1)*j + j])
			{
				s.push(&matrix[i*j + j]);
				pos++;
			}
			else
			{
				v.pop();
				v.push(s.top());
				s.pop();
				pos--;
			}
		}
	}
};






