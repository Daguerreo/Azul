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
	explicit ContrastDialog(QWidget *parent, Controller *controller);
	~ContrastDialog();

protected:
	void setOptions();

protected slots:
	void processImage();

private:
	DoubleSliderGroupBox*	mContrastSlider;
	SliderGroupBox*	mBrightnesSlider;
};

#endif // CONTRASTDIALOG_H
