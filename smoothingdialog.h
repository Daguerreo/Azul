#ifndef SMOOTHINGDIALOG_H
#define SMOOTHINGDIALOG_H

#include <QDialog>

namespace Ui {
class SmoothingDialog;
}

class SmoothingDialog : public QDialog
{
	Q_OBJECT

public:
	explicit SmoothingDialog(QWidget *parent = 0);
	~SmoothingDialog();

private:
	Ui::SmoothingDialog *ui;
};

#endif // SMOOTHINGDIALOG_H
