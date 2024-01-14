/*
************************ CONTACT LIST PROGRAM **********************************
** ADD NAME, MOBILE NUMBER, EMAIL, ADDRESS, GENDER, STATUS, OCCUPATION **
******************** STORE DATA WITHIN A FILE NAMED AS CONTACT DATA ************
*/
// PREPROCESSOR DIRECTIVE HEADER 
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// MAIN() FUNCTION OF THE PROGRAM 
int main (void) {
   // DECLARE VARIABLE
   char name[30],choice[10],email[15],work[30],date[30],number[11],address[100];
   int count = 0,flag,length;

   // INITIALZING FLAG VARIABLE WITH TRUE 1
   flag = 1;
   // FILE POINTER FOR READ AND WRITE FILE
   FILE *file_variable;
   // WRITE A FILE NAMED CONTACT_DATA
   file_variable = fopen ("contact_data.dat","a+");
   if (file_variable == NULL) {
     printf ("SORRY ! FILE NOT OPENNED !\n");
   }
   else {
     printf ("Enter current date : ");
     scanf ("%s",&date);
     getchar();
     fprintf (file_variable,"**********UPDATED  CLIENTS CONTACT LISTS ON %s: *********\n",date); //
    while (1) {
 // READING DATA ON SECONDARY FIL
       begin: fprintf (file_variable,"CLIENT CONTACTS DETAILS -\n"); // READING DATA ON SECONDARY FILE
       printf ("Enter client full name : "); // OUPUT STATEMENT
       // INPUT STATEMENT OF CLIENT NAME
       scanf ("%[^\n]",&name); // INPUT STATEMENT
       fprintf (file_variable,"o Name : %s\n",name);
       getchar(); // INITILIZE NULL \0 OPERATOR AT THE END
       // INPUT STATEMENT OF CLIENT MOBILE NUMBER
       printf ("Enter 10-digit mobile number of client : ");
       scanf ("%s",&number);
       fprintf(file_variable,"o Mobile Number : %s\n",number);
       getchar(); // INITILIZE NULL \0 OPERATOR AT THE END
       printf ("Enter client email : ");
       scanf("%s",&email);
       fprintf(file_variable,"o Email : %s\n",email);
       getchar();
       printf ("Enter client address : ");
       scanf("%[^\n]",&address);
       fprintf(file_variable,"o Address : %s\n",address);
       getchar();
       printf ("Enter client work : \n");
       while (flag) {
        count += 1;
        again: printf ("Work %d : ",count);
        scanf ("%s",&work);
        fprintf (file_variable,"\n\n%s\n",work);
        printf ("Enter okay for complete : ");
        scanf ("%s",&choice);
        getchar();
        if (strcmp (choice,"okay") == 0) {
            flag = 0;
	}
        else {
            goto again;
        }
       }
       fprintf(file_variable,"o Address : %s\n",address);
       getchar();
       // ASK PROGRAM EXIST OR NOT START AGAIN
       printf ("Enter 'yes' if you want to close program \n");
       printf ("Enter any keyword for start over \n");
       scanf ("%s",&choice);
       getchar();
       // CHECK CHOICE IS YES OR NOT
       if (strcmp(choice,"yes") == 0 || strcmp (choice,"YES") == 0 || strcmp (choice,"Yes")) {
        goto stop;
       }
       else {
        goto begin;
       }
    };
   }
   stop: printf ("DATA has been stored with in the file ");
  
    return 0; // IT INDICATES THAT PROGRAM EXECUTE SUCCESSFULLY
}
