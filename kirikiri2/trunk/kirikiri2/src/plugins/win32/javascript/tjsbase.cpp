#include "tjsbase.h"

void
TJSBase::wrap(Isolate *isolate, Handle<Object> obj)
{
	obj->SetInternalField(0, External::New(isolate, this));
}

// パラメータ取得
bool
TJSBase::getVariant(tTJSVariant &result, Handle<Object> obj)
{
	Local<Value> v = obj->GetInternalField(0);
	bool empty = v.IsEmpty();
	if (!v.IsEmpty()) {
		TJSBase *base = (TJSBase*)External::Cast(*v);
		result = base->variant;
		return true;
	}
	return false;
}
