#include"online_store.h"
#include<stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <time.h>


void displaymenu()
{
 printf("\n----------------------Online Shopping Store--------------------\n");
 printf("\n1. Add product\n");
 printf("2. Delete product\n");
 printf("3. Show available products to buy with their quantity and price\n");
 printf("4. Buy a product\n");
 printf("5. Change the price of a product\n");
 printf("6. Add More Quantity\n");
 printf("7. Remove Quantity\n");
 printf("8. Show products in order\n");
 printf("9. Show products in most-recent order\n");
 printf("10.Show all products sorted by their quantities. (Low to High)\n");
 printf("11.Delete all products that belong to a specific category (allow the user to choose it)\n");
 printf("12.Show sales and purchashes\n");
 printf("13.Exit\n");
 printf("\nEnter your choice: \n");

}
//-------------------------------

void createlist(List *l)
{
 l->head=NULL;
 l->tail=NULL;
 l->Size=0;
}

//--------------------------------

int  Emptylist (List *l)
{
 return l->Size==0;
}

int  Fulllist  (List *l)
{
 return 0;
}

//------------------------------------------------------
//Add product      ((--------1--------))

//check id in list to achieve unique id

int CheckId (List *l, int id)
{
  Node *n=l->head;
  for(int i=0 ;i<l->Size;i++)
  {
      if (id != n->data.id)
      {
        n=n->next;
      }
     else
     {
       return 1;//when be same id in list
       break;
     }
  }

  return 0;// when be not same id in list
}



//--------------------------------
//Add product

void  Addproduct (List *l, DataP d)
{
  Node *n=(Node*)malloc(sizeof(Node));

  n->next=NULL;
  n->prev=NULL;

  n->data=d;

 if(l->Size==0) //empty list
    {
     l->head=n;
     l->tail=n;
    }
 else   //will add this node in tail
    {
    n->prev=l->tail;
    l->tail->next=n;
    l->tail=n;
    }
l->Size++;
}

//----------------
// display through Add Product

void Traverse_Add(List *l , void(*pf)(DataP d))
{
  Node *n2=l->head;
  if (!l->head)
  {
   return;
  }
  else
  {
  Node *n=l->head;
  for(int i=0 ;i<l->Size;i++)
    {
     (*pf)(n->data);
      n=n->next;
   }
 }
}

//--------------------------------------------------------
//Delete product        ((------2------))

int PosofID(List *l, int id)
{
    Node *n = l->head;
    int position = 0;


    while (n != NULL)
        {
        if (id == n->data.id)
         {
            return position;
         }

        n = n->next;
        position++;
    }

    return -1;
}

//-----------------

void Delete(List *l, DataP *d)
{

    if (l->head == NULL)
        {
          printf("( Alert ! ) is empty.\n");
          return;
        }

    *d = l->head->data;


    Node *temp = l->head->next;
    free(l->head);
    l->head = temp;

    if (l->head != NULL)
    {
      l->head->prev = NULL;
    }


    l->Size--;
}


void DeleteATpos(List *l, int pos, DataP *d)
{

    if (l->head == NULL)
    {
      printf("( Alert! ) Store is empty.\n");
      return;
    }


    if (pos < 0 || pos >= l->Size)
    {
      printf("Invalid position.\n");
      return;
    }

    Node *current = l->head;


    for (int i = 0; i < pos; i++)
    {
      current = current->next;
    }


    *d = current->data;


    if (current->prev != NULL)
    {
      current->prev->next = current->next;
    }
    else
    {
      l->head = current->next;
    }

    if (current->next != NULL)
    {
      current->next->prev = current->prev;
    }

    free(current);

    l->Size--;
}

//--------------------------------------------------------
//display product        ((------3------))

void Traverse(List *l , void(*pf)(DataP d))
{
  Node *n2=l->head;
  if (!l->head)
  {
   printf("( Alert! ) Store is empty!\n");
   return;
  }
  else
  {
  Node *n=l->head;
  for(int i=0 ;i<l->Size;i++)
    {
     (*pf)(n->data);
      n=n->next;
   }
 }
}

