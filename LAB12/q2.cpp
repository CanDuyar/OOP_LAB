#include <iostream>
#include <string>

using namespace std;

// getProductID function
int getProductID(int ids[], string names[], int numProducts, string target)
{
	for (int i = 0; i < numProducts; i++)
	{
		if (names[i] == target)
			return ids[i];
	}

	throw (target + " is not found."); //throw
} 

	/* TEST */
int main()
{
	int productIds[] = { 4, 5, 8, 10, 13 };
	string products[] = { "computer", "flash drive", "mouse", "printer", "camera" }; 

	// try-catch
	try
	{
		cout << getProductID(productIds, products, 5, "mouse") << endl;
		cout << getProductID(productIds, products, 5, "camera") << endl;
		cout << getProductID(productIds, products, 5, "laptop") << endl;
	}
	catch (string message)
	{
		cout << "Error: " << message << endl; //error message
	}

	return 0;
} 