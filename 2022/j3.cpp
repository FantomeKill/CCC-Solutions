//
// Created by trist on 2022-12-03.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    int start = 0;
    for (int i = 0; i < s.size(); ++i) {
        // check if the current character is a number
        if (isdigit(s[i])){
            // check if the next character is a letter
            if (isalpha(s[i+1]) || i == s.size()-1){
                string st = s.substr(start, i - start + 1);
//                cout << st << endl;
                string final = "";
                start = i+1;
                int tmp = 0;

                for (int i = 0; i < st.size(); ++i){
                    if (ispunct(st[i])){
                        final += st.substr(0, i);
                        tmp = i;
                    }
                }

                if (st.find('+') != string::npos){
                    final += " tighten ";
                } else if (st.find('-') != string::npos){
                    final += " loosen ";
                }

                final += st.substr(tmp+1);
                cout << final << endl;

                final = "";
                tmp = 0;
                st = "";

            }
        }
    }
}