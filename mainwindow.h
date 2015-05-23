#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "pixelinfodialog.h"
#include "grayscaledialog.h"
#include "contrastdialog.h"
#include "sharpendialog.h"

#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QFileInfoList>
#include <QLabel>
#include <QSpinBox>
#include <QFileDialog>
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

protected slots:
    void resizeEvent( QResizeEvent *event );
    bool eventFilter( QObject *obj, QEvent *ev );


protected:
	void showImage( const QImage& image );
	void scaleView( const float& factor );

private slots:
	void on_action_Open_triggered();
	void on_action_Save_triggered();
	void on_action_Pixel_Info_triggered();
	void on_action_Grayscale_triggered();
	void on_action_Contrast_Brightness_triggered();
	void on_action_Sharpen_triggered();

private:
    Ui::MainWindow *ui;
    PixelInfoDialog* mPixelInfoDialog;
	GrayscaleDialog* mGrayscaleDIalog;
	ContrastDialog* mContrastDialog;
	SharpenDialog* mSharpenDialog;

    QGraphicsPixmapItem* mPixmapItem;
    QGraphicsScene mScene;
    QFileInfoList mFileInfoList;
    QLabel mLoadTime;
    QLabel mImageSize;
    QSpinBox mZoomBox;
	QImage mImage;
    float mScaleFactor;


};

#endif // MAINWINDOW_H
