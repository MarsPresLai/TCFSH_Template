vector<vector<LL>> p;
struct lca
{
    vector<LL> dep;
    vector<vector<LL>> v;
    
    void dfs(LL prev,LL pos, LL depth)
    {
        dep[pos] = depth;
        v[0][pos] = prev;
        for (LL i : p[pos])
        {
            dfs(pos,i, depth + 1);
        }
        
        return;
    }

    void init(LL n)
    {
        dep.resize(n + 1);
        v.resize(20, vector<LL>(n + 1));
        dfs(1, 1, 0);
        for (int i = 1; i <= 19; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                v[i][j] = v[i - 1][v[i - 1][j]];
            }
        }
    }

    LL LCA(LL a,LL b)
    {
        LL pa = a, pb = b;
        if (dep[pa] > dep[pb])
        {
            swap(pa, pb);
        }
        LL dif = dep[pb] - dep[pa];
        LL cnt = 0;
        while (dif != 0)
        {
            if (dif & 1)
            {
                pb = v[cnt][pb];
            }
            cnt++;
            dif >>= 1;
        }
 
        if (pa == pb)
        {
            return pa;
        }
        else
        {
            for (LL i = 19; i >= 0; i--)
            {
                if (v[i][pa] != v[i][pb])
                {
                    pa = v[i][pa];
                    pb = v[i][pb];
                }
            }
            return v[0][pa];
        }
    }
};
