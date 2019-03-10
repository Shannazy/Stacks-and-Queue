#include <iostream>

using namespace std;
class NormalStack{

private:
    struct Node{
    int data;
    Node* next;
    Node* previous;
};
    Node* temp;
    Node* first;
    int Elements=0;

public:

    void InsertionSorting(){
    bool Swapped=true;
    temp=first->next;
    while(Swapped==true){
            Swapped=false;
            if((temp->data<temp->previous->data)&&(temp->next!=NULL)){
            if((temp->previous->data==first->data)){
                first=temp;
            }
            cout<<"Swapped "<<temp->data<<" with "<<temp->previous->data<<endl;
            temp->previous->next=temp->next;
            temp->next->previous=temp->previous;
            temp->next=temp->previous;
            temp->previous=temp->next->previous;
            temp->next->previous=temp;
            if((temp->previous==NULL)||(temp->data>temp->previous->data)){
                    temp=temp->next;
                }
            Swapped=true;
            }
            else if((temp->data<temp->previous->data)&&(temp->next==NULL)){
            cout<<"Swapped "<<temp->data<<" with "<<temp->previous->data<<endl;
            temp->previous->next=NULL;
            temp->next=temp->previous;
            temp->previous=temp->previous->previous;
            temp->previous->next->previous=temp;
            temp->previous->next=temp;
                if((temp->previous==NULL)||(temp->data>temp->previous->data)){
                    temp=temp->next;
                }
            Swapped=true;
            }
            else if((temp->data>temp->previous->data)&&(temp->next!=NULL)){
            temp=temp->next;
            Swapped=true;
            }
            else if((temp->data>temp->previous->data)&&(temp->next==NULL)){
            Swapped=false;
            }
    }
    cout<<"Sorting is complete"<<endl;
    }
    void Push(int input){
        if(Elements>=1){
        temp=new Node;//create new node
        temp->data=input;//input the data in the node
        temp->next=first;//the next pointer in node points at the current old first
        temp->previous=NULL;
        first->previous=temp;//the first points points at correct new first which is temp
        first=temp;
        Elements++;
        }
        else if(Elements<1){
            temp=new Node;
        temp->data=input;
        temp->next=NULL;
        first=temp;
        Elements++;
        }
    }

    int Pop(){
        if(Elements>1){
            cout<<first->data<<"\n"<<endl;
            first=first->next;
            first->previous=NULL;
            Elements--;
        }
        else if(Elements==1){
            cout<<first->data<<endl;
            Elements--;
        }
        else {
            cout<<"ERROR! THERE ARE NO ELEMENTS IN THE LIST!"<<endl;
        }
        return first->data;
    }

    int Peek(){
    cout<<first->data<<"\n"<<endl;
    return first->data;
    }

};
int main()
{   NormalStack starter;
    char selection;
    int input;
    int returns;

    while(selection!= 'N'){
    cout<<"Please select what you wish to do\n"
        <<"P: Push\n"
        <<"O: Pop\n"
        <<"S: Sort\n"
        <<"K: Peek\n"
        <<"N: Nothing else\n";

    cin>>selection;
    if(selection=='P'){
        cout<<"Enter the data that you wish to store\n";
        cin>>input;
        starter.Push(input);
    }
    else if(selection=='O'){
        returns=starter.Pop();
    }
    else if(selection=='S'){
        starter.InsertionSorting();
    }
    else if(selection=='K'){
        starter.Peek();
    }
    else if(selection=='N'){
        cout<<"Goodbye"<<endl;
    }
    else{
        cout<<"You have picked and invalid option. Please try again\n";
    }
}

    return 0;
}
