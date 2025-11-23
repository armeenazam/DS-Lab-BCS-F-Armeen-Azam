#include <iostream>
#include <string>
using namespace std;

class StudentHashTable {
public:
    static const int size = 15;

    string names[size];
    int rolls[size];

    StudentHashTable() {
        for(int i = 0; i < size; i++) {
            names[i] = "";
            rolls[i] = -1;
        }
    }

    int hashFunc(int r) {
        return r % size;
    }

    void InsertRecord(int roll, string name) {
        int idx = hashFunc(roll);
        int attempt = 0;
        while(attempt < size) {
            int newIdx = (idx + attempt*attempt) % size;
            if(rolls[newIdx] == -1) {
                rolls[newIdx] = roll;
                names[newIdx] = name;
                return;
            }
            attempt++;
        }
        cout << "Table full\n";
    }

    void SearchRecord(int roll) {
        int idx = hashFunc(roll);
        int attempt = 0;
        while(attempt < size) {
            int newIdx = (idx + attempt*attempt) % size;
            if(rolls[newIdx] == roll) {
                cout << names[newIdx] << endl;
                return;
            }
            if(rolls[newIdx] == -1) break;
            attempt++;
        }
        cout << "Record not found\n";
    }
};
