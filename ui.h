void setColor(unsigned short ForeColor = 7,
		unsigned short BackGroundColor = 0) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); //��ȡ��ǰ���ھ��
	SetConsoleTextAttribute(handle, ForeColor + BackGroundColor * 0x10); //������ɫ`
}
//���ù��λ��
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
			"��������������������������������������������������������������������������������\n��                                      ��\n��          ");
	setColor(14, 0);
	printf("��ӭʹ��ͨѶ¼ϵͳ");
	setColor(10, 0);
	printf("          ��\n��                                      ��\n");
	printf("�ǩ�����������������������������������������������������������������������������\n");
	printf("��              ");
	setColor(14, 0);
	printf("ʵ������ҵ");
	setColor(10, 0);
	printf("              ��\n");
	printf("��������������������������������������������������������������������������������\n");
	Sleep(2000);
	system("cls");
	printf("\n");
	printf("�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
	Sleep(100);
	printf("�U          ");
	setColor(14, 0);
	printf("��ӭʹ��ͨѶ¼");
	setColor(10, 0);
	printf("          �U\n");
	Sleep(100);
	printf("�d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g\n");
	Sleep(100);
	printf("�U��        [1]����ͨѶ¼         ��U\n");
	Sleep(100);
	printf("�U��        [2]����ͨѶ¼         ��U\n");
	Sleep(100);
	printf("�U��        [3]��ʾͨѶ¼         ��U\n");
	Sleep(100);
	printf("�U��        [4]����ͨѶ¼         ��U\n");
	Sleep(100);
	printf("�U��        [5]�޸�ͨѶ¼         ��U\n");
	Sleep(100);
	printf("�U��        [6]����ͨѶ¼         ��U\n");
	Sleep(100);
	printf("�U��        [7]ɾ��ͨѶ¼         ��U\n");
	Sleep(100);
	printf("�U��        [8]��ʾɾ����ͨѶ¼   ��U\n");
	Sleep(100);
	printf("�U��        [9]����ɾ��ͨѶ¼     ��U\n");
	Sleep(100);
	printf("�U��        [10]����ͨѶ¼ΪCSV   ��U\n");
	Sleep(100);
	printf("�U��        [0]�˳�               ��U\n");
	Sleep(100);
	printf("�d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g\n");
	Sleep(100);
	printf("�U�������ʵ������ҵ�������U\n");
	Sleep(100);
	printf("�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
	printf("������0-10ѡ���ܣ�");
}

