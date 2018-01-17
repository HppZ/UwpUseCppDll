#ifndef DFP_INTERFACE_INCLUDE_H_
#define DFP_INTERFACE_INCLUDE_H_

#ifdef DEVICEFINGERPRINT_EXPORTS
#define DEVICEFINGERPRINT_API __declspec(dllexport)
#else
#define DEVICEFINGERPRINT_API __declspec(dllimport)
#endif

#include <string>

class IDfpCallback {
public:
    ~IDfpCallback() {}
    virtual void OnDfpReturn(const wchar_t* dfp) = 0;
};

extern "C" {
    DEVICEFINGERPRINT_API void  get_dfp(IDfpCallback* callback);
    DEVICEFINGERPRINT_API void  get_device_info(std::wstring* env);
    DEVICEFINGERPRINT_API void  get_dfp_sync(std::wstring* dfp);
}

#endif	// !defined(DFP_INTERFACE_INCLUDE_H_)