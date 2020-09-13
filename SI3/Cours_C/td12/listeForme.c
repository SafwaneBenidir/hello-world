#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef enum{ carre, rond, triangle } forme;
typedef struct noeud {
  forme f;
  struct noeud *suivant;
} * ListeDeFormes;

void afficherForme(forme f){
  switch (f) {
    case carre : printf("carre \n"); break;
    case rond : printf("rond \n"); break;
    case triangle : printf("triangle \n"); break;
    default : printf("forme inconnue \n");
  }
}

void afficherListedeFormes(ListeDeFormes lf){
  while(lf!=NULL){
    afficherForme(lf->f);
    lf=lf->suivant;
  }
}

int longueur(ListeDeFormes l){
  int i=0;
  while( l!=NULL){
    i++;
    l=l->suivant;
  }
  return i;
}

forme ieme(ListeDeFormes l, int r){
  int i=0;
  while(i<r){
    while( l!=NULL){
    i++;
    l=l->suivant;
    }
    afficherForme(l->f);
  }
}

void inserer(ListeDeFormes *l, const int r, forme f){
  //r est le rang
  assert(r >= 1 && r <= longueur(*l)+1);
  struct noeud *p = malloc(sizeof(struct noeud));
  p -> f=f;
  if (r==1){
    p -> suivant=*l;
    *l = p;
  }
  else { // 1 < r <=longueur(*l) + 1
    struct noeud *q = *l;
    for (int i=2 ; i < r ; i++)
      q = q -> suivant;
    // q pointe sur le noeud au rang r-1
    p -> suivant = q -> suivant;
    q -> suivant = p;
  }
}


    
int main(void){
  ListeDeFormes *lf;
  struct noeud *p;
  struct noeud *q;
  struct noeud *r;
  p=malloc(sizeof(struct noeud));
  //(*p).f=carre;
  p->f=carre;
  //(*p).suivant=NULL;
  p->suivant=NULL;
  *lf=p;
  q=malloc(sizeof(struct noeud));
  q->f=triangle;
  q->suivant=p;
  *lf=q;
  r=malloc(sizeof(struct noeud));
  r->f=rond;
  r->suivant=q;
  *lf=r;
  afficherListedeFormes(*lf);
  printf("longueur de la liste = %d\n\n",longueur(*lf));
  inserer(lf, 4, rond);
  afficherListedeFormes(*lf);
  printf("longueur de la liste = %d\n",longueur(*lf));
  int x,y,z;
  z=5;
  x=y=6;
  printf("%d %d %d\n",x,y,z);
}
  
  
  
  
