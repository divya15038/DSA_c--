#include<bits/stdc++.h>
using namespace std;

int getMaxArea2(vector<int> hist){
	int n = hist.size();
	stack<int> s;
	s.push(-1);
	vector<int> leftSmall(n,-1), rightSmall(n,n);  
	int maxArea = hist[0];
	int i = 0;

	while(i<n){
		while(!s.empty() and s.top()!=-1 and hist[s.top()]>hist[i]){
			rightSmall[s.top()] = i;
			s.pop();
		}
		if(i>0 and hist[i] == hist[i-1]){
			leftSmall[i] = leftSmall[i-1];
		}
		else{
			leftSmall[i] = s.top();
		}
		s.push(i);
		i++;
	}
	for(int j=0; j<n; j++){
		maxArea = max(maxArea, hist[j] * (rightSmall[j] - leftSmall[j] - 1));
	}
	return maxArea;
}

//Time complexity: O(n)
int getMaxArea(vector<int> hist){
    int n = hist.size();
	stack<int> s;
	int i = 0;
	int maxArea = 0, currArea = 0;
	while(i<n){
		//if the height is greater than current bar, push index to the stack
		if(s.empty() || hist[s.top()]<=hist[i]){
			s.push(i++);
		}
		//monotonic stack increasing lengths of bars a upwards
		//i gives us the right index, that is the number of bars with length greater or equal to current bar
		//s.top() gives us the left index, that is index after which bars are greater or equal to current bar
		else{
			int top = s.top();
			s.pop();
			currArea = hist[top] * (s.empty()? i : (i-s.top()-1));
			if(currArea > maxArea){
				maxArea = currArea;
			}
		}
	}
	while(!s.empty()){
		int top = s.top();
		s.pop();
		int currArea = hist[top]*(s.empty()?i: i - s.top() - 1);

		if(currArea > maxArea){
			maxArea = currArea;
		}
	}
	return maxArea;
}

// Driver program to test above function
int main()           //{-1,-1,1, 1, 1, -1, 4 }
{					 //{0, 1, 2, 3, 4, 5, 6}
	vector<int> hist = {6, 2, 5, 4, 5, 1, 6};
	cout << "Maximum area is " << getMaxArea(hist) << endl;
	cout << "Maximum area is:" << getMaxArea2(hist);
	return 0;
}
