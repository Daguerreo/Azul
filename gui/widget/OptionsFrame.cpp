#include "OptionsFrame.h"

OptionsFrame::OptionsFrame(QWidget *parent): QFrame(parent)
{
	setFrameStyle( QFrame::NoFrame );
	setSizePolicy( QSizePolicy::Fixed, QSizePolicy::Expanding );
}

OptionsFrame::~OptionsFrame()
{
}
