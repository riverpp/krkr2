#include "IDispatchWrapper.hpp"
#include <stdarg.h>

static void log(const tjs_char *format, ...)
{
	va_list args;
	va_start(args, format);
	tjs_char msg[1024];
	_vsnwprintf(msg, 1024, format, args);
	TVPAddLog(msg);
	va_end(args);
}

// {125DF12C-67F5-4d9e-BFD3-6C59B0348952}
static const GUID IID_iTJSDispatch2 = 
{ 0x125df12c, 0x67f5, 0x4d9e, { 0xbf, 0xd3, 0x6c, 0x59, 0xb0, 0x34, 0x89, 0x52 } };

// �I�u�W�F�N�g���̑Ή����Ƃ邽�߂̃}�b�s���O���
// �Ƃ肠�������̃N���X�ɕ�����Ă��Ƃ� static �ێ��őΉ�

#pragma warning(disable: 4786)
#include <map>
using namespace std;
static map<ttstr,int> methodMap;
static map<int,ttstr> methodIdMap;

/**
 * ���O�����ӂ̐��l������
 * @param name ���O
 * @return �A�g���l
 */
static int
getAtom(const tjs_char *name)
{
	ttstr atomName(name);
	map<ttstr,int>::const_iterator n = methodMap.find(atomName);
	if (n != methodMap.end()) {
		return n->second;
	}
	int ret = methodMap.size() + 1;
	methodMap[atomName] = ret;
	methodIdMap[ret] = atomName;
	return ret;
}

/**
 * �A�g���l���疼�O�𓾂�
 * @param atom �A�g���l
 * @return ���O
 */
static const tjs_char *
getName(int atom)
{
	map<int,ttstr>::const_iterator n = methodIdMap.find(atom);
	if (n != methodIdMap.end()) {
		return n->second.c_str();	
	}
	return NULL;
}

/**
 * VARIANT �� tTJSVariant �Ɋi�[����
 * @param result �ϊ���
 * @param variant �ϊ���
 */
void
IDispatchWrapper::storeVariant(tTJSVariant &result, VARIANT &variant)
{
	result.Clear();
	switch (variant.vt) {
	case VT_NULL:
		result = (iTJSDispatch2*)NULL;
		break;
	case VT_I8:
		result = variant.llVal;
		break;
	case VT_I4:
		result = (tjs_int32)variant.lVal;
		break;
	case VT_UI1:
		result = (tjs_int32)variant.bVal;
		break;
	case VT_I2:
		result = (tjs_int32)variant.iVal;
		break;
	case VT_R4:
		result = (double)variant.fltVal;
		break;
	case VT_R8:
		result = variant.dblVal;
		break;
	case VT_BOOL:
		result = (variant.boolVal == VARIANT_TRUE);
		break;
	case VT_BSTR:
		result = variant.bstrVal;
		break;
	case VT_ARRAY | VT_UI1:
		{
			SAFEARRAY *psa = variant.parray;
			unsigned char *p;
			if (SUCCEEDED(SafeArrayAccessData(psa, (LPVOID*)&p))) {
				// p;
				//psa->rgsabound->cElements;
				// XXX variant �ɂǂ�����悤�H
				SafeArrayUnaccessData(psa);
			}
		}
		break;
	case VT_UNKNOWN:
	case VT_DISPATCH:
		if (variant.punkVal) {
			iTJSDispatch2 *obj = NULL;
			if (variant.punkVal->QueryInterface(IID_iTJSDispatch2, (void**)&obj) == S_OK) {
				result = obj;
				obj->Release();
			} else {
				IDispatch *dispatch = NULL;
				if (variant.punkVal->QueryInterface(IID_IDispatch, (void**)&dispatch) == S_OK) {
					iTJSDispatch2 *obj = new iTJSDispatch2Wrapper(dispatch);
					result = obj;
					obj->Release();
					dispatch->Release();
				}
			}
		} else {
			result = (iTJSDispatch2*)NULL;
		}
		break;
	case VT_BYREF | VT_I8:
		result = *variant.pllVal;
		break;
	case VT_BYREF | VT_I4:
		result = (tjs_int32)*variant.plVal;
		break;
	case VT_BYREF | VT_UI1:
		result = (tjs_int32)*variant.pbVal;
		break;
	case VT_BYREF | VT_I2:
		result = (tjs_int32)*variant.piVal;
		break;
	case VT_BYREF | VT_R4:
		result = *variant.pfltVal;
		break;
	case VT_BYREF | VT_R8:
		result = *variant.pdblVal;
		break;
	case VT_BYREF | VT_BOOL:
		result = (*variant.pboolVal == VARIANT_TRUE);
		break;
	case VT_BYREF | VT_BSTR:
		result = *variant.pbstrVal;
		break;
	case VT_BYREF | VT_ARRAY | VT_UI1:
		{
			SAFEARRAY *psa = *(variant.pparray);
			const tjs_uint8 *p;
			if (SUCCEEDED(SafeArrayAccessData(psa, (LPVOID*)&p))) {
				result = tTJSVariant(p, psa->rgsabound->cElements);
				SafeArrayUnaccessData(psa);
			}
		}
		break;
	case VT_BYREF | VT_UNKNOWN:
	case VT_BYREF | VT_DISPATCH:
		if (*(variant.ppunkVal)) {
			iTJSDispatch2 *obj = NULL;
			if ((*(variant.ppunkVal))->QueryInterface(IID_iTJSDispatch2, (void**)&obj) == S_OK) {
				result = obj;
				obj->Release();
			} else {
				IDispatch *dispatch = NULL;
				if ((*(variant.ppunkVal))->QueryInterface(IID_IDispatch, (void**)&dispatch) == S_OK) {
					iTJSDispatch2 *obj = new iTJSDispatch2Wrapper(dispatch);
					result = obj;
					obj->Release();
					dispatch->Release();
				}
			}
		} else {
			result = (iTJSDispatch2*)NULL;
		}
		break;
	case (VT_BYREF | VT_VARIANT):
		storeVariant(result, *variant.pvarVal);
	default:
		;//log(L"unkown result type");
	}
}

