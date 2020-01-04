#include<iostream>

using namespace std;
float funcYin(int x1,int x2, float w1,float w2, float b)
{
    float Yin=x1*w1+x2*w2+b;
    return Yin;
}
float delw(float a,float error,float w)
{
    return(a*error*w);
}
int update(int x1,int x2,float *w1,float *w2,float *b, float Yin, int t, float a)
{
    float error=(t-Yin);
    *w1=*w1+delw(a,error,x1);
    *w2=*w2+delw(a,error,x2);
    *b=*b+delw(a,error,1);
}
int funcY(float Yin)
{
    int y;
    if(Yin>0)
            y=1;
        else
            y=-1;
    return y;
}
int main()
{ cout<<"Adaline network for AND"<<endl;
    int x1,x2,t,i,y,k=1,p=5;
    int x11[]={-1,-1,1,1};
    int x22[]={-1,1,-1,1};
    int tt[]={-1,-1,-1,1};

    float b=0.1,w1=0.1,w2=0.1,Yin,a;
    float error[10],min_error,mse;

    cout<<"enter learning rate"<<endl;
    cin>>a;

    cout<<"\n enter least error"<<endl;
    cin>>min_error;

    do{
            mse=0.0;
    for(i=0;i<4;i++)
    {
        x1=x11[i];
        x2=x22[i];
        t=tt[i];
        Yin=funcYin(x1,x2,w1,w2,b);

        y=funcY(Yin);
        update(x1,x2,&w1,&w2,&b,Yin,t,a);
        error[i]=(t-Yin)*(t-Yin);
    }
    cout<<"EPOCH "<<k<<endl;
    cout<<" w1 = "<<w1<<endl;
    cout<<" w2 = "<<w2<<endl;
    cout<<" b  = "<<b<<endl;
    cout<<"Errors for epoch "<<k++<<endl;
    for(i=0;i<4;i++)
    {
        cout<<error[i]<<endl;
        mse=mse+error[i];
    }
    mse=mse*0.5;

    cout<<"mean square error="<<mse<<"\n\n"<<endl;

    if(mse<=min_error)
    {
        cout<<"\n Training Successful"<<endl;
        break;
    }
}while(--p>0);

if(p<=0)
{
    cout<<"\nCannot be trained to this accuracy"<<endl;
    return 0;
}
}
