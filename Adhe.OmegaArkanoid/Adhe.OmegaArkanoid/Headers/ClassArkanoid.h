#ifndef CLASSARKANOID_H_INCLUDED
#define CLASSARKANOID_H_INCLUDED

enum GAMETYPE
{
    MENU=1,
    LOADING,
    PLAYGAME,
    WIN,
    GAMEOVER,
    EXIT
};



using namespace sf;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**PROTOTIPOS NECESARIOS*/
void CentrarSprite( Sprite& Rectangulo,float ResX,float PosY);
void AllCollisiones(Blockes &Enemigos,   Esfera & BOLA1);
bool Colission( RectangleShape Bloque,CircleShape Ball   )  ;
void DOENEMIES( Blockes *Enemigos, int Cant, float ResX,float ResY);
void AnglePolarity(Platform &Player,Esfera &Ball);
bool Collisions(Blockes &Enemigos,Esfera &Ball);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Arkanoid
{

private:
    float ResX;
    float ResY;
    float MinResX;
    float MinResY;
public:

///EL JUEGO SE EJECUTARA EN 1280x720 POR DEFECTO
    Arkanoid(const float A=1280,const float B= 720, const float  C=0,const float D=0)
    {
        ResX=A ;
        ResY= B;
        MinResX= C;
        MinResY= D;

    }
    /**PROXIMAMENTE**/
    /**VOID PLAYARKANOID();**/
    int MenuPrincipal(RenderWindow& window,float ResX,float ResY); ///FUNCION PRINCIPAL QUE UTILIZARA A LAS DEMAS
    /**
    EASY - 2 FILAS DE BLOQUES - VELOCIDAD BAJA DE ESFERA
    MEDIUM - 4 FILAS DE BLOQUES - VELOCIDA MEDIA
    HARD - 7 FILAS DE BLOQUES - VELOCIDAD MAXIMA DE ESFERA


    SURVIVAL - 8 FILAS - MAXIMA VELOCIDAD DE ESFERA Y JUGADOR
    */

    int LoadingGame( float ResX, float ResY, RenderWindow& window);
    int Iniciar(RenderWindow& window,float ResX,float ResY);
    int YouLose( float ResX, float ResY, RenderWindow& window);
    int YouWin( float ResX, float ResY, RenderWindow& window );
    ///VUELVE AL MENU
    int ComoJugar();
    ///EXPLIQUEMOS COMO JUGAR
    int Puntuaciones();

    int Configuracion();

    /**VOLUMEN EFECTS
        MUSIC VOLUME

                CONTROLS:
                CONTROL LEFT
                CONTROL RIGHT
                LAUNCH CONTROL
    */


    ///AUXILIARESBETA : NO NECESARIOS AL FINALIZAR
    int Salir();
    const float getResX()
    {
        return ResX;
    }
    const float getResY()
    {
        return ResY;
    }

    ///FUNCION SOLO DE PRUEBAS
    int MenuPrincipal2(RenderWindow& window,float ResX,float ResY);

///DESTRUCTOR
    ~Arkanoid() {}
};

