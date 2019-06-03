#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<char>vec;
	int T; cin >> T;
	string s;
	getline(cin,s);
	while(T--){
		bool pos = true;
		getline(cin,s);
		vec.clear();
       if(s == ""){
       	cout << "Yes" << endl;
       	continue;
       }
		for(int i = 0 ; i < s.size(); i++){
            
			if(s[i] != '(' && s[i] != '[' && s[i] != ')' && s[i] != ']'){
				pos = false;
				break;
			}
			if(s[i] == '(' || s[i] == '['){
				vec.push_back(s[i]);
			}else if(vec.empty())pos=false;
			else if(s[i] == ')' || s[i] == ']'){
				if((s[i] == ')' && vec.back() == '(') || (s[i] == ']' && vec.back() == '[')){
					vec.pop_back();
				}else{
				pos = false;
				break;
				}
			}
			
		}
		if(!pos || !vec.empty()) cout << "No"<< endl;
		else
         cout << "Yes"<< endl;
         s.clear();
	}
	
} 
