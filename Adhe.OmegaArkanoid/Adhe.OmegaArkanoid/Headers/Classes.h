#ifndef CLASSES_H_INCLUDED
#define CLASSES_H_INCLUDED

#include "PathResources.h"

using namespace sf;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**PROTOTIPOS NECESARIOS*/
void CentrarElementX( RectangleShape& Rectangulo,float ResX,float PosY);
void CentrarTexto(Text &Titulo,float ResX,float PosY );
int Ramdom(int Var);
  void VaciarSettings();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**ELEMENTOS DE ALTA IMPORTANCIA**/

class AllFiles{
private:
    int Volumen; //1       Settings.dat
    int Effectos;   //2       Settings.dat

    int HighScore; // Highscore.dat
    bool Lectura;
public:

int LoadSettings(int OP){

    FILE *S;
    fopen_s(&S, "resources/Archives/Settings.dat","rb");

    if(S==NULL){ cout<<"DEFAULT SETTINGS"<<endl;   }
    int Extraer;

    fseek(S, sizeof Extraer *OP,0);
    Lectura=fread(&Extraer, sizeof(Extraer),1,S);
    fclose(S);

    if(Lectura)return Extraer;

    return 80; //default;

}

int LoadHighscore(){

    FILE *H;
    //H=
    errno_t err = fopen_s(&H, "resources/Archives/HighScore.dat","rb");

    if(H==NULL){ cout<<"DEFAULT Puntajes"<<endl; return 10000; }

    int PrimeScore;
    Lectura=fread(&PrimeScore, sizeof(PrimeScore),1,H);
    fclose(H);
    if(Lectura)return PrimeScore;
return 10000;
}

void LoadFiles(){

Volumen=LoadSettings(0);

Effectos=LoadSettings(1);

HighScore=LoadHighscore();

}

AllFiles(){
LoadFiles();

}

const int getVolumen(){return Volumen;}
const int getEfectos(){return Effectos;}
const int getHighScore(){return HighScore;}

~AllFiles(){}

};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///CLASE SUPERBLOQUE
class Blockes{
    private:
///Automatizamos bloques con propiedades preestablecidas
	RectangleShape Bloque;              //CLASE BLOQUES
    Texture ColorBlock;

	SoundBuffer BufferCollision;                //CLASE BUFFER PARA LA CORRECTA CARGA DE SONIDO
    Sound Collision;

	SoundBuffer BufferDestroy;  //CLASE PARA CREAR UNA VARIABLE DE SONIDO
    Sound Destroy;


	Texture Dead;               //CLASE PARA CARGAR UNA TEXTURA DE DESTRUCCION
	Sprite Explosion;               //SPRITE PARA CARGAR LA TEXTURA

	//PROPIEDADES
	float BloqPosX;
	float BloqPosY;
	float BlockTamX;
	float BlockTamY;
	int Vida;
	bool Bonus;
	int TipeBonus;
	int MyColor;
public:

   Blockes(const float PosX=640,const float PosY=300 ,const float TamX=80,const float TamY=20 ){


 srand((unsigned)time(NULL));

    Vida=4;
    Bonus=0;
    TipeBonus=0;
    MyColor=0;
    Bonus=true;
    ///POSICION
    BloqPosX=PosX;
    BloqPosY=PosY;
    ///TAMAÑO
    BlockTamX=TamX;
    BlockTamY=TamY;
    Bloque.setSize(Vector2f(BlockTamX,BlockTamY));
    Bloque.setOutlineColor(Color::Black);
    Bloque.setOutlineThickness(3);
    Bloque.setPosition( BloqPosX, BloqPosY );

    ///SONIDOS DE IMPACTO Y DESTRUCCION DE BLOQUE
BufferCollision.loadFromFile("resources/Sounds/BloqColision.wav");
 Collision.setBuffer(BufferCollision);


BufferDestroy.loadFromFile("resources/Sounds/BloqDestroy.wav");
Destroy.setBuffer(BufferDestroy);


}

void setVolumeEffects(int Vol){
Collision.setVolume(Vol);
Destroy.setVolume(Vol);
}


void SetYellowBlock ();
void SetBlueBlock ();
void SetGreenBlock ();
void SetRedBlock ();

    void setBlockPos(float W, float H){     Bloque.setPosition(W,H );  }
	const float getTamX(){return BlockTamX;}
	const float getTamY() {return BlockTamY;}

const int getVida(){return Vida;}
const RectangleShape GetBloque(){return RectangleShape(Bloque); }
const Vector2f getBlockPos(){  return Vector2f ( Bloque.getPosition());  }

void DownVida(){ Vida--;}
void PlayDestroy(){  Destroy.play(); }
void PlayCollision(){  Collision.play(); }
void DownAlfa(int Alfa){ Bloque.setFillColor(Color(Alfa,Alfa,Alfa,Alfa));  }

///DESTRUCTOR
~Blockes(){}

};

