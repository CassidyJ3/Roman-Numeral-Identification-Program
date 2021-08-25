#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

int main(){
  int k[256];
  char t;
  for(int i = 0; i < 256; i++){
    k[i] = 34;
  }
  t = '0';
  k[t] = 0;
  t = '1';
  k[t] = 0;
  t = '2';
  k[t] = 0;
  t = '3';
  k[t] = 0;
  t = '4';
  k[t] = 0;
  t = '5';
  k[t] = 0;
  t = '6';
  k[t] = 0;
  t = '7';
  k[t] = 0;
  t = '8';
  k[t] = 0;
  t = '9';
  k[t] = 0;


  t = '+';
  k[t] = 1;
  t = '-';
  k[t] = 2;
  t = '<';
  k[t] = 3;
  t = '=';
  k[t] = 4;
  t = '!';
  k[t] = 5;
  t = '&';
  k[t] = 6;
  t = '|';
  k[t] = 7;
  t = ';';
  k[t] = 8;
  t = ',';
  k[t] = 9;
  t = ':';
  k[t] = 10;
  t = '?';
  k[t] = 11;
  t = '^';
  k[t] = 12;
  t = '.';
  k[t] = 13;
  t = '>';
  k[t] = 33;


  t = 'P';
  k[t] = 14;
  t = 'R';
  k[t] = 15;
  t = 'O';
  k[t] = 16;
  t = 'G';
  k[t] = 17;
  t = 'A';
  k[t] = 18;
  t = 'M';
  k[t] = 19;
  t = 'B';
  k[t] = 20;
  t = 'E';
  k[t] = 21;
  t = 'I';
  k[t] = 22;
  t = 'N';
  k[t] = 23;
  t = 'D';
  k[t] = 24;
  t = 'F';
  k[t] = 25;
  t = 'T';
  k[t] = 26;
  t = 'H';
  k[t] = 27;
  t = 'L';
  k[t] = 28;
  t = 'S';
  k[t] = 29;
  t = 'W';
  k[t] = 30;

  t = 'C';
  k[t] = 31;
  t = 'Z';
  k[t] = 31;
  t = 'X';
  k[t] = 31;
  t = 'Q';
  k[t] = 31;
  t = 'V';
  k[t] = 31;
  t = 'J';
  k[t] = 31;
  t = 'K';
  k[t] = 31;
  t = 'Y';
  k[t] = 31;
  t = 'U';
  k[t] = 31;

  t = '_';
  k[t] = 32;
  t = '%';
  k[t] = 32;
  for(int i = 0; i < 256; i++){
    cout << k[i] << ", ";

  }

}
