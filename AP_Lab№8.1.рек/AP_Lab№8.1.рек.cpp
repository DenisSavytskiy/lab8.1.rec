#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int Count(char* str, int i) {
    if (strlen(str) < 5) return 0;
    if (str[i + 4] != 0)
        if (str[i] == 'w' && str[i + 1] == 'h' && str[i + 2] == 'i' &&
            str[i + 3] == 'l' && str[i + 4] == 'e')
            return 1 + Count(str, i + 1);
        else
            return Count(str, i + 1);
    else
        return 0;
}

char* Change(char* dest, const char* str, char* t, int i) {
    if (str[i + 4] != 0) {
        if (str[i] == 'w' && str[i + 1] == 'h' && str[i + 2] == 'i' &&
            str[i + 3] == 'l' && str[i + 4] == 'e') {
            strcat_s(t, 4, "***");
            return Change(dest, str, t + 3, i + 5);
        }
        else {
            *t++ = str[i++];
            *t = '\0';
            return Change(dest, str, t, i);
        }
    }
    else {
        while (str[i] != 0) {
            *t++ = str[i++];
        }
        *t = '\0';
        return dest;
    }
}
int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);
    cout << "String contained " << Count(str, 0) << " groups of 'while'" << endl;
    char* dest1 = new char[151];
    dest1[0] = '\0';
    char* dest2;
    dest2 = Change(dest1, str, dest1, 0);
    cout << "Modified string (param) : " << dest1 << endl;
    cout << "Modified string (result): " << dest2 << endl;
    return 0;
}
