#include "StageContext.h"

void StageContext::Draw() const
{
	for (auto& StageObject : stage_objects)
	{
		StageObject->Draw();
	}
}