


//两个栈来实现一个队列

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



//用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
//路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
//如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。
//例如 a b c e s f c s a d e e 矩阵中包含一条字符串"bcced"的路径，
//但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，
//路径不能再次进入该格子。
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
			//右路适合
			if (matrix[i*j + j + 1] == str[pos] && v.top() != &matrix[i*j + j + 1])
			{
				s.push(&matrix[i*j + j]);
				pos++;
			}
			//左路
			else if (matrix[i*j + j - 1] == str[pos] && v.top() != &matrix[i*j + j - 1])
			{
				s.push(&matrix[i*j + j]);
				pos++;
			}
			//上路适合
			else	 if (matrix[(i - 1)*j + j] == str[pos] && v.top() != &matrix[(i - 1)*j + j])
			{
				s.push(&matrix[i*j + j]);
				pos++;
			}
			//下路适合
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






