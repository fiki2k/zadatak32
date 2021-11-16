// Program ce sortirat polje pomocu quicksort metode.

#include<stdio.h>
void quicksort(int polje[50],int prvi,int zadnji){
   int i, j, pivot, temp;

	/*Prv izaberemo neki element kojeg nazovemo pivot,
	Podjelimo nesortirane elemente u 2 polja 
	elementi koji su manji od pivota idu u prvo polje 
	a koji su veci u drugo polje.
	ponavljamo 2.korak.  */ 

   if(prvi<zadnji){
      pivot=prvi;
      i=prvi;
      j=zadnji;

      while(i<j){
         while(polje[i]<=polje[pivot]&&i<zadnji)
            i++;
         while(polje[j]>polje[pivot])
            j--;
         if(i<j){
            temp=polje[i];
            polje[i]=polje[j];
            polje[j]=temp;
         }
      }

      temp=polje[pivot];
      polje[pivot]=polje[j];
      polje[j]=temp;
      quicksort(polje,prvi,j-1);
      quicksort(polje,j+1,zadnji);

   }
}

int main(){
   int i, broj, polje[50];

   printf("Koliko elemenata ces unijeti?: ");
   scanf("%d",&broj);

   printf("Unesi %d elemente: ", broj);
   for(i=0;i<broj;i++)
      scanf("%d",&polje[i]);

   quicksort(polje,0,broj-1);

   printf("Sortirano polje: ");
   for(i=0;i<broj;i++)
      printf(" %d",polje[i]);

   return 0;
}
