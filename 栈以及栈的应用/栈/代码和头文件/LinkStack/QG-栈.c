#include"QG-ջ.h"

int main()
{
	LinkStack s;
	initLStack(&s);

	int e;//ջ��Ԫ��
	int length;//ջ����
	ElemType data;
	while (1)
	{
	
		menu();
		int choose;
		printf("�������ѡ��");
		scanf("%d", &choose);

		switch (choose)
		{
		case 1://�ж�ջ�Ƿ�Ϊ��
			isEmptyLStack(&s);
			break;
		case 2://�õ�ջ��Ԫ��
			getTopLStack(&s, &e);
			break;
		case 3://���ջ
			clearLStack(&s);
			break;
		case 4://����ջ
			destroyLStack(&s);
			break;
		case 5://���ջ����
			LStackLength(&s, &length);
			break;
		case 6://��ջ
			printf("����Ҫ��ջ��ֵ��");
			scanf("%d", &data);
			pushLStack(&s, data);
			break;
		case 7://��ջ
			popLStack(&s, &data);
			break;
		default:
			printf("ѡ����Ч��\n");
			break;
		}
	}
}

//�˵�����
void menu()
{
	printf("1.�ж�ջ�Ƿ�Ϊ��\n");
	printf("2.�õ�ջ��Ԫ��\n");
	printf("3.���ջ\n");
	printf("4.����ջ\n");
	printf("5.���ջ����\n");
	printf("6.��ջ\n");
	printf("7.��ջ\n");
	printf("\n");
}

Status initLStack(LinkStack* s)//��ʼ��ջ
{
	s->top = NULL;
	//s->top = 0;
	s->count = 0;
	return 1;
}

Status isEmptyLStack(LinkStack* s)//�ж�ջ�Ƿ�Ϊ��
{
	if (s->top != NULL)
	{
		printf("�ж�ջ��Ϊ��\n");
		return 1;
	}
	printf("�ж�ջΪ��\n");

	system("pause");
	system("cls");
	return 0;
}

Status getTopLStack(LinkStack* s, ElemType* e)//�õ�ջ��Ԫ��
{
	if (s->top != NULL)
	{
		e = s->top->data;
		printf("ջ��Ԫ��e=%d\n", e);
		system("pause");
		system("cls");
		return 1;
	}
	printf("ջΪ�գ���ȡʧ�ܣ�\n");
	system("pause");
	system("cls");
	return 0;
}

Status clearLStack(LinkStack* s)//���ջ
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

Status destroyLStack(LinkStack* s)//����ջ
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

Status LStackLength(LinkStack* s, int* length)//���ջ����
{
	printf("ջ����=%d\n", s->count);
	system("pause");
	system("cls");
	return 1;
}

Status pushLStack(LinkStack* s, ElemType data)//��ջ
{
	LinkStackPtr  newNode = malloc(sizeof(StackNode));
	newNode->data = data;
	newNode->next = s->top;
	s->top = newNode;
	printf("��ջ�ɹ���\n");
	s->count++;
	//����������Ϣ
	printf("ջ����Ϣ�У�");
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

Status popLStack(LinkStack* s, ElemType* data)//��ջ
{
	if (s->top == NULL)
	{
		printf("ջΪ�գ�\n");
		system("pause");
		system("cls");
		return 0;
	}
	LinkStackPtr  p = s->top;
	data = s->top->data;
	s->top = s->top->next;
	free(p);
	printf("��ջ�ɹ���\n");
	s->count--;
	//����������Ϣ
	printf("ջ����Ϣ�У�");
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