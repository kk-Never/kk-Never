#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE  100

typedef struct
{
    char data[100];
    int top;
} Stack;

Stack s;

typedef struct Node
{
    float data;  // ջ����Ϊfloat���ݣ������������ջ��ջ��
    struct Node* next;
} Node, * LinkList;

//typedef struct Node* LinkList;

LinkList top;
