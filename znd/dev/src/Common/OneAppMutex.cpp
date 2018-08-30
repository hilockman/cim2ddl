#include "Stdafx.h"
#include <windows.h>

HANDLE CreateOneAppMutex(const char* lpszName)
{
	HANDLE	hMutex = CreateMutex(NULL, 1, lpszName);   // Create mutex
	switch (GetLastError())
	{
	case ERROR_SUCCESS:
		//
		// Mutex created successfully. There is no instances running
		//
		break;

	case ERROR_ALREADY_EXISTS:
		//
		// Mutex already exists so there is a running instance of our app.
		//
		hMutex = NULL;
		break;

	default:
		//
		// Failed to create mutex by unkniown reason
		//
		break;
	}

	return hMutex;
}
