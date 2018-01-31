#include <iostream>
using namespace std;
const float PI = 3.1416;
int main()
{
	int graphicType;
	float radius, a, b, perimeter;
	cout << "请选择图形的类型 (1-圆形 2-长方形 3-正方形) ：";
	cin >> graphicType;            //在此行设置断点
	switch(graphicType)
	{
	case 1:
		cout << "请输入圆的半径为：";
		cin >> radius;
		perimeter = PI * 2 * radius;
		cout<<"圆"<< radius <<"的周长为："<< perimeter <<endl;
		break;
	case 2:
		cout << "请输入矩形的长，宽（以空格分隔）：";
		cin >> a >> b;
		perimeter = 2*(a+b);
	    cout<<"矩形"<< a <<"："<<b<<"的周长为："<< perimeter <<endl;
		break;
	case 3:
		cout << "请输入正方形的边长为：";
		cin >> a;
		perimeter = a * 4;
		cout<<"正方形"<< a <<"的周长为："<< perimeter <<endl;
		break;
	default:
		cout << "输入错误!"<<endl;
	}
	return 0;
}