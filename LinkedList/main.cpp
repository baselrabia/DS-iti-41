#include <iostream>
#include <string.h>

using namespace std;

struct node {
    int id;
    char name[30];
    node* next;
    node* prev;
};

class linkedlist{

    node* head;
    node* tail;

public:
    linkedlist(){
        head = tail = NULL;
    }

    linkedlist(linkedlist& oldlist){
        head = tail = NULL;
        //node* temp = new node();
        node* temp = oldlist.head;

        while(temp != NULL){
           append(temp->id,temp->name);
            temp=temp->next;
        }

    }

    void append(int id ,char name[])
    {
        node* temp = new node();
        temp->id = id;
        strcpy(temp->name,name);
        if(head == NULL){
            head = tail = temp;
            temp->next= temp->prev = NULL;
        }else{
            temp->next = NULL;
            temp->prev = tail;
            tail->next = temp;
            tail=temp;
        }
    }

    void appendfirst(int id ,char name[])
    {
        node* temp = new node();
        temp->id = id;
        strcpy(temp->name,name);
        if(head == NULL){
            head = tail = temp;
            temp->next= temp->prev = NULL;
        }else{
            temp->next = head;
            temp->prev = NULL;
            head->prev = temp;
            head=temp;
        }
    }

    void display( )
    {
        node* temp = head;

        while(temp != NULL){
            cout<<temp->id<<" : "<<temp->name<<endl;
            temp=temp->next;
        }

    }

    int getcount( )
    {
        node* temp = head;
        int c=0;
        while(temp != NULL){
            c++;
            temp=temp->next;
        }
        return c;
    }

   node* searchbyid(int id)
    {
        node* temp = head;

        while(temp != NULL){
            if(temp->id == id){
                return temp;
            }
            temp=temp->next;
        }
        return NULL;
    }


    void displaybyid(int id)
    {
        node* temp = searchbyid(id);
        cout<<temp->id<<" : "<<temp->name<<endl;
    }

    void deletebyid(int id)
    {
        node* temp = searchbyid(id);

        if(temp == NULL){
            return ;
        }

        if(head == tail){
            head=tail=NULL;
            delete temp;
        }else if( temp == head){
            head = temp->next;
            head->prev= NULL;
            delete temp;
        }else if( temp == tail){
            tail = temp->prev;
            tail->next= NULL;
            delete temp;
        }else{
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
        }

    }

    void insertafter(int nodeid,int id,char name[])
    {
        node* oldnode = searchbyid(nodeid);
        node* temp = new node();

        temp->id = id;
        strcpy(temp->name,name);
        if(head == NULL){
            head = tail = temp;
            temp->next= temp->prev = NULL;
        }else if(tail == oldnode){
            append(id,name);
        }else{
            temp->next = oldnode->next;
            temp->prev = oldnode;
            oldnode->next->prev = temp;
            oldnode->next = temp;
        }
    }

    void insertbefore(int nodeid,int id,char name[])
    {
        node* oldnode = searchbyid(nodeid);
        node* temp = new node();

        temp->id = id;
        strcpy(temp->name,name);
        if(head == NULL){
            head = tail = temp;
            temp->next= temp->prev = NULL;
        }else if(head == oldnode){
            appendfirst(id,name);
        }else{
            temp->next = oldnode;
            temp->prev = oldnode->prev;
            oldnode->prev->next = temp;
            oldnode->prev = temp;
        }
    }
    void deleteall()
    {
        node* temp = head;
        node* temp2 = head;

         while(temp2 != NULL){
            temp =temp2;
            temp2=temp2->next;
            delete temp;
        }
        head=tail=NULL;
        cout<<"delete all "<<endl;

    }

    int operator==(linkedlist& oldlist)
    {
        node* temp = head;
        node* temp2 = oldlist.head;

        while(temp != NULL && temp2 != NULL){
                //cout << temp->name<<endl;
           if (strcmp(temp->name,temp2->name) == 1){
                return false;
           }
            temp=temp->next;
            temp2=temp2->next;
        }

        return true;
    }

    linkedlist operator=(linkedlist& oldlist)
    {
        this->deleteall();
        head = tail = NULL;

        //node* temp = new node();
        node* temp = oldlist.head;

        while(temp != NULL){
           append(temp->id,temp->name);
            temp=temp->next;
        }

        return *this;
    }




};


int main()
{
    cout << "Hello world!" << endl;

    linkedlist list1;
    list1.append(10,"mohamed");
    list1.append(20,"ahmed");
    list1.append(30,"ali");
    list1.append(40,"eslam");

   // cout<<list1.getcount()<<endl;

   // list1.appendfirst(5,"sara");

   // list1.insertbefore(20,360,"nada");
   // list1.insertafter(20,330,"aya");

   // list1.displaybyid(20);
   // list1.deletebyid(40);

    list1.display();

    //list1.deleteall();
      //  list1.append(10,"mohamed");

    //list1.display();

    //list1.display();

    linkedlist list2;
    list2.append(320,"aali");
    list2.append(420,"eeslam");

    list2.display();

    list2=list1;
    list2.display();


    //list2.display();
cout <<"eqal result " <<(list1==list2) <<endl;


    //list1.searchbyid(10);
    //list1.deletebyid(30);

    //list1.display();



    return 0;
}