/**
 * tTJSVariant �� VARIANT �Ɋi�[����
 * @param result �i�[��
 * @param variant �i�[��
 */
void
IDispatchWrapper::storeVariant(VARIANT &result, tTJSVariant &variant)
{
	VariantClear(&result);
	switch (variant.Type()) {
	case tvtVoid:
		//log(L"void");
		break;
	case tvtObject:
		// �I�u�W�F�N�g
		//log(L"object");
		{
			iTJSDispatch2 *dispatch = variant.AsObjectNoAddRef();
			if (dispatch) {
				V_VT(&result)       = VT_DISPATCH;
				V_DISPATCH(&result) = new IDispatchWrapper(dispatch);
			} else {
				V_VT(&result) = VT_NULL;
			}
		}
		break;
	case tvtString:
		//log(L"string");
		// ������
		V_VT(&result) = VT_BSTR;
		V_BSTR(&result) = SysAllocString(variant.GetString());
		break;
	case tvtOctet:
		//log(L"octet");
		// �I�N�e�b�g��
		{
			tTJSVariantOctet *octet = variant.AsOctetNoAddRef();
			if (octet) {
				SAFEARRAY *psa;
				SAFEARRAYBOUND sabound;
				sabound.lLbound = 0;
				sabound.cElements = octet->GetLength();
				if ((psa = SafeArrayCreate(VT_UI1, 1, &sabound))) {
					// �f�[�^���R�s�[����
					unsigned char *p;
					if (SUCCEEDED(SafeArrayAccessData(psa, (LPVOID*)&p))) {
						memcpy(p, octet->GetData(), octet->GetLength());
						SafeArrayUnaccessData(psa);
						V_VT(&result) = VT_ARRAY | VT_UI1;
						V_ARRAY(&result) = psa;
					} else {
						SafeArrayDestroy(psa);
					}
				} else {
					// �������s����O
				}
			}
		}
		break;
	case tvtInteger:
		// COM �� 64bit ���T�|�[�g���Ă��Ȃ�!!
		// �Ƃ������Ƃ� COM �ɓn�������Ő����l�� 32bit �𒴂��Ȃ��悤�ɒ��ӂ��邱�Ɓi�܁j
		//log(L"integer");
		V_VT(&result) = VT_I4;
		V_I4(&result) = (int)(variant);
		break;
	case tvtReal:
		//log(L"real");
		V_VT(&result) = VT_R8;
		V_R8(&result) = (double)(variant);
		break;
	}
}

//----------------------------------------------------------------------------
// �R���X�g���N�^�E�f�X�g���N�^


IDispatchWrapper::IDispatchWrapper(iTJSDispatch2 *obj) 
{
	refCount = 1;
	this->obj = obj;
	obj->AddRef();
}

IDispatchWrapper::~IDispatchWrapper()
{
	obj->Release();
}

