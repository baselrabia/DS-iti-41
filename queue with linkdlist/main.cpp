#include <iostream>
#include <string.h>

using namespace std;

struct node {
    int d;
    node* next;
    node(int data){
        d= data;
        next = NULL;
    }
};

class queuet{
    node* rear;
    node* qfront;

public:
    queuet()
    {
        rear = qfront =  NULL;
    }

    int isempty()
    {
       return (qfront== NULL);
    }

    void enqueue(int x)
    {
        node* temp = new node(x);

        if (rear == NULL) {
            qfront = rear = temp;
             cout << "************enqueue : "<<x<<endl;
            return;
        }

        rear->next = temp;
        rear = temp;
        cout << "************enqueue : "<<x<<endl;
    }

     int dequeue(int& x)
    {
        if (qfront == NULL){
            cout << "\n queue is empty" << endl;
            return 0;
        }


        node* temp = qfront;
        qfront = qfront->next;

        if (qfront == NULL){
            rear = NULL;
        }
        x=temp->d;
        cout << "dequeue : "<<x<<endl;
        delete temp;
        return 1;


    }





};
int test(){

 queuet q1;
    q1.enqueue(10);
        q1.enqueue(20);
    q1.enqueue(30);
        q1.enqueue(40);

    int x;
    int z;

    q1.dequeue(x);

    q1.dequeue(x);

    q1.dequeue(x);



     q1.enqueue(10);
        q1.enqueue(20);
    q1.enqueue(30);
        q1.enqueue(40);


}


int main()
{
    cout << "Hello from Queue by linkdlist!" << endl;

    test();

    return 0;
}
