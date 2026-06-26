#include <iostream>
#include <forward_list>

using namespace std;

int main() {
    pmr::forward_list<int> list;

    list.push_front(10);

    cout << list.front() << endl;

    return 0;
}