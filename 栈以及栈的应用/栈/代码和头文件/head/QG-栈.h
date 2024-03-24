#pragma once
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum Status
{
	ERROR = 0,
    SUCCESS = 1,
}Status;

typedef int ElemType;

//����
typedef  struct StackNode
{
	ElemType data;
	struct StackNode* next;
}StackNode, * LinkStackPtr;

//ջ
typedef  struct  LinkStack
{
	LinkStackPtr top;//ջ��ָ��
	int	count;//��ʾ��ջ�ĳ���
}LinkStack;



//��ջ
Status initLStack(LinkStack* s);//��ʼ��ջ
Status isEmptyLStack(LinkStack* s);//�ж�ջ�Ƿ�Ϊ��
Status getTopLStack(LinkStack* s, ElemType* e);//�õ�ջ��Ԫ��
Status clearLStack(LinkStack* s);//���ջ
Status destroyLStack(LinkStack* s);//����ջ
Status LStackLength(LinkStack* s, int* length);//���ջ����
Status pushLStack(LinkStack* s, ElemType data);//��ջ
Status popLStack(LinkStack* s, ElemType* data);//��ջ
//�˵�����
void menu();

#endif 