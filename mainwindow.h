#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QSpinBox>

#include <Controller.h>
#include <GrayscaleFilterDialog.h>
#include <ContrastDialog.h>
#include <NegativeFilterDialog.h>
#include <PixelInfoDialog.h>
#include <SmoothingFilterDialog.h>

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
	void updateView();

protected:
	void displayImage(const QImage &image);
	void scaleView(const double &factor);

private slots:
	void resizeEvent(QResizeEvent *event);
	void closeEvent(QCloseEvent *event);
	bool eventFilter(QObject *obj, QEvent *event);
	float getImageScaleFactor();
	void updateZoomBox();
	void updateZoomBoxManually(int zoom);

	void on_action_Open_triggered();
	void on_action_Save_triggered();
	void on_action_Close_triggered();
	void on_action_Quit_triggered();
	void on_action_Adapt_Zoom_triggered();
	void on_action_Zoom_Out_triggered();
	void on_action_Zoom_In_triggered();
	void on_action_Original_Size_triggered();
	void on_action_Pixel_Info_triggered();
	void on_action_Contrast_Brightness_triggered();
	void on_action_Grayscale_triggered();
	void on_action_Sharpen_triggered();
	void on_action_Smoothing_triggered();
	void on_action_Morphology_triggered();
	void on_action_About_Qt_triggered();
	void on_action_Negative_triggered();

private:
	// View
	Ui::MainWindow*			ui;
	QGraphicsPixmapItem*	mPixmapItem;
	QGraphicsScene			mScene;

	// Variables
	Controller*				mController;
	double					mScaleFactor;
	QLabel					mLoadTime;
	QLabel					mImageSize;
	QSpinBox				mZoomBox;

	// Dialogs
	GrayscaleFilterDialog*	mGrayscaleDialog;
	ContrastDialog*			mContrastDialog;
	NegativeFilterDialog*	mNegativeDialog;
	PixelInfoDialog*		mPixelInfoDialog;
	SmoothingFilterDialog*	mSmoothingDialog;

signals:
	void sigOpenGrayscaleDialog();
	void sigOpenContrastDialog();
	void sigOpenNegativeDialog();
	void sigOpenPixelInfoDialog( const QPixmap& clip, const QPointF& mousePos );
	void sigOpenSmoothingDialog();
 };

#endif // MAINWINDOW_H
