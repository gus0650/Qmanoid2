// http://www.kaiiv.de/retrocoding/1/

#include <stdio.h>
#include <stdlib.h>

#include <exec/exec.h>

#include <dos/dos.h>

#include <graphics/gfxbase.h>
#include <graphics/gfxmacros.h>
#include <graphics/gels.h>

#include <intuition/intuition.h>
#include <intuition/screens.h>
#include <clib/exec_protos.h>
#include <clib/dos_protos.h>
#include <clib/graphics_protos.h>
#include <clib/intuition_protos.h>
//#include <clib/alib_protos.h>

#include <devices/timer.h>


struct GfxBase* GfxBase = 0;
struct IntuitionBase* IntuitionBase = 0;

 float f = 14.5f;


struct NewScreen Screen1 = {
    0,0,
    640,480,
    5,
    DETAILPEN, BLOCKPEN,
    HIRES,
    PUBLICSCREEN,              
    NULL,       
    "Qmanoid", 
    NULL,
    NULL
};

WORD __chip sprite_data1[] = { 
    0x7ffe, 0x80ff,
    0x7c3e, 0x803f,
    0x7c3e, 0x803f,
    0x7ffe, 0x80ff,
    0, 0 
};

struct SimpleSprite sprite1 = { 
      sprite_data1, 
      16,
      160, 100,
      2
}; 



int main(int argc, char **argv)
{

//f++;
//    printf("Hello %f", f);


    GfxBase = (struct GfxBase *) OpenLibrary("graphics.library", 0);
    IntuitionBase = (struct IntuitionBase*) OpenLibrary("intuition.library", 0);

    if (GfxBase == NULL) 
    { 
        printf("Öffnen des graphics.library nicht möglich !\n"); 
        exit(FALSE); 
    } 


     struct Screen *myScreen;
     myScreen = OpenScreen(&Screen1); 


    int s = GetSprite(&sprite1,sprite1.num);
    printf("%d", s); 

//    ChangeSprite(NULL, &sprite1, (APTR)sprite_data);
    for (int i = 0; i < 200; i++) {
        MoveSprite(NULL, &sprite1, i, 100);



//if (CheckSignal(SIGBREAKF_CTRL_C)) exit(0);


//ScrollVPort();

 WaitTOF();

     Delay(5);
    }     
     if (myScreen) CloseScreen(myScreen); 
      

    //cleanup

    FreeSprite(0);

    CloseLibrary((struct Library*)IntuitionBase);
    CloseLibrary((struct Library*)GfxBase);

    exit(TRUE);
}
