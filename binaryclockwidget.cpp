#include "binaryclockwidget.h"
#include "./ui_binaryclockwidget.h"
#include <QPainter>

BinaryClockWidget::BinaryClockWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BinaryClockWidget)
    , m_hRects(QVector<QRect>())
    , m_mRects(QVector<QRect>())
    , m_sRects(QVector<QRect>())
{
    ui->setupUi(this);

    this->setWindowTitle("Binary Clock Widget");
    this->setFixedSize(240, 95);

    initializeRects();
}

BinaryClockWidget::~BinaryClockWidget()
{
    delete ui;
}


void BinaryClockWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    QPen pen;
    pen.setColor(Qt::black);

    // Draw background.
    QPainter painter(this);
    painter.setPen(pen);
    painter.setBrush(QBrush(Qt::gray));
    painter.drawRect(this->rect());

    drawSectionSeparator(painter, pen, 30, 10, 30, 85);
    drawRects(painter, m_hRects);
    drawSectionSeparator(painter, pen, 90, 10, 90, 85);
    drawRects(painter, m_mRects);
    drawSectionSeparator(painter, pen, 150, 10, 150, 85);
    drawRects(painter, m_sRects);
    drawSectionSeparator(painter, pen, 210, 10, 210, 85);
}

void BinaryClockWidget::initializeRects()
{
    m_hRects = {
        {40, 10, RECT_WIDTH, RECT_WIDTH}, {65, 10, RECT_WIDTH, RECT_WIDTH},
        {40, 30, RECT_WIDTH, RECT_WIDTH}, {65, 30, RECT_WIDTH, RECT_WIDTH},
        {40, 50, RECT_WIDTH, RECT_WIDTH}, {65, 50, RECT_WIDTH, RECT_WIDTH},
        {40, 70, RECT_WIDTH, RECT_WIDTH}, {65, 70, RECT_WIDTH, RECT_WIDTH},
    };

    m_mRects = {
        {100, 10, RECT_WIDTH, RECT_WIDTH}, {125, 10, RECT_WIDTH, RECT_WIDTH},
        {100, 30, RECT_WIDTH, RECT_WIDTH}, {125, 30, RECT_WIDTH, RECT_WIDTH},
        {100, 50, RECT_WIDTH, RECT_WIDTH}, {125, 50, RECT_WIDTH, RECT_WIDTH},
        {100, 70, RECT_WIDTH, RECT_WIDTH}, {125, 70, RECT_WIDTH, RECT_WIDTH},
    };

    m_sRects = {
        {160, 10, RECT_WIDTH, RECT_WIDTH}, {185, 10, RECT_WIDTH, RECT_WIDTH},
        {160, 30, RECT_WIDTH, RECT_WIDTH}, {185, 30, RECT_WIDTH, RECT_WIDTH},
        {160, 50, RECT_WIDTH, RECT_WIDTH}, {185, 50, RECT_WIDTH, RECT_WIDTH},
        {160, 70, RECT_WIDTH, RECT_WIDTH}, {185, 70, RECT_WIDTH, RECT_WIDTH},
    };
}

void BinaryClockWidget::drawSectionSeparator(QPainter& painter, QPen& pen,
                                             int x1, int y1, int x2, int y2) const
{
    pen.setWidth(2);
    painter.setPen(pen);
    painter.drawLine(x1, y1, x2, y2);

    // Restore pen default width.
    pen.setWidth(1);
    painter.setPen(pen);
}

void BinaryClockWidget::drawRects(QPainter& painter, const QVector<QRect>& rects) const
{
    for (const auto& rect : rects)
        painter.drawRect(rect);
}
