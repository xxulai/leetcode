// leetcode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MinStack.h"
#include "EasyCase.h"
#include "MediumCase.h"


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

	 void rotate(int nums[], int n, int k) {
        
        int tvalue=0;
        vector<int> tarray;
        
        if(k>n){
            k=k%n;
        }
        
        for(int i=0; i<n; i++){
            tarray.push_back(nums[i]);
        } 

		for(int i=0; i<k; i++)
		{
			nums[i]=tarray.at(n-k+i);
		}

		for(int i=k; i<n; i++)
		{
			nums[i]=tarray.at(i-k);
		}
     }

	 void rotateO1(int nums[], int n, int k){

		 int tvalue=0;
		 int steps=k%n;

		 for(int i=0; i<steps; i++){
			 tvalue=nums[n-1];
			 for(int i=n-1; i>=0; i--){
				 nums[i]=nums[i-1];
			 }
			 nums[0]=tvalue;
		 }
			 /*for(int i=0; i<n; i++){
				 nums[i+1]=nums[i];  WRONG!!!!, number will be polluted by num[1]
			 }*/
	 }

	 int strtoi(string s){
        int ret=0;
        int count=s.length()*2;
        
        
        for(string::iterator sit=s.begin(); sit!=s.end(); sit++)
        {
            int ivalue=0;

			if(*(sit)=='A') ivalue=0;
			else if(*(sit)=='C') {ivalue=1; ret+=pow(2.0, count-2);}
			else if(*(sit)=='G') {ivalue=2; ret+=pow(2.0, count-1);}
			else if(*(sit)=='T') {ivalue=3; ret+=pow(2.0, count-1)+pow(2.0, count-2);}
            
			count-=2;
        }
        
        return ret;
    }

	 vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ret;
		int size=s.length();
		unordered_map<char, int> charmp;
		unordered_map<int, int> mp;

		charmp.insert(std::pair<char, int>('A', 0));
		charmp.insert(std::pair<char, int>('C', 1));
		charmp.insert(std::pair<char, int>('G', 2));
		charmp.insert(std::pair<char, int>('T', 3));
		
		int ivalue=0;
		for(string::iterator sit=s.begin(); sit!=s.end(); sit++){
			string tvalue="";
			if(sit-s.begin()<9){
			    continue;
			}
			
			ivalue=(ivalue<<2+charmp[*(sit)])&0xFFFFF;
			
			if(mp.count(ivalue)){
				if(mp[ivalue]>0)
				{
					mp[ivalue]+=1;
				}
				else
				{
				    for(int i=9; i>0; i--) {tvalue+=*(sit-i);}
					ret.push_back(tvalue);	
					mp[ivalue]=1;
				}
			}else{
				mp.insert(std::pair<int, int>(ivalue, 0));
			}
			
		}

		return ret;
     }


	  vector<string> findRepeatedDnaSequencesIndex(string s) {
        vector<string> ret;
		int size=s.length();
		unordered_map<char, int> charmp;
		unordered_map<int, int> mp;

		charmp.insert(std::pair<char, int>('A', 0));
		charmp.insert(std::pair<char, int>('C', 1));
		charmp.insert(std::pair<char, int>('G', 2));
		charmp.insert(std::pair<char, int>('T', 3));
		
		int ivalue=0;
		for(int i=0; i<s.length(); i++){
			string tvalue="";

			ivalue<<=2;
			ivalue=(ivalue+charmp[s.at(i)])&0xFFFFF;

			if(i<9){
			    continue;
			}
			
			if(mp.count(ivalue)){
				if(mp[ivalue]>0)
				{
					mp[ivalue]+=1;
				}
				else
				{
				    tvalue=s.substr(i-9, 10);
					ret.push_back(tvalue);	
					mp[ivalue]=1;
				}
			}else{
				mp.insert(std::pair<int, int>(ivalue, 0));
			}
			
		}

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

	bool samevector(vector<int> &num){

		bool ret=true;

		for(vector<int>::iterator it=num.begin(); it!=num.end()-1; it++){
			if(*it!=*(it+1)){
				ret=false;
			}
		}

		return ret;
	}

	int majorityElement(vector<int> &num) {
        
		unordered_map<int, int> mp;
		int ret=num.at(0);

		for(vector<int>::iterator it=num.begin(); it!=num.end(); it++){
			if(mp.count(*it)){
				mp[*it]+=1;
				if(mp[*it]>num.size()/2){
					ret=*it;
					break;
				}
			} else{
				mp.insert(std::pair<int, int>(*it, 1));
			}
		}
		return ret; 
    }

	int titleToNumber(string s) {

		int length=s.length();
		char tchar='A';
		int ret=0;
		

		std::unordered_map<char, int> mp;

		for(int i=0; i<26; i++){
			mp.insert(std::pair<char, int>(tchar+i, i+1));
		}

        for(string::iterator sit=s.begin(); sit!=s.end(); sit++){
			ret+=mp[*sit]*pow(26.0, length-1);
			length--;
		}

		return ret;
    }

	//split 13.25.2.6  into vector 13 25 2 6
	vector<string> refineString(string& str){
		vector<string> ret;
		string tvalue;
		string::iterator rit=str.begin();

		for(string::iterator sit=rit; sit!=str.end(); sit++){
			if(*sit=='.'){
				ret.push_back(tvalue);
				tvalue="";
				continue;
			}
			tvalue+=*sit;
		}

		ret.push_back(tvalue);

		return ret;
	}

    int compareVersion(string version1, string version2) {
	    int ret=0;
		vector<string> refined1=refineString(version1);
		vector<string> refined2=refineString(version2);

		vector<string>::iterator sit1=refined1.begin();
		vector<string>::iterator sit2=refined2.begin();

		int cmp1=0;
		int cmp2=0;

		while(sit1!=refined1.end() || sit2!=refined2.end()){
			
			if(sit1==refined1.end()) cmp1=0;
			else {cmp1=atoi(sit1->c_str()); sit1++;}

			if(sit2==refined2.end()) cmp2=0;
			else {cmp2=atoi(sit2->c_str()); sit2++;}

			if(cmp1>cmp2){ret=1; break;}
			else if(cmp1<cmp2) {ret=-1; break;}
		}

        return ret;
    }

	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ret=NULL;
        ListNode *pointA=headA;
        ListNode *pointB=headB;
        int lengthA=1;
        int lengthB=1;
        
        if(pointA==NULL || pointB==NULL) return NULL;
        
        while(pointA->next!=NULL){
            pointA=pointA->next;
            lengthA++;
        }
        
        while(pointB->next!=NULL){
            pointB=pointB->next;
            lengthB++;
        }
        
        pointA=headA;
        pointB=headB;
        
        for(int i=0;i<(lengthA-lengthB); i++){ pointA=pointA->next; }
        for(int i=0;i<(lengthB-lengthA); i++){ pointB=pointB->next; }
        
        while(pointA!=NULL || pointB!=NULL){
            
            if(pointA==pointB) return pointA;
            else{ pointA=pointA->next; pointB=pointB->next;}
            
        }
        return ret;
    }


