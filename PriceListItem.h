#pragma once
#include <string>

using namespace std;

class PriceListItem {
public:
	PriceListItem();
	PriceListItem(const string &itemName, const string &code, double price, bool taxable);
	string getItemName();
	string getCode();
	double getPrice();
	bool isTaxable();
	// Add? PriceListItem *next;
private:
	// any private member variables and methods go here
	// TO BE COMPLETED
	string itemName1;
	string code1;
	double price1;
	bool taxable1;

};
