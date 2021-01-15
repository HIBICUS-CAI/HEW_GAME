#include "GameApp.h"

int main()
{
    if (Init())
    {
        RunGame();
    }

    TurnOff();

    return 0;
}
