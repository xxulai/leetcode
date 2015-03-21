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
		string fret;

		string dic[26]={"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};

		while(n > 0){
            int indexNum = n % 26;
            if(indexNum == 0){
                indexNum = 26;
            }
            ret=dic[indexNum-1]+ret;
            n = (n-1) / 26;
        }
		/*for (std::string::reverse_iterator rit=ret.rbegin(); rit!=ret.rend(); ++rit)
			fret+=*rit;*/
		
        return ret;
    }

	string convertTT(int n){
		string ret;

		if(n<=0){
			return "";
		}

		string dic[26]={"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};

		int indexNum=n%26;

		if(indexNum==0){
			indexNum=26;
		}

		ret=convertTT((n-1)/26)+dic[indexNum-1];
		return ret;
	}

	int atoii(string str) {
		vector<char> ve;
        int ret=0;
        bool firstflag=true;
		bool badnumber=false;
        
        for (std::string::iterator it=str.begin(); it!=str.end(); it++)
        {
            if(firstflag && *it == ' '){
				//skip start space
                continue;
            }



            if(firstflag)
            {
                firstflag=false;
            }

            if(*it>'9' || *it<'0')
            {
				//not numeric between, return 0
				badnumber=true;
                ret=0;
                break;
            }
            
            ve.push_back(*it);
        }

		if(!badnumber){
			for(int i=0; i<ve.size(); i++){
				if(ve.at(i)>'9' || ve.at(i)<'0'){
					ret=0;
					break;
				} else{
					ret+=ve.at(ve.size()-1-i)*pow(10.0, i);
				}
			}
		}

		return ret;
	}

	 uint32_t reverseBits(uint32_t n) {
        uint32_t ret=0;
        
        vector<int> bits;
        
        if(n==0){
            return n;
        }
        
        for(int i=0; i<32; i++)   //32/4
        {
            bits.push_back(n%2);
            n=n/2;
        }
            
        for(int i=32; i>0; i--){
            ret+=bits.at(32-i)*pow(2.0, i-1);
        }
        
        return ret;
    }

int _tmain(int argc, _TCHAR* argv[])
{
	string out, out1;
	int input=729;
	out = convertToTitle(input);
	out1=convertTT(input);
	
	uint32_t a;
	a=1;
	a=reverseBits(a);
	
	input = atoii("  -1234567890123456789");



	return 0;
}