int
IDispatchWrapper::Construct(VARIANT *pvarResult, int argc, VARIANT *argv, tjs_error &err)
{
	log(L"construct");

	int ret = S_OK;
	
	// �����ϊ�
	tTJSVariant **args = new tTJSVariant*[argc];
	for (int i=0;i<argc;i++) {
		args[i] = new tTJSVariant();
		storeVariant(*args[i], argv[argc - i - 1]);
	}
	
	// �R���X�g���N�^�Ăяo��
	iTJSDispatch2 *instance = NULL;
	try {
		if (TJS_SUCCEEDED(err = obj->CreateNew(0, NULL, NULL, &instance, argc, args, obj))) {
			if (instance) {
				if (pvarResult) {
					V_VT(pvarResult)       = VT_DISPATCH;
					V_DISPATCH(pvarResult) = new IDispatchWrapper(instance);
				}
				instance->Release();
			} else {
				if (pvarResult) {
					V_VT(pvarResult) = VT_NULL;
				}
			}
		}
	} catch(...) {
		ret = DISP_E_EXCEPTION;
	}
	
	// �����j��
	for (i=0;i<argc;i++) {
		delete args[i];
	}
	delete[] args;

	return ret;
}

//----------------------------------------------------------------------------
// IUnknown ����

HRESULT STDMETHODCALLTYPE
IDispatchWrapper::QueryInterface(REFIID riid, void __RPC_FAR *__RPC_FAR *ppvObject) {
	if (riid == IID_iTJSDispatch2) {
		if (ppvObject == NULL)
			return E_POINTER;
		*ppvObject = (void*)obj;
		obj->AddRef();
		return S_OK;
	} else if (riid == IID_IUnknown || riid == IID_IDispatch || riid == IID_IDispatchEx) {
		if (ppvObject == NULL)
			return E_POINTER;
		*ppvObject = this;
		AddRef();
		return S_OK;
	} else {
		*ppvObject = 0;
		return E_NOINTERFACE;
	}
}

ULONG STDMETHODCALLTYPE
IDispatchWrapper::AddRef()
{
	refCount++;
	return refCount;
}
	
ULONG STDMETHODCALLTYPE
IDispatchWrapper::Release()
{
	int ret = --refCount;
	if (ret <= 0) {
		delete this;
		ret = 0;
	}
	return ret;
}

//-------------------------------------------------------------------
// IDispatch ����

HRESULT
IDispatchWrapper::GetIDsOfNames(REFIID riid, LPOLESTR* rgszNames, UINT cNames, LCID lcid, DISPID* rgdispid)
{
	HRESULT ret = S_OK;
	UINT i;
	for (i=0; i<cNames; i++) {
		const tjs_char *memberName = rgszNames[i];
		if (true) {
			rgdispid[i] = getAtom(memberName);
		} else {
			rgdispid[i] = DISPID_UNKNOWN;
			ret = DISP_E_UNKNOWNNAME;
		}
	}
	return ret;
}

HRESULT
IDispatchWrapper::Invoke(DISPID dispidMember, REFIID riid, LCID lcid, WORD wFlags,
						 DISPPARAMS* pdispparams, VARIANT* pvarResult, EXCEPINFO* pexcepinfo, UINT* puArgErr)
{
	return InvokeEx(dispidMember, lcid, wFlags, pdispparams, pvarResult, pexcepinfo, NULL);
}

HRESULT
IDispatchWrapper::GetDispID( 
	/* [in] */ BSTR bstrName,
	/* [in] */ DWORD grfdex,
	/* [out] */ DISPID *pid)
{
	const tjs_char *memberName = bstrName;
	if (true) {
		*pid = getAtom(memberName);
		return S_OK;
	} else {
		*pid = DISPID_UNKNOWN;
		return DISP_E_UNKNOWNNAME;
	}
}

