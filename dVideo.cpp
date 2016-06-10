#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;
int main()
{
    ifstream in("ss.in",ios::in);
    if(!in)
    {
        cerr << "Failed opening the input the file \"s.in\".";
        exit(1);
    }
    ofstream out("catch.out",ios::out);
    if(!out)
    {
        cerr << "Failed to output into the file \"catch.txt\".";
        exit(1);
    }
    string ss;
    while(getline(in,ss))
    {
        int wordCount = 0;
        for(int i=0;i<ss.size();i++)
        {
            if((ss[i] >= 'a' && ss[i] <= 'z')||(ss[i] >= 'A' && ss[i] <= 'Z')||(ss[i] >= '0' && ss[i] <= '9'))
            {
                wordCount++;
            }
            else
            {//遇到符號、空格或換行
                if(wordCount != 0)
                {//有計算到字母數，排除一直遇到符號就輸出0的情況
                    if(wordCount == 3 && ss[i-1] == '4' && ss[i-2] == 'p' && ss[i-3] == 'm')
                    {//找到mp4的關鍵字
                        //#define DEBUG_CATCH
                        #ifdef DEBUG_CATCH
                            cout<<"catch!!!!"<<endl<<ss<<endl;
                        #endif
                        int end = i,start;
                        for(int j=i;j>=0;j--)
                        {//得到網址開頭
                            if(ss[j] == '\'' )
                            {
                                //cout<<j<<" "<<end<<endl;
                                start = j;
                                break;
                            }
                        }
                        for(int j=start+1;ss[j] != '\'';j++)
                        {//不輸出前後的'
                            //cout<<ss[j];
                            out<<ss[j];
                        }
                        //cout<<endl;
                        out<<"\r\n";//windows換行
                    }
                    //#define DEBUG_WORD_LENGTH
                    #ifdef DEBUG_WORD_LENGTH
                        cout << wordCount << " ";
                    #endif
                    wordCount = 0; //每經一個單字就歸0
                }
            }
        }
        #ifdef DEBUG_WORD_LENGTH
            cout << endl;
        #endif
        //cout<<ss<<endl;
    }
    in.close();//關閉檔案
    out.close();
    return 0;
}
