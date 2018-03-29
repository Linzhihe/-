void setColor(unsigned short ForeColor = 7,
		unsigned short BackGroundColor = 0) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); //获取当前窗口句柄
	SetConsoleTextAttribute(handle, ForeColor + BackGroundColor * 0x10); //设置颜色`
}
//设置光标位置
void SetPos(int x, int y) {
	COORD pos;
	HANDLE handle;
	pos.X = x;
	pos.Y = y;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, pos);

}
void meun() {
	setColor(10, 0);
	printf(
			"┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n┃                                      ┃\n┃          ");
	setColor(14, 0);
	printf("欢迎使用通讯录系统");
	setColor(10, 0);
	printf("          ┃\n┃                                      ┃\n");
	printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	printf("┃              ");
	setColor(14, 0);
	printf("实验三作业");
	setColor(10, 0);
	printf("              ┃\n");
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	Sleep(2000);
	system("cls");
	printf("\n");
	printf("╔══════════════════════════════════╗\n");
	Sleep(100);
	printf("║          ");
	setColor(14, 0);
	printf("欢迎使用通讯录");
	setColor(10, 0);
	printf("          ║\n");
	Sleep(100);
	printf("╠══════════════════════════════════╣\n");
	Sleep(100);
	printf("║★        [1]创建通讯录         ★║\n");
	Sleep(100);
	printf("║★        [2]导入通讯录         ★║\n");
	Sleep(100);
	printf("║★        [3]显示通讯录         ★║\n");
	Sleep(100);
	printf("║★        [4]新增通讯录         ★║\n");
	Sleep(100);
	printf("║★        [5]修改通讯录         ★║\n");
	Sleep(100);
	printf("║★        [6]查找通讯录         ★║\n");
	Sleep(100);
	printf("║★        [7]删除通讯录         ★║\n");
	Sleep(100);
	printf("║★        [8]显示删除的通讯录   ★║\n");
	Sleep(100);
	printf("║★        [9]撤销删除通讯录     ★║\n");
	Sleep(100);
	printf("║★        [10]导出通讯录为CSV   ★║\n");
	Sleep(100);
	printf("║★        [0]退出               ★║\n");
	Sleep(100);
	printf("╠══════════════════════════════════╣\n");
	Sleep(100);
	printf("║★☆★☆★☆实验三作业☆★☆★☆★║\n");
	Sleep(100);
	printf("╚══════════════════════════════════╝\n");
	printf("请输入0-10选择功能：");
}

