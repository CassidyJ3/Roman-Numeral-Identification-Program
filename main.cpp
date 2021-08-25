/*
* main.cpp
*
* Author: Joe Cassidy
* Purpose: To create a finite state machine that accepts only Roman numerals.
* Date: 13 September, 2018
* Class: CSCI 371
*/

#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

static int nextState[12][5] =
{
  {1,2,3,4,5},
  {-1,-1,-1,-1,-1},
  {-1,-1,6,4,5},
  {7,7,8,4,5},
  {-1,-1,-1,-1,9},
  {-1,-1,1,1,10},
  {-1,-1,8,4,11},
  {-1,-1,-1,4,11},
  {-1,-1,7,4,11},
  {-1,-1,-1,-1,10},
  {-1,-1,-1,-1,1},
  {-1,-1,1,1,10},
};

// all 0's are dead states, which are handled in another way
static int action[12][5] =
{
  {100, 50, 10, 5, 1},
  {0,0,0,0,0},
  {0,0,10,5,1},
  {80,30,10,5,1},
  {0,0,0,0,1},
  {0,0,8,3,1},
  {0,0,10,5,1},
  {0,0,0,5,1},
  {0,0,10,5,1},
  {0,0,0,0,1},
  {0,0,0,0,1},
  {0,0,8,3,1}
};

int isValid(string input, int charPosition, int currentState, int value){
  if(charPosition < input.length()){
    char currChar = input.at(charPosition);
    int tableColumn;
    switch(currChar){
      case 'C': tableColumn = 0;
                break;
      case 'L': tableColumn = 1;
                break;
      case 'X': tableColumn = 2;
                break;
      case 'V': tableColumn = 3;
                break;
      case 'I': tableColumn = 4;
                break;
      default:  return -1;
    }
    value = value + action[currentState][tableColumn];
    currentState = nextState[currentState][tableColumn];
    //immediately return false upon reaching a dead state
    if(currentState != -1){
      return isValid(input, charPosition + 1, currentState, value);
    }
    else{
      return -1;
    }
  }
  else{
      return value;
  }
}

int main(){
  string input;
  cin >> input;
  int value = isValid(input, 0, 0, 0);
  if(value != -1){
    cout << input << " = " << value << endl;
  }
  else{
    cout << input << " is not a valid Roman numeral between 0 and 100." << endl;
  }
  exit(0);
}
