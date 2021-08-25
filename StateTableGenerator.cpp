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
  int stateTable[x][35];
  for(int i = 0; i < x; i++){
    for(int j = 0; j < 35; j++){
      stateTable[i][j] = 0;
    }
  }

  for(int i = 0; i < x; i++){
    //non-specified characters
    stateTable[i][34] = 0;

    //letters not in keywords
    stateTable[i][31] = 43;

    //special characters
    stateTable[i][charConverter('+')] = 0;
    stateTable[i][charConverter('-')] = 0;
    stateTable[i][charConverter('<')] = 44;
    stateTable[i][charConverter('>')] = 45;
    stateTable[i][charConverter('=')] = 0;
    stateTable[i][charConverter('!')] = 46;
    stateTable[i][charConverter('&')] = 47;
    stateTable[i][charConverter('|')] = 48;
    stateTable[i][charConverter('1')] = 49;
    stateTable[i][charConverter('.')] = 53;
    stateTable[i][charConverter(';')] = 0;
    stateTable[i][charConverter(',')] = 0;
    stateTable[i][charConverter(':')] = 52;
    stateTable[i][charConverter('?')] = 0;
    stateTable[i][charConverter('^')] = 0;

    //letters starting key words
    stateTable[i][charConverter('P')] = 1;
    stateTable[i][charConverter('B')] = 8;
    stateTable[i][charConverter('E')] = 13;
    stateTable[i][charConverter('I')] = 19;
    stateTable[i][charConverter('T')] = 27;
    stateTable[i][charConverter('W')] = 31;
    stateTable[i][charConverter('R')] = 36;
    stateTable[i][charConverter('F')] = 40;

    //letters in key words not at start
    stateTable[i][charConverter('O')] = 43;
    stateTable[i][charConverter('G')] = 43;
    stateTable[i][charConverter('A')] = 43;
    stateTable[i][charConverter('M')] = 43;
    stateTable[i][charConverter('N')] = 43;
    stateTable[i][charConverter('D')] = 43;
    stateTable[i][charConverter('L')] = 43;
    stateTable[i][charConverter('S')] = 43;
    stateTable[i][charConverter('H')] = 43;
  }

  //lines with additional actions possible
  stateTable[44][charConverter('=')] = 0;
  stateTable[45][charConverter('=')] = 0;
  stateTable[46][charConverter('=')] = 0;
  stateTable[47][charConverter('&')] = 0;
  stateTable[48][charConverter('|')] = 0;
  stateTable[49][charConverter('.')] = 50;
  stateTable[50][charConverter('1')] = 51;
  stateTable[52][charConverter('=')] = 0;
  stateTable[53][charConverter('1')] = 51;

  //non-letters for strings
  for(int i = 1; i <= 43; i++){
    stateTable[i][charConverter('&')] = 43;
    stateTable[i][charConverter('1')] = 43;
    for(int j = 14; j <= 32; j++){
      stateTable[i][j] = 43;
    }
  }

  stateTable[0][charConverter('P')] = 1;
  stateTable[1][charConverter('R')] = 2;
  stateTable[2][charConverter('O')] = 3;
  stateTable[3][charConverter('G')] = 4;
  stateTable[4][charConverter('R')] = 5;
  stateTable[5][charConverter('A')] = 6;
  stateTable[6][charConverter('M')] = 7;

  stateTable[0][charConverter('B')] =  8;
  stateTable[8][charConverter('E')] =  9;
  stateTable[9][charConverter('G')] =  10;
  stateTable[10][charConverter('I')] = 11;
  stateTable[11][charConverter('N')] = 12;

  stateTable[0][charConverter('E')] =  13;
  stateTable[13][charConverter('N')] = 14;
  stateTable[14][charConverter('D')] = 15;

  //                            E>
  stateTable[13][charConverter('L')] = 16;
  stateTable[16][charConverter('S')] = 17;
  stateTable[17][charConverter('E')] = 18;

  stateTable[0][charConverter('I')] =  19;
  stateTable[19][charConverter('F')] = 20;

  //                            I>
  stateTable[19][charConverter('N')] = 21;
  stateTable[21][charConverter('T')] = 22;
  stateTable[22][charConverter('E')] = 23;
  stateTable[23][charConverter('G')] = 24;
  stateTable[24][charConverter('E')] = 25;
  stateTable[25][charConverter('R')] = 26;

  stateTable[0][charConverter('T')] =  27;
  stateTable[27][charConverter('H')] = 28;
  stateTable[28][charConverter('E')] = 29;
  stateTable[29][charConverter('N')] = 30;

  stateTable[0][charConverter('W')] =  31;
  stateTable[31][charConverter('H')] = 32;
  stateTable[32][charConverter('I')] = 33;
  stateTable[33][charConverter('L')] = 34;
  stateTable[34][charConverter('E')] = 35;

  stateTable[0][charConverter('R')] =  36;
  stateTable[36][charConverter('E')] = 37;
  stateTable[37][charConverter('A')] = 38;
  stateTable[38][charConverter('L')] = 39;

  stateTable[0][charConverter('F')] =  40;
  stateTable[40][charConverter('O')] = 41;
  stateTable[41][charConverter('R')] = 42;
  // row 43 reserved for variables


  for(int i = 0; i < x; i++){
    cout << '{';
    for(int j = 0; j < 34; j++){
      cout << stateTable[i][j] << ", ";
    }
    cout << stateTable[i][34] << "}," << endl;
  }
}
