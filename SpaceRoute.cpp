#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Node {
public:
    T& data;
    Node* next;
    Node* prev;

    Node(T& d) : data(d), next(nullptr), prev(nullptr) {}
    void print() { cout << data << " "; }
};

class CelestialNode {
private:
    string name;
    double distance_from_earth;
    string mission_log;

public:
    CelestialNode(const string& n, double d, const string& log);
    const string& getName() const;
    double getDistance() const;
    const string& getMissionLog() const;
    void print() const { cout << name << " (" << distance_from_earth << " AU) - " << mission_log << endl; }
};

template <typename T>
class SpaceRoute {
private:
    Node<T>* head;
    Node<T>* tail;
    int length = 0;

public:
    SpaceRoute() {};  // Constructor
    ~SpaceRoute() {
        if (length == 0) {
            return;
        }
        Node<T> *temp = head;
        while (head != nullptr) {
            head = head -> next;
            delete temp;
            temp = head;

        }
    }; // Destructor

    void addWaypointAtBeginning(T& data) {
        Node<T> *newNode = new Node<T>(data);

        if (length == 0) {
            head = newNode;
            tail = newNode;
        } else {
            newNode -> next = head;
            head -> prev = newNode;
            head = newNode;
        }
        length++;

    }
    void addWaypointAtEnd(T& data) {
        Node<T> *newNode = new Node<T>(data);
        if (length == 0) {
            head = newNode;
            tail = newNode;
        } else {
            newNode -> prev = tail;
            tail -> next = newNode;
            tail = newNode;
        }
        length++;
    }
    void addWaypointAtIndex(int index, T& data) {
        if (index < 0 || index >= length) {
            cout << "Index is invalid" << endl;
            return;
        }

        if (index == 0) {
            addWaypointAtBeginning(data);
            return;
        }

        if (index == length - 1) {
            addWaypointAtEnd(data);
        } else {
            Node<T> *newNode = new Node<T>(data);
            Node<T> *temp = head;
            for (int i = 0; i < index; i++) {
                temp = temp -> next;
            }
            newNode -> next = temp;
            newNode -> prev = temp -> prev;
            newNode -> next -> prev = newNode;
            newNode -> prev -> next = newNode;
            length++;
        }

    }
    void removeWaypointAtBeginning() {
        Node<T> *temp = head;
        head = temp -> next;
        delete temp;
        length--;
    };
    void removeWaypointAtEnd() {
        Node <T> *temp = tail;
        tail = temp -> prev;
        delete temp;
        length--;
    };
    void removeWaypointAtIndex(int index) {
        Node<T> *temp = getWaypoint(index);
        if (!temp) {
            return;
        }

        if (temp -> next == nullptr) {
            removeWaypointAtEnd();
        } else if (temp -> prev == nullptr) {
            removeWaypointAtBeginning();
        } else {
            temp -> next -> prev = temp -> prev;
            temp -> prev -> next = temp -> next;
        }

        delete temp;
        length--;


    };
    void traverseForward() {
        print();
    };

    void traverseBackward() {
        Node<T>* current = tail;
        while (current) {
            current->print();
            current = current->prev;
        }
        cout << endl;
    };
    Node<T>* getWaypoint(int index) {
        if (index < 0 || index >= length) {
            cout << "Index is invalid" << endl;
            return nullptr;
        }

        if (index == 0) {
            return head;
        }

        if (index == length - 1) {
            return tail;
        }

        Node<T> *temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp-> next;
        }
        return temp;
    }
    void setWaypoint(int index, T& data) {
        if (index == 0) {
            addWaypointAtBeginning(data);
            removeWaypointAtIndex(index + 1);
            return;
        }

        if (index == length - 1) {
            addWaypointAtEnd(data);
            removeWaypointAtIndex(index - 1);
            return;
        }
        Node<T> *temp = getWaypoint(index);
        //checks to see if that index exists within the list
        if (!temp) {
            return;
        }

        Node<T> *newNode = new Node<T>(data);
        newNode -> next = temp -> next;
        newNode -> prev = temp -> prev;
        //checks to see if temp.next ptr isn't pointing to null
        if (temp -> next) {
            temp -> prev -> next = newNode;
        }
        //checks to see if temp.prev isn't pointing to null
        if (temp -> prev) {
            temp -> next -> prev = newNode;
        }
        delete temp;
    };
    void print(){

            Node<T>* current = head;
            while (current) {
                current->print();
                current = current->next;
            }
            cout << endl;
        }

};

