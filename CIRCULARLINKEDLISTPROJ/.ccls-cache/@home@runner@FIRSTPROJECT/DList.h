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

#ifndef DLLIST_H
#define DLLIST_H

template <class T>
struct node
{
   node<T> *back; 
   T info;
   node<T> *next;    
};

template <class T>
class DList
{
   private:
      node<T> *first;
      int length;

   public: 
      //Constructor 
      DList ();
      // destructor
     ~DList (); 
      // Copy constructor
      DList ( const DList<T> & );
      // Overload the = operator
      const DList<T> & operator= ( const DList<T> &);
      // Destroy the list
      void destroy();
      // Copy the list
      void copy (const DList<T> &);
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