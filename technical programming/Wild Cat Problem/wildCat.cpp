#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;
const int MAX = 50;

int strmatch(const char pattern[], const char text[])
{
    int n = strlen(text);
    int m = strlen(pattern);
    int i = 0, j = 0, startIndex = -1, match = 0;

    while (i < n)
    {
        if (j < m && pattern[j] == text[i])
        {
            // Characters match or '?' in pattern matches any character.
            i++;
            j++;
        }
        else if (j < m && pattern[j] == '*')
        {
            // Wildcard character '*', mark the current position in the pattern
            // x and the text as a proper match.
            startIndex = j;
            match = i;
            j++;
        }
        else if (startIndex != -1)
        {
            // No match, but a previous wildcard was found. Backtrack to the
            // last '*' character position and try for a different match.
            j = startIndex + 1;
            match++;
            i = match;
        }
        else
        {
            // If none of the above cases comply, the pattern does not match.
            return false;
        }
    }

    // Consume any remaining '*' characters in the given pattern.
    while (j < m && pattern[j] == '*')
    {
        j++;
    }

    // If we have reached the end of both the pattern and the text, the pattern
    // matches the text.
    return j == m;
}
//====================================================================
// MAIN
//====================================================================
bool checkAuto(ifstream &fin, ifstream &res);
void checkManual(ifstream &fin, ifstream &res);

int main()
{
    char s[MAX] = "the*brown*fox", t[MAX] = "the brown fox fox";
    ifstream fin("wildCat.inp"), res("wildCat.out");

    cout << s << " " << t << " " << strmatch(s, t);
    // checkAuto(fin, res);
    // checkManual(fin, res);

    fin.close();
    res.close();
}
//====================================================================
// Phan chuong tr�nh cho cac ham check dap an
//====================================================================
bool checkAuto(ifstream &fin, ifstream &res)
{
    char s[MAX], t[MAX];

    int test, word, countTest = 0;
    bool ans, check, wrong = 0;
    fin >> test;
    fin.ignore();
    while (test--)
    {
        fin.getline(s, MAX);
        // cout << s << ": \n";
        fin >> word;
        fin.ignore();
        while (word--)
        {
            countTest++;
            fin.getline(t, MAX);
            res >> check;
            ans = strmatch(s, t);
            if (check != ans)
            {
                wrong = 1;
                cout << "wrong answer on test " << countTest << ":\n";
                cout << s << endl << t << endl;
                cout << "expected: " << check << endl;
                cout << "founded: " << ans << endl;
                cout << endl;
                return 0;
            }
        }
    }
    if (!wrong)
        cout << "AC ~" << endl;
    return 1;
}
void checkManual(ifstream &fin, ifstream &res)
{
    int test, amount;
    char s[MAX] = "app*", t[MAX] = "apple";
    fin >> test;
    fin.ignore();
    while (test--)
    {
        fin.getline(s, MAX);
        fin >> amount;
        fin.ignore();
        cout << s << ": \n";
        while (amount--)
        {
            fin.getline(t, MAX);
            cout << t << " " << strmatch(s, t) << endl;
        }
        cout << endl;
    }
}
