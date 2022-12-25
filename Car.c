#include<stdio.h>
#include"conio2.h"
#include"Car.h"
#include<string.h>
#include<time.h>



void addAdmin()
{
    FILE *fp=fopen("admin.bin","rb");
    if (fp==NULL)
    {
        fp=fopen("admin.bin","wb");
        User u[2]={{"admin","test","Swapnil"},{"super","demo","Anil"}};
        fwrite(u,sizeof(u),1,fp);
    }
    getch();
    fclose(fp);
}

User* getlnput()
{
    int i;
    clrscr();
    gotoxy(32,1);
    textcolor(YELLOW);
    printf("CAR RENTAL SYSTEM");
    gotoxy(1,2);
    textcolor(YELLOW);
    for(i=0;i<80;i++)
       printf("%c",247);
    gotoxy(32,5);
    printf("* LOGIN PANEL *");
    gotoxy(1,7);
    textcolor(LIGHTCYAN);
    for(i=0;i<80;i++)
       printf("%c",247);
    gotoxy(1,14);
    for(i=0;i<80;i++)
       printf("%c",247);
    gotoxy(60,8);
    textcolor(WHITE);
    printf("Press 0 to exit");
    gotoxy(25,9);
    textcolor(LIGHTCYAN);
    printf("Enter User id:");
    textcolor(WHITE);
    static User u;
    fflush(stdin);
    fgets(u.userid,20,stdin);
    char *pos;
    pos=strchr(u.userid,'\n');
    if(pos!=NULL)
    {
        *pos='\0';
    }
    if(strcmp(u.userid,"0")==0)
    {
        textcolor(LIGHTRED);
        gotoxy(30,17);
        printf("Login Cancelled");
        getch();
        return NULL;
    }
    gotoxy(25,10);
    textcolor(LIGHTCYAN);
    printf("Enter Password:");
    fflush(stdin);
    i=0;
    char ch;
    textcolor(WHITE);
    for(;;)
    {
        ch=getch();
        if(ch==13)
        {
            break;
        }
        if(ch==8)
        {
          if(i==0)
            continue;
          printf("\b \b");
          i--;
           continue;
        }
       printf("%c",ch);
       delay(200);
       printf("\b*");
       u.pwd[i]=ch;
       i++;
    }
    u.pwd[i]='\0';
    if(strcmp(u.pwd,"0")==0)
    {
        textcolor(LIGHTRED);
        gotoxy(30,17);
        printf("Login Cancelled");
        getch();
        return NULL;
    }
    getch();
    return &u;
}

int checkUserExist(User u,char *usertype)
{
    if(strlen(u.userid)==0||strlen(u.pwd)==0)
    {
        gotoxy(25,20);
        textcolor(LIGHTRED);
        printf("Both field are mandotary. Try again");
        getch();
        gotoxy(25,20);
        printf("/t/t/t/t/t");
        return 0;
    }
    FILE *fp;
    if(strcmp(usertype,"admin")==0)
    {
       fp=fopen("admin.bin","rb");
    }
    else
    {
        fp=fopen("emp.bin","rb");
    }
    if(fp==NULL)
    {
        gotoxy(28,20);
        textcolor(LIGHTRED);
        printf("Sorry!Cannot open the file");
        getch();
        gotoxy(28,20);
        printf("/t/t/t/t/t");
        return -1;
    }
    int found=0;
    User user;
    while(fread(&user,sizeof(user),1,fp)==1)
    {
        if(strcmp(u.userid,user.userid)==0 && strcmp(u.pwd,user.pwd)==0)
        {
            found=1;
            break;
        }
    }
    if(found==0)
    {
        gotoxy(25,20);
        textcolor(LIGHTRED);
        printf("Invalid Userid/password.Try again");
        getch();
        gotoxy(25,20);
        printf("\t\t\t\t\t\t");
    }
    else
    {
        gotoxy(28,20);
        textcolor(GREEN);
        printf("Login successful!");
        getch();
        gotoxy(28,20);
        printf("\t\t\t\t\t\t");
    }
    fclose(fp);
    return found;
}

