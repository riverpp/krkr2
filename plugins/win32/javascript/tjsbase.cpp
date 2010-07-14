#include "tjsbase.h"

// パラメータ取得
bool
TJSBase::getVariant(tTJSVariant &result, Handle<Object> obj)
{
	if (obj->InternalFieldCount() > 0) {
		TJSBase *base = (TJSBase*)obj->GetPointerFromInternalField(0);
		result = base->variant;
		return true;
	}
	return false;
}

