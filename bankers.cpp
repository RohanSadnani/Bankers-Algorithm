#include<iostream>
#include <cstdlib>
#include<conio.h>
#include <cstring>
using namespace std;

int main()
{
int p,r;
int allocation[5][5];
int maximum[5][5];
int available[5];
int need[5][5];



cout<<"enter no. of process=";
cin>>p;
cout<<"enter no. of resources=";
cin>>r;
cout<<"enter"<<p*r<<"elements of matrix\allocation"<<endl;
for(int i=0;i<p;i++)
        {
            for(int j=0;j<r;j++)
            {
                cin>>allocation[i][j];
            }
        }
cout<<"enter"<<p*r<<"elements of matrix/maximum"<<endl;
                for(int i=0;i<p;i++)
                {
                    for(int j=0;j<r;j++)
                    {
                        cin>> maximum[i][j];
                    }
                }
cout<<"enter"<<p*r<<"elements of matrix\availabel"<<endl;
for(int i=0;i<r;i++)
        {
           cin>> available[i];
        }
        for(int i=0;i<p;i++)
        {
            for(int j=0;j<r;j++)
            {
                need[i][j] = maximum[i][j] - allocation[i][j];
            }
        }

int done[p] ;    //to check which processes are complete.
int undone[p] ;
int counter = 0;    //to check which processes are incomplete.
        for(int i=0;i<p;i++)
        {
            done[i] = 0;
            undone[i] = 1;
        }
        while(counter < p)
        {
            for(int i=0;i<p;i++)
            {
                for(int j=0;j<r;j++)
                {
                    if(undone[i]!=0)
                    {
                        if(need[i][j] > available[j])
                        {
                            cout<<"need "<<p+i<<" cannot acquire resources."<<endl;
                            if(counter == (p-1))
                            {
                                cout<<"This is a deadlock situtation!"<<endl;
                                exit(0);
                            }
                            break;
                        }
                        else if(j==(r-1))
                        {
                            cout<<"need" <<p+i<<" can acquire resources and complete execution."<<endl;
                                                        for(j=0;j<r;j++)
                            {
                                available[j] += allocation[i][j];
                            }
                            done[counter] = i;
                            undone[i] = 0;
                            counter++;
                        }
                    }
                }
            }
        }
        cout<<"Order of process execution: "<<endl;
        for(int i=0;i<p;i++)
        {
            cout<<"P("<<done[i]<<")";
        }




return 0;

}
