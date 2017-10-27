#include "mainwindow.h"
#include <QPainter>
#include <QColor>
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);

    shape = Line;
    color = penColorLabel->palette().color(QPalette::Window);
    Qt::PenStyle style = Qt::SolidLine;
    cap = Qt::SquareCap;
    join = Qt::BevelJoin;
    pen = QPen(color, 1, style, cap, join);

    brush_color = brashColorLabel->palette().color(QPalette::Window);
    brush_style = Qt::SolidPattern;
    brush = QBrush(brush_color, brush_style);
}

MainWindow::~MainWindow()
{
}

void MainWindow::on_shapeCBX_currentIndexChanged(int index)
{
    shape = (Shape)index;
    update();
}

void MainWindow::on_changePenColorBTN_clicked()
{
    color = QColorDialog::getColor(static_cast<int>(Qt::blue));
    penColorLabel->setPalette(QPalette(color));

    pen.setColor(color);
    update();
}

void MainWindow::on_penWidth_valueChanged(int value)
{
    //pen = QPen(color, value, style, cap, join);
    pen.setWidth(value);
    update();
}

void MainWindow::on_penStyleCBX_currentIndexChanged(int index)
{
    switch (index) {
        case 0:
            style = Qt::SolidLine;
            break;
        case 1:
            style = Qt::DashLine;
            break;
        case 2:
            style = Qt::DotLine;
            break;
        case 3:
            style = Qt::DashDotLine;
            break;
        case 4:
            style = Qt::DashDotDotLine;
            break;
        case 5:
            style = Qt::CustomDashLine;
            break;
        default:
            break;
    }

    pen.setStyle(style);
    update();
}

void MainWindow::on_penCapCBX_currentIndexChanged(int index)
{
    switch (index) {
        case 0:
            cap = Qt::SquareCap;
            break;
        case 1:
            cap = Qt::FlatCap;
            break;
        case 2:
            cap = Qt::RoundCap;
            break;
        default:
            break;
    }

    pen.setCapStyle(cap);
    update();
}

void MainWindow::on_penJoinCBX_currentIndexChanged(int index)
{
    switch (index) {
        case 0:
            join = Qt::BevelJoin;
            break;
        case 1:
            join = Qt::MiterJoin;
            break;
        case 2:
            join = Qt::RoundJoin;
            break;
        default:
            break;
    }

    pen.setJoinStyle(join);
    update();
}

void MainWindow::on_fillModelCBX_currentIndexChanged(int index)
{
    switch (index) {
        case 0:
            fillRule = Qt::OddEvenFill;
            break;
        case 1:
            fillRule = Qt::WindingFill;
            break;
        default:
            break;
    }

    update();
}

void MainWindow::on_spreadEffectCBX_currentIndexChanged(int index)
{
    switch (index) {
        case 0:
            spread = QGradient::PadSpread;
            break;
        case 1:
            spread = QGradient::RepeatSpread;
            break;
        case 2:
            spread = QGradient::ReflectSpread;
            break;
        default:
            break;
    }

    update();
}

void MainWindow::on_changeBrashColorBTN_clicked()
{
    brush_color = QColorDialog::getColor(static_cast<int>(Qt::blue));
    brashColorLabel->setPalette(QPalette(brush_color));

    brush.setColor(brush_color);

    update();
}

