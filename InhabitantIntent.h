#pragma once
#include "settings.h"

class InhabitantIntent
{
public:
	const InhabitantAction action;
	const Position where;

	InhabitantIntent(InhabitantAction _action = NONE,
		Position _where = NOWHERE)
		:action(_action), where(_where) {}
};

