#include<iostream>
#include<string>
#include<vector>

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
			std::cout<<"Found pattern at index "<< current - (pattern.size() -1 );
			matched_pos = pie[matched_pos-1];
		}
	}
}

int main()
{
	std::string text,pattern;
	std::cout<<"enter text:";
	std::cin>>text;
	std::cout<<"enter pattern:";
	std::cin>>pattern;
	
	kmp(text,pattern);
	
	return 0;
}