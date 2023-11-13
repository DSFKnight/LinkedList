#include <iostream>
using namespace std;
class LinkedList {
    int element;
    LinkedList* next = NULL;
    LinkedList* prev = NULL;
    static LinkedList* head;
    static LinkedList* tail;
    static int counter;

    LinkedList(int n) : element(n) {
        counter++;
    }
    ~LinkedList() {
        counter--;
    }

public:

    static bool IsEmpty() {
        return (head == tail && head == NULL);
    }

    static int get_size() {
        return counter;
    }

    static void print() {
        if (IsEmpty()) return;
        LinkedList* p = head;
        cout << "head -> ";
        while (p) {
            cout << p->element << " ";
            p = p->next;
        }
        cout << "<- tail" << endl;
    }

    static bool push_front(int n) {
        LinkedList* p = new LinkedList(n);
        if (!p) return false;
        if (IsEmpty()) {
            head = tail = p;
        }
        else {
            head->prev = p;
            p->next = head;
            head = p;
        }
        return true;
    }

    static bool push_back(int n) {
        LinkedList* p = new LinkedList(n);
        if (!p) return false;
        if (IsEmpty()) {
            head = tail = p;
        }
        else {
            tail->next = p;
            p->prev = tail;
            tail = p;
        }
        return true;
    }

    static bool pop_front() {
        if (IsEmpty()) return false;
        LinkedList* p = head;
        if (head == tail) head = tail = NULL;
        else {
            head = head->next;
            head->prev = NULL;
        }
        delete p;
        return true;
    }

    static bool pop_back() {
        if (IsEmpty()) return false;
        LinkedList* p = tail;
        if (head == tail) head = tail = NULL;
        else {
            tail = tail->prev;
            tail->next = NULL;
        }
        delete p;
        return true;
    }

    static bool erase_element(int n) {
        LinkedList* p = head;
        while (p) {
            if (p->element == n) {
                if (p == head) {
                    return pop_front();
                }
                else if (p == tail) {
                    return pop_back();
                }
                else {
                    p->prev->next = p->next;
                    p->next->prev = p->prev;
                    delete p;
                    return true;
                }
            }
            p = p->next;
        }
        return false;
    }

    static bool delete_list() {
        while (head) {
            pop_front();
        }
        return true;
    }
};

LinkedList* LinkedList::head = NULL;
LinkedList* LinkedList::tail = NULL;
int LinkedList::counter = 0;

int main()
{
    LinkedList::push_front(10);
    LinkedList::push_front(20);
    LinkedList::push_front(30);
    LinkedList::print(); //  30 20 10
    LinkedList::pop_front();
    LinkedList::print(); // 20 10
    cout << LinkedList::get_size() << endl; // 2
    LinkedList::push_front(30);
    LinkedList::push_front(40);
    LinkedList::print(); // 40 30 20 10
    LinkedList::push_back(50);
    LinkedList::pop_front();
    LinkedList::push_front(60);
    LinkedList::print();// 60 30 20 10 50
    LinkedList::pop_back();
    LinkedList::pop_back();
    LinkedList::print();// 60 30 20
    LinkedList::erase_element(30);
    LinkedList::print(); // 60 20
    LinkedList::push_front(70);
    LinkedList::push_back(80); // 70 60 20 80
    LinkedList::erase_element(70);
    LinkedList::erase_element(20);
    LinkedList::print();
    LinkedList::delete_list();
    cout << LinkedList::get_size(); // 0
    return 0;
}