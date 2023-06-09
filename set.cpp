#include <iostream>
#include <string>
using namespace std;

class Node {
    public:
        string name;
        int age;
        Node* next = nullptr;
        Node(string name, int age) {
            this->name = name;
            this->age = age;
        }
        Node() {
            name = "None";
            age = 0;
        }
};

class Set {
    int length = 0;
    Node* start = nullptr;
    Node* pointer = nullptr;
    bool repeat = false;
    public:
        void add(string name_arg, int age_arg) {
            Node* node = new Node(name_arg, age_arg);
            if (length == 0) {
                start = node;
                pointer = node;
                length++;
            } else {
                Node* obj = start;
                if ((!repeat && !check_by_age(node->age)) || repeat) {
                    while (obj) {
                        if (obj->age > node->age) {
                            if (obj == start) {
                                node->next = start;
                                start = node;
                                pointer = node;
                                pointer->next = node->next;
                                while (pointer->next) pointer = pointer->next;
                                length++;
                                break;
                            } else {
                                Node* buffer_pointer = pointer;
                                pointer = start;
                                while (pointer->next->age != obj->age) pointer = pointer->next;
                                node->next = pointer->next;
                                pointer->next = node;
                                while (pointer->next) pointer = pointer->next;
                                length++;
                                break;
                            }
                        } else obj = obj->next;
                    }
                    if (pointer->age < node->age) {
                        pointer->next = node;
                        pointer = node;
                        length++;
                    }
                }
                
            }
        }
        void repeat_mode(bool expression) {
            repeat = expression;
        }
        bool check_by_age(int age) {
            Node* obj = start;
            while (obj) {
                if (obj->age == age) return true;
                else obj = obj->next;
            }
            return false;
        }
        Node* find_by_age(int age) {
            Node* obj = start;
            while (obj) {
                if (obj->age == age) return obj;
                else obj = obj->next;
            }
            return new Node();
        }
        void print() {
            Node* obj = start;
            while (obj) {
                cout << obj->name << " " << obj->age << endl;
                obj = obj->next;
            }
        }
};

int main() {
    Set set;
    set.add("Oleg", 17);
    set.add("Pasha", 13);
    set.add("Stepan", 20);
    set.add("Nazar", 40);
    set.add("Vova", 4);
    set.add("Ivan", 8);
    set.add("Roman", 60);
    set.add("Sergiy", 19);
    set.add("Danylo", 2);
    set.add("Olia", 50);
    set.add("Tania", 58);
    // set.repeat_mode(true);
    set.add("Danylo", 2);
    set.add("Olia", 50);
    set.add("Tania", 58);
    set.add("Vitalik", 1);
    
    set.print();
    cout << set.check_by_age(62) << endl;
    cout << set.find_by_age(60)->name << endl;
}