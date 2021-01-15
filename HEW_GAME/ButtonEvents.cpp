#include "ButtonEvents.h"
#include "UIObject.h"
#include "DeclaredValues.h"
#include "CustomizedApp.h"

void OpenUIObj(int id)
{
    GetUIObjByID(id)->TurnOn();
}

void CloseUIObj(int id)
{
    GetUIObjByID(id)->TurnOff();
}

void RunButtonEvent(int value)
{
    switch (value)
    {
    case TEST_OPENSUB:
        OpenUIObj(GetUIObjByName("child")->ID);
        SetSelectedBtn(GetUIObjByName("child")->Buttons);
        break;

    case TEST_CLOSETHIS:
        CloseUIObj(GetUIObjByName("child")->ID);
        SetSelectedBtn(GetUIObjByName("parent")->Buttons);
        break;

    default:
        break;
    }

    AppButtonEvent(value);
}
