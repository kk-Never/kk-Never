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
		printf("\n输入你的选择：");
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
			printf("输入p节点的值：");
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
			printf("输入错误！");
			exit(0);
			break;
		}
	}
}

void menu()//菜单
{
	//system("cls");
	printf("\n");
	printf("1.销毁链表\n");
	printf("2.实现插入功能\n");
	printf("3.打印链表信息\n");
	printf("4.删除节点p后的第一个节点，并将其值赋给e\n");
	printf("5.遍历链表并调用visit函数\n");

}

//初始化一个只有头节点的空链表
Status InitList_DuL(DuLinkedList* L)
{
	printf("输入节点个数：");
	int k;//节点个数
	scanf("%d", &k);
	//建立头结点 
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

	printf("输入成功\n");
	//输出链表
	printf("链表信息：");
	while ((*L)->next != 0)
	{
		printf("%d ", (*L)->next->data);
		(*L) = (*L)->next;
	}
	printf("\n");
	return SUCCESS;
}

//销毁链表
void DestroyList_DuL(DuLinkedList* L)
{
	DuLinkedList p = *L;
	while (*L)
	{
		*L = (*L)->next;
		free(p);
		p = *L;
	}
	printf("销毁成功！");
}

//插入功能
void InsertList(DuLinkedList* L)
{
	DuLinkedList p = (*L)->next;
	DuLNode* q = (DuLinkedList)malloc(sizeof(DuLNode));
	printf("输入q节点的数据：");
	scanf("%d", &(q->data));
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

	printf("选择功能：\n1.在节点p之前插入节点q\n2.将节点q插入节点p之后\n");
	int choose;
	printf("输入选择：");
	scanf("%d", &choose);
	if (choose == 1)
		InsertBeforeList_DuL(&p, &q);
	else
		InsertAfterList_DuL(&p, &q);
}

//输出新的链表
void printList(DuLinkedList L)
{
	DuLNode* move = L->next;
	printf("链表信息：");
	while (move != 0)
	{
		printf("%d ", move->data);
		move = move->next;
	}
	printf("\n");
}

//在节点p之前插入节点q
Status InsertBeforeList_DuL(DuLNode* p, DuLNode* q)
{
	DuLNode* temp = p->prior;
	q->next = p;
	p->prior = q;
	q->prior = temp;
	temp->next = q;
	
	printf("插入成功!");

	return SUCCESS;
}

//将节点q插入节点p之后
Status InsertAfterList_DuL(DuLNode* p, DuLNode* q)
{
	DuLNode* temp = p->next;
	p->next = q;
	q->prior = p;
	q->next = temp;
	temp->prior = q;
	printf("插入成功!");
	return SUCCESS;
}

//删除节点p后的第一个节点，并将其值赋给e
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

//遍历链表并调用visit函数
//void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
//{
//
//}
//
//void (*visit)(ElemType e)
//{
//
//}