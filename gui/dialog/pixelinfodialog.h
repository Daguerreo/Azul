#ifndef PIXELINFODIALOG_H
#define PIXELINFODIALOG_H

#include <QDialog>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

namespace Ui {
class PixelInfoDialog;
}

class PixelInfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PixelInfoDialog(QWidget *parent = 0);
    ~PixelInfoDialog();
    int getWidthClip() const;
    int getHeightClip() const;

public slots:
    void updateClip( const QPixmap& clip, const QPointF mousePos );

private:
    Ui::PixelInfoDialog *ui;
	QGraphicsPixmapItem* mPixmapItem;
    QGraphicsScene mScene;
};

#endif // PIXELINFODIALOG_H
