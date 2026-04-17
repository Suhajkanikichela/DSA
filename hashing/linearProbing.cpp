#include <iostream>
#define SIZE 10

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
        return key % SIZE; // Hash function
    }

    void Insert(int key) {
        int idx = Hash(key);
        // Linear probing to find an empty slot
        while (table[idx] != 0) {
            idx = (idx + 1) % SIZE; // Move to the next index
        }
        table[idx] = key; // Insert the key
    }

    int Search(int key) {
        int idx = Hash(key);
        int startIdx = idx; // To avoid infinite loop
        while (table[idx] != 0) {
            if (table[idx] == key) {
                return idx; // Key found
            }
            idx = (idx + 1) % SIZE; // Move to the next index
            if (idx == startIdx) {
                break; // Prevent infinite loop if table is full
            }
        }
        return -1; // Key not found
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
    int A[] = {26, 30, 45, 23, 25, 43, 74, 19, 29};
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
