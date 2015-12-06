#ifndef CONTRASTDIALOG_H
#define CONTRASTDIALOG_H

#include <QObject>
#include <QWidget>
#include <BaseDialog.h>
#include <SliderGroupBox.h>
#include <DoubleSliderGroupBox.h>

class ContrastDialog : public BaseDialog
{
	Q_OBJECT

public:
	explicit ContrastDialog(QWidget *parent, Mediator *mediator);
	~ContrastDialog();

protected:
	void setOptions();
	void buttonApplyClicked();

protected slots:
	void processImage();

private:
	DoubleSliderGroupBox*	mContrastSlider;
	SliderGroupBox*	mBrightnesSlider;
};

#endif // CONTRASTDIALOG_H
