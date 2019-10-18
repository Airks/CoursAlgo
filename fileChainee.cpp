#include <iostream>

using namespace std;

struct Maillon{
    Maillon * suivant;
    double donnee;
};

struct File {
    Maillon * tete;
    Maillon * queue;
};

void Init_F(File &);
bool Vide(File);
void insertion(File &, double);
void affichage(File);
double consultation(File);
double suppression(File &);

int main(int argc, char *argv[]){
    
    File file;
    Init_F(file);

    printf("File vide : %d\n", Vide(file));
    for (int i = 0; i < 10; i++){
        insertion(file, i);
    }
    printf("File vide : %d\n", Vide(file));
    affichage(file);

    printf("Premier élément: %.2f\n", suppression(file));

    affichage(file);

    while (!Vide(file)){
        suppression(file);
    }
    affichage(file);
    
    return 0;
}

void Init_F(File & f){
    f.tete = nullptr;
    f.queue = nullptr;
}

bool Vide(File f){
    return (f.tete == nullptr && f.queue == nullptr);
}

void insertion(File & f, double donnee){
    if ( Vide(f) ){
        f.queue = new Maillon;
        f.queue -> donnee = donnee;
        f.tete = f.queue;
    }else{
        f.queue -> suivant = new Maillon;
        f.queue = f.queue -> suivant;
        f.queue -> donnee = donnee;
    }
}

void affichage(File f){
    Maillon * temp = f.tete;
    cout << "[" ;
    while (temp != nullptr){
        cout << " " << temp -> donnee << " " ;
        temp = temp -> suivant;
    }
    cout << "]" << endl;
}

// Ne doit pas être utilisée si la file est vide.
double consultation(File f){
    return f.tete -> donnee;
}

// Ne doit pas être utilisée si la file est vide.
// Retourne l'élément supprimé.
double suppression(File & f){
    double temp = f.tete -> donnee;
    Maillon * gomme = f.tete;
    f.tete = f.tete -> suivant;
    
    // Si c'est le dernier élément de la liste
    if (f.tete == nullptr){
        f.queue = nullptr;
    }
    delete gomme;
    return temp;
}