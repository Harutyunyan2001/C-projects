#include <iostream>
using namespace std;

template <typename T>
class List {
private:
    template <typename T>
    class Node {
    public:
        T data;
        Node* prev, * next;
        Node(T data) {
            this->data = data;
            this->next = this->prev = nullptr;
        }
    };

public:
    Node<T>* head, * tail;
    int size;
    List() {
        head = tail = nullptr;
        size = 0;
    }
    ~List() {
        while (head != nullptr)
        {
            pop_front();
        }
    }

    void push_fron(int data) {
        Node<T>* teamp = new Node<T>(data);
        teamp->next = head;
        if (head != nullptr) {
            head->prev = teamp;
        }
        if (tail == nullptr) {
            tail = teamp;
        }
        head = teamp;
        size++;
    }

    void push_back(int data) {
        Node<T>* teamp = new Node<T>(data);
        teamp->prev = tail;
        if (tail != nullptr) {
            tail->next = teamp;
        }
        if (head == nullptr) {
            head = teamp;
        }
        tail = teamp;
        size++;
    }

    void getsize() {
        cout << size << endl;
    }

    void pop_front() {
        if (head == nullptr) { return; }
        Node<T>* temp = head->next;
        if (temp != nullptr) {
            temp->prev = nullptr;
        }
        else
        {
            tail = nullptr;
        }
        delete head;
        head = temp;
        size--;
    }

    void pop_back() {
        if (tail == nullptr) { return; }
        Node<T>* temp = tail->prev;
        if (temp != nullptr) {
            temp->next = nullptr;
        }
        else
        {
            head = nullptr;
        }
        delete tail;
        tail = temp;
        size--;
    }

    Node<T>* getAt(int index) {
        Node<T>* teamp = head;
        int n = 0;
        while (n != index)
        {
            if (teamp == nullptr) {
                return teamp;
            }
            teamp = teamp->next;
            n++;
        }
        return teamp;
    }

    Node<T>* operator [] (int index) {
        return getAt(index);
    }

    Node<T>* insert(int data, int index) {
        Node<T>* right = getAt(index);
        if (right == nullptr) {
            return push_back(data);
        }
        Node<T>* left = right->prev;
        if (left == nullptr) {
            return push_fron(data);
        }
        Node<T>* newNode = new Node<T>(data);
        newNode->prev = left;
        newNode->next = right;
        left->next = newNode;
        right->prev = newNode;
        size++;
        return newNode;
    }

    void earse(int index) {
        Node<T>* teamp = getAt(index);
        if (teamp == nullptr) { return; }
        if (teamp->prev == nullptr) {
            pop_front();
            return;
        }
        if (teamp->next == nullptr) {
            pop_back();
            return;
        }
        Node<T>* leaft = teamp->prev;
        Node<T>* right = teamp->next;
        leaft->next = right;
        right->prev = leaft;
        size--;
        delete teamp;
    }


};

int main()
{
    List<int> lst;
    lst.push_fron(5);
    lst.push_fron(5);
    lst.push_fron(5);
    lst.push_fron(5);
    lst.push_fron(5);
    lst.pop_front();
    lst.getsize();


}

