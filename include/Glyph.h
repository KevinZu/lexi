#ifndef __GLYPY_H__
#define __GLYPY_H__

#include "Window.h"

class Glyph{
public:
	virtual void Draw(Window w) ;
	virtual void Bounds (Rect&);
	virtual bool Intersects (const Point&);
	virtual void Insert (Glyph*, int);
	virtual void Remove (Glyph*);
	virtual Glyph* Child (int);
	virtual Glyph* Parent();
};



#endif

