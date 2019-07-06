/*
@author Sandra Shtabnaya

assignment: name surfer
purpose: declares ListNode, which is element of linked_list
*/

#ifndef NODE
#define NODE


template <class NODETYPE> class linked_list;

template <class NODETYPE>
class ListNode{
	friend class linked_list<NODETYPE>;
public:
	ListNode() { next = 0; }
	ListNode(const NODETYPE &);
	NODETYPE getData() const;
private:
	NODETYPE data;
	ListNode <NODETYPE>*next;
};
#include "single_node.cpp"

#endif