HRESULT
IDispatchWrapper::InvokeEx( 
	/* [in] */ DISPID id,
	/* [in] */ LCID lcid,
	/* [in] */ WORD wFlags,
	/* [in] */ DISPPARAMS *pdispparams,
	/* [out] */ VARIANT *pvarResult,
	/* [out] */ EXCEPINFO *pei,
	/* [unique][in] */ IServiceProvider *pspCaller)
{
	if (!pdispparams) return E_POINTER;
	
	const tjs_char *memberName = id == DISPID_VALUE ? NULL : getName(id);
	
	// �����p�����[�^�ݒ�
	int      argc = pdispparams->cArgs;
	VARIANT *argv = pdispparams->rgvarg;

	HRESULT ret = S_OK;
	tjs_error err;
	
	if ((wFlags & DISPATCH_CONSTRUCT)) {

		// �R���X�g���N�^
		ret = Construct(pvarResult, argc, argv, err);
		
	} else if ((wFlags & DISPATCH_METHOD)) {

		// ���\�b�h�Ăяo��
		log(L"FuncCall %ls", memberName);
		
		// �����ϊ�
		tTJSVariant **args = new tTJSVariant*[argc];
		for (int i=0;i<argc;i++) {
			args[i] = new tTJSVariant();
			storeVariant(*args[i], argv[argc - i - 1]);
		}
		
		// �I�u�W�F�N�g���s�p�̃X�N���v�g�N���X�𐶐�
		tTJSVariant result;
		try {
			if (TJS_SUCCEEDED(err = obj->FuncCall(0, memberName, (tjs_uint32*)&id, &result, argc, args, obj))) {
				if (pvarResult) {
					storeVariant(*pvarResult, result);
				}
			}
		} catch(...) {
			ret = DISP_E_EXCEPTION;
		}
		
		// �����j��
		for (i=0;i<argc;i++) {
			delete args[i];
		}
		delete[] args;
		
	} else if ((wFlags & DISPATCH_PROPERTYGET)) {
		
		log(L"PropGet %ls", memberName);
		
		tTJSVariant result;
		try {
			if (TJS_SUCCEEDED(err = obj->PropGet(0, memberName, (tjs_uint32*)&id, &result, obj))) {
				if (pvarResult) {
					storeVariant(*pvarResult, result);
				}
			}
		} catch(...)    {
			ret = DISP_E_EXCEPTION;
		}
	} else if ((wFlags & DISPATCH_PROPERTYPUT) && argc > 0) {

		log(L"PropPut %ls", memberName);
		
		tTJSVariant arg;
		storeVariant(arg, argv[0]);
		try {
			err = obj->PropSet(TJS_MEMBERENSURE, memberName, (tjs_uint32*)&id, &arg, obj);
		} catch(...) {
			ret = DISP_E_EXCEPTION;
		}
	}
	
	if (ret == DISP_E_EXCEPTION) {
		if (pei) {
			memset(pei, 0, sizeof(EXCEPINFO));
			pei->wCode = 0x0201;
			pei->bstrSource = SysAllocString(L"TJScript");
			pei->bstrDescription = SysAllocString(L"Exception");
			pei->scode = DISP_E_EXCEPTION;
		}
	} else if (TJS_FAILED(err)) {
		switch (err) {
		case TJS_E_MEMBERNOTFOUND:
			ret = DISP_E_MEMBERNOTFOUND;
			break;
		case TJS_E_BADPARAMCOUNT:
			ret = DISP_E_BADPARAMCOUNT;
			break;
		case TJS_E_INVALIDPARAM:
			ret = DISP_E_BADVARTYPE;
			break;
		case TJS_E_NOTIMPL:
		case TJS_E_INVALIDTYPE:
		case TJS_E_INVALIDOBJECT:
		case TJS_E_ACCESSDENYED:
		case TJS_E_NATIVECLASSCRASH:
		default:
			ret = S_FALSE;
		}
	}
	
	return ret;
}

HRESULT
IDispatchWrapper::DeleteMemberByDispID( 
		/* [in] */ DISPID id)
{
	const tjs_char *memberName = getName(id);
	HRESULT ret = S_FALSE;
	if (memberName) {
		try {
			if (TJS_SUCCEEDED(obj->DeleteMember(TJS_MEMBERMUSTEXIST, memberName, (tjs_uint32*)&id, obj))) {
				ret = S_OK;
			}
		} catch(...)  {
			TVPAddLog(TJS_W("DeleteMember �ŗ�O"));
		}
	}
	return ret;
}

HRESULT
IDispatchWrapper::GetMemberName( 
	/* [in] */ DISPID id,
	/* [out] */ BSTR *pbstrName)
{
	const tjs_char *memberName = getName(id);
	if (true) {
		if (pbstrName) {
			*pbstrName = SysAllocString(memberName);
		}
		return S_OK;
	} else {
		return DISP_E_UNKNOWNNAME;
	}
}

class GetEnumCaller : public tTJSDispatch /** EnumMembers �p */
{
protected:
	vector<DISPID> *methodEnums;
public:
	GetEnumCaller(vector<DISPID> *methodEnums) : methodEnums(methodEnums) {};
	virtual tjs_error TJS_INTF_METHOD FuncCall( // function invocation
												tjs_uint32 flag,			// calling flag
												const tjs_char * membername,// member name ( NULL for a default member )
												tjs_uint32 *hint,			// hint for the member name (in/out)
												tTJSVariant *result,		// result
												tjs_int numparams,			// number of parameters
												tTJSVariant **param,		// parameters
												iTJSDispatch2 *objthis		// object as "this"
												) {
		//TVPAddLog(TJS_W("enumMemberCallback"));
		if (numparams > 1) {
			if ((int)param[1] != TJS_HIDDENMEMBER) {
				methodEnums->push_back(getAtom(param[0]->GetString()));
			}
		}
		if (result) {
			*result = true;
		}
		return TJS_S_OK;
	}
};

