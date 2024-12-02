#include <stdio.h>
#include <iostream>
#include <vector>
#include <array>
#include <iterator>
#include <algorithm>

using namespace std;

int find_subsets(int N, int D, vector<int> S){
    sort(S.rbegin(), S.rend()); 
    vector<int> set_sizes;

    for(int i = 0; i < S.size(); i++){
        int j = i;
        int thresh_value = S[i] - D;
        while( S[j] >= thresh_value && j < S.size() ){
            j++;
        }
        set_sizes.push_back( j-i);
    }
    

    int max = 0;
    for(int i = 0; i < set_sizes.size()-1; i++){
        for(int j = i+set_sizes[i]; j < set_sizes.size(); j++){
            if( set_sizes[i]+set_sizes[j] > max )
                max = set_sizes[i]+set_sizes[j];
        }
    }

    return max;
}

int main(){

    // freopen("input.txt", "r", stdin); // DECOMMENTA QUA SE VUOI LEGGERE DA FILE
    // freopen("output.txt", "w", stdout); // DECOMMENTA QUA SE VUOI SCRIVERE DA FILE
    int T;
    cin >> T;

    while(T--){
        int N, D;
        vector<int> S;

        cin >> N >> D;
        
        for(int i = 0; i < N; i++){
            int x;
            cin >> x;
            S.push_back(x);
        }
        
        cout << find_subsets(N, D, S) << endl;
    }

    return 0;
}