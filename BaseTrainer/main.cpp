#include "mainform.h"
#include <Windows.h>
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	#if _DEBUG
		AllocConsole();
	#endif

	argc =0;
	QApplication a(argc, NULL);
	MainForm w;
	w.show();

	return a.exec();	
}
//Dll entry point
BOOL APIENTRY DllMain(HINSTANCE hInstance, DWORD fdwReason, LPVOID lpReserved)
{
	UNREFERENCED_PARAMETER(lpReserved);

	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
		{
			HANDLE hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)main, (LPVOID)hInstance, 0, NULL);
			if (hThread == NULL)
				return FALSE;
		}
	}
	return TRUE;
}