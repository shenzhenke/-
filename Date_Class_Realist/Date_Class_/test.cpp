
#include "Date.h"
int main()
{
	Date d(2017,3,8);
    Date d1 = d + 100;
	d.display();
	d1.display();
	Date d2(2017, 3, 8);
	d2 += 100;
	d2.display();
	Date d3 = d2 - (-100);
	d3.display();
	Date d4 = d3 + (-100);
	d4.display();
	int k=d3 > d4;
	cout << k << endl;
	Date d5 = d4;
	(d5++).display();
	(++d5).display();
	int a = d3 - d4;
	cout << a << endl;
	system("pause");
	return 0;
}