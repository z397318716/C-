#include "BinaryTree.h"



int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	BTree<char> t1("ABD##E##CFH##I##G##", '#');
	t1.pre_order();
	cout << endl;
	t1.level_order();
	cout << endl;


	return 0;
}