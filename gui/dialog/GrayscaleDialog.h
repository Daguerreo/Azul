#ifndef GRAYSCALEDIALOG_H
#define GRAYSCALEDIALOG_H

#include <QObject>
#include <QWidget>

#include <BaseDialog.h>
#include <RadioButtonGroupBox.h>
#include <SliderGroupBox.h>

class GrayscaleDialog : public BaseDialog
{
	Q_OBJECT

public:
	explicit GrayscaleDialog(QWidget *parent, Mediator *mediator);
	~GrayscaleDialog();

protected:
	void setOptions();

protected slots:
	void processImage();
	void enableSlider(int index);

private:
	RadioButtonGroupBox* mAlgoRadio;
	SliderGroupBox*	mGraySlider;
};

#endif // GRAYSCALEDIALOG_H
