#include"address_book.h"
enum option{
	SHOW,
	MODIFY,
	ADD,
	DEL,
	EMPTY,
	FIND
};

// 显示联系人
void Show(const contact *table){

}
// 修改联系人
void Modify(contact *table)
{

}
// 添加联系人
void Add(contact *table)
{

}
// 删除联系人
void Del(contact *table)
{

}
// 清空通讯录
void Empty(contact *table)
{

}
// 查找联系人
void Find(contact *table)
{

}

// 初始化通讯录
void Book_Init(contact *table)
{

}
// 对通讯录排序
void Book_sort(contact *table)
{

}

void menu(){
	printf("0. 显示通讯录\n");
	printf("1. 修改联系人\n");
	printf("2. 添加联系人\n");
	printf("3. 删除联系人\n");
	printf("4. 清空联系人\n");
	printf("5. 查找联系人\n");
}
void Test(){
	// 创建通讯录
	struct contact table;
	Book_Init(&table);
	int input = 0;
	while (1){
		menu();
		printf("输入选择: \n");
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