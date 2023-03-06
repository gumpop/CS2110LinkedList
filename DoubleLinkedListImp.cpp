#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
};

class DoubleLinkedList{
    public:
        Node* head;
        Node* sorted; //if insertion sort or selection
        int size=0;
        DoubleLinkedList() {
            head=nullptr;
        }
        DoubleLinkedList(Node* h)
        {
            head=h;
        }

        Node* getPrevNode(Node* x){
            Node* currNode = head;
            if(currNode == x) return nullptr;

            return currNode->prev;
        } //modified

        void swapNodes(Node* x, Node* y) {

            if (x == y) {
                return;
            }

            Node* prevX = x->prev;
            Node* currX = x;
            Node* nextX = x->next;

            Node* prevY = y->prev;
            Node* currY = y;
            Node* nextY = y->next;

            if (currX == nullptr || currY == nullptr) {
                return;
            }

            if (prevX != nullptr) {
                prevX->next = y;
                y->prev=prevX;
                nextX->prev=y;
            }
            else {
                head = currY;
                y->prev=nullptr;
            }

            if (prevY != nullptr) {
                prevY->next = x;
                x->prev=prevY;
                nextY->prev=x;
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
                    curr->next->next->prev=curr->next;
                    delete remove;
                    size--;
                    return;
                }
                curr = curr->next;
            }
        }
        void print(){
            Node* print = head;
            cout<<"Here is the linked list: Head->";
            while(print!=nullptr)
            {
                if(print->next != nullptr)
                {
                    cout<<print->data<<"<->";
                    print=print->next;
                } else {
                    cout<<print->data<<"->null";
                    print=print->next;
                }


            }
            cout<<endl;
        } //modified
        void add(int add) {
            Node* addPtr= new Node;
            addPtr->data=add;
            addPtr->prev=nullptr;
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
            addPtr->prev=curr;

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
                int val = cur->data;
                cur->data=min->data;
                min->data=val;
                cur = next;
            }
        }
        void bubbleSort() {
            for (int i = 0; i < size; i++) {

                Node* x = head;
                Node* y = x->next;
                for (int j = 0; j<size-i-1; j++) {
                    if (x->data > y->data) {
                        int val = x->data;
                        x->data=y->data;
                        y->data=val;
                        x = x->next;
                        y = y->next;
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
    DoubleLinkedList list;
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