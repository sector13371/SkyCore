#ifndef SC_APPLICATION_H
#define SC_APPLICATION_H

extern void Logic();

class SkyApplication
{
public:
	HWND hWnd = NULL;
	void Init( std::string name, WNDPROC proc )
	{
		WNDCLASSEX wCls = { sizeof(WNDCLASSEX), 0, proc, 0, 0, NULL, 0, 0, 0, 0, name.c_str(), 0 };
		RegisterClassEx( &wCls );
		this->hWnd = CreateWindowEx( 0, name.c_str(), name.c_str(), WS_DISABLED, 0, 0, 0, 0, HWND_DESKTOP, NULL, NULL, NULL );
		if( !this->hWnd )
			throw "!CreateWindowEx()";
	}
	int Run()
	{
		MSG nMss;
		HACCEL hAccelTable = LoadAccelerators( NULL, "" );
		while ( GetMessage( &nMss, NULL, 0, 0 ) )
		{
			if ( !TranslateAccelerator( nMss.hwnd, hAccelTable, &nMss ) )
			{
				TranslateMessage( &nMss );
				DispatchMessage( &nMss );
			}
			Logic();
		}
		return (int)nMss.wParam;
	}
};


#endif //SC_APPLICATION_H