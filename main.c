#include <stdio.h>
#include <stdlib.h>
#include"Modes/SinglePlayer/singleplayer.h"
#include"Modes/MultiPlayer/multiplayer.h"
#include"Logic/logic.h"
int main()
{
    short int Loc_nChoise=0;
    while(Loc_nChoise!=-1)
    {
        Loc_nChoise=LOGC_nMainList();
        switch(Loc_nChoise)
        {
            case 1:
                {
                    while(1)
                    {
                        MOMT_vMultiplayerMode();
                        if(!LOGC_nPlayAgain())
                        {
                            break;
                        }
                    }
                    break;
                }
            case 2:
                {
                    Loc_nChoise=LOGC_nSinglePlayerMode();
                    if(Loc_nChoise==1)
                    {
                        while(1)
                        {
                            MOSP_vHardMODE();
                            if(!LOGC_nPlayAgain())
                            {
                                break;
                            }
                        }
                    }
                    else if(Loc_nChoise==2)
                    {
                        while(1)
                        {
                            MOSP_vEasyMode();
                            if(!LOGC_nPlayAgain())
                            {
                                break;
                            }
                        }
                    }
                    break;
                }
            case 3:
                {
                    Loc_nChoise=-1;
                    break;
                }
        }
    }
}
