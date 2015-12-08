#ifndef NEGATIVEDIALOG_H
#define NEGATIVEDIALOG_H

#include <QObject>
#include <QWidget>
#include <BaseDialog.h>

class NegativeFilterDialog : public BaseDialog
{
	Q_OBJECT

public:
	NegativeFilterDialog(QWidget *parent, Controller *controller);
	~NegativeFilterDialog();

protected:

protected slots:
	void processImage();
};

#endif // NEGATIVEDIALOG_H
