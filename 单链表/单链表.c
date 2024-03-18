#include"LinkedList.h"

Status InitList(LinkedList* L)
{
	printf("输入有效节点个数：");
	int k;//含义值的节点个数
	scanf("%d", &k);
	//建立头结点 
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

	printf("输入成功\n");
	//输出链表
	LinkedList b = *L;
	printf("链表信息：");
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
	//输出链表
	LinkedList b = *L;
	printf("链表信息：");
	while (b->next != 0)
	{
		printf("%d ", b->next->data);
		b = b->next;
	}
	printf("\n");
	//system("plaus");
	//system("csl");
}

void menu()//菜单
{
	printf("\n");
	printf("1.销毁链表，释放所有节点\n");
	printf("2.将节点q插入节点p之后\n");
	printf("3.删除节点p后的第一个节点，并将其值赋给e\n");
	//printf("4.根据e找到链表中的第一个节点\n");
	printf("5.倒转链表\n");
	printf("6.判断链表是否循环\n");
	//printf("7.倒转链表中值为偶数的节点，输入:1 ->\n");
	printf("8.找出链表中的中间节点\n");
	printf("9.输出链表信息\n");

}

void DestroyList(LinkedList* L)//销毁链表，释放所有节点
{
	LinkedList p = *L;
	while (*L)
	{
		*L = (*L)->next;
		free(p);
		p = *L;
	}
	printf("销毁成功！");
	//system("cls");
}

void Nodep_and_q(LinkedList* L)//将节点q插入节点p之后
{
	LinkedList p = (*L)->next;
	
	printf("输入p节点的数据：");
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
	printf("输入q节点的数据：");
	scanf("%d", &(q->data));
	LNode* temp = p->next;
	p->next = q;
	q->next = temp;
	//输出链表
	LinkedList b = *L;
	printf("链表信息：");
	while (b->next != 0)
	{
		printf("%d ", b->next->data);
		b = b->next;
	}
	printf("\n");
}

//删除节点p后的第一个节点，并将其值赋给e
Status DeleteList(LNode* p, ElemType* e)
{
	if (p->data == NULL)
		return ERROR;
	LNode* q = p->next;
	p->next = q->next;
	e = q->data;
	
	free(q);
	printf("删除成功！\n");
	printf("e=%d", e);
	return SUCCESS;
}

Status IsLoopList(LinkedList L)//判断链表是否循环
{
	LinkedList fast, slow;
	slow = L;
	fast = L->next;
	while (fast->next == NULL)
	{
		if (fast == slow)
		{
			printf("链表循环！");
			return ERROR;
		}
		else
		{
			fast = fast->next->next;
			slow = slow->next;
		}
	}
	printf("链表不循环！");
}

Status ReverseList(LinkedList* L)//倒转链表
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
	//输出新的链表
	printf("链表信息：");
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

	
	printf("\n输入你的选择：");
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
			printf("输入p节点的数据：");
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
				printf("未找到p节点！");
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
			printf("输入错误！");
			exit(0);
			break;
		}
	}
}