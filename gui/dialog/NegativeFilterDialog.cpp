#include "NegativeFilterDialog.h"

NegativeFilterDialog::NegativeFilterDialog(QWidget* parent, Mediator* mediator) : BaseDialog(parent, mediator, false)
{
	setWindowTitle(tr("Negative Filter"));

}

NegativeFilterDialog::~NegativeFilterDialog()
{
}

void NegativeFilterDialog::processImage()
{
	mMediator->negativeFilter();

	QImage image = mMediator->requestWCQImage();
	displayImage( image );
}
