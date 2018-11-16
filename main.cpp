#include <iostream>
#include <cstdlib>





using namespace std;
//This Creates a struct to hold data and pointer to the next node
struct Node{
    int data;
    Node *next;
};

//Initializing the first node
Node *start=NULL;

//Stack
void pop(){


    Node *traverse,*previousNode;
    cout<<endl;
    traverse=start;

    //This loop will find last Node
    while(traverse->next!=NULL)
        {
            previousNode=traverse; //this will keep the address of previous node
            traverse=traverse->next;
        }
        //if previous node is NULL then stack is Empty
    if(previousNode==NULL){
        cout<<"Empty";
    }
    //This will delete the last node and update the pointer of previous node to NULL, which represents End of LinkedList
    else{
        cout<<"Value Popped : "<<traverse->data<<" ";
        previousNode->next=NULL;
        delete traverse;
    }

    cout<<endl;

}


//Queue
void dequeue(){

    cout<<endl;
    Node *traverse,*next;
    traverse=start;         //traverse have the address of first node
    if(start==NULL)
        cout<<"Empty Queue";
    else{
    next=traverse->next;    //now next have the pointer to the next node
    cout<<"Value Dequeued : "<<traverse->data<<" ";   //this prints the data on current node
    delete traverse;        //Delete this Node
    start=next;             //Assign start node the the value of next node, so now it can start dequeueing form that node
    }

    cout<<endl;

}


//LINKED LIST FUNCTIONs
void printLinkedList(){
    cout<<endl;
    Node *traverse=start;
    if(traverse==NULL){
        cout<<"Empty List";
    }
    while(traverse!=NULL){
        cout<<traverse->data<<" ";  //This prints the data on the node
        traverse=traverse->next;    //This moves the pointer to the next node
    }
    cout<<endl;
}

void insertAtLast(){

    cout<<"Enter -1 to Stop adding more nodes"<<endl;
    cout<<endl;
    Node *temp,*traverse;
    int n;
    cout<<"Enter Number: ";
    cin>>n;                 //Take Input
    while(n!=-1)            //This will keep on taking input until user enter -1
    {
        temp=new Node;      //Create a new node
        temp->data=n;
        temp->next=NULL;

        if(start==NULL)     //if it is the first node in the list
            start=temp;
        else
        {
            traverse=start;
            while(traverse->next!=NULL) //Add Linearly new node one after an other ,,this also links all nodes
                traverse=traverse->next;    //this points to the next node
            traverse->next=temp;        //this save the just created node into this
        }
        cout<<"Enter Number: ";
        cin>>n;
    }
}

void insertAtBegining(){

    cout<<"Enter -1 to Stop adding more nodes"<<endl;
    cout<<endl;
Node *temp;
int n;
cout<<"Enter ";
cin>>n;
while(n!=-1){
    temp=new Node;      //Create a node
    temp->data=n;
    temp->next=start; //this points the address of start
    start=temp;         //now this new start has new data n and pointer to the old start

    cout<<"Enter ";
    cin>>n;             //Input data
}


}

void insertAt(){
Node *temp,*previousNode,*traverse;
int n,loc;

    cout<<"Enter Location: ";
    cin>>loc;
    cout<<"Enter Number: ";
    cin>>n;

    traverse=start;
    for(int i=1;i<loc;i++){         //this loop reach the the location where user want to input data
        previousNode=traverse;
        traverse=traverse->next;
    }
    temp=new Node;
    temp->data=n;
    temp->next=traverse;            //temp have the address of the node what user selected
    previousNode->next=temp;        //this has the address of node which was previous node of the selected node


}

void deleteLastNode(){

    Node *traverse,*previousNode;

    traverse=start;
    while(traverse->next!=NULL){    //this traverse to the last node
        previousNode=traverse;
        traverse=traverse->next;
    }
    previousNode->next=NULL;        //this makes the 2nd last node pointer NULL, so that it cant point to the next node
    delete traverse->next;
    cout<<"Last Node Deleted"<<endl;

}

void deleteAtBegining(){

    Node *temp,*nextNode;
    temp=start;
    nextNode=temp->next;    //nextNode points to the 2nd node
    delete start;
    start=nextNode;         //Now new start is the 2nd node
    cout<<"First Node Deleted"<<endl;
}

void deleteAt(){
    Node *traverse,*previousNode;
    traverse=start;
    int loc;
    cout<<"Enter Location: ";
    cin>>loc;
    for(int i=1;i<loc;i++){         //this again finds the user selected location to delete node
        previousNode=traverse;
        traverse=traverse->next;
    }
    previousNode->next=traverse->next;      //now previousNode points to the node which was after the user selected node
    delete traverse;
    cout<<loc<<" Node Deleted"<<endl;
}