int adminMenu()
{
    int i,choice;
    gotoxy(32,2);
    textcolor(LIGHTRED);
    printf("CAR RENTAL SYSTEM");
    textcolor(LIGHTGREEN);
    gotoxy(1,5);
    for(i=1;i<=80;i++)
    printf("*");
    gotoxy(35,6);
    printf("ADMIN MENU\n");
    for(i=1;i<=80;i++)
    printf("*");
    gotoxy(32,8);
    textcolor(YELLOW);
    printf("1. Add Employee");
    gotoxy(32,9);
    printf("2. Add Car Details");
    gotoxy(32,10);
    printf("3. Show Employee");
    gotoxy(32,11);
    printf("4. Show Car Details");
    gotoxy(32,12);
    printf("5. Delete Employee");
    gotoxy(32,13);
    printf("6. Delete Car Details");
    gotoxy(32,14);
    printf("7. Exit");
    gotoxy(32,16);
    printf("Enter choice:");
    gotoxy(1,18);
    textcolor(LIGHTGREEN);
    for(i=1;i<=80;i++)
    printf("*");
    gotoxy(45,16);
    textcolor(WHITE);
    scanf("%d",&choice);
    return choice;
}
void addEmployee()
{
    char temp[20];
    char choice;
    char *pos;
    User u;
    FILE *fp=fopen("emp.bin","ab+");
    fseek(fp,0,SEEK_END);
    long total_rec=ftell(fp)/sizeof(User);
    if(total_rec!=0)
     {
        fseek(fp,-60,SEEK_END);
        fread(temp,sizeof(temp),1,fp);
        pos=strchr(temp,'-');
        total_rec=atoi(pos+1);


     }
    total_rec++;
    sprintf(u.userid,"EMP-%lu",total_rec);
    fseek(fp,0,SEEK_END);
    do
    {
        clrscr();
        gotoxy(32,2);
        textcolor(LIGHTRED);
        printf("CAR RENTAL APP");
        textcolor(LIGHTGREEN);
        int i;
        gotoxy(1,3);
        for(i=1;i<=80;i++)
            printf("%c",247);
        textcolor(LIGHTCYAN);
        gotoxy(25,4);
        printf("***** ADD EMPLOYEE DETAILS *****");
        gotoxy(1,5);
        textcolor(LIGHTGREEN);
        for(i=1;i<=80;i++)
            printf("%c",247);
        gotoxy(1,5);
        textcolor(LIGHTGREEN);
        gotoxy(1,8);
        textcolor(YELLOW);
        printf("Enter Employee Name:");
        fflush(stdin);
        textcolor(WHITE);
        fgets(u.name,20,stdin);
        char *pos;
        pos=strchr(u.name,'\n');
        if(pos!=NULL)
        {
            *pos='\0';
        }
        textcolor(YELLOW);
        printf("Enter Employee Pwd:");
        fflush(stdin);
        textcolor(WHITE);
        fgets(u.pwd,20,stdin);
        pos=strchr(u.pwd,'\n');
        if(pos!=NULL)
        {
            *pos='\0';
        }
        fwrite(&u,sizeof(u),1,fp);
        gotoxy(30,15);
        textcolor(LIGHTGREEN);
        printf("EMPLOYEE ADDED SUCCESSFULY!");
        printf("\nEMPLOYEE ID is %s",u.userid);
        getch();
        gotoxy(1,20);
        textcolor(LIGHTRED);
        printf("Do you want to add more employees (Y/N)?");
        textcolor(WHITE);
        fflush(stdin);
        scanf("%c",&choice);
        total_rec++;
        sprintf(u.userid,"EMP-%lu",total_rec);
    }while(choice=='Y'||choice=='y');
    fclose(fp);
}

