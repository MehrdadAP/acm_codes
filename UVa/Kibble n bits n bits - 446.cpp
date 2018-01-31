//AC Code


#include <iostream>


#include <string>
#include <cstring>
#include <string.h>

using namespace std;

int string2int(char ch);

int main ()
{
    int n,t,u,flag,y,n1,n2,len,sum;
    char ch[20],ch1[20],ch2[20];
    int b1[13]={0},b2[13]={0};
    char sign;
    cin>>n;
//    cin>>y;
    while (n)
    {
          cin>>ch1>>sign>>ch2;
          for (int i=0;i<13;i++)
          {    
              b1[i]=0;
              b2[i]=0;
          }
          if (sign=='+')
             flag=1;
          else 
               flag=2;
          
          len=strlen(ch1)-1;
          t=1;
          n1=0;
          while (len>=0)
          {
                n1+=string2int(ch1[len])*t;
                t=t*16;
                len--;              
          }

          len=strlen(ch2)-1;
          t=1;
          n2=0;
          
          while (len>=0)
          {
                n2+=string2int(ch2[len])*t;
                t=t*16;
                len--;              
          }
          if (flag==1)
              sum=n1+n2;
          else 
               sum=n1-n2;
          ///dec 2 bin
          for (int i=12;n1>0;i--)
          {
              b1[i]=n1%2;
              n1=n1/2;
          }
          
          //print b1
          for (int i=0;i<13;i++)
              cout<<b1[i];
          
          ///flag
          if (flag==1)
             cout<<" + ";
          else  
              cout<<" - ";
          
              
          for (int i=12;n2>0;i--)
          {
              b2[i]=n2%2;
              n2=n2/2;
          }
          ///print b2
          for (int i=0;i<13;i++)
              cout<<b2[i];
          cout<<" = "<<sum<<endl;    
          n--;
    }
    
    //system("pause");
    return 0;
}

int string2int(char ch)
{
     switch (ch)
     {
            case 'A':
                 return 10;break;
            case 'B':
                 return 11;break;
            case 'C':
                 return 12;break;
            case 'D':
                 return 13;break;     
            case 'E':
                 return 14;break;
            case 'F':
                 return 15;break;          
            default :
                 return ch-'0';break;
                    
     }
 }