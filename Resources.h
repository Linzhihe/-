#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define LIST_INIT_SIZE 100
#define OVERFLOW -2
#define SCREEN_CLS "cls"
#define TITLE "���\t����\t�Ա�\t��ϵ\t�绰1\t\t�绰2\t\t����\n"
#define ID "���"
#define NAME "����"
#define SEX "�Ա�"
#define RELATIONSHIP "��ϵ"
#define PHONE_ONE "�绰1"
#define PHONE_TWO "�绰2"
#define EMAIL "����"
#define HINT "������0-10ѡ����:"
#define INIT_AB "ͨѶ¼�����ɹ�\n"
#define ERROR_INIT_AB "ͨѶ¼δ�����ɹ�\n"
#define UNINIT_AB "δ����ͨѶ¼,���ȴ���ͨѶ¼\n"
#define AB_EMPTY "ͨѶ¼Ϊ��\n"
#define ERROR_CSV "û���ļ�...\n"
typedef int Status;

typedef struct AddressBook {
	char id[20];
	char name[20];
	char sex[20];
	char relationship[20];
	char phone_one[20];
	char phone_two[20];
	char email[20];
} ElemType;

typedef struct {
	char AddressBook_name[20];
	ElemType *AddressBook_data;
	int length;
	int listsize;
} SqList;

typedef struct Node {
	char Delete_AddressBook_name[20];
	ElemType AddressBook_data;
	struct Node *next;
}Node;
typedef struct Node* LinkList;
//���غ���״̬
Status status = 0;
//ͨѶ¼�Ƿ����
Status txl = 0;
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include "ui.h"
#include "ui2.h"
#include "LinkList_AddressBook.h"
#include "List_AddressBook.h"

