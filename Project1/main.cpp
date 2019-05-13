#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

void addToList(vector<int> & vect) {
	int temp;
	bool quit = false;

	// Takes input as long as it is an int
	while (!quit) {
		cin >> temp;

		if (!cin.fail()) {
			vect.push_back(temp);
		}
		else {
			quit = true;
		}
	}
	return;
}

void getMinor(vector<int> & vect, vector<int> & temp, int i, int n)
{
	temp = vect;
	int j = i;
	int sum;

	// Loop to delete uneccesary column values
	for (int col = 0; col < n; col++)
	{
		temp.erase(temp.begin() + j);
		j += n - 1;
	}
	// Loop to delete uneccesary row values
	for (int row = 0; row < (n - 1); row++)
	{
		temp.erase(temp.begin());
	}
}

int determinant(vector<int> & vect, int n)
{
	vector<int> temp;
	int sum = 0;
	int pos = 1; // Determines if the matrices are adding or subtracting

	if (n == 1) // If n = 1 then the matrix is just vect[0]
		return(vect[0]);
	else if (n == 2) // If n = 2 we can just solve it as shown
		return((vect[0] * vect[n + 1]) - (vect[n - 1] * vect[n]));
	else {
		for (int i = 0; i < n; i++)
		{
			getMinor(vect, temp, i, n); // Gets minor of matrix
			sum += pos * vect[i] * determinant(temp, n - 1); // Recursively calls determinant function
			pos = -pos; // Sign changed
		}
	}
	return sum;
}

int main() {
	vector<int> vect;

	addToList(vect);

	// Checks to see if it's a square
	long double square = sqrt(vect.size());
	if ((square - floor(square)) != 0) {
		cout << "Error! Non-square matrix!" << endl;
		return 1;
	}

	// Gets value of vector which will be used for rows and cols
	int n = sqrt(vect.size());

	cout << determinant(vect, n) << endl;
	return 0;
}
