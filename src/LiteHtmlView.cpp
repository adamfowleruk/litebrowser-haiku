#include "LiteHtmlView.h"

LiteHtmlView::LiteHtmlView(BRect frame, const char *name, uint32 resizingMode, uint32 flags)
	: BView(frame,name,resizingMode,flags),
	fContext(NULL)
{
	;
}

void
LiteHTMLView::SetContext(litehtml::context* ctx)
{
	fContext = ctx;
}

void
RenderFile(const char* localFilePath)
{
	
}
