#ifndef LIST_LIST_H
#define LIST_LIST_H

#include <vector>
#include <functional>
#include <memory>

using namespace std;

class Node {
public:
    shared_ptr<Node> next;
    int value{};
};

class List {
public:
    shared_ptr<Node> head;

    List();
    List(initializer_list<int> list);
    [[nodiscard]] int size() const;
    [[nodiscard]] int get(int index) const;
    void set(int index, int value) const;
    void append(int element);
    void insert(int index, int element);
    void extend(vector<int> toExtend);
    void extend(vector<int> toExtend, int index);
    [[nodiscard]] int pop();
    void removeAt(int index);
    void remove(int element);
    void removeAll(const vector<int>& elements);
    void clear();
    [[nodiscard]] int index(int element) const;
    [[nodiscard]] int count(int element) const;
    [[nodiscard]] bool contains(int element) const;
    [[nodiscard]] bool containsAll(const vector<int>& elements) const;
    void sort(bool reverse);
    void reverse();
    [[nodiscard]] List copy() const;
    [[nodiscard]] bool isEmpty() const;
    [[nodiscard]] List subList(int fromIndex, int toIndex) const;
    [[nodiscard]] vector<int> toVector() const;
    [[nodiscard]] int* toArray() const;
    void forEach(const function<void(int)>& function) const;

    int operator [](int index) const;
    friend bool operator==(const List& list1, const List& list2);
    friend bool operator!= (const List& list1, const List& list2);
    friend List operator - (const List& list1, const List& list2);
    friend List operator + (const List& list1, const List& list2);
    List& operator = (const List& list1);

};
ostream & operator<< (ostream & _stream, List const & list);




#endif //LIST_LIST_H
