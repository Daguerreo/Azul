#ifndef CANNYFILTER_H
#define CANNYFILTER_H

#include <QGroupBox>
#include <BaseDialog.h>
#include <EntryGroupBox.h>

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
	EntryGroupBox* mThreshBox;
};

#endif // CANNYFILTER_H