//--------------------------------------------------------
// Buy a product  ((------4------))

void buy(List* l, int pos, int quantity, DataP *data ,DataP *sal )
{
    if (l == NULL || l->head == NULL)
    {
        printf("\n( Alert! ) List is Empty\n");
        return;
    }

    Node* current = l->head;
    int i = 0;
    while (current != NULL && i < pos)
    {
        current = current->next;
        i++;
    }


    if (current == NULL)
    {
        printf("\nProduct not found at position %d\n", pos);
        return;
    }

    if (current->data.quantity < quantity)
    {

        printf("\n\n( Alert! ) Exceed the quantity that available\n");
        return;
    }
    printf("\nThe amount:%d         Total price: %.2f   \n",quantity, (quantity * current->data.Price) );
    current->data.quantity -= quantity;
    *data = current->data;

    //----------
    if(current->data.quantity > 0 )
    {
     getCurrentDateTime(current->data.datetime);
     printf("\n\nProduct that you buy..?");
     printf("\nid:%d   category:%s    Quantity:%d   Price:%.2f    date:%s\n",current->data.id,current->data.Category,current->data.quantity,current->data.Price , current->data.datetime);
    }
    else
    {
      printf("\n\nProduct that you buy..?");
      printf("\nid:%d   category:%s    Quantity:%d   Price:%.2f    date:%s\n",current->data.id,current->data.Category,current->data.quantity,current->data.Price , current->data.datetime);
      printf("\n\n( Alert! ) quantity of %s just has been Finished !\n" , current->data.Category);
    }

    sal->id = current->data.id;

    sal->quantity = quantity;

    sal->Price = (quantity * current->data.Price);

    strcpy(sal->Category, current->data.Category);

    strcpy(sal->datetime, current->data.datetime);





}

//-------------------------------------------
// Function check if all quantity 0 reurn 1

int allQuantitiesZero(List *list)
{
    Node *current = list->head;
    while (current != NULL) {
        if (current->data.quantity != 0)
        {
            return 0;
        }
        current = current->next;
    }
    return 1;
}

//-------------------------------------------
//function delete if quantity be zero (direct)

void delete_if_quantity_zero(List *list)
{
    Node *current = list->head;

    while (current != NULL)
        {
          Node *next_node = current->next;

          if (current->data.quantity == 0)
          {
            if (current == list->head)
            {

                list->head = current->next;


                if (list->head != NULL)
                {
                    list->head->prev = NULL;
                }
                else
                {
                    list->tail = NULL;
                }

            }
            else if (current == list->tail)
            {
                list->tail = current->prev;
                list->tail->next = NULL;
            }
            else
            {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }

            free(current);
            list->Size--;
        }
        current = next_node;
    }
}


//--------------------------------------------------------
// change price a product  ((------5------))
void ChangePrice(List *l ,int pos ,float NewPrice, DataP *data)
{
 Node *n=l->head;
 for(int i=0 ; i<pos;i++)
    {
      n=n->next;
    }
  n->data.Price=NewPrice;
  *data=n->data;

}

//--------------------------------------------------------
// Add quantity a product  ((------6------))

void add_Quantity(List *l ,int pos ,int addQuantity, DataP *data)
{
 Node *n=l->head;
 for(int i=0 ; i<pos;i++)
    {
      n=n->next;
    }
  n->data.quantity=n->data.quantity + addQuantity;
  *data=n->data;

}

//--------------------------------------------------------
// remove quantity a product  ((------7------))

int remove_Quantity(List *l, int pos, int subquantity, DataP *data  )
{
    Node *n = l->head;

    for (int i = 0; i < pos && n != NULL; i++)
    {
        n = n->next;
    }
    if (n != NULL)
    {
        if (n->data.quantity >= subquantity)
        {
            n->data.quantity -= subquantity;
            *data = n->data;
              return  1;


        }
        else if (n->data.quantity < subquantity)
        {

            return 0 ;

        }

    }
    else
    {
        printf("( Alert! ) Invalid position!\n");

    }
}


