#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void game(char word[]);
void game2();
float bc(char [],char []);
main()
{
    char word[10];
    static int seen[10];
    int i,r,play;
    FILE * f;
    scanf("%d",&play);
    printf("\n");
    if(play==0)
    {
    f=fopen("ma","r");
    srand(time(0));
    r = rand()%4257;
    fseek(f,5*r,SEEK_SET);
    fscanf(f,"%s",word);
    game(word);
    fclose(f);
    }

    else
    {
     game2();
    }
    return 0;
}

float bc(char orig[], char guess[])
{
    float b_c=0.0;
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(tolower(orig[i])==tolower(guess[j]))
            {
                if(i==j)
                {
                    b_c++;
                }
                else
                {
                   b_c+=0.1;
                }
                break;
            }
        }
    }
    return b_c;
}

void game(char word[])
{
    char uw[10];
    int count=0;
    float b_c=0.0;
    while(1)
    {
        count++;
        b_c=0.0;
        scanf("%s", uw);
        b_c=bc(word,uw);
        


    printf("     Bulls : %d       Cows : %d \n",(int) b_c ,(int)(b_c*10)%10);
    
    if(b_c==4)
    {
        printf("Good, You have found the word in %d chances", count);
        break;
    }
    }


}

void game2()
{
    FILE * f1,*f2,*f,*next;
    char word[10];
int r;    
    f1=fopen("ma","r");
    f2=fopen("pos1","w");
while(!feof(f1))
    {

    fscanf(f1,"%s",word);
    fprintf(f2,"%s ",word);
    }
    fclose(f2);
    fclose(f1);

float res;
char guess[10];
int wc = 4257,b,c;
float ub_c;
int chances=0;
    while(1)
    {
        chances++;
        f=fopen("pos1","r");
        next=fopen("pos2","w");
     srand(time(0));
    r = rand()%wc;
    fseek(f,5*r,SEEK_SET);
    fscanf(f,"%s",word);
    printf("%s\n",word);
    scanf("%d%d",&b,&c);
    ub_c=b+(float)c/10;
    wc=0;
    fseek(f,0,SEEK_SET);
    if(ub_c==4)
    {
        printf("no of chances : %d\n",chances);
        break;
    }
    while(!feof(f))
    {   
        fscanf(f,"%s",guess);
     res=bc(guess,word);
    
       
        if(ub_c==res&&strcasecmp(guess,word))
        {
              fprintf(next,"%s ",guess);
              wc++;
        }
       

    }
if(wc==0)
   { printf("pack\n ");
exit(1);
   }
    fclose(f);
    fclose(next);
    remove("pos1");
    rename("pos2","pos1");
        
   }


}

