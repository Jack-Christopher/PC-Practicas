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

void kmp(std::string text,std::string pattern)
{
    std::vector<int> result;
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
			// std::cout<<"RESULT: "<< current - (pattern.size() -1 );
            result.push_back(current - (pattern.size() -1 ));
			matched_pos = pie[matched_pos-1];
		}
	}
    
    if (result.size() == 0)
        std::cout<<"Not Found";
    else
    {
        std::cout<<result.size()<<"\n";
        std::cout<<result[0]+1;
        for (int i = 1; i < result.size(); i++)
            std::cout<<" "<<result[i]+1;
    }
}


int main()
{
    int T;
    std::cin >> T;
    while (T--)
    {
        std::string A,B;
        std::cin >> A >> B;
        kmp(A,B);
        //Linea entre dos casos
        if (T)
            std::cout << "\n\n";
    }

    return 0;
}