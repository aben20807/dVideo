#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>
using namespace std;
int main()
{
    ifstream in("ss.in",ios::in);
    if(!in)
    {
        cerr<<"Failed opening the input file \"s.in\".";
        exit(1);
    }
    string ss;
    while(getline(in,ss))
    {
        int count=0;
        for(int i=0;i<ss.size();i++)
        {
            if((ss[i]>='a'&&ss[i]<='z')||(ss[i]>='A'&&ss[i]<='Z')||(ss[i]>='0'&&ss[i]<='9'))
            {
                count++;
            }
            else
            {
                if(count!=0)
                {
                    cout<<count<<" ";
                    count=0;
                }
            }
        }
        cout<<endl;
        //cout<<count<<endl;
        //cout<<ss<<endl;
    }
    in.close();
    return 0;
}
