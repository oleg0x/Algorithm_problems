/******************************************************************************
 * Given the head of a linked list, rotate the list to the right by k places.
 *****************************************************************************/

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;



struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};



ListNode* RotateRight(ListNode* head, int k)
{
	if ( !head || !head->next )  return head;
	ListNode* node = head;
	int len = 1;
    for ( ; node->next != nullptr; node = node->next )  ++len;
	node->next = head;
	node = head;
	for ( int i = 0; i < len - 1 - k % len; i++ )  node = node->next;
	head = node->next;
	node->next = nullptr;
	return head;
}



void PrintList(const ListNode* const node)
{
	for ( const ListNode* p = node; p; p = p->next )  cout << p->val << ' ';
	cout << '\n';
}



int main()
{
	{
		ListNode b2(2);
		ListNode b1(1, &b2);
		PrintList(&b1);
		auto p = RotateRight(&b1, 3);
		PrintList(p);
	}
	
	{
		ListNode a5(5);
		ListNode a4(4, &a5);
		ListNode a3(3, &a4);
		ListNode a2(2, &a3);
		ListNode a1(1, &a2);
		PrintList(&a1);
		auto p = RotateRight(&a1, 3);
		PrintList(p);
	}
}
