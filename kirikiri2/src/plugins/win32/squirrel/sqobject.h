#ifndef __SQOBJECT_H__
#define __SQOBJECT_H__

// �^��
#ifndef SQOBJECTNAME
#define SQOBJECTNAME _SC("Object")
#endif

#ifndef SQTHREADNAME
#define SQTHREADNAME _SC("Thread")
#endif

#include <squirrel.h>
#include <vector>
#include <string>

/**
 * �I�u�W�F�N�g/�X���b�h�����̏�����
 * @param v squirrel VM
 */
extern void sqobject_init(HSQUIRRELVM v);

/**
 * �I�u�W�F�N�g/�X���b�h�������C������
 * @param tick tick�l
 */
extern int sqobject_main(int tick);

/**
 * �I�u�W�F�N�g/�X���b�h�����I������
 */
extern void sqobject_done();

namespace sqobject {

typedef std::basic_string<SQChar> tstring;

// �G���[�����p
extern SQRESULT ERROR_CREATE(HSQUIRRELVM v);
extern SQRESULT ERROR_BADINSTANCE(HSQUIRRELVM v);

// setter/getter ���O����
extern void getSetterName(tstring &store, const SQChar *name);
extern void getGetterName(tstring &store, const SQChar *name);

class Object; // �I�u�W�F�N�g�N���X
class Thread; // �X���b�h�N���X
class ObjectInfo; // �I�u�W�F�N�g���ێ��p�N���X

/**
 * �I�u�W�F�N�g�p
 */
class Object {

	// ------------------------------
	// �p�����
	// ------------------------------
protected:
	static std::vector<SQUserPointer>tags;
public:
	static void pushTag(const SQUserPointer tag) {
		tags.push_back(tag);
	}

protected:
	// ���̃I�u�W�F�N�g��҂��Ă�X���b�h�̈ꗗ
	std::vector<Thread*> _waitThreadList;
	// delegate
	ObjectInfo *delegate;

public:
	/**
	 * �I�u�W�F�N�g�҂��̓o�^
	 * @param thread �X���b�h
	 */
	void addWait(Thread *thread);

	/**
	 * �I�u�W�F�N�g�҂��̉���
	 * @param thread �X���b�h
	 */
	void removeWait(Thread *thread);

protected:

	/**
	 * �R���X�g���N�^
	 */
	Object();

	/**
	 * �f�X�g���N�^
	 */
	virtual ~Object();

	/**
	 * ���̃I�u�W�F�N�g��҂��Ă���P�X���b�h�̑҂�������
	 */
	void _notify();
	
	/**
	 * ���̃I�u�W�F�N�g��҂��Ă���S�X���b�h�̑҂�������
	 */
	void _notifyAll();

	// ------------------------------------------------------------------

public:
	/**
	 * @return �I�u�W�F�N�g���I�u�W�F�N�g
	 */
	static Object *getObject(HSQUIRRELVM v, int idx);

protected:
	/**
	 * �I�u�W�F�N�g�̃����[�T
	 */
	static SQRESULT release(SQUserPointer up, SQInteger size);

	/**
	 * �I�u�W�F�N�g�̃R���X�g���N�^
	 */
	static SQRESULT constructor(HSQUIRRELVM v);

	static bool isClosure(SQObjectType type);
	
	/**
	 * �v���p�e�B����l���擾
	 * @param name �v���p�e�B��
	 * @return �v���p�e�B�l
	 */
	static SQRESULT _get(HSQUIRRELVM v);

	/**
	 * �v���p�e�B�ɒl��ݒ�
	 * @param name �v���p�e�B��
	 * @param value �v���p�e�B�l
	 */
	static SQRESULT _set(HSQUIRRELVM v);

	/**
	 * set�v���p�e�B�̑��݊m�F
	 * @param name �v���p�e�B��
	 * @return set�v���p�e�B�����݂����� true
	 */
	static SQRESULT hasSetProp(HSQUIRRELVM v);
	
	/**
	 * �Ϗ��̐ݒ�
	 */
	static SQRESULT setDelegate(HSQUIRRELVM v);

	/**
	 * �Ϗ��̎擾
	 */
	static SQRESULT getDelegate(HSQUIRRELVM v);
	
	/**
	 * �P��X���b�h�ւ̃I�u�W�F�N�g�҂��̏I���ʒm�p
	 */
	static SQRESULT notify(HSQUIRRELVM v);

	/**
	 * �S�X���b�h�ւ̃I�u�W�F�N�g�҂��̏I���ʒm
	 */
	static SQRESULT notifyAll(HSQUIRRELVM v);

public:
	/**
	 * �N���X�̓o�^
	 * @param v squirrel VM
	 */
	static void registClass(HSQUIRRELVM v);
};

};// namespace

// ���\�b�h�o�^
#define REGISTMETHOD(name) \
	sq_pushstring(v, _SC(#name), -1);\
	sq_newclosure(v, name, 0);\
	sq_createslot(v, -3);

// ���\�b�h�o�^�i���O���j
#define REGISTMETHODNAME(name, method) \
	sq_pushstring(v, _SC(#name), -1);\
	sq_newclosure(v, method, 0);\
	sq_createslot(v, -3);

// ���\�b�h�o�^
#define REGISTENUM(name, value) \
	sq_pushstring(v, _SC(#name), -1);\
	sq_pushinteger(v, value);\
	sq_createslot(v, -3);

#endif