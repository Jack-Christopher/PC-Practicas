#include <bits/stdc++.h>

std::vector<int> pre_kmp(std::string pattern)
{
	int size = pattern.size();
    std::vector<int> pie(size);
	pie[0] = 0;
	int k = 0;
	for(int i = 1; i < size; i++)
	{
		while(k > 0 && pattern[k] != pattern[i] )
			k=pie[k-1];
		if( pattern[k] == pattern[i] )
			k=k+1;
		pie[i]=k;
	}
	return pie;
}

int kmp(std::string text,std::string pattern)
{
    int times = 0;
	std::vector<int> pie = pre_kmp(pattern);
	int matched_pos=0;
	for(int current=0; current< text.size(); current++)
	{
		while (matched_pos > 0 && pattern[matched_pos] != text[current] )
			matched_pos = pie[matched_pos-1];
			
		if(pattern[matched_pos] == text[current])
			matched_pos = matched_pos+1;
			
		if( matched_pos == (pattern.size()) )
		{
            times++;
			matched_pos = pie[matched_pos-1];
		}
	}

    return times;
}

int main()
{
    int N = -1;
    std::vector<std::string> patterns;
    std::string text, pattern;
    std::vector<std::pair<std::string, int>> ans;
    int max;

    while(true)
    {
        std::cin>>N;
        if (N == 0)
            break;

        while(N--)
        {
            std::cin>>pattern;
            patterns.push_back(pattern);
        }
        std::cin>>text;
        max = 0;

        for (int i = 0; i < patterns.size(); i++)
        {
            ans.push_back(std::make_pair(patterns[i], kmp(text, patterns[i])));
            max = std::max(max, ans[i].second);
        }

        std::cout<<max<<"\n";
        for (int i = 0; i < ans.size(); i++)
        {
            if (ans[i].second == max)
                std::cout<<ans[i].first<<"\n";
        }
        ans.clear();
        patterns.clear();

    }

    return 0;
}