void Blockes::SetBlueBlock (){

Bonus=true;
 int i;

   i=rand()%4;

PathArchivos X;
ColorBlock.loadFromFile(X.BlockBlue[i]);
Bloque.setTexture(&ColorBlock);

}

void Blockes::SetGreenBlock (){
Bonus=true;
PathArchivos X;
 int i;

   i=rand()%4;
ColorBlock.loadFromFile(X.BlockGreen[i]);

Bloque.setTexture(&ColorBlock);


}

void Blockes::SetRedBlock (){

Bonus=true;
int i;
PathArchivos X;
   i=rand()%4;
ColorBlock.loadFromFile(X.BlockRed[i]);
Bloque.setTexture(&ColorBlock);

}

void Blockes::SetYellowBlock (){
Bonus=true;
 int i;
    i=rand()%4;
PathArchivos X;
ColorBlock.loadFromFile(X.BlockYellow[i]);
Bloque.setTexture(&ColorBlock);
}


///ESFERA
class Esfera{
private:

        CircleShape Ball;
        Texture TextureBall;

        SoundBuffer BufferCollisonWall;        // Buffer colison de pared
        Sound CollisonWall;                            //sonido de colision pared

        SoundBuffer BufferCollisonPlayer;   //Buffer colision al jugador
        Sound CollisonPlayer;                       //sonido colision al jugador


        float  Radio;
        float  MoveSpeedX;
        float MoveSpeedY;
        float  PosX;
        float PosY;
        float ResX;
        float ResY;

public:

Esfera(const float  Radius=5.f,const float  Mx= 8.f , const float  My= -8.f){

       ResX=1280;
        ResY=720;
PosX=150;
PosY=10;

///construimos la esfera
Radio=Radius;
MoveSpeedX =Mx;
MoveSpeedY=My;

TextureBall.loadFromFile("resources/Images/MetalBall.jpg");
Ball.setTexture(&TextureBall);
Ball.setRadius(Radio);
Ball.setOutlineThickness(5.f);
Ball.setOutlineColor(Color::Cyan);
Ball.setRadius(Radio);
Ball.setPosition(ResX/2,650-50);

///cargamos y configuramos el sonido 1
BufferCollisonWall.loadFromFile("resources/Sounds/BallCollision.wav");
CollisonWall.setBuffer(BufferCollisonWall);
CollisonWall.setVolume(100);

///cargamos y configuramos el sonido 2
BufferCollisonPlayer.loadFromFile("resources/Sounds/PlayerCollision.wav");
CollisonPlayer.setBuffer(BufferCollisonPlayer);

}

void setVolumeEffects(int Vol){
CollisonWall.setVolume(Vol);
CollisonPlayer.setVolume(Vol );
}

 void PlayCollisionWall(){  CollisonWall.play(); }
 void PlayCollisionPlayer(){  CollisonPlayer.play(); }


///////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////

const float getBallDiameter(){return Radio*2;}
const float getBallPosX () { return PosX;}
const float getBallPosY () { return PosY;}

const float getSpeedX(){return MoveSpeedX;}
const float getSpeedY(){return MoveSpeedY;}

const CircleShape getBall(){return CircleShape(Ball); }
const Vector2f getBallPosition(){   return Vector2f(   Ball.getPosition() );  }
void SetBallPos(float PX, float PY){Ball.setPosition( PX, PY );}

void setPolarityX( float X){ MoveSpeedX*=X;}
void setPolarityY( float Y){ MoveSpeedY *=Y;}

void MoveBall(){Ball.move(MoveSpeedX, MoveSpeedY);}
void MoveBallEspecial(float x,float y){Ball.move(x, y);}

void ResetSpeed(){  MoveSpeedX =8.f; MoveSpeedY=-8.f;    }

void AddSpeedX(float Speed  ){   MoveSpeedX+= Speed;    }
void AddSpeedY(float Speed  ){   MoveSpeedY+= Speed;    }

///DESTRUCTOR
~Esfera(){}
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///JUGADOR
 class Platform{
private:
        //FORMAS
        RectangleShape Player;
        Texture TexturePlayer;
        SoundBuffer DeadB;
        Sound Dead;

