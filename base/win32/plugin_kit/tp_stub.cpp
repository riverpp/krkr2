/*

	TVP2 ( T Visual Presenter 2 )  A script authoring tool
	Copyright (C) 2000-2004  W.Dee <dee@kikyou.info>

	See details of license at "license.txt"
*/
/* This file is always generated by makestub.pl . */
/* Modification by hand will be lost. */

#include <windows.h>
#include "tp_stub.h"

#define TVP_IN_PLUGIN_STUB

tjs_int TVPPluginGlobalRefCount = 0;

//---------------------------------------------------------------------------
// stubs
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
// Stub library setup
//---------------------------------------------------------------------------

static iTVPFunctionExporter * TVPFunctionExporter = NULL;

void * TVPGetImportFuncPtr(const char *name)
{
	void *ptr;
	if(TVPFunctionExporter->QueryFunctionsByNarrowString(&name, &ptr, 1))
	{
		// succeeded
	}
	else
	{
		// failed
		static const char *funcname = "void ::TVPThrowPluginUnboundFunctionError(const char *)";
		if(!TVPFunctionExporter->QueryFunctionsByNarrowString(&funcname, &ptr, 1))
		{
			*(int*)0 = 0; // causes an error
		}
		typedef void (__stdcall * __functype)(const char *);
		((__functype)(ptr))(name);
	}
	return ptr;
}

/* TVPInitImportStub : stub initialization */
bool TVPInitImportStub(iTVPFunctionExporter * exporter)
{
	// set TVPFunctionExporter
	TVPFunctionExporter = exporter;
	return true;
}

/* TVPUninitImportStub : stub uninitialization */
void TVPUninitImportStub()
{
}



