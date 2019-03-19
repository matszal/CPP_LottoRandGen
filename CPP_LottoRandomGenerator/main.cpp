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


int main(int argc, const char * argv[]) {
  
  int numOfLines;
  const int MAX_NUMBERS = 6;
  
  std::default_random_engine engine( static_cast<unsigned int>(time(0)));
  std::uniform_int_distribution<unsigned int> randomInt(1, 47);
  
  
  std::cout<<"Sexy lotto number generator with C++11 rand style"<<std::endl;
  std::cout<<"How many lines ya want? "<<std::endl;
  
  std::cin>>numOfLines;
  
  for (int lines = 0; lines != numOfLines; ++lines)
  {
    for (int nos = 0; nos != MAX_NUMBERS; ++nos)
    {
        std::cout << randomInt(engine)<<" ";
    }
    std::cout<<"\n";
  }
  return 0;
}
