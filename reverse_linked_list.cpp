/******************************************************************************
 * Given the head of a singly linked list, reverse the list, and return the 
 * reversed list.
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
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};



ListNode* ReverseList1(ListNode* const head)
{
    ListNode* prev = nullptr;
	for ( ListNode *curr = head, *temp;  curr;  curr = temp )
	{
        temp = curr->next;
        curr->next = prev;
        prev = curr;
    }
    return prev;
}



ListNode* ReverseList2(ListNode* head)  // Recursive
{
    if ( !head || !head->next )  return head;
    ListNode* p = ReverseList2(head->next);
    head->next->next = head;
    head->next = nullptr;
    return p;
}



void PrintList(const ListNode* const node)
{
	for ( const ListNode* p = node; p; p = p->next )  cout << p->val << ' ';
	cout << '\n';
}



int main()
{
	{
		PrintList(nullptr);
		PrintList(ReverseList1(nullptr));
	}
	
	{
		ListNode b2(2);
		ListNode b1(1, &b2);
		PrintList(&b1);
		auto p = ReverseList1(&b1);
		PrintList(p);
		PrintList(ReverseList2(p));
	}
	
	{
		ListNode a5(5);
		ListNode a4(4, &a5);
		ListNode a3(3, &a4);
		ListNode a2(2, &a3);
		ListNode a1(1, &a2);
		PrintList(&a1);
		auto p = ReverseList1(&a1);
		PrintList(p);
		PrintList(ReverseList2(p));
	}
}
