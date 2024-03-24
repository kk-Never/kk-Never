#include"QG-栈.h"

int main()
{
	LinkStack s;
	initLStack(&s);

	int e;//栈顶元素
	int length;//栈长度
	ElemType data;
	while (1)
	{
	
		menu();
		int choose;
		printf("输入你的选择：");
		scanf("%d", &choose);

		switch (choose)
		{
		case 1://判断栈是否为空
			isEmptyLStack(&s);
			break;
		case 2://得到栈顶元素
			getTopLStack(&s, &e);
			break;
		case 3://清空栈
			clearLStack(&s);
			break;
		case 4://销毁栈
			destroyLStack(&s);
			break;
		case 5://检测栈长度
			LStackLength(&s, &length);
			break;
		case 6://入栈
			printf("输入要入栈的值：");
			scanf("%d", &data);
			pushLStack(&s, data);
			break;
		case 7://出栈
			popLStack(&s, &data);
			break;
		default:
			printf("选择无效！\n");
			break;
		}
	}
}

//菜单函数
void menu()
{
	printf("1.判断栈是否为空\n");
	printf("2.得到栈顶元素\n");
	printf("3.清空栈\n");
	printf("4.销毁栈\n");
	printf("5.检测栈长度\n");
	printf("6.入栈\n");
	printf("7.出栈\n");
	printf("\n");
}

Status initLStack(LinkStack* s)//初始化栈
{
	s->top = NULL;
	//s->top = 0;
	s->count = 0;
	return 1;
}

Status isEmptyLStack(LinkStack* s)//判断栈是否为空
{
	if (s->top != NULL)
	{
		printf("判断栈不为空\n");
		return 1;
	}
	printf("判断栈为空\n");

	system("pause");
	system("cls");
	return 0;
}

Status getTopLStack(LinkStack* s, ElemType* e)//得到栈顶元素
{
	if (s->top != NULL)
	{
		e = s->top->data;
		printf("栈顶元素e=%d\n", e);
		system("pause");
		system("cls");
		return 1;
	}
	printf("栈为空，获取失败！\n");
	system("pause");
	system("cls");
	return 0;
}

Status clearLStack(LinkStack* s)//清空栈
{
	LinkStackPtr p;
	while (s->top) {
		p = s->top;
		s->top = s->top->next;
		s->count--;
		free(p);
	}
	system("pause");
	system("cls");
}

Status destroyLStack(LinkStack* s)//销毁栈
{
	int len = s->count;
	int i;
	for (i = 0; i < len; i++) {
		free(s->top);
		s->top=s->top->next;
	}
	s->top = NULL;

	s->count = 0;
	system("pause");
	system("cls");
}

Status LStackLength(LinkStack* s, int* length)//检测栈长度
{
	printf("栈长度=%d\n", s->count);
	system("pause");
	system("cls");
	return 1;
}

Status pushLStack(LinkStack* s, ElemType data)//入栈
{
	LinkStackPtr  newNode = malloc(sizeof(StackNode));
	newNode->data = data;
	newNode->next = s->top;
	s->top = newNode;
	printf("入栈成功！\n");
	s->count++;
	//输出链表的信息
	printf("栈的信息有：");
	LinkStackPtr  q=s->top;
	while (q != NULL)
	{
		printf("%d ", q->data);
		q = q->next;
	}
	printf("\n");
	system("pause");
	system("cls");
	return 1;
}

Status popLStack(LinkStack* s, ElemType* data)//出栈
{
	if (s->top == NULL)
	{
		printf("栈为空！\n");
		system("pause");
		system("cls");
		return 0;
	}
	LinkStackPtr  p = s->top;
	data = s->top->data;
	s->top = s->top->next;
	free(p);
	printf("出栈成功！\n");
	s->count--;
	//输出链表的信息
	printf("栈的信息有：");
	LinkStackPtr  q = s->top;
	while (q != NULL)
	{
		printf("%d ", q->data);
		q = q->next;
	}

	printf("\n");
	system("pause");
	system("cls");
	return 1;
}