void viewEmployee()
{
    FILE *fp=fopen("emp.bin","rb");
    int i;
    User ur;
    gotoxy(32,1);
    textcolor(YELLOW);
    printf("CAR RENTAL SYSTEM\n");
    for(i=1;i<=80;i++)
        printf("%c",247);
    gotoxy(31,5);
    printf("* EMPLOYEE DETAILS *");
    gotoxy(1,7);
    textcolor(LIGHTGREEN);
    for(i=0;i<=80;i++)
        printf("%c",247);
    if(fp==NULL)
    {
        gotoxy(31,9);
        textcolor(LIGHTRED);
        printf("Sorry! No Employees added yet!");
        getch();
        return;
    }
    gotoxy(1,8);
    printf("Employee ID\t\t\tName\t\t\tPassword");
    gotoxy(1,9);
    for(i=1;i<=80;i++)
        printf("%c",247);
    int row=10;
    textcolor(YELLOW);
    while(fread(&ur,sizeof(ur),1,fp)==1)
    {
        gotoxy(2,row);
        printf("%s",ur.userid);
        gotoxy(33,row);
        printf("%s",ur.name);
        gotoxy(57,row);
        printf("%s",ur.pwd);
        row++;
    }
    fclose(fp);
    getch();
}
int deleteEmp()
{
    FILE *fp1=fopen("emp.bin","rb");
    char empid[10];
    int i,result;
    textcolor(YELLOW);
    gotoxy(32,1);
    printf("CAR RENTAL SYSTEM\n");
    for(i=1; i<=80; i++)
        printf("%c",247);
    gotoxy(29,5);
    textcolor(YELLOW);
    printf("* DELETE EMPLOYEE RECORD *");
    gotoxy(1,7);
    textcolor(LIGHTGREEN);
    for(i=1; i<80; i++)
        printf("%c",247);
    gotoxy(1,12);
    for(i=1; i<80; i++)
        printf("%c",247);
    if(fp1==NULL)
    {
        textcolor(LIGHTRED);
        printf("\nNo Employee Added Yet!");
        return -1;
    }
    FILE *fp2=fopen("temp.bin","wb+");
    gotoxy(10,9);
    textcolor(YELLOW);
    printf("Enter Employee Id to delete the record:");
    textcolor(WHITE);
    scanf("%s",empid);
    User U;
    int found=0;
    while(fread(&U,sizeof(U),1,fp1)==1)
    {
        if(strcmp(U.userid,empid)!=0)
        {
            fwrite(&U,sizeof(U),1,fp2);
        }
        else
        {
            found=1;
        }
    }
    fclose(fp1);
    fclose(fp2);
     if(found==0)
    {
        remove("temp.bin");
    }
    else
    {
        result=remove("emp.bin");
        if(result!=0)
            return 2;

        result=rename("temp.bin","emp.bin");
        if(result!=0)
            return 2;
    }
    return found;
    getch();

}

