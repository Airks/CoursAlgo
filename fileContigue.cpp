#include <iostream>
#define TAILLE_MAX 100

using namespace std;

struct File{
    int tete, queue;
    double T [TAILLE_MAX] ;
};

File Init_F();
bool Vide(File);
bool Pleine(File);
bool insertion(File &, double);
void affichage(File);
double consultation(File);
double suppression(File &);
int succ(int);

int main(int argc, char *argv[]){
    
    return 0;
}

// Crée une file vide
File Init_F (){
    File f;
    f.tete = 0;
    f.queue = TAILLE_MAX;
    return f;
}

// Vérifie si la file est vide
bool Vide(File f){
    return succ(f.queue == f.tete);
}

// Vérifie si la file est pleine
bool Pleine(File f){
    return succ(succ(f.queue)) == f.tete;
}

// Insère un nouvel élément dans la file
bool insertion(File & f, double data){
    if (!Pleine(f)){
        f.T[succ(f.queue)] = data;
        f.queue = succ(f.queue);
        return true;
    }else{
        return false;
    }
}

// Affiche la file
void affichage(File f){
    if (Vide(f)){
        cout << "La file est vide" << endl;
    }else{
        int temp = f.tete;
        cout << "[" ;
        while (temp <= f.queue){
            cout << " " << f.T[temp] << " ";
            temp ++;
        }
        cout << "]" << endl;
        if (Pleine(f)){
            cout << "La file est pleine" << endl;
        }
    }
}

// A n'utiliser que si la file est non vide
double consultation(File f){
    return f.T[f.tete];
}

// A n'utiliser que si la file est non vide
double suppression(File & f){
    double temp = f.T[f.tete];
    f.tete = succ(f.tete);
    return temp;
}

// Retourne l'indice de la prochaine position dans la file
int succ(int indice){
    if (indice == TAILLE_MAX - 1){
        return 0;
    }else{
        return ++indice;
    }
}