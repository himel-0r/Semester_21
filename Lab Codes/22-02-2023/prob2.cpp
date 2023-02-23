#include "stacks.hpp"

int main()
{
    freopen("in2.txt", "r", stdin);
    freopen("out2.txt", "w", stdout);

    vector<int> pushed, popped;

    int n1;
    cin >> n1;

    for (int i = 0; i < n1; i++)
    {
        int x;
        cin >> x;
        pushed.push_back(x);
    }

    int n2;
    cin >> n2;

    for (int i = 0; i < n2; i++)
    {
        int x;
        cin >> x;
        popped.push_back(x);
    }

    Stack st;

    int pu = 0, po = 0;

    for (; pu < n1; pu++)
    {
        st.push(pushed[pu]);

        while (popped[po] == st.peek() && po < n2)
        {
            st.pop();
            po++;

            // cout << "pop disp ";
            // st.display();

            if (popped[po] != st.peek())
                po--;
        }
    }
    po++;

    // cout << "out of 1st loop\n";
    // st.display();

    for (; po < n2; po++)
    {
        if (popped[po] != st.peek())
        {
            cout << "False\n";
            return 0;
        }

        st.pop();
    }

    // cout << "last ";
    // st.display();

    cout << (st.empty() ? "True\n" : "False\n");
}