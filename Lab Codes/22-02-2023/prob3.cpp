#include "stacks.hpp"

int main()
{
    freopen("in3.txt", "r", stdin);
    freopen("out3.txt", "w", stdout);

    string s;
    Stack st;

    int num_of_lines;
    cin >> num_of_lines;

    for (int i = 0; i < num_of_lines; i++)
    {
        cin >> s;

        if (s[0] >= '0' && s[0] <= '9' || s.size() > 1)
        {
            st.push(stoi(s));
        }

        else
        {
            int b = st.pop();
            int a = st.pop();

            switch (s[0])
            {
            case '+':
            {
                st.push(a + b);
                break;
            }
            case '-':
            {
                st.push(a - b);
                break;
            }
            case '*':
            {
                st.push(a * b);
                break;
            }
            case '/':
            {
                st.push(a / b);
                break;
            }
            default:
                break;
            }
        }

        // cout << st.peek() << endl;
    }

    cout << st.pop() << endl;
}