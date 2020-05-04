#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,j;
    cout<<"No of variable: ";
    cin>>n;
    cout<<setprecision(5)<<fixed;
    float eqn[n][n+1];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            cin>>eqn[i][j];
        }
    }
    float f21=(eqn[1][0]/eqn[0][0]);
    float f31=eqn[2][0]/eqn[0][0];
    float f32=(eqn[2][1]-f31*eqn[0][1])/(eqn[1][1]-f21*eqn[0][1]);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n+1;j++){
            if(i==1)
            {
                eqn[i][j]=eqn[i][j]-eqn[0][j]*f21;
            }
            else if(i==2)
            {
                eqn[i][j]=eqn[i][j]-eqn[0][j]*f31;
            }
        }
    }
    eqn[1][0]=0;
    eqn[2][1]=eqn[2][1]-f32*eqn[1][1];
    eqn[2][2]=eqn[2][2]-f32*eqn[1][2];
    eqn[2][3]=eqn[2][3]-f32*eqn[1][3];
    cout<<"\nAfter Forward Elimination:\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            if(eqn[i][j]<0)
                cout<<eqn[i][j]<<" ";
            else
                cout<<" "<<eqn[i][j]<<" ";
        }
        cout<<endl;
    }
    float x1,x2,x3;
    x3=eqn[2][3]/eqn[2][2];
    x2=(eqn[1][3]-eqn[1][2]*x3)/eqn[1][1];
    x1=(eqn[0][3]-eqn[0][2]*x3-eqn[0][1]*x2)/eqn[0][0];
    cout<<"\nx1= "<<x1;
    cout<<"\nx2= "<<x2;
    cout<<"\nx3= "<<x3;

    return 0;
}
