#include<bits/stdc++.h>
#include<fstream>
#include<string>


using namespace std;


int main(){
    ifstream infile("input.txt");

    string s;
    int total = 0;
    unordered_map<string,string> nums = {{"one","1"},{"two","2"},
                                        {"three","3"},{"four","4"},
                                        {"five","5"},{"six","6"},
                                        {"seven","7"},{"eight","8"},
                                        {"nine","9"}};
    while(infile >> s){
        int i = 0;
        int n = s.size();
        int j = n;
        string digit = "";
        bool found = false;

        for(;i < n ; i++){
            if(found){
                break;
            }

            if(s[i] >= '0' && s[i] <= '9') {
                digit += s[i];
                break;
            }else{
                for (int k = 3; k <= 5; k++) {
                  if (found) {
                    break;
                  }
                  string str = s.substr(i, k);
                  if (nums.find(str) != nums.end()) {
                    digit += nums[str];
                    found = true;
                    break;
                  }
                }
            }
        }


        found = false;

        for( ; j >= 0 ; j--){
            if(found){
                break;
            }
            if(s[j] >= '1' && s[j] <= '9') {
                digit += s[j];
                break;
            }else{
                for (int k = 3; k <= 5; k++) {
                  if (found) {
                    break;
                  }
                  if (j - (k - 1) >= 0) {
                    string str = s.substr(j - (k -1), k);
                    if (nums.find(str) != nums.end()) {
                      digit += nums[str];
                      found = true;
                      break;
                    }
                  }
                }
            }
        }


        total += stoi(digit);
    }

    cout << total << "\n";

    return 0;
}
