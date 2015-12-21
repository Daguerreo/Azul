#ifndef THRESHOLDDIALOG_H
#define THRESHOLDDIALOG_H

#include <QObject>
#include <QWidget>
#include <BaseDialog.h>
#include <RadioButtonGroupBox.h>
#include <SliderGroupBox.h>

class ThresholdDialog : public BaseDialog
{
	Q_OBJECT

public:
	explicit ThresholdDialog(QWidget *parent, Controller *controller);
	~ThresholdDialog();

protected:
	void setOptions();

protected slots:
	void processImage();
	void enableSlider(int index);

private:
	RadioButtonGroupBox* mTypeRadio;
	SliderGroupBox*		 mThresholdSlider;
};

#endif // THRESHOLDDIALOG_H
