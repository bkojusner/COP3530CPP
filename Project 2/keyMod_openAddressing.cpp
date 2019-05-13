///Key Mod Table Size
///Open Addressing
#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

//key mod table size hashing function
int hashFunction(int key, int sizeTable)
{
	return (key % sizeTable);
}

//load factor function
double loadFactor(int items, int buckets)
{
	return ((double)items / (double)buckets);
}

int main() {
	int size = 7; //number of items in bucket (Adjustable)
	int buckets = 7; //number of buckets in the hashtable (Adjustable)
	int hashtable[7][7]; //(Adjustable)
	int hashtableSize = size * buckets; //size of the hashtable

	//fill out hashtable with temporary place holders
	for (int i = 0; i < buckets; i++)
	{
		for (int j = 0; j < size; j++)
		{
			hashtable[i][j] = -2;
		}
	}

	//variables to track counting
	int items = 0;
	int collisions = 0;
	double loadfactor = 0.0;

	for (int n = 0; n < hashtableSize; n++)
	{
		//key generation and hashing
		int key = 0 + (rand() * (int)((3 * hashtableSize) - 0) / RAND_MAX);
		int hidx = hashFunction(key, buckets);

		//checking collision and load factor
		for (int m = 0; m < size; m++)
		{
			if (hashtable[hidx][m] == -2)
			{
				//put key in bucket
				hashtable[hidx][m] = key;
				items++;
				cout << "Collisions: " << collisions << endl;
				loadfactor = loadFactor(items, buckets);
				cout << "Load Factor: " << loadfactor << endl;
				break;
			}
			else
			{
				collisions++;
			}
		}
	}
	return 0;
}