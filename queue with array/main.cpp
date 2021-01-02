#include <iostream>

using namespace std;

class queuet
{
    int* arr;
    int sizet;
    int rear;
    int qfront;
public:
    queuet(int s=5)
    {
        sizet=s;
        rear = qfront = -1;
        arr=new int[sizet];
    }
    int isfull()
    {
       return ((rear==sizet-1 && qfront==0) || qfront==rear+1) ;
    }

    int isempty()
    {
       return (qfront==-1);
    }

    void enqueue(int d)
    {
        if(isfull()){
            cout<<"\n queue is full"<<endl;
            return ;
        }else{
            if(isempty()){
                qfront=rear=0;
            }else if(rear == sizet-1){
                rear=0;
            }else{
                rear++;
            }
            arr[rear]=d;
        }
    }

    int dequeue(int& d){
         if(isempty()){
            cout << "\n queue is empty" << endl;
            return 0;
        }else{
            d=arr[qfront];
            if(qfront == rear){
                qfront=rear=-1;
            }else if(qfront == sizet-1){
                qfront=0;
            }else{
                qfront++;
            }
            return 1;
        }

    }



};

int test(){

    queuet q1(3);
    q1.enqueue(10);
        q1.enqueue(20);
    q1.enqueue(30);
        q1.enqueue(40);

    int x;
    int z;

    z= q1.dequeue(x);
    if(z==1){
        cout << "dequeue : "<<x<<endl;
    }
    z= q1.dequeue(x);
    if(z==1){
        cout << "dequeue : "<<x<<endl;
    }
    z= q1.dequeue(x);
    if(z==1){
        cout << "dequeue : "<<x<<endl;
    }
     q1.enqueue(10);
        q1.enqueue(20);
    q1.enqueue(30);
        q1.enqueue(40);

}

int main()
{
    cout << "Hello from Queue!" << endl;

   test();






    return 0;
}
