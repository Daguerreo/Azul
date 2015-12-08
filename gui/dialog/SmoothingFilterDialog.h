#ifndef SMOOTHINGFILTERDIALOG_H
#define SMOOTHINGFILTERDIALOG_H

#include <QObject>
#include <QWidget>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>

#include <BaseDialog.h>
#include <RadioButtonGroupBox.h>

class SmoothingFilterDialog : public BaseDialog
{
	Q_OBJECT

public:
	explicit SmoothingFilterDialog(QWidget *parent, Controller *controller);
	~SmoothingFilterDialog();

protected:
	void setOptions();

protected slots:
	void processImage();

private:
	RadioButtonGroupBox* mAlgoRadio;
	QGroupBox* mKernelBox;
	QLabel* labelKernel;
	QLineEdit* leditKernel;
};

#endif // SMOOTHINGFILTERDIALOG_H