void updateLastNode(){
    int n;
    cout<<"Enter Number: ";
    cin>>n;
    Node *traverse;
    traverse=start;
    while(traverse->next!=NULL){    //this traverse to the last node
        traverse=traverse->next;
    }
    traverse->data=n;

}

void updateAtBegining(){
    int n;
    cout<<"Enter Number : ";
    cin>>n;
    Node *temp=start;       //This temp node points to start node
    temp->data=n;           //update the data of node
}

void updateAt(){
    int n,loc;
    Node *traverse;
    traverse=start;
    cout<<"Enter Location: ";
    cin>>loc;
    cout<<"Enter Number: ";
    cin>>n;

    for(int i=1;i<loc;i++)           // Find user required location
        traverse=traverse->next;
    traverse->data=n;               //update that node
}

void search(){

    int n,loc=0;
    bool isPresent=false;
    Node *traverse;
    cout<<"Enter Number To Search: ";
    cin>>n;                             //Input data to be searched
    traverse=start;
    while(traverse!=NULL){              //traverse till it last Node
            loc++;
        if(traverse->data==n){          //find required data
            isPresent=true;             //if present isPresent=true
            break;                      //break the loop since value is found
        }
        traverse=traverse->next;
    }
    if(isPresent)
        cout<<"\n"<<n<<"  is present at  "<<loc<<endl;
    else
        cout<<"\n"<<n<<"  is not present in list  "<<endl;
}

void deleteLinkedList(){

     start=NULL;

}

//BINARY SEARCH TREE
 struct node{
    int data;
    node *leftChild;
    node *rightChild;
};

node *root=NULL;

void insert(int n){


    node *current,*temp,*parent;

        temp=new node;
        temp->data=n;
        temp->leftChild=NULL;
        temp->rightChild=NULL;

        if(root==NULL)      //if its first node then it is root node
            root=temp;
        else{
            current=root;
            parent=root;

        while(1){
            parent=current;

            if(n<parent->data){     //if data entered is less than parent node
                current=current->leftChild; //now current points to the left
                if(current==NULL){          //if this node is null then insert
                        parent->leftChild=temp;
                        return;
                        }
            }
            else{                               //if data entered is greater than parent node
                current=current->rightChild;        //now current points to the right
                if(current==NULL){                  //if this node is null then insert
                        parent->rightChild=temp;
                        return;
                        }
                    }
                }
            }
}

void insertBT(){

    cout<<"Enter -1 to Stop adding more nodes"<<endl;
    cout<<endl;
    //This implements the insert() method, and keep on asking user to insert the data till user enters -1
    int n;
    cout<<"Enter Number: ";
    cin>>n;
    while(n!=-1){
        insert(n);
        cout<<"Enter Number: ";
        cin>>n;
    }
}

void searchBT(){

    node *temp,*traverse;
    bool isPresent=false;
    traverse=root;
    int data;
    cout<<"Enter Number..: ";
    cin>>data;

    while(1){
            cout<< traverse->data<<"->";
            if(data==traverse->data){
                isPresent=true;
                break;
            }
            else if(data<traverse->data){
                traverse=traverse->leftChild;
            }
            else if(data>traverse->data){
                traverse=traverse->rightChild;
            }

            if(traverse->leftChild==NULL && traverse->rightChild==NULL){
                cout<< traverse->data<<" ";
                if(data==traverse->data){isPresent=true;}
                break;
            }
     }
    if(isPresent)
        cout<<"\n 'Value Found'"<<endl;
    else
        cout<<"\n 'Value Not Found'"<<endl;
}

void inOrderTraversing(node *traverse){

    if(traverse==NULL)
        return;

    inOrderTraversing(traverse->leftChild);

    cout<<traverse->data<<" ";

    inOrderTraversing(traverse->rightChild);

}

//To Clear The Screen
void clearScreen(){
    system("cls");
}

//To Display Main Menu
void mainMenu(){

    cout<<endl;
    cout<<"\t\t\t"<<"**********MAIN MENU***********"<<endl;
    cout<<"\t\t\t"<<" 1 : Stack"<<endl;
    cout<<"\t\t\t"<<" 2 : Queue"<<endl;
    cout<<"\t\t\t"<<" 3 : Linked List"<<endl;
    cout<<"\t\t\t"<<" 4 : Array"<<endl;
    cout<<"\t\t\t"<<" 5 : BST"<<endl;
    cout<<"\t\t\t"<<"-1 : Exit"<<endl;
    cout<<endl;

}

