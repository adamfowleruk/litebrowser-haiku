#include "App.h"
#include "MainWindow.h"

char master_css[] = 
{
#include "master.css.inc"
,0
};

App::App(litehtml::context* ctx)
	:	BApplication("application/x-vnd.af-litebrowser")
{
	MainWindow *mainwin = new MainWindow(ctx);
	mainwin->Show();
}

int main (int argc, char *argv[])
{
	litehtml::context html_context;
	html_context.load_master_stylesheet(master_css);

	App *app = new App(&html_context);
	app->Run();
	delete app;
	return 0;
}
