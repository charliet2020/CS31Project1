#include <iostream>
#include <string>
using namespace std;

int main()
{
	cout << "Importer: ";
	string importer;
	getline(cin, importer); // prints out importer for first line

	cout << "Product value (in trillions): ";
	double productValue; // productValue doesn't need to be an integer
	cin >> productValue;
	cin.ignore(10000, '\n');

	cout << "Product: ";
	string product;
	getline(cin, product);

	cout << "---" << endl;	// prints out exactly 3 hyphens, as directed

	cout.setf(ios::fixed);
	cout.precision(2);
	
	double duty500 = productValue * 0.31;
	double dutyLimit900 = 500 * 0.31 + (productValue - 500)*0.25;
	double dutyPm = 500 * 0.31 + (productValue - 500)*0.29;
	double dutyGreater = 500 * 0.31 + (400)*0.25 + (productValue - 900)*0.22; 
	double dutyPMGreater = 500 * 0.31 + (400)*0.29 + (productValue - 900)*0.22;
	
	if (importer == "") //empty importer case
	{
		cout << "You must enter an importer.";
		return 1;
	}
	if (productValue < 0) //negative product value case
	{
		cout << "The product value must not be negative.";
		return 1;
	}	
	if (product == "") //empty product case
	{
		cout << "You must enter a product.";
		return 1;
	} // cases without error in input below
	if (productValue <= 500)
	{
		cout << "The import duty for " << importer << " is G" << duty500 << " trillion.";
		return 1;
	}
	if (productValue > 500 && productValue <= 900) // second tariff part
	{
		if (product == "pigs" || product == "mud") // case for pigs or mud
			cout << "The import duty for " << importer << " is G" << dutyPm << " trillion.";
		else 
		{
			cout << "The import duty for " << importer << " is G" << dutyLimit900 << " trillion.";
			return 1;
		}
		return 1;
	}	
	if (productValue > 900) // third tariff part
	{
		if (product == "pigs" || product == "mud") //again, case for pigs or mud
			cout << "The import duty for " << importer << " is G" << dutyPMGreater << " trillion.";
		else
		{
			cout << "The import duty for " << importer << " is G" << dutyGreater << " trillion.";
			return 1;
		}
		return 1;
	}
	//cout << "The import duty for "<< importer << " is G" << duty500 << " trillion.";   
}