#ifndef OPTIONSFRAME_H
#define OPTIONSFRAME_H

#include <QFrame>
#include <QObject>

class OptionsFrame : public QFrame
{
	Q_OBJECT
public:
	OptionsFrame(QWidget *parent=0);
	~OptionsFrame();
};

#endif // OPTIONSFRAME_H