int Arkanoid::MenuPrincipal(  RenderWindow& window,float ResX,float ResY    )
{
    window.setFramerateLimit(30);
/////////////////////////////////////////////////////////////////////////////////////
//MUSICA
    PathArchivos PA;

    AllFiles FileX;
    int Volume=FileX.getVolumen();

    Music Menu;
    Menu.openFromFile(PA.MusicStages[7]);
    Menu.setVolume(Volume);
    Menu.play();


    /**DESCARTADO**/
//MENU MOUSE PROPERTIES
//int C,St,H,Sc,Qg,Teclas;
//C=St=H=Sc=Qg=Teclas=0;
//MENU PRINCIPAL PROPIEDADES

    int GUI=-1,Ctrl=-1,Alfa=0,i=0,AuxGUI;
    int Track=7;
    Titulos Titulo;
    Vector2i CursorM;
    FloatRect MouseM;
    bool Game=true,Out=false;
    Clock MenuT;


//AUXILIAR IMPORTANTE
    Settings Main;


//CONTROL DE DIBUJADO
    int SwitchDraw=0; //POR DEFECTO

    Event event;
//////////////////////POR DEFECTO////////////////////////////////////////////////////////////////////////

    while (Game)
    {

        while ( window.pollEvent(event))
        {
            if (event.type == Event::Closed)   window.close();
        }
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

        if(MenuT.getElapsedTime().asSeconds()>4.5)
        {
            if (controles()>0)
            {
                if (GUI==-1 )
                {
                    GUI=1 ;
                    Ctrl=0;
                }
            }
            Ctrl++;
            if (controles()==W|| controles()==Up    )
            {
                GUI--;
                Ctrl=0;
            }
            if (controles()==S ||  controles()==Down  )
            {
                GUI++;
                Ctrl=0;
            }
            if (GUI==11 )
            {
                GUI =1;
            }
            if(GUI== 0 )
            {
                GUI =10;
            }

        }

//////EFECTO DE MENU SELECTOR
        if(MenuT.getElapsedTime().asSeconds()>4.5)
        {

            CursorM=Mouse::getPosition(window);
            Titulo.KeyEffect(GUI,window, Ctrl );
            /**DESCARTADO POR FALTA DE TIEMPO**/
            //MENU SELECTOR IGUAL QUE CON LAS TECLAS SOLO QUE CON EL MOUSE
            //NO SE AVANZO EN EL POR FALTA DE TIEMPO Y POR NO SER ALTAMENTE NECESARIO

            /**EFECTO DE MOUSE SOBRE  LAS OPCIONES**/
            // if(Titulo.MouseEffect(CursorM, Titulo.getStart() ,1,window,St))  {St++;} else{St=0;}
            // if(Titulo.MouseEffect(CursorM, Titulo.getSetup() ,2,window,C))    {C++;}else{C=0;}
            //if(Titulo.MouseEffect(CursorM, Titulo.getHTP() ,3,window,H))      {H++;}else{H=0;}
            //if(Titulo.MouseEffect(CursorM, Titulo.getScores() ,4,window,Sc))   {Sc++;}else{Sc=0;}
            // if(Titulo.MouseEffect(CursorM, Titulo.getQuit() ,5,window,Qg)) {Qg++;}else{Qg=0;}
        }
////////////////////FONDO ANIMADO////////////////////
        Texture GIF;
        GIF.loadFromFile(PA.Gif[i]);
        GIF.setSmooth(true);
        Sprite GIFPS;
        GIFPS.setTexture(GIF);
        GIFPS.setScale(2.56,1.44);
        i++;
        if (i==44)i=0;
        /**EFECTO TRANSISION EXPERIMENTAL*/
///INICIO

        if (!Out)
        {

            if (Alfa<255)
            {
                GIFPS.setColor(Color(Alfa,Alfa, Alfa, Alfa));
                Alfa+=5;
            }
        }

///SELECIONAR OPCION
//FIJO
        if (controles() ==Enter && (GUI>=9|| GUI<=2) )
        {
            Titulo.PlaySelected();    //INICIAR Y/O SALIR
            Out=true;
        }
        if (controles() ==Enter)
        {
            Titulo.PlaySelected();
            SwitchDraw=Main.setSwitch(GUI);
            AuxGUI=GUI;
        }
        if (controles() ==Esc )
        {
            Titulo.PlaySelected();
            SwitchDraw=0;
            GUI=AuxGUI;
        }

///PARA SALIR Y/O INICAR JUEGO
        if (Out)
        {
            SwitchDraw=0;
            Titulo.AlphaDownAll(Alfa);
            GIFPS.setColor(Color(Alfa,Alfa, Alfa, Alfa));
            Alfa-=3;
            /**DESVANECIMIENTO DE MUSICA EXPERIMENTAL*/
            if(Volume>0) Menu.setVolume(Volume--);
            if (Alfa==0)
            {
                Game=false;
                Main.SaveSettings();
                if (GUI>=9)return EXIT;
                if (GUI<=2)return LOADING;

            }
        }



//////////////ACTUALIZAR PANTALLA//////////////////
        window.clear();
        window.draw(GIFPS);

        /**TEMPORIZAR LA MUESTRA DE MENU*/

        if (SwitchDraw==0)if(MenuT.getElapsedTime().asSeconds()>4.5)
            {
                Titulo.DrawAllTitles(window);
            }


        if (SwitchDraw!=0)
        {

            switch (SwitchDraw)
            {
            case 2:
                Main.DrawSetUp( window);
                break;
            case 3:
                window.draw (Main.getHowToPlay() );
                break;
            case 4:
                Main.DrawBestScore(window);
                break;

            }


        }


        window.display();
/////////////////////////////////////////////////////////
//RESETAMOS LOS COLORES

        if (!Out)Titulo.ResetColorAll();

    }

}

