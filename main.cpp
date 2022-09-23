#include<iostream>
#include<graphics.h>//图形库，文档：https://docs.easyx.cn/zh-cn/intro
#include<cmath>

#define WIDTH 803
#define HEIGHT 803

char key;//接收指令发出指令

using namespace std;

//控制台菜单
void menu()
{
	cout << "1.一次函数" << endl;
	cout << "2.二次函数" << endl;
	cout << "3.反比例函数" << endl;
	cout << "c.清空图像" << endl;
}

//x坐标的转换函数
int _x(int x)
{
	if (x == 0)//如果x与y轴重合
	{
		return 402;
	}
	if (x > 0)//如果x在正半轴（不含0）
	{
		return x + 402;
	}
	if (x < 0)//如果x在负半轴（不含0）
	{
		return x + 400;
	}
}

//y坐标的转换函数
int _y(int y)
{
	if (y == 0)//如果y与x轴重合
	{
		return 402;
	}
	if (y > 0)//如果y在正半轴（不含0）
	{
		return 400 - y;
	}
	if (y < 0)//如果y在负半轴（不含0）
	{
		return 402 - y;
	}
}

//绘制一次函数
void drawLinearFunction(float k,float b)
{
	int x = -400;
	int y = 0;
	for (float xf = -4.0f; xf <= 4.0f;xf+=0.01f) {
		float yf = k * xf+b;
		y = yf * 100;
		if (y <= 400 && y >= -400)
		{
			putpixel(_x(x), _y(y), RGB(0xea, 0x6b, 0x48));
		}
		x++;
	}
}

//绘制二次函数
void drawQuadraticFunctions(float a, float b, float c)
{
	int x = -400;
	int y = 0;
	for (float xf = -4.0f; xf <= 4.0f; xf += 0.01f) {
		float yf = a * pow(xf,2) + b*xf+c;
		y = yf * 100;
		if (y <= 400 && y >= -400)
		{
			putpixel(_x(x), _y(y), RGB(0xea, 0x6b, 0x48));
		}
		x++;
	}
}

//绘制反比例函数
void drawInverseProportionalFunction(float k)
{
	int x = -400;
	int y = 0;
	for (float xf = -4.0f; xf <= 4.0f; xf += 0.01f) {
		float yf = k/xf;
		y = yf * 100;
		if (y <= 400 && y >= -400)
		{
			putpixel(_x(x), _y(y), RGB(0xea, 0x6b, 0x48));
		}
		x++;
	}
}

//绘制坐标系
void drawCoordinates()
{
	solidrectangle(0, 401, 803, 403);//绘制x轴
	solidrectangle(401, 0, 403, 803);//绘制y轴

}

int main()
{
	initgraph(WIDTH, HEIGHT, EW_SHOWCONSOLE);//显示控制台窗口

	setbkcolor(RGB(0xf2, 0xe4, 0xe3));
	cleardevice();//将背景颜色设为灰色

	setfillcolor(RGB(0xea, 0x6b, 0x48));//填充颜色为橙色
	
	drawCoordinates();//绘制坐标系

	float a=0;
	float b=0;
	float c=0;
	float k=0;

	//主循环
	while(true)
	{
		menu();

		cin >> key;
		if (key == '1')
		{
			cout << "请输入k的值" << endl;
			cin >> k;
			//k不为0
			if (k == 0) 
			{
				cout << "k不能为0（自动将k改为1）" << endl;
				k = 1;
			}
			cout << "请输入b的值" << endl;
			cin >> b;
			cout << "请稍后……" << endl;
			drawLinearFunction(k,b);
			cout << "已完成" << endl;
			//打印函数表达式
			if (b == 0)
			{
				if (k == 1)
					cout << "y=x" << endl;
				else
					cout << "y=" << k << "x" << endl;
			}
			else if (b > 0)
			{
				if (k == 1)
					cout << "y=x+"<< b << endl;
				else
					cout << "y=" << k << "x+"<< b << endl;
			}
			else
			{
				if (k == 1)
					cout << "y=x" << b << endl;
				else
					cout << "y=" << k << "x"<< b << endl;
			}
			a = 0;
			b = 0;
			c = 0;
			k = 0;
			system("pause");
		}
		else if (key == '2')
		{
			cout << "请输入a的值" << endl;
			cin >> a;
			//a不为0
			if (a == 0)
			{
				cout << "a不能为0（自动将k改为1）" << endl;
				a = 1;
			}
			cout << "请输入b的值" << endl;
			cin >> b;
			cout << "请输入c的值" << endl;
			cin >> c;
			cout << "请稍后……" << endl;
			drawQuadraticFunctions(a,b,c);
			cout << "已完成" << endl;
			//打印函数表达式
			if (c == 0)
			{
				if (b == 0)
					if(a==1)
						cout << "y=x^2" << endl;
					else
						cout << "y=" << a << "x^2" << endl;
				else if(b>=0)
					if (a == 1)
						cout << "y=x^2+" << b << "x" << endl;
					else
						cout << "y=" << a << "x^2+"<<b<<"x" << endl;
				else
					if (a == 1)
						cout << "y=x^2" << b << "x" << endl;
					else
						cout << "y=" << a << "x^2" << b << "x" << endl;
			}
			else if (c > 0)
			{
				if (b == 0)
					if (a == 1)
						cout << "y=x^2+" << c << endl;
					else
						cout << "y=" << a << "x^2+"<< c << endl;
				else if (b >= 0)
					if (a == 1)
						cout << "y=x^2+" << b << "x+" << c << endl;
					else
						cout << "y=" << a << "x^2+" << b << "x+" << c << endl;
				else
					if (a == 1)
						cout << "y=x^2" << b << "x+" << c << endl;
					else
						cout << "y=" << a << "x^2" << b << "x+" << c << endl;
			}
			else
			{
				if (b == 0)
					if (a == 1)
						cout << "y=x^2" << c << endl;
					else
						cout << "y=" << a << "x^2" << c << endl;
				else if (b >= 0)
					if (a == 1)
						cout << "y=x^2+" << b << "x" << c << endl;
					else
						cout << "y=" << a << "x^2+" << b << "x" << c << endl;
				else
					if (a == 1)
						cout << "y=x^2" << b << "x" << c << endl;
					else
						cout << "y=" << a << "x^2" << b << "x" << c << endl;
			}
			a = 0;
			b = 0;
			c = 0;
			k = 0;
			system("pause");
		}
		else if (key == '3')
		{
			cout << "请输入k的值" << endl;
			cin >> k;
			//k不为0
			if (k == 0)
			{
				cout << "k不能为0（自动将k改为1）" << endl;
				k = 1;
			}
			cout << "请稍后……" << endl;
			drawInverseProportionalFunction(k);
			cout << "已完成" << endl;
			
			//打印函数表达式
			cout << "y=" << k << "/x";

			a = 0;
			b = 0;
			c = 0;
			k = 0;
			system("pause");
		}
		else if (key == 'c')
		{
			cout << "请稍后……" << endl;
			cleardevice();//清除所有
			drawCoordinates();//再将坐标系画上去
			cout << "已完成" << endl;
			a = 0;
			b = 0;
			c = 0;
			k = 0;
			system("pause");
		}
		else
		{
			cout << "未识别指令" << endl;
		}

		key = 0;//将key初始化

		system("cls");//清屏
	}

	return 0;
}