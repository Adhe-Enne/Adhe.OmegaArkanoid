#ifndef ARKANOIDMANAGER_H_INCLUDED
#define ARKANOIDMANAGER_H_INCLUDED



using namespace sf;
/**ADMINISTRADOR PRINCIPAL DE ARKANOID**/

class ArkanoidManager{
private:
RenderWindow ArkanoidWindow;
float ResX;
float ResY;
float MinResX;
float MinResY;
GAMETYPE ArkaType;
bool Game;

public:
   ArkanoidManager(const float A=1280,const float B= 720, const float  C=0,const float D=0){
    ResX=A ;
    ResY= B;
    MinResX= C;
    MinResY= D;
ArkaType=MENU;
 Game=true;
ArkanoidWindow.create(VideoMode(ResX, ResY),"Omega's ARKANOID - by Carpincho ®");
ArkanoidWindow.setVerticalSyncEnabled(true);

}

void PlayArkanoid();

GAMETYPE getType(int MODGAME   ){
                                                                                //TYPE
if (MODGAME==MENU) return MENU;                         //1
if (MODGAME==LOADING)return LOADING;            //2
if (MODGAME==PLAYGAME)return PLAYGAME;       //3
if (MODGAME==WIN)return WIN;                                //4
if (MODGAME==GAMEOVER)return GAMEOVER;     //5
if (MODGAME==EXIT)return EXIT;                                //6

     }

};


void ArkanoidManager::PlayArkanoid(){

Arkanoid MainArk;
int MODGAME;
cout<<endl;

while (Game){

cout<<"OPTION "<<ArkaType<<": "<<endl;


switch(ArkaType){
    case MENU:
        cout<<"MENU"<<endl;
      MODGAME=MainArk.MenuPrincipal(ArkanoidWindow, ResX, ResY);
    break;

    case LOADING:
        cout<<"LOADING GAME"<<endl;
        MODGAME=MainArk.LoadingGame(ResX, ResY,ArkanoidWindow ) ;
    break;

    case PLAYGAME:
    cout<<"START GAME"<<endl;
    MODGAME=MainArk.Iniciar(ArkanoidWindow,ResX, ResY ) ;

    break;

                case WIN:
                    cout<<"WINNER"<<endl;
                    MODGAME=MainArk.YouWin(ResX, ResY,ArkanoidWindow ) ;
                break;

                case GAMEOVER:
                    cout<<"GAMEOVER"<<endl;
                    MODGAME=MainArk.YouLose(ResX, ResY,ArkanoidWindow ) ;
                break;

    case EXIT:
        cout<<"EXIT GAME"<<endl;
        ArkanoidWindow.close();
        Game=false;
    break;

cout<<endl;
}

cout<<endl;
ArkaType=getType(MODGAME);

}

cout<<"ARKANOID WAS SUCESSFULLY RUN AND CLOSED "<<endl;
system("pause>null");
}






#endif // ARKANOIDMANAGER_H_INCLUDED
