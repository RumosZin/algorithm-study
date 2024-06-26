#include <iostream>

using namespace std;

int N, num, strike, ball;
bool answer[1001] = {true, };

string current_num;
int strike_count, ball_count, cnt = 0;
    
int main(){
    // input
    cin >> N;

    for(int i = 123; i <= 987; i++){ // 어느 두 숫자도 겹칠 수 없고, 세 자리 수ㄴ
        current_num = to_string(i);
        
        /**
         * 어느 두 숫자가 같으면 안 됨
        */
        if(current_num[0] == current_num[1] || current_num[1] == current_num[2] || current_num[0] == current_num[2]) answer[i] = false;

        /**
         * 0을 포함하는 경우 답이 될 수 없음
        */
        if(current_num[0] - '0'  == 0 || current_num[1] - '0'  == 0 || current_num[2] - '0' == 0) answer[i] = false; 
    }
    
    for(int i = 1; i <= N; i++){
        cin >> num >> strike >> ball;

        for(int i = 123; i <= 987; i++){
            strike_count = 0;
            ball_count = 0;
            
            if(answer[i]){ // 앞서 제외된 케이스가 아닌 것에 대해 수행
                string number = to_string(num);
                string current_case = to_string(i);
    
                for(int a = 0; a < 3; a++){
                    for(int b = 0; b < 3; b++){
                        if(a == b && number[a] == current_case[b]) strike_count++;
                        if(a != b && number[a] == current_case[b]) ball_count++;
                    }
                }
                
                if(strike_count != strike || ball_count != ball) answer[i] = false;
            }
        }
    }
    
    for(int i = 123; i <= 987; i++) {
        if(answer[i]) cnt++;
    }
    
    cout << cnt;
    
    return 0;
}