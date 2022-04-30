inline int getLCA(int a, int b)
{
    if(d[a] < d[b])
        swap(a,b);
    for(int i = 19; i >= 0; i--)
    {
        if(d[p[i][a]] >= d[b])
            a = p[i][a];
    }
    if(a == b)
        return a;
    for(int i = 19; i >= 0; i--)
    {
        if(p[i][a] != p[i][b])
            a = p[i][a], b = p[i][b];
    }
    return p[0][a];
}