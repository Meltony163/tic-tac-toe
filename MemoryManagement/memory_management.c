#include "stdio.h"
#include "stdlib.h"
#include "string.h"
/**
 * @file Memory_Management.h
 * @author Moamen eltony
 * @brief This file contains functions that deal with memory in Heab.
 * @version 0.1
 * @date 2023-11-10
 */

/**
 *brief :Use this function to initially allocate memory for player names.
 *@param ptr_aName:pointer to a character pointer
 */
void MEMN_vAllocatePlayerName(char **ptr_aName)
{
    *ptr_aName=(char*)malloc(50*sizeof(char));
}

/**
 *brief :Use this function to reduce memory allocated for player names.
 *@param ptr_aName:pointer to a character pointer
 */
void MEMN_vResizePlayerName(char **ptr_aName)
{
    *ptr_aName=(char*)realloc(*ptr_aName,strlen(*ptr_aName)+1);
}