        /**PROPIEDADES PREDETERMINADAS*/
        //TAMAÑO JUGADOR
        float PlayerTamX;
        float PlayerTamY;
        //UBICACION JUGADOR
        float PlayerPosX;
        float PlayerPosY;
        //VELOCIDAD JUGADOR
        float SpeedX;
        float SpeedY;
        int Vida;
        int Bonus;

public:

Platform( const float ResX=1280,const float ResY=720){
  //TAMAÑO JUGADOR
        PlayerTamX=200;
        PlayerTamY=30;
        //UBICACION JUGADOR
        PlayerPosX=640;
        PlayerPosY=650;
        //VELOCIDAD JUGADOR
        SpeedX=0.f;
        SpeedY=0.f;
        Vida=3;

TexturePlayer.loadFromFile("resources/Images/BlockSprites/Paddle4.png");
Player.setTexture(&TexturePlayer);
Player.setSize(Vector2f(PlayerTamX,PlayerTamY));
CentrarElementX(Player,ResX,PlayerPosY);

DeadB.loadFromFile("resources/Sounds/DownLife.wav");
Dead.setBuffer(DeadB);
    }

///GETS//SETS
void setVolumeEffects(int Vol){
Dead.setVolume(Vol);
}

void PlayDead(){Dead.play();}
const RectangleShape getPlayer(){ return RectangleShape(Player);}
const Vector2f getPlayerPosition(){ return Vector2f (Player.getPosition());}
const float getPlayerTamX(){return PlayerTamX;}
const float getPlayerTamY(){return PlayerTamY;}
const float getPlayerPosY(){ return PlayerPosY; }
const int getLives(){return Vida;}
const float getPolarityX(){return SpeedX;}

///"setSpeed"//
void DownLive(){ Vida--;   }
void ResetSpeed(){SpeedX=0.f;SpeedY=0.f;}
void setPolarityX(float X){SpeedX=X;}
void LimitPositionX(float X,float Y){Player.setPosition(X,Y);}
void MovePlayer(){  Player.move(SpeedX,SpeedY); }

///DESTRUCTOR
~Platform(){}
};


///ELEMENTOS ADDICIONALES
class Titulos{

private:
Font Principal;
Font ByCar;

Font StartGame;
Font Carpincho;
Font CopyR;
Font BaseOptions;

Text Main;
Text ByCarpincho;
Text Start;
Text Setup;
Text HowToPlay;
Text Scores;
Text QuitGame;

Text Cr;
Text TituloDev;
//
Font Venner;
Font Maxi;

Text Wenner;
Text Wenner2;
//
Font Cont;
Text Continue;
//

SoundBuffer MenuBuffer;
Sound MenuSelect;

SoundBuffer SelectionBuffer;
Sound Selection;

