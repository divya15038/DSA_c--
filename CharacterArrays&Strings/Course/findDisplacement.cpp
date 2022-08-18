//find displacement: Given a string containing directions, find the shortest path from origin to the destination.
//Time complexity: O(n)
#include<iostream>
#include<vector>
using namespace std;

vector<char> findDisplacement(string dir) {
    int x = 0, y = 0;
    vector<char> displacement;
    for(int i=0; i<dir.length() ; i++) {
        switch(dir[i]){
            case 'S':
                y--;
                break;
            case 'N':
                y++;
                break;
            case 'E':
                x++;
                break;
            case 'W':
                x--;
                break;
            default:
                cout << "Not a valid direction";
                break;
        }        
    }
    while(y!=0){
        if(y>0){
            displacement.push_back('N');
            y--;
        } else {
            displacement.push_back('S');
            y++;
        }
    }

    while(x!=0){
        if(x>0){
            displacement.push_back('E');
            x--;
        } else {
            displacement.push_back('W');
            x++;
        }
    }

    return displacement;
}

int main(){
    string distance = "SNNNEWE";
    vector<char> displacement = findDisplacement(distance);
    for(auto x: displacement){
        cout << x;
    }
    return 0;
}