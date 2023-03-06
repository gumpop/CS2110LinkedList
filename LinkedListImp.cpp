#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
    //Node* prev;
};

class SinglyLinkedList{
    public:
        Node* head;
        Node* sorted; //if insertion sort or selection
        int size=0;
        SinglyLinkedList() {
            head=nullptr;
        }
        SinglyLinkedList(Node* h)
        {
            head=h;
        }

        Node* getPrevNode(Node* x){
            Node* currNode = head;
            if(currNode == x) return nullptr;
            while(currNode!=nullptr)
            {
                if(currNode->next == x)
                {
                    return currNode;
                }
                currNode = currNode->next;
            }
            return nullptr;
        }

        void swapNodes(Node* x, Node* y) {

            if (x == y) {
                return;
            }

            Node* prevX = getPrevNode(x);
            Node* currX = x;

            Node* prevY = getPrevNode(y);
            Node* currY = y;

            if (currX == nullptr || currY == nullptr) {
                return;
            }

            if (prevX != nullptr) {
                prevX->next = y;
            }
            else {
                head = currY;
            }

            if (prevY != nullptr) {
                prevY->next = x;
            } else {
                head = currX;
            }

            if (x == head) {
                head = x;
                prevX->next = y;
                Node* temp = prevY->next;
                prevY->next = head->next;
                head->next = temp;
                return;
            }

            Node* temp = currY->next;
            currY->next = currX->next;
            currX->next = temp;
        }
        void searchDelete(int key){
            Node* curr = head;
            while(curr->next != nullptr)
            {
                if(curr->next->data == key)
                {
                    Node* remove = curr->next;
                    curr->next = remove->next;
                    delete remove;
                    size--;
                    return;
                }
                curr = curr->next;
            }
        }
        void print(){
            Node* print = head;
            cout<<"Here is the linked list: ";
            while(print!=nullptr)
            {
                cout<<print->data<<"->";
                print=print->next;
            }
            cout<<endl;
        }
        void add(int add) {
            Node* addPtr= new Node;
            addPtr->data=add;
            addPtr->next=nullptr;

            Node* curr = head;
            size++;
            if(curr == nullptr)
            {
                head = addPtr;
                return;
            }
            while(curr->next != nullptr)
            {
                curr = curr->next;
            }

            curr->next=addPtr;

        }
        void selectionSort() {
            Node* cur = head;
            while (cur != nullptr) {
                Node* min = cur;
                Node* comp = cur->next;
                while (comp != nullptr) {
                    if (min->data > comp->data) {
                        min = comp;
                    }
                    comp = comp->next;
                }
                Node* next = cur->next;
                swapNodes(cur, min);
                cur = next;
            }
        }
        void bubbleSort() {
            for (int i = 0; i < size; i++) {

                Node* x = head;
                Node* y = x->next;
                for (int j = 0; j<size-i-1; j++) {
                    if (x->data > y->data) {
                        swapNodes(x, y);
                        Node* temp = x;
                        x = y->next;
                        y = temp->next;
                    } else{
                        x = x->next;
                        y = x->next;
                    }
                }
            }
        }
    void insertionSort() {
        sorted = nullptr;

        Node* currNode = head;
        while(currNode != nullptr){
            if ( sorted == nullptr || sorted->data > currNode->data ) {
                Node* newNode = new Node;
                newNode->data = currNode->data;
                newNode->next=sorted;
                sorted=newNode;
            } else {
                Node* temp = sorted;
                while ( temp->next != nullptr) {
                    if(temp->next->data > currNode->data )
                    {
                        Node* newNode = new Node; newNode->data = currNode->data; newNode->next=temp->next;
                        temp->next = newNode;
                        break;
                    } else temp = temp->next;
                }
                if(!temp->next)
                {
                    Node* newNode = new Node; newNode->data = currNode->data; newNode->next=nullptr;
                    temp->next = newNode;
                }

            }
            currNode = currNode->next;
        }

        head = sorted;
    }

};

int main(){
    SinglyLinkedList list;
    list.add(7);
    list.add(9);
    list.add(15);
    list.add(12);
    list.add(15);
    list.add(8);
    list.add(8);
    list.add(2);
    list.add(4);
    list.add(2);

    list.print();
    list.searchDelete(15);
    list.print();
    list.add(15);

    list.insertionSort();
    list.print();

    return 0;
};