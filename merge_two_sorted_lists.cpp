/******************************************************************************
 * Merge two sorted linked lists and return it as a sorted list. The list 
 * should be made by splicing together the nodes of the first two lists.
 *****************************************************************************/

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;



struct ListNode
{
	int val;
	ListNode* next;
	ListNode() : val {0}, next {nullptr} {}
	ListNode(int x) : val {x}, next {nullptr} {}
	ListNode(int x, ListNode* next) : val {x}, next {next} {}
};



ListNode* MergeTwoLists1(ListNode* l1, ListNode* l2)  // Recursive function
{
	if ( l1 == nullptr )  return l2;
	if ( l2 == nullptr )  return l1;
	
	if ( l1->val < l2->val )
	{
		l1->next = MergeTwoLists1(l1->next, l2);
		return l1;
	}

	l2->next = MergeTwoLists1(l1, l2->next);
	return l2;
}



ListNode* MergeTwoLists2(ListNode* l1, ListNode* l2)
{
	if ( l1 == nullptr )  return l2;
	if ( l2 == nullptr )  return l1;
	
	ListNode* res = new ListNode;
	ListNode* cur;
	
	for ( cur = res; l1 && l2; cur = cur->next )
		if ( l1->val < l2->val )
		{
			cur->next = new ListNode(l1->val);
			l1 = l1->next;
		}
		else
		{
			cur->next = new ListNode(l2->val);
			l2 = l2->next;
		}

	if ( l1 )  cur->next = l1;
	if ( l2 )  cur->next = l2;
	
	return res->next;
}



void PrintList(const ListNode* node)
{
	for ( ; node; node = node->next )  cout << node->val << ' ';
	cout << '\n';
}



int main()
{
	{
		ListNode a2(4);  ListNode a1(2, &a2);  ListNode a(1, &a1);
		ListNode b2(4);  ListNode b1(3, &b2);  ListNode b(1, &b1);
		PrintList(MergeTwoLists1(&a, &b));
	}
	
	{
		ListNode a2(4);  ListNode a1(2, &a2);  ListNode a(1, &a1);
		ListNode b2(4);  ListNode b1(3, &b2);  ListNode b(1, &b1);
		PrintList(MergeTwoLists2(&a, &b));
	}
	
	{
		ListNode a2(9);  ListNode a1(4, &a2);  ListNode a(1, &a1);
		ListNode b3(8);  ListNode b2(5, &b3);  ListNode b1(3, &b2);  ListNode b(2, &b1);
		PrintList(MergeTwoLists1(&a, &b));
	}
	
	{
		ListNode a2(9);  ListNode a1(4, &a2);  ListNode a(1, &a1);
		ListNode b3(8);  ListNode b2(5, &b3);  ListNode b1(3, &b2);  ListNode b(2, &b1);
		PrintList(MergeTwoLists2(&a, &b));
	}
}
