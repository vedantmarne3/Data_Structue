#include<iostream>
using namespace std;

#pragma pack(1)

template<class T>
struct node
{
    T data;
    struct node<T> *next;
};

template<class T>
class SinglyLL
{
    private:
        struct node<T>*first;
        int iCount;

    public:
        SinglyLL();

        void Display();

        int Count();

        void InsertFirst(T iNo);

        void InsertLast(T iNo);

        void InserAtPos(T iNo, int iPos);

        void DeleteFirst();

        void DeleteLast();

        void DeleteAtPos(int iPos);
};

template<class T>
SinglyLL<T>::SinglyLL()
{
    this->first = NULL;
    this->iCount = 0;
}

template<class T>
void SinglyLL<T>::Display()
{
    struct node<T> *temp = NULL;

    temp = this->first;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

template<class T>
int SinglyLL<T>::Count()
{
    return this->iCount;
}

template<class T>

void SinglyLL<T>::InsertFirst(T iNo)
{
    struct node<T> *newn = NULL;

    newn = new struct node<T>;

    newn->data = iNo;
    newn->next = NULL;

    if(this->first == NULL)
    {
        this->first = newn; //Important

    }
    else
    {
        newn->next = this->first;
        this->first = newn;
    }

    this->iCount++;
}

template<class T>

void SinglyLL<T>::InsertLast(T iNo)
{
    struct node<T> *newn = NULL;
    struct node<T> *temp = NULL;

    newn = new struct node<T>;

    newn->data = iNo;
    newn->next = NULL;

    if(this->first == NULL)
    {
        this->first = newn; //IMportant

    }
    else
    {
        temp = this->first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }

    this->iCount++;
}

template<class T>

void SinglyLL<T>::InserAtPos(T iNo, int iPos)
{
    struct node<T> *newn = NULL;
    struct node<T> *temp = NULL;
    int i = 0;

    if((iPos < 1) || (iPos > iCount + 1))
    {
        cout<<"Invalide Position\n";
        return;
    }

    if(iPos == 1)
    {
        this->InsertFirst(iNo);
    }
    else if (iPos == iCount+1)
    {
        this->InsertLast(iNo);
    }
    else
    {
        newn = new struct node<T>;

        newn->data = iNo;
        newn->next = NULL;

        temp = this->first;

        for(i = 1; i < iPos-1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;


        this->iCount++;
    }


}

template<class T>

void  SinglyLL<T>::DeleteFirst()
{
    struct node<T> *temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if (this->first->next == NULL)
    {
        delete(this->first);
        this->first = NULL;
    }
    else
    {
        temp = this->first;
        this->first = this->first->next;
        delete temp;
    }
    
    this->iCount--;
}

template<class T>

void  SinglyLL<T>::DeleteLast()
{
    struct node<T> *temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if (this->first->next == NULL)
    {
        delete(this->first);
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }
    
    this->iCount--;
}

template<class T>

void SinglyLL<T>::DeleteAtPos(int iPos)
{
    struct node<T> *temp = NULL;
    struct node<T> *target = NULL;
    int i = 0;

    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalide Position\n";
        return;
    }

    if(iPos == 1)
    {
        this->DeleteFirst();
    }
    else if (iPos == iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for(i = 1; i < iPos-1; i++)
        {
            temp = temp->next;
        }

        target = temp->next;
        temp->next = target->next;
        delete target;

        this->iCount--;
    }


}

int main()
{
    SinglyLL<int> sobj;
    int iRet = 0;

    sobj.InsertFirst(51);
    sobj.InsertFirst(21);
    sobj.InsertFirst(11);

    sobj.Display();

    iRet = sobj.Count();

    cout<<"Number of Elements are : "<<iRet<<endl;
    

    sobj.InsertLast(101);
    sobj.InsertLast(111);
    sobj.InsertLast(121);

    sobj.Display();

    iRet = sobj.Count();

    cout<<"Number of Elements are : "<<iRet<<endl;

    sobj.DeleteFirst();


    sobj.Display();

    iRet = sobj.Count();

    cout<<"Number of Elements are : "<<iRet<<endl;


    sobj.DeleteLast();

    sobj.Display();

    iRet = sobj.Count();

    cout<<"Number of Elements are : "<<iRet<<endl;


    sobj.InserAtPos(105,4);

    sobj.Display();

    iRet = sobj.Count();

    cout<<"Number of Elements are : "<<iRet<<endl;


    sobj.DeleteAtPos(4);

    sobj.Display();

    iRet = sobj.Count();

    cout<<"Number of Elements are : "<<iRet<<endl;


    return 0;
}