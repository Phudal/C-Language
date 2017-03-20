#ifndef __BOOK_H__
#define __BOOK_H__

#include "Constant.h"

void InputData3DArray(wchar_t Array3D[][LINE][SENTENCE], const FILE* pFile);
void InputData2DArrayPointer(wchar_t(*pArray2D)[LINE][SENTENCE], const FILE* pFile);
void PrintData(wchar_t pArray3D[][LINE][SENTENCE], const FILE* pFile);
#endif