//--------------------------------------------------------
// Show products in order  ((------8------))


//the same to traverse function in question ((3)) but send function display to show with id


//--------------------------------------------------------
// Show products in most-recent order  ((------9------))

void RevTraverse(List *l , void(*pf)(DataP d))
{
   if (!l->head)
  {
   printf("( Alert !) Store is empty.\n");
   return;
  }
  else
  {
  Node *n=l->tail;
  for(int i=l->Size-1 ;i>= 0;i--)
    {
     (*pf)(n->data);
      n=n->prev;
    }
  }
}

//--------------------------------------------------------
// sort by quantity  ((------10------))

// insert in list that created as a temp to add in it the sorted item

void insertSorted(List* sortedList, DataP newData)
{
    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->data = newData;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (sortedList->head == NULL)
    {
        sortedList->head = newNode;
        sortedList->tail = newNode;
    }
    else
    {
        Node* current = sortedList->head;
        Node* prev = NULL;

        while (current != NULL && current->data.quantity < newData.quantity)
        {
            prev = current;
            current = current->next;
        }

        if (prev == NULL)
        {
            newNode->next = sortedList->head;
            sortedList->head->prev = newNode;
            sortedList->head = newNode;
        }
        else if (current == NULL)
        {
            prev->next = newNode;
            newNode->prev = prev;
            sortedList->tail = newNode;
        }
        else
        {
            prev->next = newNode;
            newNode->prev = prev;
            newNode->next = current;
            current->prev = newNode;
        }
    }
    sortedList->Size++;
}

//---------------------
// sort by Quantity

void sort_Quantity(List* l, List* sortedList)
{
    sortedList->head = NULL;
    sortedList->tail = NULL;
    sortedList->Size = 0;

    Node* current = l->head;

    while (current != NULL)
    {
        insertSorted(sortedList, current->data);
        current = current->next;
    }
}


//--------------------------------------------------------
// delete by category  ((------11------))

//check if category exist or not
int checkCategory(List *list,  char *category)
{
    Node *current = list->head;

    while (current != NULL)
    {
        if (strcmp(current->data.Category, category) == 0)
        {
            return 1;
        }
        current = current->next;
    }

    return 0;
}


//----------------------
//delete catedory

void deleteProductsByCategory(List *l, char category[])
{
    Node* current = l->head;
    while (current != NULL)
     {
        if (strcmp(current->data.Category, category) == 0)
         {
            Node *tmp = current;
            if (current == l->head)
            {
                l->head = current->next;
            }
            if (current == l->tail)
            {
                l->tail = current->prev;
            }
            if (current->prev != NULL)
            {
                current->prev->next = current->next;
            }
            if (current->next != NULL)
            {
                current->next->prev = current->prev;
            }


            DataP deleteData = current->data;
            printf("\n\nProduct that has been deleted is..?\n");
            printf("category:%s    Quantity:%d    Price:%.2f    \n", deleteData.Category, deleteData.quantity, deleteData.Price);


            current = current->next;
            free(tmp);
            l->Size--;
        }
        else
        {
            current = current->next;
        }
    }

}

//--------------------------------------------------------
// Exit  ((------12------))

// Exit

//--------------------------------------------------------
//---------------------------
//read category with space

void read_category_with_spaces(char *category)
{
    getchar();
    fgets(category, 50, stdin);
    category[strcspn(category, "\n")] = '\0';
}


//-----------------
//check if input is int or char

int getIntegerInput()
{
    int value;
    while (1)
    {

        if (scanf("%d", &value) == 1)
        {
            break;
        }
        else {
            printf("\n(Alert!) Please enter an integer number.\n");
            printf("\nEnter your choise: \n");
            while (getchar() != '\n');
        }
    }
    return value;
}

//-----------------
//check if input is int or char

bool getIntegerInput_1(int *result)
{

    if (scanf("%d", result) == 1)
    {
      return true;
    }
    else
    {
        while (getchar() != '\n');
        return false;
    }
}

