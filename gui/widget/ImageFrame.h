#ifndef IMAGEFRAME_H
#define IMAGEFRAME_H

#include <QFrame>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QObject>

class ImageFrame : public QFrame
{
	Q_OBJECT

public:
	ImageFrame(QWidget *parent=0);
	~ImageFrame();
	void Resize();

public slots:
	void resizeEvent(QResizeEvent *event);

protected:
	QGraphicsView* mGraphicView;
	QGraphicsPixmapItem* mPixmapItem;
	QGraphicsScene mScene;
};

#endif // IMAGEFRAME_H
