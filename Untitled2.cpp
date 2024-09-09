#include<iostream>
using namespace std;

class Node {
public:
    int So_toa;
    Node *tiep;
    Node(int x) : So_toa(x), tiep(NULL) {}
};

class StackB {
public:
    Node *top;
    StackB() : top(NULL) {}

    void Push(int x) {
        Node *data = new Node(x);
        data->tiep = top;
        top = data;
    }

    bool Pop(int &Gia_Tri_Lay) {
        if (top == NULL)
            return false;
        else {
            Node *data = top;
            Gia_Tri_Lay = data->So_toa;
            top = top->tiep;
            delete data;
            return true;
        }
    }
};

class LinkedList {
public:
    Node *head;
    LinkedList() : head(NULL) {}

    void AddToList(int x) {
        Node *newNode = new Node(x);
        if (head == NULL) {
            head = newNode;
        } else {
            Node *temp = head;
            while (temp->tiep != NULL) {
                temp = temp->tiep;
            }
            temp->tiep = newNode;
        }
    }

    bool RemoveFromList(int &x) {
        if (head == NULL)
            return false;
        Node *temp = head;
        x = head->So_toa;
        head = head->tiep;
        delete temp;
        return true;
    }
};

int main() {
    int n, i, j, t;
    StackB B;
    LinkedList C;

    cout << "Nhap so luong toa tau o vi tri A: ";
    cin >> n;

    cout << "Nhap thu tu cac toa tau can xep vao vi tri C:\n";
    for (i = 0; i < n; i++) {
        int x;
        cin >> x;
        C.AddToList(x);
    }

    Node *tempC = C.head;
    for (j = 0, i = 1; i <= n; i++) {
        if (tempC != NULL && tempC->So_toa == i) {
            tempC = tempC->tiep;
            j++;
        } else {
            B.Push(i);
        }
        while (B.top != NULL && B.top->So_toa == (tempC != NULL ? tempC->So_toa : -1)) {
            B.Pop(t);
            tempC = tempC->tiep;
            j++;
        }
    }

    if (j < n - 1)
        cout << "Khong the sap xep!";
    else {
        cout << "Cac buoc thuc hien di chuyen cac toa nhu sau:\n";
        tempC = C.head;
        for (j = 0, i = 1; i <= n; i++) {
            if (tempC != NULL && tempC->So_toa == i) {
                cout << "Chuyen toa so " << i << " tu A -> C\n";
                tempC = tempC->tiep;
                j++;
            } else {
                B.Push(i);
                cout << "Chuyen toa so " << i << " tu A -> B\n";
            }
            while (B.top != NULL && B.top->So_toa == (tempC != NULL ? tempC->So_toa : -1)) {
                B.Pop(t);
                cout << "Chuyen toa so " << t << " tu B -> C\n";
                tempC = tempC->tiep;
                j++;
            }
        }
    }

    return 0;
}