//------------------------------
//Extra function

//insert at position

void  InsertATpos(List *l, int pos ,DataP d)
{
  Node*n=(Node*)malloc(sizeof(Node));

  Node*tmp=l->head;
  n->next=NULL;
  n->prev=NULL;
  n->data=d;

 if(l->Size ==0)
 {
   l->head=n;
   l->tail=n;
 }
 else if (pos==0)
 {
   n->next=l->head;
   l->head->prev=n;
   l->head=n;
 }
 else
 {     //will add this node in tail

  for(int i=0;i<pos-1;i++)
  {
    tmp=tmp->next;
  }

 n->prev=tmp;
 n->next=tmp->next;

 if(pos != l->Size)
 {
  tmp->next->prev=n;
  tmp->next=n;
 }
 l->Size++;
}
}
//-------------------
//size of list

int sizeList (List *l)
{
  return l->Size;
}



//----------------------------------------------
/*
bool checkIdInFile(const char *filename, int idToCheck)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        return false;
    }

    char line[100];
    int lineNumber = 0;
    int currentId = -1;
    while (fgets(line, sizeof(line), file) != NULL)
    {
     lineNumber++;
        if (lineNumber % 4 == 1)
        {

            if (sscanf(line, "id : %d", &currentId) != 1)
            {
                printf("Error parsing ID on line %d.\n", lineNumber);
                fclose(file);
                return false;
            }

            if (currentId == idToCheck)
            {
                fclose(file);
                return true;
            }
        }
    }

    fclose(file);
    return false;
}
*/

//------------------------
// check if id exist in file or not for unique
bool checkIdInFile(const char *filename, int idToCheck)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return false;
    }

    int currentId;
    bool idFound = false;
    char line[100];


    while (fgets(line, sizeof(line), file) != NULL)
        {

        if (sscanf(line, "Id : %d", &currentId) == 1)
        {

            if (currentId == idToCheck)
            {
                idFound = true;
                break;
            }
        }
    }

    fclose(file);
    return idFound;
}

//---------------
// readItemsFromFile and add to list

void readItemsFromFile(const char *filename, List *l , DataP tempd)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return;
    }

    char line[100];
    char category[50]; // Adjust size as needed
    int currentId, quantity;
    double price;
    char date[25];


    while (fgets(line, sizeof(line), file) != NULL)
    {
        if (sscanf(line, "Id : %d", &currentId) == 1)
        {
            if (fgets(line, sizeof(line), file) == NULL ||
                sscanf(line, "Category : %49[^\n]", category) != 1 ||
                fgets(line, sizeof(line), file) == NULL ||
                sscanf(line, "Quantity : %d", &quantity) != 1 ||
                fgets(line, sizeof(line), file) == NULL ||
                sscanf(line, "Price : %lf", &price) != 1 ||
                fgets(line, sizeof(line), file) == NULL ||
                sscanf(line, "date: %24[^\n]", date) != 1)

            {
                fprintf(stderr, "Error reading item details\n");
                fclose(file);
                return;
            }


            // Prepare a new DataP item
            DataP tempd;
            tempd.id = currentId;
            strcpy(tempd.Category, category);
            tempd.quantity = quantity;
            tempd.Price = price;
            strcpy(tempd.datetime, date);


            // Add the item to the list
            Addproduct(l, tempd);
        }
    }

    fclose(file);

}

//-----------------------
// Write data from list in to file

void writeDataToFile(List *list, const char *filename)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        perror("Error opening file");
        return;
    }

    Node *current = list->head;
    while (current != NULL)
    {
        DataP product = current->data;
        fprintf(file, "Id : %d\n", product.id);
        fprintf(file, "Category: %s\n", product.Category);
        fprintf(file, "Quantity: %d\n", product.quantity);
        fprintf(file, "Price: %.2f\n", product.Price);
        fprintf(file, "date: %s\n", product.datetime);
        fprintf(file, "\n"); // Separate entries with a blank line or other delimiter

        current = current->next;
    }

    fclose(file);
}


