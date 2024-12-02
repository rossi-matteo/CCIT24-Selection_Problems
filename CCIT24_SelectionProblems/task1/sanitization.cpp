#include <stdio.h>
#include <iostream>
#include <vector>
#include <array>
#include <string.h>

using namespace std;

vector<string> sanitize(vector<string> words, vector<string> banned){
    char word[21];
    char ban[21];

    vector<string> answers;
    for( int i = 0; i < words.size(); i++){
        bool found = false;
        for(int j = 0; j < banned.size(); j++){

            strcpy(word, words[i].c_str());
            strcpy(ban, banned[j].c_str());
            
            char* ptr = strstr( word, ban);
            if( ptr != NULL){
                found = true;
                answers.push_back("BANNED");
                break;
            }
                
        }
        if(!found)
            answers.push_back("SAFE");
    }

    return answers;
}

int main()
{

    // freopen("input.txt", "r", stdin); // DECOMMENTA QUA SE VUOI LEGGERE DA FILE
    // freopen("output.txt", "w", stdout); // DECOMMENTA QUA SE VUOI SCRIVERE DA FILE

    int N, M;
    vector<string> words, banned, answers;
    cin >> N >> M;

    for(int i = 0; i < M; i++){
        string s;
        cin >> s;
        banned.push_back(s);
    }

    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        words.push_back(s);
    }

    answers = sanitize(words, banned);

    for(auto s : answers){
        cout << s << endl;
    }

    return 0;
}