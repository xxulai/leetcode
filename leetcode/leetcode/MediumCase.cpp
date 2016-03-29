#include "stdafx.h"
#include "MediumCase.h"
#include "DataStructure.h"

static void getPath(TreeNode *leaf, vector<int> &list, vector<vector<int>> &retlist){

	if(leaf->left==nullptr && leaf->right==nullptr) {
		list.push_back(leaf->val);
		retlist.push_back(list);
	}

	list.push_back(leaf->val);

	if(leaf->left!=nullptr){
		getPath(leaf->left, list, retlist);
	}

	if(leaf->right!=nullptr){
		getPath(leaf->right, list, retlist);
	}

	list.pop_back();
}

vector<vector<int>> MediumCase::pathSumII(TreeNode *root, int sum){
	vector<vector<int>> ret;
	vector<int> list;

	getPath(root, list, ret);

	return ret;
}

int MediumCase::minimumTotal(vector<vector<int> > &triangle){
	int ret;



	return ret;
}

ListNode *MediumCase::deleteDuplicatesII(ListNode *head) {

	unordered_map<int, int> mp;
    ListNode* p1=head;
	ListNode* p2=head;
        
    if(p1==NULL) return NULL;
	
	p2=p1->next;
	mp.insert(pair<int, int>(p1->val, 1));

    while(p2!=NULL){
        if(mp.count(p2->val)) 
		{
		    mp[p2->val]+=1;
			if(p2->next==NULL) p1->next=NULL;
			else {
			   p1->next=p2->next;
			   p2=p1->next;
			   continue;
			}
		}
        else mp.insert(pair<int, int>(p2->val, 1));
            
        p1=p1->next;
		p2=p2->next;
    }
        
    while(head != NULL && mp[head->val]!=1){
        head=head->next;
    }
        
    if(head==NULL) return head;
       
    p1=head;
    p2=p1->next;
        
    while(p2!=NULL){
        if(mp[p2->val]>1){
            p1->next=p2->next;
            p2=p1->next;
        } else {
            p1=p1->next;
            p2=p2->next;
        }
    }
        
    return head;
}

int MediumCase::rangeBitwiseAndSample(int m, int n) {
        while(n>m){
            n=n&(n-1);
        }
        return m&n;
}

int MediumCase::rangeBitwiseAnd(int m, int n){
	int intret=0x7fffffff;

	int step=0;
	int bitwise=4;    //4 bit per step
	int lowbound=-1;
	int highbound=-1;

	vector<int> flagvec;
	

	for(int i=1; i<8; i++){
		int buf=0x7fffffff-0x10000000*(i-1);
		for(int i=1; i<8; i++){
				buf=(buf>>(i*bitwise))*(int)pow(2.0, bitwise*(i));
				flagvec.push_back(buf);
		}
	}
	for(int i=(flagvec.size()-1); i>=0; i--){
		if(m<=flagvec.at(i)){
			lowbound=i; 
			break;
		}
	}
	for(int i=0; i<flagvec.size(); i++){
		if(n>=flagvec.at(i)){
			highbound=i; 
		}
	}

	

	//m<=n
	if(highbound==-1 || lowbound==-1){
		//no high bound find, both right
		//no low bound find, both left
		step=0;
	}else {
		int tvalue=flagvec.at(lowbound);
		int mod=tvalue%16;
		while(mod==0){
			step++;
			tvalue=tvalue/16;
			mod=tvalue%16;
		}
	}

	for(int i=m>>(step*bitwise); i<=n>>(step*bitwise); i++){
		intret&=i;
		if(intret==0 || i==0x7fffffff) break;
	}
	return intret;
}

string MediumCase::fractionToDecimal(int numerator, int denominator){
		if(numerator==0) return "0";  
        string result;  
        if(numerator<0 ^ denominator<0 ) result+='-';   
        //abs INT_MIN  will cause overflow so use long long int
        long long int n=numerator,d=denominator;  
        n=abs(n);
		d=abs(d);                
          
        result+=to_string(n/d);  //div part
        long long int modvalue=n%d;     //mod part 
        if(modvalue==0) return result;  
        else result+='.';  

        unordered_map<int,int> map;  
        while(modvalue){  

            if(map.find(modvalue)!=map.end()){  
                result.insert(map[modvalue],1,'(');   
                 result+=')';  
                break;  
            }  
            map[modvalue]=result.size();    
  
            modvalue*=10;  
            result+=to_string(modvalue/d);  
            modvalue=modvalue%d;  
        }  
        return result;  
}

