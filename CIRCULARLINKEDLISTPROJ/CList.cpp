#include "CList.h"

/********************************************/
/*Programmer: Ulises Romero                     */
/* Date:  Feburary 21, 2024                    */
/* Purpose: Circular Linked  List class  -    */
/*          implementation file             */
/* Input: none                              */
/* Output: printList function prints        */
/*         all current items in the list    */
/********************************************/

template <class T> CList<T>::CList() {
  first = NULL;
  length = 0;
}

template <class T> CList<T>::~CList() { destroy(); }

template <class T> CList<T>::CList(const CList<T> &other) { copy(other); }

template <class T> const CList<T> &CList<T>::operator=(const CList<T> &other) {
  if (this != &other) {
    destroy();
    copy(other);
  }

  return *this;
}

template <class T> void CList<T>::destroy() {
  if(first == NULL){
    return; // nothing to destroy
  }

  node<T> *walker = first; //walker is set to the first node
  node<T> *temp;

  do{
    temp = walker;
    walker = walker->next;
    delete temp;
  }while(walker != first);
  
  first = nullptr;
}


template <class T> void CList<T>::copy(const CList<T> &other) {
  length = other.length;

  if (other.first == NULL){
    first = NULL;
    return;
  }

  // Creating first node for current list
    first = new node<T>;
    first->info = other.first->info;
    first->back = NULL;

    node<T> *pOther = other.first->next;
    node<T> *q = first;

    while(pOther != other.first){
      // Creating a new node in list and copying info
      q->next = new node<T>;
      q->next->info = pOther->info;
      q->next->back = q;
      q = q->next; // Moves to the new node in the current list
      pOther = pOther->next; // moves to the next node in the list
    }
    q->next = first;
    first->back = q;
  }


template <class T> int CList<T>::getLength() { return length; }

template <class T> bool CList<T>::isEmpty() { return first == NULL; }

template <class T>
void CList<T>::insertItem(T item) {
    length++; // when item is added list increases and returns numer of items
    // Create a new node
    node<T>* newNode = new node<T>;
    newNode->info = item;

    // If the list is empty
    if (first == NULL) {
        first = newNode;
        first->next = first; // Circular list with only one node
        return;
    }

    // If the item is smaller than the first node
    if (item <= first->info) {
        // Find the last node
        node<T>* lastNode = first;
        while (lastNode->next != first) {
            lastNode = lastNode->next;
        }


        newNode->next = first; // Connect the new node to the first node
        lastNode->next = newNode; // Connect the last node to the new node
        first = newNode; // Update first to point to the new node (last node)
        return;
    }

    // Traverse to find the correct position to insert the new node
    node<T>* walker = first;
    while (walker->next != first && walker->next->info < item) {
        walker = walker->next;
    }

    // Insert the new node
    newNode->next = walker->next;
    walker->next = newNode;
}

template <class T>
void CList<T>::deleteItem(T item) {
    if (first == NULL) { // checking if the list is empty
        cout << "\nERROR - LIST EMPTY OR ITEM NOT THERE\n";
        return;
        //checking whether the first item in the list needs to be deleted
    }

    //Deleting the first node
    if (first->info == item) {
        if (first->next == first) { // Only one node in the list
            delete first;
            first = nullptr;
        } else {
            node<T> *temp = first; //  Store address of first node using temp
            node<T> *last = first;  // created a pointer to traverse list and find last  node
            while (last->next != first) { // traverse list to find  last node
                last = last->next; 
            }
            last->next = first->next; // update next pointer of the last node to skip over first
            first = first->next; // move the first pointer to the next node
            delete temp; // delete the first node
        }
        cout << "\nITEM DELETED\n";
        length--;
        return;
    }

    // Case 2: Deleting nodes in the middle or the last node
    node<T> *walker = first->next; // walker points to first->next
    node<T> *previous = first; // previous  points to first
    while (walker != first) { // traversing the list until walker reaches first
        if (walker->info == item) { // checking if data of current node is item to be deleted
            previous->next = walker->next; // update the next pointer of the previous node to skip current node
            delete walker;   // deleting the node with the item
            cout << "\nITEM DELETED\n";
            length--;
            return;
        }
        previous = walker;  // update previous to the current node before moving to next node
        walker = walker->next;  // move walker to the next node in the list
    }

    // Case 3: Deletion of last node
    if (walker == first && walker->info == item) {
        previous->next = first->next; // update the next pointer of the previous node to skip over the last node
        delete walker;  // deletes last node
        cout << "\nITEM DELETED\n";
        length--;
        return;
    }
    
    cout << "\nITEM NOT FOUND\n";

}
    


template <class T> bool CList<T>::searchItem(T item) {
  // Checking if list is empty
  if (first == NULL)
    return false;

  node<T> *p = first;
  do {
    // Checking if current node contains the search value
    if (p->info == item)
      return true;
    p = p->next; // moves to the next
  } while (p != first);
  return false;
}

template <class T> void CList<T>::printList() { // print list was done in class, straightforward. last points to first.
  if (first == NULL){
    cout << "\nLIST IS EMPTY\n";
    return;
  }
  
    node<T> *walker = first;
    do {
        cout << walker->info;
        if (walker->next != first) {
            cout << " -> ";
        }
        walker = walker->next;
    } while (walker != first);
    cout << endl;
  }




