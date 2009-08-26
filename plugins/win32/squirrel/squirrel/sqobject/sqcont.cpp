#include "sqcont.h"
#include "sqthread.h"

namespace sqobject {

ObjectInfo beforeContinuousList;
ObjectInfo afterContinuousList;

// ���X�g�ɒǉ�(���ɓo�^����Ă�ꍇ�͖���)
static void add(ObjectInfo &list, ObjectInfo &info)
{
	SQInteger max = list.len();
	for (SQInteger i=0;i<max;i++) {
		ObjectInfo f = list.get(i);
		if (f == info) {
			return;
		}
	}
	list.append(info);
}

// ���X�g����폜(�S���폜)
static void remove(ObjectInfo &list, ObjectInfo &info)
{
	SQInteger max = list.len();
	SQInteger i=0;
	while (i<max) {
		if (list.get(i) == info) {
			list.remove(i);
			max--;
		} else {
			i++;
		}
	}
}

static void call(ObjectInfo &list, int tick, int diff)
{
	SQInteger max = list.len();
	SQInteger i=0;
	for (SQInteger i=0;i<max;i++) {
		if (SQ_FAILED(list.get(i).call(tick, diff))) {
			list.remove(i);
			max--;
		}
	}
}

/// �n���h���o�^
static SQRESULT addContinuousHandler(HSQUIRRELVM v)
{
	ObjectInfo info(v,2);
	SQInteger type;
	if (sq_gettop(v) >= 3) {
		sq_getinteger(v, 3, &type);
	} else {
		type=1;
	}
	if (type == 0) {
		add(beforeContinuousList, info);
	} else if (type == 1) {
		add(afterContinuousList, info);
	}
	return SQ_OK;
}

/// �n���h���폜
static SQRESULT removeContinuousHandler(HSQUIRRELVM v)
{
	ObjectInfo info(v,2);
	SQInteger type;
	if (sq_gettop(v) >= 3) {
		sq_getinteger(v, 3, &type);
	} else {
		type=1;
	}
	if (type == 0) {
		remove(beforeContinuousList, info);
	} else if (type == 1) {
		remove(afterContinuousList, info);
	}
	return SQ_OK;
}

static SQRESULT clearContinuousHandler(HSQUIRRELVM v)
{
	beforeContinuousList.clearData();
	afterContinuousList.clearData();
	return SQ_OK;
}


/// �@�\�o�^
void registerContinuous()
{
#define REGISTERMETHOD(name, n, type) \
	sq_pushstring(v, _SC(#name), -1);\
	sq_newclosure(v, name, 0);\
	sq_setparamscheck(v, n, type);\
	sq_createslot(v, -3);

	HSQUIRRELVM v = getGlobalVM();
	sq_pushroottable(v); // root
	REGISTERMETHOD(addContinuousHandler, -2, _SC(".cn"));
	REGISTERMETHOD(removeContinuousHandler, -2, _SC(".cn"));
	REGISTERMETHOD(clearContinuousHandler, 0, _SC(""));
	sq_pop(v,1);

	beforeContinuousList.initArray();
	afterContinuousList.initArray();
}

/// �n���h�������Ăяo���BThread::main �̌�ŌĂяo���K�v������
void beforeContinuous(int diff)
{
	call(beforeContinuousList, Thread::currentTick + diff, diff);
}

void afterContinuous()
{
	call(afterContinuousList, Thread::currentTick, Thread::diffTick);
}

/// �@�\�I��
void doneContinuous()
{
	beforeContinuousList.clearData();
	beforeContinuousList.clear();
	afterContinuousList.clearData();
	afterContinuousList.clear();
}

};