HRESULT
IDispatchWrapper::GetNextDispID( 
	/* [in] */ DWORD grfdex,
	/* [in] */ DISPID id,
	/* [out] */ DISPID *pid)
{
	if (id == DISPID_STARTENUM) {
		methodEnums.clear();
		methodEnumsCount = 0;
		GetEnumCaller caller(&methodEnums);
		tTJSVariantClosure closure(&caller);
		try {
			obj->EnumMembers(TJS_ENUM_NO_VALUE, &closure, obj);
		} catch (...) {
			TVPAddLog(L"EnumMembers �ŗ�O");
		}
	}
	if (methodEnums.size() > methodEnumsCount) {
		*pid = methodEnums[methodEnumsCount++];
		return S_OK;
	} else {
		return S_FALSE;
	}
}

// -------------------------------------------------------------------------------------------

/**
 * ���s�����{��
 * @param dispatch IDispatch
 * @param wFlags ���s���
 * @param membername �����o��
 * @param result ���ʊi�[��
 * @param numparams �p�����[�^��
 * @param param �p�����[�^
 */
tjs_error
iTJSDispatch2Wrapper::Invoke(IDispatch *dispatch,
							 DWORD wFlags,
							 const tjs_char *membername,
							 tTJSVariant *result,
							 tjs_int numparams,
							 tTJSVariant **param
							 )
{
	LCID lcid = LOCALE_SYSTEM_DEFAULT;

	DISPID dispId;
	HRESULT hr;

	if (membername == NULL) {
		if (wFlags & DISPATCH_METHOD) {
			dispId = DISPID_VALUE;
		} else {
			return TJS_E_NOTIMPL;
		}
	} else {
		// DISPID �̎擾
		BSTR wcmdname = SysAllocString(membername);
		hr = dispatch->GetIDsOfNames(IID_NULL, &wcmdname, 1, lcid, &dispId);
		SysFreeString(wcmdname);
		if (FAILED(hr)) {
			return TJS_E_MEMBERNOTFOUND;
		}
	}
	
	// �Ăяo���p�p�����[�^�ϊ�
	DISPPARAMS dispParams;
	memset(&dispParams, 0, sizeof(DISPPARAMS));
	dispParams.cArgs = numparams;
	dispParams.rgvarg = (VARIANT*)malloc(sizeof VARIANTARG * numparams);
	for (int i=0; i<numparams; i++) {
		VariantInit(&dispParams.rgvarg[numparams - i - 1]);
		IDispatchWrapper::storeVariant(dispParams.rgvarg[numparams - i - 1], *param[i]);
	}
	
	// PROPERTYPUT �p���ꏈ��
	DISPID dispIDParam = DISPID_PROPERTYPUT;
	if (wFlags & DISPATCH_PROPERTYPUT) {
		dispParams.cNamedArgs = 1;
		dispParams.rgdispidNamedArgs = &dispIDParam;
	}
	
	// �Ăяo������
	VARIANT invokeResult;
	VariantInit(&invokeResult);
	hr = dispatch->Invoke(dispId, IID_NULL, LOCALE_SYSTEM_DEFAULT, wFlags, &dispParams, &invokeResult, NULL, NULL);
	
	// ��Еt��
	for (i=0; i<numparams; i++) {
		VariantClear(&dispParams.rgvarg[i]);
	}
	free(dispParams.rgvarg);
	
	// �G���[����
	tjs_error ret;
	if (SUCCEEDED(hr)) {
		if (result) {
			IDispatchWrapper::storeVariant(*result, invokeResult);
		}
		VariantClear(&invokeResult);
		ret = TJS_S_OK;
	} else {
		// XXX ��O�ǂ����悤
		switch (hr) {
		case DISP_E_MEMBERNOTFOUND:
			ret = TJS_E_MEMBERNOTFOUND;
			//log(TJS_W("member not found"));
			break;
		case DISP_E_BADPARAMCOUNT:
			ret = TJS_E_BADPARAMCOUNT;
			//log(TJS_W("bad param count"));
			break;
		case DISP_E_BADVARTYPE:
			ret = TJS_E_INVALIDPARAM;
			//log(TJS_W("bad var type"));
			break;
		default:
			//log(TJS_W("other"));
			ret = TJS_E_FAIL;
		}
	}
	return ret;
}