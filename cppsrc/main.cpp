#include <napi.h>
#include "encdec.h"

Napi::Boolean Encode(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    auto buffer = info[0].As<Napi::Uint8Array>();
    auto offset = info[1].ToNumber();
    auto length = info[2].ToNumber();
    return Napi::Boolean::New(
        env, W2EncDec::Encode(buffer.Data(), offset.Int32Value(), length.Int32Value()));
}

Napi::Boolean Decode(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    auto buffer = info[0].As<Napi::Uint8Array>();
    auto offset = info[1].ToNumber();
    auto length = info[2].ToNumber();
    return Napi::Boolean::New(
        env, W2EncDec::Decode(buffer.Data(), offset.Int32Value(), length.Int32Value()));
}

Napi::Object Init(Napi::Env env, Napi::Object exports)
{
    srand(time(0));
    exports.Set(Napi::String::New(env, "encode"), Napi::Function::New(env, Encode));
    exports.Set(Napi::String::New(env, "decode"), Napi::Function::New(env, Decode));
    return exports;
}

NODE_API_MODULE(w2encdec, Init)