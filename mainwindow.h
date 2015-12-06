#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QSpinBox>

#include <Mediator.h>
#include <GrayscaleDialog.h>
#include <ContrastDialog.h>

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


private:
	// View
	Ui::MainWindow* ui;
    QGraphicsPixmapItem* mPixmapItem;
	QGraphicsScene mScene;

	// Variables
	Mediator* mMediator;
	double mScaleFactor;
	QLabel mLoadTime;
	QLabel mImageSize;
	QSpinBox mZoomBox;

	// Dialogs
	GrayscaleDialog* mGrayscaleDialog;
	ContrastDialog* mContrastDialog;

signals:
	void sigOpenGrayscaleDialog();
	void sigOpenContrastDialog();
 };

#endif // MAINWINDOW_H
