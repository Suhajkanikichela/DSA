
#include <iostream>
#define SIZE 10
#define PRIME 7

using namespace std;

class HashTable {
private:
    int table[SIZE]; // Array to hold the hash table values

public:
    HashTable() {
        // Initialize the hash table with zeros
        for (int i = 0; i < SIZE; i++) {
            table[i] = 0;
        }
    }

    int Hash(int key) {
        return key % SIZE; // Primary hash function
    }

    int PrimeHash(int key) {
        return PRIME - (key % PRIME); // Secondary hash function
    }

    int DoubleHash(int key) {
        int idx = Hash(key);
        int i = 0;
        // Double hashing to find an empty slot
        while (table[(idx + i * PrimeHash(key)) % SIZE] != 0) {
            i++;
        }
        return (idx + i * PrimeHash(key)) % SIZE; // Return index for insertion
    }

    void Insert(int key) {
        int idx = Hash(key);
        // If the slot is occupied, use double hashing
        if (table[idx] != 0) {
            idx = DoubleHash(key);
        }
        table[idx] = key; // Insert the key
    }

    int Search(int key) {
        int idx = Hash(key);
        int i = 0;
        // Search for the key using double hashing
        while (table[(idx + i * PrimeHash(key)) % SIZE] != key) {
            if (table[(idx + i * PrimeHash(key)) % SIZE] == 0) {
                return -1; // Key not found
            }
            i++;
        }
        return (idx + i * PrimeHash(key)) % SIZE; // Return index of found key
    }

    void Print() {
        cout << "Hash Table: [";
        for (int i = 0; i < SIZE; i++) {
            cout << table[i];
            if (i < SIZE - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
};

int main() {
    HashTable ht;

    // Insert elements into the hash table
    int A[] = {5, 25, 15, 35, 95};
    int n = sizeof(A) / sizeof(A[0]);

    for (int i = 0; i < n; i++) {
        ht.Insert(A[i]);
    }

    // Print the hash table
    ht.Print();

    // Search for keys
    int index = ht.Search(25);
    cout << "Key 25 found at: " << index << endl;

    index = ht.Search(35);
    cout << "Key 35 found at: " << index << endl;

    return 0;
}
