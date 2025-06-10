#ifndef ONLINE_STORE_H_INCLUDED
#define ONLINE_STORE_H_INCLUDED
#include <stdbool.h>
#include <time.h>


//Data of product

#define max1  100
#define max2 100

typedef struct data
{
 int id;
 char Category[100];
 int quantity;
 float Price;
 char datetime[25];
 int sales;
 float money;

}DataP;

//for nodes will enter in double linked list

typedef struct node
{
 struct node *next;
 struct node *prev;
 DataP data;    //struct of data  has a product

}Node;

//List

typedef struct list
{
 Node *head;
 Node *tail;
 int Size;

}List;


//--------------------------------
//functions

void displaymenu();

void createlist(List *l);

int  Emptylist (List *l);
int  Fulllist  (List *l);

int sizeList (List *l);

//---------------

int CheckId (List *l, int id);
void  Addproduct   (List *l, DataP d);
void Traverse_Add(List *l , void(*pf)(DataP d));

//---------------
int PosofID(List *l , int id);
void  Delete     (List *l, DataP *d);
void  DeleteATpos(List *l, int pos ,DataP *d);

//---------------

void Traverse(List *l , void(*pf)(DataP));

//---------------

void buy (List *l ,int pos  ,int quantity,DataP *data , DataP *sal );
void delete_if_quantity_zero(List *list);

//---------------

void ChangePrice(List *l ,int PosofID ,float NewPrice,DataP *data);

//---------------

void add_Quantity(List *l ,int pos ,int addQuantity, DataP *data);

//---------------

int remove_Quantity(List *l, int pos, int subquantity, DataP *data);

//---------------

void  InsertATpos(List *l, int pos ,DataP d);

//---------------

void Traverse(List *l , void(*pf)(DataP));

//---------------

void insertSorted(List* sortedList, DataP newData);
void sort_Quantity(List* l, List* sortedList);

//---------------

int checkCategory(List *list,  char *category);
void deleteProductsByCategory(List *l, char category[]);

//---------------

void read_category_with_spaces(char *category);

//---------------

int getIntegerInput();
bool getIntegerInput_1(int *result);

//---------------
bool checkIdInFile(const char *filename, int idToCheck);

//---------------
void readItemsFromFile(const char *filename, List *l , DataP tempd);

//---------------
void writeDataToFile(List *list, const char *filename) ;

//---------------
void getCurrentDate(char *dateString);

//---------------
void getCurrentDateTime(char *datetimeString);

//---------------
void readItemsFromFile_spc(const char *filename, List *l  );

//---------------
void writeDataToFile_spc(List *list, const char *filename);

//---------------
void sumSalesAndMoney(List *l , const char *filename);

//---------------
bool isQuantityGreater(List *list, int id, int thresholdQuantity) ;

//---------------
bool isQuantityEqual(List *list, int id, int targetQuantity);

//--------------
bool validateQuantityList(List *list, int id, int targetQuantity);


#endif // ONLINE_STORE_H_INCLUDED
