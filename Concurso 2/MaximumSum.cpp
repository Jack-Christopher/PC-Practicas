#include <iostream>
#include <bits/stdc++.h>

struct block 
{
	int indice;
	long long int valor;
};

const int N = 1e5+5;
int n;
long long int a[N];
block t[N<<2];

block combine(block l, block r) 
{ 	
    return l.valor > r.valor ? l : r; 
}

void build(int k, int l, int r) 
{
	if (l == r) 
    {
		t[k] = { l, a[l] };
		return;
	}
	int m = (l+r)>>1;
	build(k<<1, l, m);
	build(k*2+1, m+1, r);
	t[k] = combine(t[k<<1], t[k*2+1]);
}

void update(int k, int l, int r, int x, int y) 
{
	if (r < x || x < l) 
        return;
	if (l == x && r == x) 
    {
		t[k] = { x, y };
		return;
	}
	int m = (l+r)>>1;
	update(k<<1, l, m, x, y);
	update(k*2+1, m+1, r, x, y);
	t[k] = combine(t[k<<1], t[k*2+1]);
}

block findMax(int k, int l, int r, int L, int R) 
{
	if (r < L || R < l) 
        return { -1, -1 };
	if (L <= l && r <= R) 
        return t[k];
	int m = (l+r)>>1;
	block lt = findMax(k<<1, l, m, L, R);
	block rt = findMax(k*2+1, m+1, r, L, R);

	return combine(lt, rt);
}



int main()
{
    int Q;
    char c; 
    int x, y;
    
    scanf("%d", &n);
    for (int k = 1; k <= n; k++)
        scanf("%lld", a+k);

	build(1,1,n);
	
	scanf("%d\n", &Q);

	while (Q--) 
    {
        scanf("%c", &c);
        scanf ("%d%d\n", &x, &y);
		if (c == 'U') 
			update(1,1,n,x,y);
		else if (c == 'Q')
        {
			block p = findMax(1,1,n,x,y);
			block izquierda = findMax(1,1,n,x,p.indice-1);
			block derecha = findMax(1,1,n,p.indice+1,y);
			block combinacion = combine(izquierda, derecha);
			printf("%lld\n", p.valor + combinacion.valor);
		}
	}
}