//SCOVILLE
#include <iostream>
#include <string>
using namespace std;

enum Color{verde, amarillo, naranja, rojo};

//---REGISTRO---
struct chiles{
	string nombre;
	int shu;
	Color color;
};
typedef chiles CHILE;


struct Nodo{
    CHILE dato;
    struct Nodo *izquierda;
    struct Nodo *derecha;
};
typedef struct Nodo *arbol;

arbol hacerArbol(CHILE ch);

void ponerIzqui(arbol n, CHILE dato);
void ponerDerech(arbol n, CHILE dato);
void agregarNodo(arbol n);

void PreOrd(arbol x);
void InOrd(arbol x);
void PosOrd(arbol x);

//---PROTOTIPOS---

chiles solicitar(){
	chiles ch;
    cout << "Nombre del chile: ";
    getline(cin, ch.nombre);
 
 bool flag2 = true;
    do{
        char opcion = 0;
        cout << "Colores de chile: 1-v (verde), 2-a (amarillo), 3-n (naranja), 4-r (rojo)\n ";
        cout<<"Ingrese una opcion: ";
        cin >> opcion;
        switch(opcion){
            case 'v': 
				ch.color = verde; 
				flag2 = false; 
				break;
            case 'a': 
				ch.color = amarillo; 
				flag2 = false; 
				break;
            case 'n': 
				ch.color = naranja; 
				flag2 = false; 
				break;
            case 'r': 
				ch.color = rojo; 
				flag2 = false; 
				break;
            default: cout << "OPCION NO VALIDA\n";
			break;
        }
    }while(flag2); 
	    
    cout << "Ingrese el SHU(nivel de picoso): ";
    cin >> ch.shu; 
	cin.ignore();
    if (ch.shu<0){
    	
        cout << "DATO ERRONEO: ";
     	cin >> ch.shu; 
		 cin.ignore();
    }
    
    return ch;
}
void MostrarDato(chiles c);
void MostrarPicante(chiles c);
void MostrarRojos(chiles c);

enum comparacion{menorque,mayorque,igualque};
bool comparar(chiles a, comparacion operador, chiles b){
    bool resultado = false;
    switch(operador){
        case menorque: resultado = a.shu < b.shu; break;
        case mayorque: resultado = a.shu > b.shu; break;
        case igualque: resultado = a.shu == b.shu; break;
    }
    return resultado;
}

//________________________________________________________________
int main(){
	cout<<"\t|| ARBOL DE CHILES ||\n\n";
	cout<<"Ingrese la raiz:\n\n ";
	arbol arbol = hacerArbol(solicitar());
	int opcion=0;
	bool flag=true;
	
	cout<<"\n\n1.Ingresar chile\n"; 
	cout<<"2. Mostrar chiles\n"; 
	cout<<"3. Mostrar rojos\n"; 
	cout<<"4. Mostrar mas de 50000 SHU\n";
	cout<<"5. Salir\n";
	cout<<"Opcion: "; cin>>opcion;
	
	switch(opcion){
		
		case 1:
			agregarNodo(arbol);
			break;
		case 2:
			InOrd(arbol);
			break;
		case 3:
			PreOrd(arbol);
			break;
		case 4:
			PosOrd(arbol);
			break;
		case 5:
			flag=false;
			break;
		default:
			cout<<"OPCION NO VALIDA\n";
			break;
	}while(flag);
	
	return 0;
}
//_________________________________________________________________

//---FUNCIONES---

arbol hacerArbol(CHILE ch){
    arbol A = new Nodo;
    A->dato = ch;
    A->izquierda = NULL;
    A->derecha = NULL;
    return A;
}
void ponerIzqui(arbol n, CHILE dato){
    if(n == NULL){
    	cout << "EL ARBOL ESTA VACIO\n";
    }
        
    else if(n->izquierda != NULL){
    	cout << "YA EXISTE\n";
    }
        
    else{
    	n->izquierda = hacerArbol(dato);
    }
        
}
void ponerDerech(arbol n, CHILE dato){
    if(n == NULL){
    	cout << "ARBOL VACIO\n";
    }
        
    else if(n->derecha != NULL){
    	 cout << "YA EXISTE\n";
    }
       
    else{
    	 n->derecha = hacerArbol(dato);
    }
       
}

void agregarNodo(arbol n){
    cout << "Inserte un dato:\n ";
    CHILE dato = solicitar();
    
    arbol x = n;
       cout << "Dato a agregar:\n";
    
   
    while(true){
        if(comparar(dato, igualque, x->dato)){
            cout << "EL DATO YA EXISTE" << endl;
            return;
        }
        else if(comparar(dato, menorque, x->dato)){
            if(x->izquierda == NULL)
                break;
            else
                x = x->izquierda;
        }
        else{
            if(x->derecha == NULL)
                break;
            else
                x = x->derecha;
        }
    }
    
    
    if(comparar(dato, menorque, x->dato))
        ponerIzqui(x, dato);
    else
        ponerDerech(x, dato);

}

//---------------------------
void MostrarDato(chiles ch){
    cout << "Nombre: " << ch.nombre;

cout << " Color: ";
    switch(ch.color){
        case verde: 
		cout << "verde\n";
		break;
		
        case amarillo: 
		cout << "amarillo\n"; 
		break;
		
        case naranja: 
		cout << "naranja\n"; 
		break;
		
        case rojo: 
		cout << "rojo\n";
		break;
        
    }
    cout << "SHU: " << ch.shu;
    
}
void MostrarRojos(chiles ch){
    if (ch.color==rojo)
    {
        cout << "Nombre: " << ch.nombre;

		cout << " Color: ";
    	switch(ch.color){
        	case rojo: 
			cout << "rojo\n";
			break;
        
    	}

    cout << "SHU: " << ch.shu;
    }   
    
}
void MostrarPicante(chiles ch){
    if (ch.shu>50000)
    {
        cout << "Nombre del chile: " << ch.nombre;


cout << " Color: ";
    switch(ch.color){
        case verde: cout << "verde" << endl; break;
        case amarillo: cout << "amarillo" << endl; break;
        case naranja: cout << "naranja" << endl; break;
        case rojo: cout << "rojo" << endl; break;
        
    }

    cout << "SHU: " << ch.shu;
    }
    
    
}

void PreOrd(arbol x){
    if(x != NULL){
        cout << "\n"; 
		MostrarRojos(x->dato);
        PreOrd(x->izquierda);
        PreOrd(x->derecha);
    }
}
void InOrd(arbol x){
    if(x != NULL){
        InOrd(x->izquierda);
        cout << "\n"; 
		MostrarDato(x->dato);
        InOrd(x->derecha);
    }
}
void PosOrd(arbol x){
    if(x != NULL){
        PosOrd(x->izquierda);
        PosOrd(x->derecha);
        cout << "\n"; 
		MostrarPicante(x->dato);
    }
}

