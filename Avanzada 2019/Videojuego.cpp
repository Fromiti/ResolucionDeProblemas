/* A usted se le ha pedido que dise�e un videojuego, que se compone de enemigos que luchan contra h�roes. En espec�fico se le pide
que:

Programe la clase Entidad, que posee vida (int) y nombre, programar getters, setters y constructor.

Programe la clase Enemigo, que posee vida (int), nombre, ataque (int) y descripci�n. Programe getters y setters y un constructor.

Programe la clase Heroe, que posee vida (int), ataque (int) y nombre. Programe getters, setters y constructor

Programe la clase Juego, que posee 50 enemigos, 1 h�roe, un nombre y una descripci�n. Programe getters y setters para el nombre
y la descripci�n, y un constructor que reciba estos par�metros tambi�n.

Cree el m�todo addEnemigo de la clase Juego, que dado un enemigo, lo agrega al arreglo de enemigos del juego.

Cree el m�todo addHeroe, que dado un h�roe lo agrega como h�roe del juego.

Cree el m�todo atacarEnemigo del juego, que recibe un nombre (string), y le quita al enemigo de ese nombre dentro del arreglo
tanta vida como el ataque del h�roe del juego, y le quita al heroe tanta vida como el ataque del enemigo.. De no existir h�roe, o no
existir enemigo con ese nombre, no hace nada.

Pruebe todo lo anterior en la funci�n main(): Cree un par de enemigos, un h�roe, un juego, agregue enemigos y heroe al juego, use
atacarEnemigo un par de veces y mediante couts verifique que la vida de los enemigos va bajando. */
#include<iostream>
#include<conio.h>
using namespace std;
class Entidad{
	protected:
		int vida;
		string nombre;
	public:
		Entidad(int vida, string nombre){
			this->vida = vida;
			this->nombre = nombre;
		}
		void setVida(int vida){
			this->vida = vida;
		}
		void setNombre(string nombre){
			this->nombre = nombre;
		}
		int getVida(){
			return vida;
		}
		string getNombre(){
			return nombre;
		}	
};
class Heroe: public Entidad{		// Herencia de atributos vida y nombre.
	protected:
		int ataque;
	public:
		Heroe(int vida, string nombre, int ataque):Entidad(vida, nombre){
			this->ataque  = ataque;
		}
		void setAtaque(int ataque){
			this->ataque = ataque;
		}
		int getAtaque(){
			return ataque;
		}			
};
class Enemigo: public Heroe{	// Herencia de atributos vida, nombre y ataque
	private: 
		char descripcion[50];
	public:
		Enemigo(int vida, string nombre, int ataque, char descripcion[50]):Heroe(vida, nombre, ataque){
			this->descripcion[50] = descripcion[50];
		}
		void setDescripcion(char descripcion[50]){
			this->descripcion[50] = descripcion[50];
		}
		char getDescripcion(){
			return descripcion[50];
		}	
};
class Juego{
	private:
		string name;
		char d[30];
		Enemigo *enemigos[50];
		Heroe *heroe;
	public:
		Juego(string name, char d[30]){
			this->name = name;
			this->d[30] = d[30];
		}
		void setNombre(string nombre){
			this->name = nombre;
		}
		string getNombre(){
			return name;
		}
		void setDescripcion(char d[30]){
			this->d[30] = d[30];
		}
		char getDescripcion(){
			return d[30];
		}
		void addEnemigo(Enemigo *e){
			for(int i = 0; i < 50; i++){
				if(enemigos[i] == NULL){
					enemigos[i] = e;
					break;
				}
				if(enemigos[49] != NULL){
					cout<<"No hay espacio para mas enemigos"<<endl;
					break;
				}
			}
		}
		void addHeroe(Heroe *h){
			if(heroe == NULL){
				heroe = h;
			}else{
				cout<<"Ya hay un heroe en el juego!"<<endl;
			}
			
		}
		void atacarEnemigo(string nombreEnemigo){
			for(int i = 0; i < 50; i++){
				if(enemigos[i]->getNombre() == nombreEnemigo){
					if(heroe != NULL){
					cout<<"El heroe a atacado al enemigo: "<<nombreEnemigo<<"!!"<<endl;
					enemigos[i]->setVida(enemigos[i]->getVida() - heroe->getAtaque());
					cout<<"La vida del enemigo quedo en "<<enemigos[i]->getVida()<<endl;
					}else{
						break;
					}
				}
			}
		}
};
int main(){
	Juego *juego = new Juego("Elcallampa","un juego en el q te culean rico");
	
	
	
	
	
	
	
	getch();
	return 0;
}
