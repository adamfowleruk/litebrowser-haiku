/*
 * Copyright 2019-2020 Haiku Inc.
 * All rights reserved. Distributed under the terms of the MIT license.
 * Constributors
 * 2019-2020	Adam Fowler <adamfowleruk@gmail.com>
 */
#include "App.h"
#include "MainWindow.h"
#include "../litehtml/include/litehtml.h"

char master_css[] = 
{
#include "master.css.inc"
,0
};

App::App(litehtml::context* ctx,const char* filePathOrUrl)
	:	BApplication("application/x-vnd.af-litebrowser")
{
	MainWindow *mainwin = new MainWindow(ctx);
	if (NULL != filePathOrUrl)
	{
		mainwin->Load(filePathOrUrl);
	}
	mainwin->Show();
}

int main (int argc, char *argv[])
{
	litehtml::context html_context;
	html_context.load_master_stylesheet(master_css);

	const char* filePathOrUrl = NULL;
	if (argc > 1)
	{
		filePathOrUrl = argv[1];
	}
	App *app = new App(&html_context,filePathOrUrl);
	app->Run();
	delete app;
	return 0;
}
