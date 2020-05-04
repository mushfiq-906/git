#include<bits/stdc++.h>
using namespace std;

//3 -0.1 -0.2
//0.1 7 -0.3
//0.3 -0.2 10
void Print(float a[3][3])
{
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++){
            if(a[i][j]<0)
                printf("%8.6f ",a[i][j]);
            else
                printf("%9.6f ",a[i][j]);
        }
        cout<<endl;
    }
}

void Print(float d1,float d2,float d3)
{
    cout<<setprecision(5)<<fixed;
    cout<<"d1="<<d1<<endl;
    cout<<"d2="<<d2<<endl;
    cout<<"d3="<<d3<<endl;
    cout<<endl;


}


int main()
{
    int i,j;
    float a[3][3];
    float l[3][3];
    float u[3][3];
    float rev[3][3];
    cout<<"Enter the Matrix:\n";
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++){
            cin>>a[i][j];
        }
    }

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++){
           if(i==j)
            l[i][j]=1;
           else
            l[i][j]=0;
        }
    }

    float f21=(a[1][0]/a[0][0]);
    float f31=a[2][0]/a[0][0];
    float f32=(a[2][1]-f31*a[0][1])/(a[1][1]-f21*a[0][1]);
    l[1][0]=f21;
    l[2][0]=f31;
    l[2][1]=f32;
    cout<<"\nLower Triangular Matrix: "<<endl;
    Print(l);

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++){
            if(i==0){
                u[i][j]=a[i][j];
            }
            else if(i==1)
            {
                u[i][j]=a[i][j]-a[0][j]*f21;
            }
            else if(i==2)
            {
                u[i][j]=a[i][j]-a[0][j]*f31;
            }
        }
    }
    u[1][0]=0;
    u[2][1]=u[2][1]-f32*u[1][1];
    u[2][2]=u[2][2]-f32*u[1][2];
    cout<<"\nUpper Triangular Matrix: "<<endl;
    Print(u);

    float d1=1;
    float d2=-l[1][0]*d1;
    float d3=-l[2][0]*d1-l[2][1]*d2;
    cout<<"\nSub problem 1:\n";
    Print(d1,d2,d3);

    float x1,x2,x3;
    x3=rev[2][0]=d3/u[2][2];
    x2=rev[1][0]=(d2-u[1][2]*x3)/u[1][1];
    x1=rev[0][0]=(d1-u[0][2]*x3-u[0][1]*x2)/u[0][0];

    d1=0;
    d2= 1-l[1][0]*d1;
    d3=-l[2][0]*d1-l[2][1]*d2;
    cout<<"\nSub problem 2:\n";
    Print(d1,d2,d3);

    x3=rev[2][1]=d3/u[2][2];
    x2=rev[1][1]=(d2-u[1][2]*x3)/u[1][1];
    x1=rev[0][1]=(d1-u[0][2]*x3-u[0][1]*x2)/u[0][0];

    d1=0;
    d2=-l[1][0]*d1;
    d3=1-l[2][0]*d1-l[2][1]*d2;
    cout<<"\nSub problem 3:\n";
    Print(d1,d2,d3);
    cout<<"\n A inverse:\n";
    x3=rev[2][2]=d3/u[2][2];
    x2=rev[1][2]=(d2-u[1][2]*x3)/u[1][1];
    x1=rev[0][2]=(d1-u[0][2]*x3-u[0][1]*x2)/u[0][0];
    Print(rev);
}
