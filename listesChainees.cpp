#include <iostream>

using namespace std;

struct Maillon{
    Maillon * suivant;
    double valeur;
};

Maillon * creerListe();
void insererTete(Maillon* &, double);
void supprimerListe(Maillon * &);

int main(int argc, char *argv[]){

    Maillon * liste = creerListe();

    for (int i = 0; i < 3; i++){
        insererTete(liste, i);
    }
    
    supprimerListe(liste);

    return 0;
}

// Retourne la liste vide, soit NULL
Maillon * creerListe(){
    return NULL;
}

void insererTete(Maillon * & tete, double val){
    // Initialisation de la tête dans le cas où la liste vient d'être créée.
    if (tete == NULL){
        tete = new Maillon;
        tete -> suivant = NULL;
        tete -> valeur = val;
    }else{
        Maillon * temp = new Maillon;
        temp -> suivant = tete;
        tete = temp;
        tete -> valeur = val;
        
    }

}

void supprimerListe(Maillon * & tete){
    if (tete -> suivant == NULL){
        delete tete;
    }else{
        supprimerListe(tete -> suivant);
        delete tete;
    }
}