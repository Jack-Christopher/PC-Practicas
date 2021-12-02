#include <bits/stdc++.h>

int input[100005]; 
int rank[100005], sufix_array[100005];
int pos[100005];
int temp[100005];
int longest_common_prefix[100005]; 
int w[100005]; 
int N, S, gap;
bool tieneLCP = false;


bool comparar(int i, int j) 
{
    if (pos[i] == pos[j]) 
    {
        i += gap;
        j += gap;
        if (i < S && j < S)
            return pos[i] < pos[j];
        else
            return i > j;
    }
    return pos[i] < pos[j];
}


void get_suffix_array() 
{
    for (int i = 0; i < S; ++i) 
    {
        pos[i] = input[i];
        sufix_array[i] = i;
        temp[i] = 0;
    }
    // se comparan las cadenas anteriores

    gap = 1;
    while (true) 
    {
        //se ordenan las cadenas
        std::sort(std::begin(sufix_array), std::begin(sufix_array) + S, comparar);
        for(int i=0; i < S-1; ++i)
        {
            int higher = comparar(sufix_array[i], sufix_array[i+1]);
            temp[i+1] = temp[i] + (higher ? 1 : 0);
        }
        for(int i=0; i < S; ++i)
            pos[sufix_array[i]] = temp[i];
        // se repiten hasta que las cadenas sean distintas
        if (temp[S-1] >= S-1) 
            break;
        gap = gap << 1;
    }
}

void get_longest_common_prefix(int sufix_array_tam) 
{
    for(int i=0; i < sufix_array_tam; ++i)
        rank[sufix_array[i]] = i;
    longest_common_prefix[0] = 0;
    int h = 0;
    for (int i = 0; i < sufix_array_tam; ++i) 
    {
        if (rank[i] == 0) 
        {
            longest_common_prefix[i] = 0;
            continue;
        }
        if (rank[i] > 0) 
        {
            int j = sufix_array[rank[i]-1];
            while (i+h < sufix_array_tam && j+h < sufix_array_tam && input[i+h] == input[j+h])
                ++h;
            longest_common_prefix[rank[i]] = h;
            if (h > 0) 
            {
                --h;
                tieneLCP = true;
            }
        }
    }
}
 
bool longest_common_substring(int x, int sufix_array_tam, bool print) 
{
    bool counted[N];
    int count;
    for (int i = 1; i < sufix_array_tam; ++i) 
    {
        if (longest_common_prefix[i] >= x) 
        {
            for(int i=0; i < N; ++i)
                counted[i] = false;
            count = 1;
            counted[w[sufix_array[i-1]]] = true;
            int j = i;
            while (j < sufix_array_tam && longest_common_prefix[j] >= x)
            { 
                if (w[sufix_array[j]] != w[sufix_array[j]+x-1])
                    break;
                if (!counted[w[sufix_array[j]]]) 
                {
                    counted[w[sufix_array[j]]] = true;
                    ++count;
                }
                ++j;
            }
            if (count > N/2)
            {
                if (print) 
                {
                    printf("%c", 'a' + input[sufix_array[i]]);
                    for (int k = 1; k < x; ++k) 
                    {
                        printf("%c", 'a' + input[sufix_array[i]+k]);
                    }
                    printf("\n");
                }
                else
                    return true;
            }
            i = j-1;
        }
    }
    return false;
}


int main() 
{
    int T, sufix_array_tam, longestWord = -1;
    std::string line;
    while (scanf("%d", &N) == 1 && N != 0) 
    {
        sufix_array_tam = 0;
        // se omite el fin de linea
        std::getline(std::cin, line); 
        for(int i=0; i < N; ++i)
        {
            std::getline(std::cin, line);
            if (line.length() - longestWord > 0)
                longestWord = line.length();
            for (int j = 0; j < line.length(); ++j) 
            {
                w[sufix_array_tam] = i;
                input[sufix_array_tam++] = line[j] - 'a';
            }
            input[sufix_array_tam++] = 27+i;
            input[sufix_array_tam] = 0;
        }
        input[sufix_array_tam-1] = 0;

        --sufix_array_tam;
        S = sufix_array_tam;
        get_suffix_array();
        get_longest_common_prefix(sufix_array_tam);

        int low = 1, best = -1;
        int high = longestWord;
        if (tieneLCP) 
        {
            while (high >= low) 
            {
                int mid = low + (high-low)/2;
                if (longest_common_substring(mid, sufix_array_tam, false)) 
                {
                    low = mid + 1;
                    best = std::max(mid,best);
                }
                else
                    high = mid - 1;
            }
        }
        if (best != -1) 
        {
            longest_common_substring(best, sufix_array_tam, true);
        }
        else // no hay subcadena en comun
            printf ("?\n");
        printf ("\n");
     }
    return 0;
}