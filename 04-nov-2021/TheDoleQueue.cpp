#include <stdio.h>
#include <iostream>
#include <queue>

int main() 
{
  int N, K, M, temp_of1, temp_of2, counter, index, oficial1, oficial2;
  int circle[20];

  while(std::cin >> N >> K >> M && N) 
  {
    // inicio del conteo
    oficial1 = 0;
    oficial2 = N - 1;

    // establecer sus numeros
    for(index = 0;index < N; index++)
      circle[index] = index + 1;

    counter = 0;

    while(counter < N) 
    {
      index = K;
      while (index > 0)
      {
        if(circle[oficial1] > 0) 
            index--;
        if(index == 0) 
            temp_of1 = oficial1;
        oficial1 = (oficial1 + 1) % N;
      }

      index = M;
      while(index > 0) 
      {
        if(circle[oficial2] > 0) 
            index--;
        if(index == 0) 
            temp_of2 = oficial2;
        oficial2 = (oficial2 + N - 1) % N;
      }

      if(counter > 0)
        std::cout <<",";

      if(temp_of1 != temp_of2) // dos distintos --> reetraining
      {
        printf("%3d%3d", circle[temp_of1], circle[temp_of2]);
        counter += 2;
      }
      else //politician
      {
        printf("%3d", circle[temp_of1]);
        counter++;
      }

      circle[temp_of1] = circle[temp_of2] = 0;
    }

    std::cout << '\n';
  }

  return 0;
}