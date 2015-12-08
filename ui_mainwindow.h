/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_Open;
    QAction *action_Pixel_Info;
    QAction *action_Save;
    QAction *action_Close;
    QAction *action_Grayscale;
    QAction *action_Quit;
    QAction *action_Zoom_In;
    QAction *action_Zoom_Out;
    QAction *action_Contrast_Brightness;
    QAction *action_Sharpen;
    QAction *action_Smoothing;
    QAction *action_Adapt_Zoom;
    QAction *action_About;
    QAction *action_About_Qt;
    QAction *action_Negative;
    QAction *action_Original_Size;
    QAction *action_Transform;
    QAction *action_Morphology;
    QAction *action_Resize;
    QAction *action_Merge;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QGraphicsView *graphicsView;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuImage;
    QMenu *menuFilters;
    QMenu *menuView;
    QMenu *menuHelp;
    QStatusBar *statusBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(798, 674);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 175, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(127, 215, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(63, 195, 255, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(0, 87, 127, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(0, 117, 170, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        QBrush brush7(QColor(255, 255, 220, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        MainWindow->setPalette(palette);
        MainWindow->setMouseTracking(false);
        MainWindow->setAutoFillBackground(true);
        MainWindow->setTabShape(QTabWidget::Rounded);
        MainWindow->setDockOptions(QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks);
        action_Open = new QAction(MainWindow);
        action_Open->setObjectName(QStringLiteral("action_Open"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/res/icon/open_folder.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Open->setIcon(icon);
        action_Pixel_Info = new QAction(MainWindow);
        action_Pixel_Info->setObjectName(QStringLiteral("action_Pixel_Info"));
        action_Pixel_Info->setEnabled(true);
        action_Save = new QAction(MainWindow);
        action_Save->setObjectName(QStringLiteral("action_Save"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/res/icon/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Save->setIcon(icon1);
        action_Close = new QAction(MainWindow);
        action_Close->setObjectName(QStringLiteral("action_Close"));
        action_Close->setEnabled(true);
        action_Grayscale = new QAction(MainWindow);
        action_Grayscale->setObjectName(QStringLiteral("action_Grayscale"));
        action_Quit = new QAction(MainWindow);
        action_Quit->setObjectName(QStringLiteral("action_Quit"));
        action_Zoom_In = new QAction(MainWindow);
        action_Zoom_In->setObjectName(QStringLiteral("action_Zoom_In"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/res/icon/zoom_out.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Zoom_In->setIcon(icon2);
        action_Zoom_Out = new QAction(MainWindow);
        action_Zoom_Out->setObjectName(QStringLiteral("action_Zoom_Out"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/res/icon/zoom_in.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Zoom_Out->setIcon(icon3);
        action_Contrast_Brightness = new QAction(MainWindow);
        action_Contrast_Brightness->setObjectName(QStringLiteral("action_Contrast_Brightness"));
        action_Sharpen = new QAction(MainWindow);
        action_Sharpen->setObjectName(QStringLiteral("action_Sharpen"));
        action_Sharpen->setEnabled(false);
        action_Smoothing = new QAction(MainWindow);
        action_Smoothing->setObjectName(QStringLiteral("action_Smoothing"));
        action_Smoothing->setEnabled(true);
        action_Adapt_Zoom = new QAction(MainWindow);
        action_Adapt_Zoom->setObjectName(QStringLiteral("action_Adapt_Zoom"));
        action_Adapt_Zoom->setCheckable(true);
        action_Adapt_Zoom->setChecked(true);
        action_About = new QAction(MainWindow);
        action_About->setObjectName(QStringLiteral("action_About"));
        action_About->setEnabled(false);
        action_About_Qt = new QAction(MainWindow);
        action_About_Qt->setObjectName(QStringLiteral("action_About_Qt"));
        action_Negative = new QAction(MainWindow);
        action_Negative->setObjectName(QStringLiteral("action_Negative"));
        action_Original_Size = new QAction(MainWindow);
        action_Original_Size->setObjectName(QStringLiteral("action_Original_Size"));
        action_Transform = new QAction(MainWindow);
        action_Transform->setObjectName(QStringLiteral("action_Transform"));
        action_Transform->setEnabled(false);
        action_Morphology = new QAction(MainWindow);
        action_Morphology->setObjectName(QStringLiteral("action_Morphology"));
        action_Morphology->setEnabled(false);
        action_Resize = new QAction(MainWindow);
        action_Resize->setObjectName(QStringLiteral("action_Resize"));
        action_Resize->setEnabled(false);
        action_Merge = new QAction(MainWindow);
        action_Merge->setObjectName(QStringLiteral("action_Merge"));
        action_Merge->setEnabled(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        QBrush brush8(QColor(200, 220, 255, 255));
        brush8.setStyle(Qt::SolidPattern);
        graphicsView->setBackgroundBrush(brush8);

        verticalLayout->addWidget(graphicsView);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 798, 26));
        menuBar->setAutoFillBackground(true);
        menuBar->setNativeMenuBar(false);
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuFile->setAutoFillBackground(true);
        menuImage = new QMenu(menuBar);
        menuImage->setObjectName(QStringLiteral("menuImage"));
        menuFilters = new QMenu(menuBar);
        menuFilters->setObjectName(QStringLiteral("menuFilters"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QStringLiteral("menuView"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setAutoFillBackground(true);
        MainWindow->setStatusBar(statusBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mainToolBar->sizePolicy().hasHeightForWidth());
        mainToolBar->setSizePolicy(sizePolicy);
        QPalette palette1;
        QBrush brush9(QColor(0, 170, 255, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::NoRole, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::NoRole, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::NoRole, brush9);
        mainToolBar->setPalette(palette1);
        mainToolBar->setAcceptDrops(false);
        mainToolBar->setLayoutDirection(Qt::LeftToRight);
        mainToolBar->setAutoFillBackground(true);
        mainToolBar->setMovable(true);
        mainToolBar->setAllowedAreas(Qt::LeftToolBarArea|Qt::RightToolBarArea|Qt::TopToolBarArea);
        mainToolBar->setIconSize(QSize(60, 60));
        mainToolBar->setFloatable(false);
        MainWindow->addToolBar(Qt::LeftToolBarArea, mainToolBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuImage->menuAction());
        menuBar->addAction(menuFilters->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(action_Open);
        menuFile->addAction(action_Save);
        menuFile->addAction(action_Close);
        menuFile->addSeparator();
        menuFile->addAction(action_Quit);
        menuImage->addAction(action_Contrast_Brightness);
        menuImage->addAction(action_Pixel_Info);
        menuImage->addAction(action_Transform);
        menuImage->addAction(action_Resize);
        menuFilters->addAction(action_Grayscale);
        menuFilters->addAction(action_Negative);
        menuFilters->addAction(action_Smoothing);
        menuFilters->addAction(action_Sharpen);
        menuFilters->addAction(action_Morphology);
        menuView->addAction(action_Adapt_Zoom);
        menuView->addAction(action_Zoom_In);
        menuView->addAction(action_Zoom_Out);
        menuView->addAction(action_Original_Size);
        menuHelp->addAction(action_About);
        menuHelp->addAction(action_About_Qt);
        mainToolBar->addAction(action_Open);
        mainToolBar->addAction(action_Save);
        mainToolBar->addAction(action_Zoom_Out);
        mainToolBar->addAction(action_Zoom_In);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QString());
        action_Open->setText(QApplication::translate("MainWindow", "&Open", 0));
        action_Open->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0));
        action_Pixel_Info->setText(QApplication::translate("MainWindow", "Pixel Info", 0));
        action_Pixel_Info->setShortcut(QApplication::translate("MainWindow", "Ctrl+'", 0));
        action_Save->setText(QApplication::translate("MainWindow", "&Save", 0));
        action_Save->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0));
        action_Close->setText(QApplication::translate("MainWindow", "&Close", 0));
        action_Close->setShortcut(QApplication::translate("MainWindow", "Ctrl+W", 0));
        action_Grayscale->setText(QApplication::translate("MainWindow", "Grayscale", 0));
        action_Quit->setText(QApplication::translate("MainWindow", "Quit", 0));
        action_Zoom_In->setText(QApplication::translate("MainWindow", "Zoom In", 0));
        action_Zoom_In->setShortcut(QApplication::translate("MainWindow", "Ctrl++", 0));
        action_Zoom_Out->setText(QApplication::translate("MainWindow", "Zoom Out", 0));
        action_Zoom_Out->setShortcut(QApplication::translate("MainWindow", "Ctrl+-", 0));
        action_Contrast_Brightness->setText(QApplication::translate("MainWindow", "Contrast/Brightness", 0));
        action_Sharpen->setText(QApplication::translate("MainWindow", "Sharp", 0));
        action_Smoothing->setText(QApplication::translate("MainWindow", "Smooth", 0));
        action_Adapt_Zoom->setText(QApplication::translate("MainWindow", "Fit in View", 0));
        action_Adapt_Zoom->setShortcut(QApplication::translate("MainWindow", "Ctrl+0", 0));
        action_About->setText(QApplication::translate("MainWindow", "About", 0));
        action_About_Qt->setText(QApplication::translate("MainWindow", "About Qt", 0));
        action_Negative->setText(QApplication::translate("MainWindow", "Negative", 0));
        action_Original_Size->setText(QApplication::translate("MainWindow", "Original Size", 0));
        action_Transform->setText(QApplication::translate("MainWindow", "Transform", 0));
        action_Morphology->setText(QApplication::translate("MainWindow", "Morphology", 0));
#ifndef QT_NO_TOOLTIP
        action_Morphology->setToolTip(QApplication::translate("MainWindow", "Morphology Operators", 0));
#endif // QT_NO_TOOLTIP
        action_Resize->setText(QApplication::translate("MainWindow", "Resize", 0));
        action_Merge->setText(QApplication::translate("MainWindow", "Merge", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "&File", 0));
        menuImage->setTitle(QApplication::translate("MainWindow", "&Image", 0));
        menuFilters->setTitle(QApplication::translate("MainWindow", "Fi&lters", 0));
        menuView->setTitle(QApplication::translate("MainWindow", "&View", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "&Help", 0));
        mainToolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
