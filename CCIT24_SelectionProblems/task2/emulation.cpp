#include <stdio.h>
#include <iostream>
#include <vector>
#include <array>
#include <cstring>

using namespace std;

pair< string, int> lb_pos;
vector < pair< string, int> > mapping;


long long emulate(vector<string> code){
    long long a = 0,b = 0,c = 0,d = 0,e = 0, f = 0;
    int new_line = 0;
    for(int i = 0; i < code.size(); i++){

        if(strstr(code[i].c_str(),"add ")){
            char tmp = code[i][4];
            long long number = atoll(code[i].substr(6, code[i].length()-6).c_str() );
            switch( tmp){
                case 'a':
                    a+=number;
                    break;
                case 'b':
                    b+=number;
                    break;
                case 'c':
                    c+=number;
                    break;
                case 'd':
                    d+=number;
                    break;
                case 'e':
                    e+=number;
                    break;
                case 'f':
                    f+=number;
                    break;
            }
        }else if(strstr(code[i].c_str(),"sub ")){
            char tmp = code[i][4];
            long long number = atoll(code[i].substr(6, code[i].length()-6).c_str() );
            switch( tmp){
                case 'a':
                    a-=number;
                    break;
                case 'b':
                    b-=number;
                    break;
                case 'c':
                    c-=number;
                    break;
                case 'd':
                    d-=number;
                    break;
                case 'e':
                    e-=number;
                    break;
                case 'f':
                    f-=number;
                    break;
            }
        }else if(strstr(code[i].c_str(),"mul ")){
            char tmp = code[i][4];
            long long number = atoll(code[i].substr(6, code[i].length()-6).c_str() );
            switch( tmp){
                case 'a':
                    a*=number;
                    break;
                case 'b':
                    b*=number;
                    break;
                case 'c':
                    c*=number;
                    break;
                case 'd':
                    d*=number;
                    break;
                case 'e':
                    e*=number;
                    break;
                case 'f':
                    f*=number;
                    break;
            }

        }else if(strstr(code[i].c_str(),"jmp ")){
            bool updated = false;
            char* ptr = strtok( (char*) code[i].c_str(), " ");
            vector<char*> v;
            while(ptr!=nullptr)
            {
                v.push_back(ptr);
                ptr = strtok(nullptr," ");
            }
            char var = v[1][0];
            long long number = atoll(v[2]);
            char* label = v[3];

            switch( var){
                case 'a':
                    if(a == number){
                        for(int i = 0; i < mapping.size(); i++){
                            if( strncmp( label , (char* )mapping[i].first.c_str(), 2) == 0 ){
                                new_line = mapping[i].second;
                                updated = true;
                                break;
                            }
                        }
                    }
                    break;
                case 'b':
                    if(b == number){
                        for(int i = 0; i < mapping.size(); i++){
                            if( strncmp( label , (char* )mapping[i].first.c_str(), 2) == 0 ){
                                new_line = mapping[i].second;
                                updated = true;
                                break;
                            }
                        }
                    }
                    break;
                case 'c':
                    if(c == number){
                        for(int i = 0; i < mapping.size(); i++){
                            if( strncmp( label , (char* )mapping[i].first.c_str(), 2) == 0 ){
                                new_line = mapping[i].second;
                                updated = true;
                                break;
                            }
                        }
                    }
                    break;
                case 'd':
                    if(d == number){
                        for(int i = 0; i < mapping.size(); i++){
                            if( strncmp( label , (char* )mapping[i].first.c_str(), 2) == 0 ){
                                new_line = mapping[i].second;
                                updated = true;
                                break;
                            }
                        }
                    }
                    break;
                case 'e':
                    if(e == number){
                        for(int i = 0; i < mapping.size(); i++){
                            if( strncmp( label , (char* )mapping[i].first.c_str(), 2) == 0 ){
                                new_line = mapping[i].second;
                                updated = true;
                                break;
                            }
                        }
                    }
                    break;
                case 'f':
                    if(f == number){
                        for(int i = 0; i < mapping.size(); i++){
                            if( strncmp( label , (char* )mapping[i].first.c_str(), 2) == 0 ){
                                new_line = mapping[i].second;
                                updated = true;
                                break;
                            }
                        }
                    }
                    break;
            }
            if(updated)
                i = new_line;
        }

    }


    return a+b+c+d+e+f;
}




int main()
{

    // freopen("input.txt", "r", stdin); // DECOMMENTA QUA SE VUOI LEGGERE DA FILE
    // freopen("output.txt", "w", stdout); // DECOMMENTA QUA SE VUOI SCRIVERE DA FILE

    int N;
    vector<string> code;
    string s;
    cin >> N;
    getline(cin, s);
    string label_name = "";

    for(int i = 0; i < N; i++){
        getline(cin, s);
        if( strstr(s.c_str(), "lab ") != NULL){
            label_name = s.substr(4,2);
            lb_pos = {label_name, i};
            mapping.push_back(lb_pos);
        }
        code.push_back(s);
    }

    cout << emulate(code) << endl;

    return 0;
}