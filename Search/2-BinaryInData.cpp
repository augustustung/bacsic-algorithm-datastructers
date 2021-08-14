#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

struct  Product
{
	int id;
	char name[150];
	float price;
};


void TypeData(Product products[], int n)
{
	for(int i = 0; i < n; i++)
	{
		cout <<"Product at " << i+1<< endl;
		cout <<"ID: ";
		cin>>products[i].id;
		cin.ignore();
		cout <<"Name: ";
		cin.get(products[i].name, 150);

		cout <<"Price: ";
		cin>>products[i].price;
	}
}

void Print(Product products[], int n)
{
	for(int i = 0; i < n; i++)
	{
		Product product = products[i];
		cout << product.id <<"\t" << product.name << "\t" << product.price << endl; 
	}
}

Product *findProduct(Product products[], int n, float price)
{
	int left = 0;
	int right = n-1;
	int mid = 0;
	do {
		mid = (left+right)/2;
		Product product = products[mid];
		if(product.price == price)
			return &product;
		else if(product.price > price)
			right = mid - 1;
		else
			left = mid + 1;
	} while(left <= right);
	return NULL;
}

int main()
{
	int n;
	cout << "Number of product(s): ";
	cin >> n;
	Product products[n];
	TypeData(products, n);
	cout << "Products are stored\n";
	Print(products, n);
	float _price;
	cout << "Type price of product you wanna find: ";
	cin >> _price;
	Product *pro = findProduct(products, n, _price);
	pro == NULL ? cout <<"Can't find it!\n" : cout << pro->id << "\t" << pro->name << "\t" << pro->price << endl;
	return 0;
}