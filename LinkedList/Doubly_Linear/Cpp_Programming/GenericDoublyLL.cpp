#include<iostream>
using namespace std;

#pragma pack(1)

template<class T>

struct node
{
    T data;
    struct node<T> *next;
    struct node<T> *prev;
};

template<class T>

class DoublyLL
{
    protected:
        struct node<T>* first;
        int iCount;

    public:
        DoublyLL();

        void Display();

        int Count();

        void InsertFirst(T iNo);

        void InsertLast(T iNo);

        void InsertAtPos(T iNo, int iPos);

        void DeleteFirst();

        void DeleteLast();

        void DeleteAtPos(int iPos);
};

template<class T>

DoublyLL<T>::DoublyLL()
{
    cout<<"Inside Constructor"<<endl;
    this->first = NULL;
    this->iCount = 0;
}

template<class T>

void DoublyLL<T>::Display()
{
    struct node<T>* temp = NULL;

    temp = first;

    while (temp != NULL)
    {
        cout<<"| "<<temp->data<<" | <=> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
    
}

template<class T>

int DoublyLL<T>::Count()
{
    return this->iCount;
}

template<class T>

void DoublyLL<T>::InsertFirst(T iNo)
{
    struct node<T>* newn = NULL;

    newn = new struct node<T>;

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;  // $

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        newn->next = this->first;
        this->first->prev = newn;  // *
        this->first = newn;
    }

    iCount++;
}

template<class T>

void  DoublyLL<T>::InsertLast(T iNo)
{
    struct node<T>* newn = NULL;
    struct node<T>* temp = NULL;

    newn = new struct node<T>;

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;  // $

    if(NULL == this->first)
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;

        newn->prev = temp;  // $
    }

    iCount++;

}

template<class T>

void  DoublyLL<T>::InsertAtPos(T iNo, int iPos)
{
    int iCount = 0;
    struct node<T>* temp = NULL;
    int i = 0;
    struct node<T>* newn = NULL;

    iCount = Count();

    if((iPos < 1) || (iPos > iCount+1))
    {
        printf("Invalid Position\n");
        return;
    }
    if(iPos == 1)
    {
        InsertFirst(iNo);
    }
    else if (iPos == iCount+1)
    {
        InsertLast(iNo);
    }
    else
    {
        temp = this->first;

        newn = new struct node<T>;

        newn->data = iNo;
        newn->next = NULL;
        newn->prev = NULL;          // $

        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        
        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn; 
        newn->prev = temp;

        iCount++;
    }
    
}

template<class T>

void DoublyLL<T>::DeleteFirst()
{
    if(this->first == NULL)
    {
        return;
    }
    else if((this->first)->next == NULL)
    {
        free(this->first);
        this->first = NULL;
    }
    else
    {
        this->first = this->first->next;
        delete (this->first)->prev;   //$
        (this->first)->prev = NULL;  //$
    }
    iCount--;
}

template<class T>

void  DoublyLL<T>::DeleteLast()
{
    struct node<T>* temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if((this->first)->next == NULL)
    {
        free(this->first);
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;

    }
    iCount--;
}

template<class T>

void DoublyLL<T>::DeleteAtPos(int iPos)
{
    int iCount = 0;
    struct node<T>* temp = NULL;
    int i = 0;
    struct node<T>* newn = NULL;

    iCount = Count();

    if((iPos < 1) || (iPos > iCount))
    {
        printf("Invalid Position\n");
        return;
    }
    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }
        
}

int main()
{
    DoublyLL<int> dobj;
    int iRet = 0;

    dobj.InsertFirst(51);
    dobj.InsertFirst(21);
    dobj.InsertFirst(11);

    dobj.Display();

    iRet = dobj.Count();

    cout<<"Number of Elements are : "<<iRet<<endl;
    

    dobj.InsertLast(101);
    dobj.InsertLast(111);
    dobj.InsertLast(121);

    dobj.Display();

    iRet = dobj.Count();

    cout<<"Number of Elements are : "<<iRet<<endl;

    dobj.DeleteFirst();


    dobj.Display();

    iRet = dobj.Count();

    cout<<"Number of Elements are : "<<iRet<<endl;


    dobj.DeleteLast();

    dobj.Display();

    iRet = dobj.Count();

    cout<<"Number of Elements are : "<<iRet<<endl;


    dobj.InsertAtPos(105,4);

    dobj.Display();

    iRet = dobj.Count();

    cout<<"Number of Elements are : "<<iRet<<endl;


    dobj.DeleteAtPos(4);

    dobj.Display();

    iRet = dobj.Count();

    cout<<"Number of Elements are : "<<iRet<<endl;

    return 0;
}