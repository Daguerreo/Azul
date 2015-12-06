#include "ImageFrame.h"

ImageFrame::ImageFrame(QWidget *parent) : QFrame(parent)
{
	setFrameStyle( QFrame::Box );
	setSizePolicy( QSizePolicy::Preferred, QSizePolicy::Preferred );
	setBaseSize(QSize(320,240));
	setMinimumSize(320,240);

	mGraphicView = new QGraphicsView(this);
	mGraphicView->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );
	mGraphicView->setBaseSize( 320, 240 );
	mGraphicView->setMinimumSize( 320, 240 );
	mPixmapItem = new QGraphicsPixmapItem();

	mGraphicView->setScene(&mScene);
	mScene.addItem( mPixmapItem );
}

ImageFrame::~ImageFrame()
{
	delete mGraphicView;
	delete mPixmapItem;

}

void ImageFrame::Resize()
{
	mGraphicView->fitInView(mPixmapItem, Qt::KeepAspectRatio);
}

void ImageFrame::resizeEvent(QResizeEvent *event)
{
	mGraphicView->fitInView(mPixmapItem, Qt::KeepAspectRatio);
	QWidget::resizeEvent(event);
}

