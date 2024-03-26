#ifndef PATHRESOURCES_H_INCLUDED
#define PATHRESOURCES_H_INCLUDED

class PathArchivos{
private:

 public:
     ///Block sprites path
         string BlockMetal[4];
         string BlockBlue[4];
         string BlockGreen[4];
         string BlockYellow[4];
         string BlockRed[4];
    ///Bloq Collision on Player
        string Sounds[8];
    ///Sounds[0] = Sonido de paleta al recibir impacto de esfera
        string Gif [45];
        string Stage[42];
        string GameOver [45];
        string Load[23];
        string Win[22];
        ///MUSICA DE JUEGO
       string MusicStages[8];
        string MusicTest;
        string LoadCover[30];

PathArchivos(  ){ ///PATH DE ARCHIVOS USADOS  BlueBlocks/
       ///BLOCKS SPRITES
        BlockBlue[0]="resources/Images/BlockSprites/BlueBlocks/BlueBlock.jpg";
        BlockBlue[1]="resources/Images/BlockSprites/BlueBlocks/BlueBlock2.jpg";
        BlockBlue[2]="resources/Images/BlockSprites/BlueBlocks/BlueBlock3.jpg";
        BlockBlue[3]="resources/Images/BlockSprites/BlueBlocks/BlueBlock4.jpg";

        BlockGreen[0]="resources/Images/BlockSprites/GreenBlocks/GreenBlock.jpg";
        BlockGreen[1]="resources/Images/BlockSprites/GreenBlocks/GreenBlock2.jpg";
        BlockGreen[2]="resources/Images/BlockSprites/GreenBlocks/GreenBlock3.jpg";
        BlockGreen[3]="resources/Images/BlockSprites/GreenBlocks/GreenBlock4.jpg";

        BlockYellow[0]="resources/Images/BlockSprites/YellowBlocks/YellowBlock.jpg";
        BlockYellow[1]="resources/Images/BlockSprites/YellowBlocks/YellowBlock2.jpg";
        BlockYellow[2]="resources/Images/BlockSprites/YellowBlocks/YellowBlock3.jpg";
        BlockYellow[3]="resources/Images/BlockSprites/YellowBlocks/YellowBlock4.jpg";

        BlockRed[0]="resources/Images/BlockSprites/RedBlocks/RedBlock.jpg";
        BlockRed[1]="resources/Images/BlockSprites/RedBlocks/RedBlock2.jpg";
        BlockRed[2]="resources/Images/BlockSprites/RedBlocks/RedBlock3.jpg";
        BlockRed[3]="resources/Images/BlockSprites/RedBlocks/RedBlock4.jpg";

        BlockMetal[0]= "resources/Images/BlockSprites/MetalBlocks/MetalBlock.jpg";
        BlockMetal[1]= "resources/Images/BlockSprites/MetalBlocks/MetalBlock2.jpg";
        BlockMetal[2]= "resources/Images/BlockSprites/MetalBlocks/MetalBlock3.jpg";
        BlockMetal[3]= "resources/Images/BlockSprites/MetalBlocks/MetalBlock4.jpg";

///GIF ANIMATION MENU
Gif[0]="resources/Images/Gif FPS 1/LEDS_frame_0001.png";
Gif[1]="resources/Images/Gif FPS 1/LEDS_frame_0002.png";
Gif[2]="resources/Images/Gif FPS 1/LEDS_frame_0003.png";
Gif[3]="resources/Images/Gif FPS 1/LEDS_frame_0004.png";
Gif[4]="resources/Images/Gif FPS 1/LEDS_frame_0005.png";
Gif[5]="resources/Images/Gif FPS 1/LEDS_frame_0006.png";
Gif[6]="resources/Images/Gif FPS 1/LEDS_frame_0007.png";
Gif[7]="resources/Images/Gif FPS 1/LEDS_frame_0008.png";
Gif[8]="resources/Images/Gif FPS 1/LEDS_frame_0009.png";
Gif[9]="resources/Images/Gif FPS 1/LEDS_frame_0010.png";
Gif[10]="resources/Images/Gif FPS 1/LEDS_frame_0011.png";
Gif[11]="resources/Images/Gif FPS 1/LEDS_frame_0012.png";
Gif[12]="resources/Images/Gif FPS 1/LEDS_frame_0013.png";
Gif[13]="resources/Images/Gif FPS 1/LEDS_frame_0014.png";
Gif[14]="resources/Images/Gif FPS 1/LEDS_frame_0015.png";
Gif[15]="resources/Images/Gif FPS 1/LEDS_frame_0016.png";
Gif[16]="resources/Images/Gif FPS 1/LEDS_frame_0017.png";
Gif[17]="resources/Images/Gif FPS 1/LEDS_frame_0018.png";
Gif[18]="resources/Images/Gif FPS 1/LEDS_frame_0019.png";
Gif[19]="resources/Images/Gif FPS 1/LEDS_frame_0020.png";
Gif[20]="resources/Images/Gif FPS 1/LEDS_frame_0021.png";
Gif[21]="resources/Images/Gif FPS 1/LEDS_frame_0022.png";
Gif[22]="resources/Images/Gif FPS 1/LEDS_frame_0023.png";
Gif[23]="resources/Images/Gif FPS 1/LEDS_frame_0024.png";
Gif[24]="resources/Images/Gif FPS 1/LEDS_frame_0025.png";
Gif[25]="resources/Images/Gif FPS 1/LEDS_frame_0026.png";
Gif[26]="resources/Images/Gif FPS 1/LEDS_frame_0027.png";
Gif[27]="resources/Images/Gif FPS 1/LEDS_frame_0028.png";
Gif[28]="resources/Images/Gif FPS 1/LEDS_frame_0029.png";
Gif[29]="resources/Images/Gif FPS 1/LEDS_frame_0030.png";
Gif[30]="resources/Images/Gif FPS 1/LEDS_frame_0031.png";
Gif[31]="resources/Images/Gif FPS 1/LEDS_frame_0032.png";
Gif[32]="resources/Images/Gif FPS 1/LEDS_frame_0033.png";
Gif[33]="resources/Images/Gif FPS 1/LEDS_frame_0034.png";
Gif[34]="resources/Images/Gif FPS 1/LEDS_frame_0035.png";
Gif[35]="resources/Images/Gif FPS 1/LEDS_frame_0036.png";
Gif[36]="resources/Images/Gif FPS 1/LEDS_frame_0037.png";
Gif[37]="resources/Images/Gif FPS 1/LEDS_frame_0038.png";
Gif[38]="resources/Images/Gif FPS 1/LEDS_frame_0039.png";
Gif[39]="resources/Images/Gif FPS 1/LEDS_frame_0040.png";
Gif[40]="resources/Images/Gif FPS 1/LEDS_frame_0041.png";
Gif[41]="resources/Images/Gif FPS 1/LEDS_frame_0042.png";
Gif[42]="resources/Images/Gif FPS 1/LEDS_frame_0043.png";
Gif[43]="resources/Images/Gif FPS 1/LEDS_frame_0044.png";
Gif[44]="resources/Images/Gif FPS 1/LEDS_frame_0045.png";


///GIF ANIMATION STAGE

Stage[0]= "resources/Images/Stage3/1.jpg";
Stage[1]="resources/Images/Stage3/2.jpg";
Stage[2]="resources/Images/Stage3/3.jpg";
Stage[3]="resources/Images/Stage3/4.jpg";
Stage[4]="resources/Images/Stage3/5.jpg";
Stage[5]="resources/Images/Stage3/6.jpg";
Stage[6]="resources/Images/Stage3/7.jpg";
Stage[7]="resources/Images/Stage3/8.jpg";
Stage[8]="resources/Images/Stage3/9.jpg";
Stage[9]="resources/Images/Stage3/10.jpg";
Stage[10]="resources/Images/Stage3/11.jpg";
Stage[11]="resources/Images/Stage3/12.jpg";
Stage[12]="resources/Images/Stage3/13.jpg";
Stage[13]="resources/Images/Stage3/14.jpg";
Stage[14]="resources/Images/Stage3/15.jpg";
Stage[15]="resources/Images/Stage3/16.jpg";
Stage[16]="resources/Images/Stage3/17.jpg";
Stage[17]="resources/Images/Stage3/18.jpg";
Stage[18]="resources/Images/Stage3/19.jpg";
Stage[19]="resources/Images/Stage3/20.jpg";
Stage[20]="resources/Images/Stage3/21.jpg";
Stage[21]="resources/Images/Stage3/22.jpg";
Stage[22]="resources/Images/Stage3/23.jpg";
Stage[23]="resources/Images/Stage3/24.jpg";
Stage[24]="resources/Images/Stage3/25.jpg";
Stage[25]="resources/Images/Stage3/26.jpg";
Stage[26]="resources/Images/Stage3/27.jpg";
Stage[27]="resources/Images/Stage3/28.jpg";
Stage[28]="resources/Images/Stage3/29.jpg";
Stage[29]="resources/Images/Stage3/30.jpg";
Stage[30]="resources/Images/Stage3/31.jpg";
Stage[31]="resources/Images/Stage3/32.jpg";
Stage[32]="resources/Images/Stage3/33.jpg";
Stage[33]="resources/Images/Stage3/34.jpg";
Stage[34]="resources/Images/Stage3/35.jpg";
Stage[35]="resources/Images/Stage3/36.jpg";
Stage[36]="resources/Images/Stage3/37.jpg";
Stage[37]="resources/Images/Stage3/38.jpg";
Stage[38]="resources/Images/Stage3/39.jpg";
Stage[39]="resources/Images/Stage3/40.jpg";
Stage[40]="resources/Images/Stage3/41.jpg";
Stage[41]="resources/Images/Stage3/42.jpg";


///LOADING FONT

Load[0]="resources/Images/Loading/1.jpg";
Load[1]="resources/Images/Loading/2.jpg";
Load[2]="resources/Images/Loading/3.jpg";
Load[3]="resources/Images/Loading/4.jpg";
Load[4]="resources/Images/Loading/5.jpg";
Load[5]="resources/Images/Loading/6.jpg";
Load[6]="resources/Images/Loading/7.jpg";
Load[7]="resources/Images/Loading/8.jpg";
Load[8]="resources/Images/Loading/9.jpg";
Load[9]="resources/Images/Loading/10.jpg";
Load[10]="resources/Images/Loading/11.jpg";
Load[11]="resources/Images/Loading/12.jpg";
Load[12]="resources/Images/Loading/13.jpg";
Load[13]="resources/Images/Loading/14.jpg";
Load[14]="resources/Images/Loading/15.jpg";
Load[15]="resources/Images/Loading/16.jpg";
Load[16]="resources/Images/Loading/17.jpg";
Load[17]="resources/Images/Loading/18.jpg";
Load[18]="resources/Images/Loading/19.jpg";
Load[19]="resources/Images/Loading/20.jpg";
Load[20]="resources/Images/Loading/21.jpg";
Load[21]="resources/Images/Loading/22.jpg";
Load[22]="resources/Images/Loading/23.jpg";

///LOADING COVER
LoadCover[0]="resources/Images/LoadingGif/1.png";
LoadCover[1]="resources/Images/LoadingGif/2.png";
LoadCover[2]="resources/Images/LoadingGif/3.png";
LoadCover[3]="resources/Images/LoadingGif/4.png";
LoadCover[4]="resources/Images/LoadingGif/5.png";
LoadCover[5]="resources/Images/LoadingGif/6.png";
LoadCover[6]="resources/Images/LoadingGif/7.png";
LoadCover[7]="resources/Images/LoadingGif/8.png";
LoadCover[8]="resources/Images/LoadingGif/9.png";
LoadCover[9]="resources/Images/LoadingGif/10.png";
LoadCover[10]="resources/Images/LoadingGif/11.png";
LoadCover[11]="resources/Images/LoadingGif/12.png";
LoadCover[12]="resources/Images/LoadingGif/13.png";
LoadCover[13]="resources/Images/LoadingGif/14.png";
LoadCover[14]="resources/Images/LoadingGif/15.png";
LoadCover[15]="resources/Images/LoadingGif/16.png";
LoadCover[16]="resources/Images/LoadingGif/17.png";
LoadCover[17]="resources/Images/LoadingGif/18.png";
LoadCover[18]="resources/Images/LoadingGif/19.png";
LoadCover[19]="resources/Images/LoadingGif/20.png";
LoadCover[20]="resources/Images/LoadingGif/21.png";
LoadCover[21]="resources/Images/LoadingGif/22.png";
LoadCover[22]="resources/Images/LoadingGif/23.png";
LoadCover[23]="resources/Images/LoadingGif/24.png";
LoadCover[24]="resources/Images/LoadingGif/25.png";
LoadCover[25]="resources/Images/LoadingGif/26.png";
LoadCover[26]="resources/Images/LoadingGif/27.png";
LoadCover[27]="resources/Images/LoadingGif/28.png";
LoadCover[28]="resources/Images/LoadingGif/29.png";
LoadCover[29]="resources/Images/LoadingGif/30.png";



 ///GAMEOVER ANIMATION
GameOver[0]="resources/Images/GameOver/1.jpg";
GameOver[1]="resources/Images/GameOver/2.jpg";
GameOver[2]="resources/Images/GameOver/3.jpg";
GameOver[3]="resources/Images/GameOver/4.jpg";
GameOver[4]="resources/Images/GameOver/5.jpg";
GameOver[5]="resources/Images/GameOver/6.jpg";
GameOver[6]="resources/Images/GameOver/7.jpg";
GameOver[7]="resources/Images/GameOver/8.jpg";
GameOver[8]="resources/Images/GameOver/9.jpg";
GameOver[9]="resources/Images/GameOver/10.jpg";
GameOver[10]="resources/Images/GameOver/11.jpg";
GameOver[11]= "resources/Images/GameOver/12.jpg";
GameOver[12]="resources/Images/GameOver/13.jpg";
GameOver[13]="resources/Images/GameOver/14.jpg";
GameOver[14]="resources/Images/GameOver/15.jpg";
GameOver[15]="resources/Images/GameOver/16.jpg";
GameOver[16]="resources/Images/GameOver/17.jpg";
GameOver[17]="resources/Images/GameOver/18.jpg";
GameOver[18]="resources/Images/GameOver/19.jpg";
GameOver[19]="resources/Images/GameOver/20.jpg";
GameOver[20]="resources/Images/GameOver/21.jpg";
GameOver[21]="resources/Images/GameOver/22.jpg";
GameOver[22]="resources/Images/GameOver/23.jpg";
GameOver[23]="resources/Images/GameOver/24.jpg";
GameOver[24]="resources/Images/GameOver/25.jpg";
GameOver[25]="resources/Images/GameOver/26.jpg";
GameOver[26]="resources/Images/GameOver/27.jpg";
GameOver[27]="resources/Images/GameOver/28.jpg";
GameOver[28]="resources/Images/GameOver/29.jpg";
GameOver[29]="resources/Images/GameOver/30.jpg";
GameOver[30]="resources/Images/GameOver/31.jpg";
GameOver[31]="resources/Images/GameOver/32.jpg";
GameOver[32]="resources/Images/GameOver/33.jpg";
GameOver[33]="resources/Images/GameOver/34.jpg";
GameOver[34]="resources/Images/GameOver/35.jpg";
GameOver[35]="resources/Images/GameOver/36.jpg";
GameOver[36]="resources/Images/GameOver/37.jpg";
GameOver[37]="resources/Images/GameOver/38.jpg";
GameOver[38]="resources/Images/GameOver/39.jpg";
GameOver[39]="resources/Images/GameOver/40.jpg";
GameOver[40]="resources/Images/GameOver/41.jpg";
GameOver[41]="resources/Images/GameOver/42.jpg";
GameOver[42]="resources/Images/GameOver/43.jpg";
GameOver[43]="resources/Images/GameOver/44.jpg";
GameOver[44]="resources/Images/GameOver/45.jpg";
GameOver[45]="resources/Images/GameOver/46.jpg";



///WENNER

Win[0]= "resources/Images/YouWin2/1.jpg";
Win[1]="resources/Images/YouWin2/2.jpg";
Win[2]="resources/Images/YouWin2/3.jpg";
Win[3]="resources/Images/YouWin2/4.jpg";
Win[4]="resources/Images/YouWin2/5.jpg";
Win[5]="resources/Images/YouWin2/6.jpg";
Win[6]="resources/Images/YouWin2/7.jpg";
Win[7]="resources/Images/YouWin2/8.jpg";
Win[8]="resources/Images/YouWin2/9.jpg";
Win[9]="resources/Images/YouWin2/10.jpg";
Win[10]="resources/Images/YouWin2/11.jpg";
Win[11]="resources/Images/YouWin2/12.jpg";
Win[12]="resources/Images/YouWin2/13.jpg";
Win[13]="resources/Images/YouWin2/14.jpg";
Win[14]="resources/Images/YouWin2/15.jpg";
Win[15]="resources/Images/YouWin2/16.jpg";
Win[16]="resources/Images/YouWin2/17.jpg";
Win[17]="resources/Images/YouWin2/18.jpg";
Win[18]="resources/Images/YouWin2/19.jpg";
Win[19]="resources/Images/YouWin2/20.jpg";
Win[20]="resources/Images/YouWin2/21.jpg";
Win[21]="resources/Images/YouWin2/22.jpg";



///SOUNDS PLAYER
Sounds[0]="resources/Sounds/Paleta1.wav";


MusicTest="resources/Sounds/SunGlasses.wav";

///MUSIC GAME PLAYER
MusicStages[0]="resources/Sounds/ENERGY.wav";
MusicStages[1]="resources/Sounds/Automatic.wav";
MusicStages[2]="resources/Sounds/Jordaan.wav";
MusicStages[3]="resources/Sounds/Back To Life.wav";
MusicStages[4]="resources/Sounds/SunGlasses.wav";

MusicStages[5]="resources/Sounds/WIN.wav";///WIN MUSIC
MusicStages[6]="resources/Sounds/Game Over2.wav";///LOSE MUSIC
MusicStages[7]="resources/Sounds/ADOY1.wav";///MENU MUSIC


}

///DESTRUCTOR
~PathArchivos(){}

};

#endif // PATHRESOURCES_H_INCLUDED
