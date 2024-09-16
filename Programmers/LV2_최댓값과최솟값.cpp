#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

// 4:00

string solution(string s) {
    string answer = "";
    string sub_str;
    vector<int> v;
    
    stringstream ss(s);
    
   while(getline(ss, sub_str, ' ')) {
       v.push_back(stoi(sub_str));
   }
    
    sort(v.begin(), v.end());
    
    answer += to_string(v[0]) + " " + to_string(v[v.size() -1]);
    
    return answer;
}