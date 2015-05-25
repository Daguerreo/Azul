#include "smoothingdialog.h"
#include "ui_smoothingdialog.h"

SmoothingDialog::SmoothingDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::SmoothingDialog)
{
	ui->setupUi(this);
}

SmoothingDialog::~SmoothingDialog()
{
	delete ui;
}
