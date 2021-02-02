#include "BuilderManager.h"
#include "AppDeclared.h"
#include "UIObject.h"

void InitBuildingManager()
{
	for (int i = 0; i < BUILDINGS_SIZE; i++)
	{
		GetEditBuildingsArray()[i].Status = BUILDING_STATUS::NOTHING;
		GetEditBuildingsArray()[i].Type = B_TYPE_NOTHING;
		GetEditBuildingsArray()[i].Event = B_EVNT_NOTHING;
	}
}

void UpdateBuildingManager()
{

}

void TurnOffBuildingManager()
{

}
