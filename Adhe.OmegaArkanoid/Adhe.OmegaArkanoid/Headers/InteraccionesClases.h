#ifndef INTERACCIONESCLASES_H_INCLUDED
#define INTERACCIONESCLASES_H_INCLUDED

#include <math.h>

using namespace sf;


/**PODEMOS ENVIAR EL ELEMENTO DEL RENDERWINDOW
USAR LA MISMA VENTANA PARA TODAS LAS FUNCIONES.

**/

void CentrarSprite( Sprite& Rectangulo,float ResX,float PosY)
{
float Large=(Rectangulo.getGlobalBounds().width) /2 ;
Rectangulo.setPosition(ResX/2-Large,PosY);
}

void CentrarTexto(Text &Titulo,float ResX,float PosY ){

float Large=(Titulo.getGlobalBounds().width) /2 ;

Titulo.setPosition(ResX/2-Large,PosY);

}

bool Colission( RectangleShape Bloque ,CircleShape Ball  ){
 if (Bloque.getGlobalBounds().intersects(Ball.getGlobalBounds() ) )   return true;
return false;
}

void AllCollisiones(Blockes &Enemigos,Esfera &Ball){

Vector2f BallPos =Ball.getBallPosition();
Vector2f EnemiePos=Enemigos.getBlockPos();




bool CheckCollisions=false;

              if( ( BallPos.x < Enemigos.getBlockPos().x)||
                 (BallPos.x+Ball.getBallDiameter()  > Enemigos.getBlockPos().x +Enemigos.getTamX() +Ball.getBallDiameter())   ) {
              Enemigos.PlayCollision();

               Ball.setPolarityX( -1);

              }else if( (BallPos.y < Enemigos.getBlockPos().y ) ||
             (BallPos.y +Ball.getBallDiameter() > Enemigos.getBlockPos().y+Enemigos.getTamY()-Ball.getBallDiameter() )     ) {
                                       Enemigos.PlayCollision();

                                       Ball.setPolarityY( -1);
                                    }


    Enemigos.DownVida();////REDUCIMOS LA VIDA DEL BLOCKE EN -1
if (Enemigos.getVida()==0){ cout<<"DEAD BLOCK"<<endl; Enemigos.PlayDestroy();      }
switch (Enemigos.getVida()){
case 1:  Enemigos.SetRedBlock();
    break;
case 2: Enemigos.SetYellowBlock();
    break;
case 3: Enemigos.SetGreenBlock();
    break;
                    }

}


bool Collisions(Blockes &Enemigos,Esfera &Ball){


Vector2f BallPos =Ball.getBallPosition();
Vector2f EnemiePos=Enemigos.getBlockPos();


bool BallMoveX,BallMoveY=false,BounceY=false;

bool CheckCollisions=true;

    if ( BallPos.y + Ball.getBallDiameter()<  EnemiePos.y )CheckCollisions=false;
    if ( BallPos.y > EnemiePos.y + Enemigos.getTamY()  )CheckCollisions=false;


    if ( BallPos.x +  Ball.getBallDiameter() < EnemiePos.x )CheckCollisions=false;
    if ( BallPos.x > EnemiePos.x +Enemigos.getTamX()  )CheckCollisions=false;





////REDUCIMOS LA VIDA DEL BLOCKE EN -1
    if (CheckCollisions){

    Enemigos.DownVida();
    Enemigos.PlayCollision();
if (Enemigos.getVida()==0){ cout<<"DEAD BLOCK"<<endl; Enemigos.PlayDestroy();      }
switch (Enemigos.getVida()){
case 1:  Enemigos.SetRedBlock();
    break;
case 2: Enemigos.SetYellowBlock();
    break;
case 3: Enemigos.SetGreenBlock();
    break;


                    }


        }
        return CheckCollisions;
}


int Ramdom(int Var){
int i;
//srand(time(NULL));
srand((unsigned)time(NULL));

//num=rand()%10+1;

  i=rand()%Var+1;
return i;
}


void DOENEMIES( Blockes *Enemigos , int Cant, float ResX,float ResY){

        Vector2f TamBlock= Enemigos->GetBloque().getSize();

        int i=0,k,j=0,Pos=0;
        float AxY=100;
        float Aux1;
        float DistanceX=15,DistanceY=0,Launch=30;
        int EnemyFiles;
        Aux1=Cant/14.0;

        EnemyFiles = (int)ceil(Aux1);

        for(i=0;  i<EnemyFiles;  i++){
            for(  k=0;  k<13;  k++){
                Enemigos[Pos].SetBlueBlock();
                //Enemigos[Pos].setBlockPos( TamBlock.x+TamBlock.x * k+10, AxY+40*i  );
                Enemigos[Pos].setBlockPos( Launch  +    ((TamBlock.x +DistanceX)* k ) , AxY+((TamBlock.y+DistanceY)*i )  );


                if (Pos==Cant)k=14;
                Pos++;
            }
        }


}


void AnglePolarity(Platform &Player,Esfera &Ball){

bool BallMoveX,BallMoveY=false,BounceY=false;
int PlayerPolarity=-1;
float MaxSpeed=16.f;
float MinSpeed=6.f;

Vector2f PlayerPos,EsferaPos;
PlayerPos= Player.getPlayerPosition();
EsferaPos =Ball.getBallPosition();

        //OBTENER POLARIDADES
        if (Ball.getSpeedX() < 0 ) {BallMoveX=false;} else {BallMoveX=true;}
        if (Ball.getSpeedY() > 0 ){BallMoveY=true;}//else {BallMoveY=false;}
        if (Player.getPolarityX()<0 && Player.getPolarityX() !=0 )PlayerPolarity=0;
        else if (Player.getPolarityX()>0 && Player.getPolarityX() !=0 )PlayerPolarity=1;


        //SIMULAR INCREMENTO - DECREMENTO DEL ANGULO AL REBOTAR
        if (PlayerPolarity==0 && BallMoveX ) {if (Ball.getSpeedX()< MaxSpeed )Ball.AddSpeedX(2.0);      }
        if (PlayerPolarity==1 && !BallMoveX ){ if (Ball.getSpeedX()>  -(MaxSpeed) )Ball.AddSpeedX(-2.0);     }

        if (PlayerPolarity==1 &&  BallMoveX ) if (Ball.getSpeedX()> MinSpeed )Ball.AddSpeedX(-2.0);
        if (PlayerPolarity==0 &&  !BallMoveX ) if (Ball.getSpeedX()<  -(MinSpeed) )Ball.AddSpeedX(2.0);

        //EFECTO DE REBOTE INVERSO ARKANOID
        if (!BallMoveX && BallMoveY
            &&  EsferaPos.x >  PlayerPos.x + Player.getPlayerTamX()*7/10  ){
            Ball.setPolarityX(-1);
        }

        if (BallMoveX && BallMoveY
            &&  EsferaPos.x <  PlayerPos.x + Player.getPlayerTamX()*3/10  ){
            Ball.setPolarityX(-1);
        }

Ball.setPolarityY(-1);

}


void VaciarSettings(){
            FILE *Save;
            fopen_s(&Save, "resources/Archives/Settings.dat","wb");
            if(Save==NULL){ cout<<"ERROR TO EMPTY SETTINGS";  }
           fclose(Save);
        cout<<"SETTINGS HAS BEEN EMPTIED"<<endl;
}


#endif // INTERACCIONESCLASES_H_INCLUDED
