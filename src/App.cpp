#include "App.h"
#include "MainWindow.h"
#include "../litehtml/include/litehtml.h"

char master_css[] = 
{
#include "master.css.inc"
,0
};

App::App(litehtml::context* ctx,const char* filePath)
	:	BApplication("application/x-vnd.af-litebrowser")
{
	MainWindow *mainwin = new MainWindow(ctx);
	if (NULL != filePath)
	{
		mainwin->LoadFile(filePath);
	}
	mainwin->Show();
}

int main (int argc, char *argv[])
{
	litehtml::context html_context;
	html_context.load_master_stylesheet(master_css);

	const char* filePath = NULL;
	if (argc > 1)
	{
		filePath = argv[1];
	}
	App *app = new App(&html_context,filePath);
	app->Run();
	delete app;
	return 0;
}
