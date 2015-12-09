#ifndef CANNYFILTER_H
#define CANNYFILTER_H

#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>

#include <BaseDialog.h>

class CannyFilterDialog : public BaseDialog
{
	Q_OBJECT

public:
	explicit CannyFilterDialog(QWidget *parent, Controller *controller);
	~CannyFilterDialog();

protected:
	void setOptions();

protected slots:
	void processImage();

private:
	QGroupBox* threshBox;
	QLabel* labelLowThresh;
	QLabel* labelHighThresh;
	QLineEdit* leditLow;
	QLineEdit* leditHigh;
};

#endif // CANNYFILTER_H
