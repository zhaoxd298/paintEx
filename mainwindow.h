#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPen>
#include <QBrush>
#include "ui_mainwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public Ui::MainWindow
{
    Q_OBJECT

public:
    enum Shape{Line,Rectangle,RoundRect,Ellipse,Polygon,Polyline,Points,Arc,Path,Text,Pixmap};
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void paintEvent(QPaintEvent *);

private slots:
    void on_shapeCBX_currentIndexChanged(int index);
    void on_changePenColorBTN_clicked();
    void on_penWidth_valueChanged(int value);
    void on_penStyleCBX_currentIndexChanged(int index);
    void on_penCapCBX_currentIndexChanged(int index);
    void on_penJoinCBX_currentIndexChanged(int index);
    void on_fillModelCBX_currentIndexChanged(int index);
    void on_spreadEffectCBX_currentIndexChanged(int index);
    void on_changeBrashColorBTN_clicked();
    void on_brashStyleCBX_currentIndexChanged(int index);

private:
    QPen pen;
    QBrush brush;
    Shape shape;
    Qt::FillRule fillRule;
    QGradient::Spread spread;

    QColor color;
    QColor brush_color;
    Qt::PenStyle style;
    Qt::BrushStyle brush_style;
    Qt::PenCapStyle cap;
    Qt::PenJoinStyle join;
};

#endif // MAINWINDOW_H
