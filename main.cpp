#include<iostream>
#include<graphics.h>//ͼ�ο⣬�ĵ���https://docs.easyx.cn/zh-cn/intro
#include<cmath>

#define WIDTH 803
#define HEIGHT 803

char key;//����ָ���ָ��

using namespace std;

//����̨�˵�
void menu()
{
	cout << "1.һ�κ���" << endl;
	cout << "2.���κ���" << endl;
	cout << "3.����������" << endl;
	cout << "c.���ͼ��" << endl;
}

//x�����ת������
int _x(int x)
{
	if (x == 0)//���x��y���غ�
	{
		return 402;
	}
	if (x > 0)//���x�������ᣨ����0��
	{
		return x + 402;
	}
	if (x < 0)//���x�ڸ����ᣨ����0��
	{
		return x + 400;
	}
}

//y�����ת������
int _y(int y)
{
	if (y == 0)//���y��x���غ�
	{
		return 402;
	}
	if (y > 0)//���y�������ᣨ����0��
	{
		return 400 - y;
	}
	if (y < 0)//���y�ڸ����ᣨ����0��
	{
		return 402 - y;
	}
}

//����һ�κ���
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

//���ƶ��κ���
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

//���Ʒ���������
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

//��������ϵ
void drawCoordinates()
{
	solidrectangle(0, 401, 803, 403);//����x��
	solidrectangle(401, 0, 403, 803);//����y��

}

int main()
{
	initgraph(WIDTH, HEIGHT, EW_SHOWCONSOLE);//��ʾ����̨����

	setbkcolor(RGB(0xf2, 0xe4, 0xe3));
	cleardevice();//��������ɫ��Ϊ��ɫ

	setfillcolor(RGB(0xea, 0x6b, 0x48));//�����ɫΪ��ɫ
	
	drawCoordinates();//��������ϵ

	float a=0;
	float b=0;
	float c=0;
	float k=0;

	//��ѭ��
	while(true)
	{
		menu();

		cin >> key;
		if (key == '1')
		{
			cout << "������k��ֵ" << endl;
			cin >> k;
			//k��Ϊ0
			if (k == 0) 
			{
				cout << "k����Ϊ0���Զ���k��Ϊ1��" << endl;
				k = 1;
			}
			cout << "������b��ֵ" << endl;
			cin >> b;
			cout << "���Ժ󡭡�" << endl;
			drawLinearFunction(k,b);
			cout << "�����" << endl;
			//��ӡ�������ʽ
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
			cout << "������a��ֵ" << endl;
			cin >> a;
			//a��Ϊ0
			if (a == 0)
			{
				cout << "a����Ϊ0���Զ���k��Ϊ1��" << endl;
				a = 1;
			}
			cout << "������b��ֵ" << endl;
			cin >> b;
			cout << "������c��ֵ" << endl;
			cin >> c;
			cout << "���Ժ󡭡�" << endl;
			drawQuadraticFunctions(a,b,c);
			cout << "�����" << endl;
			//��ӡ�������ʽ
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
			cout << "������k��ֵ" << endl;
			cin >> k;
			//k��Ϊ0
			if (k == 0)
			{
				cout << "k����Ϊ0���Զ���k��Ϊ1��" << endl;
				k = 1;
			}
			cout << "���Ժ󡭡�" << endl;
			drawInverseProportionalFunction(k);
			cout << "�����" << endl;
			
			//��ӡ�������ʽ
			cout << "y=" << k << "/x";

			a = 0;
			b = 0;
			c = 0;
			k = 0;
			system("pause");
		}
		else if (key == 'c')
		{
			cout << "���Ժ󡭡�" << endl;
			cleardevice();//�������
			drawCoordinates();//�ٽ�����ϵ����ȥ
			cout << "�����" << endl;
			a = 0;
			b = 0;
			c = 0;
			k = 0;
			system("pause");
		}
		else
		{
			cout << "δʶ��ָ��" << endl;
		}

		key = 0;//��key��ʼ��

		system("cls");//����
	}

	return 0;
}