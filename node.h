/***********************************************************************
 * Header:
 *    NODE
 * Summary:
 *    One node in a linked list (and the functions to support them).
 *      __      __     _______        __
 *     /  |    /  |   |  _____|   _  / /
 *     `| |    `| |   | |____    (_)/ /
 *      | |     | |   '_.____''.   / / _
 *     _| |_   _| |_  | \____) |  / / (_)
 *    |_____| |_____|  \______.' /_/
 *
 *    This will contain the class definition of:
 *        Node         : A class representing a Node
 *    Additionally, it will contain a few functions working on Node
 * Author
 *    <your names here>
 ************************************************************************/

#pragma once

#include <cassert>     // for ASSERT
#include <iostream>    // for NULL

/*************************************************
 * NODE
 * the node class.  Since we do not validate any
 * of the setters, there is no point in making them
 * private.  This is the case because only the
 * List class can make validation decisions
 *************************************************/
template <class T>
class Node
{
public:


   //
   // Construct
   //
   //
   // Construct
   //

	/*Node.default-constructor()
 data -> T()
 pNext -> NULL
 pPrev -> NULL*/
   Node() 
   { 
		this->data=T();
		this->pNext=NULL;
		this->pPrev=NULL;
		//pNext = pPrev = this;
   }

   /*Node.copy-constructor(t)
 data -> t
 pNext -> NULL
 pPrev -> NULL*/
   Node(const T& data) 
   {
		this->data = data;
		this->pNext = NULL;
		this->pPrev = NULL;
		//pNext = pPrev = this;
   }

   /*copy(pSource)
 pDestination -> new Node(pSource.data)
 pSrc -> pSource
 pDes -> pDestination
 FOR pSrc -> pSrc.pNext … end of the list
 pDes -> insert(pSrc.data, pDes, true)
 return pDestination*/
   Node(T&& data) 
   {
	   this->data = data;
	   this->pNext = NULL;
	   this->pPrev = NULL;
      //pNext = pPrev = this;
   }

   //
   // Member variables
   //

   T data;                 // user data
   Node <T> * pNext;       // pointer to next node
   Node <T> * pPrev;       // pointer to previous node
};

/***********************************************
 * COPY
 * Copy the list from the pSource and return
 * the new list
 *   INPUT  : the list to be copied
 *   OUTPUT : return the new list
 *   COST   : O(n)
 **********************************************/
template <class T>
inline Node <T> * copy(const Node <T> * pSource) 
{

   return new Node<T>;
}

/***********************************************
 * Assign
 * Copy the values from pSource into pDestination
 * reusing the nodes already created in pDestination if possible.
 *   INPUT  : the list to be copied
 *   OUTPUT : return the new list
 *   COST   : O(n)
 **********************************************/
/*pSrc -> pSource
pDes -> pDestination
WHILE pSrc ≠ NULL AND pDest ≠ NULL
 pDes.data -> pSrc.data
 pDes -> pDes.pNext
 pSrc -> pSrc.pNext

 Step II:
 IF pSrc ≠ NULL
 pDes -> pDesPrevious
 WHILE pSrc ≠ NULL
 pDes -> insert(pDes, pSrc.data, TRUE)
 IF pDestination = NULL
 pDestination -> pDes


 Step III:
 IF pSrc ≠ NULL
 setToNull -> FALSE
 IF pDes.pRev ≠ NULL
 pDEs.pPrev.pNext -> NULL
 ELSE
 setToNull -> TRUE
 freeData(pDes)
 IF setToNull
 pDestination -> NULL

 */
template <class T>
inline void assign(Node <T> * & pDestination, const Node <T> * pSource)
{
		//Step I :
	const Node <T>* pSrc=pSource;
	const Node <T>* pDest=pDestination;
	while(pSrc != NULL && pDest != NULL)
	{
		pDest.data=pSrc.data;
		pDest=pDest.pNext;
		pSrc=pSrc.pNext;
	}

		//Step II :
	if (pSrc != NULL)
	{
		pDest->pDesPrevious;
			while (pSrc != NULL)
			{
				pDest.insert(pDest, pSrc.data, true);
					if (pDestination = NULL)
						pDestination->pDest;
			}
	}


		//Step III :
	bool setToNull;
	if (pSrc != NULL)
		setToNull=false;
	if (pDest.pRev != NULL)
		pDest.pPrev.pNext=NULL;
	else
	{
		setToNull=true;
		freeData(pDest);
	}
	if (setToNull)
		pDestination=NULL;
}

