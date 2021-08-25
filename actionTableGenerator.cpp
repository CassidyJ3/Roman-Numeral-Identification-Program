#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

static int charConvert[256] = {
  34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 5, 34, 34, 34, 32, 6, 34, 34, 34, 34, 1, 9, 2, 13, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 8, 3, 4, 33, 11, 34, 18, 20, 31, 24, 21, 25, 17, 27, 22, 31, 31, 28, 19, 23, 16, 14, 31, 15, 29, 26, 31, 31, 30, 31, 31, 31, 34, 34, 34, 12, 32, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 7, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34
};

int charConverter(int character){
  return charConvert[character];
}

int main(){
  int x = 54;
  int actionTable[x][36];
  for(int i = 0; i < x; i++){
    for(int j = 0; j <= 36; j++){
      actionTable[i][j] = -1;
    }
  }

  //common for row
  for(int j = 0; j < 36; j++){
    actionTable[52][j] = 404;
    actionTable[46][j] = 600;
    actionTable[51][j] = 200;
    actionTable[50][j] = 1;
    actionTable[53][j] = 600;
  }

  //consistent for column
  for(int i = 0; i < x; i++){
    actionTable[i][charConverter('+')] = 301;
    actionTable[i][charConverter('-')] = 302;
    actionTable[i][charConverter('=')] = 305;
    actionTable[i][charConverter(';')] = 401;
    actionTable[i][charConverter(',')] = 402;
    actionTable[i][charConverter('?')] = 405;
    actionTable[i][charConverter('^')] = 406;
    actionTable[i][34] = 600;
  }

  //clump rules

  //transition from building token X to building token Y
  for(int i = 1; i < 54; i++){
    actionTable[i][charConverter('P')] = 2;
    actionTable[i][charConverter(':')] = 2;
    actionTable[i][charConverter('<')] = 2;
    actionTable[i][charConverter('>')] = 2;
    actionTable[i][charConverter('!')] = 2;
    actionTable[i][charConverter('|')] = 2;
    actionTable[i][charConverter('&')] = 2;
    actionTable[i][charConverter('R')] = 2;
    actionTable[i][charConverter('O')] = 2;
    actionTable[i][charConverter('G')] = 2;
    actionTable[i][charConverter('A')] = 2;
    actionTable[i][charConverter('M')] = 2;
    actionTable[i][charConverter('B')] = 2;
    actionTable[i][charConverter('E')] = 2;
    actionTable[i][charConverter('I')] = 2;
    actionTable[i][charConverter('N')] = 2;
    actionTable[i][charConverter('D')] = 2;
    actionTable[i][charConverter('L')] = 2;
    actionTable[i][charConverter('S')] = 2;
    actionTable[i][charConverter('T')] = 2;
    actionTable[i][charConverter('F')] = 2;
    actionTable[i][charConverter('Z')] = 2;
    actionTable[i][charConverter('W')] = 2;
    actionTable[i][charConverter('H')] = 2;
    actionTable[i][charConverter('1')] = 2;
    actionTable[i][charConverter('.')] = 2;
  }

  //currently a variable
  for(int i = 1; i < 44; i++){
    for(int j = 0; j < 14; j++){
      actionTable[i][j] = 35;
    }
    actionTable[i][charConverter('<')] = 100;
    actionTable[i][charConverter('>')] = 100;
    actionTable[i][charConverter('!')] = 100;
    actionTable[i][charConverter('|')] = 100;
    actionTable[i][charConverter('&')] = -1;
    actionTable[i][charConverter('_')] = -1;
    actionTable[i][charConverter('1')] = -1;
    actionTable[i][35] = 100;
    for(int j = 14; j < 32; j ++){
      actionTable[i][j] = -1;
    }
  }

  //column 35
  actionTable[7][35] = 501;
  actionTable[12][35] = 502;
  actionTable[15][35] = 503;
  actionTable[18][35] = 506;
  actionTable[20][35] = 504;
  actionTable[26][35] = 508;
  actionTable[30][35] = 505;
  actionTable[35][35] = 507;
  actionTable[39][35] = 509;
  actionTable[42][35] = 510;
  actionTable[44][35] = 303;
  actionTable[45][35] = 304;
  actionTable[46][35] = 600;
  actionTable[47][35] = 600;
  actionTable[48][35] = 600;
  actionTable[49][35] = 200;
  actionTable[50][35] = 1;
  actionTable[51][35] = 200;
  actionTable[52][35] = 404;
  actionTable[53][35] = 600;

  //return to start state and perform ending action, then act from there: 35
  //actionTable[row][35] = ending action
  for(int i = 1; i <= 53; i++){
    actionTable[i][charConverter('+')] = 35;
    actionTable[i][charConverter('-')] = 35;
    actionTable[i][charConverter('=')] = 35;
    actionTable[i][charConverter(';')] = 35;
    actionTable[i][charConverter(',')] = 35;
    actionTable[i][charConverter('?')] = 35;
    actionTable[i][charConverter('^')] = 35;
  }

  //specific rules
  actionTable[44][charConverter('=')] = 307;
  actionTable[45][charConverter('=')] = 308;
  actionTable[46][charConverter('=')] = 306;
  actionTable[47][charConverter('&')] = 309;
  actionTable[48][charConverter('|')] = 310;
  actionTable[49][charConverter('1')] = -1;
  actionTable[50][charConverter('.')] = 1;
  actionTable[51][charConverter('1')] = -1;
  actionTable[52][charConverter('=')] = 403;
  actionTable[49][charConverter('.')] = -1;
  actionTable[50][charConverter('1')] = -1;



  for(int i = 0; i < x; i++){
    cout << '{';
    for(int j = 0; j < 35; j++){
      cout << actionTable[i][j] << ", ";
    }
    cout << actionTable[i][35] << "}," << endl;
  }
}
