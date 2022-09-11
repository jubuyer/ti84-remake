#include <nds.h>
#include <gl2d.h>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <maxmod9.h>

inline void clrscr() { iprintf("\e[1;1H\e[2J"); }

// sounds
// #include "soundbank.h"
// #include "soundbank_bin.h"


// clrscr function taken from libnds practical wiki https://github.com/NotImplementedLife/libnds-practical-wiki
// no longer used
// inline void clrscr() { iprintf("\e[1;1H\e[2J"); }

int main()
{
    consoleDemoInit();
    touchPosition touch;

    // video and vram setup
    // videoSetMode(MODE_5_3D);
    // videoSetModeSub(MODE_5_2D);
    // vramSetBankA(VRAM_A_TEXTURE);
    // vramSetBankB(VRAM_B_TEXTURE);
    // vramSetBankC(VRAM_C_TEXTURE);
    // vramSetBankD(VRAM_D_SUB_SPRITE);
    // vramSetBankI(VRAM_I_LCD);
    // vramSetBankI(VRAM_I_SUB_SPRITE_EXT_PALETTE);
    // vramSetBankE(VRAM_E_TEX_PALETTE);

    // main loop
    while (1)
    {
        clrscr();
        iprintf("TI-84");
        
        scanKeys();
        if(KEY_TOUCH & keysDown()) {
            touchRead(&touch);
        }

        // DS Resolution is 256 (x) by 192 (y)
        iprintf("\ntouchposition x = %d",(touch.px));
        iprintf("\ntouchposition y = %d",(touch.py));

        swiWaitForVBlank();

        // DC_FlushAll();
        oamUpdate(&oamMain);
        oamUpdate(&oamSub);
    }
    return 0;
}