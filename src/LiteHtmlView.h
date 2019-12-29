#ifndef LITEHTMLVIEW_H
#define LITEHTMLVIEW_H

#include <litehtml/litehtml.h>
#include <View.h>

class LiteHtmlView : public BView, protected litehtml::document_container
{
public:
								//LiteHtmlView(BMessage *archive);
								LiteHtmlView(BRect frame, const char *name, uint32 resizingMode, uint32 flags);
								//LiteHtmlView(const char *name, uint32 flags, BLayout *layout=NULL);
								
	virtual						~LiteHtmlView();
	
			void				SetContext(litehtml::context* ctx);
			void				RenderFile(const char* localFilePath);
protected:
	
private:
	litehtml::context*			fContext;
};

#endif