void * TVPImportFuncPtr0 = NULL;
void * TVPImportFuncPtr1 = NULL;
void * TVPImportFuncPtr2 = NULL;
void * TVPImportFuncPtr3 = NULL;
void * TVPImportFuncPtr4 = NULL;
void * TVPImportFuncPtr5 = NULL;
void * TVPImportFuncPtr6 = NULL;
void * TVPImportFuncPtr7 = NULL;
void * TVPImportFuncPtr8 = NULL;
void * TVPImportFuncPtr9 = NULL;
void * TVPImportFuncPtr10 = NULL;
void * TVPImportFuncPtr11 = NULL;
void * TVPImportFuncPtr12 = NULL;
void * TVPImportFuncPtr13 = NULL;
void * TVPImportFuncPtr14 = NULL;
void * TVPImportFuncPtr15 = NULL;
void * TVPImportFuncPtr16 = NULL;
void * TVPImportFuncPtr17 = NULL;
void * TVPImportFuncPtr18 = NULL;
void * TVPImportFuncPtr19 = NULL;
void * TVPImportFuncPtr20 = NULL;
void * TVPImportFuncPtr21 = NULL;
void * TVPImportFuncPtr22 = NULL;
void * TVPImportFuncPtr23 = NULL;
void * TVPImportFuncPtr24 = NULL;
void * TVPImportFuncPtr25 = NULL;
void * TVPImportFuncPtr26 = NULL;
void * TVPImportFuncPtr27 = NULL;
void * TVPImportFuncPtr28 = NULL;
void * TVPImportFuncPtr29 = NULL;
void * TVPImportFuncPtr30 = NULL;
void * TVPImportFuncPtr31 = NULL;
void * TVPImportFuncPtr32 = NULL;
void * TVPImportFuncPtr33 = NULL;
void * TVPImportFuncPtr34 = NULL;
void * TVPImportFuncPtr35 = NULL;
void * TVPImportFuncPtr36 = NULL;
void * TVPImportFuncPtr37 = NULL;
void * TVPImportFuncPtr38 = NULL;
void * TVPImportFuncPtr39 = NULL;
void * TVPImportFuncPtr40 = NULL;
void * TVPImportFuncPtr41 = NULL;
void * TVPImportFuncPtr42 = NULL;
void * TVPImportFuncPtr43 = NULL;
void * TVPImportFuncPtr44 = NULL;
void * TVPImportFuncPtr45 = NULL;
void * TVPImportFuncPtr46 = NULL;
void * TVPImportFuncPtr47 = NULL;
void * TVPImportFuncPtr48 = NULL;
void * TVPImportFuncPtr49 = NULL;
void * TVPImportFuncPtr50 = NULL;
void * TVPImportFuncPtr51 = NULL;
void * TVPImportFuncPtr52 = NULL;
void * TVPImportFuncPtr53 = NULL;
void * TVPImportFuncPtr54 = NULL;
void * TVPImportFuncPtr55 = NULL;
void * TVPImportFuncPtr56 = NULL;
void * TVPImportFuncPtr57 = NULL;
void * TVPImportFuncPtr58 = NULL;
void * TVPImportFuncPtr59 = NULL;
void * TVPImportFuncPtr60 = NULL;
void * TVPImportFuncPtr61 = NULL;
void * TVPImportFuncPtr62 = NULL;
void * TVPImportFuncPtr63 = NULL;
void * TVPImportFuncPtr64 = NULL;
void * TVPImportFuncPtr65 = NULL;
void * TVPImportFuncPtr66 = NULL;
void * TVPImportFuncPtr67 = NULL;
void * TVPImportFuncPtr68 = NULL;
void * TVPImportFuncPtr69 = NULL;
void * TVPImportFuncPtr70 = NULL;
void * TVPImportFuncPtr71 = NULL;
void * TVPImportFuncPtr72 = NULL;
void * TVPImportFuncPtr73 = NULL;
void * TVPImportFuncPtr74 = NULL;
void * TVPImportFuncPtr75 = NULL;
void * TVPImportFuncPtr76 = NULL;
void * TVPImportFuncPtr77 = NULL;
void * TVPImportFuncPtr78 = NULL;
void * TVPImportFuncPtr79 = NULL;
void * TVPImportFuncPtr80 = NULL;
void * TVPImportFuncPtr81 = NULL;
void * TVPImportFuncPtr82 = NULL;
void * TVPImportFuncPtr83 = NULL;
void * TVPImportFuncPtr84 = NULL;
void * TVPImportFuncPtr85 = NULL;
void * TVPImportFuncPtr86 = NULL;
void * TVPImportFuncPtr87 = NULL;
void * TVPImportFuncPtr88 = NULL;
void * TVPImportFuncPtr89 = NULL;
void * TVPImportFuncPtr90 = NULL;
void * TVPImportFuncPtr91 = NULL;
void * TVPImportFuncPtr92 = NULL;
void * TVPImportFuncPtr93 = NULL;
void * TVPImportFuncPtr94 = NULL;
void * TVPImportFuncPtr95 = NULL;
void * TVPImportFuncPtr96 = NULL;
void * TVPImportFuncPtr97 = NULL;
void * TVPImportFuncPtr98 = NULL;
void * TVPImportFuncPtr99 = NULL;
void * TVPImportFuncPtr100 = NULL;
void * TVPImportFuncPtr101 = NULL;
void * TVPImportFuncPtr102 = NULL;
void * TVPImportFuncPtr103 = NULL;
void * TVPImportFuncPtr104 = NULL;
void * TVPImportFuncPtr105 = NULL;
void * TVPImportFuncPtr106 = NULL;
void * TVPImportFuncPtr107 = NULL;
void * TVPImportFuncPtr108 = NULL;
void * TVPImportFuncPtr109 = NULL;
void * TVPImportFuncPtr110 = NULL;
void * TVPImportFuncPtr111 = NULL;
void * TVPImportFuncPtr112 = NULL;
void * TVPImportFuncPtr113 = NULL;
void * TVPImportFuncPtr114 = NULL;
void * TVPImportFuncPtr115 = NULL;
void * TVPImportFuncPtr116 = NULL;
void * TVPImportFuncPtr117 = NULL;
void * TVPImportFuncPtr118 = NULL;
void * TVPImportFuncPtr119 = NULL;
void * TVPImportFuncPtr120 = NULL;
void * TVPImportFuncPtr121 = NULL;
void * TVPImportFuncPtr122 = NULL;
void * TVPImportFuncPtr123 = NULL;
void * TVPImportFuncPtr124 = NULL;
void * TVPImportFuncPtr125 = NULL;
void * TVPImportFuncPtr126 = NULL;
void * TVPImportFuncPtr127 = NULL;
void * TVPImportFuncPtr128 = NULL;
void * TVPImportFuncPtr129 = NULL;
void * TVPImportFuncPtr130 = NULL;
void * TVPImportFuncPtr131 = NULL;
void * TVPImportFuncPtr132 = NULL;
void * TVPImportFuncPtr133 = NULL;
void * TVPImportFuncPtr134 = NULL;
void * TVPImportFuncPtr135 = NULL;
void * TVPImportFuncPtr136 = NULL;
void * TVPImportFuncPtr137 = NULL;
void * TVPImportFuncPtr138 = NULL;
void * TVPImportFuncPtr139 = NULL;
void * TVPImportFuncPtr140 = NULL;
void * TVPImportFuncPtr141 = NULL;
void * TVPImportFuncPtr142 = NULL;
void * TVPImportFuncPtr143 = NULL;
void * TVPImportFuncPtr144 = NULL;
void * TVPImportFuncPtr145 = NULL;
void * TVPImportFuncPtr146 = NULL;
void * TVPImportFuncPtr147 = NULL;
void * TVPImportFuncPtr148 = NULL;
void * TVPImportFuncPtr149 = NULL;
void * TVPImportFuncPtr150 = NULL;
void * TVPImportFuncPtr151 = NULL;
void * TVPImportFuncPtr152 = NULL;
void * TVPImportFuncPtr153 = NULL;
void * TVPImportFuncPtr154 = NULL;
void * TVPImportFuncPtr155 = NULL;
void * TVPImportFuncPtr156 = NULL;
void * TVPImportFuncPtr157 = NULL;
void * TVPImportFuncPtr158 = NULL;
void * TVPImportFuncPtr159 = NULL;
void * TVPImportFuncPtr160 = NULL;
void * TVPImportFuncPtr161 = NULL;
void * TVPImportFuncPtr162 = NULL;
void * TVPImportFuncPtr163 = NULL;
void * TVPImportFuncPtr164 = NULL;
void * TVPImportFuncPtr165 = NULL;
void * TVPImportFuncPtr166 = NULL;
void * TVPImportFuncPtr167 = NULL;
void * TVPImportFuncPtr168 = NULL;
void * TVPImportFuncPtr169 = NULL;
void * TVPImportFuncPtr170 = NULL;
void * TVPImportFuncPtr171 = NULL;
void * TVPImportFuncPtr172 = NULL;
void * TVPImportFuncPtr173 = NULL;
void * TVPImportFuncPtr174 = NULL;
void * TVPImportFuncPtr175 = NULL;
void * TVPImportFuncPtr176 = NULL;
void * TVPImportFuncPtr177 = NULL;
void * TVPImportFuncPtr178 = NULL;
void * TVPImportFuncPtr179 = NULL;
void * TVPImportFuncPtr180 = NULL;
void * TVPImportFuncPtr181 = NULL;
void * TVPImportFuncPtr182 = NULL;
void * TVPImportFuncPtr183 = NULL;
void * TVPImportFuncPtr184 = NULL;
void * TVPImportFuncPtr185 = NULL;
void * TVPImportFuncPtr186 = NULL;
void * TVPImportFuncPtr187 = NULL;
void * TVPImportFuncPtr188 = NULL;
void * TVPImportFuncPtr189 = NULL;
void * TVPImportFuncPtr190 = NULL;
void * TVPImportFuncPtr191 = NULL;
void * TVPImportFuncPtr192 = NULL;
void * TVPImportFuncPtr193 = NULL;
void * TVPImportFuncPtr194 = NULL;
void * TVPImportFuncPtr195 = NULL;
void * TVPImportFuncPtr196 = NULL;
void * TVPImportFuncPtr197 = NULL;
void * TVPImportFuncPtr198 = NULL;
void * TVPImportFuncPtr199 = NULL;
void * TVPImportFuncPtr200 = NULL;
void * TVPImportFuncPtr201 = NULL;
void * TVPImportFuncPtr202 = NULL;
void * TVPImportFuncPtr203 = NULL;
void * TVPImportFuncPtr204 = NULL;
void * TVPImportFuncPtr205 = NULL;
void * TVPImportFuncPtr206 = NULL;
void * TVPImportFuncPtr207 = NULL;
void * TVPImportFuncPtr208 = NULL;
void * TVPImportFuncPtr209 = NULL;
void * TVPImportFuncPtr210 = NULL;
void * TVPImportFuncPtr211 = NULL;
void * TVPImportFuncPtr212 = NULL;
void * TVPImportFuncPtr213 = NULL;
void * TVPImportFuncPtr214 = NULL;
void * TVPImportFuncPtr215 = NULL;
void * TVPImportFuncPtr216 = NULL;
void * TVPImportFuncPtr217 = NULL;
void * TVPImportFuncPtr218 = NULL;
void * TVPImportFuncPtr219 = NULL;
void * TVPImportFuncPtr220 = NULL;
void * TVPImportFuncPtr221 = NULL;
void * TVPImportFuncPtr222 = NULL;
void * TVPImportFuncPtr223 = NULL;
void * TVPImportFuncPtr224 = NULL;
void * TVPImportFuncPtr225 = NULL;
void * TVPImportFuncPtr226 = NULL;
void * TVPImportFuncPtr227 = NULL;
void * TVPImportFuncPtr228 = NULL;
void * TVPImportFuncPtr229 = NULL;
void * TVPImportFuncPtr230 = NULL;
void * TVPImportFuncPtr231 = NULL;
void * TVPImportFuncPtr232 = NULL;
void * TVPImportFuncPtr233 = NULL;
void * TVPImportFuncPtr234 = NULL;
void * TVPImportFuncPtr235 = NULL;
void * TVPImportFuncPtr236 = NULL;
void * TVPImportFuncPtr237 = NULL;
void * TVPImportFuncPtr238 = NULL;
void * TVPImportFuncPtr239 = NULL;
void * TVPImportFuncPtr240 = NULL;
void * TVPImportFuncPtr241 = NULL;
void * TVPImportFuncPtr242 = NULL;
void * TVPImportFuncPtr243 = NULL;
void * TVPImportFuncPtr244 = NULL;
void * TVPImportFuncPtr245 = NULL;
void * TVPImportFuncPtr246 = NULL;
void * TVPImportFuncPtr247 = NULL;
void * TVPImportFuncPtr248 = NULL;
void * TVPImportFuncPtr249 = NULL;
void * TVPImportFuncPtr250 = NULL;
void * TVPImportFuncPtr251 = NULL;
void * TVPImportFuncPtr252 = NULL;
void * TVPImportFuncPtr253 = NULL;
void * TVPImportFuncPtr254 = NULL;
void * TVPImportFuncPtr255 = NULL;
void * TVPImportFuncPtr256 = NULL;
void * TVPImportFuncPtr257 = NULL;
void * TVPImportFuncPtr258 = NULL;
void * TVPImportFuncPtr259 = NULL;
void * TVPImportFuncPtr260 = NULL;
void * TVPImportFuncPtr261 = NULL;
void * TVPImportFuncPtr262 = NULL;
void * TVPImportFuncPtr263 = NULL;
void * TVPImportFuncPtr264 = NULL;
void * TVPImportFuncPtr265 = NULL;
void * TVPImportFuncPtr266 = NULL;
void * TVPImportFuncPtr267 = NULL;
void * TVPImportFuncPtr268 = NULL;
void * TVPImportFuncPtr269 = NULL;
void * TVPImportFuncPtr270 = NULL;
void * TVPImportFuncPtr271 = NULL;
void * TVPImportFuncPtr272 = NULL;
void * TVPImportFuncPtr273 = NULL;
void * TVPImportFuncPtr274 = NULL;
void * TVPImportFuncPtr275 = NULL;
void * TVPImportFuncPtr276 = NULL;
void * TVPImportFuncPtr277 = NULL;
void * TVPImportFuncPtr278 = NULL;
void * TVPImportFuncPtr279 = NULL;
void * TVPImportFuncPtr280 = NULL;
void * TVPImportFuncPtr281 = NULL;
void * TVPImportFuncPtr282 = NULL;
void * TVPImportFuncPtr283 = NULL;
void * TVPImportFuncPtr284 = NULL;
void * TVPImportFuncPtr285 = NULL;
void * TVPImportFuncPtr286 = NULL;
void * TVPImportFuncPtr287 = NULL;
void * TVPImportFuncPtr288 = NULL;
void * TVPImportFuncPtr289 = NULL;
void * TVPImportFuncPtr290 = NULL;
void * TVPImportFuncPtr291 = NULL;
void * TVPImportFuncPtr292 = NULL;
void * TVPImportFuncPtr293 = NULL;
void * TVPImportFuncPtr294 = NULL;
void * TVPImportFuncPtr295 = NULL;
void * TVPImportFuncPtr296 = NULL;
void * TVPImportFuncPtr297 = NULL;
void * TVPImportFuncPtr298 = NULL;
void * TVPImportFuncPtr299 = NULL;
void * TVPImportFuncPtr300 = NULL;
void * TVPImportFuncPtr301 = NULL;
void * TVPImportFuncPtr302 = NULL;
void * TVPImportFuncPtr303 = NULL;
void * TVPImportFuncPtr304 = NULL;
void * TVPImportFuncPtr305 = NULL;
void * TVPImportFuncPtr306 = NULL;
void * TVPImportFuncPtr307 = NULL;
void * TVPImportFuncPtr308 = NULL;
void * TVPImportFuncPtr309 = NULL;
void * TVPImportFuncPtr310 = NULL;
void * TVPImportFuncPtr311 = NULL;
void * TVPImportFuncPtr312 = NULL;
void * TVPImportFuncPtr313 = NULL;
void * TVPImportFuncPtr314 = NULL;
void * TVPImportFuncPtr315 = NULL;
void * TVPImportFuncPtr316 = NULL;
void * TVPImportFuncPtr317 = NULL;
void * TVPImportFuncPtr318 = NULL;
void * TVPImportFuncPtr319 = NULL;
void * TVPImportFuncPtr320 = NULL;
void * TVPImportFuncPtr321 = NULL;
void * TVPImportFuncPtr322 = NULL;
void * TVPImportFuncPtr323 = NULL;
void * TVPImportFuncPtr324 = NULL;
void * TVPImportFuncPtr325 = NULL;
void * TVPImportFuncPtr326 = NULL;
void * TVPImportFuncPtr327 = NULL;
void * TVPImportFuncPtr328 = NULL;
void * TVPImportFuncPtr329 = NULL;
void * TVPImportFuncPtr330 = NULL;
void * TVPImportFuncPtr331 = NULL;
void * TVPImportFuncPtr332 = NULL;
void * TVPImportFuncPtr333 = NULL;
void * TVPImportFuncPtr334 = NULL;
void * TVPImportFuncPtr335 = NULL;
void * TVPImportFuncPtr336 = NULL;
void * TVPImportFuncPtr337 = NULL;
void * TVPImportFuncPtr338 = NULL;
void * TVPImportFuncPtr339 = NULL;
void * TVPImportFuncPtr340 = NULL;
void * TVPImportFuncPtr341 = NULL;
void * TVPImportFuncPtr342 = NULL;
void * TVPImportFuncPtr343 = NULL;
void * TVPImportFuncPtr344 = NULL;
void * TVPImportFuncPtr345 = NULL;
void * TVPImportFuncPtr346 = NULL;
void * TVPImportFuncPtr347 = NULL;
void * TVPImportFuncPtr348 = NULL;
void * TVPImportFuncPtr349 = NULL;
void * TVPImportFuncPtr350 = NULL;
void * TVPImportFuncPtr351 = NULL;
void * TVPImportFuncPtr352 = NULL;
void * TVPImportFuncPtr353 = NULL;
void * TVPImportFuncPtr354 = NULL;
void * TVPImportFuncPtr355 = NULL;
void * TVPImportFuncPtr356 = NULL;
void * TVPImportFuncPtr357 = NULL;
void * TVPImportFuncPtr358 = NULL;
void * TVPImportFuncPtr359 = NULL;
void * TVPImportFuncPtr360 = NULL;
void * TVPImportFuncPtr361 = NULL;
void * TVPImportFuncPtr362 = NULL;
void * TVPImportFuncPtr363 = NULL;
void * TVPImportFuncPtr364 = NULL;
void * TVPImportFuncPtr365 = NULL;
void * TVPImportFuncPtr366 = NULL;
void * TVPImportFuncPtr367 = NULL;
void * TVPImportFuncPtr368 = NULL;
void * TVPImportFuncPtr369 = NULL;
void * TVPImportFuncPtr370 = NULL;
void * TVPImportFuncPtr371 = NULL;
void * TVPImportFuncPtr372 = NULL;
void * TVPImportFuncPtr373 = NULL;
void * TVPImportFuncPtr374 = NULL;
void * TVPImportFuncPtr375 = NULL;
void * TVPImportFuncPtr376 = NULL;
void * TVPImportFuncPtr377 = NULL;
void * TVPImportFuncPtr378 = NULL;
void * TVPImportFuncPtr379 = NULL;
void * TVPImportFuncPtr380 = NULL;
void * TVPImportFuncPtr381 = NULL;
void * TVPImportFuncPtr382 = NULL;
void * TVPImportFuncPtr383 = NULL;
void * TVPImportFuncPtr384 = NULL;
void * TVPImportFuncPtr385 = NULL;
void * TVPImportFuncPtr386 = NULL;
void * TVPImportFuncPtr387 = NULL;
void * TVPImportFuncPtr388 = NULL;
void * TVPImportFuncPtr389 = NULL;
void * TVPImportFuncPtr390 = NULL;
void * TVPImportFuncPtr391 = NULL;
void * TVPImportFuncPtr392 = NULL;
void * TVPImportFuncPtr393 = NULL;
void * TVPImportFuncPtr394 = NULL;
void * TVPImportFuncPtr395 = NULL;
void * TVPImportFuncPtr396 = NULL;
void * TVPImportFuncPtr397 = NULL;
void * TVPImportFuncPtr398 = NULL;
void * TVPImportFuncPtr399 = NULL;
void * TVPImportFuncPtr400 = NULL;
void * TVPImportFuncPtr401 = NULL;
void * TVPImportFuncPtr402 = NULL;
void * TVPImportFuncPtr403 = NULL;
void * TVPImportFuncPtr404 = NULL;
void * TVPImportFuncPtr405 = NULL;
void * TVPImportFuncPtr406 = NULL;
void * TVPImportFuncPtr407 = NULL;
void * TVPImportFuncPtr408 = NULL;
void * TVPImportFuncPtr409 = NULL;
void * TVPImportFuncPtr410 = NULL;
void * TVPImportFuncPtr411 = NULL;
void * TVPImportFuncPtr412 = NULL;
void * TVPImportFuncPtr413 = NULL;
void * TVPImportFuncPtr414 = NULL;
void * TVPImportFuncPtr415 = NULL;
void * TVPImportFuncPtr416 = NULL;
void * TVPImportFuncPtr417 = NULL;
void * TVPImportFuncPtr418 = NULL;
void * TVPImportFuncPtr419 = NULL;
void * TVPImportFuncPtr420 = NULL;
void * TVPImportFuncPtr421 = NULL;
void * TVPImportFuncPtr422 = NULL;
void * TVPImportFuncPtr423 = NULL;
void * TVPImportFuncPtr424 = NULL;
void * TVPImportFuncPtr425 = NULL;
void * TVPImportFuncPtr426 = NULL;
void * TVPImportFuncPtr427 = NULL;
void * TVPImportFuncPtr428 = NULL;
void * TVPImportFuncPtr429 = NULL;
void * TVPImportFuncPtr430 = NULL;
void * TVPImportFuncPtr431 = NULL;
void * TVPImportFuncPtr432 = NULL;
void * TVPImportFuncPtr433 = NULL;
void * TVPImportFuncPtr434 = NULL;
void * TVPImportFuncPtr435 = NULL;
void * TVPImportFuncPtr436 = NULL;
void * TVPImportFuncPtr437 = NULL;
void * TVPImportFuncPtr438 = NULL;
void * TVPImportFuncPtr439 = NULL;
void * TVPImportFuncPtr440 = NULL;
void * TVPImportFuncPtr441 = NULL;
void * TVPImportFuncPtr442 = NULL;
void * TVPImportFuncPtr443 = NULL;
void * TVPImportFuncPtr444 = NULL;
void * TVPImportFuncPtr445 = NULL;
void * TVPImportFuncPtr446 = NULL;
void * TVPImportFuncPtr447 = NULL;
void * TVPImportFuncPtr448 = NULL;
void * TVPImportFuncPtr449 = NULL;
void * TVPImportFuncPtr450 = NULL;
void * TVPImportFuncPtr451 = NULL;
void * TVPImportFuncPtr452 = NULL;
void * TVPImportFuncPtr453 = NULL;
void * TVPImportFuncPtr454 = NULL;
void * TVPImportFuncPtr455 = NULL;
void * TVPImportFuncPtr456 = NULL;
void * TVPImportFuncPtr457 = NULL;
void * TVPImportFuncPtr458 = NULL;
void * TVPImportFuncPtr459 = NULL;
void * TVPImportFuncPtr460 = NULL;
void * TVPImportFuncPtr461 = NULL;
void * TVPImportFuncPtr462 = NULL;
void * TVPImportFuncPtr463 = NULL;
void * TVPImportFuncPtr464 = NULL;
void * TVPImportFuncPtr465 = NULL;
void * TVPImportFuncPtr466 = NULL;
void * TVPImportFuncPtr467 = NULL;
void * TVPImportFuncPtr468 = NULL;
void * TVPImportFuncPtr469 = NULL;
void * TVPImportFuncPtr470 = NULL;
void * TVPImportFuncPtr471 = NULL;
void * TVPImportFuncPtr472 = NULL;
void * TVPImportFuncPtr473 = NULL;
void * TVPImportFuncPtr474 = NULL;
void * TVPImportFuncPtr475 = NULL;
void * TVPImportFuncPtr476 = NULL;
void * TVPImportFuncPtr477 = NULL;
void * TVPImportFuncPtr478 = NULL;
void * TVPImportFuncPtr479 = NULL;
void * TVPImportFuncPtr480 = NULL;
void * TVPImportFuncPtr481 = NULL;
void * TVPImportFuncPtr482 = NULL;
void * TVPImportFuncPtr483 = NULL;
void * TVPImportFuncPtr484 = NULL;
void * TVPImportFuncPtr485 = NULL;
void * TVPImportFuncPtr486 = NULL;
void * TVPImportFuncPtr487 = NULL;
void * TVPImportFuncPtr488 = NULL;
void * TVPImportFuncPtr489 = NULL;
void * TVPImportFuncPtr490 = NULL;
void * TVPImportFuncPtr491 = NULL;
void * TVPImportFuncPtr492 = NULL;
void * TVPImportFuncPtr493 = NULL;
void * TVPImportFuncPtr494 = NULL;
void * TVPImportFuncPtr495 = NULL;
void * TVPImportFuncPtr496 = NULL;
void * TVPImportFuncPtr497 = NULL;
void * TVPImportFuncPtr498 = NULL;
void * TVPImportFuncPtr499 = NULL;
void * TVPImportFuncPtr500 = NULL;
void * TVPImportFuncPtr501 = NULL;
void * TVPImportFuncPtr502 = NULL;
void * TVPImportFuncPtr503 = NULL;
void * TVPImportFuncPtr504 = NULL;
void * TVPImportFuncPtr505 = NULL;
void * TVPImportFuncPtr506 = NULL;
void * TVPImportFuncPtr507 = NULL;

