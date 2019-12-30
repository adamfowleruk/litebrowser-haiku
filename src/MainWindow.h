#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <Window.h>

#include "../litehtml/include/litehtml.h"
#include "../litehtml/containers/haiku/container_haiku.h"

class MainWindow : public BWindow
{
public:
						MainWindow(litehtml::context* ctx);
			void		MessageReceived(BMessage *msg);
			bool		QuitRequested(void);
	virtual void		ScreenChanged(BRect	screenSize, color_space	depth) override;
			
private:
	litehtml::context*	fContext;
	LiteHtmlView* 		fHtmlView;
};

#endif
