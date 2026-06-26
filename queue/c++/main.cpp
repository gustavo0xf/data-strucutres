#include <iostream>
#include <queue>

using namespace std;

void populateQueue(queue<int> &queue) {
    queue.push(10);
    queue.push(20);
    queue.push(30);
    queue.push(40);
    queue.push(50);
}

void printQueue(queue<int> queue) {
    while (!queue.empty()) {
        cout << queue.front() << " ";
        queue.pop();
    }
    cout << "\n";
}

int main() {
    queue<int> queue;
    populateQueue(queue);
    printQueue(queue);

    return 0;
}