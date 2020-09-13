#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define ANNEE_MIN 1600

int main(void) {
  int j,m,a;
  int nbJoursMax;
  scanf("%2d %2d %4d",&j,&m,&a);
  //vérification de la date
  if (a<ANNEE_MIN) {
    fprintf(stderr ,"Année %d incorrecte < %d\n",a, ANNEE_MIN);
    return EXIT_FAILURE;
  }
  // année valide, on vérifie maintenant le mois
  if (m<1 || m>12) {
    fprintf(stderr , "mois %d incorrect\n",m);
    return EXIT_FAILURE;
  }
  // mois et année valides => vérifier le jour
  // mois avec 31 jours
  switch(m){
  case 1:
  case 3:
  case 5:
  case 7:
  case 8:
  case 10:
  case 12:
  if (j<1 || j>31) {
       fprintf(stderr , "jour %d incorrect\n",j);
       return EXIT_FAILURE;
       }
  // on test à part le cas du 31 décembre
  else if (j==31){
    if (m==12){
      printf("1 janvier %d\n",a+1);
    }
    //à la fin du mois on passe au mois suivant
    else
      printf("1 mois suivant %d\n",a);
  }
  // sinon il n'y a que le jour qui change
  else
    printf("%d mois en cours %d\n",j+1,a);
  }
  // mois avec 30 jours
  switch(m){
  case 4: 
  case 6:
  case 9:
  case 11:
  if (j<1 || j>30) {
       fprintf(stderr , "jour %d incorrect\n",j);
       return EXIT_FAILURE;
       }
  else
    //à la fin du mois on passe au mois suivant
    if (j==30){
      printf("1 mois suivant %d\n",a);
  }
  // sinon il n'y a que le jour qui change
    else
      printf("%d mois en cours %d\n",j+1,a);
    }
  // cas du mois de février : on doit tester l'année
  if (m == 2) {
    if ((a%4==0 && a%100 != 0) || (a%400==0)) { //année bissextile
      if (j<1 || j>29) {
	fprintf(stderr , "jour %d incorrect\n",j);
        return EXIT_FAILURE;
       }
      else
	if (j==29){
	  printf("1 mars %d\n",a);
	}
	else
	  printf("%d février %d\n",j,a);
	    }
    //sinon l'année n'est pas bissextile
    else
      if (j<1 || j>28) {
	fprintf(stderr , "jour %d incorrect\n",j);
        return EXIT_FAILURE;
       }
      else
	if (j==28) {
	   printf("1 mars %d\n",a);
	}
        else
	  printf("%d février %d\n",j,a);
	    }
}
  
