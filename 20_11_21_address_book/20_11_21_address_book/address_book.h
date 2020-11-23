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
/* 通讯录实现功能:
	1. 显示通讯录
	2. 添加联系人
	3. 修改联系人
	4. 删除联系人
	5. 清空
	6. 查找联系人
	
	支持添加联系人后 自动排序*/
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