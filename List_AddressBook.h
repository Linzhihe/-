Status InitAddressBook(SqList &L) {  //构造一个空的线性表L
	txl = 1;
	strcpy(L.AddressBook_name, "");
	L.AddressBook_data = (ElemType *) malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.AddressBook_data) {
		return ERROR;
	}
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}
Status Load_AddressBook(SqList &L) {
	InitAddressBook(L);
	printf("请输入要打开的通讯录名称:\n");
	setColor(15, 0);
	scanf("%s",L.AddressBook_name);
	setColor(10, 0);
	strcat(L.AddressBook_name,".csv");
	FILE *fp; //FILE：变量类型，用于文件；FILE *fp:声明fp是指针，用来指向FILE类型的对象
	//ElemType q;

	fp = fopen(L.AddressBook_name, "r"); //r:以只读方式打开文件
	if (fp == NULL) {
		return ERROR;
	}
	int csv_num = 1, j = 0;
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
		while (token != NULL) {
			if (csv_num % 7 == 1) {
				printf("%s\t", token);
				strcpy(L.AddressBook_data[j].id, token);
			}
			if (csv_num % 7 == 2) {
				printf("%s\t", token);
				strcpy(L.AddressBook_data[j].name, token);
			}
			if (csv_num % 7 == 3) {
				printf("%s\t", token);
				strcpy(L.AddressBook_data[j].sex, token);
			}
			if (csv_num % 7 == 4) {
				printf("%s\t", token);
				strcpy(L.AddressBook_data[j].relationship, token);
			}
			if (csv_num % 7 == 5) {
				printf("%.20s\t", token);
				strcpy(L.AddressBook_data[j].phone_one, token);
			}
			if (csv_num % 7 == 6) {
				printf("%.20s\t", token);
				strcpy(L.AddressBook_data[j].phone_two, token);
			}
			if (csv_num % 7 == 0) {
				printf("%.20s", token);
				strcpy(L.AddressBook_data[j].email, token);
				L.length++;
				if (L.length > L.listsize) {
					return ERROR;
				}
				j++;
				puts("");
			}
			/*if (csv_num % 7 == 0) {
			 L.length++;
			 if (L.length > L.listsize) {
			 return ERROR;
			 }
			 j++;
			 puts("");
			 }*/
			token = strtok(NULL, ",");
			csv_num++;
		}
	}
	fclose(fp);
	return OK;
}
Status Printf_AddressBook(SqList &L) { //显示通讯录
	if (txl) {
		if (L.length) {
			printf (TITLE);
			for (int i = 0; i < L.length; ++i) {
				printf("%s\t%s\t%s\t%s\t%.20s\t%.20s\t%.20s\n",
						L.AddressBook_data[i].id, L.AddressBook_data[i].name,
						L.AddressBook_data[i].sex,
						L.AddressBook_data[i].relationship,
						L.AddressBook_data[i].phone_one,
						L.AddressBook_data[i].phone_two,
						L.AddressBook_data[i].email);
			}
		} else {
			printf (AB_EMPTY);
		}
	} else {
		printf (UNINIT_AB);
	}

}
Status Insert_AddressBook(SqList &L, ElemType &e) { //增加数据
	if (txl) {
		if (L.length > L.listsize) {
			ElemType *newbase;
			newbase = (ElemType *) realloc(L.AddressBook_data,
					(L.listsize + LIST_INIT_SIZE) * sizeof(ElemType));
			if (!newbase) {
				return ERROR;
			}
			L.AddressBook_data = newbase;
			L.listsize += LIST_INIT_SIZE;
		}
		strcpy(L.AddressBook_data[L.length].id, e.id);
		strcpy(L.AddressBook_data[L.length].name, e.name);
		strcpy(L.AddressBook_data[L.length].sex, e.sex);
		strcpy(L.AddressBook_data[L.length].relationship, e.relationship);
		strcpy(L.AddressBook_data[L.length].phone_one, e.phone_one);
		strcpy(L.AddressBook_data[L.length].phone_two, e.phone_two);
		strcpy(L.AddressBook_data[L.length].email, e.email);
		L.length++;
	} else {
		printf (UNINIT_AB);
	}
}
Status Modify_AddressBook(SqList &L) { //修改通讯录
	if (txl) {
		int num = -1;
		char index[20];
		printf("请输入需要修改的信息(编号、名字、电话1、电话2、邮箱)：");
		setColor(15, 0);
		scanf("%s", index);
		setColor(10, 0);
		for (int i = 0; i < L.length; ++i) {
			if (strcmp(index, L.AddressBook_data[i].id) == 0) {
				num = i;
			}
			if (strcmp(index, L.AddressBook_data[i].name) == 0) {
				num = i;
			}
			if (strcmp(index, L.AddressBook_data[i].phone_one) == 0) {
				num = i;
			}
			if (strcmp(index, L.AddressBook_data[i].phone_two) == 0) {
				num = i;
			}
			if (strcmp(index, L.AddressBook_data[i].email) == 0) {
				num = i;
			}
		}
		if (num != -1) {
			printf("%s\t%s\t%s\t%s\t%.20s\t%.20s\t%.20s\n",
					L.AddressBook_data[num].id, L.AddressBook_data[num].name,
					L.AddressBook_data[num].sex,
					L.AddressBook_data[num].relationship,
					L.AddressBook_data[num].phone_one,
					L.AddressBook_data[num].phone_two,
					L.AddressBook_data[num].email);
			printf("请选择要修改的项:(1、编号,2、名字,3、性别,4、关系,5、电话1,6、电话2,7、邮件,0、结束)\n");
			int num1[7] = { 0 }, i = 0;
			setColor(15, 0);
			scanf("%d", &num1[i]);
			setColor(10, 0);
			while (num1[i]) {
				i++;
				scanf("%d", &num1[i]);
			}
			for (int j = 0; j < i; ++j) {
				switch (num1[j]) {
				case 1:
					printf("%s\t", ID);
					break;
				case 2:
					printf("%s\t", NAME);
					break;
				case 3:
					printf("%s\t", SEX);
					break;
				case 4:
					printf("%s\t", RELATIONSHIP);
					break;
				case 5:
					printf("%s\t\t", PHONE_ONE);
					break;
				case 6:
					printf("%s\t\t", PHONE_TWO);
					break;
				case 7:
					printf("%s", EMAIL);
					break;
				default:
					break;
				}
				if (j == i - 1) {
					puts("");
				}
			}
			for (int j = 0; j < i; ++j) {
				switch (num1[j]) {
				case 1:
					scanf("%s", L.AddressBook_data[num].id);
					break;
				case 2:
					scanf("%s", L.AddressBook_data[num].name);
					break;
				case 3:
					scanf("%s", L.AddressBook_data[num].sex);
					break;
				case 4:
					scanf("%s", L.AddressBook_data[num].relationship);
					break;
				case 5:
					scanf("%s", L.AddressBook_data[num].phone_one);
					break;
				case 6:
					scanf("%s", L.AddressBook_data[num].phone_two);
					break;
				case 7:
					scanf("%s", L.AddressBook_data[num].email);
					break;
				default:
					break;
				}
			}
		} else {
			printf("未找到\n");
			return ERROR;
		}
	} else {
		printf (UNINIT_AB);
	}
	return OK;
}
Status Search_AddressBook(SqList &L, char *index) { //查询通讯录
	if (txl) {
		int num = -1;
		for (int i = 0; i < L.length && num == -1; ++i) {
			if (strcmp(index, L.AddressBook_data[i].id) == 0) {
				num = i;
			}
			if (strcmp(index, L.AddressBook_data[i].name) == 0) {
				num = i;
			}
			if (strcmp(index, L.AddressBook_data[i].phone_one) == 0) {
				num = i;
			}
			if (strcmp(index, L.AddressBook_data[i].phone_two) == 0) {
				num = i;
			}
			if (strcmp(index, L.AddressBook_data[i].email) == 0) {
				num = i;
			}
		}
		if (num != -1) {
			printf("已找到信息:\n");
			printf(TITLE);
			printf("%s\t%s\t%s\t%s\t%.20s\t%.20s\t%.20s\n",
					L.AddressBook_data[num].id, L.AddressBook_data[num].name,
					L.AddressBook_data[num].sex,
					L.AddressBook_data[num].relationship,
					L.AddressBook_data[num].phone_one,
					L.AddressBook_data[num].phone_two,
					L.AddressBook_data[num].email);
			return num;
		} else {
			printf("未找到信息");
			return -1;
		}
	} else {
		printf (UNINIT_AB);
	}
}
Status Filter_AddressBook(SqList &L, char *index) { //过滤通讯录
	if (txl) {
		int num[L.length] = { 0 }, j = 0, temp = 0;
		for (int i = 0; i < L.length; ++i) {
			if (strcmp(index, L.AddressBook_data[i].relationship) == 0) {
				temp = 1;
				num[j++] = i;
			}
			if (strcmp(index, L.AddressBook_data[i].sex) == 0) {
				temp = 1;
				num[j++] = i;
			}

		}
		if (temp) {
			printf("已过滤出信息:\n");
			printf (TITLE);
			for (int i = 0; i < j; ++i) {
				printf("%s\t%s\t%s\t%s\t%.20s\t%.20s\t%.20s\n",
						L.AddressBook_data[num[i]].id,
						L.AddressBook_data[num[i]].name,
						L.AddressBook_data[num[i]].sex,
						L.AddressBook_data[num[i]].relationship,
						L.AddressBook_data[num[i]].phone_one,
						L.AddressBook_data[num[i]].phone_two,
						L.AddressBook_data[num[i]].email);
			}
		} else {
			printf("未找到信息\n");

		}
	} else {
		printf (UNINIT_AB);
	}

}
Status Delete_AddressBook(SqList &L, LinkList &List) { //删除通讯录
	if (txl) {
		char str[20];
		printf("请输入要删除的信息:");
		setColor(15, 0);
		scanf("%s", str);
		setColor(10, 0);
		int position = Search_AddressBook(L, str);
		if (position != -1) {
			printf("确认删除此信息(1:确认    2:返回)?\n");
			int whether;
			setColor(15, 0);
			scanf("%d", &whether);
			setColor(10, 0);
			if (whether == 1) {
				//Init_Delete_AddressBook(List);
				Insert_Delete_AddressBook(List, L.AddressBook_data[position]);
				int k;
				for (k = position; k < L.length; k++) {
					strcpy(L.AddressBook_data[k].id,
							L.AddressBook_data[k + 1].id);
					strcpy(L.AddressBook_data[k].name,
							L.AddressBook_data[k + 1].name);
					strcpy(L.AddressBook_data[k].sex,
							L.AddressBook_data[k + 1].sex);
					strcpy(L.AddressBook_data[k].relationship,
							L.AddressBook_data[k + 1].relationship);
					strcpy(L.AddressBook_data[k].phone_one,
							L.AddressBook_data[k + 1].phone_one);
					strcpy(L.AddressBook_data[k].phone_two,
							L.AddressBook_data[k + 1].phone_two);
					strcpy(L.AddressBook_data[k].email,
							L.AddressBook_data[k + 1].email);
				}/* 将删除位置后继元素前移 */
				L.length--;
				system("cls");
				meun2();
				printf("删除成功\n");
			} else {
				printf (HINT);
			}
		} else {
			//printf("未找到信息\n");
		}
	} else {
		//printf("未创建通讯录,请先创建通讯录");
	}

}
Status Csv_AddressBook(SqList &L) {
	printf("请输入文件名:\n");
	setColor(15, 0);
	scanf("%s",L.AddressBook_name);
	setColor(10, 0);
	strcat(L.AddressBook_name,".csv");
	FILE * file = fopen(L.AddressBook_name, "w");
	int i;
	if (file) {
		fprintf(file, "%s%,%s,%s,%s,%s,%s,%s\n", ID, NAME, SEX, RELATIONSHIP,
				PHONE_ONE, PHONE_TWO, EMAIL);
		for (i = 0; i < L.length; i++) {

			if (i == L.length - 1) {
				fprintf(file, "%s%,%s,%s,%s,%s,%s,%s", L.AddressBook_data[i].id,
						L.AddressBook_data[i].name, L.AddressBook_data[i].sex,
						L.AddressBook_data[i].relationship,
						L.AddressBook_data[i].phone_one,
						L.AddressBook_data[i].phone_two,
						L.AddressBook_data[i].email);
			} else {
				fprintf(file, "%s%,%s,%s,%s,%s,%s,%s\n",
						L.AddressBook_data[i].id, L.AddressBook_data[i].name,
						L.AddressBook_data[i].sex,
						L.AddressBook_data[i].relationship,
						L.AddressBook_data[i].phone_one,
						L.AddressBook_data[i].phone_two,
						L.AddressBook_data[i].email);
			}
		}
	}
	fclose(file);
	printf("导出通讯录成功。\n");
}
