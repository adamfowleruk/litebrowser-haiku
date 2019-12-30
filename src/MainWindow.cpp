#include "MainWindow.h"

#include <Application.h>
#include <LayoutBuilder.h>
#include <ScrollBar.h>
#include <Window.h>
#include <TextView.h>

#include "../litehtml/include/litehtml.h"
#include "../litehtml/containers/haiku/container_haiku.h"

MainWindow::MainWindow(litehtml::context* ctx)
	:	BWindow(BRect(100,100,500,400),"litebrowser",B_DOCUMENT_WINDOW, B_NOT_ZOOMABLE),
	fContext(ctx)
{
	fHtmlView = new LiteHtmlView(Bounds(), "html");
	fHtmlView->SetContext(ctx);
	
	BGroupLayout* vGroup = new BGroupLayout(B_VERTICAL, 0);
	vGroup->SetInsets(0, 0, 0, 0);
	SetLayout(vGroup);
	
	//vGroup->AddView(fHtmlView);
	
	
	BGroupLayout* hGroup = new BGroupLayout(B_HORIZONTAL, 0);
	hGroup->SetInsets(0, -1, -1, -1); // hides scroll bar borders
	BView* hView = new BView("hview", 0, hGroup);
	
	BLayoutItem* htmlView = hGroup->AddView(fHtmlView);
	htmlView->SetExplicitAlignment(BAlignment(B_ALIGN_USE_FULL_WIDTH, 
		B_ALIGN_USE_FULL_HEIGHT));

	BScrollBar* scrollBar = new BScrollBar("htmlscroll",
		fHtmlView, 0, 100, B_VERTICAL);
	scrollBar->SetResizingMode(B_FOLLOW_RIGHT | B_FOLLOW_TOP);
	BLayoutItem* liScrollBar = hGroup->AddView(scrollBar);
	liScrollBar->SetExplicitAlignment(BAlignment(B_ALIGN_RIGHT, 
		B_ALIGN_USE_FULL_HEIGHT));
	
	BLayoutItem* hGroupView = vGroup->AddView(hView);
	hGroupView->SetExplicitAlignment(BAlignment(B_ALIGN_USE_FULL_WIDTH, 
		B_ALIGN_USE_FULL_HEIGHT));
		
	BScrollBar* hScroll = new BScrollBar("hhtmlscroll",
		fHtmlView,0,100,B_HORIZONTAL);
	hScroll->SetResizingMode(B_FOLLOW_LEFT | B_FOLLOW_BOTTOM);
	BLayoutItem* liHScrollBar = vGroup->AddView(hScroll);
	liHScrollBar->SetExplicitAlignment(BAlignment(B_ALIGN_USE_FULL_WIDTH, 
		B_ALIGN_BOTTOM));
	
	//BTextView* txt = new BTextView("text");
	//vGroup->AddView(txt);
	//txt->SetText("Some text here");
	
	fHtmlView->RenderFile("/boot/home/git/Paladin/Documentation/Paladin Documentation.html");
	//fHtmlView->RenderFile("/boot/home/git/test.html");
}


void
MainWindow::MessageReceived(BMessage *msg)
{
	switch (msg->what)
	{
		default:
		{
			BWindow::MessageReceived(msg);
			break;
		}
	}
}


bool
MainWindow::QuitRequested(void)
{
	be_app->PostMessage(B_QUIT_REQUESTED);
	return true;
}

void
MainWindow::ScreenChanged(BRect	screenSize, color_space	depth)
{
	fHtmlView->Invalidate();
} 
