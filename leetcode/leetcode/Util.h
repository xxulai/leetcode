#include "DataStructure.h"

class Util{
public:
	//template involved, implementation has to be inside .h file?
	template<typename T> 
	ListNode* genListNodeList(vector<typename T> vec)
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

	vector<int> getVecByArray(int[], int);
};