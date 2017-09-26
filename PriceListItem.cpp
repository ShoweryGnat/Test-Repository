#include "PriceListItem.h"

PriceListItem::PriceListItem(const string &itemName, const string &code, double price, bool taxable) {
	// TO BE COMPLETED
	itemName1 = itemName;
	code1 = code;
	price1 = price;
	taxable1 = taxable;
}

PriceListItem::PriceListItem() {
	// TO BE COMPLETED
	itemName1 = " ";
	code1 = " ";
	price1 = 0.0;
	taxable1 = false;
}

string PriceListItem::getItemName() {
	// TO BE COMPLETED
	return itemName1;
}

string PriceListItem::getCode() {
	// TO BE COMPLETED
	return code1;
}

double PriceListItem::getPrice() {
	// TO BE COMPLETED
	return price1;
}

bool PriceListItem::isTaxable() {
	// TO BE COMPLETED
	return taxable1;
}

