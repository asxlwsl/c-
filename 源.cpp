#include<easyx.h>
#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;

void Screen(int xd,int yd){										//��ʼ��ͼ�δ���
	initgraph(xd, yd);
	floodfill(0, 0, WHITE);
}
void Creatmap(int x,int y) {									//��������״����
	setlinecolor(BLACK);
	setlinestyle(PS_ENDCAP_SQUARE | PS_JOIN_ROUND,3);
	rectangle(0, 0, x-1, y-1);
	for (int temp_x = 1; temp_x <= x; temp_x += 10) {
		line(temp_x, 1, temp_x, y);
	}
	for (int temp_y = 1; temp_y <= y; temp_y += 10) {
		line(1, temp_y,x , temp_y);
	}
}
void fill_color() {																		//���ɫ����
	MessageBox(NULL, TEXT("�����������ɫ(R/B/G)"), TEXT("��ʾ"), MB_OK);
	char ch = _getch();
	switch (ch) {
	case 'R':
		setfillcolor(0x5555FF);
		break;
	case 'B':
		setfillcolor(0xFF5555);
		break;
	case 'G':
		setfillcolor(0x55FF55);
		break;
	}
}
void mouse() {
	MOUSEMSG msg;										//���������Ӧ
	fill_color();										//�������ɫ���ĺ���
	while (true) {
		msg = GetMouseMsg();
		if (msg.uMsg == WM_LBUTTONDOWN) {				//��ɫ
			
			floodfill(msg.x, msg.y, BLACK);
		}
		else if (msg.uMsg == WM_RBUTTONDBLCLK) {		//�����ɫ
			setbkcolor(WHITE);
			cleardevice();
			floodfill(0, 0, WHITE);
			Creatmap(500, 500);
		}
		else if (msg.uMsg== WM_MBUTTONDOWN)				//�ı������ɫ
		{
			fill_color();								
			continue;
		}
		else if(msg.uMsg== WM_MOUSEWHEEL)				//�ر�ͼ�δ���
		{
			closegraph();
		}
	}
}
int main() {
	Screen(500, 500);			//��ʼ����Ļ
	Creatmap(500,500);			//��������״����
	mouse();					//������
	
	return 0;
}