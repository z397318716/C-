#include"address_book.h"
enum option{
	SHOW,
	MODIFY,
	ADD,
	DEL,
	EMPTY,
	FIND
};

// ��ʾ��ϵ��
void Show(const contact *table){

}
// �޸���ϵ��
void Modify(contact *table)
{

}
// �����ϵ��
void Add(contact *table)
{

}
// ɾ����ϵ��
void Del(contact *table)
{

}
// ���ͨѶ¼
void Empty(contact *table)
{

}
// ������ϵ��
void Find(contact *table)
{

}

// ��ʼ��ͨѶ¼
void Book_Init(contact *table)
{

}
// ��ͨѶ¼����
void Book_sort(contact *table)
{

}

void menu(){
	printf("0. ��ʾͨѶ¼\n");
	printf("1. �޸���ϵ��\n");
	printf("2. �����ϵ��\n");
	printf("3. ɾ����ϵ��\n");
	printf("4. �����ϵ��\n");
	printf("5. ������ϵ��\n");
}
void Test(){
	// ����ͨѶ¼
	struct contact table;
	Book_Init(&table);
	int input = 0;
	while (1){
		menu();
		printf("����ѡ��: \n");
		scanf("%d", &input);
		switch (input){
		case SHOW:
			Show(&table);
			break;
		case MODIFY:
			Modify(&table);
			break;
		case ADD:
			Add(&table);
			break;
		case DEL:
			Del(&table);
			break;
		case EMPTY:
			Empty(&table);
			break;
		case FIND:
			Find(&table);
			break;
		default:
			break;
		}
	}
}
int main(){
	Test();

	return 0;
}