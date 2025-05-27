#pragma once
#include<iostream>

template<typename T>
class Arr_Bag
{
private:
	T items[100];
	int actual_num=0;
public:
	Arr_Bag() = default;

	bool add(const T& newEntry)
	{
		if (actual_num == 100)
			return false;
		items[actual_num] = newEntry;
		actual_num++;
		return true;
	}
	int getLength(){
		return actual_num;
		}
	bool remove(int i,T& rmvd)
	{
		if (i > actual_num - 1)
			return false;
		rmvd = items[i];
		items[i] = items[actual_num - 1];
		actual_num--;
		return true;
	}
	void printArray()
	{
		if (getLength() == 0)
			return;
		cout << "[";
		for (int i= 0; i < actual_num; i++)
		{
			cout << items[i];
			if (i == actual_num - 1)
			{
				cout << "]";
				return;
			}
			cout << ",";
		}
	}
	int getCount() const
	{
		return actual_num;
	}
};