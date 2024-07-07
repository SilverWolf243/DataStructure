#include "pch.h"
#include "DynamicArray.h"
int main() 
{
	DynamicArray<int> da;
	da.PushBack(1);
	da.PushBack(2);
	da.PushBack(3);
	da.PushBack(4);
	da.PushBack(5);
	da.PushBack(6);
	da.PushBack(7);
	da.PushBack(8);

	for (int i = 0; i < da.Size(); i++)
		cout << da[i] << endl;

	for (int i = 0; i < 3; i++)
		da.PopBack();

	cout << "-----" << endl;

	for (int i = 0; i < da.Size(); i++)
		cout << da[i] << endl;

	return 0;
}