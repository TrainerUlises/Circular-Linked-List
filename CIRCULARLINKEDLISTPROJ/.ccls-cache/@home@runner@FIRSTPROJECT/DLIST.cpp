#include "DList.h"

/********************************************/
/* Programmer: Anna Salvati                 */   
/* Date: February 3, 2022                   */   
/* Purpose: Doubly Linked  List class  -    */
/*          implementation file             */ 
/* Input: none                              */
/* Output: printList function prints        */
/*         all current items in the list    */
/********************************************/

template <class T>
DList<T> :: DList (  )
{
   first = NULL;
   length = 0;
}

template <class T>
DList<T> :: ~DList ()
{
   destroy();
}

template <class T>
DList<T> :: DList (const DList<T> &other)
{
   copy (other);
}

template <class T>
const DList<T> & DList<T> :: operator= (const DList<T> &other)
{
   if ( this != &other )   
   {
      destroy();
      copy(other);
   }

   return *this;
}  

template <class T>
void DList<T> :: destroy ()
{
   node <T> *p;

   while ( first != NULL )
     {
        p = first;
        first = first->next;
        delete p;
     }
}

template <class T>
void DList<T> :: copy (const DList<T> & other)
{
   length = other.length;

   if ( other.first == NULL )
      first = NULL;

   else
   {
      first = new node<T>;
      first->info = other.first->info; 
      first->back = NULL;

      node<T> *p = other.first->next;
      node<T> *q = first;

      while ( p != NULL )
        {
          q->next =new node<T>;
          q->next->info = p->info;
          q->next->back = q;  
          q = q->next;
          p = p->next;
        }
      q->next = NULL;

   }

}
template <class T>
int DList<T> :: getLength ()
{
   return length; 
}

template <class T>
bool DList<T> :: isEmpty()
{
   return first == NULL;
}

template <class T>
void DList<T> :: insertItem (T item)
{
   length++;

   node<T> *temp = new node<T>;

   temp->info = item;

   if ( first == NULL || first->info > item )
   {
      temp->next = first;
      temp->back = NULL;
      first = temp;
      if ( temp->next != NULL ) 
        first->next->back = first;
   }
   else
   {
      node<T> *p = first;
      node<T> *q = NULL;

      while ( p != NULL && p->info < item )
        {
          q = p;
          p = p->next;
        }

      temp->next = p;
      temp->back = q;
      q->next = temp;
      if ( p != NULL )
        p->back = temp;


   }

}

template <class T>
void DList<T> :: deleteItem (T item)
{
   if ( first == NULL || first->info > item )
       cout<<"\nERROR - LIST EMPTY OR ITEM NOT THERE\n";
   else if ( item == first->info )
   {
       node<T> *p = first;
       first = first->next;
       first->back = NULL;  
       delete p;
       length--; 
       cout<<"\nITEM DELETED\n"; 
   }
   else
   {
      node<T> *q = NULL;
      node<T> *p = first;

      while ( p != NULL && p->info < item )
        {
           q = p;
           p = p->next;
        }

      if ( p == NULL || p->info > item )
         cout<<"\nITEM NOT THERE\n";
      else
      {
        q->next = p->next;
        if ( q->next != NULL )
          q->next->back = q;
        delete p;
        length--;
        cout<<"\nITEM DELETED\n"; 
      }
   }

}

template <class T>
bool DList<T> :: searchItem( T item)
{
    node<T> *p = first;

    while ( p != NULL && p->info <= item )
      {
         if ( p->info == item )
            return true;
         p = p->next;
      }

    return false;
}

template <class T>
void DList<T> :: printList ()
{
  if ( first == NULL )
    cout<<"\nLIST IS EMPTY\n";
  else
  {
     node<T> *p = first;

     cout<<"\nLIST IS : ";

     while ( p != NULL )
       {
         cout<<p->info<<"  ";
         p = p->next;
       }

      cout<<"\n";
  }
}