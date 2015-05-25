#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "pixelinfodialog.h"
#include "grayscaledialog.h"
#include "contrastdialog.h"
#include "sharpendialog.h"
#include "smoothingdialog.h"

#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QFileInfoList>
#include <QLabel>
#include <QSpinBox>
#include <QFileDialog>
#include <QRubberBand>
#include <opencv2/core/core.hpp>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
	void updateImage(const QImage &image );

signals:
    void sigPixelInfoDialog( const QPixmap& clip, const QPointF& mousePos );
	void sigGrayscaleDialog( const QImage& image );
	void sigContrastDialog( const QImage& image );
	void sigSharpenDialog( const QImage& image );

protected:
    void resizeEvent( QResizeEvent *event );
	bool eventFilter( QObject *obj, QEvent *event );
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);

protected slots:
	void showImage( const QImage& image );
	void scaleView( const float& factor );
	float getImageScaleFactor();
	void updateZoomBox();
	void updateZoomBoxManually(int zoom);

private slots:
	void on_action_Open_triggered();
	void on_action_Save_triggered();
	void on_action_Pixel_Info_triggered();
	void on_action_Grayscale_triggered();
	void on_action_Contrast_Brightness_triggered();
	void on_action_Sharpen_triggered();
	void on_action_Smoothing_triggered();
	void on_action_Adapt_Zoom_triggered();
	void on_action_Zoom_Out_triggered();
	void on_action_Zoom_In_triggered();

private:
    Ui::MainWindow *ui;
    PixelInfoDialog* mPixelInfoDialog;
	GrayscaleDialog* mGrayscaleDIalog;
	ContrastDialog* mContrastDialog;
	SharpenDialog* mSharpenDialog;
	SmoothingDialog* mSmoothingDialog;

    QGraphicsPixmapItem* mPixmapItem;
    QGraphicsScene mScene;
    QFileInfoList mFileInfoList;
    QLabel mLoadTime;
    QLabel mImageSize;
    QSpinBox mZoomBox;
	QImage mImage;
	QImage mImageInRect;
    float mScaleFactor;
	QRubberBand* mRubberBand;
	QPoint mypoint;

};

#endif // MAINWINDOW_H
