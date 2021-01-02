#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include <time.h>

void addDiary();
void viewDiary();
void ViewSpecificDiary();
void editDiary();
void CustomeRange();
void deleteDiary();
int compare(char * str1, char * str2);

//Structure for dairy for adding process
struct Diary{
    char title[50];
    char date[10];
    char time[6];
    char name[30];
    char place[25];
    char duration[10];
    char note[500];
} ;

int main(){
    system("cls");
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int num,j=0;

    printf("\n\t*************************\n");
    printf("\t*PERSONAL DIARY DATABASE*\n");
    printf("\t*************************");

    while(j == 0){
        printf("\n\t\tMAIN MENU:");
        printf("\n\tPRESS [1]\tADD DIARY");//Create diary note
        printf("\n\tPRESS [2]\tVIEW ALL DIARIES");//Show all diary
        printf("\n\tPRESS [3]\tVIEW A SPECIFIC DAIRY");//View a specific diary by name and created date
        printf("\n\tPRESS [4]\tEDIT A DIARY");//Update a diary
        printf("\n\tPRESS [5]\tSHOW DIARIES FROM A CUSTOME RANGE OF DATE ");//Show all diary from a date to another
        printf("\n\tPRESS [6]\tDELETE A DIARY");
        printf("\n\tPRESS [0]\tEXIT THE PROGRAM");

        printf("\n\n\tNOW: %d-%d-%d %d:%d:%d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
        printf("\n\tENTER YOUR CHOICE:");
        scanf("%d",&num);


        switch(num){
            case 1:
                addDiary();
                break;
            case 2:
                viewDiary();
                break;
            case 3:
                ViewSpecificDiary();
                break;
            case 4:
                editDiary();
                break;
            case 5:
                CustomeRange();
                break;
            case 6:
                deleteDiary();
                break;
            case 0:
                printf("\n\n\t\tTHANK YOU FOR USING OUR SYSTEM...");
                getch();
                exit(0);
            default:
                printf("\nPLEASE TRY AGAIN...");
                getch();
                break;
        }
    }

}
void addDiary(){

    int i = 0;
    system("cls");
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    FILE *fp ;
    struct Diary d[500] ;
    char filename[15];
    int choice;

    fp = fopen("Diary.txt","a");

    printf("\n\n\t\t***************************\n");
    printf("\t\t* WELCOME TO THE ADD MENU *");
    printf("\n\t\t***************************\n\n");

    printf("\n\n\t\tNOW: %d-%d-%d %d:%d:%d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    printf("\n\t\t*PLEASE INPUT THE DATE AND TIME ACCORDING TO THE PRESENT...");
    printf("\n\n\tENTER TITLE OF DIARY: ");
    gets(d[i].title);
    gets(d[i].title);
    fprintf(fp,d[i].title);
    fprintf(fp,"\n");

    printf("\n\n\tENTER DATE OF YOUR DIARY:[yyyy-mm-dd]: ");
    scanf("%s",&d[i].date);
    fprintf(fp,d[i].date);
    fprintf(fp,"\n");

    printf("\n\n\tENTER TIME OF YOUR DIARY:[hh:mm]: ");
    scanf("%s",&d[i].time);
    fprintf(fp,"Time: ");
    fprintf(fp,d[i].time);
    fprintf(fp,"\n");

    printf("\n\n\tENTER PLACE OF YOUR DIARY: ");
    gets(d[i].place);
    gets(d[i].place);
    fprintf(fp,"Place: ");
    fprintf(fp,d[i].place);
    fprintf(fp,"\n");

    printf("\n\n\tENTER DURATION OF YOUR DIARY: ");
    gets(d[i].duration);
    fprintf(fp,"Duration: ");
    fprintf(fp,d[i].duration);
    fprintf(fp,"\n");

    printf("\n\n\tSTART WRITING NOTE OF YOUR DIARY: \n\t\t");
    gets(d[i].note);
    fprintf(fp,"Note: ");
    fprintf(fp,d[i].note);
    fprintf(fp,"\n");

    i++;

    while (i>=0){
        int yn;
        printf("Do you want to add another dairy? (Yes~Press[1] / No~Press[0])");
        scanf("%d",&yn);
        if(yn == 0){
            break;
        }if(yn == 1){
            printf("\n\n\tNOW:  %d-%d-%d %d:%d:%d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

            printf("\n\n\tENTER TITLE OF DIARY: ");
            gets(d[i].title);
            gets(d[i].title);
            fprintf(fp,d[i].title);
            fprintf(fp,"\n");


            printf("\n\n\tENTER DATE OF YOUR DIARY:[yyyy-mm-dd]: ");
            scanf("%s",&d[i].date);
            fprintf(fp,d[i].date);
            fprintf(fp,"\n");

            printf("\n\n\tENTER TIME OF YOUR DIARY:[hh:mm]: ");
            scanf("%s",&d[i].time);
            fprintf(fp,"Time: ");
            fprintf(fp,d[i].time);
            fprintf(fp,"\n");

            printf("\n\n\tENTER PLACE OF YOUR DIARY: ");
            gets(d[i].place);
            gets(d[i].place);
            fprintf(fp,"Place: ");
            fprintf(fp,d[i].place);
            fprintf(fp,"\n");

            printf("\n\n\tENTER DURATION OF YOUR DIARY: ");
            gets(d[i].duration);
            fprintf(fp,"Duration: ");
            fprintf(fp,d[i].duration);
            fprintf(fp,"\n");

            printf("\n\n\tSTART WRITING NOTE OF YOUR DIARY: \n\t\t");
            gets(d[i].note);
            fprintf(fp,"Note: ");
            fprintf(fp,d[i].note);
            fprintf(fp,"\n");

            i++;
        }
    }
    fclose (fp) ;
    printf("\n\n\tPRESS ANY KEY TO EXIT...");
    getch();
    system("cls");
}
void viewDiary(){
    system("cls");
    FILE *fp;
    int i = 0;
    char str[100][1000];
    char* filename = "Diary.txt";

    fp = fopen(filename, "r");

    if (fp == NULL){
        printf("Could not open file");
    }
    while (fgets(str[i],1000, fp) != NULL){
        if(i==0){
            printf("%d.%s",i+1, str[i]);
        }else if((i%6 != 0)&&(i < 6)){
            printf("\t%s",str[i]);
        }else if(i % 6 == 0){
            printf("%d.%s",(i/6)+1, str[i]);
        }else if((i%6 != 0)&&(i > 6)){
            printf("\t%s",str[i]);
        }
        i++;
    }
    fclose(fp);
    printf("\n\n\tPRESS ANY KEY TO EXIT...");
    getch();
    system("cls");
}
void ViewSpecificDiary(){
    system("cls");
    FILE *fp;
    int i =0,j=0,k=0,c=0;
    int opt,flag;
    char str[100][1000],strc[100][1000],date[10],title[1000];
    char* filename = "Diary.txt";

    printf("\t\t***********************\n");
    printf("\t\t*VIEW A DETAILED DIARY*\n");
    printf("\t\t***********************\n\n\n");

    printf("\t\tPRESS[1] TO VIEW DIARY BY TITLE\n");
    printf("\t\tPRESS[2] TO VIEW DIARY BY DATE\n");
    printf("\t\tPRESS[0] TO STOP THIS OPERATION\n");
    int n;
    fp = fopen(filename, "r");
    while(10){
        printf("ENTER YOUR OPTION: ");
        scanf("%d",&opt);

        if(opt == 1){

            printf("\n\nINPUT THE TITLE: ");
            getchar();
            scanf("%[^\n]s", title);

            while (fgets(str[i],1000, fp) != NULL){
                flag = compare(str[i],title);
                if(flag == 10){
                    i++;
                    while (fgets(str[i],1000, fp) != NULL){
                        if(i==1 || i%6 ==1){
                            printf("\n\t\tDate:%s",str[i]);
                            i++;
                        }
                        printf("\t\t%s\n",str[i]);
                        if(i%6==0){
                            break;
                        }
                        i++;
                    }
                    break;
                }

                i++;
            }
            if(flag ==10){
                break;
            }
            printf("We cannot find your title...");
            break;
        }else if(opt == 2){
            printf("\n\nINPUT THE DATE:(yyyy:mm:dd): ");
            scanf("%s",&date);
            while (fgets(str[i],1000, fp) != NULL){
                flag = compare(str[i],date);
                if(flag == 10){
                    printf("\n\t\tThe title: %s\n",str[i-1]);
                    i ++;
                    while (fgets(str[i],1000, fp) != NULL){
                        if(i%6==0){
                            break;
                        }
                        printf("\t\t%s\n",str[i]);
                        i++;
                    }
                    break;
                }

                i++;
            }
            if(flag ==10){
                break;
            }
            printf("We cannot find your title...");
            break;
        }else if(opt == 0){
            break;
        }else{
            printf("\tWe don't recognize your key \n\tPlease try again...\n");
            break;
        }
    }
    fclose(fp);
    printf("\n\n\tPRESS ANY KEY TO EXIT...");
    getch();
    system("cls");
}
void editDiary(){
    FILE *fp;

    struct Diary D;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int i = 0,opt,m,j,n=0;
    char str[100][1000],strc[100][1000];
    char *filename = "Diary.txt";

    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Could not open file %s",filename);
    }
    while (fgets(str[i],1000, fp) != NULL){
        if(i==0 || i%6 == 0){
            printf("%d.%s",(i/6)+1,str[i]);
        }
        strcpy(strc[i],str[i]);
        i++;
        n++;
    }
    fclose(fp);

    printf("Which number of daily would you like to edit? ");
    scanf("%d",&opt);

    m = ( opt - 1 ) * 6;

    fp = fopen(filename,"w");
    for(j = 0; j < n; j++){
        if(j == m){
            while(j != m + 6){
                if(j == m){
                    printf("\n\tSTART UPDATE YOUR DATA...");
                    printf("\n\n\tNOW: %d-%d-%d %d:%d:%d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
                    printf("\n\n\tENTER TITLE OF DIARY: ");
                    gets(D.title);
                    gets(D.title);
                    fprintf(fp,D.title);
                    fprintf(fp,"\n");
                }else if(j == m+1){
                    printf("\n\n\tENTER DATE OF YOUR DIARY:[yyyy-mm-dd]: ");
                    scanf("%s",&D.date);
                    fprintf(fp,D.date);
                    fprintf(fp,"\n");
                }else if(j == m+2){
                    printf("\n\n\tENTER TIME OF YOUR DIARY:[hh:mm]: ");
                    scanf("%s",&D.time);
                    fprintf(fp,"Time: ");
                    fprintf(fp,D.time);
                    fprintf(fp,"\n");
                }else if(j == m+3){
                    printf("\n\n\tENTER PLACE OF YOUR DIARY: ");
                    gets(D.place);
                    gets(D.place);
                    fprintf(fp,"Place: ");
                    fprintf(fp,D.place);
                    fprintf(fp,"\n");
                }else if(j == m+4){
                    printf("\n\n\tENTER DURATION OF YOUR DIARY: ");
                    gets(D.duration);
                    fprintf(fp,"Duration: ");
                    fprintf(fp,D.duration);
                    fprintf(fp,"\n");
                }else if(j == m+5){
                    printf("\n\n\tSTART WRITING NOTE OF YOUR DIARY: \n\t\t");
                    gets(D.note);
                    fprintf(fp,"Note: ");
                    fprintf(fp,D.note);
                    fprintf(fp,"\n");
                    break;
                }
                j++;
            }

            continue;
        }
        fprintf(fp, strc[j]);
    }
    fclose(fp);

    getchar();
    printf("\n\n\tPRESS ANY KEY TO EXIT...");
    system("cls");
}
void CustomeRange(){
    system("cls");
    FILE *fp;
    int n1,n2;
    int i =0,j=0,k=0,c=0,n;
    int opt;
    char str[100][1000],strc[100][1000],date[10],title[1000];
    char* filename = "Diary.txt";

    printf("\t\t***********************\n");
    printf("\t\t*VIEW A DETAILED DIARY*\n");
    printf("\t\t***********************\n\n\n");

    fp = fopen(filename,"r");
    while (fgets(str[i],1000, fp) != NULL){
        if(i == 1 || i%6 == 1){
            printf("%d.Date: %s",(i/6)+1,str[i]);
        }
        strcpy(strc[i],str[i]);
        i++;
        n++;
    }
    fclose(fp);
    printf("INPUT THE NUMBER FOR THE STARTING DATE: ");
    scanf("%d",&n1);
    printf("INPUT THE NUMBER FOR THE ENDING DATE: ");
    scanf("%d",&n2);
    fp = fopen(filename,"r");
    for(i =0; i<n; i++){
        if((i/6)+1 == n1){
            printf("\n\tTITLE: %s",strc[i]);
            i++;
            printf("\n\tSTARTING DATE %s",strc[i]);
            i++;
            printf("\n\t%s",strc[i]);
            i++;
            printf("\n\t%s",strc[i]);
            i++;
            printf("\n\t%s",strc[i]);
            i++;
            printf("\n\t%s",strc[i]);
        }else if(i%6 == 1){
            if(((i/6)+1 > n1) && ((i/6)+1 < n2 )){
                printf("\n\tTITLE: %s",strc[i-1]);
                printf("\n\tDATE %s",strc[i]);
                i++;
                printf("\n\t%s",strc[i]);
                i++;
                printf("\n\t%s",strc[i]);
                i++;
                printf("\n\t%s",strc[i]);
                i++;
                printf("\n\t%s",strc[i]);
            }
        }else if((i/6)+1 == n2){
            printf("\n\tTITLE: %s",strc[i]);
            i++;
            printf("\n\tENDING DATE %s",strc[i]);
            i++;
            printf("\n\t%s",strc[i]);
            i++;
            printf("\n\t%s",strc[i]);
            i++;
            printf("\n\t%s",strc[i]);
            i++;
            printf("\n\t%s",strc[i]);
        }

    }

    fclose(fp);

    printf("\n\n\tPRESS ANY KEY TO EXIT...");
    getch();
    system("cls");

}
int compare(char * str1, char * str2){
    int i = 0;

    /* Iterate till both strings are equal */
    while(str1[i] == str2[i])
    {
        if(str1[i] == '\0' && str2[i] == '\0')
            break;

        i++;
    }

    // Return the difference of current characters.
    return str1[i] - str2[i];
}
void deleteDiary(){
    system("cls");

    int CH,i=0,j=0,n=0,m;
    int delete_line;
    char strc[100][1000];
    char str[100][1000];
    FILE *fp;
    char *filename = "Diary.txt";

    printf("\t\t****************\n");
    printf("\t\t*DELETE A DIARY*\n");
    printf("\t\t****************\n\n\n");

    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Could not open file %s",filename);
        getchar();
        system("cls");
    }
    while (fgets(str[i],1000, fp) != NULL){

        if(i==0 || i%6 == 0){
            printf("\t\t%d.%s",(i/6)+1,str[i]);
        }
        strcpy(strc[i],str[i]);

        i++;
        n++;
    }
    fclose(fp);

    printf("\t\tWhich diary do you want to delete?\n");
    printf("\t\tINPUT YOUR CHOICE: ");
    scanf("%d",&CH);

    m = ( CH - 1 ) * 6;
    fp = fopen(filename,"w");
    for(j = 0; j < n; j++){
        if(j == m){
            j += 5;
            printf("SUCCESSFULLY DELETED...\n");
            continue;
        }
        fprintf(fp, strc[j]);
    }
    fclose(fp);

    printf("\n\n\tPRESS ANY KEY TO EXIT...");
    getch();
    system("cls");
}
