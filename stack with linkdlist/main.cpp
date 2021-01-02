#include <iostream>
#include <string.h>

using namespace std;

struct student {
    int id;
    char name[30];
};

struct node {
    student s;
    node* prev;
};

class stackt{
    node* tos;
public:
    int c = 0;
    stackt(){
        tos = NULL;
    }

    void push(student d)
    {
        node* temp = new node();
        temp->s = d;
        if(tos == NULL){
            tos = temp;
            temp->prev = NULL;
        }else{
            temp->prev = tos;
            tos=temp;
        }
        c++;
    }

    int pop(student& d){

         if(tos == NULL){
            cout << "\n stack is empty" << endl;
            return 0;
        }

        d = tos->s;
        node* temp = tos;
        tos = temp->prev;
        delete temp;
        c--;
        return 1;
    }

    getc(){
        cout << " number of element in stack : "<< c << endl;
    }



};
int test(){

stackt s1;

student d1;
d1.id =20;
strcpy(d1.name,"mohamed");
s1.push(d1);

student d2;
d2.id =30;
strcpy(d2.name,"ali");
s1.push(d2);

student d3;
d3.id =40;
strcpy(d3.name,"eslam");
s1.push(d3);

s1.getc();

student d4;
s1.pop(d4);
cout << "element in stack : "<< d4.id << " : " << d4.name << endl;

s1.getc();


}

int main()
{
    cout << "Hello from stack by linkdlist!" << endl;

    test();


    return 0;
}
