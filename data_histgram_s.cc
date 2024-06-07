#include<iostream>
#include<string>
#include<vector>
#include<cctype>
#include<stack>

using namespace std;
//'a' = 97
int main(){
    bool flag = false;
    long long int d = 1, k = 1;
    vector<long long int> s(26, 0);
    stack<int> sk;
    string n;
    cin >> n;
    for(int i = 0; i < n.size(); i++){
        cout << "first" << d << endl;
        if(isdigit(static_cast<unsigned char>(n[i]))){
            if(flag == true){
                d *= 10;
                d += n[i] - '0';
                cout << "dd" << d << endl;
            }else{
                d = n[i] - '0';
                flag = true;
            }
        }else if(n[i] == '('){
            cout << d << "(" << endl;
            sk.push(d);
            k *= d;
            d = 1;
            flag = false;

        }else if(n[i] == ')'){
            k /= sk.top();
            sk.pop();
            flag = false;

        }else{
            s[n[i] - 97] += d * k;
            d = 1;
            flag = false;
        }
    }
    int aaa;
    for(int i = 0; i < 26; i++){
        aaa = i + 97;
            cout << (char)aaa << " " << s[i] << endl;
        }

        return 0;
}