vector<vector<int> > MediumCase::threeSum(vector<int> &num){
		int index1=0;
        int index2=1;
        vector<vector<int> > retvec;
        vector<int> bufvec;
		map<vector<int>, int> mp;
        
        if(num.size()<3) return retvec;
        
        sort(num.begin(), num.end());
        
		while(index2!=num.size()-1){
			while(index2<num.size()){
				for(int i=index2+1; i<num.size(); i++){
					/*if((i+1)!=num.size()){
						//not last element
						if(num.at(i)==num.at(i+1)) {
							index2++;
							continue; //skip same element
						}
					}*/
					if((num.at(index1)+num.at(index2)+num.at(i))==0){
						bufvec.push_back(num.at(index1));
						bufvec.push_back(num.at(index2));
						bufvec.push_back(num.at(i));
						if(mp.find(bufvec)==mp.end()){
							mp.insert(pair<vector<int>, int>(bufvec, 0));
						}
						bufvec.clear();
					}
				}
				index2++;
			}
			index1++;
			index2=index1+1;
		}

		for(map<vector<int>, int>::iterator it=mp.begin(); it!=mp.end(); it++){
			retvec.push_back(it->first);
		}

		
        
        return retvec;
}


 void MediumCase::reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL) return;
        
		ListNode *reversehead=NULL;
		ListNode *reversecur=NULL;
        ListNode *cur=head;
        ListNode *p=head;
		ListNode *half=head->next;
        vector<ListNode*> vec;
        vector<ListNode*> second;
        
        int length=1;

		//revert link list
        while(p!=NULL){
            vec.push_back(p);
            p=p->next;
        }

		length=vec.size();
		for(int i=0; i<length; i++){
			if(reversecur==NULL){
				reversehead=vec.back();
				reversecur=reversehead;
			} else{
				reversecur->next=vec.back();
				reversecur=reversecur->next;
			}
			vec.pop_back();
		}
		reversecur->next=NULL;
		reversecur=reversehead;
		cur=head;
		p=cur->next;
        
        for(int i=0; i<length/2; i++){
            cur->next=reversecur;
			reversecur->next=p;
			cur=p;
			p=cur->next;
			reversecur=reversecur->next;
        }

		if(length%2!=0){
			cur->next=NULL;
		} else{
			cur=NULL;
		}
}


bool MediumCase::containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t){
	unordered_map<int, int> mp;   //value, index
        
    for(int i=0; i<nums.size(); i++){
			for(int j=abs(nums[i]-t); j<nums[i]; j++){
				if(mp.find(nums[i])!=mp.end() && abs(nums[i]-nums[mp[nums[i]]])<=t && abs(mp[nums[i]]-i)<=k)
					return true;
				else
					mp[j]=i;
			}
			for(int j=abs(nums[i]+t); j>nums[i]; j--){
				if(mp.find(nums[i])!=mp.end() && abs(nums[i]-nums[mp[nums[i]]])<=t && abs(mp[nums[i]]-i)<=k)
					return true;
				else
					mp[j]=i;
			}
	}
        
    return false;

}

int MediumCase::singleNumber(vector<int>& nums) {
        
        unordered_map<int, bool> mp;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(mp.count(nums.at(i)))
            {
                mp[nums.at(i)]=true;
                continue;
            }
            else
            {
                mp.insert(pair<int, int>(nums.at(i), false));
            }
        }
        
        for(unordered_map<int, bool>::iterator it=mp.begin(); it!=mp.end(); it++)
        {
            if(!it->second)  return it->first;
            
        }
        return -1;
}

vector<int> MediumCase::singleNumberIII(vector<int>& nums) {
         unordered_map<int, bool> mp;
         vector<int> ret;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(mp.count(nums.at(i)))
            {
                mp[nums.at(i)]=true;
                continue;
            }
            else
            {
                mp.insert(pair<int, int>(nums.at(i), false));
            }
        }
        
        for(unordered_map<int, bool>::iterator it=mp.begin(); it!=mp.end(); it++)
        {
            if(!it->second)
            {
                ret.push_back(it->first);
            }
            
        }
        return ret;
}

vector<int> MediumCase::productExceptSelf(vector<int>& nums) {
        vector<int> ret;
		        
        int lproduct=1;
		for(int i=0; i<nums.size(); i++)
		{
			if(i!=0) lproduct=lproduct*nums.at(i-1);
			ret.push_back(lproduct);
		}

		int rproduct=1;
		for(int i=(nums.size()-1); i>=0; i--)
		{
			if(i!=(nums.size()-1)) rproduct=rproduct*nums.at(i+1);
			ret.at(i)=ret.at(i)*rproduct;
		}

        return ret;
}

