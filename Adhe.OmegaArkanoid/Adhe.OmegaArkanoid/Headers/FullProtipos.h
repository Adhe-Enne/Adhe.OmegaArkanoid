#ifndef FULLPROTIPOS_H_INCLUDED
#define FULLPROTIPOS_H_INCLUDED

using namespace sf;



/////////JUGABILIDAD
int controles();

//void CREARBLOQUES( Blockes *Ene , int Cant, float ResX,float ResY);
//void CREARBLOQUES(float ResX,float ResY, int Cant);

/////////AUXILIARES MINIMOS
void Testteo();

int Ramdom(int Var);

/////////FUNCIONES DE PANTALLA
void CrearMarco(RectangleShape&LeftM ,RectangleShape&RightM ,RectangleShape&SupM ,int ResX,int ResY);
void CentrarElementX( RectangleShape& Rectangulo,float ResX,float PosY);

////////FUNCONES DE BLOQUES Y/O ESFERA
//bool Colission(RectangleShape Bloque, CircleShape Ball );

//void ChangeBlockColor(Blockes Enemigo);






#endif // FULLPROTIPOS_H_INCLUDED
