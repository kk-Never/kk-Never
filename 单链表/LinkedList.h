#pragma once
//#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef int ElemType;

// define struct of linked list
typedef struct LNode {
	ElemType data;
	struct LNode* next;
} LNode, * LinkedList;

// define Status
typedef enum Status {
	ERROR,
	SUCCESS
} Status;

Status InitList(LinkedList* L);//����������ʼ������ͷ���û��ֵ
void printList(LinkedList* L);//��ʾ����
void menu();//�˵�
void DestroyList(LinkedList* L);//���������ͷ����нڵ�
void Nodep_and_q(LinkedList* L);//���ڵ�q����ڵ�p֮��

Status DeleteList(LNode* p, ElemType* e);//ɾ���ڵ�p��ĵ�һ���ڵ㣬������ֵ����e
Status IsLoopList(LinkedList L);//�ж������Ƿ�ѭ��
Status ReverseList(LinkedList* L);//��ת����
LNode* FindMidNode(LinkedList* L);//���м�ֵ