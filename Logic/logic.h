#ifndef LOGIC
#define LOGIC
void LOGC_vInitBoard(char cpy_aBoard[][3]);

int LOGC_Win(char cpy_aBoard[][3]);

void LOGC_vTakeInput(char cpy_aBoard[][3],char cpy_cValue);

void LOGC_vPutInput(char cpy_aBoard[][3],char cpy_cValue,char cpy_cPosition);

char LOGC_cAlmostWinX(char cpy_aBoard[][3]);

char LOGC_cAlmostWinO(char cpy_aBoard[][3]);
#endif