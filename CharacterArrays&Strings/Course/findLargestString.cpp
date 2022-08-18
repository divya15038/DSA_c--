// find largest string: We are required to input n number of strings and find the largest string out of all of them.
//Time Complexity: O(n*length of largest string)
#include<iostream>
#include<cstring>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.get(); //to consume the newline after taking input

    char sentence[1000], largestString[1000];
    int largestLength = 0;
    while(n--){
        cin.getline(sentence, 1000);
        //cout << sentence << endl;
        int currLen = strlen(sentence);
        if(currLen > largestLength){
            largestLength = currLen;
            strcpy(largestString, sentence);
        }
    }

    cout <<  "Largest string:" << largestString;
    return 0;
}