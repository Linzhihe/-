//============================================================================
// Name        : new_AddressBook.cpp
// Author      : �ֵ���
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Resources.h"
using namespace std;
int main() {
	//�˵���
	meun();
	ElemType e;
	SqList L;
	LinkList List;
	Init_Delete_AddressBook(List);
	//Csv_Delete_AddressBook(List);
	int choice_number;
	while (1) {
		setColor(15, 0);
		scanf("%d", &choice_number); //����ѡ��
		setColor(10, 0);
		switch (choice_number) {
		case 0: {
			system(SCREEN_CLS);	//����
			int i = 5;
			//����
			if(!L.AddressBook_data){
				free(L.AddressBook_data);
			}
			L.AddressBook_data=NULL;
			L.listsize=L.length=0;
			ClearList(List);
			Csv_Delete_AddressBook(List);
			while (i--) {
				printf("ͨѶ¼����");
				setColor(15, 0);
				printf("%d", i);
				setColor(10, 0);
				printf("���˳�����л����ʹ��");
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
				printf(INIT_AB);	//ͨѶ¼�����ɹ�
				printf(HINT);
			} else {
				printf(ERROR_INIT_AB);	//ͨѶ¼δ�����ɹ�
				printf(HINT);

			}
			break;
		case 2: {
			system(SCREEN_CLS);
			meun2();
			status = Load_AddressBook(L);	//���ض�ȡCSV�ļ���ͨѶ¼���ݣ������غ���״̬
			if (!status) {
				printf(ERROR_CSV);	//û���ļ�����
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
			printf("��������Ϣ(�س�ȷ��)\n");
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
				printf("�޸�ʧ��\n");
			}else{
				printf("�޸ĳɹ�\n");
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
			printf("��ѡ��Ҫ���ҵ���:(1�����,2������,3���Ա�,4����ϵ,5���绰1,6���绰2,7���ʼ�,0������)\n");
			setColor(15, 0);
			scanf("%d", &num);
			setColor(10, 0);
			printf("������Ҫ��ѯ����Ϣ:\n");
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
			status = Read_Delete_AddressBook(List);	//���ض�ȡCSV�ļ���ͨѶ¼���ݣ������غ���״̬
			if (!status) {
				printf(ERROR_CSV);	//û���ļ�����
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
				printf("�޴���Ϣ\n");
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
			printf("��������ȷ������!\n");
			printf(HINT);
			//scanf("%d", &choice_number);
			break;
		}
	}
	return 0;

}