void addCarDetails()
{
    int i,temp=0;
    Car c;
    char ch;
    FILE *fp=fopen("car.bin","ab+");
    fseek(fp,0,SEEK_END);
    long count=ftell(fp)/sizeof(Car);
    if(count!=0)
    {
        fseek(fp,-(unsigned long int)sizeof(c),SEEK_END);
        fread(&temp,sizeof(temp),1,fp);
        count=temp;
        fseek(fp,0,SEEK_END);
    }
    do
    {
        clrscr();
        count++;
        textcolor(RED);
        gotoxy(35,2);
        printf("CAR RENTAL APP");
        gotoxy(1,3);
        textcolor(GREEN);
        for(i=1;i<=80;i++)
          printf("%c",247);
        textcolor(WHITE);
        gotoxy(28,4);
        textcolor(LIGHTCYAN);
        printf("***** ADD CAR DETAILS *****");
        gotoxy(1,5);
        textcolor(LIGHTGREEN);
        for(i=1;i<=80;i++)
            printf("%c",247);
        gotoxy(1,8);
        textcolor(YELLOW);
        printf("Enter Car Model:");
        fflush(stdin);
        textcolor(WHITE);
        fgets(c.car_name,20,stdin);
        char *pos;
        pos=strchr(c.car_name,'\0');
        if(pos!=NULL)
        {
            *pos='\0';
        }
        textcolor(YELLOW);
        printf("Enter Car Capacity:");
        textcolor(WHITE);
        scanf("%d",&c.capacity);
        textcolor(YELLOW);
        printf("Enter Car Count:");
        textcolor(WHITE);
        scanf("%d",&c.car_count);
        c.car_id=c.car_count;
        textcolor(YELLOW);
        printf("Enter Car Price for per day:");
        textcolor(WHITE);
        scanf("%d",&c.price);
        textcolor(GREEN);
        gotoxy(28,16);
        c.car_id=count;
        fwrite(&c,sizeof(c),1,fp);
        gotoxy(30,15);
        textcolor(LIGHTGREEN);
        printf("CAR ADDED SUCCESSFULLY\n");
        printf(" CAR ID IS: %ld",count);
        gotoxy(1,22);
        textcolor(RED);
        printf("DO YOU WANT TO ADD MORE CAR(Y/N):");
        textcolor(WHITE);
        fflush(stdin);
        scanf("%c",&ch);
    }while(ch=='Y');
    fclose(fp);
}
void ShowCarDetails()
{
    FILE *fp=fopen("car.bin","rb");
    int i;
    Car C;
    gotoxy(32,1);
    textcolor(YELLOW);
    printf("CAR RENTAL SYSTEM\n");
    for(i=1;i<=80;i++)
        printf("%c",247);
    gotoxy(31,5);
    printf("* ALL CAR DETAILS *");
    gotoxy(1,7);
    textcolor(LIGHTGREEN);
    for(i=0;i<=80;i++)
        printf("%c",247);
    if(fp==NULL)
    {
        gotoxy(31,9);
        textcolor(LIGHTRED);
        printf("Sorry! No Cars added yet!");
        getch();
        return;
    }
    gotoxy(1,8);
    printf("Car ID\tModel\t\tCapacity\tAvailable\tPrice/Day");
    gotoxy(1,9);
    for(i=1;i<=80;i++)
        printf("%c",247);
    int row=10;
    textcolor(YELLOW);
    while(fread(&C,sizeof(C),1,fp)==1)
    {
        gotoxy(2,row);
        printf("%d",C.car_id);
        gotoxy(9,row);
        printf("%s",C.car_name);
        gotoxy(28,row);
        printf("%d",C.capacity);
        gotoxy(45,row);
        printf("%d",C.car_count);
        gotoxy(61,row);
        printf("%d",C.price);
        row++;
    }
    fclose(fp);
    getch();
}

int deleteCarModel()
{
    FILE *fp1=fopen("car.bin","rb");
    int carid;
    int i,result;
    textcolor(YELLOW);
    gotoxy(32,1);
    printf("CAR RENTAL SYSTEM\n");
    for(i=1; i<=80; i++)
        printf("%c",247);
    gotoxy(29,5);
    textcolor(YELLOW);
    printf("* DELETE CAR RECORD *");
    gotoxy(1,7);
    textcolor(LIGHTGREEN);
    for(i=1; i<80; i++)
        printf("%c",247);
    gotoxy(1,12);
    for(i=1; i<80; i++)
        printf("%c",247);
    if(fp1==NULL)
    {
        textcolor(LIGHTRED);
        printf("\nNo Car Added Yet!");
        return -1;
    }
    FILE *fp2=fopen("temp.bin","wb+");
    gotoxy(10,9);
    textcolor(YELLOW);
    printf("Enter Car model Id to delete the record:");
    textcolor(WHITE);
    scanf("%d",&carid);
    Car C;
    int found=0;
    while(fread(&C,sizeof(C),1,fp1)==1)
    {
        if((C.car_id==carid)==0)
        {
            fwrite(&C,sizeof(C),1,fp2);
        }
        else
        {
            found=1;
        }
    }
    fclose(fp1);
    fclose(fp2);
     if(found==0)
    {
        remove("temp.bin");
    }
    else
    {
        result=remove("car.bin");
        if(result!=0)
            return 2;

        result=rename("temp.bin","car.bin");
        if(result!=0)
            return 2;
    }
    return found;
    getch();

}