        float LargoText;
        float AlturaTxt;
        float AnchoTxt;
        float TextoY;
        float TextTam;
        float Csnd;
        float ResX;
        float ResY;
        float Tickness;
        float Aux;

public:

///cargamos el texto
Titulos(const float X=1280,const float Y=720){
ResX=X;
ResY=Y;
TextoY=330;
TextTam= 40;
Tickness=4;
Aux=10;

///Titulo Principal
Principal.loadFromFile("resources/Text Style/Base 21.ttf");

Main.setFont(Principal);
Main.setString("Omega's ARKANOID");
Main.setCharacterSize(140);
Main.setFillColor(Color::Cyan);
Main.setOutlineColor(Color::Magenta);
CentrarTexto(Main,ResX,75);
Main.setOutlineThickness(5);

///Titulo segundario
ByCar.loadFromFile("resources/Text Style/Base 23.ttf");

ByCarpincho.setFont(ByCar);
ByCarpincho.setString("By Carpincho - ADN ");
ByCarpincho.setCharacterSize(50);
ByCarpincho.setFillColor(Color::Transparent);
ByCarpincho.setOutlineColor(Color::Magenta);
ByCarpincho.setPosition(ResX*0.58 , ResY*0.3);
ByCarpincho.setOutlineThickness(1);


///cargamos el texto desarrolador
Carpincho.loadFromFile("resources/Text Style/CAPCOM.ttf");
TituloDev.setFont(Carpincho);
TituloDev.setString("CARPINCHO");
TituloDev.setCharacterSize(40);
TituloDev.setFillColor(Color::Yellow);
TituloDev.setOutlineColor(Color::Blue);
TituloDev.setOutlineThickness(5);
CentrarTexto(TituloDev,ResX,650);

///texto copyright
CopyR.loadFromFile("resources/Text Style/CAPCOM.ttf");
Cr.setFont(CopyR);
Cr.setString("®");
Cr.setCharacterSize(20);
Cr.setFillColor(Color::Yellow);
Cr.setOutlineColor(Color::Blue);
LargoText=TituloDev.getLocalBounds().width;
Cr.setPosition(ResX/2 +LargoText/2,655);
Cr.setOutlineThickness(Tickness);

///////////////////////////////TEXTOS DE OPCION MENU////////////////////////////////////
///BASE TE TEXTO:
BaseOptions.loadFromFile("resources/Text Style/Base 15.otf");

///OPCION INICIAR JUEGO
Start.setFont(BaseOptions);
Start.setString("START GAME");
Start.setCharacterSize(TextTam);
Start.setFillColor(Color::White);
Start.setOutlineColor(Color::Black);
Start.setOutlineThickness(Tickness);
CentrarTexto(Start,ResX,TextoY);


///OPCION CONFIGURACION
Setup.setFont(BaseOptions);
Setup.setString("SET UP");
Setup.setCharacterSize(TextTam);
Setup.setFillColor(Color::White);
Setup.setOutlineColor(Color::Black);
LargoText=Setup.getLocalBounds().width;
CentrarTexto(Setup,ResX,TextoY+=60);
Setup.setOutlineThickness(Tickness);

///OPCION COMO JUGAR

HowToPlay.setFont(BaseOptions);
HowToPlay.setString("HOW TO PLAY");
HowToPlay.setCharacterSize(TextTam);
HowToPlay.setFillColor(Color::White);
HowToPlay.setOutlineColor(Color::Black);
CentrarTexto(HowToPlay,ResX,TextoY+=60);
HowToPlay.setOutlineThickness(Tickness);

///OPCION PUNTUACIONES MAXIMAS
Scores.setFont(BaseOptions);
Scores.setString("HIGH SCORES");
Scores.setCharacterSize(TextTam);
Scores.setFillColor(Color::White);
Scores.setOutlineColor(Color::Black);
CentrarTexto(Scores,ResX,TextoY+=60);
Scores.setOutlineThickness(Tickness);

///OPCION SALIR
QuitGame.setFont(BaseOptions);
QuitGame.setString("QUIT GAME");
QuitGame.setCharacterSize(TextTam);
QuitGame.setFillColor(Color::White);
QuitGame.setOutlineColor(Color::Black);
CentrarTexto(QuitGame,ResX,TextoY+=60);
QuitGame.setOutlineThickness(Tickness);


///SONIDO DE MENU SELECTOR
MenuBuffer.loadFromFile("resources/Sounds/select 9.wav");
MenuSelect.setBuffer(MenuBuffer);
MenuSelect.setPitch(2);


///SONIDO SELECTOR 2
SelectionBuffer.loadFromFile("resources/Sounds/select 8.wav");
Selection.setBuffer(SelectionBuffer);
Selection.setPitch(2);


///MENSAJE GANADOR
Maxi.loadFromFile("resources/Text Style/Base 15.otf");
Wenner.setFont(Maxi);
Wenner.setString("You Wenner! ");
Wenner.setCharacterSize(120);
Wenner.setFillColor(Color::Cyan);
Wenner.setOutlineColor(Color::Magenta);
CentrarTexto(Wenner,ResX,200);
Wenner.setOutlineThickness(5);

Venner.loadFromFile("resources/Text Style/Base 23.ttf");
Wenner2.setFont(Venner);
Wenner2.setString("or Venner according Maxi ;D");
Wenner2.setCharacterSize(50);
Wenner2.setFillColor(Color::Cyan);
Wenner2.setOutlineColor(Color::Magenta);
CentrarTexto(Wenner2,ResX,400);
Wenner2.setOutlineThickness(3);

///PRESS ANY KEY TO CONTINUE
Cont.loadFromFile("resources/Text Style/Base 2.ttf");
Continue.setFont(Cont);
Continue.setString("Press Any Key To Continue");
Continue.setCharacterSize(25);
Continue.setFillColor(Color::White);
Continue.setOutlineColor(Color::Black);
Continue.setPosition(ResX*0.5, 600);
Continue.setOutlineThickness(5);


}

void setVolumeEffects(int Vol){
    Selection.setVolume(Vol);
    MenuSelect.setVolume(Vol);

}


void PlaySelect(){    MenuSelect.play();  }
void PlaySelected(){    Selection.play();  }

const Text getCr(){  return Text(Cr);}
const Text getTituloDev(){  return Text(TituloDev);}
const Text getMain(){  return Text(Main);}
const Text getByCar(){  return Text(ByCarpincho);}
const Text getStart(){  return Text(Start);}
const Text getSetup(){  return Text(Setup);}
const Text getHTP(){  return Text(HowToPlay);}
const Text getScores(){  return Text(Scores);}
const Text getQuit(){  return Text(QuitGame);}

const Text getWenner(){ return Text(Wenner);}
const Text getVenner(){ return Text(Wenner2);}
const Text getContinue(){return Text(Continue);}

void ResetColorAll(){
        TextoY=320;
        TextTam= 40;
            Start.setFillColor(Color::White);
            Start.setCharacterSize(TextTam);
            CentrarTexto(Start,ResX,TextoY);

            Setup.setFillColor(Color::White);
            Setup.setCharacterSize(TextTam);
            CentrarTexto(Setup,ResX,TextoY+=60);

            HowToPlay.setFillColor(Color::White);
            HowToPlay.setCharacterSize(TextTam);
            CentrarTexto(HowToPlay,ResX,TextoY+=60);

            Scores.setFillColor(Color::White);
            Scores.setCharacterSize(TextTam);
            CentrarTexto(Scores,ResX,TextoY+=60);

            QuitGame.setFillColor(Color::White);
            QuitGame.setCharacterSize(TextTam);
            CentrarTexto(QuitGame,ResX,TextoY+=60);

    }

void setStartYellow(  ){
    Start.setFillColor(Color::Yellow);
    Start.setCharacterSize(60) ;
    CentrarTexto(Start,ResX,TextoY-Aux);
     }

void setSetupYellow(  ){
    Setup.setFillColor(Color::Yellow);
 Setup.setCharacterSize(60) ;
   CentrarTexto(Setup,ResX,TextoY+60-Aux);
  }

void setHowToPlayYellow(  ){
    HowToPlay.setFillColor(Color::Yellow);
 HowToPlay.setCharacterSize(60) ;
   CentrarTexto(HowToPlay,ResX,TextoY+60*2-Aux);
  }

void setScoresYellow(  ){
    Scores.setFillColor(Color::Yellow);
 Scores.setCharacterSize(60) ;
   CentrarTexto(Scores,ResX,TextoY+60*3-Aux);
 }

void setQuitGameYellow(  ){
    QuitGame.setFillColor(Color::Yellow);
 QuitGame.setCharacterSize(60) ;
   CentrarTexto(QuitGame,ResX,TextoY+60*4-Aux);
  }

bool MouseEffect(const Vector2i &CursorM,const Text &Title,int OPC ,RenderWindow &Win ,int C ){
///efecto selector mouse
float RX,LargTxt ,RY, AltTxt;
float TextY= Title.getGlobalBounds().top;
float ScaleX,ScaleY;
RX=Win.getSize().x;
RY=Win.getSize().y;
LargTxt=Title.getGlobalBounds().width;
AltTxt=Title.getGlobalBounds().height;

ScaleX=RX/ResX;
ScaleY=RY/ResY;

TextoY=300;

if ((CursorM.x > RX/2-LargTxt/2 && CursorM.x<RX/2+LargTxt/2)
    && (CursorM.y >= TextY*ScaleY && CursorM.y < TextY*ScaleY +AltTxt*0.8*ScaleY) ){
TextoY=300;
switch (OPC){
case 1:setStartYellow();
    break;
case 2:setSetupYellow();
    break;
case 3:setHowToPlayYellow();
    break;
case 4:setScoresYellow();
    break;
case 5:setQuitGameYellow();
    break;

}

if (C==0){PlaySelect();}
return true;
}
///REPRODUCIMOS UNA SOLA VEZ QUE ESTE EN EL AREA DE SELECCION

return false;
}

bool KeyEffect(int OPC ,RenderWindow &Win ,int C ){
TextoY=320;

switch (OPC){

case 1:
    case 2:
    setStartYellow();
    break;
case 3:
    case 4:
    setSetupYellow();
    break;
case 5:
    case 6:
    setHowToPlayYellow();
    break;
case 7:
    case 8:
    setScoresYellow();
    break;

case 9:
case 10:setQuitGameYellow();
    break;

}


if (C==0){PlaySelect(); }
return true;


}


void DrawAllTitles(RenderWindow& window){

    window.draw(Main);
    window.draw(ByCarpincho);
    window.draw(TituloDev);
    window.draw(Cr);
    window.draw(Start);
    window.draw(Setup);
    window.draw(HowToPlay);
    window.draw(Scores);
    window.draw(QuitGame);


}

void AlphaDownAll(int Alfa){

Main.setFillColor(Color(Alfa,Alfa,Alfa,Alfa));
ByCarpincho.setFillColor(Color(0,0,0,Alfa));

Start.setFillColor(Color(Alfa,Alfa,Alfa,Alfa));
Cr.setFillColor(Color(Alfa,Alfa,Alfa,Alfa));
TituloDev.setFillColor(Color(Alfa,Alfa,Alfa,Alfa));
Setup.setFillColor(Color(Alfa,Alfa,Alfa,Alfa));
HowToPlay.setFillColor(Color(Alfa,Alfa,Alfa,Alfa));
Scores.setFillColor(Color(Alfa,Alfa,Alfa,Alfa));
QuitGame.setFillColor(Color(Alfa,Alfa,Alfa,Alfa));

}


void AlphaDownWin(int Alfa ){
Wenner.setFillColor(Color(Alfa,Alfa,Alfa,Alfa));
Wenner2.setFillColor(Color(Alfa,Alfa,Alfa,Alfa));
Continue.setFillColor(Color(Alfa,Alfa,Alfa,Alfa));
}

///DESTRUCTOR
~Titulos(){}
};


class PlayList{
private:
    int NumeroTrack;
    string Tracks[5];
    bool Lectura;
public:

PlayList(){

    Tracks[0]=" Energy - by Young & Free ( From Hillsong) ";
    Tracks[1]=" Automatic Call - by NINA ";
    Tracks[2]=" Cafe Speed - by Jordaan ";
    Tracks[3]=" Back To Life - by Young & Free (From Hillsong) ";
    Tracks[4]=" San Francisco - by ADOY ";

}


/**
RETORNARA UN VALOR DEL 1 AL 5 QUE SE UTILIZARA
EN EL VECTOR DE RUTAS PARA QUE LA CANCION
SEA DIFERENTE CADA VEZ QUE SE HAYA JUGADO;
*/
int getLastTrack(){
FILE *Lt;
     fopen_s(&Lt, "resources/Archives/TrackPlay.dat", "rb");

    if(Lt==NULL){ cout<<"ERROR TO READ TRACKLIST";  }

    Lectura=fread(&NumeroTrack, sizeof(NumeroTrack),1,Lt);
    if(Lectura)return NumeroTrack;
       fclose(Lt);
    cout<<"TRACK NUMBER EXTRACTED"<<endl;
    return 0;
}


void saveLastTrack(){
    int Update=getLastTrack();
    Update++;
    if (Update==5){Update=0;}
FILE *Sav;
fopen_s(&Sav, "resources/Archives/TrackPlay.dat", "wb");
    if(Sav==NULL){ cout<<"ERROR TO SAVE TRACKLIST"; return; }
    fwrite(&Update, sizeof(Update),1,Sav);
    fclose(Sav);
cout<<"TRACK NUMBER SAVED"<<endl;
}

///DESTRUCTOR
~PlayList(){}
};


class ScoreGUI{
private:
    RectangleShape MainGui;
    Font Scores;
    Sprite Lives;
    Texture IconLives;
    Text TopScore;
    Text TopScoreDraw;
    Text YourScore;
    Text ScoreGameplay;
    Text RemainingLives;

//////////////////////////////////////
    /**EXPERIMENTAL**/
std::stringstream s,sd,Ld;
//////////////////////////////////////