/***********************************************
 * SWAP
 * Swap the list from LHS to RHS
 *   COST   : O(1)
 **********************************************/
template <class T>
inline void swap(Node <T>* &pLHS, Node <T>* &pRHS)
{
   
}

/***********************************************
 * REMOVE
 * Remove the node pSource in the linked list
 *   INPUT  : the node to be removed
 *   OUTPUT : the pointer to the parent node
 *   COST   : O(1)
 **********************************************/
/*remove(pRemove)
 IF NULL = pRemove
 return
 IF pRemove.pPrev
 pRemove.pPrev.pNext -> pRemove.pNext
 IF pRemove.pNext
 pRemove.pNext.pPrev -> pRemove.pPrev
 IF pRemove.pPrev
 pReturn -> pRemove.pPrev;
 ELSE
 pReturn -> pRemove.pNext
 DELETE pRemove
 return pReturn*/
template <class T>
inline Node <T> * remove(const Node <T> * pRemove) 
{
	Node <T>* pReturn = new Node <T>();
	if (pRemove = NULL)
		return NULL;
	if (pRemove.pPrev)
		pRemove.pPrev.pNext->pRemove.pNext;
	if (pRemove.pNext)
		pRemove.pNext.pPrev->pRemove.pPrev;
	if (pRemove.pPrev)
		pReturn->pRemove.pPrev;
	else
		pReturn->pRemove.pNext;
		delete pRemove;
	return pReturn;
}


/**********************************************
 * INSERT 
 * Insert a new node the the value in "t" into a linked
 * list immediately before the current position.
 *   INPUT   : t - the value to be used for the new node
 *             pCurrent - a pointer to the node before which
 *                we will be inserting the new node
 *             after - whether we will be inserting after
 *   OUTPUT  : return the newly inserted item
 *   COST    : O(1)
 **********************************************/

/*insert(t, pCurrent, after)
 pNew -> NEW Node(t)
 IF pCurrent ≠ NULL and after = false
 pNew.pNext -> pCurrent
 pNew.pPrev -> pCurrent.pPrev
 pCurrent.pPrev -> pNew
 IF pNew.pPrev
 pNew.pPrev.pNext -> pNew
 IF pCurrent ≠ NULL and after = true
 … something similar …
 return pNew
*/
template <class T>
inline Node <T> * insert(Node <T> * pCurrent,
                  const T & t,
                  bool after = false)
{
	Node <T>* pNew = new Node<T>();
	if (pCurrent != NULL && after = false)
	{
		pNew.pNext->pCurrent;
		pNew.pPrev->pCurrent.pPrev;
		pCurrent.pPrev->pNew;
	}
	if (pNew.pPrev)
		pNew.pPrev.pNext->pNew;
	if (pCurrent != NULL && after = true)
		pNew.pNext->pNew;
   return pNew;
}

/******************************************************
 * FIND
 * Find a given node in an unsorted linked list.  Return
 * a pointer to the node if it is found, NULL otherwise.
 *  INPUT   : a pointer to the head of the linked list
 *            the value to be found
 *  OUTPUT  : a pointer to the node if it is found
 *  COST    : O(n)
 ********************************************************/
/*size(pHead)
 s -> 0
 FOR p ->pHead … end of the list
 s -> s + 1
 return s
*/
template <class T>
inline size_t size(const Node <T> * pHead)
{
	int s = 0;
	for (Node <T> * p = pHead; p; p = p->pNext)
		s++;
   return s;
}

/***********************************************
 * DISPLAY
 * Display all the items in the linked list from here on back
 *    INPUT  : the output stream
 *             pointer to the linked list
 *    OUTPUT : the data from the linked list on the screen
 *    COST   : O(n)
 **********************************************/
template <class T>
inline std::ostream & operator << (std::ostream & out, const Node <T> * pHead)
{
	for (Node <T>* p = pHead; p; p = p->pNext)
		std::cout << p->data;
   return out;
}

/*****************************************************
 * FREE DATA
 * Free all the data currently in the linked list
 *   INPUT   : pointer to the head of the linked list
 *   OUTPUT  : pHead set to NULL
 *   COST    : O(n)
 ****************************************************/
/*clear(pHead)
 WHILE pHead ≠ NULL
 pDelete -> pHead
 pHead -> pHead.pNext
 DELETE pDelete*/
template <class T>
inline void clear(Node <T>*& pHead)
{
	Node <T>* pDelete;
	while(pHead != NULL)
	{
		pDelete->pHead;
		pHead->pHead.pNext;
		delete pDelete;
	}
}


