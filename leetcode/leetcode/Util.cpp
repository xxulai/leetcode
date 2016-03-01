#include "stdafx.h"
#include "Util.h"

template<typename T>
ListNode* Util::genListNodeList(vector<typename T> vec)
{
	ListNode *head=NULL;
	ListNode *tail=head;
	for(int i=0; i<vec.size(); i++)
	{
		ListNode * tmp=new ListNode(vec.at(i));
		if(head==NULL)
		{
			head=tmp;
			tail=tmp;
		}
		else
		{
			tail->next=tmp;
			tail=tmp;
		}
	}
	return head;
}