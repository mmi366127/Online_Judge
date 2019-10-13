#include <bits/stdc++.h>

using namespace std;

string primality(long long n) {
    if(n < 2) return "Not prime";
    for(long long v = 2; v * v <= n; v++) {
        if(n % v == 0) return "Not prime";
    }
    return "Prime";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int p_itr = 0; p_itr < p; p_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string result = primality(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
