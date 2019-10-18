#include <iostream>
#include <ctime>
#define TAILLE_MAX 100

using namespace std;

struct Liste {
    double T [TAILLE_MAX];
    int length;
};

Liste creerListe();
void inserer(Liste &, double, int = -1);
void insererTete(Liste &, double, bool = true);
void afficherListe(Liste);
int recherche(Liste, double);
void supprimer(Liste &, int);

int main(int argc, char *argv[]){
    
    srand(time(NULL));


    return 0;
}

////////////////////////////////////////////////////////////////

Liste creerListe(){
    Liste liste;
    liste.length = 0;
    return liste;
}

void afficherListe(Liste l){
    cout << "(" ;
    for (int i = 0; i < (l.length - 1); i++)
    {
        cout << l.T[i] <<", ";
    }
    cout << l.T[l.length - 1] << ")" << endl;
    
}

// Si pos == -1, insère en fin de liste
void inserer(Liste &liste, double val, int pos /* = -1 */){
    if (pos == -1){
        liste.T[liste.length] = val;
    }else{
        for (int i = (liste.length - 1); i >= pos; i--){
            liste.T[i+1] = liste.T[i];
        }
        liste.T[pos] = val;
    }
    liste.length ++ ;
}

// Si conserverOrdre == false, le nom parle de lui même
void insererTete(Liste &liste, double val, bool conserverOrdre /* = true */){
    if (conserverOrdre){
        for (int i = (liste.length - 1); i >= 0; i--){
            liste.T[i+1] = liste.T[i];
        }
        liste.T[0] = val;
        
    }else{
        liste.T[liste.length] = liste.T[0];
        liste.T[0] = val;
    }
    liste.length ++;
}

int recherche(Liste liste, double val){
    /* 
        C'est un peu tordu comme raisonnement mais ça fonctionne.
    */
    int indice = -1;
    bool trouve = false;
    do {
        indice ++;
        trouve = (liste.T[indice] == val);
    } while ( !trouve && indice < (liste.length - 1));

    return (trouve)? indice : -1;
}

void supprimer(Liste & liste, int indice){
    /* Il suffit de décaler tous les élements vers la gauche à partir de
        l'indice de l'élément à supprimer.
    */
    for (int i = indice; i < (liste.length - 1); i++){
        liste.T[i] = liste.T[i + 1];
    }
    liste.length --;
}