int empMenu()
{
    int choice,i;
    textcolor(LIGHTRED);
    gotoxy(32,2);
    printf("CAR RENTAL SYSTEM");
    gotoxy(1,5);
    textcolor(LIGHTGREEN);
    for(i=0; i<80; i++)
    {
        printf("*");
    }
    gotoxy(35,6);
    printf("EMPLOYEE MENU\n");
    for(i=0; i<80; i++)
    {
        printf("*");
    }
    textcolor(YELLOW);
    gotoxy(32,8);
    printf("1. Rent A Car");
    gotoxy(32,9);
    printf("2. Booking Details");
    gotoxy(32,10);
    printf("3. Available Car Details");
    gotoxy(32,11);
    printf("4. Show All Car Details");
    gotoxy(32,12);
    printf("5. Return Car");
    gotoxy(32,13);
    printf("6. Exit");
    gotoxy(32,16);
    printf("Enter choice:");
    gotoxy(1,18);
    textcolor(LIGHTGREEN);
    for(i=0; i<80; i++)
       printf("*");
    gotoxy(45,16);
    textcolor(WHITE);
    scanf("%d",&choice);
    return choice;
}

int selectCarModel()
{
    int flag;
    FILE *fp=fopen("car.bin","rb");
    Car C;
    int choice,x=9;
    int carcount=0;
    gotoxy(34,x);
    while(fread(&C,sizeof(C),1,fp)==1)
    {
        if(C.car_count>0)
        {
            printf("%d . %s",C.car_id,C.car_name);
            gotoxy(34,++x);
            ++carcount;
        }
    }
    if(carcount==0)
    {
        fclose(fp);
        return -2;
    }
    gotoxy(30,x+2);
    printf("Enter your choice(0 to quit):");
    textcolor(WHITE);
    gotoxy(59,x+2);
    while(1)
    {
      flag=0;
      scanf("%d",&choice);
      if(choice==0)
      {
          fclose(fp);
          return 0;
      }
      rewind(fp);
       while(fread(&C,sizeof(C),1,fp)==1)
       {
          if(C.car_id==choice)
          {
            flag=1;
            break;

          }
       }
        if(flag==1)
        {
            fclose(fp);
            return choice;
        }
        else
        {
           gotoxy(37,x+4);
           textcolor(LIGHTRED);
           printf("Wrong Input");
          _getch();
           gotoxy(35,x+4);
           printf("\t\t\t\t\t\t\t");
           gotoxy(59,x+2);
           printf("\t\t\t\t\t\t\t\t\t\t\t\t\t");
           gotoxy(59,x+2);
           textcolor(WHITE);

        }
    }

}

