//Knuth–Morris–Pratt algorithm
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int help[100000]={0}, i=1, j=0;
    string st,pattern;
    cin>>st>>pattern;
    //preprocessing of helper array
    while(i < pattern.size()){
        if(pattern[i] == pattern[j])
            help[i++] = ++j;
        else{
            if(j != 0) j = help[j-1];
            else help[i++] = 0;
        }
    }
    i = 0, j = 0;
    //determining whether the string is found in pattern or not.
    while(i < st.size() && j < pattern.size()){
        if(st[i] == pattern[j])
            i++, ++j;
        else{
            if(j != 0) j = help[j-1];
            else i++;
        }
    }
    if(j == pattern.size()) cout<<"string st contains the pattern"<<endl;
    else cout<<"string st do not contains the pattern"<<endl;
    return 0;
}
