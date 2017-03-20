#ifndef __MINESEARCH_H__
#define __MINESEARCH_H__

int InputBoardInfo(int* _iInputRow, int* _iInputCol);
int MallocBoard(char*** pppMineBoard, int _iInputRow, int _iInputCol);
void FreeBoard(char*** pppMineBoard, int _iInputRow);
void InputObject(char*** pppMineBoard, int _iInputRow);
void SearchMine(char*** pppMineBoard, int _iInputRow, int _iInputCol);
void PrintResult(char*** pppMineBoard, int _iInputRow, int _iInputCol);

#endif
