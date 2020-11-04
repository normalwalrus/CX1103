#include <stdio.h>
#include <string.h>
#define MAX 100
typedef struct {
   char name[20];
   int telno;
} PhoneBk;

void printPB(PhoneBk *pb, int size);
int readin(PhoneBk *pb);
void search(PhoneBk *pb, int size, char *target);

int main() {
   PhoneBk s[MAX];
   char t[20], *p;
   int size=0, choice;
   char dummychar;

   printf("Select one of the following options: \n");
   printf("1: readin()\n");
   printf("2: search()\n");
   printf("3: printPB()\n");
   printf("4: exit()\n");
   do{
      printf("Enter your choice: \n");
      scanf("%d", &choice);
      switch (choice)
        {
         case 1:
            scanf("%c", &dummychar);
            size= readin(s);
            break;
         case 2:
            scanf("%c", &dummychar);
            printf("Enter search name: \n");
            fgets(t, 20, stdin);
            if (p=strchr(t,'\n')) *p= '\0';
            search(s,size,t);
            break;
         case 3:
            printPB(s, size);
            break;
            }
   } while (choice < 4);
   return 0;}
void printPB(PhoneBk *pb, int size)
    {
        int g;
        printf("The phonebook list:\n");
        for(g=0; g<size; g++)
        {
            printf("Name: %s\n", pb[g].name);
            printf("Telno: %d\n", pb[g].telno);
        }
    }
int readin(PhoneBk *pb)
    {
        int p;
        p = 0;
        while (0==0)
        {
            printf("Enter name:\n");
            scanf("%s", &pb[p].name);
            if (strcmp(pb[p].name,"#\0")==0)
                return p;
            printf("Enter tel:\n");
            scanf("%d", &pb[p].telno);
            p++;
        }
    }
void search(PhoneBk *pb, int size, char *target)
{
    int g, tru=0;
    for (g=0; g<size; g++)
    {
        printf("%s", target);
        if (strcmp(pb[g].name,target)==0)
        {
            printf("Name= %s,", pb[g].name);
            printf("Tel= %d\n", pb[g].telno);
            tru =1;
        }
    }
    if (tru==0)
        printf("Name not found!\n");
}
