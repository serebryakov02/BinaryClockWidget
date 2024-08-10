#ifndef BINARYCLOCKWIDGET_H
#define BINARYCLOCKWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class BinaryClockWidget;
}
QT_END_NAMESPACE

class BinaryClockWidget : public QWidget
{
    Q_OBJECT

public:
    BinaryClockWidget(QWidget *parent = nullptr);
    ~BinaryClockWidget();

    // QWidget interface
protected:
    virtual void paintEvent(QPaintEvent *event) override;

private:
    Ui::BinaryClockWidget *ui;

    static constexpr int RECT_WIDTH = 15;
    QVector<QRect> m_hRects;
    QVector<QRect> m_mRects;
    QVector<QRect> m_sRects;
    void initializeRects();

    void drawSectionSeparator(QPainter& painter, QPen& pen,
                              int x1, int y1, int x2, int y2) const;
    void drawRects(QPainter& painter, const QVector<QRect>& rects) const;
};

#endif // BINARYCLOCKWIDGET_H
