#include <bits/stdc++.h>
#include "list.h"

using namespace std;

void print_ll(Node *head)
{
    while (head != nullptr)
    {
        cout << head->get_data() << " -> ";
        head = head->get_next();
    }
    cout << endl;
}

int main()
{
    List l;
    l.insert_front(1);
    l.insert_front(2);
    l.insert_front(3);
    l.insert_front(4);
    l.insert_front(5);
    // l.delete_data(2);

    vector<int> nums = {1, 2, 3};

    Node *head;
    head = l.get_head();
    print_ll(head);

    cout << "Searching in ll: " << l.search(3) << endl;
    int temp;
    cout << "Enter an element to search in ll: ";
    cin >> temp;
    int key = l.recursive_search(temp);

    if (key == -1)
    {
        cout << temp << " is not found in ll" << endl;
    }
    else
    {
        cout << temp << " is found at index/node " << key << endl;
    }
    l.pop_front();
    head = l.get_head();
    print_ll(head);

    return 0;
}