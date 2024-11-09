// #include<bits/stdc++.h>
class List;

class Node
{
    int data;
    Node *next;

public:
    Node(int d) : data(d), next(nullptr) {}
    // ~Node()
    // {
    //     if (next != nullptr)
    //     {
    //         delete next;
    //     }
    //     std::cout << "Deleting Node wih Data: " << data << std::endl;
    // }

    int get_data()
    {
        return data;
    }

    Node *get_next()
    {
        return next;
    }

    friend class List;
};

class List
{
    Node *head, *tail;
    int searchHelper(Node *start, int d)
    {
        if (start == nullptr)
        {
            return -1;
        }
        if (start->data == d)
        {
            return 0;
        }
        int subIdx = searchHelper(start->next, d);
        if (subIdx == -1)
        {
            return -1;
        }
        return subIdx + 1;
    }

public:
    List() : head(nullptr), tail(nullptr) {}

    Node *get_head()
    {
        return head;
    }
    // ~List()
    // {
    //     if (head != nullptr)
    //     {
    //         delete head;
    //         head = nullptr;
    //     }
    // }
    void insert_front(int data)
    {
        if (head == nullptr)
        {
            Node *n = new Node(data);
            head = tail = n;
        }
        else
        {
            Node *n = new Node(data);
            n->next = head;
            head = n;
        }
    }

    int search(int data)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->data == data)
            {
                return 1;
            }
            temp = temp->next;
        }
        return -1;
    }

    void delete_data(int data)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->data == data)
            {
                temp = temp->next;
                delete temp;
            }
        }
    }

    int recursive_search(int d)
    {
        int idx = searchHelper(head, d);
    }

    void pop_front(){
        Node *temp = head;
        head = head -> next;
        temp -> next = nullptr;
        delete temp;
    }
};
