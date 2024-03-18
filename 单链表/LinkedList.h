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

Status InitList(LinkedList* L);//建立链表，初始化链表，头结点没有值
void printList(LinkedList* L);//显示链表
void menu();//菜单
void DestroyList(LinkedList* L);//销毁链表，释放所有节点
void Nodep_and_q(LinkedList* L);//将节点q插入节点p之后

Status DeleteList(LNode* p, ElemType* e);//删除节点p后的第一个节点，并将其值赋给e
Status IsLoopList(LinkedList L);//判断链表是否循环
Status ReverseList(LinkedList* L);//倒转链表
LNode* FindMidNode(LinkedList* L);//找中间值