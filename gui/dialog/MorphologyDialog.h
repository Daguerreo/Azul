#ifndef MORPHOLOGYDIALOG_H
#define MORPHOLOGYDIALOG_H

#include <QObject>
#include <QWidget>
#include <BaseDialog.h>
#include <EntryGroupBox.h>
#include <RadioButtonGroupBox.h>

class MorphologyDialog : public BaseDialog
{
	Q_OBJECT

public:
	MorphologyDialog(QWidget *parent, Controller *controller);
	~MorphologyDialog();

protected:
	void setOptions();

protected slots:
	void processImage();
	void enableIterations(int index);

private:
	EntryGroupBox* mOptionsBox;
	RadioButtonGroupBox* mOperatorRadio;
	RadioButtonGroupBox* mKernelRadio;
};

#endif // MORPHOLOGYDIALOG_H
