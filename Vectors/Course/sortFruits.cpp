//sort fruits: A vector of pairs containing fruit name along with their prices is provided.Sort the vector according to names, if 'name' is
//provided as parameter. If 'price' is provided as parameter, sort according to price.
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
bool compare(pair<string, int> a, pair<string, int> b) {
    return a.second < b.second;
}

vector<pair<string, int>> sortFruits(vector<pair<string, int>> input, string param){
    for(auto x:param){
        x = tolower(x);
    }
    if(param == "price"){
        sort(input.begin(), input.end(), compare);
    } else {
        sort(input.begin(), input.end());
    }
    return input;
}

int main() {
    vector<pair<string, int>> fruits = {{"Mango", 100}, {"Guava", 70}, {"Grapes", 40}, {"Apple", 60}, {"Banana", 30}};

    string sortParam;
    cin >> sortParam;
    vector<pair<string, int>> ans = sortFruits(fruits, sortParam);
    for(int i=0; i<ans.size(); i++){
        cout << "(" << ans[i].first << "," << ans[i].second << ") "; 
    }
    return 0;
}