int _tmain(int argc, _TCHAR* argv[])
{
	string out, out1;
	int input=24568;
	out = convertToTitle(input);
	
	input=729;
	out = convertToTitle(input);
	out1=convertTT(input);

	
	/*unordered_map<int, int> mp;
	string str;
	for(int i=0; i<300000; i++)
	{
		str+="test"+to_string((_ULonglong)i);
		mp.insert(std::pair<int, int>(i, i));
	}*/
	
	uint32_t a;
	a=1;
	a=reverseBits(a);
	
	input = atoii("  -1234567890123456789");

	int intinput[]={1, 2, 3, 4, 5, 6, 7, 8};
	rotateO1(intinput, 8, 125);

	string strinput="GAGAGAGAGAGA";
	
	vector<string> ret;
	ret=findRepeatedDnaSequencesIndex(strinput);

	
	vector<int> num;

	int iarray[]={0,0};

	for(int i=0; i<sizeof(iarray)/sizeof(int); i++){
		num.push_back(iarray[i]);
	}

	out=::largestNumber(num);

	//majorityElement
	int majorityElementarray[]={1};

	vector<int> majorityElementVector;
	for(int i=0; i<sizeof(majorityElementarray)/sizeof(int); i++){
		majorityElementVector.push_back(majorityElementarray[i]);
	}
	int t=majorityElement(majorityElementVector);

	int inttitleToNumber = titleToNumber("BA");

	int test=compareVersion("1", "1.2");

	MinStack *ms=new MinStack();
	
	ms->push(2147483646);
	ms->push(2147483646);
	ms->push(2147483647);
	
	ms->top();
	ms->pop();
	ms->getMin();
	ms->pop();
	ms->getMin();
	ms->pop();

	EasyCase *ec = new EasyCase();
	ec->isPalindrome("1a2");

	vector<vector<int>> generateret=ec->generate(2);
	vector<int> getRowret=ec->getRow(3);

	MediumCase *mc=new MediumCase();
	TreeNode *root=new TreeNode(5);
	TreeNode *left=new TreeNode(1);
	TreeNode *right=new TreeNode(6);

	root->left=left;
	root->right=right;

	TreeNode *left1=new TreeNode(2);
	TreeNode *right1=new TreeNode(3);
	left->left=left1;
	left->right=right1;

	TreeNode *left2=new TreeNode(4);
	left1->left=left2;

	vector<vector<int>> pathSumII=mc->pathSumII(root, 20);

	ListNode *head=new ListNode(1);
	ListNode *p1=new ListNode(1);
	ListNode *p2=new ListNode(1);

	head->next=p1;
	p1->next=p2;

	head=mc->deleteDuplicatesII(head);

	vector<int> tc;
	tc.push_back(1);
	tc.push_back(0);
	vector<int> tc2;
	tc2.push_back(1);
	
	tc=ec->plusOne(tc);

	string addBinaryret="";

	addBinaryret=ec->addBinary("101111", "10");

	return 0;
}

