    //maythu456@gmail.com
    //4 assignment (Exam)
    //File (insert, find, update)
	
	
	#include<stdio.h>
    #include<conio.h>
    #include<process.h>
    void insert();
    void find();
    void update();
    void show();
    int count = 0;
    struct staff
    {
        int id;
        char name[30];
        char password[30];
        int amount;
        int age;
        char location[50];
        }s[10];
    int main()
    {
    int option;
   //clrscr();
        while(1)
        {
            printf("\n1:Insert Staff Records");
            printf("\n2:Find Staff Records");
            printf("\n3:Update Records");
            printf("\n4: Show Staff Records");
            printf("\n5: Exit the Staff Record Program");
            printf("\n\tEnter Your Option:- ");
            scanf("%d",&option);
            switch(option)
            {
                case 1:
                		insert();
               			 break;
                case 2:
                		find();
                		break;
                case 3:
                		update(); break;
          		case 4: 
          				show(); break;
          				
				case 5: exit (0); break;
                default:
                		printf("\n\tOption not Available\n");
                		break;
            }
        }
    getch();
    return 0;
    }
    void insert()
    {
    int i,n=0;
    FILE *fp;
        fp=fopen("staff.txt","a");
        if(fp==NULL)
        {
            printf("\n File Opening Error");
            //getch();
            exit(0);
        }
        printf("\n\tHow Many Records You Want to Enter: ");
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
           printf("Enter Staff ID: ");
           scanf("%d",&s[i].id);

           printf("Enter Staff Name: ");
           scanf("%s",s[i].name);
           
                      
           printf("Enter Password: ");
           scanf("%s",s[i].password);
            
           printf("Enter Staff's Amount: ");
           scanf("%d",&s[i].amount);

           printf("Enter Staff age: ");
           scanf("%d",&s[i].age);

           printf("Enter Staff's Location: ");
           scanf("%s",s[i].location);
            
           printf("\n******************************\n");
           //fwrite(&s,sizeof(s),1,fp);
           fprintf(fp, "%d \t %s \t\t %s \t\t %d \t %d \t\t %s\n", s[i].id,s[i].name,s[i].password,s[i].amount,s[i].age,s[i].location);
        }
    fclose(fp);
    }

void find(){

char searchName[30];
char name[30];
int found=0;
int i=0;


printf("Enter name to search : ");
scanf("%s",searchName);

searchName[strlen(searchName)-1] = '\0';

FILE *fp;
        fp=fopen("staff.txt","r");
        if(fp==NULL)
        {
            printf("can't read file");
            exit(0);
        }
  printf("*************************\n");
  printf("Staff Data that you want to see!!!!\n");
 while (fgets(name, 30, fp)) 
        {
        	
             if(strstr(name,searchName))
            {
            	printf("%s\n", name);
	            found = 1;
            }
        }
        if ( found == 0)
            printf("%s cannot be found\n",searchName);
         printf("*************************\n");
        fclose(fp);
    }



void update(){
		int updateID;
		int i=0,c=0;
		char data[50];
		struct staff *temp;
		
		FILE *fp;
        fp=fopen("staff.txt","a+");
        if(fp==NULL)
        {
            printf("can't read file");
            exit(0);
        }
              
        printf("\n***************************\n");
        
		printf("\nStart editing staff record..\n");
	
	      
        printf("Enter the staff id to update:");
        scanf("%d", &updateID);

        
        while (!EOF)

        {

            fread(&temp->id, sizeof(int), 1, fp);

            printf("%d", temp->id);

            if (updateID == temp->id)

            {

			printf("Enter New Staff ID: ");
           scanf("%d",&s[i].id);

           printf("Enter New Staff Name: ");
           scanf("%s",s[i].name);
           
           printf("Enter New Password: ");
           scanf("%s",s[i].password);
            
           printf("Enter New Staff's Amount: ");
           scanf("%d",&s[i].amount);

           printf("Enter New Staff age: ");
           scanf("%d",&s[i].age);

           printf("Enter New Staff's Location: ");
           scanf("%s",s[i].location);
	           	
			//fwrite(&s,sizeof(s),1,fp);
           fprintf(fp, "%d \t %s \t\t %s \t\t %d \t %d \t\t %s\n", s[i].id,s[i].name,s[i].password,s[i].amount,s[i].age,s[i].location);
	           	
	           }
           else	
           	printf("Your ID number is invalid!!!\n");
          }
            

           
        if (c == 1)

            printf("Record updated\n");

        else

            printf("Update not successful\n");

        fclose(fp);

}
void show()
{
		char data[50];
		FILE *fp;
        fp=fopen("staff.txt","r");
        if(fp==NULL)
        {
            printf("can't read file");
            exit(0);
        }
        
        printf("*************************\n");
        printf("Show All Staff Data!!!\n");
        
        
         while( fgets ( data, 50, fp ) != NULL )
        {
         
                     printf( "%s" , data ) ;
        }
        printf("*************************\n");
         
          fclose(fp) ;
         
        
}
