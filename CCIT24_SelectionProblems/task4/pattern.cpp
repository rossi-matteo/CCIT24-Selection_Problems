#include <stdio.h>
#include <iostream>
#include <vector>
#include <array>
#include <cstring>

using namespace std;

int count_patterns(int N, int M, string alph, string s){
    int count = 0;
    int j = 0;
    
    for(int i = 0; i < s.length(); i++){
        bool covered = true;
        string pattern = s.substr(0,i+1);
        int max = i;
        for( j = 1; j < s.length() && covered; j++ ){
            if( strncmp( s.c_str()+j , (char*) pattern.c_str(), i+1) == 0){
                max = j+i; 
            }
            if( j > max)
                covered = false;
        }
        if( max != s.length()-1)
            covered = false;
        if(covered){
            //printf("%s\n", pattern.c_str());
            count++;
        }
    }

    return count;
}

int main()
{
    // freopen("input.txt", "r", stdin); // DECOMMENTA QUA SE VUOI LEGGERE DA FILE
    // freopen("output.txt", "w", stdout); // DECOMMENTA QUA SE VUOI SCRIVERE DA FILE
    int T;
    cin >> T;

    while(T--){
        int N, M;
        string alph, s;

        cin >> N >> M;
        cin >> alph >> s;
        cout << count_patterns(N, M, alph, s) << endl;
    }

    return 0;
}