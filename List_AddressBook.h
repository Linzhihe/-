Status InitAddressBook(SqList &L) {  //����һ���յ����Ա�L
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
	printf("������Ҫ�򿪵�ͨѶ¼����:\n");
	setColor(15, 0);
	scanf("%s",L.AddressBook_name);
	setColor(10, 0);
	strcat(L.AddressBook_name,".csv");
	FILE *fp; //FILE���������ͣ������ļ���FILE *fp:����fp��ָ�룬����ָ��FILE���͵Ķ���
	//ElemType q;

	fp = fopen(L.AddressBook_name, "r"); //r:��ֻ����ʽ���ļ�
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
Status Printf_AddressBook(SqList &L) { //��ʾͨѶ¼
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
Status Insert_AddressBook(SqList &L, ElemType &e) { //��������
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
Status Modify_AddressBook(SqList &L) { //�޸�ͨѶ¼
	if (txl) {
		int num = -1;
		char index[20];
		printf("��������Ҫ�޸ĵ���Ϣ(��š����֡��绰1���绰2������)��");
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
			printf("��ѡ��Ҫ�޸ĵ���:(1�����,2������,3���Ա�,4����ϵ,5���绰1,6���绰2,7���ʼ�,0������)\n");
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
			printf("δ�ҵ�\n");
			return ERROR;
		}
	} else {
		printf (UNINIT_AB);
	}
	return OK;
}
Status Search_AddressBook(SqList &L, char *index) { //��ѯͨѶ¼
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
			printf("���ҵ���Ϣ:\n");
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
			printf("δ�ҵ���Ϣ");
			return -1;
		}
	} else {
		printf (UNINIT_AB);
	}
}
Status Filter_AddressBook(SqList &L, char *index) { //����ͨѶ¼
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
			printf("�ѹ��˳���Ϣ:\n");
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
			printf("δ�ҵ���Ϣ\n");

		}
	} else {
		printf (UNINIT_AB);
	}

}
Status Delete_AddressBook(SqList &L, LinkList &List) { //ɾ��ͨѶ¼
	if (txl) {
		char str[20];
		printf("������Ҫɾ������Ϣ:");
		setColor(15, 0);
		scanf("%s", str);
		setColor(10, 0);
		int position = Search_AddressBook(L, str);
		if (position != -1) {
			printf("ȷ��ɾ������Ϣ(1:ȷ��    2:����)?\n");
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
				}/* ��ɾ��λ�ú��Ԫ��ǰ�� */
				L.length--;
				system("cls");
				meun2();
				printf("ɾ���ɹ�\n");
			} else {
				printf (HINT);
			}
		} else {
			//printf("δ�ҵ���Ϣ\n");
		}
	} else {
		//printf("δ����ͨѶ¼,���ȴ���ͨѶ¼");
	}

}
Status Csv_AddressBook(SqList &L) {
	printf("�������ļ���:\n");
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
	printf("����ͨѶ¼�ɹ���\n");
}
