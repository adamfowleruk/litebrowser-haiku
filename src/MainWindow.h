/*
 * Copyright 2019-2020 Haiku Inc.
 * All rights reserved. Distributed under the terms of the MIT license.
 * Constributors
 * 2019-2020	Adam Fowler <adamfowleruk@gmail.com>
 */
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
			void		Load(const char* filePathOrUrl);
			
	// BWindow overrides
	virtual void		ScreenChanged(BRect	screenSize, color_space	depth) override;
	virtual void		FrameResized(float newWidth, float newHeight) override;

protected:
	// Internal and unique to this class
	virtual	void		UpdateScrollbars();
	
private:
	litehtml::context*	fContext;
	LiteHtmlView* 		fHtmlView;
	BScrollBar* 		vScroll;
	BScrollBar* 		hScroll;
	std::string			fDataReceived;
};

#endif
