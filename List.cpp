#include "List.h"

#include <iostream>
#include <memory>
#include <vector>
#include <functional>

using namespace std;

List::List() {
    head = nullptr;
}

List::List(initializer_list<int> list) {
head = nullptr;
    for(int i : list) {
        this->append(i);
    }
}


int List::size() const {
    if(head == nullptr) {
        return 0;
    }
    int count = 0;
    shared_ptr<Node> temp = head;
    while(temp->next != nullptr) {
        count += 1;
        temp = temp->next;
    }

    return count + 1;
}

int List::get(int index) const {
    shared_ptr<Node> temp = head;
    for(int i = 0; i < index; i++) {
        if(temp->next == nullptr) {
            break;
        }
        temp = temp->next;
    }

    return temp->value;
}

void List::set(int index, int value) const {
    shared_ptr<Node> temp = head;
    for(int i = 0; i < this->size(); i++) {
        if(i == index) {
            temp->value = value;
            return;
        }
        temp = temp->next;
    }
}

void List::append(int element) {
    shared_ptr<Node> temp1 = make_shared<Node>();
    temp1->value = element;
    temp1->next = nullptr;
    if(head == nullptr) {
        head = temp1;
        return;
    }
    shared_ptr<Node> temp2 = head;
    while(temp2->next != nullptr) {
        temp2 = temp2->next;
    }
    temp2->next = temp1;
}

void List::insert(int index, int element) {
    shared_ptr<Node> temp = head;
    shared_ptr<Node> temp1 = make_shared<Node>();
    if(index == 0) {
        temp1->next = temp;
        temp1->value = element;
        head = temp1;
        return;
    }

    for(int i = 0; i < index-1; i++) {
        if(temp->next == nullptr) {
            return;
        }
        temp = temp->next;
    }
    shared_ptr<Node> temp2 = temp->next;
    temp1->value = element;
    temp1->next = temp2;
    temp->next = temp1;
}

void List::extend(vector<int> toExtend) {
    for(int i: toExtend) {
        append(i);
    }
}

void List::extend(vector<int> toExtend, int index) {
    for(int i = 0; i < toExtend.size(); i++) {
        this->insert(index+i, toExtend[i]);
    }
}

int List::pop() {
    if(head->next == nullptr) {
        int value = head->value;
        head = nullptr;
        return value;
    }
    shared_ptr<Node> temp = head;
    while(temp->next->next != nullptr) {
        temp = temp->next;
    }
    shared_ptr<Node> temp2 = temp->next;
    temp->next = nullptr;
    int value = temp2->value;
    temp2.reset();

    return value;
}

void List::removeAt(int index){
    shared_ptr<Node> temp = head;
    if(index >= this->size()) {
        return;
    }

    if(index < 0) {
        return;
    }

    if(index == 0) {
        head = temp->next;
        temp = nullptr;
        temp.reset();
        return;
    }
    for(int i = 0; i < index - 1; i++) {
        temp = temp->next;
    }
    shared_ptr<Node> temp2 = temp->next;
    temp->next = temp2->next;
    temp2 = nullptr;
    temp2.reset();
}

void List::remove(int element) {
    shared_ptr<Node> temp = head;
    if(temp->value == element) {
        head = temp->next;
        temp = nullptr;
        temp.reset();
        return;
    }
    while(temp->next != nullptr) {
        if(temp->next->value == element) {
            break;
        }
        temp = temp->next;
    }
    shared_ptr<Node> temp2 = temp->next;
    temp->next = temp2->next;
    temp2 = nullptr;
    temp2.reset();
}

void List::removeAll(const vector<int>& elements) {
    for(int i : elements) {
        remove(i);
    }
}

void List::clear() {
    int size = this->size();
    for(int i = 0; i < size; i++) {
        int test = this->pop();
    }
}

int List::index(int element) const {
    int count = 0;
    shared_ptr<Node> temp = head;
    while(temp->next != nullptr) {
        if(temp->value == element) {
            break;
        }
        count += 1;
        temp = temp->next;
    }
    if(count == this->size()) {
        return -1;
    }
    return count;
}

int List::count(int element) const {
    int count = 0;
    shared_ptr<Node> temp = head;
    while(temp->next != nullptr) {
        if(temp->value == element) {
            count += 1;
        }
        temp = temp->next;
    }

    return count;
}

bool List::contains(int element) const {
    shared_ptr<Node> temp = head;
    while(temp->next != nullptr) {
        if(temp->value == element) {
            return true;
        }
        temp = temp->next;
    }
    return false;
};

bool List::containsAll(const vector<int>& elements) const {
    int count = 0;
    shared_ptr<Node> temp = head;
    while(temp->next != nullptr) {
        for(int element : elements) {
            if(temp->value == element) {
                count += 1;
            }
        }
        temp = temp->next;
    }

    if(count >= elements.size()) {
        return true;
    }
    return false;
}

void List::sort(bool reverse) {
    //TODO write sort method
}

void List::reverse() {
    shared_ptr<Node> current = head;
    shared_ptr<Node> prev = nullptr;
    shared_ptr<Node> next;
    while(current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

List List::copy() const {
    List list = {};
    for(int i = 0; i < this->size(); i++) {
        list.append(this->get(i));
    }
    return list;
}

bool List::isEmpty() const {
    if(head == nullptr) {
        return true;
    }
    return false;
}

List List::subList(int fromIndex, int toIndex) const {
    List list;
    for(int i = fromIndex; i < toIndex; i++) {
        list.append(this->get(i));
    }

    return list;
}

vector<int> List::toVector() const {
    vector<int> vector1;
    vector1.reserve(this->size());
    for(int i = 0; i < this->size(); i++) {
        vector1.push_back(this->get(i));
    }

    return vector1;
}

int * List::toArray() const {
    int array[this->size()];
    for(int i = 0; i < this->size(); i++) {
        array[i] = this->get(i);
    }

    int *ptr = array;

    return ptr;
}

void List::forEach(const function<void(int)>& function) const {
    for(int i = 0; i < this->size(); i++) {
        function(this->get(i));
    }
}

int List::operator [](int index) const{
    return get(index);
}

bool operator== (const List& list1, const List& list2) {
    int count = 0;
    if(list1.size() != list2.size()) {
        return false;
    }

    for(int i = 0; i < list1.size(); i++) {
        if(list1.get(i) == list2.get(i)) {
            count += 1;
        }
    }

    if(count == list1.size()) {
        return true;
    }
    return false;
}

bool operator!= (const List& list1, const List& list2) {
    int count = 0;
    if(list1.size() != list2.size()) {
        return true;
    }

    for(int i = 0; i < list1.size(); i++) {
        if(list1.get(i) == list2.get(i)) {
            count += 1;
        }
    }

    if(count == list1.size()) {
        return false;
    }
    return true;
}

List operator + (const List &list1, const List &list2) {
    List list = list1;
    list.extend(list2.toVector());
    return list;
}

List operator - (const List &list1, const List &list2) {
    List list = list1;
    list.removeAll(list2.toVector());
    return list;
}

List& List::operator = (const List &list1) {
    this->clear();
    for(int i = 0; i < list1.size(); i++) {
        this->append(list1[i]);
    }
    return *this;
}

ostream & operator<<(ostream & _stream, List const & list) {
    shared_ptr<Node> temp = list.head;
    _stream << "[";
    while (temp != nullptr) {
        if(temp->next == nullptr) {
            _stream << temp->value;
        }
        else {
            _stream << temp->value << ", ";
        }
        temp = temp->next;
    }
    _stream << "]";
    return _stream;
}