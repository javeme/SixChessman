// GoAbleChesman.h: interface for the GoAbleChesman class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GOABLECHESMAN_H__9B8D1BE3_2EC0_4984_A253_09A3C8CAFC39__INCLUDED_)
#define AFX_GOABLECHESMAN_H__9B8D1BE3_2EC0_4984_A253_09A3C8CAFC39__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Coordinate.h"

class GoAbleChesman  
{
public:
	GoAbleChesman();
	virtual ~GoAbleChesman();
public:
	Coordinate position;
	Coordinate direction;
	bool willBeenEat;
	int eatAbleCount;

};

#endif // !defined(AFX_GOABLECHESMAN_H__9B8D1BE3_2EC0_4984_A253_09A3C8CAFC39__INCLUDED_)