//---------------------------------------------------------------------------
// tTJSDispatch
//---------------------------------------------------------------------------
tTJSDispatch::tTJSDispatch()
{
	BeforeDestructionCalled = false;
	RefCount = 1;
#ifdef TVP_IN_PLUGIN_STUB // TVP plug-in support
	TVPPluginGlobalRefCount++;
#endif
}
//---------------------------------------------------------------------------
tTJSDispatch::~tTJSDispatch()
{
	if(!BeforeDestructionCalled)
	{
		BeforeDestructionCalled = true;
		BeforeDestruction();
	}
}
//---------------------------------------------------------------------------
tjs_uint TJS_INTF_METHOD  tTJSDispatch::AddRef(void)
{
#ifdef TVP_IN_PLUGIN_STUB // TVP plug-in support
	TVPPluginGlobalRefCount++;
#endif
	return ++RefCount;
}
//---------------------------------------------------------------------------
tjs_uint TJS_INTF_METHOD  tTJSDispatch::Release(void)
{
#ifdef TVP_IN_PLUGIN_STUB // TVP plug-in support
	TVPPluginGlobalRefCount--;
#endif
	if(RefCount == 1) // avoid to call "BeforeDestruction" with RefCount == 0
	{
		// object destruction
		if(!BeforeDestructionCalled)
		{
			BeforeDestructionCalled = true;
			BeforeDestruction();
		}

		if(RefCount == 1) // really ready to destruct ?
		{
			delete this;
			return 0;
		}
	}
	return --RefCount;
}
//---------------------------------------------------------------------------
tjs_error TJS_INTF_METHOD
	tTJSDispatch::FuncCallByNum(
		tjs_uint32 flag,
		tjs_int num,
		tTJSVariant *result,
		tjs_int numparams,
		tTJSVariant **param,
		iTJSDispatch2 *objthis
		)
{
	tjs_char buf[34];
	TJS_int_to_str(num, buf);
	return FuncCall(flag, buf, NULL, result, numparams, param, objthis);
}
//---------------------------------------------------------------------------
tjs_error TJS_INTF_METHOD
	tTJSDispatch::PropGetByNum(
		tjs_uint32 flag,
		tjs_int num,
		tTJSVariant *result,
		iTJSDispatch2 *objthis
		)
{
	tjs_char buf[34];
	TJS_int_to_str(num, buf);
	return PropGet(flag, buf, NULL, result, objthis);
}
//---------------------------------------------------------------------------
tjs_error TJS_INTF_METHOD
	tTJSDispatch::PropSetByNum(
		tjs_uint32 flag,
		tjs_int num,
		const tTJSVariant *param,
		iTJSDispatch2 *objthis
		)
{
	tjs_char buf[34];
	TJS_int_to_str(num, buf);
	return PropSet(flag, buf, NULL, param, objthis);
}
//---------------------------------------------------------------------------
tjs_error TJS_INTF_METHOD
	tTJSDispatch::GetCountByNum(
		tjs_int *result,
		tjs_int num,
		iTJSDispatch2 *objthis
		)
{
	tjs_char buf[34];
	TJS_int_to_str(num, buf);
	return GetCount(result, buf, NULL, objthis);
}
//---------------------------------------------------------------------------
tjs_error TJS_INTF_METHOD
	tTJSDispatch::DeleteMemberByNum(
		tjs_uint32 flag,
		tjs_int num,
		iTJSDispatch2 *objthis
		)
{
	tjs_char buf[34];
	TJS_int_to_str(num, buf);
	return DeleteMember(flag, buf, NULL, objthis);
}
//---------------------------------------------------------------------------
tjs_error TJS_INTF_METHOD
	tTJSDispatch::InvalidateByNum(
		tjs_uint32 flag,
		tjs_int num,
		iTJSDispatch2 *objthis
		)
{
	tjs_char buf[34];
	TJS_int_to_str(num, buf);
	return Invalidate(flag, buf, NULL, objthis);
}
//---------------------------------------------------------------------------
tjs_error TJS_INTF_METHOD
	tTJSDispatch::IsValidByNum(
		tjs_uint32 flag,
		tjs_int num,
		iTJSDispatch2 *objthis
		)
{
	tjs_char buf[34];
	TJS_int_to_str(num, buf);
	return IsValid(flag, buf, NULL, objthis);
}
//---------------------------------------------------------------------------
tjs_error TJS_INTF_METHOD
	tTJSDispatch::CreateNewByNum(
		tjs_uint32 flag,
		tjs_int num,
		iTJSDispatch2 **result,
		tjs_int numparams,
		tTJSVariant **param,
		iTJSDispatch2 *objthis
		)
{
	tjs_char buf[34];
	TJS_int_to_str(num, buf);
	return CreateNew(flag, buf, NULL, result, numparams, param, objthis);
}
//---------------------------------------------------------------------------
tjs_error TJS_INTF_METHOD
	tTJSDispatch::IsInstanceOfByNum(
		tjs_uint32 flag,
		tjs_int num,
		const tjs_char *classname,
		iTJSDispatch2 *objthis
		)
{
	tjs_char buf[34];
	TJS_int_to_str(num, buf);
	return IsInstanceOf(flag, buf, NULL, classname, objthis);
}
//---------------------------------------------------------------------------
tjs_error TJS_INTF_METHOD
	tTJSDispatch::OperationByNum(
		tjs_uint32 flag,
		tjs_int num,
		tTJSVariant *result,
		const tTJSVariant *param,
		iTJSDispatch2 *objthis
		)
{
	tjs_char buf[34];
	TJS_int_to_str(num, buf);
	return Operation(flag, buf, NULL, result, param, objthis);
}
//---------------------------------------------------------------------------
tjs_error TJS_INTF_METHOD
	tTJSDispatch::Operation(
		tjs_uint32 flag,
		const tjs_char *membername,
		tjs_uint32 *hint,
		tTJSVariant *result,
		const tTJSVariant *param,
		iTJSDispatch2 *objthis
	)
{
	tjs_uint32 op = flag & TJS_OP_MASK;

	if(op!=TJS_OP_INC && op!=TJS_OP_DEC && param == NULL)
		return TJS_E_INVALIDPARAM;

	if(op<TJS_OP_MIN || op>TJS_OP_MAX)
		return TJS_E_INVALIDPARAM;

	tTJSVariant tmp;
	tjs_error hr;
	hr = PropGet(0, membername, hint, &tmp, objthis);
	if(TJS_FAILED(hr)) return hr;

	TJSDoVariantOperation(op, tmp, param);

	hr = PropSet(0, membername, hint, &tmp, objthis);
	if(TJS_FAILED(hr)) return hr;

	if(result) result->CopyRef(tmp);

	return TJS_S_OK;
}
//---------------------------------------------------------------------------