int Arkanoid::LoadingGame (float ResX, float ResY,RenderWindow& window)
{

    window.setFramerateLimit(20);


    int Alfa=255;
    int Loaded=0;
    PathArchivos X;
    int j=0,k=0;
    bool Game=true,Continue=false;
    Clock LoadT;

    Event event;
    while (Game)
    {
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)  window.close();
        }

        /**LOAD BANNER*/
        Vector2u LoadV;
        Texture LoadCover;
        LoadCover.loadFromFile(X.LoadCover[k]);
        LoadCover.setSmooth(true);
        Sprite LoadGraph(LoadCover);
        LoadGraph.setPosition(50,500);

        if (Loaded==4)
        {
            Loaded=0;
            k++ ;
        }
        else
        {
            Loaded++;
        }

        if(k==29 )
        {
            k=20;
            Continue=true;
        }

        /**LOAD WINDOW*/
        Vector2u LoadPos;
        Texture LoadGif;
        LoadGif.loadFromFile(X.Load[j]);
        LoadGif.setSmooth(true);
        Sprite Loading(LoadGif);
        LoadPos= LoadGif.getSize();
        Loading.setScale(ResX/LoadPos.x,ResY/LoadPos.y);

        if (j==22)j=0;
        j++ ;


        if (Continue)
        {
            if (Alfa>0)
            {
                Loading.setColor(Color(Alfa,Alfa, Alfa, Alfa));
                LoadGraph.setColor(Color(Alfa,Alfa, Alfa, Alfa));
                Alfa-=3;
            }
        }

        if (Alfa==0)
        {
            Game=false;
            return PLAYGAME;
        }

        window.clear();
        window.draw(Loading);
        window.draw(LoadGraph);
        window.display();

    }

}

int Arkanoid::Iniciar(RenderWindow& window,float ResX,float ResY)
{
    /**PROPIEDADES DE PANTALLA*/
    const float  MinResX = 0, MinResY = 0;
    window.setFramerateLimit(66);

    Platform P1; //JUGADOR
    Esfera BOLA1; //ESFERA

    AllFiles FileX;

    int Efectos=FileX.getEfectos();
    BOLA1.setVolumeEffects(Efectos);

    int Volume=FileX.getVolumen();
///VARIABLES AUXILIARES
    int i;
    int Alfa=0,Intersects=0;
    int j=0;
    bool Cont = true,MoveBall=false;
    /**CREAMOS ENEMIGOS*/
    int EnemiesAlive=0;
    Blockes Enemigos[104];
    DOENEMIES(Enemigos,104,ResX,ResY);
    bool Game=true,ISGAMEWIN;
////////////////////////////////////////////////////////////////////////////////////
    ScoreGUI GUI; //PUNTAJES
///Musica
    PathArchivos X;
    PlayList List;
    int Track=List.getLastTrack();
    List.saveLastTrack(); ///ACTUALIZAR TRACK
    Music GameP;
    GameP.openFromFile(X.MusicStages[Track]);



    GameP.setVolume(Volume);
    GameP.play();

    Vector2f PosicionEsfera,PosicionPlayer,PosicionBlock;//AUXILIARES PARA EL JUGADOR/ESFERA/BLOQUE

/////////////////A PARTIR DE ESTE PUNTO SE EJECUTAN LOS PARAMETROS EN LA VENTANA/////////////////////
    Event event;
//while ( window.isOpen()){ // NO NECESARIO
    while (Game)
    {
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)  window.close();
        }

////ACCIONES DE LA ESFERA////////////////////////////////////////////////////////////
        /**  IMPORTANTE ESTO CAMBIA LA POLARIDAD PARA DETECTAR LA COLICION DE LAS PAREDES*/

// SI COLISIONA CON MUROS LATERALES
        PosicionEsfera =BOLA1.getBallPosition();//posicion actual  de la esfera
        if (PosicionEsfera.x <= 0 || PosicionEsfera.x >= ResX - BOLA1.getBallDiameter()   )
        {
            BOLA1.setPolarityX( -1);
            BOLA1.PlayCollisionWall();
        }
// SI COLISIONA CON MURO SUPERIOR
        if (PosicionEsfera.y <= 40 )
        {
            BOLA1.PlayCollisionWall();
            BOLA1.setPolarityY( -1);
        }

