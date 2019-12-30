#ifndef APP_H
#define APP_H

#include <Application.h>
#include "../litehtml/include/litehtml.h"

class App : public BApplication
{
public:
	App(litehtml::context* ctx);
};

#endif
