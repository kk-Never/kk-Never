#include"duLinkedlist.h"

int main()
{
	DuLNode* L = NULL;
	InitList_DuL(&L);

	ElemType e;
	int delete_p;

	menu();
	
	
	while (1)
	{
		printf("\n�������ѡ��");
		int choose;//=_getch();
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			DestroyList_DuL(&L);
			break;
		case 2:
			//InsertBeforeList_DuL();
			InsertList(&L);
			break;
		case 3:
			printList(L);
			break;
		case 4:
			printf("����p�ڵ��ֵ��");
			scanf("%d", &delete_p);
			DuLNode* p = L->next;
			while (p != NULL)
			{
				if (p->data == delete_p)
					break;
				else
					p = p->next;
			}
			DeleteList_DuL(&p,&e);
			break;
		/*case 5:
			TraverseList_DuL(L,&e);
			break;*/
		default:
			printf("�������");
			exit(0);
			break;
		}
	}
}

void menu()//�˵�
{
	//system("cls");
	printf("\n");
	printf("1.��������\n");
	printf("2.ʵ�ֲ��빦��\n");
	printf("3.��ӡ������Ϣ\n");
	printf("4.ɾ���ڵ�p��ĵ�һ���ڵ㣬������ֵ����e\n");
	printf("5.������������visit����\n");

}

//��ʼ��һ��ֻ��ͷ�ڵ�Ŀ�����
Status InitList_DuL(DuLinkedList* L)
{
	printf("����ڵ������");
	int k;//�ڵ����
	scanf("%d", &k);
	//����ͷ��� 
	*L = (DuLinkedList)malloc(sizeof(DuLNode));
	(*L)->prior = NULL;
	DuLinkedList a = *L;
	//(*L)->next = NULL;
	int i;
	DuLNode* p;
	for (i = k; i > 0; i--)
	{
		p = (DuLinkedList)malloc(sizeof(DuLNode));
		scanf("%d", &(p->data));
		p->next = NULL;
		a->next = p;
		p->prior = a;
		a = p;
	}
	a->next = NULL;
	system("cls");
	//system("plaus");

	printf("����ɹ�\n");
	//�������
	printf("������Ϣ��");
	while ((*L)->next != 0)
	{
		printf("%d ", (*L)->next->data);
		(*L) = (*L)->next;
	}
	printf("\n");
	return SUCCESS;
}

//��������
void DestroyList_DuL(DuLinkedList* L)
{
	DuLinkedList p = *L;
	while (*L)
	{
		*L = (*L)->next;
		free(p);
		p = *L;
	}
	printf("���ٳɹ���");
}

//���빦��
void InsertList(DuLinkedList* L)
{
	DuLinkedList p = (*L)->next;
	DuLNode* q = (DuLinkedList)malloc(sizeof(DuLNode));
	printf("����q�ڵ�����ݣ�");
	scanf("%d", &(q->data));
	printf("����p�ڵ�����ݣ�");
	int p1;
	scanf("%d", &p1);
	getchar();
	while (p != NULL)
	{
		if (p->data == p1)
			break;
		else
			p = p->next;
	}

	printf("ѡ���ܣ�\n1.�ڽڵ�p֮ǰ����ڵ�q\n2.���ڵ�q����ڵ�p֮��\n");
	int choose;
	printf("����ѡ��");
	scanf("%d", &choose);
	if (choose == 1)
		InsertBeforeList_DuL(&p, &q);
	else
		InsertAfterList_DuL(&p, &q);
}

//����µ�����
void printList(DuLinkedList L)
{
	DuLNode* move = L->next;
	printf("������Ϣ��");
	while (move != 0)
	{
		printf("%d ", move->data);
		move = move->next;
	}
	printf("\n");
}

//�ڽڵ�p֮ǰ����ڵ�q
Status InsertBeforeList_DuL(DuLNode* p, DuLNode* q)
{
	DuLNode* temp = p->prior;
	q->next = p;
	p->prior = q;
	q->prior = temp;
	temp->next = q;
	
	printf("����ɹ�!");

	return SUCCESS;
}

//���ڵ�q����ڵ�p֮��
Status InsertAfterList_DuL(DuLNode* p, DuLNode* q)
{
	DuLNode* temp = p->next;
	p->next = q;
	q->prior = p;
	q->next = temp;
	temp->prior = q;
	printf("����ɹ�!");
	return SUCCESS;
}

//ɾ���ڵ�p��ĵ�һ���ڵ㣬������ֵ����e
Status DeleteList_DuL(DuLNode* p, ElemType* e)
{
	DuLNode* temp = p->next;
	if (temp == NULL)
		return ERROR;
	e = temp->data;
	p->next = temp->next;
	free(temp);
	return SUCCESS;
}

//������������visit����
//void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
//{
//
//}
//
//void (*visit)(ElemType e)
//{
//
//}