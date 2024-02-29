#include <iostream>
using namespace std;

/*************************************************/
/* Programmer: Ulises Romero                     */ 
/* Date:  Feburary 21, 2024                   */ 
/* Purpose:  Circular linked List class,          */
/*           linked implementation, header file  */ 
/* Input: none                                   */
/* Output: none                                  */
/********************************************** **/

#ifndef CLLIST_H
#define CLLIST_H

template <class T>
struct node
{
   node<T> *back; 
   T info;
   node<T> *next;    
};

template <class T>
class CList
{
   private:
      node<T> *first;
      int length;

   public: 
      //Constructor 
      CList ();
      // destructor
     ~CList (); 
      // Copy constructor
      CList ( const CList<T> & );
      // Overload the = operator
      const CList<T> & operator= ( const CList<T> &);
      // Destroy the list
      void destroy();
      // Copy the list
      void copy (const CList<T> &);
      // Insert an item parameter into the list
      void insertItem ( T );
      // Delete an item parameter from the list
      void deleteItem ( T );
      // Search for an item parameter, return true if  
      // found, false otherwise
      bool searchItem ( T );
      // Return the length of the list
      int getLength ();
      // Return true if list is empty, false otherwise
      bool isEmpty ();
      // Print all the items in the list
      void printList ();
};
#endif
