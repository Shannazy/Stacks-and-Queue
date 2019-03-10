#include <iostream>

using namespace std;

 class ArbitraryQueue{

private:
    struct Node{
    string data;
    Node* next;
    Node* previous;
};
    Node* temp;
    Node* first;
    Node* last;
    int Elements=0;

public:
    void Push(string input){
        if(Elements>=1){
        temp=new Node;//create new node
        temp->data=input;//input the data in the node
        temp->next=first;//the next pointer in node points at the current old first
        first->previous=temp;//the first points points at correct new first which is temp
        first=temp;
        Elements++;
        }
        else if(Elements<1){
            temp=new Node;
        temp->data=input;
        first=temp;
        last=first;
        Elements++;
        }
    }
    void Enqueue(string input){
        if(Elements>=1){
        temp=new Node;
            temp->data=input;
            last->next=temp;//old last next points at temp that is new last
            temp->previous=last;
            last=temp;//last now at the proper last
            Elements++;
        }
        else if(Elements<1){
            temp=new Node;
            temp->data=input;
            first=temp;
            last=first;
            Elements++;
        }
    }
    string Pop(){
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
    string Dequeue(){
        if(Elements>1){
        cout<<last->data<<"\n"<<endl;
        last=last->previous;
        last->next=NULL;
        Elements--;
        }
        else if(Elements==1){
            cout<<last->data<<endl;
            Elements--;
        }
        else{
            cout<<"ERROR! THERE ARE NO ELEMENTS IN THE LIST!"<<endl;
         return "ERROR!";}


    return last->data;
    }

    string Traverse(int index){
    if(index==0){
        cout<<first->data<<endl;
    }
    else if(index >Elements-1){
            cout<<"There aren't enough elements in the list"<<endl;
    }
    else{
            temp=first;
        for(int i=0;i<index;i++){
            temp=temp->next;
        }
        cout<<temp->data<<endl;
    }
  return temp->data;
    }

};

int main()
{

char answer='A';
string input;
int index;
string returns;
ArbitraryQueue myQueue;


while(answer!= 'N'){
    cout<<"Please select what you wish to do\n"
        <<"P: Push\n"
        <<"E: Enqueue\n"
        <<"O: Pop\n"
        <<"D: Dequeue\n"
        <<"T: Traverse\n"
        <<"N: Nothing else\n";
    cin>>answer;
    if(answer=='P'){
        cout<<"Enter the data that you wish to store\n";
        cin>>input;
        myQueue.Push(input);
    }
    else if (answer=='E'){
        cout<<"Enter the data that you wish to store\n";
        cin>>input;
        myQueue.Enqueue(input);
    }
    else if(answer=='O'){
        returns=myQueue.Pop();
    }
    else if(answer=='D'){
        returns=myQueue.Dequeue();
    }
    else if(answer=='T'){
        cout<<"Enter the index you are trying to access\n";
        cin>>index;
        returns=myQueue.Traverse(index);
    }
    else if(answer=='N'){
        cout<<"Goodbye"<<endl;
    }
    else{
        cout<<"You have picked and invalid option. Please try again\n";
    }
}

    return 0;
}
