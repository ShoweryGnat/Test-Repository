#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "PriceList.h"
#include "PriceListItem.h"

using namespace std;

PriceList::PriceList()
{
	itemList = new PriceListItem[0];
	size = 0;
}
PriceList::~PriceList()
{
	delete[] itemList;
}
PriceList::PriceList(PriceList & p)
{
	size = p.size;
	itemList = new PriceListItem[p.size];
	for (int i = 0; i < size; i++)
	{
		itemList[i] = p.itemList[i];
	}
}
PriceList & PriceList::operator=(const PriceList & a)
{
	if (this != &a)
	{
		size = a.size;
		delete[] itemList;
		itemList = new PriceListItem[a.size];
		for(int i = 0; i < a.size; i++)
		{
			itemList[i] = a.itemList[i];
		}
	}
	return(*this);
}

// Load information from a text file with the given filename.
void PriceList::createPriceListFromDatafile(string filename) {
	ifstream myfile(filename);

	if (myfile.is_open()) {
		cout << "Successfully opened file " << filename << endl;
		string name;
		string code;
		double price;
		bool taxable;
		while (myfile >> name >> code >> price >> taxable) {
			// cout << code << " " << taxable << endl;
			addEntry(name, code, price, taxable);
		}
		myfile.close();
	}
	else
		throw invalid_argument("Could not open file " + filename);
}

// return true only if the code is valid
bool PriceList::isValid(string code) const {
	// TO BE COMPLETED
	bool found = false;
	int i = 0;
	while (!(found) && i<size)
	{
		string code_ = itemList[i].getCode();
		if (code_ == code)
		{
			found = true;
		}
		i++;
	}
	return found;
}

// return price, item name, taxable? as an ItemPrice object; throw exception if code is not found
PriceListItem PriceList::getItem(string code) const {
	// TO BE COMPLETED

	//needs to find the code(item) in the array
	//search for code using itemList[i].getCode()
	bool found = false;
	int i = 0;
	while (!(found) && i<size)
	{
		string code_ = itemList[i].getCode();
		if (code_ == code)
		{
			found = true;
		}
		i++;
	}
	if (!(found))
	{
		throw invalid_argument("Code is not found");
	}
	return itemList[i - 1];

}

// add to the price list information about a new item
void PriceList::addEntry(string itemName, string code, double price, bool taxable) {
	// TO BE COMPLETED

	//make array larger

	PriceListItem * temp;
	temp = new PriceListItem[size + 1];
	
	for (int i = 0; i < size; i++)
	{
		temp[i] = itemList[i];
	}
	itemList = temp;

	PriceListItem temp_(itemName, code, price, taxable);
	itemList[size] = temp_;
	size++;
}
