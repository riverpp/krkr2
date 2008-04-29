//---------------------------------------------------------------------------
/*
	TVP2 ( T Visual Presenter 2 )  A script authoring tool
	Copyright (C) 2000-2004  W.Dee <dee@kikyou.info>

	See details of license at "license.txt"
*/
//---------------------------------------------------------------------------
// System Initialization and Uninitialization
//---------------------------------------------------------------------------
#include "tjsCommHead.h"
#pragma hdrstop

#include <vector>
#include "tjsUtils.h"
#include "SysInitIntf.h"
#include "ScriptMgnIntf.h"
#include "tvpgl.h"


//---------------------------------------------------------------------------
// global data
//---------------------------------------------------------------------------
ttstr TVPProjectDir; // project directory
//---------------------------------------------------------------------------




//---------------------------------------------------------------------------
// TVPSystemInit : Entire System Initialization
//---------------------------------------------------------------------------
void TVPSystemInit(void)
{
	TVPBeforeSystemInit();

	TVPInitScriptEngine();

	TVPInitTVPGL();

	TVPAfterSystemInit();
}
//---------------------------------------------------------------------------





//---------------------------------------------------------------------------
// TVPSystemUninit : System shutdown, cleanup, etc...
//---------------------------------------------------------------------------
static void TVPCauseAtExit();
bool TVPSystemUninitCalled = false;
void TVPSystemUninit(void)
{
	if(TVPSystemUninitCalled) return;
	TVPSystemUninitCalled = true;

	TVPBeforeSystemUninit();

	TVPUninitTVPGL();

	TVPUninitScriptEngine();

	TVPAfterSystemUninit();

	TVPCauseAtExit();
}
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------
// TVPAddAtExitHandler related
//---------------------------------------------------------------------------
struct tTVPAtExitInfo
{
	tTVPAtExitInfo(tjs_int pri, void(*handler)())
	{
		Priority = pri, Handler = handler;
	}

	tjs_int Priority;
	void (*Handler)();

	bool operator <(const tTVPAtExitInfo & r) const
		{ return this->Priority < r.Priority; }
	bool operator >(const tTVPAtExitInfo & r) const
		{ return this->Priority > r.Priority; }
	bool operator ==(const tTVPAtExitInfo & r) const
		{ return this->Priority == r.Priority; }

};
static std::vector<tTVPAtExitInfo> *TVPAtExitInfos = NULL;
static bool TVPAtExitShutdown = false;
//---------------------------------------------------------------------------
void TVPAddAtExitHandler(tjs_int pri, void (*handler)())
{
	if(TVPAtExitShutdown) return;

	if(!TVPAtExitInfos) TVPAtExitInfos = new std::vector<tTVPAtExitInfo>();
	TVPAtExitInfos->push_back(tTVPAtExitInfo(pri, handler));
}
//---------------------------------------------------------------------------
static void TVPCauseAtExit()
{
	if(TVPAtExitShutdown) return;
	TVPAtExitShutdown = true;

	std::sort(TVPAtExitInfos->begin(), TVPAtExitInfos->end()); // descending sort

	std::vector<tTVPAtExitInfo>::iterator i;
	for(i = TVPAtExitInfos->begin(); i!=TVPAtExitInfos->end(); i++)
	{
		i->Handler();
	}

	delete TVPAtExitInfos;
}
//---------------------------------------------------------------------------





