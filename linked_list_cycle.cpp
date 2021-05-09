/******************************************************************************
 * Given head, the head of a linked list, determine if the linked list has a 
 * cycle in it. There is a cycle in a linked list if there is some node in the 
 * list that can be reached again by continuously following the next pointer.
 *****************************************************************************/

#include <cassert>
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;



struct ListNode
{
	int val;
	ListNode *next = nullptr;
};



bool HasCycle1(ListNode* const head)
{
	unordered_set<ListNode*> nodes_visited;
	for ( ListNode* node = head; node; node = node->next )
	{
		if ( nodes_visited.count(node) == 1 )  return true;
		nodes_visited.insert(node);
		cout << node->val << ' ';
	}
	return false;
}



bool HasCycle2(ListNode* head)
{
	if ( !head )  return false;
	ListNode* slow = head;
	ListNode* fast = head->next;
	while ( slow != fast )
	{
		if ( !fast || !fast->next )  return false;
		slow = slow->next;
		fast = fast->next->next;
	}
	return true;
}



int main()
{
	cout << boolalpha;
	ListNode a3 {3};  ListNode a2 {2, &a3};  ListNode a1 {1, &a2};
	cout << HasCycle1(&a1) << ' ' << HasCycle2(&a1) << '\n';
	
	ListNode b4 {4};  ListNode b3 {3, &b4};
	ListNode b2 {2, &b3};  ListNode b1 {1, &b2};
	b4.next = &b3;
	cout << HasCycle1(&b1) << ' ' << HasCycle2(&b1) << '\n';
}