////////////////////////////////////////////////////////////////////////////////////////////
//ACCIONES DEL JUGADOR
        if (controles() ==A||controles() ==Left )
        {
            P1.setPolarityX(-12);   //DIRECCIONES DE JUGADOR
        }
        if (controles() ==D||controles() ==Right )
        {
            P1.setPolarityX(12);    //DIRECCIONES DE JUGADOR
        }
        PosicionPlayer= P1.getPlayerPosition();
        if(PosicionPlayer.x < 0.f)
        {
            P1.LimitPositionX(MinResX+1,PosicionPlayer.y);
        }
        if(PosicionPlayer.x > (ResX-P1.getPlayerTamX() ) )
        {
            P1.LimitPositionX(ResX-P1.getPlayerTamX(),PosicionPlayer.y);
        }

        /**  IMPORTANTE ESTO CAMBIA LA POLARIDAD PARA DETECTAR LA COLICION DE LA ESFERA CONTRA EL JUGADOR*/
        //ERROR DE LA ESFERA DENTRO DEL AREA DEL JUGADOR FUE RESUELTO
        if (Colission(P1.getPlayer(),BOLA1.getBall() ) )
        {
            Intersects++;
        }
        else
        {
            Intersects=0;
        }
        if(Intersects==1)
        {
            AnglePolarity( P1,BOLA1) ;
            BOLA1.PlayCollisionPlayer();
        }

////////////////////////////////////////////////////////////////////////////////////////////
        /**EXPERIMENTAL MEJORADO: NUEVO METODO DE COLISION PERFECTA**/
        for (i=0; i<104; i++)
        {
            if (Enemigos[i].getVida()>0)
            {
                if (Colission(Enemigos[i].GetBloque(),BOLA1.getBall() ) )
                {
                    GUI.setScore();
                    AllCollisiones(Enemigos[i], BOLA1);
                    break;
                }
            }
        }


        /**  IMPORTANTE  ESTO MANTIENE EL CONTINUO MOVIMIENTO DE LA ESFERA Y EL JUGADOR */
        P1.MovePlayer();
        P1.ResetSpeed();
        //ACTIVAR MOVIMIENTO DE ESFERA
        if (PosicionEsfera.y  > ResY-20 )
        {
            GUI.DownLiveGui();
            P1.DownLive();
            P1.PlayDead();
            MoveBall=false;
        }
        if (controles()==Space)MoveBall=true;
        if (MoveBall)
        {
            BOLA1.MoveBall();
        }
        else
        {
            BOLA1.SetBallPos(PosicionPlayer.x + P1.getPlayerTamX()/2,PosicionPlayer.y -BOLA1.getBallDiameter()-15 );
            BOLA1.ResetSpeed();
        }

////////////////////////////////////////////////////////////////////////////////////////////
        /**EXPERIMENTAL FONDO ANIMADO*/
        if (Cont)
        {
            Cont=false;
            j++ ;
        }
        else
        {
            Cont=true;
        }
        Vector2u Msprite;
        Texture GameGif;
        GameGif.loadFromFile(X.Stage[j]);
        Sprite GameAnim;
        GameAnim.setTexture(GameGif);
        Msprite= GameGif.getSize();
        GameAnim.setScale(ResX/Msprite.x,ResY/Msprite.y);
        if (j==41)j=0;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Dibujamos elementos en pantalla
        window.clear();


        if (Alfa<255)   //EFECTO DE TRANSICION
        {
            GameAnim.setColor(Color(Alfa,Alfa, Alfa, Alfa));
            for (i=0; i<104; i++)
            {
                Enemigos[i].DownAlfa(Alfa);
            }
            Alfa+=3;
        }

        window.draw(GameAnim);

        for (i=0; i<104; i++) // DIBUJAR ENEMIGOS CON VIDA
        {
            if (Enemigos[i].getVida()>0)
            {
                window.draw(Enemigos[i].GetBloque());
                EnemiesAlive++;
            }
        }

        GUI.DrawAll(window);
        window.draw(P1.getPlayer());
        window.draw(BOLA1.getBall());

        window.display();

        if (P1.getLives()<0)
        {
            Game=false;
            GameP.stop();
            ISGAMEWIN=false;
        }
        if (EnemiesAlive==0)
        {
            Game=false;
            GameP.stop();
            ISGAMEWIN=true;
        }
        EnemiesAlive=0;
////////////////////////////////////////////FIN RENDER EN VENTANA//////////////////////////////////////////////////
    }
    GUI.saveScore();

    cout<< "TERMINO PLAYER GAME"<<endl;
    if (ISGAMEWIN)
    {
        return WIN;
    }
    else
    {
        return GAMEOVER;
    }
}

