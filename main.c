#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Movie{
  char* name;
  int tool;
  char* genre;
  char* kholase;
  char* director;
};

struct Sans{
  char* date; // 10/10/1000
  char* startTime; // 10:10:10
  char* endTime;
  int availableSits;
  struct Movie movie;
};


struct Salon{
  int numberOfSalon;
  int zarfiatSalon;
  struct Sans* sanses;
};

struct Cinema{
  char* name;
  struct Salon* salons;
};

void view_list(FILE* ptf){
  fseek(ptf,0,SEEK_SET);
  while(feof(ptf)){
    char* str;
    fgets( str, 255, ptf);
    printf("%s\n",str );
  }
}

void reserve_sans(FILE* ptf) {
  struct Sans sans,sans2;
  printf("Enter the name of the movie that you want to reserve:\n");
  scanf("%s",sans.movie.name);
   printf("Enter the Date that you consider:\n");
  scanf("%s",sans.date);
  printf("Enter the start time that you consider:\n");
  scanf("%s",sans.startTime);

  fseek(ptf,0,SEEK_SET);
  while(feof(ptf)){
    fscanf(ptf,"%s %s %s %s %i", sans2.movie.name,
	   sans2.date, sans2.startTime,
	   sans2.endTime, &sans2.availableSits);
    
    if( !strcmp(sans.movie.name, sans2.movie.name) &&
	!strcmp(sans.date, sans2.date) &&
	!strcmp(sans.startTime, sans2.startTime)){
       if(sans2.availableSits > 0){
	 sans2.availableSits--;
	    /* bayad too file ham avazesh konammm!!! */
	 printf("successfuly Reserved!\n");
       }
       else
	 printf("No Sits Available!\n");
    }
    else
      printf("Not Found!\n");
	  
  }
}

int main()
 {
   FILE *ptf = fopen("salon.txt","w+");
   if(ptf)
    return 0;
   
   char c;
   while(1){
     printf("1.view the list 2.reserve 0.exit\n");
     scanf("%c",&c);
     switch(c){

     case '1':
       view_list(ptf);
       break;

     case '2':
       reserve_sans(ptf);
       break;
       
     case '0':
       return 0;
     } 
   }
 }
