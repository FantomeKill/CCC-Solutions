//
// Created by trist on 2022-12-23.
//

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(string str, string token){
    vector<string>result;
    while(str.size()){
        int index = str.find(token);
        if(index!=string::npos){
            result.push_back(str.substr(0,index));
            str = str.substr(index+token.size());
            if(str.size()==0)result.push_back(str);
        }else{
            result.push_back(str);
            str = "";
        }
    }
    return result;
}

int main(){
    int t;
    cin >> t;
    vector<string> l;
    string tmp = "test";
    for (int i = 0; i<=t;i++){
        getline(cin, tmp);
        if (tmp != ""){
            l.push_back(tmp);

        }}
    for (auto i:l){
        vector<string> item = split(i, " ");
        string value = item[1];
        stringstream intString(item[0]);
        int item0 = 0;
        intString >> item0;
        for (int i =0;i<item0;i++){
            cout << value;
        }
        cout << endl;
    }
}