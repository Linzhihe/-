#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define LIST_INIT_SIZE 100
#define OVERFLOW -2
#define SCREEN_CLS "cls"
#define TITLE "编号\t姓名\t性别\t关系\t电话1\t\t电话2\t\t邮箱\n"
#define ID "编号"
#define NAME "姓名"
#define SEX "性别"
#define RELATIONSHIP "关系"
#define PHONE_ONE "电话1"
#define PHONE_TWO "电话2"
#define EMAIL "邮箱"
#define HINT "请输入0-10选择功能:"
#define INIT_AB "通讯录创建成功\n"
#define ERROR_INIT_AB "通讯录未创建成功\n"
#define UNINIT_AB "未创建通讯录,请先创建通讯录\n"
#define AB_EMPTY "通讯录为空\n"
#define ERROR_CSV "没有文件...\n"
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
//返回函数状态
Status status = 0;
//通讯录是否存在
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

