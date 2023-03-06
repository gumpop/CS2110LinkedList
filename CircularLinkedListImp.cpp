#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
    //Node* prev;
};

class CircularLinkedList{
    public:
        Node* head;
        Node* sorted = new Node; //if insertion sort or selection
        int size=0;
        CircularLinkedList() {
            head=nullptr;
        }
        CircularLinkedList(Node* h)
        {
            head=h;
        }

        Node* getPrevNode(Node* x){
            Node* currNode = head;
            //if(currNode == x) return nullptr;

            do{
                if(currNode->next == x)
                {
                    return currNode;
                }
                currNode = currNode->next;
            } while(currNode!=head);
            return currNode;
        } //modified
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
                head = y;
                prevX->next = y;
                Node* temp = x->next;
                prevY->next = head->next;
                head->next = temp;
                return;
            }

            Node* temp = currY->next;
            currY->next = currX->next;
            currX->next = temp;
        } //modified
        void searchDelete(int key){
            Node* curr = head;

            do{
                if(curr->next->data == key)
                {
                    Node* remove = curr->next;
                    curr->next = remove->next;
                    delete remove;
                    size--;
                    return;
                }
                curr = curr->next;
            }while(curr->next != head);
        } //modified
        void print(){ //modified
            Node* print = head;
            cout<<"Here is the linked list: Head->";
            do{
                if(print->next != head)
                {
                    cout<<print->data<<"->";
                    print=print->next;
                } else {
                    cout<<print->data;
                    print=print->next;
                }


            } while(print!=head);
            cout<<endl;
        } //modified
        void add(int add) { //modified for circle
            Node* addPtr= new Node;
            addPtr->data=add;
            Node* curr = head;
            size++;
            if(curr == nullptr)
            {
                head = addPtr;
                addPtr->next=head;
                return;
            }
            do{
                curr = curr->next;
            }while(curr->next != head);
            addPtr->next=head;
            curr->next=addPtr;

        } //modified
        void addSort(int add) { //modified for circle
            Node* addPtr= new Node;
            addPtr->data=add;
            Node* curr = sorted;
            size++;
            if(curr == nullptr)
            {
                head = addPtr;
                addPtr->next=head;
                return;
            }
            do{
                curr = curr->next;
            }while(curr->next != sorted);
            addPtr->next=sorted;
            curr->next=addPtr;

        }
        void selectionSort() {
            Node* cur = head;
             do {
                Node* min = cur;
                Node* comp = cur->next;
                do{
                    if (min->data > comp->data) {
                        min = comp;
                    }
                    comp = comp->next;
                } while (comp != head);
                Node* next = cur->next;
                swapNodes(cur, min);
                cur = next;
            } while (cur->next != head);
        } //modified
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
        sorted->data = head->data;
        sorted-> next = sorted;
        Node* currNode = head->next;
        do{

            if ( sorted->data > currNode->data ) {
                Node* newNode = new Node;
                newNode->data = currNode->data;
                Node* temp = sorted;
                do{
                    temp = temp->next;
                } while(temp->next != sorted);
                temp->next = newNode;
                newNode->next=sorted;
                sorted=newNode;
            }else {
                Node* temp = sorted;
                do {

                    if(temp->next->data > currNode->data )
                    {
                        Node* newNode = new Node; newNode->data = currNode->data; newNode->next=temp->next;
                        temp->next = newNode;
                        break;
                    } else temp = temp->next;
                } while ( temp->next != sorted);
                if(temp->next == sorted)
                {
                    addSort(currNode->data);
                }

            }

            currNode = currNode->next;
        } while(currNode != head);

        head = sorted;
    } //modified

};

int main(){
    CircularLinkedList list;
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