void stackMenu(){
    cout<<endl;
    cout<<"\t\t\t"<<"**********STACK MENU***********"<<endl;
    cout<<"\t\t\t"<<" 1 : Push"<<endl;
    cout<<"\t\t\t"<<" 2 : Pop"<<endl;
    cout<<"\t\t\t"<<"-1 : Exit"<<endl;
    cout<<endl;
}

void queueMenu(){
    cout<<endl;
    cout<<"\t\t\t"<<"**********QUEUE MENU***********"<<endl;
    cout<<"\t\t\t"<<" 1 : Enqueue"<<endl;
    cout<<"\t\t\t"<<" 2 : Dequeue"<<endl;
    cout<<"\t\t\t"<<"-1 : Exit"<<endl;
    cout<<endl;
}

void linkListMenu(){
    cout<<endl;
    cout<<"\t\t\t"<<"**********LINNKED LIST***********"<<endl;
    cout<<"\t\t\t"<<" 1 : Insert At Last"<<endl;
    cout<<"\t\t\t"<<" 2 : Insert At Begining"<<endl;
    cout<<"\t\t\t"<<" 3 : Insert At Location"<<endl;
    cout<<"\t\t\t"<<" 4 : Update Last Node"<<endl;
    cout<<"\t\t\t"<<" 5 : Update Start Node"<<endl;
    cout<<"\t\t\t"<<" 6 : Update At Location"<<endl;
    cout<<"\t\t\t"<<" 7 : Delete Last Node"<<endl;
    cout<<"\t\t\t"<<" 8 : Delete Start Node"<<endl;
    cout<<"\t\t\t"<<" 9 : Delete At Location"<<endl;
    cout<<"\t\t\t"<<" 10: Search For Node"<<endl;
    cout<<"\t\t\t"<<" 11: Display List"<<endl;
    cout<<"\t\t\t"<<"-1 : Exit"<<endl;
    cout<<endl;
}

void arrayMenu(){

}

void BSTMenu(){
    cout<<endl;
    cout<<"\t\t\t"<<"**********BST***********"<<endl;
    cout<<"\t\t\t"<<" 1 : Insert"<<endl;
    cout<<"\t\t\t"<<" 2 : Search"<<endl;
    cout<<"\t\t\t"<<" 3 : In Order Traverse"<<endl;
    cout<<"\t\t\t"<<"-1 : Exit"<<endl;
    cout<<endl;

}

int main()
{
    int option,option1;
    option=0;
    while(option!=-1){
    mainMenu();
    cout<<"\t\t\t"<<"Choice Option: ";
    cin>>option;
    switch(option){
    case 1:
        stackMenu();
        option1=0;
        while(option1!=-1)
        {
            cout<<"\t\t\t"<<"Choice Option: ";
            cin>>option1;
            switch(option1)
            {
            case 1:
                insertAtLast();
                break;
            case 2:
                pop();
                break;
            case (-1):
                clearScreen();
                deleteLinkedList();
                break;
            }
        }
    case 2 :
        queueMenu();
        option1=0;
        while(option1!=-1)
        {
            cout<<"\t\t\t"<<"Choice Option: ";
            cin>>option1;

            switch(option1)
            {
            case 1:
                insertAtLast();
                break;
            case 2:
                dequeue();
                break;
            case (-1):
                clearScreen();
                deleteLinkedList();
                break;

            }
        }
    case 3:
        linkListMenu();
         option1=0;
        while(option1!=-1)
        {
            cout<<"\t\t\t"<<"Choice Option: ";
            cin>>option1;

            switch(option1)
            {
            case 1:
                insertAtLast();
                break;
            case 2:
                insertAtBegining();
                break;
            case 3:
                insertAt();
                break;
            case 4:
                updateLastNode();
                break;
            case 5:
                updateAtBegining();
                break;
            case 6:
                updateAt();
                break;
            case 7:
                deleteLastNode();
                break;
            case 8:
                deleteAtBegining();
                break;
            case 9:
                deleteAt();
                break;
            case 10:
                search();
                break;
            case 11:
                printLinkedList();
                break;
            case (-1):
                clearScreen();
                deleteLinkedList();
                break;
            }
        }
    case 4:
           break;
    case 5:
        BSTMenu();
        option1=0;
        while(option1!=-1)
        {
            cout<<"\t\t\t"<<"Choice Option: ";
            cin>>option1;
            switch(option1)
            {
            case 1:
                insertBT();
                break;
            case 2:
                searchBT();
                break;
            case 3:
                inOrderTraversing(root);
                cout<<endl;
                break;
            case (-1):
                clearScreen();
                deleteLinkedList();
                break;
            }
        }

    }
}

    return 0;
}
