#ifndef SAMPLERWINDOW_H
#define SAMPLERWINDOW_H

#include <QComboBox>
#include <QMainWindow>
#include <QMap>
#include <QSound>

QT_BEGIN_NAMESPACE
namespace Ui { class SamplerWindow; }
QT_END_NAMESPACE



class SamplerWindow : public QMainWindow
{
    Q_OBJECT

public:
    SamplerWindow(QWidget *parent = nullptr);
    ~SamplerWindow();

private slots:
    void on_sample0Btn_released();

    void on_sample0Btn_pressed();

    void on_sample1Btn_pressed();

    void on_sample1Btn_released();

    void on_sample2Btn_pressed();

    void on_sample2Btn_released();

    void on_sample3Btn_pressed();

    void on_sample3Btn_released();

    void on_sample4Btn_pressed();

    void on_sample4Btn_released();

    void on_sample5Btn_pressed();

    void on_sample5Btn_released();

    void on_sample6Btn_pressed();

    void on_sample6Btn_released();

    void on_sample7Btn_pressed();

    void on_sample7Btn_released();

    void on_nextSetBtn_pressed();

    void on_prevSetBtn_pressed();

private:
    void PlaySample(int sampleNum, bool up=false);
    QString LoadSample(int sampleNum);
    Ui::SamplerWindow *ui;

    QMap<int,QSound*> _sounds;
    QMap<int,QComboBox*> _modes;
    int _sampleSet = 0;
};
#endif // SAMPLERWINDOW_H
