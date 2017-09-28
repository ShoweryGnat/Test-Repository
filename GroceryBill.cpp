#include "GroceryBill.h"
#include "PriceList.h"
#include <iostream>
#include <fstream>

using namespace std;

GroceryBill::GroceryBill(const PriceList *priceList, double taxRate) {
	// To be completed
	price_list = new PriceList;
	price_list = priceList;
	tax_rate = taxRate/100;
	bill = new PriceListItem[1000];
	s = 0;
	total = 0;
	

	
}
GroceryBill::~GroceryBill()
{
	delete price_list;
}
GroceryBill::GroceryBill(GroceryBill & g)
{
	price_list = new PriceList;
	price_list = g.price_list;
	tax_rate = g.tax_rate;
	bill = new PriceListItem[1000];
	for (int i = 0; i < g.s; i++)
	{
		bill[i] = g.bill[i];
	}
	s = g.s;
	total = g.total;
}
GroceryBill & GroceryBill::operator=(const GroceryBill & a)
{
	if (this != &a)
	{
		s = a.s;
		delete[] bill;
		bill = new PriceListItem[a.s];
		for (int i = 0; i < a.s; i++)
		{
			bill[i] = a.bill[i];
		}
	}
	return(*this);
}


void GroceryBill::scanItem(string scanCode, double quantity) 
{
	// To be completed
	PriceListItem temp = price_list->getItem(scanCode);
	temp.setPrice((temp.getPrice())*quantity);
	if (temp.isTaxable())
	{
		temp.setPrice(temp.getPrice() + (tax_rate*temp.getPrice()));
	}
	
	bill[s] = temp;
	s++;
	total = total + temp.getPrice();
}

// Scan multiple codes and quantities from the given text file
// Each line contains two numbers separated by space: the first is the code (an integer), the second the quantity (a float/double)
// Example line from text file:
// 15000000 1.5
void GroceryBill::scanItemsFromFile(string filename) {
	// To be completed
	// HINT: Look at code in PriceList::createPriceListFromDatafile(string filename)
	ifstream myFile(filename);

	if (myFile.is_open()) {
		cout << "Successfully opened file " << filename << endl;
		int c;
		double quantity;
		while (myFile >> c >> quantity) {

			string code = c + "";

			cout << code << " " << quantity << endl;
			scanItem(code, quantity);

		}
		myFile.close();
	}
	else
		throw invalid_argument("Could not open file " + filename);
}

// return the total cost of all items scanned
double GroceryBill::getTotal() {
	// To be completed
	
	return total;
}

// Print the bill to cout. Each line contains the name of an item, total price, and the letter "T" if tax was addded. 
// The last line shows the total.
// An example:
//Plastic_Wrap	1.60547 T
//Sugar_white	5.475
//Waffles_frozen	5.16
//Oil_Canola_100%_pure	2.69
//Potatoes_red	13.446
//TOTAL 	28.3765
void GroceryBill::printBill() {
	// To be completed
	string letter = "";
	for (int i = 0; i < s; i++)
	{
		if (bill[i].isTaxable())
		{
			letter = "T";
		}

		cout << bill[i].getItemName() << "   " << bill[i].getPrice() << "   " << letter << endl;
	}
	cout << "TOTAL     " << getTotal() << endl;

}