//----------------------------------------------------------------
//readItemsFromFile_spc

void readItemsFromFile_spc(const char *filename, List *l)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return;
    }

    char line[100];
    int currentId;
    int sales;
    float money;
    int sum1;
    int sum2;
    char cat[100];
    char date[25];

    while (fgets(line, sizeof(line), file) != NULL)
        {
        if (sscanf(line, "Id : %d", &currentId) == 1)
        {
            if ( fgets(line, sizeof(line), file) == NULL ||
                sscanf(line, "type: %s", &cat) != 1 ||
                fgets(line, sizeof(line), file) == NULL ||
                sscanf(line, "sales : %d", &sales ) != 1 ||
                fgets(line, sizeof(line), file) == NULL ||
                sscanf(line, "purchases : %f", &money) != 1||
                fgets(line, sizeof(line), file) == NULL ||
                sscanf(line, "date: %24[^\n]", date) != 1)
                {
                fprintf(stderr, "Error reading item details\n");
                fclose(file);
                return;
                }


            DataP tempd;
            tempd.id = currentId;
            tempd.sales = sales;
            tempd.money = money;
            strcpy(tempd.Category, cat);
            strcpy(tempd.datetime, date);



            Addproduct(l, tempd);
        }

    }

    fclose(file);
}

//-----------------------
// Write data from list in to file

void writeDataToFile_spc(List *list, const char *filename)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        perror("Error opening file");
        return;
    }

    Node *current = list->head;
    while (current != NULL)
    {
        DataP product = current->data;
        fprintf(file, "Id : %d\n", product.id);
        fprintf(file, "type: %s\n", product.Category);
        fprintf(file, "sales: %d\n", product.sales);
        fprintf(file, "purchases: %.2f\n", product.money);
        fprintf(file, "date: %s\n" , product.datetime);


        fprintf(file, "\n");

        current = current->next;
    }

    fclose(file);
}

//--------------------------------------------------------------
// date with hour

void getCurrentDateTime(char *datetimeString)
{
    time_t currentTime;
    struct tm *localTime;


    currentTime = time(NULL);


    localTime = localtime(&currentTime);


    strftime(datetimeString, 25, "%Y-%m-%d  %H:%M:%S", localTime);
}
//---------------------------------
//sumSalesAndMoney

void sumSalesAndMoney(List *l ,const char *filename )
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        perror("Error opening file");
        return;
    }
    int totalSales = 0;
    float totalMoney = 0.0;

    Node *current = l->head;
    while (current != NULL)
    {
        totalSales += current->data.sales;
        totalMoney += current->data.money;
        current = current->next;
    }
    fprintf(file, "Total sales: %d\n",totalSales );
    fprintf(file, "Total money: %.2f\n",totalMoney );
    fclose(file);
    printf("\nTotal sales: %d\n", totalSales);
    printf("Total money: %.2f\n", totalMoney);

}



//---------------------
bool isQuantityGreater(List *list, int id, int thresholdQuantity)
{
    Node *current = list->head;
    while (current != NULL)
    {
        if (current->data.id == id)
        {

            if (current->data.quantity  > thresholdQuantity)
            {
                return true;
            } else
            {
                return false;
            }
        }
        current = current->next;
    }


    return false;
}

//--------------------------------
bool isQuantityEqual(List *list, int id, int targetQuantity)
{
    Node *current = list->head;
    while (current != NULL)
        {
        if (current->data.id == id)
            {

            if (current->data.quantity == targetQuantity)
            {
                return true;
            } else
            {
                return false;
            }
        }
        current = current->next;
    }


    return false;
}


//-------------------
bool validateQuantityList(List *list, int id, int targetQuantity)
 {
    Node *current = list->head;

    while (current != NULL)
    {
        if (current->data.id == id)
            {

            if (current->data.quantity == targetQuantity || current->data.quantity > targetQuantity)
            {
                return true;
            } else
            {
                return false;
            }
        current = current->next;
    }


    return false;
}
 }


