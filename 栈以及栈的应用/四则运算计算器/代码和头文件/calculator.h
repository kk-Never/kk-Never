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
    float data;  // 栈改造为float数据，包括后面的入栈出栈。
    struct Node* next;
} Node, * LinkList;

//typedef struct Node* LinkList;

LinkList top;
