//explication du code

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define AnneeMin 1600

// antécédent
// conséquent

void ecrireDate(int jour, int mois, int annee) {
  printf("%d ",jour);
  switch (mois) {
  case 1 : printf("janvier"); break;
  case 2 : printf("février"); break;
  case 3 : printf("mars"); break;
  case 4 : printf("avril"); break;
  case 5 : printf("mai"); break;
  case 6 : printf("juin"); break;
  case 7 : printf("juillet"); break;
  case 8 : printf("août"); break;
  case 9 : printf("septembre"); break;
  case 10 : printf("octobre"); break;
  case 11 : printf("novembre"); break;
  case 12 : printf("décembre"); break;
    //default : printf(stderr,"mois inconnu\n"); break;
  }
  printf(" %d\n",annee);
}

//antécédent : année valide ie > AnneeMin
//conséquent : vrai si bissextile faux sinon

int bissextile(int annee) {
  return (annee % 4 == 0 && annee % 100 != 0) || annee % 400 == 0;
}

int joursDansMois(int mois, int annee) {
  switch(mois) {
  case 1:
  case 3:
  case 5:
  case 7:
  case 8:
  case 10:
  case 12: return 31;
  case 2: return bissextile(annee) ? 29 : 28;
  default : return 30;
  }
}

int dateValide(int jour,int mois,int annee) {
  if (annee < AnneeMin) return 0;
  if (mois < 1 || mois > 12) return 0;
  return jour>=1 && jour<=joursDansMois(mois,annee);
}



		  
int main(void) {
  int jour,mois,annee;
  scanf("%d %d %d",&jour,&mois,&annee);
  if (!dateValide(jour,mois,annee)) {
    fprintf(stderr,"la date n'est pas valide\n");
    return 1;
  }
  if (jour < joursDansMois(mois,annee))
    jour ++;
  else {
    jour = 1;
    if (mois<12)
      mois ++;
    else {
      mois = 1;
      annee ++;
    }
  }
  ecrireDate(jour,mois,annee);
  return 0;
}
