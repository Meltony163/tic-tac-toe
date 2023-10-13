#ifndef OUTPUT
#define OUTPUT
/**
 * @file output.h
 * @author Moamen eltony
 * @brief This file contains functions that deal with output.
 * @version 0.1
 * @date 2023-11-10
 */
char IOUT_cTakeInput(char cpy_aBoard[][3],char cpy_cValue);

void IOUT_vPrintTurn(char *ptr_aName,char cpy_cSymbol);

void IOUT_vPrintBoard(char cpy_aBoard[][3]);

void IOUT_vPrintList(short int cpy_nFlag);

void IOUT_vSinglePlayerMode(short int cpy_nFlag);

void IOUT_vPlayAgain(short int cpy_nFlag);
#endif
