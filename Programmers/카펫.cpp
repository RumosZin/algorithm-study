#include <string>
#include <vector>

using namespace std;

// 2:46 : 다른 사람의 풀이 참고...

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int x = 3;
    int y = (brown - 2) / 2;
    
    while(1) {
        if((x - 2) * (y - 2) == yellow) break;
        x++; y--;
    }
    
    answer.push_back(y); answer.push_back(x); 
    return answer;
}