void MainWindow::on_brashStyleCBX_currentIndexChanged(int index)
{
    switch (index) {
        case 0:
            brush_style = Qt::SolidPattern;
            break;
        case 1:
            brush_style = Qt::Dense1Pattern;
            break;
        case 2:
            brush_style = Qt::Dense2Pattern;
            break;
        case 3:
            brush_style = Qt::Dense3Pattern;
            break;
        case 4:
            brush_style = Qt::Dense4Pattern;
            break;
        case 5:
            brush_style = Qt::Dense5Pattern;
            break;
        case 6:
            brush_style = Qt::Dense6Pattern;
            break;
        case 7:
            brush_style = Qt::Dense7Pattern;
            break;
        case 8:
            brush_style = Qt::HorPattern;
            break;
        case 9:
            brush_style = Qt::VerPattern;
            break;
        case 10:
            brush_style = Qt::CrossPattern;
            break;
        case 11:
            brush_style = Qt::BDiagPattern;
            break;
        case 12:
            brush_style = Qt::FDiagPattern;
            break;
        case 13:
            brush_style = Qt::DiagCrossPattern;
            break;
        case 14:
            brush_style = Qt::LinearGradientPattern;
            break;
        case 15:
            brush_style = Qt::ConicalGradientPattern;
            break;
        case 16:
            brush_style = Qt::RadialGradientPattern;
            break;
        case 17:
            brush_style = Qt::TexturePattern;
            break;

        default:
            break;
    }

    if(brush_style == Qt::LinearGradientPattern)
    {
        QLinearGradient linearGradient(0,0,400,400);
        linearGradient.setColorAt(0.0,Qt::white);
        linearGradient.setColorAt(0.2,color);
        linearGradient.setColorAt(1.0,Qt::black);
        linearGradient.setSpread(spread);
        brush = linearGradient;
    }
    else if(brush_style == Qt::RadialGradientPattern)
    {
        QRadialGradient radialGradient(200,200,150,150,100);
        radialGradient.setColorAt(0.0,Qt::white);
        radialGradient.setColorAt(0.2,color);
        radialGradient.setColorAt(1.0,Qt::black);
        radialGradient.setSpread(spread);
        brush = radialGradient;
    }
    else if(brush_style == Qt::ConicalGradientPattern)
    {
        QConicalGradient conicalGradient(200,200,30);
        conicalGradient.setColorAt(0.0,Qt::white);
        conicalGradient.setColorAt(0.2,color);
        conicalGradient.setColorAt(1.0,Qt::black);
        brush = conicalGradient;
    }
    else if(brush_style == Qt::TexturePattern)
    {
        brush = QBrush(QPixmap(":/img/pic.jpg"));
    }
    else
    {
        brush = QBrush(brush_color, brush_style);
    }

    //brush.setStyle(brush_style);
    update();
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.setPen(pen);
    p.setBrush(brush);

    QRect rect(50,100,300,200);

    static const QPoint points[4]=
    {
        QPoint(150,100),
        QPoint(300,150),
        QPoint(350,250),
        QPoint(100,300)
    };
    int startAngle =30*16;
    int spanAngle =120*16;

    QPainterPath path;
    path.addRect(150,150,100,100);
    path.moveTo(100,100);
    path.cubicTo(300,100,200,200,300,300);
    path.cubicTo(100,300,200,200,100,100);
    path.setFillRule(fillRule);

    switch(shape)
    {
        case Line:                                         	//直线
            p.drawLine(rect.topLeft(),rect.bottomRight());
            break;
        case Rectangle:                                    	//长方形
            p.drawRect(rect);
            break;
        case RoundRect:                                    	//圆角方形
            p.drawRoundRect(rect);
            break;
        case Ellipse:                                      	//椭圆形
            p.drawEllipse(rect);
            break;
        case Polygon:                                      	//多边形
            p.drawPolygon(points,4);
            break;
        case Polyline:                                      //多边线
            p.drawPolyline(points,4);
            break;
        case Points:                                      	//点
            p.drawPoints(points,4);
            break;
        case Arc:                                          	//弧
            p.drawArc(rect,startAngle,spanAngle);
            break;
        case Path:                                         	//路径
            p.drawPath(path);
            break;
        case Text:                                        	//文字
            p.drawText(rect,Qt::AlignCenter,tr("Hello Qt!"));
            break;
        case Pixmap:                                      	//图片
            p.drawPixmap(150,150,QPixmap(":/img/pic.jpg"));
            break;
        default:
            break;
    }
}
