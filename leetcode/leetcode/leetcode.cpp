// leetcode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DataStructure.h"


/*
	vector<int> input;
	input.push_back(3);
	input.push_back(2);
	input.push_back(4);

	input=twoSum(input, 6);
*/
vector<int> twoSum(vector<int> &numbers, int target) {
	vector<int> ret;
	unordered_map<int, int> hm;
	unordered_map<int, int>::iterator it;    
	
	for(int i=0; i<numbers.size(); i++){
		if(hm.count(numbers.at(i))){
			//hm contains same number 0, 3, 0    target = 0
			if(numbers.at(i)*2==target){
				ret.push_back(hm.find(numbers.at(i))->second);
				ret.push_back(i+1);
				break;
			}
		}
		else{
			hm.insert(std::pair<int, int>(numbers.at(i), i+1));
		}
	}

	if(ret.size()==0){
		for(it=hm.begin(); it!=hm.end(); it++){
			if(hm.count(target-it->first) && hm.find(target-it->first)->second != it->second){
    				ret.push_back(it->second);
    				ret.push_back(hm.find(target-it->first)->second);
    				break;
    		}
		}
	}

	return ret;
}


/*
	ListNode *t1=new ListNode(5);
	ListNode *t2=new ListNode(5);
	ListNode *out;

	out=addTwoNumbers(t1, t2);
*/
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *ret=new ListNode(-1);
        ListNode *t1=l1;
        ListNode *t2=l2;
        ListNode *cur_ret=ret;
        int tvalue=0;
        int carry=0;
        
        do{
            if(t1 != NULL) tvalue+=t1->val;
            if(t2 != NULL) tvalue+=t2->val;
            
            tvalue+=carry;
            
            if(tvalue>=10){
                tvalue-=10;
                carry=1;
            } 
            else{
                carry=0;
            }
            
            if(cur_ret->val==-1){
                //first element
                cur_ret->val=tvalue;
            }
            else{
               cur_ret->next=new ListNode(tvalue);
               cur_ret=cur_ret->next;
            }
            
            if(t1!=NULL) t1=t1->next;
            if(t2!=NULL) t2=t2->next;
            tvalue=0;
            
        }while(t1!=NULL || t2!=NULL);

		if(carry){
            cur_ret->next=new ListNode(carry);
        }
		
        return ret;
    }


	string convertToTitle(int n) {
        string ret;
        int tn=n;

		string dic[]={"", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
        
         for(int i=0; i<n/26; i++){
            ret+="A";
        }
        
        ret+=dic[n%26];
        
        return ret;
    }

int _tmain(int argc, _TCHAR* argv[])
{
	string out;
	int input=24568;
	out = convertToTitle(input);
	
	
	return 0;
}

