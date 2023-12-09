#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
struct Donor{
	char first_name[20];
	char last_name[20];
	float totalpoints;
};
void add_donor_record();
void view_donor_record();
//int name_is_valid(char[],char[]);
void contribution_calculation();
 float prev_points=0;
  FILE *file_ptr;
void contribution_type()
{
	printf("\n\6t\t--------CONTRIBUTION TYPES-------\n ");
	printf("\n\t\t1.Cash \n ");
	printf("\n\t\t2.Clothes \n ");
	printf("\n\t\t3.Volunteer works \n ");
//	Sleep(2000);
}
void contribution_criteria()
{
   printf("\n\t\t-----------DASHBOARD--------------\n ");
	printf("\n\t\t1.Cash:Rs1000\t\t\t\t  1points\n ");
	printf("\n\t\t2.Clothes:1kg\t\t\t\t  1points \n ");
	printf("\n\t\t3.Volunteer works:1hour \t\t 10points \n ");
//	Sleep(2000);
}
void menu()
{
    while (1)
    {
        system("cls");
        int choice = 0;
        printf("-------Donation-------");
        printf("\n\t\t1.Add Donor Record\n");
        printf("\n\t\t2.Display Donor Leaderboard\n");
        printf("\n\t\t3.Exit\n");
        
        printf("------------------------------------\n");
    re_choice:
        printf("Enter your choice: ");
        scanf("%d", &choice);
        fflush(stdin);
        switch (choice)
        {
        case 1:
            add_donor_record();
            break;
           

        case 2:
            view_donor_record();
            break;
           case 3:
           	exit(0);

        default:
            printf("\nInvalid Choice");
          //  Sleep(1000);
            menu();
            break;
        }
        choice = 0;
    }
}
void add_donor_record()
{
     struct Donor input_donor;
     struct Donor read_donor;
//      FILE *file_ptr;
      int name_valid;
      int is_donor_present = 0;
      char type1[]="cash";
      char type2[]="clothes";
      char type3[]="volunteer";
      float n,pts1=0,m,pts2=0,p,pts3=0;
      int count=0;
      char choose;
      char type[25];
     
      file_ptr = fopen("D:\\donation leaderboard\\donor_info.DAT", "ab+");
     if (file_ptr == NULL)
    {
        printf("\nFILE DOESN'T EXIST\n");
        getchar();
        exit(0);
    }
    printf("\n\t\t======Add Donor Record=======\n");
    fflush(stdin);
again_name:
    printf("\n\t\tEnter first name: ");
    scanf("%s", input_donor.first_name);
    fflush(stdin);
    printf("\n\t\tEnter last name: ");
    scanf("%s", input_donor.last_name);
    fflush(stdin);
 
    while (fread(&read_donor, sizeof(struct Donor), 1, file_ptr))
    {
        if (strcmp(read_donor.first_name, input_donor.first_name)==0)
        {
            prev_points=read_donor.totalpoints;
        
        }
    }
    
   	again:
   	contribution_type();
 	printf("\n\tEnter Contribution Type: ");
    scanf("%s",type);
    if(strcmp(type,type1)==0)
    {
          printf("\nenter the blood donor has donated: ");
          scanf("%f",&n);
          pts1=n*5;
        printf("points=%.2f",pts1);
    }
	fflush(stdin);
    if(strcmp(type,type2)==0)
    {
      printf("\nenter kilos of clothes donor has donated: ");
      scanf("%2f",&m);
      pts2=1*m;
    printf("\npoints=%.2f",pts2);
    }
    fflush(stdin);
    if(strcmp(type,type3)==0)
    {
	     printf("\nenter how many hours donor has volunteered:  ");
	     scanf("%f",&p);
	     pts3=10*p;
	     printf("points=%.2f",pts3);
    }
	alpha:
    fflush(stdin);
    printf("\nDo you want to add your donation?If yes then press 'Y'or'y' else 'N'or 'n':" );
    scanf("%c",&choose);
    if(choose=='Y'||choose=='y')
    {
		goto again;
	}
	else if(choose=='N'||choose=='n')
	{ 
	  input_donor.totalpoints= pts1+pts2+pts3+prev_points;
	  printf("the total points gained is %.2f ",input_donor.totalpoints);
	  Sleep(2000);

	}
	else
	{
		printf("\nenter valid choice: ");
		goto alpha;
	}
    
    fwrite(&input_donor, sizeof(struct Donor), 1, file_ptr);
    printf("\nFILE HAS BEEN SUCCESSFULLY ADDED");
    fclose(file_ptr);
  //  Sleep(3000);
//    prev_points=0;
}

  void view_donor_record()
{
//	system("cls");
	struct Donor read_donor[10],temp;
//	 FILE *file_ptr;
	 int i=0,j=0;
 file_ptr= fopen("D:\\donation leaderboard\\donor_info.DAT", "rb+");
     if (file_ptr == NULL)
    {
        printf("\nFILE DOESN'T EXIST\n");
        getchar();
        exit(0);
    }
        fread(&read_donor, sizeof(read_donor), 1,file_ptr);
        
		for(i=0;i<5;i++)
		{
			for(j=i+1;j<5;j++)
			{
			 if(read_donor[i].totalpoints<read_donor[j].totalpoints)
				 {
			 	temp=read_donor[i];
				 read_donor[i]=read_donor[j];
				 read_donor[j]=temp;	
				 }	
			}
	}
	printf("\nDonation Contribution Leaderboard:\n");
 printf("---------------------------------\n");
    printf("%-20s %-10s\n", "Donor Name", "Contribution points");
	for(i=0;i<5;i++)
	{
		 getchar();
		//system("cls");
		printf("\n\t\t  %s %s",read_donor[i].first_name,read_donor[i].last_name);
		printf("\t\t\t  %.2f ",read_donor[i].totalpoints);
//		 getchar();
//		 sleep(1000);
	  }
	fclose(file_ptr);
	printf("\n\t\t FILE SUCCESSFULLY READ");
}
int main()
{
	contribution_type ();
	contribution_criteria();
	menu();
	  view_donor_record();
	return 0;
	
}