    int HighScore;
    int PlayedPlace;
    bool Lectura;
    float ResX;
    float ResY;
    int LivesCount;
public:

ScoreGUI(const float X= 1280,const float Y=720){

AllFiles FileX;


ResX=X;
ResY=Y;
HighScore= FileX.getHighScore();
PlayedPlace=0;
LivesCount=3;
Scores.loadFromFile("resources/Text Style/Base 19.ttf");

///RECTANGLE
MainGui.setFillColor(Color(100,100,100,100));
MainGui.setSize(Vector2f(ResX,40));
MainGui.setOutlineThickness(5);
MainGui.setOutlineColor(Color::Magenta);


///TEXTS

YourScore.setString("YOUR SCORE:  ");
YourScore.setCharacterSize(40);
YourScore.setFont(Scores);
YourScore.setFillColor(Color::White);
YourScore.setOutlineThickness(5);
YourScore.setOutlineColor(Color::Black);
YourScore.setPosition(50,-10);

ScoreGameplay.setCharacterSize(40);
ScoreGameplay.setOutlineThickness(5);
ScoreGameplay.setOutlineColor(Color::Black);
ScoreGameplay.setFont(Scores);
ScoreGameplay.setFillColor(Color::White);
ScoreGameplay.setPosition(325,-10);

sd << PlayedPlace;
ScoreGameplay.setString(sd.str());

///TOP
TopScore.setString(" TOP SCORE - ");
TopScore.setCharacterSize(40);
TopScore.setOutlineThickness(3);
TopScore.setOutlineColor(Color::Red);
TopScore.setFont(Scores);
TopScore.setFillColor(Color::White);
TopScore.setPosition(600,-10);

///DRAW
TopScoreDraw.setCharacterSize(40);
TopScoreDraw.setOutlineThickness(3);
TopScoreDraw.setOutlineColor(Color::Red);
TopScoreDraw.setFont(Scores);
TopScoreDraw.setFillColor(Color::White);
TopScoreDraw.setPosition(850,-10);

s <<HighScore;
TopScoreDraw.setString(s.str());

///LIVES COUNT
IconLives.loadFromFile( "resources/Images/BlockSprites/PaddleIcon.png"  );
Lives.setTexture(IconLives);
Lives.setScale( 0.8,0.8);
Lives.setPosition( ResX*0.88,-2);

RemainingLives.setFont(Scores);
RemainingLives.setCharacterSize(40);
RemainingLives.setOutlineThickness(3);
RemainingLives.setOutlineColor(Color::Black);
RemainingLives.setFillColor(Color::White);
RemainingLives.setPosition(ResX*0.96,-10);

Ld <<LivesCount;
RemainingLives.setString(Ld.str());

    }


void setScore(){
PlayedPlace+=100;
std::stringstream s,NewTop;
s << PlayedPlace;
ScoreGameplay.setString(s.str() );

if(PlayedPlace>HighScore){
    NewTop<<PlayedPlace;
    TopScoreDraw.setString(NewTop.str());
}

}


void DownLiveGui(){
LivesCount--;
if (LivesCount<0)LivesCount=0;
std::stringstream Ld;
Ld <<LivesCount;
RemainingLives.setString(Ld.str());
}

///GETS
const RectangleShape getGUI(){return RectangleShape(MainGui); }
const Text getGameScore(){return Text(ScoreGameplay); }
const Text getYourScore(){return Text(YourScore); }
const int getPuntos(){return PlayedPlace;}
const Text getTop(){return Text(TopScore); }
const Text getDrawTop(){return Text(TopScoreDraw); }

void DrawAll(RenderWindow &window){
window.draw(MainGui);
window.draw(Lives);
window.draw(RemainingLives);
window.draw(TopScore);
window.draw(TopScoreDraw);
window.draw(YourScore);
window.draw(ScoreGameplay);
}

void saveScore()
{
    FILE *Save;
    fopen_s(&Save, "resources/Archives/HighScore.dat","wb");
    if(Save==NULL){ cout<<"ERROR TO SAVE SCORES"; return; }
    int MaxS=HighScore;
    if (PlayedPlace>HighScore) MaxS=PlayedPlace;
    fwrite(&MaxS, sizeof(MaxS),1,Save);
    fclose(Save);
    cout<<"HIGHSCORE HAS BEEN UPDATED"<<endl;
}

///DESTRUCTOR
~ScoreGUI(){}
};

class Settings{
private:
    Font MainFont;
    Text HowToPlay;
    string Prology;
    string Ctrls;
    Font MainOp;
    Text VolumeLVL;
    Text Volstring;
    Text SoundFxsLVL;
    Text FxString;
    Text Controls;
    Font Score;
    Text ScoreT,ScoreN,ScorePts;
    std::stringstream AuxT;
    float ResX;
    float ResY;
    float TextoY;
    float TextTam;
    float Tickness;
    float Aux;
    int Volumen;
    int Effectos;
    int Gx,Gy;
    int Points;
    std::stringstream Vol,Effx;

public:
Settings(){
    Gx=0,Gy=0;
Prology= "\t\t\t\t BIENVENIDO A OMEGA'S ARKANOID! By Carpincho - ADN :D \n"
" \n"
" \n"
"Un juego que recrea de forma basica al famoso juego de Arkanoid de 1976 \n"
"Disfruta la musica, los efectos y algo de humor en esta edicion creada por ADN. \n"
" \n"
" \n"
" COMO JUGAR: \n"
"Destruye los bloques con la esfera mientras mueves la paleta ARKANOID \n"
"Pero no dejes que la esfera caiga por debajo de la paleta que el señor Omega \n"
"Hara sonar su horrible musica!! :C \n"

" \n"
" CONTROLES: \n"
"Puedes Mover la paleta del jugador con las teclas DIRECCIONALES Derecha E Izquierda, \n"
"Asi tambien con las teclas A (para Izquierda) y D (para Derecha) , como a ti mas te agrade! \n"
"Para liberar la esfera al inicio del juego debes presionar la tecla ESPACIO \n"
" \n"
" \n"
"\t\t\t\t Diviertete! Pero Ten CUIDADO, la esfera es mas pequeña de lo que parece! \n"
" \n"
"\t\t\t\t Date Prisa que la Señora Arkanoid te espera para la cena!  :D \n"
" \n" ;
Ctrls=" Controls Default: \n"
" A or <-  = FOR LEFT DIRECCTION  \n"
" \n"
" D or ->  = FOR RIGHT DIRECCTION \n"
" \n"
" SPACE  = FOR THROW BALL \n";

ResX=1280;
ResY=720;
TextoY=300;
TextTam= 40;
Tickness=4;
Aux=10;

AllFiles FilesX;


    Volumen=FilesX.getVolumen();
    Effectos=FilesX.getEfectos();
    Points=FilesX.getHighScore();


MainFont.loadFromFile("resources/Text Style/Base 10.ttf");
HowToPlay.setFont(MainFont);
HowToPlay.setString(Prology);
HowToPlay.setFillColor(Color::White);
HowToPlay.setCharacterSize(25);
HowToPlay.setOutlineColor(Color::Black);
HowToPlay.setOutlineThickness(3);
HowToPlay.setPosition( 150,50);

MainOp.loadFromFile("resources/Text Style/Base 15.otf");
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
VolumeLVL.setFont(MainOp);
VolumeLVL.setString("VOLUME MUSIC : ");
VolumeLVL.setCharacterSize(TextTam);
VolumeLVL.setFillColor(Color::White);
VolumeLVL.setOutlineColor(Color::Black);
VolumeLVL.setOutlineThickness(Tickness);
VolumeLVL.setPosition(200, 100 );

Volstring.setFont(MainOp);
Volstring.setCharacterSize(TextTam);
Volstring.setFillColor(Color::White);
Volstring.setOutlineColor(Color::Black);
Volstring.setOutlineThickness(Tickness);
Volstring.setPosition(700, 100 );

Vol << Volumen;
Volstring.setString(Vol.str());


//////////////////////////////////////////////////////////////////////////////////////////////////////////////
SoundFxsLVL.setFont(MainOp);
SoundFxsLVL.setString("VOLUME EFFECTS : ");
SoundFxsLVL.setCharacterSize(TextTam);
SoundFxsLVL.setFillColor(Color::White);
SoundFxsLVL.setOutlineColor(Color::Black);
SoundFxsLVL.setOutlineThickness(Tickness);
SoundFxsLVL.setPosition(200, 200 );

FxString.setFont(MainOp);
FxString.setCharacterSize(TextTam);
FxString.setFillColor(Color::White);
FxString.setOutlineColor(Color::Black);
FxString.setOutlineThickness(Tickness);
FxString.setPosition(700, 200 );

Effx << Effectos;
FxString.setString(Effx.str());

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
Controls.setFont(MainFont );
Controls.setString(Ctrls);
Controls.setFillColor(Color::White);
Controls.setCharacterSize(40);
Controls.setOutlineColor(Color::Black);
Controls.setOutlineThickness(3);
Controls.setPosition( 300,350);


//////////////////////////////////////////////////////////////////////////////////////////////////////////////

Score.loadFromFile("resources/Text Style/Base 2.ttf"  );
ScoreT.setFont(Score);
ScoreT.setString("BEST SCORE  ");
ScoreT.setFillColor(Color::White);
ScoreT.setOutlineColor(Color::Magenta);
ScoreT.setOutlineThickness(3);
ScoreT.setCharacterSize(90);
ScoreT.setPosition( 200,150);

ScoreN.setFont(MainOp);
ScoreN.setFillColor(Color::White);
ScoreN.setOutlineColor(Color::Red);
ScoreN.setOutlineThickness(7);
ScoreN.setCharacterSize(180);
ScoreN.setPosition( 200,300);


AuxT << Points;

ScoreN.setString(AuxT.str());

ScorePts.setFont(MainOp);
ScorePts.setString("Pts! ");
ScorePts.setFillColor(Color::White);
ScorePts.setOutlineColor(Color::Red);
ScorePts.setOutlineThickness(5);
ScorePts.setCharacterSize(110);
ScorePts.setPosition( 900,300);


}


const Text getHowToPlay(){return Text(HowToPlay);}

int setSwitch (int GUI){
    if(GUI==3|| GUI==4) { return 2;}//SETUP
    if (GUI==5|| GUI==6) { return 3;}//PROLOGO
    if  (GUI==7|| GUI==8) { return 4;}//SCORES
}

void DrawSetUp(RenderWindow& window){

Gy+=ControlsOnSetUp();
if (Gy==4)Gy=0;

switch(Gy){

case 0:
   case 1:
      setYellowVol();
        if(Volumen>=10 ) if (controles()==A||controles()==Left )Volumen-=10;
        if (Volumen<=90  ) if (controles()==D||controles()==Right )Volumen+=10;
    break;

case 2:
case 3:
        setYellowEFFX();
        if(Effectos>=10 ) if (controles()==A||controles()==Left )Effectos-=10;
        if (Effectos<=90  ) if (controles()==D||controles()==Right )Effectos+=10;
    break;
}


std::stringstream Vol,Effx;
Vol << Volumen;
Volstring.setString(Vol.str());
Effx << Effectos;
FxString.setString(Effx.str());

    window.draw( VolumeLVL );
    window.draw( Volstring);
    window.draw( SoundFxsLVL );
    window.draw( FxString);
    window.draw( Controls );

}

void setYellowVol(){
VolumeLVL.setFillColor(Color::Yellow);
Volstring.setFillColor(Color::Yellow);

FxString.setFillColor(Color::White);
SoundFxsLVL.setFillColor(Color::White);


}

void setYellowEFFX(){

FxString.setFillColor(Color::Yellow);
SoundFxsLVL.setFillColor(Color::Yellow);


VolumeLVL.setFillColor(Color::White);
Volstring.setFillColor(Color::White);


}

int ControlsOnSetUp(){

if (controles()== W || controles()== S || controles()== Up  || controles()== Down  )return 1;

return 0;
}

void SaveSettings(){
          VaciarSettings();
            FILE *Save;
            fopen_s(&Save, "resources/Archives/Settings.dat","ab");
            if(Save==NULL){ cout<<"ERROR TO SAVE SETTINGS";  }
           fwrite(&Volumen, sizeof(Volumen),1,Save);
           fwrite(&Effectos, sizeof(Effectos),1,Save);
           fclose(Save);
        cout<<"SETTINGS HAS BEEN SAVED"<<endl;

}

void DrawBestScore(RenderWindow& window){

window.draw(ScorePts);
window.draw(ScoreN);
window.draw(ScoreT);

}


~Settings(){}
};


#endif // CLASSES_H_INCLUDED
