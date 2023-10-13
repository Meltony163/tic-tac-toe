#ifndef LOGIC
#define LOGIC
/**
 * @file logic.h
 * @author Moamen eltony
 * @brief This file contains functions that deal with logic of the game.
 * @version 0.1
 * @date 2023-11-10
 */

void LOGC_vInitBoard(char cpy_aBoard[][3]);

int LOGC_Win(char cpy_aBoard[][3]);

void LOGC_vTakeInput(char cpy_aBoard[][3],char cpy_cValue);

void LOGC_vPutInput(char cpy_aBoard[][3],char cpy_cValue,char cpy_cPosition);

char LOGC_cAlmostWinX(char cpy_aBoard[][3]);

char LOGC_cAlmostWinO(char cpy_aBoard[][3]);

char LOGC_cRandomPosition(char cpy_aBoard[][3]);

int LOGC_nMainList();

int LOGC_nSinglePlayerMode();

int LOGC_nPlayAgain();
#endif