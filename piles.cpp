#include <iostream>

using namespace std;

class EmptyStack : public exception {
    public : const char * what() {
        return "The stack is empty!";
    }
};


struct Stage{
    Stage * next;
    double value;
};

Stage * createStack();
double peek(Stage *);
void push(Stage *&, double);
double pop(Stage *&);
bool isEmpty(Stage *);

int main(int argc, char *argv[]){
    
    Stage * stack = createStack();
    push(stack, 50);
    cout << isEmpty(stack) << endl;
    try {
        cout << peek(stack) << endl;
    }catch (EmptyStack & e){
        cout << e.what() << endl;
    }
    pop(stack);
    cout << isEmpty(stack);
    return 0;
}

// Ne doit pas être appelée si la pile est vide
double peek(Stage * p){
    if (isEmpty(p)){
        throw EmptyStack();
    }
    return p -> value;
}

void push(Stage * & p, double data){
    Stage * newStage = new Stage;
    newStage -> value = data;
    newStage -> next = p;
    p = newStage;
}

// Ne doit pas être appelée si la pile est vide
double pop(Stage * & p){
    Stage * temp = p;
    double tempVal = p -> value;
    p = p -> next;
    delete temp;
    return tempVal;
}

Stage * createStack(){
    Stage * s = nullptr;
    return s;
}

bool isEmpty(Stage * s){
    return (s == nullptr);
}