int Arkanoid::YouLose(float ResX, float ResY, RenderWindow& window)
{

    window.setFramerateLimit(45);
///Game Over Cover
    Texture Looser;
    Looser.loadFromFile("resources/Images/GameOver Covers/YouLose.png");
    Sprite GameOver;
    GameOver.setTexture(Looser);
    CentrarSprite(GameOver,ResX,30);

    Texture Looser2;
    Looser2.loadFromFile("resources/Images/GameOver Covers/YouLose3.png");
    Sprite GameOver2;
    GameOver2.setTexture(Looser2);
    GameOver2.setScale(0.7,0.7  );
    CentrarSprite(GameOver2,ResX,100);


///You Win Music
    AllFiles FileX;
    int Volume=FileX.getVolumen();
    PathArchivos X;
    int Track=6,Vol=80; ///GAME OVER TRACK
    Music Loser;
    Loser.openFromFile(X.MusicStages[Track]);
    Loser.setVolume(Volume);
    Loser.play();

    bool Continue=false,Game=true;
    int Alfa=255,i=0,FPS=0;
    Titulos Win;


    Event event;
    while (Game)
    {

        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)  window.close();
        }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /**EXPERIMENTAL FONDO ANIMADO*/
        Vector2u LosePos;
        Texture LoseGif;
        LoseGif.loadFromFile(X.GameOver[i]);
        LosePos= LoseGif.getSize();
        Sprite LoseSprite(LoseGif);
        LoseSprite.setScale(ResX/LosePos.x,ResY/LosePos.y);

        if (FPS==2)
        {
            i++;
            FPS=0;
        }
        else
        {
            FPS++;
        }
        if (i==45)i=0;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        if (controles()>=0)Continue=true;

        if (Continue)
        {
            if (Alfa>0)
            {
                LoseSprite.setColor(Color(Alfa,Alfa, Alfa, Alfa));
                GameOver2.setColor(Color(Alfa,Alfa, Alfa, Alfa));
                GameOver.setColor(Color(Alfa,Alfa, Alfa, Alfa));
                Win.AlphaDownWin(Alfa);
                if (Vol>0)Loser.setVolume(Vol--);
                Alfa-=3;
            }
        }

        if (Alfa==0)
        {
            Loser.stop();

            Game=false;
            return MENU;

        }

        window.clear();
        window.draw(LoseSprite);
        window.draw(GameOver2);
        window.draw(GameOver);
        window.draw(Win.getContinue());
        window.display();

    }

}

////////////////RECIBE UNA VENTANA YA ABIERTA PARA INTERACTUAR EN ELLA.
int Arkanoid::YouWin( float ResX, float ResY, RenderWindow& window   )
{

    window.setFramerateLimit(20);
    bool WinCover=false,Continue=false,Game=true;
    PathArchivos X;
    int j=0;
    AllFiles FileX;
    int Volume=FileX.getVolumen();
    int Alfa=255,Vol=Volume;

    Titulos Win;
    Music WinMusic;
    WinMusic.openFromFile(X.MusicStages[5]);
    WinMusic.setVolume(Vol);
    WinMusic.play();

    Event event;
    while (Game)
    {
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)  window.close();
        }

        if (WinCover)
        {
            WinCover=false;
            j++ ;
        }
        else
        {
            WinCover=true;
        }

        Vector2u Wpos;
        Texture WinGif;
        WinGif.loadFromFile(X.Win[j]);
        Sprite WinFont(WinGif);
        Wpos= WinGif.getSize();
        WinFont.setScale(ResX/Wpos.x,ResY/Wpos.y);

        if (j==21)j=0;

        if (controles()==Esc)Continue=true;

        if (Continue)
        {
            if (Alfa>0)
            {

                WinFont.setColor(Color(Alfa,Alfa, Alfa, Alfa));
                Win.AlphaDownWin(Alfa);
                if (Vol>0)  WinMusic.setVolume(Vol--);
                Alfa-=3;
            }
        }

        if (Alfa==0)
        {
            WinMusic.stop();
            Game=false;
            return MENU;
        }

        window.clear();
        window.draw(WinFont);
        window.draw(Win.getWenner());
        window.draw(Win.getVenner());
        window.draw(Win.getContinue());
        window.display();

    }

}

void AbrirVentana1(int X,int Y, RenderWindow &window)
{

    Texture Image1;
    Image1.loadFromFile("resources/Images/menu2.jpg");
    Sprite Screen1;
    Screen1.setTexture(Image1);

    window.draw(Screen1);

}
#endif // CLASSARKANOID_H_INCLUDED
