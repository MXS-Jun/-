#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 100

typedef struct
{
    int record[MAXSIZE];
    int length;
} SeqList;


void InitSeqList(SeqList *list);
int ClearSeqList(SeqList *list);
int GetLength(SeqList *list);
bool IsEmpty(SeqList *list);
void InsertElem(SeqList *list, int index, int elem);
void DeleteElem(SeqList *list, int index, int *elem);
int LocateElem(SeqList *list, int *elem);
int MergeSeqList(SeqList *list1, SeqList *list2);
int ReverseSeqList(SeqList *list);
int GetMaxElem(SeqList *list);
int GetMinElem(SeqList *list);


int main(void)
{

    return 0;
}


void InitSeqList(SeqList *list);
int ClearSeqList(SeqList *list);
int GetLength(SeqList *list);
bool IsEmpty(SeqList *list);
void InsertElem(SeqList *list, int index, int elem);
void DeleteElem(SeqList *list, int index, int *elem);
int LocateElem(SeqList *list, int *elem);
int MergeSeqList(SeqList *list1, SeqList *list2);
int ReverseSeqList(SeqList *list);
int GetMaxElem(SeqList *list);
int GetMinElem(SeqList *list);
