#include <string>
#include <vector>

using namespace std;

// 9:14
int total = 0;

void dfs(vector<int>& numbers, int& target, int sum, int idx) {
    if(idx == numbers.size() - 1) { 
        if(sum == target) total++;
        return; 
    }
    
    dfs(numbers, target, sum + numbers[idx + 1], idx + 1);
    dfs(numbers, target, sum - numbers[idx + 1], idx + 1);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    dfs(numbers, target, numbers[0], 0);
    dfs(numbers, target, -numbers[0], 0);
    answer = total;
    
    return answer;
}