int isValidDate(struct tm dt)
{
    if(dt.tm_year>=2021&& dt.tm_year<=2022)
    {

        if(dt.tm_mon>=1 && dt.tm_mon<=12)
        {
            if((dt.tm_mday>=1 && dt.tm_mday<=31) && (dt.tm_mon==1 || dt.tm_mon==3 || dt.tm_mon==5 || dt.tm_mon==7 || dt.tm_mon==8 || dt.tm_mon==10 || dt.tm_mon==12))
               return 1;
            else if((dt.tm_mday>=1 && dt.tm_mday<=30) && (dt.tm_mon==4 || dt.tm_mon==6 || dt.tm_mon==9 || dt.tm_mon==11))
               return 1;
            else if((dt.tm_mday>=1 && dt.tm_mday<=28) && (dt.tm_mon==2))
               return 1;
            else if(dt.tm_mday==29 && dt.tm_mon==2 && (dt.tm_year%400==0 ||(dt.tm_year%4==0 && dt.tm_year%100!=0)))
               return 1;
            else
               return 0;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

void updateCarCount(int c)
{

    FILE *fp=fopen("car.bin","rb+");
    if(fp==NULL)
    {
        printf("Sorry file cannot be open!");
        getch();
        return;
    }
    Car C;
    while(fread(&C,sizeof(Car),1,fp)==1)
    {

        if(C.car_id==c)
        {
            fseek(fp,-8,SEEK_CUR);
            int cc;
            int cc_new=C.car_count-1;
            fwrite(&cc_new,sizeof(cc_new),1,fp);
            fseek(fp,-4,SEEK_CUR);
            _getch();
       }

    }
    fclose(fp);
}

void bookedCarDetails()
{
    clrscr();
    FILE *fp=fopen("customer.bin","rb");
    Customer_Car_Details CC;
    int i;
    textcolor(YELLOW);
    gotoxy(32,1);
    printf("CAR RENTAL SYSTEM\n");
    for(i=1; i<=80; i++)
        printf("%c",247);
    gotoxy(31,5);
    textcolor(YELLOW);
    printf("* BOOKED CAR DETAILS *");
    gotoxy(1,7);
    textcolor(LIGHTGREEN);
    for(i=1; i<=80; i++)
        printf("%c",247);
    gotoxy(1,8);
    printf("Model\t    Cust Name\t   Pick Up\t   Drop\t          S_Date\tE_Date");
    gotoxy(1,9);
    textcolor(LIGHTGREEN);
    for(i=1; i<=80; i++)
        printf("%c",247);
    int x=10;
    textcolor(YELLOW);

    while(fread(&CC,sizeof(Customer_Car_Details),1,fp)==1)
    {
        gotoxy(1,x);
        printf("%s",getCarName(CC.car_id));
        gotoxy(13,x);
        printf("%s",CC.cust_name);
        gotoxy(29,x);
        printf("%s",CC.pick);
        gotoxy(42,x);
        printf("%s",CC.drop);
        gotoxy(58,x);
        printf("%d-%d-%d",CC.sd.tm_mday,CC.sd.tm_mon,CC.sd.tm_year);
        gotoxy(71,x);
        printf("%d-%d-%d",CC.ed.tm_mday,CC.ed.tm_mon,CC.ed.tm_year);
        x++;
    }
    fclose(fp);
    _getch();
}

char * getCarName(int car_id)
{
    FILE *fp=fopen("car.bin","rb");
    static Car C;
    while(fread(&C,sizeof(C),1,fp)==1)
    {
        if(C.car_id==car_id)
        {
             break;
        }
    }
    fclose(fp);
    return C.car_name;
}

int rentCar()
{
    Customer_Car_Details CC;
    int c,i;
    textcolor(LIGHTRED);
    gotoxy(32,2);
    printf("CAR RENTAL SYSTEM");
    textcolor(LIGHTGREEN);
    gotoxy(1,5);
    for(i=0; i<80; i++)
    {
        printf("*");
    }
    gotoxy(35,6);
    printf("EMPLOYEE MENU\n");
    for(i=0; i<80; i++)
    {
        printf("*");
    }
    gotoxy(1,19);
    for(i=0; i<80; i++)
    {
        printf("*");
    }
    textcolor(YELLOW);
    gotoxy(32,8);
    c=selectCarModel();
    if(c==0||c==-2)
        return c;
    CC.car_id=c;
    clrscr();
    textcolor(LIGHTRED);
    gotoxy(32,2);
    printf("CAR RENTAL SYSTEM");
    textcolor(LIGHTGREEN);
    gotoxy(1,5);
    for(i=0; i<80; i++)
    {
        printf("*");
    }
    gotoxy(35,6);
    printf("EMPLOYEE MENU\n");
    for(i=0; i<80; i++)
    {
        printf("*");
    }
    gotoxy(1,17);
    for(i=0; i<80; i++)
    {
        printf("*");
    }
    textcolor(YELLOW);
    gotoxy(27,9);
    printf("Enter Customer Name:");
    fflush(stdin);
    textcolor(WHITE);
    fgets(CC.cust_name,30,stdin);
    char *pos;
    pos=strchr(CC.cust_name,'\n');
    *pos='\0';
    gotoxy(27,10);
    textcolor(YELLOW);
    printf("Enter Pickup Point:");
    fflush(stdin);
    textcolor(WHITE);
    fgets(CC.pick,30,stdin);
    pos=strchr(CC.pick,'\n');
    *pos='\0';
    gotoxy(27,11);
    textcolor(YELLOW);
    printf("Enter Drop Point:");
    fflush(stdin);
    textcolor(WHITE);
    fgets(CC.drop,30,stdin);
    pos=strchr(CC.drop,'\n');
    *pos='\0';
    gotoxy(27,12);
    textcolor(YELLOW);
    printf("Enter start date (dd/m/yyyy):");
    textcolor(WHITE);
    do
    {
        scanf("%d/%d/%d",&CC.sd.tm_mday,&CC.sd.tm_mon,&CC.sd.tm_year);
        int datevalid=isValidDate(CC.sd);
        if(datevalid==0)
        {
            gotoxy(27,18);
            textcolor(LIGHTRED);
            printf("Wrong Date");
            _getch();
            gotoxy(27,18);
            printf("\t\t");
            gotoxy(56,12);
            printf("\t\t\t");
            gotoxy(56,12);
            textcolor(WHITE);
        }
        else
            break;
    }while(1);
    gotoxy(27,13);
    textcolor(YELLOW);
    printf("Enter end date (dd/m/yyyy):");
    textcolor(WHITE);

    do
    {
        scanf("%d/%d/%d",&CC.ed.tm_mday,&CC.ed.tm_mon,&CC.ed.tm_year);
        int datevalid=isValidDate(CC.ed);
        if(datevalid==0)
        {
            gotoxy(27,18);
            textcolor(LIGHTRED);
            printf("Wrong Date");
            _getch();
            gotoxy(27,18);
            printf("\t\t");
            gotoxy(54,13);
            printf("\t\t\t");
            gotoxy(54,13);
            textcolor(WHITE);
        }
        else
            break;
    }while(1);

    int correctdate=checkDate(CC.sd,CC.ed);
    if(correctdate==1)
    {
      FILE *fp;
      fp=fopen("customer.bin","ab");
      if(fp==NULL)
      {
        gotoxy(27,18);
        textcolor(LIGHTRED);
        printf("Sorry ! File cannot be opened");
        getch();
        gotoxy(27,18);
        printf("\t\t");
        return -1;
      }
    fwrite(&CC,sizeof(Customer_Car_Details),1,fp);
    printf("Booking Done:%d",CC.car_id);
    printf("\nPress any key to continue...");
    getch();
    fclose(fp);
    updateCarCount(c);
    bookedCarDetails();
    return 1;
   }
   else
   {
      gotoxy(32,18);
      textcolor(LIGHTRED);
      printf("Wrong date ");
      gotoxy(27,19);
      printf("Booking cannot be done");
      getch();
   }
}

void availCarDetails()
{
    FILE*fp=fopen("car.bin","rb");
    Car C;
    int i;
    textcolor(YELLOW);
    gotoxy(32,1);
    printf("CAR RENTAL SYSTEM\n");
    textcolor(LIGHTGREEN);
    for(i=1;i<=80;i++)
        printf("%c",247);
    gotoxy(32,5);
    textcolor(YELLOW);
    printf("* AVAILABLE CAR DETAILS *");
    gotoxy(1,7);
    textcolor(LIGHTGREEN);
    for(i=1;i<=80;i++)
        printf("%c",247);
    if(fp==NULL)
    {
        gotoxy(32,8);
        textcolor(LIGHTRED);
        printf("Sorry!File cannot be opened!");
        getch();
        return;
    }
    gotoxy(1,8);
    printf("CAR ID\t   Model\t\tCapacity\tAvailable\tPrice/Day");
    gotoxy(1,9);
    for(i=1;i<=80;i++)
        printf("%c",247);
    int row=10;
    textcolor(YELLOW);
    while(fread(&C,sizeof(C),1,fp)==1)
    {
        if(C.car_count>0)
        {
            gotoxy(2,row);
            printf("%d",C.car_id);
            gotoxy(13,row);
            printf("%s",C.car_name);
            gotoxy(35,row);
            printf("%d",C.capacity);
            gotoxy(50,row);
            printf("%d",C.car_count);
            gotoxy(68,row);
            printf("%d",C.price);
            row++;
         }
    }
    fclose(fp);
    getch();
}
int returnCar()
{
    FILE *fp1=fopen("customer.bin","rb");
    int c_id;
    int i,result;
    textcolor(YELLOW);
    gotoxy(32,1);
    printf("CAR RENTAL SYSTEM\n");
    for(i=1;i<=80;i++)
    {
        printf("%c",247);
    }
    gotoxy(33,5);
    printf("* Return Car *");
    gotoxy(1,7);
    textcolor(LIGHTGREEN);
    for(i=1;i<=80;i++)
    {
        printf("%c",247);
    }
    gotoxy(1,12);
    for(i=1;i<=80;i++)
    {
        printf("%c",247);
    }
    if(fp1==NULL)
    {
        textcolor(LIGHTRED);
        gotoxy(32,10);
        printf("No Car booked yet!");
        return -1;
    }
    FILE *fp2=fopen("temp.bin","wb");
    if(fp2==NULL)
    {
        textcolor(LIGHTRED);
        gotoxy(32,10);
        printf("Sorry ! cannot create temp file");
        return -1;
    }
    gotoxy(10,9);
    textcolor(YELLOW);
    printf("Enter Car id to return a car:");
    textcolor(WHITE);
    scanf("%d",&c_id);
    Customer_Car_Details CC;
    int found=0;
    while(fread(&CC,sizeof(CC),1,fp1)==1)
    {
        if(found==0||found==1)
        {
            if(found==1)
            {
                 fwrite(&CC,sizeof(CC),1,fp2);
            }
            else
            {
                if(CC.car_id!=c_id)
                  fwrite(&CC,sizeof(CC),1,fp2);
                else
                  found=1;
            }

        }
       }
    fclose(fp1);
    fclose(fp2);
    if(found==0)
    {
        remove("temp.bin");
    }
    else
    {
        result=remove("customer.bin");
        if(result!=0)
            return 2;
        result=rename("temp.bin","customer.bin");
        if(result!=0)
            return 2;
    }
    update_car_count(c_id);

    return found;

}
 void update_car_count(int c_id)
{
    FILE* fp=fopen("car.bin","rb+");
    if(fp==NULL)
    {
        printf("Sorry file cannot be open!");
        getch();
        return;
    }
    Car C;
    while(fread(&C,sizeof(Car),1,fp)==1)
    {
        if(C.car_id==c_id)
        {
            int x=C.car_count;
            x=x+1;
            fseek(fp,-8,SEEK_CUR);

            fwrite(&x,sizeof(x),1,fp);
            break;
            //fseek(fp,4,SEEK_CUR);
        }
    }
    fclose(fp);
}

int checkDate(struct tm sd,struct tm ed)
{


    time_t obj=time(0);
    struct tm *p=localtime(&obj);
    int sd_check=0;
        if (sd.tm_year>1900+p->tm_year)
        {
            sd_check=1;
        }
        else if(sd.tm_year=1900+p->tm_year)
        {
            if(sd.tm_mon>1+p->tm_mon)
            {
                sd_check=1;
            }
            else if(sd.tm_mon=1+p->tm_mon)
            {
                if(sd.tm_mday>=p->tm_mday)
                {
                    sd_check=1;
                }
            }
        }
        if (sd_check==1)
        {
             if (sd.tm_year>ed.tm_year)
             {
                 return 1;
             }
             else if(sd.tm_year=ed.tm_year)
             {
                if(sd.tm_mon>ed.tm_mon)
                {
                  return 1;
                }
                else if(sd.tm_mon=ed.tm_mon)
                {
                   if(sd.tm_mday>=ed.tm_mday)
                   {
                      return 1;
                   }
                }
             }
        }

    return 0;

}
