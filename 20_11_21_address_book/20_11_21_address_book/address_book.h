#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#define MAX 1024

typedef struct person{
	char name[1024];
	int age;
	char sex[2];
	char tele[1024];
	char addr[1024];
}person;

typedef struct contact{
	person data[MAX];
	int num;
}contact;
/************************************************************************/
/* ͨѶ¼ʵ�ֹ���:
	1. ��ʾͨѶ¼
	2. �����ϵ��
	3. �޸���ϵ��
	4. ɾ����ϵ��
	5. ���
	6. ������ϵ��
	
	֧�������ϵ�˺� �Զ�����*/
/************************************************************************/
void Show(const contact *table);
void Modify(contact *table);
void Add(contact *table);
void Del(contact *table);
void Empty(contact *table);
void Find(contact *table);

void Book_Init(contact *table);
void Book_sort(contact *table);

void Test();