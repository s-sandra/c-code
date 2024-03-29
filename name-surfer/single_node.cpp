/*
@author Sandra Shtabnaya

assignment: name surfer
purpose: defines ListNode, which is element of linked_list
*/

#include "single_node.h"
#ifndef NODE_CPP
#define NODE_CPP

template <class NODETYPE>
ListNode<NODETYPE>::ListNode(const NODETYPE &info){
	data = info;
	next = 0;
}

template <class NODETYPE>
NODETYPE ListNode<NODETYPE>::getData() const{
	return data;
}
#endif
