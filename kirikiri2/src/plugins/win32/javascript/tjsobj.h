#ifndef __TJSOBJ_H__
#define __TJSOBJ_H__

#include <windows.h>
#include "tp_stub.h"
#include <v8.h>
using namespace v8;

#include "tjsbase.h"

/**
 * 吉里吉里用オブジェクトを単純保持するJavaScript用クラス情報
 */
class TJSObject : public TJSBase {

public:
	// 初期化用
	static void init();
	static void done();

	// オブジェクト生成
	static Local<Object> toJSObject(const tTJSVariant &variant);
	// バリアント取得用
	static bool getVariant(tTJSVariant &result, Handle<Object> obj);

private:
	// オブジェクト定義
	static Persistent<ObjectTemplate> objectTemplate;

	// 解放用
	static void release(Persistent<Value> object, void *parameter);

	// アクセス用メソッド
	static Handle<Value> getter(Local<String> property, const AccessorInfo& info);
	static Handle<Value> setter(Local<String> property, Local<Value> value, const AccessorInfo& info);
	static Handle<Value> caller(const Arguments& args);

	// 格納情報コンストラクタ
	TJSObject(const tTJSVariant &variant);
	~TJSObject();
	
	tTJSVariant variant;
};

#endif