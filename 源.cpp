#include<easyx.h>
#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;

void Screen(int xd,int yd){										//初始化图形窗口
	initgraph(xd, yd);
	floodfill(0, 0, WHITE);
}
void Creatmap(int x,int y) {									//建立网格状画布
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
void fill_color() {																		//填充色更改
	MessageBox(NULL, TEXT("请输入填充颜色(R/B/G)"), TEXT("提示"), MB_OK);
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
	MOUSEMSG msg;										//接收鼠标响应
	fill_color();										//调用填充色更改函数
	while (true) {
		msg = GetMouseMsg();
		if (msg.uMsg == WM_LBUTTONDOWN) {				//上色
			
			floodfill(msg.x, msg.y, BLACK);
		}
		else if (msg.uMsg == WM_RBUTTONDBLCLK) {		//清空上色
			setbkcolor(WHITE);
			cleardevice();
			floodfill(0, 0, WHITE);
			Creatmap(500, 500);
		}
		else if (msg.uMsg== WM_MBUTTONDOWN)				//改变填充颜色
		{
			fill_color();								
			continue;
		}
		else if(msg.uMsg== WM_MOUSEWHEEL)				//关闭图形窗口
		{
			closegraph();
		}
	}
}
int main() {
	Screen(500, 500);			//初始化屏幕
	Creatmap(500,500);			//创建方格状画布
	mouse();					//鼠标操作
	
	return 0;
}