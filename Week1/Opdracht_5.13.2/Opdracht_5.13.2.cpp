#include <iostream>
#include <string>
#include <vector>

using namespace std;

string voeg_samen(const vector<string>& v) {
    string resultaat("");
    for (auto pos = v.begin(); pos != v.end(); ++pos) {
        if (pos != v.begin())
            resultaat += "-";
        resultaat += *pos;
    }
    return resultaat;
}

int main()
{
    string arr[]{ "aap", "beer", "cobra" };
    vector<string> vs(arr, arr + 3);
    cout << voeg_samen(vs) << ". ";
}
