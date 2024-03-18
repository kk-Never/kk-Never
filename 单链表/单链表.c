#include"LinkedList.h"

Status InitList(LinkedList* L)
{
	printf("������Ч�ڵ������");
	int k;//����ֵ�Ľڵ����
	scanf("%d", &k);
	//����ͷ��� 
	*L = (LinkedList)malloc(sizeof(LNode));
	LinkedList a = *L;
	//(*L)->next = NULL;
	int i;
	LNode* p;
	for (i = k; i > 0; i--)
	{
		p = (LinkedList)malloc(sizeof(LNode));
		scanf("%d", &(p->data));
		//p->next = (*L)->next;
		a->next = p;
		a = p;
	}
	a->next = NULL;
	system("cls");
	//system("plaus");

	printf("����ɹ�\n");
	//�������
	LinkedList b = *L;
	printf("������Ϣ��");
	while (b->next != 0)
	{
		printf("%d ", b->next->data);
		b = b->next;
	}
	printf("\n");
	return SUCCESS;
}

void printList(LinkedList* L)
{
	if ((*L) == NULL)
		return;
	//�������
	LinkedList b = *L;
	printf("������Ϣ��");
	while (b->next != 0)
	{
		printf("%d ", b->next->data);
		b = b->next;
	}
	printf("\n");
	//system("plaus");
	//system("csl");
}

void menu()//�˵�
{
	printf("\n");
	printf("1.���������ͷ����нڵ�\n");
	printf("2.���ڵ�q����ڵ�p֮��\n");
	printf("3.ɾ���ڵ�p��ĵ�һ���ڵ㣬������ֵ����e\n");
	//printf("4.����e�ҵ������еĵ�һ���ڵ�\n");
	printf("5.��ת����\n");
	printf("6.�ж������Ƿ�ѭ��\n");
	//printf("7.��ת������ֵΪż���Ľڵ㣬����:1 ->\n");
	printf("8.�ҳ������е��м�ڵ�\n");
	printf("9.���������Ϣ\n");

}

void DestroyList(LinkedList* L)//���������ͷ����нڵ�
{
	LinkedList p = *L;
	while (*L)
	{
		*L = (*L)->next;
		free(p);
		p = *L;
	}
	printf("���ٳɹ���");
	//system("cls");
}

void Nodep_and_q(LinkedList* L)//���ڵ�q����ڵ�p֮��
{
	LinkedList p = (*L)->next;
	
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
	//InsertList(&p,&q);
	LNode* q = (LinkedList)malloc(sizeof(LNode));
	q->next = NULL;
	printf("����q�ڵ�����ݣ�");
	scanf("%d", &(q->data));
	LNode* temp = p->next;
	p->next = q;
	q->next = temp;
	//�������
	LinkedList b = *L;
	printf("������Ϣ��");
	while (b->next != 0)
	{
		printf("%d ", b->next->data);
		b = b->next;
	}
	printf("\n");
}

//ɾ���ڵ�p��ĵ�һ���ڵ㣬������ֵ����e
Status DeleteList(LNode* p, ElemType* e)
{
	if (p->data == NULL)
		return ERROR;
	LNode* q = p->next;
	p->next = q->next;
	e = q->data;
	
	free(q);
	printf("ɾ���ɹ���\n");
	printf("e=%d", e);
	return SUCCESS;
}

Status IsLoopList(LinkedList L)//�ж������Ƿ�ѭ��
{
	LinkedList fast, slow;
	slow = L;
	fast = L->next;
	while (fast->next == NULL)
	{
		if (fast == slow)
		{
			printf("����ѭ����");
			return ERROR;
		}
		else
		{
			fast = fast->next->next;
			slow = slow->next;
		}
	}
	printf("����ѭ����");
}

Status ReverseList(LinkedList* L)//��ת����
{
	LNode* new_head = NULL;
	LNode* temp = NULL;
	//    if((*L)==NULL||(*L)->next==NULL)
	//    {
	//        return ERROR;
	//    }
	LinkedList K = (*L)->next;
	while (K!= NULL)
	{
		temp = K;
		K = K->next;
		temp->next = new_head;
		new_head = temp;
	}
	*L = new_head;
	//����µ�����
	printf("������Ϣ��");
	while (new_head!= NULL)
	{
		printf("%d ", new_head->data);
		new_head = new_head->next;
	}
	printf("\n");
	return SUCCESS;
}

LNode* FindMidNode(LinkedList* L) {
	LNode* slow = (*L);
	LNode* fast = *L;
	while (fast->next != NULL && fast->next->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
	}
	printf("mid=%d\n", slow->data);
}

int main()
{
	LNode* L = NULL;
	InitList(&L);

	
	printf("\n�������ѡ��");
	int choose;//=_getch();
	
	while (1)
	{
		int e;
		//system("cls");
		menu();
        scanf("%d", &choose);
	    getchar();
	 	switch (choose)
		{
		case 1:
			DestroyList(&L);
			break;
		case 2:
			Nodep_and_q(&L);
			//InsertList(&L,&L);
			break;
		case 3:
			printf("����p�ڵ�����ݣ�");
			int p_data;
			scanf("%d", &p_data);
			LNode* p = L->next;
			while (p != NULL)
			{
				if (p->data == p_data)
				{
					DeleteList(p, &e);
					break;
				}
				else
					p = p->next;
			}
			if (p == NULL)
			{
				printf("δ�ҵ�p�ڵ㣡");
			}
			break;
		case 5:
			ReverseList(&L);
			break;
		case 6:
			IsLoopList(L);
			break;
		case 8:
			FindMidNode(&L);
			break;
		case 9:
			printList(&L);
			break;
		default:
			printf("�������");
			exit(0);
			break;
		}
	}
}