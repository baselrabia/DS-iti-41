#include <iostream>

using namespace std;

class Stack {
        int tos;
        int* arr;
        int size;


    public:

        Stack(int s) {       // Constructor
            cout <<" stack Constructor \n\n";

            tos = -1;
            size = s;
            arr = new int[s];
        }

        ~Stack() {          // Destructor
            cout <<"\n stack Destructor \n";
            delete[] arr;

        }

        Stack( Stack& obj) {
            cout <<" stack Copy Constructor \n\n";

            tos= obj.tos;
            size= obj.size;
            arr= new int[size];

            for(int i=0; i<=tos; i++){
                arr[i]= obj.arr[i];
            }

        }


        int push(int d) {

            if (tos < size-1){
                tos++;
                arr[tos] =d;
            }
             else
                cout <<"Error: stack Full\n";
        }

        int pop() {

            if (tos == -1){
                cout <<"Error: stack empty\n";
            }
            else{
                int d = arr[tos];
                tos--;
                return d;
            }

        }

        int isempty(){
            return tos==-1;
        }

        void view(){

            for(int i=0; i<=tos; i++){
                cout<<"stack data"<< i+1 <<"\n";
                cout<<arr[i]<<endl;
            }
        }

    Stack operator=(const Stack& s)
    {
       tos = s.tos;
       size = s.size;
       delete[] arr;
       arr= new int[size];

        for(int i=0; i<=tos; i++){
            arr[i]= s.arr[i];
        }

        return *this;
    }

    Stack operator+( Stack& s)
    {
        Stack s3(size + s.size);
        //s3.tos=tos+s.tos;

        for(int i=0; i<=tos; i++){
            s3.push(arr[i]);
        }

        for(int i=0; i<=s.tos; i++){
            s3.push(s.arr[i]);
        }

        return s3;
    }


};

int main()
{
    cout << "Hello world!" << endl;

    Stack s1(5);

    s1.push(10);

    s1.push(20);

    Stack s2(3);

    s2.push(40);

    Stack s3(30);

    s3 = s1+s2;

    s3.view();


    return 0;
}
