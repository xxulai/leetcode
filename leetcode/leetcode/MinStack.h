#include "stdafx.h"

class MinStack {
private:
    vector<int> data;
    vector<int> minarray;

public:
    void push(int x) {
        data.push_back(x);
		if(minarray.size()!=0) {
			if(x<=minarray.at(minarray.size()-1)) minarray.push_back(x); 
			/*must be <= consider 45, 45, 46 with following move
			ms->top();
			ms->pop();
			ms->getMin();
			ms->pop();
			ms->getMin();
			ms->pop();*/
		} else { minarray.push_back(x); }
    }

    void pop() {
		if(data.size()==0) return;
        if(data.at(data.size()-1)==minarray.at(minarray.size()-1)) minarray.pop_back();
        data.pop_back();
    }

    int top() {
		if(data.size()==0) return 0;
        return data.back();
    }

    int getMin() {
		if(minarray.size()==0) return 0;
        return minarray.at(minarray.size()-1);
    }
};