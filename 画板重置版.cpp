#include<iostream>
#include<graphics.h>
#include<conio.h>
using namespace std;
void Screen();
void GameMap();
void operate();
void fill_color();
int pre_x, pre_y;
COLORREF pre_color;
int main() {
	operate();
	return 0;
}
void Screen() {
	initgraph(602, 602);
	setbkcolor(WHITE);
	cleardevice();
	setlinecolor(BLACK);
	line(1, 1, 1, 600);
	line(600, 1, 600, 600);
	line(1, 1, 600, 1);
	line(1, 600, 600, 600);
}
void GameMap() {
	for (int i = 1; i <= 600; i += 15) {
		line(i, 1, i, 600);
		line(1, i, 600, i);
	}
}
void operate() {
	Screen();
	GameMap();
	MOUSEMSG M;
	fill_color();										//调用填充色更改函数
	while (true) {
		M = GetMouseMsg();
		if (M.uMsg == WM_LBUTTONDOWN) {				//上色
			floodfill(M.x, M.y, BLACK);
		}
		else if (M.uMsg == WM_LBUTTONDBLCLK) {
			setfillcolor(WHITE);
			floodfill(M.x, M.y, BLACK);
			setfillcolor(pre_color);
		}
		else if (M.uMsg == WM_RBUTTONDBLCLK) {		//清空上色
			setbkcolor(WHITE);
			cleardevice();
			GameMap();
		}
		else if (M.uMsg == WM_MBUTTONDOWN)				//改变填充颜色
		{
			fill_color();
			continue;
		}
		else if (M.uMsg == WM_MOUSEWHEEL)				//关闭图形窗口
		{
			closegraph();
		}
	}
}
void fill_color() {																		//填充色更改
	MessageBox(NULL, TEXT("请输入填充颜色(R/B/G)"), TEXT("提示"), MB_OK);
	char ch = _getch();
	switch (ch) {
	case 'R':
		pre_color = 0x5555FF;
		setfillcolor(0x5555FF);
		break;
	case 'B':
		pre_color = 0xFF5555;
		setfillcolor(0xFF5555);
		break;
	case 'G':
		pre_color = 0x55FF55;
		setfillcolor(0x55FF55);
		break;
	}
}