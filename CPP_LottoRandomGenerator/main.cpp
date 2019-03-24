//
//  main.cpp
//  CPP_LottoRandomGenerator
//
//  Created by Mateusz Szalkowski on 19/03/2019.
//  Copyright © 2019 Mateusz Szalkowski. All rights reserved.
//

#include <iostream>
#include <random>
#include <ctime>
#include <vector>
#include <algorithm>


int main(int argc, const char * argv[])
{
  const int MAX_NUMBERS = 47;
  int numOfLines;
  std::vector<std::vector<int>> numbers;
  std::vector<std::vector<int>> selected;
  
  std::random_device rd;
  std::mt19937 g(rd());

  std::cout<<"How many lines ya want? "<<std::endl;
  std::cin>>numOfLines;
  
  // fill vectors with numbers 1-47
  for (int i = 0; i != numOfLines; i++)
  {
    std::vector<int> temp;
    for (int j = 1; j <= MAX_NUMBERS; j++)
    {
      temp.push_back(j);
    }
    numbers.push_back(temp);
  }
  
  // shuffle numbers
  for (auto i = 0; i < numbers.size(); i ++)
  {
    std::shuffle(numbers[i].begin(), numbers[i].end(), g);
  }
  
  // fill 6 lucky numbers
  for (int i = 0; i <= numOfLines; i++)
  {
    std::vector<int> temp2;
    temp2.insert(temp2.end(), numbers[i].begin(), numbers[i].end()-41);
    selected.push_back(temp2);
  }
  
  // print 6 numbers for debugging
  for (int i = 0; i != numOfLines; ++i)
  {
    // sort
    std::sort(selected[i].begin(), selected[i].end());
    for (int j = 0; j != selected[i].size(); ++j)
    {
      std::cout << selected[i][j]<<" ";
    }
    std::cout<<"\n";
  }
  
  return 0;
}
