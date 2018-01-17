#include "pch.h"
#include "Class1.h"
#include "header/DeviceFingerprint.h"


using namespace WindowsRuntimeComponent1;
using namespace Platform;

void Class1::OnGetDFP(std::wstring s)
{

}

Class1::Class1()
{
	class Task : public IDfpCallback
	{
		typedef void(*DFPCallBack)(std::wstring);

	public:
		// impplements IDfpCallback
		virtual void OnDfpReturn(const wchar_t* dfp)
		{
			if (callback != nullptr)
			{
				std::wstring dfp_data = dfp != nullptr ? dfp : TEXT("");
				callback(dfp_data);
			}

			// 注意需要释放
			delete this;
		}
		DFPCallBack callback;
	};

	try
	{
		const auto dfpdll = TEXT("DevFP");
		LoadPackagedLibrary(dfpdll, 0);
		Task* t = new Task();
		if (t != nullptr)
		{
			t->callback =   OnGetDFP;
			get_dfp(t);
		}
	}
	catch (...)
	{

	}

}