int MediumCase::bulbSwitch(int n) {
        return ((int)sqrtf(n));
}

int MediumCase::missingNumber(vector<int>& nums) {
        int x = 0;
        for (int i = 0; i <= nums.size(); i++) x^= i;
        for (int i=0; i<nums.size(); i++) x ^= nums.at(i);
        return x;
}

int MediumCase::singleNumberII(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int step=3;
        
		if(nums.size()<step) return nums.at(0);

        for(int i=0; i<nums.size(); i+=step)
        {
			if((nums.size()-i)<step) return nums.at(i);

            if(nums.at(i)*step==(nums.at(i)+nums.at(i+1)+nums.at(i+2))) continue;
            else return nums.at(i)^nums.at(i+1)^nums.at(i+2);
        }
        return nums.at(0);
}

bool MediumCase::wordBreak(string s, unordered_set<string>& wordDict)
{
	unordered_map<string, bool> mp;
	for(unordered_set<string>::iterator it=wordDict.begin(); it!=wordDict.end(); it++)
	{
		
	}
	return true;
}

string MediumCase::removeDuplicateLetters(string s) {

	int count[26];
	string strbuf=s;
	int pos = 0;  

	for(int i=0; i<26; i++) count[i]=0;
    for(int i=0; i<s.length(); i++) count[s.at(i) - 'a']++;  
    
	for(int i=0; i<26; i++)
	{
		if(count[i]<=1) continue;
		pos=strbuf.find('a'+i);
		string ss=strbuf.substr(pos+1);
		ss=util.replaceAll(ss, 'a'+i);
		strbuf=strbuf.substr(0, pos+1)+ss;
	}
	return strbuf;
	/*for(int i=0; i<s.length(); i++) {  
        if(s.at(i)< s.at(pos)) pos = i;  
        if(--count[s.at(i) - 'a'] == 0) break;  
	}  
    return s.length() == 0? "" : s.at(pos) + removeDuplicateLetters(util.replaceAll(s.substr(pos+1), s.at(pos)));  */
}

void MediumCase::reverseWords(string &s)
{
	vector<string> vec;
	string buf;
	for(string::iterator it=s.begin(); it!=s.end(); it++)
	{
		if(*it!=' ')
		{
			buf+=*it;
		}
		else if(buf!="")
		{
			vec.push_back(buf);
			buf="";
		}
	}

	if(buf!="") vec.push_back(buf);  //last word without space

	s="";
	int count=vec.size();
	for(int i=0; i<count; i++)
	{
		s+=vec.back()+" ";
		vec.pop_back();
	}
	s=s.substr(0, s.length()-1);
}

int MediumCase::divide(int dividend, int divisor) {
        int buf=dividend;
        int count=0;
        while(abs(buf)>=abs(divisor))
        {
            buf=buf+~(divisor-1);
            count++;
        }
        if((dividend>0 && divisor<0) || (dividend<0 && divisor>0)) 
		{
			count=~(count-1);
		}
        
        return count;
}

int MediumCase::searchInsert(vector<int>& nums, int target) {
        
        for(int i=0; i<nums.size(); i++)
        {
            if(nums.at(i)==target) return i;
        }
        
        if(target<nums.at(0)) return 0;
        if(target>nums.at(nums.size()-1)) return nums.size();
        
        for(int i=0; i<nums.size(); i++)
        {
            if(nums.at(i)<target && nums.at(i+1)>target) return i+1;
        }
        return 0;
}

vector<int> MediumCase::countBits(int num) {
        vector<int> ret;
        ret.push_back(0);
        for(int i=1; i<=num; i++)
        {
            int buf=i;
            int count=0;
            while(buf!=0)
            {
                if(buf%2!=0) count++;
                buf=buf/2;
            }
            ret.push_back(count);
        }
        
        return ret;
}

bool MediumCase::hasCycle(ListNode *head) {
        ListNode *p1=head;
        ListNode *runner=head;
        
        if(p1==NULL || p1->next==NULL) return false;
        
        p1=p1->next;
        runner=runner->next->next;
        
        while(p1!=runner && runner!=NULL && runner->next!=NULL)
        {
            p1=p1->next;
            runner=runner->next->next;
        }
        
        if(p1==runner) return true;
        
        return false;
 }

