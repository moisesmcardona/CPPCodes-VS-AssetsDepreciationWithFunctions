/* ASSETS DEPRECIATION PROJECT
Por: Moisés Cardona
# 76937
Fecha de compilación: 28 de abril de 2014
CECS 2203
*/
#include <iostream>
#include <iomanip>
using namespace std;

void DataEntry(double &p, double &s, int &n); //Data entry function (p, s and n)
double StraightLineCalculation(double yearendvalue, double depreciation); // Calculates the year-end value for the straight line method
void StraightLineTable(int i, double &yearendvalue, double depreciation); // shows the table for the straight line method
double SumOfDigitsCalculation(double yearendvalue, double &depreciation, double yearsum, int n, int i, double p, double s); //Calculates the year-end value for the sum of digits method
void SumOfDigitsTable(int i, double &yearendvalue, double &depreciation, int yearsum, int n, double p, double s); // shows the table for the sum of digits method

int main()
{
	char choice; //saves the user choice to use a specific method or exit the program
	double p, s; //p = purchase price of the asset, s = the salvage value for the asset.
	double depreciation = 0; //anual depreciation value.
	double yearendValue; 
	int yearsum = 0; //sum of years for the sum-of-year method, initialized to 0 in order for the sum to work
	int n; //n = years over which the asset is to be depreciated.
	do // runs the program indefinitely until the user enters the letter c
	{
		cout << "MENU" << endl;
		cout << "\ta. Calculate the depreciation of an asset using the straight line method" << endl;
		cout << "\tb. Calculate the depreciation of an asset using the sum of digits method" << endl;
		cout << "\tc. End program" << endl;;
		cin >> choice;
		if (choice == 'a' || choice == 'A') // if the user enters a or A, use the straight line method
		{
			DataEntry(p, s, n); //Data entry function (p, s and n)
			//Starts depreciation math
			depreciation = (p - s) / n;
			yearendValue = p; //assigns depreciation value to yearendValue variable to substract between each year.
			cout << "Year\tDepreciation\tYear-end Value" << endl; // shows table headers
			for (int i = 1; i <= n; i++) // for each year, calculate the Year-end value and display
			{
				StraightLineTable(i, yearendValue, depreciation); // shows the table for the straight line method
			}
		}
		else if (choice == 'b' || choice == 'B') // if the user enters b or B, use the Sum of Digits method
		{
			DataEntry(p, s, n); //Data entry function (p, s and n)
			//Starts sum of years
			for (int i = 0; i <= n; i++)
				yearsum = yearsum + i;
			//Ends sum of years
			yearendValue = p; //assigns depreciation value to yearendValue variable to substract between each year.
			cout << "Year\tDepreciation\tYear-end Value" << endl; // shows table headers
			for (int i = 1; i <= n; i++) // for each year, calculate the Year-end value and display
			{
				SumOfDigitsTable(i, yearendValue, depreciation, yearsum, n, p, s);
			}
		}
	} while (choice != 'c' && choice != 'C'); // exits if the user enters c or C.
}
void DataEntry(double &p, double &s, int &n) //Data entry function (p, s and n)
{
	//Data entry
	cout << "Enter the purchase price of the asset: $";
	cin >> p;
	while (p < 0.0)
	{
		cout << "Price of the asset cannot be negative. Please enter it again: ";
		cin >> p;
	}
	cout << "Enter the salvage value for the asset: $";
	cin >> s;
	while (s < 0.0)
	{
		cout << "salvage value for the asset cannot be negative. Please enter it again: ";
		cin >> s;
	}
	cout << "Enter the term in years over which the asset is to be depreciated: ";
	cin >> n;
	while (n < 0.0)
	{
		cout << "term in years cannot be negative. Please enter it again: ";
		cin >> n;
	}
	//Ends data Entry
}
double StraightLineCalculation(double yearendvalue, double depreciation) // Calculates the year-end value for the straight line method
{
	yearendvalue = yearendvalue - depreciation; //calculates each year-end value
	return yearendvalue;
}
void StraightLineTable(int i, double &yearendvalue, double depreciation) // shows the table for the straight line method
{
	yearendvalue = StraightLineCalculation(yearendvalue, depreciation); // Calculates the year-end value for the straight line method
	cout << setprecision(2) << fixed << showpoint; // number formatting to 2 decimal places
	cout << i << "\t$" << depreciation << "\t$" << yearendvalue << endl; // shows the values for each year
}
double SumOfDigitsCalculation(double yearendvalue, double &depreciation, double yearsum, int n, int i, double p, double s) //Calculates the year-end value for the sum of digits method
{
	depreciation = ((n + 1 - i) / yearsum) * (p - s); //calculates the depreciation for each year
	yearendvalue = yearendvalue - depreciation; 
	return yearendvalue;
}
void SumOfDigitsTable(int i, double &yearendvalue, double &depreciation, int yearsum, int n, double p, double s) // shows the table for the sum of digits method
{
	yearendvalue = SumOfDigitsCalculation(yearendvalue, depreciation, yearsum, n, i, p, s); //Calculates the year-end value for the sum of digits method
	cout << setprecision(2) << fixed << showpoint; // number formatting to 2 decimal places
	cout << i << "\t$" << depreciation << "\t$" << yearendvalue << endl; // shows the values for each year
}
/* OUTPUT
MENU
a. Calculate the depreciation of an asset using the straight line method

b. Calculate the depreciation of an asset using the sum of digits method

c. End program
a
Enter the purchase price of the asset: $20000
Enter the salvage value for the asset: $5000
Enter the term in years over which the asset is to be depreciated: 5
Year    Depreciation    Year-end Value
1       $3000.00        $17000.00
2       $3000.00        $14000.00
3       $3000.00        $11000.00
4       $3000.00        $8000.00
5       $3000.00        $5000.00
MENU
a. Calculate the depreciation of an asset using the straight line method

b. Calculate the depreciation of an asset using the sum of digits method

c. End program
b
Enter the purchase price of the asset: $20000
Enter the salvage value for the asset: $5000
Enter the term in years over which the asset is to be depreciated: 5
Year    Depreciation    Year-end Value
1       $5000.00        $15000.00
2       $4000.00        $11000.00
3       $3000.00        $8000.00
4       $2000.00        $6000.00
5       $1000.00        $5000.00
MENU
a. Calculate the depreciation of an asset using the straight line method

b. Calculate the depreciation of an asset using the sum of digits method

c. End program
c

*/