#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char s[256], voc[] = "aeiou";
    cin.get(s, 255);
    for(int i=0; i<strlen(s); i++)
        if(strchr(voc, s[i]) != NULL)
            s[i] = toupper(s[i]);
    cout<<s;
}