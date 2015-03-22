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

	string largestNumber(vector<int> &num) {
		string ret;
		vector<string> strvec;

		for(vector<int>::iterator it=num.begin(); it!=num.end(); it++){
			char t[32];
			sprintf_s(t, sizeof(t)/sizeof(char), "%d", *(it));
			//itoa(*it, t, 10);
			strvec.push_back(t);
		}

		bool swflag=true;

		while(swflag){
			swflag=false;
			for(vector<string>::iterator sit=strvec.begin(); sit!=strvec.end(); sit++){
				//char strvalue[256];
				//char strvalue1[256];

				if((sit+1)==strvec.end())
				{
					break;
				}

				string strvalue=*sit+*(sit+1);
				string strvalue1=*(sit+1)+*(sit);

				//sprintf_s(strvalue, "%s%s", sit->c_str(), (sit+1)->c_str());
				//long tvalue=strtol(strvalue, &end, 10);
				//sprintf_s(strvalue1, "%s%s", (sit+1)->c_str(), (sit)->c_str());
				//long tvalue1=strtol(strvalue, &end, 10);

				if(strvalue<strvalue1){
					//switch
					string tvalue=*(sit+1);
					*(sit+1)=*sit;
					*sit=tvalue;
					swflag=true;
				}
			}
		}
		
		for(vector<string>::iterator sit=strvec.begin(); sit!=strvec.end(); sit++){
			ret+=*(sit);
		}

		if(atoi(ret.c_str())==0){
			ret="0";
		}

		return ret;
    }


	static bool cmp(string &a, string &b) {
		//return a+b>b+a;
		return false;
	}
	string largestNumbersample(vector<int> &num) {
		vector<string> snum;
		for (int i = 0; i < num.size(); i++){
			char t[256];
			itoa(num[i], t, 10);
			snum.push_back(t);
		}
 
		sort(snum.begin(), snum.end(), cmp);
 
		string res = "";
		for (int i = 0; i < snum.size(); i++)
			res += snum[i];
     
		if (res[0] == '0')
			return "0";
		return res;
	}


int _tmain(int argc, _TCHAR* argv[])
{
	string out;
	int input=24568;
	out = convertToTitle(input);
	
	vector<int> num;

	int iarray[]={0,0};

	for(int i=0; i<sizeof(iarray)/sizeof(int); i++){
		num.push_back(iarray[i]);
	}

	out=::largestNumber(num);

	
	return 0;
}

