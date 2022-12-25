#include <stdio.h>
#include <stdlib.h>
#include "conio2.h"
#include "Car.h"

int main()
{
    int i;
    int type,k,choice;
    int result;
    User *usr;
    gotoxy(25,10);
    textcolor(LIGHTCYAN);
    printf("WELCOME TO CAR RENTAL SYSTEM");
    gotoxy(20,13);
    textcolor(YELLOW);
    printf("*RENT A CAR AND GO WHEREVER YOU NEED*");
    textcolor(YELLOW);
    getch();
    while(1)
    {
      clrscr();
      gotoxy(1,2);
      textcolor(GREEN);
      for(i=0;i<80;i++)
        printf("*");
      gotoxy(1,4);
      for(i=0;i<80;i++)
        printf("*");
      gotoxy(32,3);
      textcolor(LIGHTRED);
      printf("CAR RENTAL SYSTEM");
      textcolor(LIGHTCYAN);
      gotoxy(1,8);
      for(i=0;i<80;i++)
      {
          printf("*");
      }
      gotoxy(1,18);
      for(i=0;i<80;i++)
      {
          printf("*");
      }
      gotoxy(32,10);
      textcolor(YELLOW);
      printf("1.Admin");
      gotoxy(32,12);
      printf("2.Employee");
      gotoxy(32,14);
      printf("3.Quit");
      textcolor(WHITE);
      gotoxy(32,16);
      printf("Select your role:");
      do
      {
          scanf("%d",&type);
          if(type==1)
          {
            do
            {
                usr=getlnput();
                if(usr==NULL)
                {
                   clrscr();
                   gotoxy(30,12);
                   textcolor(GREEN);
                   printf("Thank you for using the App!\n\n");
                   textcolor(WHITE);
                   getch();
                   exit(0);

                }

                else
                {
                  k=checkUserExist(*usr,"admin");
                }
            }while(k==0);
              if(k==-1)
              {
                 break;
              }
                 if(k==1)
                {
                    gotoxy(1,20);
                    textcolor(WHITE);
                    printf("Press any key to continue");
                    getch();
                    while(1)
                    {
                     clrscr();
                     choice=adminMenu();
                      if(choice==7)
                         break;
                       switch(choice)
                      {
                      case 1:
                              clrscr();
                              addEmployee();
                              break;
                      case 2:
                              clrscr();
                              addCarDetails();
                              break;
                      case 3:
                              clrscr();
                              viewEmployee();
                              break;
                      case 4:
                              clrscr();
                              ShowCarDetails();
                              break;
                      case 5:

                            clrscr();
                            result=deleteEmp();
                            gotoxy(15,14);
                            if(result==0)
                               {
                                     textcolor(LIGHTRED);
                                     printf("Sorry! No emp found for given emp id");

                                }
                            else if(result==1)
                                {
                                     textcolor(LIGHTGREEN);
                                      printf("Record deleted successfully!");
                                 }
                            else if(result==2)
                                 {
                                      textcolor(LIGHTRED);
                                       printf("Sorry! Error in deletion. Try again!");
                                 }
                               textcolor(WHITE);
                               printf("\n\nPress any key to go back to the main screen!");
                               getch();
                               break;
                      case 6:

                            clrscr();
                            result=deleteCarModel();
                            gotoxy(15,14);
                            if(result==0)
                               {
                                     textcolor(LIGHTRED);
                                     printf("Sorry! No Car found for given Car id");

                                }
                            else if(result==1)
                                {
                                     textcolor(LIGHTGREEN);
                                      printf("Record deleted successfully!");
                                 }
                            else if(result==2)
                                 {
                                      textcolor(LIGHTRED);
                                       printf("Sorry! Error in deletion. Try again!");
                                 }
                               textcolor(WHITE);
                               printf("\n\nPress any key to go back to the main screen!");
                               getch();
                               break;
                      default:
                              gotoxy(29,22);
                              textcolor(LIGHTRED);
                              printf("Invalid choice! Try again");
                              getch();
                              gotoxy(32,22);
                              printf("\t\t\t");
                              gotoxy(45,16);
                              printf("\t\t\t");


                    }


                }

          break;


            }


        }

    else if(type==2)
    {
     {
    do
      {
        usr=getlnput();
        if(usr!=NULL)
        {
          k=checkUserExist(*usr,"emp");
        }
        else
        {
         break;
        }
      }while(k==0);
        if(k==-1)
        break;
        if(k==1)
        {
          gotoxy(1,20);
          textcolor(WHITE);
          printf("Press any key to continue");
          _getch();
          while(1)
         {
          clrscr();
          choice=empMenu();
          if(choice==6)
          {
              clrscr();
              gotoxy(30,12);
              textcolor(GREEN);
              printf("Thank you for using the App!\n\n");
              textcolor(WHITE);
              getch();
              exit(0);
          }

          switch(choice)
          {
            case 1:
                      clrscr();
                      int rentresp;
                      rentresp=rentCar();
                      if(rentresp==-2)
                     {
                      gotoxy(35,9);
                      textcolor(LIGHTRED);
                      printf("Sorry! All cars booked. Try later");
                      getch();
                     }
                      else if(rentresp==0)
                     {
                      gotoxy(27,17);
                      textcolor(LIGHTRED);
                      printf("You did not choose any car");
                      getch();
                     }
                     break;
            case 2:
                     clrscr();
                     bookedCarDetails();
                     break;
            case 3:
                     clrscr();
                     availCarDetails();
                     break;
            case 4:
                     clrscr();
                     ShowCarDetails();
                     break;
            case 5:
                     clrscr();
                     result=returnCar();
                     gotoxy(15,14);
                     if(result==0)
                     {
                        textcolor(LIGHTRED);
                        printf("Sorry! No record of the given car found");
                     }
                     else if(result==1)
                     {
                        textcolor(LIGHTGREEN);
                        printf("Car returned successfully!");
                     }
                     else if(result==2)
                     {
                        textcolor(LIGHTRED);
                        printf("Error in returning a car");
                     }
                        gotoxy(1,16);
                        textcolor(WHITE);
                        printf("Press any key to return back");
                        getch();
                        break;
           default:
                     gotoxy(29,22);
                     textcolor(LIGHTRED);
                     printf("Invalid choice! Try again");
                     getch();
                     gotoxy(32,22);
                     printf("\t\t\t");
                     gotoxy(45,16);
                     printf("\t\t\t");
                     break;

            }
           }
        }
     }
  }
          else if(type==3)
          {
              clrscr();
              gotoxy(30,12);
              textcolor(GREEN);
              printf("Thank you for using the App!\n\n");
              textcolor(WHITE);
              getch();
              exit(0);
          }
          else
          {
              gotoxy(32,20);
              textcolor(RED);
              printf("Invalid choice");
              getch();
              gotoxy(30,20);
              printf("\t\t\t");
              gotoxy(49,16);
              printf("\t\t\t");
              textcolor(WHITE);
              gotoxy(49,16);
          }
      }while(1);
      getch();
    }
    return 0;
}
