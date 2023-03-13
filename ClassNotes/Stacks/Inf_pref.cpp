#include<bits/stdc++.h>
using namespace std;

int main()
{
    // freopen ("input.txt", "r", stdin);
    freopen ("in_pre.txt", "w", stdout);

    string s = "(((1+2)*3)-8)";
    string t = "";

    stack<char> st;

    for (int i=0; i<s.size(); i++) {
        char x = s[i];

        if (x == '(')
            st.push(x);
        else if (x == '+' || x == '-' || x == '*' || x == '/') {
            if (x == '*' || x == '/') {
                while (st.top() == '*' || st.top()=='/') {
                    t = st.top() + t;
                    st.pop();
                }
                st.push(x);
            }
            else 
                st.push(x);
        }
        else if (x>='0' && x<='9')
            t += x;
        else if (x == ')') {
            while (st.top() != '(') {
                t = st.top() + t;
                st.pop();
            }
            st.pop();
        }
    }

    while (!st.empty()) {
        cout << st.top() << endl;
        t += st.top();
        st.pop();
    }

    cout << t << endl;
}