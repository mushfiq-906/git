#include<bits/stdc++.h>
using namespace std;
typedef struct node Stack;

struct node
{
    char data;
    Stack *next;
}*top=NULL,*bottom=NULL,*p,*q,*newnode;
char y;

int Operand(char ch)
{
    return((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9'));
}

int Operator(char ch)
{
    return (ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^');
}

int prec(char ch)
{
    if(ch=='+'||ch=='-')
        return 1;
    else if(ch=='*'||ch=='/')
        return 2;
    else if(ch=='^')
        return 3;
    else
        return 0;
}

void push(char x)
{
    newnode = new Stack;
    newnode->data =x;
    if(bottom==NULL)
    {
        newnode->next=NULL;
        top=bottom=newnode;
    }
    else
    {
        newnode->next=top;
        top=newnode;
    }
}

void pop()
{
    p=top;
    y=p->data;
    top=top->next;
    free(p);
}

void postfix(string s)
{
    push('(');
    string ans="";
    int len=s.length();
    for(int i=0;i<len;i++)
    {
        if(s[i]=='('){
            push(s[i]);
        }

        else if(Operand(s[i])){
            ans=ans+s[i];
        }


        else if(s[i]==')')
        {
            while(top->data!='(')
            {
                if(Operator(top->data))
                {
                    pop();
                    ans=ans+y;
                }
            }
            pop();
        }
        else if(Operator(s[i]))
        {
            //ans=ans+',';
            if(Operator(top->data))
            {
                if(prec(top->data)>=prec(s[i]))
                {
                    pop();
                    ans=ans+y;
                    push(s[i]);
                }
                else
                {
                    push(s[i]);
                }
            }
            else{
                push(s[i]);
            }
        }
    }
    while(top->data!='(')
    {
        if(Operand(top->data)||Operator(top->data))
        {
            pop();
            ans=ans+y;
        }
    }
    cout<<ans<<endl;
}

int main()
{
    int t;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>s;
        postfix(s);
    }
}

