#ifndef RA_NO_H_INCLUDED
#define RA_NO_H_INCLUDED



#endif // RA_NO_H_INCLUDED
int get_q_number(q)
{
    int a[25],i,j,t,q;
    srand(time(NULL));

    for(i=0;i<=q;i++)
    {
        t=rand()%q+1;
        for(j=0;j<=i-1;j++)
        {
            if(t==a[j])
                break;
        }
        if(i==j)
        {
            return t;
        }
        else
            i--;
    }
}
