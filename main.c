#include <stdio.h>
#include <stdlib.h>
#include"online_store.h"
#include <stdbool.h>
#include <time.h>

//display

void display( DataP d )
{
     printf("id:%d    category:%s    Quantity:%d    Price:%.2f    date:%s\n",d.id,d.Category,d.quantity,d.Price,d.datetime );
}

// show product without id
void display2( DataP d)
{

   printf("category:%s    Quantity:%d    Price:%.2f    date:%s\n",d.Category,d.quantity,d.Price,d.datetime);
}
//show sales and purchashes

void display3( DataP d)
{


   printf("id:%d    type:%s    sales:%d    purchases:%.2f    date:%s\n",d.id,d.Category,d.sales,d.money,d.datetime);

}


int main()
{
    FILE *data ;
    data = fopen("file.txt" , "a");
    FILE *data2 ;
    data2 = fopen("file2.txt" , "a");

    //show menu
    displaymenu();

    int x = getIntegerInput();
    int id;
    int pos;
    int quantity;
    float newprice;
    int addquantity;
    int subquantity;
    char category[100];
    char category2[100];
    char answer[4];
    char answer1[4];
    char answer2[4];
    const char *c = "file.txt";
    const char *c2 = "file2.txt";
    const char *c3 = "file3.txt";
    int chk=0;
    int addProductDone = 0;



    DataP d;
    DataP tempd;
    DataP sal;
    DataP s;
    // As temp for dat
    List l;
    createlist(&l);
    List temp;
    createlist(&temp);
    List sort;
    createlist(&sort);
    List sale;
    createlist(&sale);



    DataP delete;

  //scanf("%d", &x);

  //--------------
  //get data from file and add to list
  readItemsFromFile( c , &l , tempd );
  readItemsFromFile_spc(c2 , &sale );

while( x != 13   )
  {


  switch(x)
  {
   x =  getIntegerInput();
   //case 1 in do while loop to enter more than one product

do{

   case 1 : //Add product ((--------1-------))
    //loop on id to check is it exist or not
     printf("-------------------------\n");
     printf("What do you want to add ?\n\n");
     getCurrentDateTime(d.datetime);


    do {

        if (strcmp(answer, "yes") == 0 )
        {
         printf("-------------------------\n");
         printf("What do you want to add ?\n\n");
        }


         printf("Products..?\n");
         Traverse_Add(&l  , &display );

        // check id is int or no
        //-----------
        while (1)
        {
        printf("\nEnter product id: \n");


        if (scanf("%d", &d.id) == 1 && d.id > -1)
        {
            break;
        }

        else
        {
           printf("\n( Alert! ) Please enter an integer number..?\n");
            while (getchar() != '\n');
        }

       }
       //-----------


        if (CheckId(&l,d.id)==1 || checkIdInFile(c , d.id))
            {
              printf("\n( Alert! ) This Product ID: %d already exists!\n" , d.id);

              do{
                  printf("\nDo you want to try another ID (yes/no)?\n");
                  scanf("%s", answer);


                }while (strcmp(answer, "yes") != 0 && strcmp(answer, "no") != 0);



            }
            /*else
            {
              data = fopen("file.txt", "a");
              if (data != NULL)
              {
                 fprintf(data, "Id : %d\n", d.id);
              }

            }*/

    } while ((CheckId(&l,d.id)==1 && strcmp(answer, "no") != 0) || (checkIdInFile(c , d.id) && strcmp(answer, "no") != 0));






    if (strcmp(answer, "yes") == 0)
    {


          do {



        if (CheckId(&l,d.id)==1 || checkIdInFile(c , d.id))
            {
              printf("( Alert! )This Product ID: %d already exists!\n", d.id);

              do{
                  printf("\nDo you want to try another ID (yes/no)?\n");
                  scanf("%s", answer);


                }while (strcmp(answer, "yes") != 0 && strcmp(answer, "no") != 0);

            if (strcmp(answer, "no") == 0)
                {
                  displaymenu();
                while (1)
                  {

                if (scanf("%d", &x) == 1 && x > -1)
                {
                 break;
                }


               else
               {
                printf("\n( Alert! ) Please enter an integer number..?\n\n");
                while (getchar() != '\n');
               }

                }
                  // to recycle loop another time
                  char answer = "yes";
                  break;

                }

            }
            /*else
            {
              data = fopen("file.txt", "a");
              if (data != NULL)
              {
                 fprintf(data, "Id : %d\n", d.id);
              }

            }*/

    } while ((CheckId(&l,d.id)==1 && strcmp(answer, "no") != 0) || (checkIdInFile(c , d.id) && strcmp(answer, "no") != 0));


        }
             if (strcmp(answer, "no") == 0 && checkIdInFile(c , d.id)  || CheckId(&l,d.id)==1)
                {
                  displaymenu();

                  while (1)
                  {

                if (scanf("%d", &x) == 1 && x > -1)
                {


                 break;

                }


               else
               {
                printf("\n( Alert! ) Please enter an integer number..?\n\n");
                while (getchar() != '\n');
               }

          }
                  break;
                }





      printf("\nEnter product category: \n");
      //scanf("%s",& d.Category);
      read_category_with_spaces(d.Category);
      /*fprintf(data ,"Category: %s" , d.Category);
      fprintf(data , "\n");*/






      //------------
       while (1)
        {
      printf("\nEnter product quantity: \n");


        if (scanf("%d", &d.quantity) == 1 && d.quantity >= 1)
        {
            /*data = fopen("file.txt", "a");
              if (data != NULL)
              {
                 fprintf(data, "Quantity : %d\n", d.quantity);
              }*/
            break;
        }


        else
        {
           printf("\n( Alert! ) Please enter an integer number..?\n");
            while (getchar() != '\n');
        }

       }



      //-------------
       while (1)
        {
         printf("\nEnter product price: \n");


        if (scanf("%f", &d.Price) == 1 && d.Price >= 1)
        {
            /*data = fopen("file.txt", "a");
              if (data != NULL)
              {
                 fprintf(data, "Price : %.2f\n", d.Price);


              }*/
            break;
        }


        else
        {
           printf("\n( Alert! ) Please enter an integer number..?\n");
            while (getchar() != '\n');
        }

       }



      Addproduct(&l,d);

    //loop to ask if you want to Add another Product or not

    do {
         printf("\n\nDo you want to Add another Product (yes/no)?\n");
         scanf("%s", answer1);

       }while (strcmp(answer1, "yes") != 0 && strcmp(answer1, "no") != 0);

    // if answer is no

    if (strcmp(answer1, "no") == 0)
        {

        // displaymenu();
        //scanf("%d" , &x);

        displaymenu();
        while (1)
        {



        if (scanf("%d", &x) == 1)
        {
            break;
        }
         else if (scanf("%d", &x) != 1)
        {
            printf("\n( Alert! ) Please enter an integer number..?\n\n");
            while (getchar() != '\n');
            continue;
        }

        else
        {
           printf("\n( Alert! ) Please enter an integer number..?\n\n");
           printf("\nEnter your choise:\n");
            while (getchar() != '\n');
        }

       }
       break;
   }





 } while (strcmp(answer1, "yes") != 0 && strcmp(answer1, "no") == 0 );


  break;


//----------------------------------------------------------------------------
// Case 2: Delete product

 case 2:
 {
    printf("---------------------------\n");
    if(!Emptylist(&l))
    {
    printf("What do you want to delete ?\n\n");
    }
    if (!Emptylist(&l))
    {
        do
        {
            //display
            printf("\n");
            Traverse(&l, &display);

            //get Id
            while (1)
             {
               printf("\n\nEnter ID of Product to delete: ");


              if (scanf("%d", &id) == 1 && id > -1)
              {
               break;
              }


             else
             {
              printf("\n( Alert! ) Please enter an integer number..?\n");
              while (getchar() != '\n');
             }

            }


            do
            {
                // Check if id exists in the list
                if (CheckId(&l, id) == 1)
                {

                    int position = PosofID(&l, id);

                    if (position != -1)
                    {

                        DataP delete;
                        DeleteATpos(&l, position, &delete);
                        printf("\n\nProduct that has been deleted is..?\n");
                        printf("ID: %d   Category: %s   Quantity: %d   Price: %.2f\n", delete.id, delete.Category, delete.quantity, delete.Price);
                        printf("\n---------------");
                        printf("\nRemain products after delete product..?\n\n");
                        Traverse(&l , &display);
                        printf("---------------");
                    }
                    else
                    {
                        printf("\n( Alert! )This product does not exist!!\n");

                    }

                }
                else
                {
                    printf("\n( Alert! ) Product with ID %d does not exist!!\n", id);
                }


                printf("\n\nDo you want to delete Product (yes/no)? ");
                scanf("%s", answer1);
                break;

            } while (strcmp(answer1, "yes") == 0);
             if (strcmp(answer1, "no") == 0)
             {

              //displaymenu();
              //scanf("%d",&x);
               displaymenu();
              while (1)
               {



               if (scanf("%d", &x) == 1)
                {
                   break;
                }
               else if (scanf("%d", &x) != 1)
               {
                 printf("\n( Alert! ) Please enter an integer number..?\n\n");
                  while (getchar() != '\n');
                 continue;
               }

              else
               {
                printf("\n( Alert! ) Please enter an integer number..?\n\n");
                printf("\nEnter your choise:\n");
                while (getchar() != '\n');
               }

             }
               break;


             }
         break;

           break;
        } while (1);
       break;
    }

    else
    {
        printf("\n( Alert! ) List is Empty!\n");
        //displaymenu();
        //scanf("%d", &x);
            displaymenu();
        while (1)
        {



        if (scanf("%d", &x) == 1)
        {
            break;
        }
         else if (scanf("%d", &x) != 1)
        {
            printf("\n( Alert! ) Please enter an integer number..?\n\n");
            while (getchar() != '\n');
            continue;
        }

        else
        {
           printf("\n( Alert! ) Please enter an integer number..?\n\n");
           printf("\nEnter your choise:\n");
            while (getchar() != '\n');
        }

       }
       break;


        break;
    }

}

//----------------------------------------------------------------------------

case 3:   //display product ((--------3-------))
    printf("---------------------------------\n");
    printf("Available products in the store ?\n\n");
    Traverse(&l,&display2);
    //displaymenu();
    //scanf("%d",&x);


    displaymenu();
        while (1)
        {



        if (scanf("%d", &x) == 1)
        {
            break;
        }
         else if (scanf("%d", &x) != 1)
        {
            printf("\n( Alert! ) Please enter an integer number..?\n\n");
            while (getchar() != '\n');
            continue;
        }

        else
        {
           printf("\n( Alert! ) Please enter an integer number..?\n\n");
           printf("\nEnter your choise:\n");
            while (getchar() != '\n');
        }

       }
       break;



    break;

//----------------------------------------------------------------------------

   case 4 : //buy product ((--------4-------))

    //loop on id to check is it exist or not
   if(!Emptylist(&l))
   {
    if(allQuantitiesZero(&l) == 1  )
        {
           printf("-------------------------");
           printf("\nWhat do you want to buy ?\n");
           printf("\n") ;
           Traverse(&l,&display);
           printf("\n( Sorry!! ) All quantity has been Finished !\n");
           //displaymenu();
           //scanf("%d",&x);

            displaymenu();
                  while (1)
                  {

                     if (scanf("%d", &x) == 1)
                     {
                           break;
                     }
                    else if (scanf("%d", &x) != 1)
                     {
                       printf("\n( Alert! ) Please enter an integer number..?\n\n");
                       while (getchar() != '\n');
                       continue;
                     }

                     else
                      {
                         printf("\n( Alert! ) Please enter an integer number..?\n\n");
                         printf("\nEnter your choise:\n");
                         while (getchar() != '\n');
                      }

                }
                  break;

           break;
        }

    do {



         printf("-------------------------");
         printf("\nWhat do you want to buy ?\n");
         printf("\n") ;
         Traverse(&l,&display);

            while (1)
             {
                printf("\nEnter ID of Product to buy\n") ;


              if (scanf("%d", &id) == 1 && id > -1 )
              {
               break;
              }


             else
             {
              printf("\n( Alert! ) Please enter an integer number..?\n");
              while (getchar() != '\n');
             }

            }


        if (CheckId(&l,d.id)==1 || x==4)
            {
              if(PosofID(&l, id) != -1)
               {

                  while (1)
                  {
                    printf("\nEnter the quantity:\n");


                   if (scanf("%d", &quantity) == 1 && quantity  >= 1)
                    {
                      break;
                    }


                   else
                   {
                     printf("\n( Alert! ) Please enter an integer number..?\n");
                     while (getchar() != '\n');
                   }

                   }


                  buy(&l,PosofID(&l,id),quantity,&delete , &sal );
                  chk = 1;

                  //delete_if_quantity_zero(&l);




                  break;

               }
               else
               {
                 printf("\n( Alert! ) This Product Not Exist\n");
                 break;
               }

              do{
                  printf("\nDo you want to try another ID (yes/no)?\n");
                  scanf("%s", answer);

                }while (strcmp(answer, "yes") != 0 && strcmp(answer, "no") != 0 );

            if (strcmp(answer, "no") == 0)
                {
                  //displaymenu();
                  //scanf("%d",&x);
                   displaymenu();
                  while (1)
                  {

                     if (scanf("%d", &x) == 1)
                     {
                           break;
                     }
                    else if (scanf("%d", &x) != 1)
                     {
                       printf("\n( Alert! ) Please enter an integer number..?\n\n");
                       while (getchar() != '\n');
                       continue;
                     }

                     else
                      {
                         printf("\n( Alert! ) Please enter an integer number..?\n\n");
                         printf("\nEnter your choise:\n");
                         while (getchar() != '\n');
                      }

                }
                  break;
                  break;


                }
            }
    } while (CheckId(&l,d.id)==1 && strcmp(answer, "no") == 0 );




    do {

         printf("\n\nDo you want to buy Product (yes/no)?\n");
         scanf("%s", answer1);

       }while (strcmp(answer1, "yes") != 0 && strcmp(answer1, "no") != 0  );

    // if answer is yes

    if (strcmp(answer1, "yes") == 0 )
    {
     s.id = sal.id;
     s.sales=sal.quantity;
     s.money=sal.Price;
     strcpy(s.Category,  sal.Category);
     strcpy(s.datetime , sal.datetime);



     if(chk==1  && validateQuantityList(&l , s.id , quantity) || quantity== s.sales&& chk==1  )
     {

      Addproduct(&sale , s);
      chk=0;
     }

   }

    // if answer is no

    if (strcmp(answer1, "no") == 0 )
        {

         //displaymenu();
         //scanf("%d",&x);
          displaymenu();
                  while (1)
                  {

                     if (scanf("%d", &x) == 1)
                     {
                           break;
                     }
                    else if (scanf("%d", &x) != 1)
                     {
                       printf("\n( Alert! ) Please enter an integer number..?\n\n");
                       while (getchar() != '\n');
                       continue;
                     }

                     else
                      {
                         printf("\n( Alert! ) Please enter an integer number..?\n\n");
                         printf("\nEnter your choise:\n");
                         while (getchar() != '\n');
                      }

                }
                  break;
                  break;

       }

   }
   else
   {
         printf("\n( Alert! ) Store is Empty !\n");
         //displaymenu();
         //scanf("%d",&x);

          displaymenu();
                  while (1)
                  {

                     if (scanf("%d", &x) == 1)
                     {
                           break;
                     }
                    else if (scanf("%d", &x) != 1)
                     {
                       printf("\n( Alert! ) Please enter an integer number..?\n\n");
                       while (getchar() != '\n');
                       continue;
                     }

                     else
                      {
                         printf("\n( Alert! ) Please enter an integer number..?\n\n");
                         printf("\nEnter your choise:\n");
                         while (getchar() != '\n');
                      }

                }
                  break;



         break;
   }

  chk = 1;


  break;

//----------------------------------------------------------------------------

// change price of product

 case 5 : //change price of product ((--------5-------))

   //loop on id to check is it exist or not
  if (!Emptylist(&l))
  {

    do {
         printf("-------------------------------------");
         printf("\nWhat do you want to change it price ?\n\n");
         printf("\n");
         Traverse(&l,&display);


         while (1)
               {
                printf("\n\nEnter ID of Product to change price: \n") ;


                if (scanf("%d", &id) == 1 && id > -1)
                {
                 break;
                }


               else
               {
                printf("\n( Alert! ) Please enter an integer number..?\n");
                while (getchar() != '\n');
               }

              }

        if (CheckId(&l,d.id)==1 || x ==5)
        {
            if(PosofID(&l, id) != -1)
            {

              while (1)
               {
                printf("\nEnter new price:\n");


                if (scanf("%f", &newprice) == 1 && newprice >= 1)
                {
                 break;
                }


               else
               {
                printf("\n( Alert! ) Please enter an integer number..?\n");
                while (getchar() != '\n');
               }

              }


              ChangePrice(&l,PosofID(&l,id),newprice,&delete);
              printf("\n\nproduct after change it price..?");
              printf("\nid:%d   category:%s    Quantity:%d   Price:%.2f   \n",delete.id,delete.Category,delete.quantity,delete.Price);
              printf("\n---------------");
              printf("\nproducts after change product id: ' %d ' price..?\n\n" , id);
              Traverse(&l , &display);
              printf("---------------");
              break;
            }
        else
        {
          printf("\n( Alert! ) this product not exist!!\n");
          break;
        }

              do{
                  printf("\nDo you want to try another ID (yes/no)?\n");
                  scanf("%s", answer);


                }while (strcmp(answer, "yes") != 0 && strcmp(answer, "no") != 0);

            if (strcmp(answer, "no") == 0)
                {
                  //displaymenu();
                  //scanf("%d",&x);

                   displaymenu();
                  while (1)
                  {

                     if (scanf("%d", &x) == 1)
                     {
                           break;
                     }
                    else if (scanf("%d", &x) != 1)
                     {
                       printf("\n( Alert! ) Please enter an integer number..?\n\n");
                       while (getchar() != '\n');
                       continue;
                     }

                     else
                      {
                         printf("\n( Alert! ) Please enter an integer number..?\n\n");
                         printf("\nEnter your choise:\n");
                         while (getchar() != '\n');
                      }

                }
                  break;

                  break;
                }
            }
    } while (CheckId(&l,d.id)==1 && strcmp(answer, "no") == 0);


    do {
         printf("\n\nDo you want to change price for Product (yes/no)?\n");
         scanf("%s", answer1);

       }while (strcmp(answer1, "yes") != 0 && strcmp(answer1, "no") != 0);

    // if answer is no

    if (strcmp(answer1, "no") == 0)
        {

         //displaymenu();
         //scanf("%d",&x);

          displaymenu();
                  while (1)
                  {

                     if (scanf("%d", &x) == 1)
                     {
                           break;
                     }
                    else if (scanf("%d", &x) != 1)
                     {
                       printf("\n( Alert! ) Please enter an integer number..?\n\n");
                       while (getchar() != '\n');
                       continue;
                     }

                     else
                      {
                         printf("\n( Alert! ) Please enter an integer number..?\n\n");
                         printf("\nEnter your choise:\n");
                         while (getchar() != '\n');
                      }

                }
                  break;

         break;

       }


   }else
   {
         printf("\n( Alert! ) Store is Empty !\n");
         //displaymenu();
         //scanf("%d",&x);
          displaymenu();
                  while (1)
                  {

                     if (scanf("%d", &x) == 1)
                     {
                           break;
                     }
                    else if (scanf("%d", &x) != 1)
                     {
                       printf("\n( Alert! ) Please enter an integer number..?\n\n");
                       while (getchar() != '\n');
                       continue;
                     }

                     else
                      {
                         printf("\n( Alert! ) Please enter an integer number..?\n\n");
                         printf("\nEnter your choise:\n");
                         while (getchar() != '\n');
                      }

                }
                  break;
         break;
   }


  break;

//----------------------------------------------------------------------------

   case 6 : //Add more quantity ((--------6-------))

   //loop on id to check is it exist or not
  if (!Emptylist(&l))
  {

    do {
         printf("-------------------------------------");
         printf("\nWhat Quantities do you want to Add ?\n\n");
         printf("\n");
         Traverse(&l,&display);

         while (1)
               {
                printf("\n\nEnter ID of Product to Add quantity: \n") ;


                if (scanf("%d", &id) == 1 && id > -1 )
                {
                 break;
                }


               else
               {
                printf("\n( Alert! ) Please enter an integer number..?\n");
                while (getchar() != '\n');
               }

              }

        if (CheckId(&l,d.id)==1 || x==6)
        {
            if(PosofID(&l, id) != -1)
            {

               while (1)
               {
                 printf("\nEnter Quanity:\n") ;


                if (scanf("%d", &addquantity) == 1 && addquantity >=  1)
                {
                 break;
                }


               else
               {
                printf("\n( Alert! ) Please enter an integer number..?\n");
                while (getchar() != '\n');
               }

              }

              add_Quantity(&l,PosofID(&l,id),addquantity,&delete);
              printf("\n\nproduct after Add more quantity..?");
              printf("\nid:%d   category:%s    Quantity:%d   Price:%.2f   \n",delete.id,delete.Category,delete.quantity,delete.Price);
              printf("\n---------------");
              printf("\nproducts after Add quantities on id: ' %d '..?\n\n", id);
              Traverse(&l , &display);
              printf("---------------");
              break;
            }
        else
        {
          printf("\n( Alert! ) This product not exist!!\n");
          break;
        }

              do{
                  printf("\nDo you want to try another ID (yes/no)?\n");
                  scanf("%s", answer);


                }while (strcmp(answer, "yes") != 0 && strcmp(answer, "no") != 0);

            if (strcmp(answer, "no") == 0)
                {
                  //displaymenu();
                  //scanf("%d",&x);

                   displaymenu();
                  while (1)
                  {

                     if (scanf("%d", &x) == 1)
                     {
                           break;
                     }
                    else if (scanf("%d", &x) != 1)
                     {
                       printf("\n( Alert! ) Please enter an integer number..?\n\n");
                       while (getchar() != '\n');
                       continue;
                     }

                     else
                      {
                         printf("\n( Alert! ) Please enter an integer number..?\n\n");
                         printf("\nEnter your choise:\n");
                         while (getchar() != '\n');
                      }

                }
                  break;

                  break;
                }
            }
    } while (CheckId(&l,d.id)==1 && strcmp(answer, "no") == 0);


    do {
         printf("\n\nDo you want to Add more quantity (yes/no)?\n");
         scanf("%s", answer1);

       }while (strcmp(answer1, "yes") != 0 && strcmp(answer1, "no") != 0);

    // if answer is no

    if (strcmp(answer1, "no") == 0)
        {

         //displaymenu();
         //scanf("%d",&x);

          displaymenu();
                  while (1)
                  {

                     if (scanf("%d", &x) == 1)
                     {
                           break;
                     }
                    else if (scanf("%d", &x) != 1)
                     {
                       printf("\n( Alert! ) Please enter an integer number..?\n\n");
                       while (getchar() != '\n');
                       continue;
                     }

                     else
                      {
                         printf("\n( Alert! ) Please enter an integer number..?\n\n");
                         printf("\nEnter your choise:\n");
                         while (getchar() != '\n');
                      }

                }
                  break;

         break;

       }


   }else
   {
         printf("\n( Alert! ) Store is Empty !\n");
         //displaymenu();
         //scanf("%d",&x);

          displaymenu();
                  while (1)
                  {

                     if (scanf("%d", &x) == 1)
                     {
                           break;
                     }
                    else if (scanf("%d", &x) != 1)
                     {
                       printf("\n( Alert! ) Please enter an integer number..?\n\n");
                       while (getchar() != '\n');
                       continue;
                     }

                     else
                      {
                         printf("\n( Alert! ) Please enter an integer number..?\n\n");
                         printf("\nEnter your choise:\n");
                         while (getchar() != '\n');
                      }

                }
                  break;

         break;
   }


  break;


//----------------------------------------------------------------------------

   case 7 : //remove more quantity ((--------7-------))

   //loop on id to check is it exist or not
  if (!Emptylist(&l))
  {

    do {
         printf("-------------------------------------");
         printf("\nWhat Quantities do you want to Remove ?\n\n");
         printf("\n");
         Traverse(&l,&display);


        while (1)
               {
                  printf("\n\nEnter ID of Product to Remove quantity: \n") ;


                if (scanf("%d", &id) == 1 && id > -1 )
                {
                 break;
                }


               else
               {
                printf("\n( Alert! ) Please enter an integer number..?\n");
                while (getchar() != '\n');
               }

              }

        if (CheckId(&l,d.id)==1 || x==7)
        {
            if(PosofID(&l, id) != -1)
            {

                while (1)
               {
                 printf("\nEnter Quanity:\n");


                if (scanf("%d", &subquantity) == 1 && subquantity >= 1)
                {
                 break;
                }


               else
               {
                printf("\n( Alert! ) Please enter an integer number..?\n");
                while (getchar() != '\n');
               }

              };

               int x = remove_Quantity(&l,PosofID(&l,id),subquantity,&delete );
                if (x == 1)
                {

                printf("\n\nproduct after remove quantity..?");
                printf("\nid:%d   category:%s    Quantity:%d   Price:%.2f   \n",delete.id,delete.Category,delete.quantity,delete.Price);
                printf("\n---------------");
                printf("\nproducts after remove quantities on id: ' %d '..?\n\n", id);
                Traverse(&l , &display);
                printf("---------------");
                break;

                }
                else if ( x == 0 )
                {
                   printf("\n( Alert! ) Exceed the available quantity!\n");
                   break;

                }

            }
        else
        {
          printf("\n( Alert! ) This product not exist!!\n");
          break;
        }

              do{
                  printf("\nDo you want to try another ID (yes/no)?\n");
                  scanf("%s", answer);


                }while (strcmp(answer, "yes") != 0 && strcmp(answer, "no") != 0 );

            if (strcmp(answer, "no") == 0)
                {
                  //displaymenu();
                  //scanf("%d",&x);

                   displaymenu();
                  while (1)
                  {

                     if (scanf("%d", &x) == 1)
                     {
                           break;
                     }
                    else if (scanf("%d", &x) != 1)
                     {
                       printf("\n( Alert! ) Please enter an integer number..?\n\n");
                       while (getchar() != '\n');
                       continue;
                     }

                     else
                      {
                         printf("\n( Alert! ) Please enter an integer number..?\n\n");
                         printf("\nEnter your choise:\n");
                         while (getchar() != '\n');
                      }

                }
                  break;

                  break;
                }
            }
    } while (CheckId(&l,d.id)==1 && strcmp(answer, "no") == 0 );


    do {
         printf("\n\nDo you want to remove more  quantity (yes/no)?\n");
         scanf("%s", answer1);

       }while (strcmp(answer1, "yes") != 0 && strcmp(answer1, "no") != 0);

    // if answer is no

    if (strcmp(answer1, "no") == 0)
        {

         //displaymenu();
         //scanf("%d",&x);

          displaymenu();
                  while (1)
                  {

                     if (scanf("%d", &x) == 1)
                     {
                           break;
                     }
                    else if (scanf("%d", &x) != 1)
                     {
                       printf("\n( Alert! ) Please enter an integer number..?\n\n");
                       while (getchar() != '\n');
                       continue;
                     }

                     else
                      {
                         printf("\n( Alert! ) Please enter an integer number..?\n\n");
                         printf("\nEnter your choise:\n");
                         while (getchar() != '\n');
                      }

                }
                  break;


         break;

       }


   }else
   {
         printf("\n( Alert! ) Store is Empty !\n");
         //displaymenu();
         //scanf("%d",&x);

          displaymenu();
                  while (1)
                  {

                     if (scanf("%d", &x) == 1)
                     {
                           break;
                     }
                    else if (scanf("%d", &x) != 1)
                     {
                       printf("\n( Alert! ) Please enter an integer number..?\n\n");
                       while (getchar() != '\n');
                       continue;
                     }

                     else
                      {
                         printf("\n( Alert! ) Please enter an integer number..?\n\n");
                         printf("\nEnter your choise:\n");
                         while (getchar() != '\n');
                      }

                }
                  break;

         break;
   }


  break;


//----------------------------------------------------------------------------

 case 8:   //Show products in order ((--------8-------))
   printf("------------------------------\n");
   printf("Available products  in order ?\n");
   printf("\n");
   Traverse(&l,&display);
   //displaymenu();
   //scanf("%d",&x);

    displaymenu();
                  while (1)
                  {

                     if (scanf("%d", &x) == 1)
                     {
                           break;
                     }
                    else if (scanf("%d", &x) != 1)
                     {
                       printf("\n( Alert! ) Please enter an integer number..?\n\n");
                       while (getchar() != '\n');
                       continue;
                     }

                     else
                      {
                         printf("\n( Alert! ) Please enter an integer number..?\n\n");
                         printf("\nEnter your choise:\n");
                         while (getchar() != '\n');
                      }

                }
                  break;

   break;

//----------------------------------------------------------------------------

 case 9:  // Show products in most-recent order ((--------9-------))
     printf("-----------------------------------------\n");
     printf("Available products in most-recent order ?\n");
     printf("\n");
     RevTraverse(&l , &display);
     //displaymenu();
     //scanf("%d",&x);
      displaymenu();
                  while (1)
                  {

                     if (scanf("%d", &x) == 1)
                     {
                           break;
                     }
                    else if (scanf("%d", &x) != 1)
                     {
                       printf("\n( Alert! ) Please enter an integer number..?\n\n");
                       while (getchar() != '\n');
                       continue;
                     }

                     else
                      {
                         printf("\n( Alert! ) Please enter an integer number..?\n\n");
                         printf("\nEnter your choise:\n");
                         while (getchar() != '\n');
                      }

                }
                  break;

     break;

//----------------------------------------------------------------------------

 case 10:  // Show all products sorted by their quantities. (Low to High)

   printf("--------------------------------------------------------------\n");
   printf("Available products sorted by their quantities. (Low to High) ?\n\n");
   sort_Quantity(&l , &sort);
   Traverse(&sort , &display2);
   //displaymenu();
   //scanf("%d",&x);

    displaymenu();
                  while (1)
                  {

                     if (scanf("%d", &x) == 1)
                     {
                           break;
                     }
                    else if (scanf("%d", &x) != 1)
                     {
                       printf("\n( Alert! ) Please enter an integer number..?\n\n");
                       while (getchar() != '\n');
                       continue;
                     }

                     else
                      {
                         printf("\n( Alert! ) Please enter an integer number..?\n\n");
                         printf("\nEnter your choise:\n");
                         while (getchar() != '\n');
                      }

                }
                  break;

   break;




//----------------------------------------------------------------------------

 case 11: //Delete all products that belong to a specific category (allow the user to choose it).
 {
    if (!Emptylist(&l))
     {
      do
       {
         printf("-------------------------------------");
         printf("\nWhat category do you want to delete ?\n\n");
         //display
         Traverse(&l, &display2);

        //get category and search about id
         printf("\nEnter category of Product to delete: ");
         //scanf("%s", &category2);
         read_category_with_spaces(category2);
      do
       {
        // Check if category exists in the list
        if (checkCategory(&l, category2) == 1)
         {

            deleteProductsByCategory(&l , category2);
            printf("\n---------------");
            printf("\nRemain products after delete category..?\n\n");
            Traverse(&l , &display2);
            printf("---------------");


         }
         else
         {
           printf("\n\n( Alert! )Product with category %s does not exist!\n", category2);
         }


          printf("\n\nDo you want to delete Product (yes/no)? ");
          scanf("%s", answer1);
          break;

      } while (strcmp(answer1, "yes") == 0);
       if (strcmp(answer1, "no") == 0)
        {

         //displaymenu();
         //scanf("%d",&x);

          displaymenu();
                  while (1)
                  {

                     if (scanf("%d", &x) == 1)
                     {
                           break;
                     }
                    else if (scanf("%d", &x) != 1)
                     {
                       printf("\n( Alert! ) Please enter an integer number..?\n\n");
                       while (getchar() != '\n');
                       continue;
                     }

                     else
                      {
                         printf("\n( Alert! ) Please enter an integer number..?\n\n");
                         printf("\nEnter your choise:\n");
                         while (getchar() != '\n');
                      }

                }
                  break;


         break;

       }


        break;
      } while (1);
        break;
    }

    else
    {
     printf("\n( Alert! ) Store is Empty!\n");
     //displaymenu();
     //scanf("%d", &x);

      displaymenu();
                  while (1)
                  {

                     if (scanf("%d", &x) == 1)
                     {
                           break;
                     }
                    else if (scanf("%d", &x) != 1)
                     {
                       printf("\n( Alert! ) Please enter an integer number..?\n\n");
                       while (getchar() != '\n');
                       continue;
                     }

                     else
                      {
                         printf("\n( Alert! ) Please enter an integer number..?\n\n");
                         printf("\nEnter your choise:\n");
                         while (getchar() != '\n');
                      }

                }
                  break;

     break;
    }

}

//-------------------------------------------------------------------

case 12:   //display sales  ((--------12-------))
    printf("---------------------------------\n");
    printf("Sales and Purchashes in the store ?\n\n");


    //displaymenu();
    //scanf("%d",&x);




    s.id = sal.id;
    s.sales=sal.quantity;
    s.money=sal.Price;
    strcpy(s.Category,  sal.Category);
    strcpy(s.datetime , sal.datetime);



    if(chk==1  && validateQuantityList(&l , s.id , quantity) || quantity== s.sales&& chk==1  )
    {

    Addproduct(&sale , s);
      chk=0;
    }


    Traverse(&sale,&display3);
    sumSalesAndMoney(&sale , c3);

    displaymenu();
        while (1)
        {



        if (scanf("%d", &x) == 1)
        {
            break;
        }
         else if (scanf("%d", &x) != 1)
        {
            printf("\n( Alert! ) Please enter an integer number..?\n\n");
            while (getchar() != '\n');
            continue;
        }

        else
        {
           printf("\n( Alert! ) Please enter an integer number..?\n\n");
           printf("\nEnter your choise:\n");
            while (getchar() != '\n');
        }

       }
       break;



    break;
 //----------------------------------------------------------------------------

 case 13:

    exit(1);


 //

 default:
            printf("\n( Alert! ) invalid input !! \n");
            //displaymenu();
            //scanf("%d", &x);

             displaymenu();
                  while (1)
                  {

                     if (scanf("%d", &x) == 1)
                     {
                           break;
                     }
                    else if (scanf("%d", &x) != 1)
                     {
                       printf("\n( Alert! ) Please enter an integer number..?\n\n");
                       while (getchar() != '\n');
                       continue;
                     }

                     else
                      {
                         printf("\n( Alert! ) Please enter an integer number..?\n\n");
                         printf("\nEnter your choise:\n");
                         while (getchar() != '\n');
                      }

                }
                  break;
            break;



   }


 }
   writeDataToFile(&l , c);
   writeDataToFile_spc(&sale , c2 );

}




