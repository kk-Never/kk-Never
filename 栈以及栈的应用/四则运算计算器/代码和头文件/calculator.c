#include"calculator.h"

//�ж�ջ�Ƿ�Ϊ��
int isEmpty()
{
    if (s.top > 0)
    {
        return 0;
    }
    return 1;
}

//��ջ
int Push(char opt)
{
    if (s.top == 100)//�ж�ջ�Ƿ���
    {
        return -1;
    }
    s.data[s.top] = opt;
    s.top++;

    return 1;
}

//��ջ
int Pop()
{
    if (s.top == 0)//�ж�ջ�Ƿ�Ϊ��
    {
        return -1;
    }

    s.data[s.top - 1] = '\0';
    s.top--;
    return 1;
}

//��ȡջ��Ԫ�ز���ջ
char Peek()
{
    if (s.top == 0)
    {
        return '\0';
    }

    char e = s.data[s.top - 1];
    s.data[s.top - 1] = '\0';
    s.top--;
    return e;
}

//��ȡջ��Ԫ�ز�����ջ��Ԫ��
char getEleTop()
{
    if (s.top == 0)
    {
        return '\0';
    }

    char e = s.data[s.top - 1];
    return e;
}

//��ʼ������
void initNumStack()
{
    top = (malloc)(sizeof(Node));
    top->next = NULL;
}
//����������Ϣ
void PushNum(float data)
{
    LinkList node = (malloc)(sizeof(Node));
    node->data = data;
    node->next = top->next;
    top->next = node;
}

//���������Ϣ
float PeekNum()
{
    if (top->next == NULL)
    {
        return 0;
    }
    LinkList topEle = top->next;

    float data = topEle->data;

    top->next = topEle->next;
    free(topEle);
    return data;
}
//�ж������Ƿ�Ϊ��
int isEmptyNum()
{
    if (top->next == NULL)
    {
        return 1;
    }

    return 0;
}

//�ж�����������ȼ�
int opt(char signal)
{
    if (signal == '+' || signal == '-')
    {
        return 1;
    }
    else if (signal == '*' || signal == '/')
    {
        return 2;
    }
}

// �����߼�����Լ�����ֵ��Ϊfloat
float caculateTopTwoEle(float firstValue, float secondValue, char signal)
{
    if (signal == '+')
    {
        return secondValue + firstValue;
    }
    else if (signal == '-')
    {
        return secondValue - firstValue;
    }
    else if (signal == '*')
    {
        return secondValue * firstValue;
    }
    else if (signal == '/')
    {
        return secondValue / firstValue;
    }

    return 0;
}

//�жϱ��ʽ�Ƿ���ȷ
int isValid(char express[])
{
    //��ʼ��ջ
    s.top = 0;
    int i;
    for (i = 0; i < strlen(express); i++)
    {
        char c = express[i];
 
        // 1�����ж�����ı��ʽ�Ƿ�������0-9 . ( ) + - * / ������ַ���
        if (!(c >= '0' && c <= '9' || c == '.' || c == '(' || c == ')' || c == '+' || c == '-' || c == '*' || c == '/'))
        {
            return 0;
        }

        // 2���������Ų�ƥ�������
        if (express[i] == '(')
        {
            if (i < strlen(express) - 1 && express[i + 1] == ')')
            {// ()
                return 0;
            }
            Push('(');
        }
        else if (express[i] == ')')
        {
            if (i < strlen(express) - 1 && express[i + 1] == '(')
            { // )(
                return 0;
            }

            if (isEmpty())
            {
                return 0;
            }

            Pop();
        }
        else if (express[i] == '+' || express[i] == '*' || express[i] == '/')
        {
            // -5+6   6+5*
            if (i == 0 || i == strlen(express) - 1)
            {
                return 0;
            }

            // (+9*2)
            if (i != 0 && express[i - 1] == '(')
            {
                return 0;
            }

            // (9*2+)
            if (i < strlen(express) - 1 && express[i + 1] == ')')
            {
                return 0;
            }

            // 8++9
            if (i < strlen(express) - 1)
            {
                char nextChar = express[i + 1];
                if (nextChar == '+' || nextChar == '*' || nextChar == '/'|| nextChar == '-')
                {
                    return 0;
                }
            }
        }
    }

    if (!isEmpty())
    {
        return 0;
    }
    return 1;
}

int main()
{
    initNumStack();
    char express[100];

    while (1)
    {
        printf("��������Ҫ����ı��ʽ��");
        scanf("%s", express);
        int valid = isValid(express);
        if (valid == 0)
        {
            printf("��Ҫ����ı��ʽ���Ϸ���\n");
            return;
        }

        initNumStack();
        int i;
        for (i = 0; i < strlen(express); i++)
        {
            // -9.3+(3--2)*3+10/2.2
            if (express[i] == '+' || (express[i] == '-' && i != 0 && express[i - 1] >= '0') && express[i - 1] <= '9' || express[i] == '*' || express[i] == '/')
            {
                if (isEmpty())
                {
                    Push(express[i]);
                    continue;
                }

                char topEle = getEleTop();
                if (topEle == '(')
                {
                    Push(express[i]);
                    continue;
                }

                while (opt(topEle) >= opt(express[i]))
                {
                    printf("%c ", Peek());
                    float firstValue = PeekNum();
                    float secondValue = PeekNum();
                    float result = caculateTopTwoEle(firstValue, secondValue, topEle);
                    PushNum(result);
                    topEle = getEleTop();
                }

                Push(express[i]);
            }
            else if (express[i] == '(')
            {
                Push(express[i]);
            }
            else if (express[i] == ')')
            {
                char topEle = Peek();
                while (topEle != '(')
                {
                    printf("%c ", topEle);
                    float firstValue = PeekNum();
                    float secondValue = PeekNum();
                    float result = caculateTopTwoEle(firstValue, secondValue, topEle);
                    PushNum(result);
                    topEle = Peek();
                }
            }
            else
            {
                char num[10];
                int index = 0;
                printf("%c", express[i]);
                num[index++] = express[i];
                int j;
                int isEnd = 0;
                // -9.3+(3--2)*3+10/2.2
                for (j = 1; i + j < strlen(express); j++)
                {
                    if (express[i + j] >= '0' && express[i + j] <= '9' || express[i + j] == '.') // ����ж���䣬����һ�����ߵ���.
                    {
                        printf("%c", express[i + j]);
                        num[index++] = express[i + j];
                        if (i + j == strlen(express) - 1)
                        {
                            isEnd = 1;
                        }
                    }
                    else
                    {
                        i = i + j - 1;
                        printf(" ");
                        break;
                    }
                }
                num[index++] = '\0';
                float value = atof(num);  // atoi���ɽ��ַ���ת��ΪС��float����double�ĺ���
                PushNum(value);
                if (isEnd)
                {
                    break;
                }
            }
        }

        while (!isEmpty())
        {
            char topEle = Peek();
            float firstValue = PeekNum();
            float secondValue = PeekNum();
            float result = caculateTopTwoEle(firstValue, secondValue, topEle);
            PushNum(result);
            printf("%c ", topEle);
        }

        printf("=%f\n", PeekNum());
    }
    return 0;
}