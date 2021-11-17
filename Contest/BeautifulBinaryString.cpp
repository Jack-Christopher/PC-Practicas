#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
int beautifulBinaryString(string b);

int main(){
    ofstream fout(getenv("OUTPUT_PATH"));
    string n_temp;
    getline(cin, n_temp);
    int n = stoi(ltrim(rtrim(n_temp)));
    string b;
    getline(cin, b);
    int result = beautifulBinaryString(b);
    fout << result << "\n";
    fout.close();
    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

int beautifulBinaryString(string b) {
    int result = 0;
    for (int i = 0; i < b.size(); ++i){
        if (b.substr(i, 3) == "010"){
            result++;
            i += 2; 
        }
    }    
    std::cout << result << endl;
    return result;
}