/*
 * copyright (c)2009 http://wamsoft.jp
 * zlib license
 */

#ifndef __SQOBJECTINFO_H__
#define __SQOBJECTINFO_H__

#include <squirrel.h>

namespace sqobject {

/// ������
HSQUIRRELVM init();
/// �I��
extern void done();
/// ���ێ��p�O���[�o��VM�̎擾
extern HSQUIRRELVM getGlobalVM();

class Object;
class Thread;
	
// ---------------------------------------------------------
// ObjectInfo
// ---------------------------------------------------------

/**
 * squirrel �I�u�W�F�N�g�ێ��p�N���X
 * ��Q�Ƃ��ێ��\
 */
class ObjectInfo {

protected:
	HSQOBJECT obj; // �I�u�W�F�N�g�Q�Ə��

public:
	// ���e����
	void clear();

	// �X�^�b�N����擾
	void getStack(HSQUIRRELVM v, int idx);

    // �X�^�b�N�����Q�ƂƂ��Ď擾
	void getStackWeak(HSQUIRRELVM v, int idx);
  
	// �R���X�g���N�^
	ObjectInfo();

	// �R���X�g���N�^
	ObjectInfo(HSQUIRRELVM v, int idx);

	// �R�s�[�R���X�g���N�^
	ObjectInfo(const ObjectInfo &orig);

	// ���
	ObjectInfo & operator=(const ObjectInfo &orig);

	// �f�X�g���N�^
	virtual ~ObjectInfo();

	// null ���H
	bool isNull() const;
	
	// �����X���b�h���H
	bool isSameThread(const HSQUIRRELVM v) const;

	// �X���b�h���擾
	operator HSQUIRRELVM() const;
	
	// �I�u�W�F�N�g��PUSH
	void push(HSQUIRRELVM v) const;

	// ---------------------------------------------------
	// delegate �����p
	// ---------------------------------------------------

	// delegate �Ƃ��ċ@�\���邩�ǂ���
	bool isDelegate();

	// bindenv �����邩�ǂ���
	bool isBindDelegate();

	// ---------------------------------------------------
	// �f�[�^�擾
	// ---------------------------------------------------

	const SQChar *getString();
	
	// ---------------------------------------------------
	// �I�u�W�F�N�g�擾
	// ---------------------------------------------------

	// Thread �̃C���X�^���X���[�U�|�C���^���擾
	Thread *getThread();
	
	// Object �̃C���X�^���X���[�U�|�C���^���擾
	Object *getObject();
	
	// ---------------------------------------------------
	// wait�����p���\�b�h
	// ---------------------------------------------------

	bool isSameString(const SQChar *str) const;
};

};

#endif