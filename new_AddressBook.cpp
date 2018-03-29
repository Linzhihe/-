//============================================================================
// Name        : new_AddressBook.cpp
// Author      : 林道利
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Resources.h"
using namespace std;
int main() {
	//菜单栏
	meun();
	ElemType e;
	SqList L;
	LinkList List;
	Init_Delete_AddressBook(List);
	//Csv_Delete_AddressBook(List);
	int choice_number;
	while (1) {
		setColor(15, 0);
		scanf("%d", &choice_number); //功能选择
		setColor(10, 0);
		switch (choice_number) {
		case 0: {
			system(SCREEN_CLS);	//清屏
			int i = 5;
			//销毁
			if(!L.AddressBook_data){
				free(L.AddressBook_data);
			}
			L.AddressBook_data=NULL;
			L.listsize=L.length=0;
			ClearList(List);
			Csv_Delete_AddressBook(List);
			while (i--) {
				printf("通讯录将在");
				setColor(15, 0);
				printf("%d", i);
				setColor(10, 0);
				printf("秒退出，感谢您的使用");
				Sleep(1000);
				system(SCREEN_CLS);
			}
			exit(0);
		}
			break;
		case 1:
			status = InitAddressBook(L);
			system(SCREEN_CLS);
			meun2();
			if (status) {
				printf(INIT_AB);	//通讯录创建成功
				printf(HINT);
			} else {
				printf(ERROR_INIT_AB);	//通讯录未创建成功
				printf(HINT);

			}
			break;
		case 2: {
			system(SCREEN_CLS);
			meun2();
			status = Load_AddressBook(L);	//加载读取CSV文件中通讯录数据，并返回函数状态
			if (!status) {
				printf(ERROR_CSV);	//没有文件存在
			}
			printf(HINT);
		}
			break;
		case 3: {
			system(SCREEN_CLS);
			meun2();
			Printf_AddressBook(L);
			printf(HINT);
		}
			break;
		case 4: {
			system(SCREEN_CLS);
			meun2();
			printf("请输入信息(回车确定)\n");
			printf(TITLE);
			setColor(15, 0);
			scanf("%s%s%s%s%s%s%s", e.id, e.name, e.sex, e.relationship,
					e.phone_one, e.phone_two, e.email);
			setColor(10, 0);
			Insert_AddressBook(L, e);

			printf(HINT);
		}
			break;
		case 5: {
			system(SCREEN_CLS);
			meun2();
			Printf_AddressBook(L);
			status=Modify_AddressBook(L);
			if(!status){
				printf("修改失败\n");
			}else{
				printf("修改成功\n");
			}
			system(SCREEN_CLS);
			meun2();
			printf(HINT);
		}

			break;
		case 6: {
			system(SCREEN_CLS);
			meun2();
			char index[20];
			int num;
			printf("请选择要查找的项:(1、编号,2、名字,3、性别,4、关系,5、电话1,6、电话2,7、邮件,0、结束)\n");
			setColor(15, 0);
			scanf("%d", &num);
			setColor(10, 0);
			printf("请输入要查询的信息:\n");
			setColor(15, 0);
			scanf("%s", index);
			setColor(10, 0);
			if (num == 1 || num == 2 || num == 5 || num == 6 || num == 7) {
				Search_AddressBook(L, index);
			} else if (num == 3 || num == 4) {
				Filter_AddressBook(L, index);
			}
			printf(HINT);
		}

			break;
		case 7: {
			system(SCREEN_CLS);
			meun2();
			Printf_AddressBook(L);
			Delete_AddressBook(L, List);
			//Csv_Delete_AddressBook(List);
			printf(HINT);
		}

			break;
		case 8: {
			system(SCREEN_CLS);
			meun2();
			//Print_Delete_AddressBook(List);
			status = Read_Delete_AddressBook(List);	//加载读取CSV文件中通讯录数据，并返回函数状态
			if (!status) {
				printf(ERROR_CSV);	//没有文件存在
			}
			printf(HINT);
		}
			break;
		case 9: {
			system(SCREEN_CLS);
			meun2();
			//print_Delete_AddressBook(List);
			status=Renew_Delete_AddressBook(L, List);
			if(!status){
				printf("无此信息\n");
			}
			printf(HINT);
		}
			break;
		case 10: {
			system(SCREEN_CLS);
			meun2();
			Csv_AddressBook(L);
			printf(HINT);
		}

			break;
		default:
			system(SCREEN_CLS);
			meun2();
			printf("请输入正确的数字!\n");
			printf(HINT);
			//scanf("%d", &choice_number);
			break;
		}
	}
	return 0;

}
