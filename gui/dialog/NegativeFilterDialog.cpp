#include "NegativeFilterDialog.h"

NegativeFilterDialog::NegativeFilterDialog(QWidget* parent, Controller* controller) : BaseDialog(parent, controller, false)
{
	setWindowTitle(tr("Negative Filter"));

}

NegativeFilterDialog::~NegativeFilterDialog()
{
}

void NegativeFilterDialog::processImage()
{
	mController->negativeFilter();

	QImage image = mController->requestWCQImage();
	displayImage( image );
}
