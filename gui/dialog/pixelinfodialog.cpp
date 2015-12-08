#include "PixelInfoDialog.h"
#include "ui_pixelinfodialog.h"

#define ZOOM_DIM_X 25
#define ZOOM_DIM_Y 25
#define ZOOM_X 7
#define ZOOM_Y 7

PixelInfoDialog::PixelInfoDialog(QWidget *parent) : QDialog(parent), ui(new Ui::PixelInfoDialog)
{
    ui->setupUi(this);
    ui->graphicsView->setScene( &mScene );
	mPixmapItem = mScene.addPixmap( QPixmap( ZOOM_DIM_X, ZOOM_DIM_Y ));
    ui->graphicsView->scale( ZOOM_X, ZOOM_Y );
    ui->graphicsView->setMinimumWidth( ZOOM_X * ZOOM_DIM_X + 5 );
    ui->graphicsView->setMinimumHeight( ZOOM_Y * ZOOM_DIM_Y + 5 );

    QPen pen = QPen( Qt::green );
    qreal penWidth = 0.16;
    pen.setWidth( penWidth );
    mScene.addRect( ZOOM_DIM_X/2 - penWidth, ZOOM_DIM_Y/2 - penWidth, 1+2*penWidth, 1+2*penWidth, pen );
}

PixelInfoDialog::~PixelInfoDialog()
{
    delete ui;
}

int PixelInfoDialog::getWidthClip() const
{
    return ZOOM_DIM_X;
}

int PixelInfoDialog::getHeightClip() const
{
    return ZOOM_DIM_Y;
}


void PixelInfoDialog::updateClip(const QPixmap &clip, const QPointF mousePos)
{
	mPixmapItem->setPixmap( clip );
    QString txt = QString("%1, %2").arg( mousePos.x() ).arg( mousePos.y() );
    ui->leMousePos->setText( txt );

    QPoint center( ZOOM_DIM_X/2+1, ZOOM_DIM_Y/2+1 );
    /*
     * Pixmap è ottimizzata per la visualizzazione, quindi non possiede le info pixel per pixel
     * va' quindi trasformata in una Qimage per estrarre i dati interessati
    */
    QRgb mouseColor = clip.toImage().pixel( center );
    QString col = QString("R %1, G %2, B %3")
                    .arg( qRed( mouseColor ) )
                    .arg( qGreen( mouseColor ) )
                    .arg( qBlue( mouseColor ) );
    ui->leRgb->setText( col );
}
