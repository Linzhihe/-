Status Init_Delete_AddressBook(LinkList &List) {
	List = (LinkList) malloc(sizeof(Node));
	if (!(List)) {
		return ERROR;
	}
	List->next = NULL;
	return OK;
}

Status Print_Delete_AddressBook(LinkList &List) {
	LinkList L1;
	L1 = List->next;
	while (L1) {
		//visit(L1->AddressBook_data);
		printf("%s\t%s\t%s\t%s\t\t%.20s\t%.20s\t%.20s\n", L1->AddressBook_data.id,
		 L1->AddressBook_data.name, L1->AddressBook_data.sex,
		 L1->AddressBook_data.relationship,
		 L1->AddressBook_data.phone_one, L1->AddressBook_data.phone_two,
		 L1->AddressBook_data.email);
		L1 = L1->next;
	}
	return OK;
}

Status Read_Delete_AddressBook(LinkList &List) {
	FILE *fp; //FILE：变量类型，用于文件；FILE *fp:声明fp是指针，用来指向FILE类型的对象
	fp = fopen("del_txl.csv", "r"); //r:以只读方式打开文件
	if (fp == NULL) {
		return ERROR;
	}
	LinkList L1,L2;
	L1 = List;
	int csv_num = 1;
	printf (TITLE);
	while (!feof(fp)) {
		char str[200];
		fscanf(fp, "%s", str);
		char* token = strtok(str, ",");
		if (strcmp(token, ID) == 0 || strcmp(token, NAME) == 0
				|| strcmp(token, SEX) == 0 || strcmp(token, RELATIONSHIP) == 0
				|| strcmp(token, PHONE_ONE) == 0
				|| strcmp(token, PHONE_TWO) == 0 || strcmp(token, EMAIL) == 0) {
			continue;
		}
		L2= (LinkList) malloc(sizeof(Node));
		//L1 = List->next;
		while (token != NULL) {
			if (csv_num % 7 == 1) {
				printf("%s\t", token);
				strcpy(L2->AddressBook_data.id, token);
			}
			if (csv_num % 7 == 2) {
				printf("%s\t", token);
				strcpy(L2->AddressBook_data.name, token);
			}
			if (csv_num % 7 == 3) {
				printf("%s\t", token);
				strcpy(L2->AddressBook_data.sex, token);
			}
			if (csv_num % 7 == 4) {
				printf("%.20s\t", token);
				strcpy(L2->AddressBook_data.relationship, token);
			}
			if (csv_num % 7 == 5) {
				printf("%.20s\t", token);
				strcpy(L2->AddressBook_data.phone_one, token);
			}
			if (csv_num % 7 == 6) {
				printf("%.20s\t", token);
				strcpy(L2->AddressBook_data.phone_two, token);
			}
			if (csv_num % 7 == 0) {
				printf("%.20s", token);
				strcpy(L2->AddressBook_data.email, token);
				L1->next = L2;
				L1=L2;
				puts("");
			}
			token = strtok(NULL, ",");
			csv_num++;
		}
	}
	L1->next=NULL;
	fclose(fp);
	return OK;
}
Status Csv_Delete_AddressBook(LinkList &List) {
	FILE * file = fopen("del_txl.csv", "w");
	if (file) {
		fprintf(file, "%s%,%s,%s,%s,%s,%s,%s\n", ID, NAME, SEX, RELATIONSHIP,
				PHONE_ONE, PHONE_TWO, EMAIL);
		LinkList L1;
		L1 = List;
		L1 = L1->next;
		while (L1) {
			if (!L1->next) {
				fprintf(file, "%s%,%s,%s,%s,%s,%s,%s", L1->AddressBook_data.id,
						L1->AddressBook_data.name, L1->AddressBook_data.sex,
						L1->AddressBook_data.relationship,
						L1->AddressBook_data.phone_one,
						L1->AddressBook_data.phone_two,
						L1->AddressBook_data.email);
			} else {
				fprintf(file, "%s%,%s,%s,%s,%s,%s,%s\n",
						L1->AddressBook_data.id, L1->AddressBook_data.name,
						L1->AddressBook_data.sex,
						L1->AddressBook_data.relationship,
						L1->AddressBook_data.phone_one,
						L1->AddressBook_data.phone_two,
						L1->AddressBook_data.email);
			}
			L1 = L1->next;
		}
	}
	fclose(file);

}
Status Renew_Delete_AddressBook(SqList &L, LinkList &List) {
	printf("已删除的信息：\n");
	LinkList L2;
	Print_Delete_AddressBook(List);
	printf("输入要恢复的信息：\n");
	LinkList position = NULL;
	char str[20];
	setColor(15, 0);
	scanf("%s", str);
	setColor(10, 0);
	L2 = List->next;
	while (L2) {
		if (strcmp(str, L2->AddressBook_data.id) == 0) {
			position = L2;
			break;
		}
		if (strcmp(str, L2->AddressBook_data.name) == 0) {
			position = L2;
			break;
		}
		if (strcmp(str, L2->AddressBook_data.phone_one) == 0) {
			position = L2;
			break;
		}
		if (strcmp(str, L2->AddressBook_data.phone_two) == 0) {
			position = L2;
			break;
		}
		if (strcmp(str, L2->AddressBook_data.email) == 0) {
			position = L2;
			break;
		}
		L2 = L2->next;
	}
	if (position) {
		printf (TITLE);
		printf("%s\t%s\t%s\t%s\t%.11s\t%.11s\t%.20s\n",
				position->AddressBook_data.id, position->AddressBook_data.name,
				position->AddressBook_data.sex,
				position->AddressBook_data.relationship,
				position->AddressBook_data.phone_one,
				position->AddressBook_data.phone_two,
				position->AddressBook_data.email);
		printf("确认恢复此信息(1:确认    2:返回)?\n");
		int whether;
		setColor(15, 0);
		scanf("%d", &whether);
		setColor(10, 0);
		if (whether == 1) {
			strcpy(L.AddressBook_data[L.length].id,
					position->AddressBook_data.id);
			strcpy(L.AddressBook_data[L.length].name,
					position->AddressBook_data.name);
			strcpy(L.AddressBook_data[L.length].sex,
					position->AddressBook_data.sex);
			strcpy(L.AddressBook_data[L.length].relationship,
					position->AddressBook_data.relationship);
			strcpy(L.AddressBook_data[L.length].phone_one,
					position->AddressBook_data.phone_one);
			strcpy(L.AddressBook_data[L.length].phone_two,
					position->AddressBook_data.phone_two);
			strcpy(L.AddressBook_data[L.length].email,
					position->AddressBook_data.email);
			L.length++;
			LinkList L3;
			L3 = List;
			while (L3->next != position) {
				L3 = L3->next;
			}
			position = L3->next;
			L3->next = position->next;
			//L3 = position->next;
			//	position->next = L3->next;
			free(position);
			Csv_Delete_AddressBook(List);
		}

	} else {
		return ERROR;
	}

	return OK;
}
Status Insert_Delete_AddressBook(LinkList &List, ElemType e) {
	LinkList L1, L2;
	L1 = List;
	L2 = (LinkList) malloc(sizeof(Node));
	while (L1->next != NULL) {
		L1 = L1->next; //遍历找到尾节点
	}
	L2->AddressBook_data = e;
	L1->next = L2;
	L2->next = NULL;
	Csv_Delete_AddressBook(List);
	return OK;
}
Status ClearList(LinkList &List) {
	LinkList L1, L2;
	L1 = List->next; /*  p指向第一个结点 */
	while (L1) /*  没到表尾 */
	{
		L2 = L1->next;
		free(L1);
		L1 = L2;
	}
	List->next = NULL; /* 头结点指针域为空 */
	return OK;
}
