// leetcode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MinStack.h"
#include "EasyCase.h"
#include "MediumCase.h"
#include "HardCase.h"
#include "Util.h"

#include "DataStructure.h"

using namespace std;


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

	EasyCase *ec = new EasyCase();
	HardCase *hc = new HardCase();
	
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
	int t=ec->majorityElement(majorityElementVector);

	int inttitleToNumber = ec->titleToNumber("BA");

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

	int intlengthOfLastWord=ec->lengthOfLastWord("a ");

	string strtranslate=ec->countAndSay(6);
	char *cp1="";
	char *cp2="a";
	int istrStr=ec->strStr(cp1, cp2);

	string strzigzag=ec->convert("PAYPALISHIRING",3);
	int reverseint=ec->reverse(1534236469);
	reverseint=ec->reverse(2147483647);

	int intatoi=ec->atoi("-2147483647");
	bool isPal=ec->isPalindrome(0);

	vector<string> vstrcommon;
	vstrcommon.push_back("a");
	vstrcommon.push_back("a");
	vstrcommon.push_back("a");
	string strcommon=ec->longestCommonPrefix(vstrcommon);

	string tt="123456";
	char cc=tt[2]; //cc='3'

	ListNode *rhead=new ListNode(1);
	ListNode *head1=new ListNode(2);
	ListNode *head2=new ListNode(3);

	rhead->next=head1;
	//head1->next=head2;

	rhead=ec->removeNthFromEnd(rhead, 1);

	bool flaghappy=ec->isHappy(7);

	int rangebit=0x7fffff00;

	rangebit=rangebit%16;

	mc->rangeBitwiseAnd(2147483646, 2147483647);

	ec->countPrimes(5);

	string strfrac=mc->fractionToDecimal(1, 99);

	int arr[]={-4,-5,-6,3,11,-13,3,14,1,-10,11,6,8,9,-6,-9,6,3,-15,-8,0,5,6,-8,14,-11,0,2,14,-15,14,-13,-5,-15,5,13,-13,-6,13,-4,-1,1,-13,14,-13,-12,-10,9,6,12,8,14,-5,-8,-9,-6,-4,-2,3,-5,-2,-6,-2,1,-5,-12,-1,-11,-11,-11,0,-4,-2,-5,-5,0,-2,-7,-14,-10,-10,10,-11,-8,-13,-13,1,-2,-7,11,8,6,-9,-9,14,1,-13,-9,-3,-9,-5,13,2,8,-7,13,-14,6,-9,-13,3,-12};
	vector<int> threesum;
	
	for(int i=0; i<sizeof(arr)/sizeof(int); i++)
		threesum.push_back(arr[i]);
	mc->threeSum(threesum);

	ListNode *reversehead=new ListNode(1);
	reversehead->next=new ListNode(2);
	reversehead->next->next=new ListNode(3);

	//mc->reorderList(reversehead);

	string str="WÃ¼nscher";   //"Wünscher"
	string outstr="";
	int ch=0;
	for(string::iterator a=str.begin(); a!=str.end(); a++){
		ch=*a;
		if (!(*a&128))
			//Byte represents an ASCII character. 
			outstr+=*a;
		else if ((*a&192)==128)
			//Byte is the middle of an encoded character. Ignore.
			continue;
		else if ((*a&224)==192)
			//Byte represents the start of an encoded character in the range
			//U+0080 to U+07FF
			outstr+=((*a&31)<<6)|a[1]&63;
		else if ((*a&240)==224)
			//Byte represents the start of an encoded character in the range
			//U+07FF to U+FFFF
			outstr+=((*a&15)<<12)|((a[1]&63)<<6)|a[2]&63;
		else if ((*a&248)==240){
			//Byte represents the start of an encoded character beyond the
			//U+FFFF limit of 16-bit integers
			outstr='?';
		}
	}

	map<string, map<string, string> > language_mp;
	map<string, string> bufmp;

	vector<string> ss;

	ss.push_back("DE");
	ss.push_back("aa");
	ss.push_back("ae");

	bufmp.insert(pair<string, string>("uu", "ue"));
	language_mp.insert(pair<string, map<string, string> >("DE", bufmp));
	
	language_mp[ss.at(0)].insert(pair<string, string>(ss.at(1), ss.at(2)));

	const char* sstr="Vo-LCâ„¢";
	unsigned offSet=9;
	sstr=sstr+offSet;

	vector<int> *ndvec=new vector<int>;
	
	/*for(int i=0; i<2147483647; i++)
		ndvec->push_back(i);

	bool ndbvalue=false;
	//ndbvalue=ec->containsNearbyDuplicate(ndvec, 1);
	ndbvalue=mc->containsNearbyAlmostDuplicate(*ndvec, 1, 2147483647);//[7,1,3], 2, 3
	*/
	int addDigitsval=ec->addDigits(385);
	/*int zeroarr[]={0,1,0};
	vector<int> zerovec(zeroarr.begin(), zeroarr.end());*/
	vector<int> zerovec;
	zerovec.push_back(1);
	zerovec.push_back(1);
	zerovec.push_back(2);
	zerovec.push_back(2);

	ec->moveZeroes(zerovec);

	bool anagflag=ec->isAnagram("ab", "ba");

	ec->NremoveDuplicates(zerovec);

	ListNode *head11=new ListNode(1);
	ListNode *p11=new ListNode(2);
	ListNode *p21=new ListNode(3);

	head11->next=p11;
	p11->next=p21;

	ListNode *revershead=ec->reverseList2(head11);

	vector<int> fvect;
	//fvect.push_back(3);
	//fvect.push_back(4);
	fvect.push_back(1);
	fvect.push_back(1);
	
	//int firstmissingp=hc->firstMissingPositive(fvect);

	ListNode *pp1=new ListNode(5);
	ListNode *pp2=new ListNode(1);
	pp2->next=new ListNode(2);
	pp2->next->next=new ListNode(4);
	pp1=ec->mergeTwoLists(pp1, pp2);

	vector<int> sr;
	sr.push_back(0);
	sr.push_back(1);
	
	vector<string> strsr=ec->summaryRanges(sr);

	ListNode *pdp1=new ListNode(1);
	ListNode *pdp2=new ListNode(0);
	ListNode *pdp3=new ListNode(1);
	pdp1->next=pdp2;
	pdp2->next=pdp3;
	bool pbvalue=ec->isPalindrome_lessspace(pdp1);

	string pattern="abba";
	string pa_str="cat cat cat cat";
	bool pa_r=ec->wordPattern(pattern, pa_str);

	string str_hint=ec->getHint("1234","0111");

	bool isvalidb=ec->isValid("({[[[]]]})");

	vector<int> odd_list;
	odd_list.push_back(1);
	odd_list.push_back(2);
	odd_list.push_back(3);
	odd_list.push_back(4);
	odd_list.push_back(5);
	Util util;
	ListNode *oddlink=util.genListNodeList(odd_list);

	//ec->oddEvenList()

	return 0;
}

