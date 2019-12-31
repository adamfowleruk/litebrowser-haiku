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
			
	// Unique to this class
			void		LoadFile(const char* filePath);
			
	// BWindow
	virtual void		ScreenChanged(BRect	screenSize, color_space	depth) override;
	virtual void		FrameResized(float newWidth, float newHeight);

protected:
	virtual	void		UpdateScrollbars();
private:
	litehtml::context*	fContext;
	LiteHtmlView* 		fHtmlView;
	BScrollBar* 		vScroll;
	BScrollBar* 		hScroll;
};

#endif
