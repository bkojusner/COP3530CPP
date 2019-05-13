/// Mid Square
/// Separate Chaining
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

//load factor method
double loadFactor(int &num_elems, int num_buckets)
{
	return ((double)num_elems / (double)num_buckets);
}

//creating node
class Node {
	friend class HashTable;
	Node* next;
	int key;
public:
	Node(int k, Node* n) {
		key = k;
		next = n;
	}
};

//declaring methods in HashTable class
class HashTable {
public:
	int size;
	vector<Node*>* buckets;

	//HashTable size
	HashTable(int s) {
		size = s;
		buckets = new vector<Node*> (size);
	}

	//insert method
	void insert(int key) {
		if (buckets->at(hashFunction(key)) == NULL) {
			buckets->at(hashFunction(key)) = new Node(key, NULL);
			return;
		}

		while (buckets->at(hashFunction(key)) != NULL) {
			if (buckets->at(hashFunction(key))->next == NULL) {
				buckets->at(hashFunction(key))->next = new Node(key, NULL);
				break;
			}
			buckets->at(hashFunction(key)) = buckets->at(hashFunction(key))->next;
		}
	}

	//hash function mid square
	int hashFunction(int num) {
		int keyHash = num * num;
		keyHash = keyHash / 100;
		keyHash = keyHash % size;
		return keyHash;
	}

	//print method
	void print(int start) {
		int lineCount = 0;
		int collision = 0;
		int count = 0;

		for (int i = start; i < buckets->size(); i++) {			
			while (buckets->at(i) != NULL) {
				buckets->at(i) = buckets->at(i)->next;
				count++;

				//count collisions
				if (buckets->at(i) != NULL)
					collision++;
			}

			//get load factor
			double load = loadFactor(count, buckets->size());

			cout << "Collisions: " << collision << endl;
			cout << "Load Factor: " << load << endl;
		}
	}
};

int main(int argc, const char* argv[]) {
	int size = 7; //Adjustable amount of buckets
	int items = size * size; //total number of items
	int hashtableSize = size * items;
	HashTable* hash = new HashTable(size); //hashtable pointer

	for (int i = 0; i < items; i++) {
		//key generated and inserted
		int key = 0 + (rand() * (int)((hashtableSize * 3) - 0) / RAND_MAX);
		hash->insert(key);
	}

	//print details
	hash->print(0);

	return 0;
}