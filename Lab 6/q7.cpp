#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct Process {
    int id, priority;
};

int main() {
    queue<Process> arrivalQueue;
    stack<Process> execStack;

    // Arrival
    arrivalQueue.push({1, 3});
    arrivalQueue.push({2, 1});
    arrivalQueue.push({3, 2});

    cout << "\nProcesses arrived (Queue Order):\n";
    queue<Process> temp = arrivalQueue;
    while (!temp.empty()) {
        cout << "Process " << temp.front().id << " (Priority " << temp.front().priority << ")\n";
        temp.pop();
    }

    // Transfer to stack (simulate LIFO high-priority execution)
    while (!arrivalQueue.empty()) {
        Process p = arrivalQueue.front();
        arrivalQueue.pop();
        if (p.priority >= 2) execStack.push(p);
    }

    cout << "\nExecuting from Stack (High Priority LIFO):\n";
    while (!execStack.empty()) {
        Process p = execStack.top(); execStack.pop();
        cout << "Running Process " << p.id << " [Priority " << p.priority << "]\n";
    }
}
