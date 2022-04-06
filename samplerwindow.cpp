#include "samplerwindow.h"
#include "ui_samplerwindow.h"

#include <QFileDialog>

SamplerWindow::SamplerWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SamplerWindow)
{
    ui->setupUi(this);

    ui->sample0Box->addItems({"one shot","hold","loop"});
    ui->sample1Box->addItems({"one shot","hold","loop"});
    ui->sample2Box->addItems({"one shot","hold","loop"});
    ui->sample3Box->addItems({"one shot","hold","loop"});
    ui->sample4Box->addItems({"one shot","hold","loop"});
    ui->sample5Box->addItems({"one shot","hold","loop"});
    ui->sample6Box->addItems({"one shot","hold","loop"});
    ui->sample7Box->addItems({"one shot","hold","loop"});

    _modes.insert(0,ui->sample0Box);
    _modes.insert(1,ui->sample1Box);
    _modes.insert(2,ui->sample2Box);
    _modes.insert(3,ui->sample3Box);
    _modes.insert(4,ui->sample4Box);
    _modes.insert(5,ui->sample5Box);
    _modes.insert(6,ui->sample6Box);
    _modes.insert(7,ui->sample7Box);
}

SamplerWindow::~SamplerWindow()
{
    delete ui;
}

void SamplerWindow::on_sample0Btn_pressed()
{
    int sampleNum = 0 + (_sampleSet * 8);
    if(_sounds.contains(sampleNum)){
        PlaySample(sampleNum);
    }
    else{
        ui->sample0Btn->setText(LoadSample(sampleNum));
    }
}

void SamplerWindow::on_sample0Btn_released()
{
    int sampleNum = 0 + (_sampleSet * 8);
    if(_sounds.contains(sampleNum)){
        PlaySample(sampleNum,true);
    }
}

void SamplerWindow::on_sample1Btn_pressed()
{
    int sampleNum = 1 + (_sampleSet * 8);
    if(_sounds.contains(sampleNum)){
        PlaySample(sampleNum);
    }
    else{
        ui->sample1Btn->setText(LoadSample(sampleNum));
    }
}


void SamplerWindow::on_sample1Btn_released()
{
    int sampleNum = 1 + (_sampleSet * 8);
    if(_sounds.contains(sampleNum)){
        PlaySample(sampleNum,true);
    }
}


void SamplerWindow::on_sample2Btn_pressed()
{
    int sampleNum = 2 + (_sampleSet * 8);
    if(_sounds.contains(sampleNum)){
        PlaySample(sampleNum);
    }
    else{
        ui->sample2Btn->setText(LoadSample(sampleNum));
    }
}


void SamplerWindow::on_sample2Btn_released()
{
    int sampleNum = 2 + (_sampleSet * 8);
    if(_sounds.contains(sampleNum)){
        PlaySample(sampleNum,true);
    }
}


void SamplerWindow::on_sample3Btn_pressed()
{
    int sampleNum = 3 + (_sampleSet * 8);
    if(_sounds.contains(sampleNum)){
        PlaySample(sampleNum);
    }
    else{
        ui->sample3Btn->setText(LoadSample(sampleNum));
    }
}


void SamplerWindow::on_sample3Btn_released()
{
    int sampleNum = 3 + (_sampleSet * 8);
    if(_sounds.contains(sampleNum)){
        PlaySample(sampleNum,true);
    }
}


void SamplerWindow::on_sample4Btn_pressed()
{
    int sampleNum = 4 + (_sampleSet * 8);
    if(_sounds.contains(sampleNum)){
        PlaySample(sampleNum);
    }
    else{
        ui->sample4Btn->setText(LoadSample(sampleNum));
    }
}


void SamplerWindow::on_sample4Btn_released()
{
    int sampleNum = 4 + (_sampleSet * 8);
    if(_sounds.contains(sampleNum)){
        PlaySample(sampleNum,true);
    }
}


void SamplerWindow::on_sample5Btn_pressed()
{
    int sampleNum = 5 + (_sampleSet * 8);
    if(_sounds.contains(sampleNum)){
        PlaySample(sampleNum);
    }
    else{
        ui->sample5Btn->setText(LoadSample(sampleNum));
    }
}


void SamplerWindow::on_sample5Btn_released()
{
    int sampleNum = 5 + (_sampleSet * 8);
    if(_sounds.contains(sampleNum)){
        PlaySample(sampleNum,true);
    }
}


void SamplerWindow::on_sample6Btn_pressed()
{
    int sampleNum = 6 + (_sampleSet * 8);
    if(_sounds.contains(sampleNum)){
        PlaySample(sampleNum);
    }
    else{
        ui->sample6Btn->setText(LoadSample(sampleNum));
    }
}


void SamplerWindow::on_sample6Btn_released()
{
    int sampleNum = 6 + (_sampleSet * 8);
    if(_sounds.contains(sampleNum)){
        PlaySample(sampleNum,true);
    }
}


void SamplerWindow::on_sample7Btn_pressed()
{
    int sampleNum = 7 + (_sampleSet * 8);
    if(_sounds.contains(sampleNum)){
        PlaySample(sampleNum);
    }
    else{
        ui->sample7Btn->setText(LoadSample(sampleNum));
    }
}


void SamplerWindow::on_sample7Btn_released()
{
    int sampleNum = 7 + (_sampleSet * 8);
    if(_sounds.contains(sampleNum)){
        PlaySample(sampleNum,true);
    }
}

void SamplerWindow::PlaySample(int sampleNum, bool up)
{
    int sampleNumWoSet = sampleNum - (_sampleSet * 8);
    if(_sounds.contains(sampleNum)){
        if(_modes.contains(sampleNumWoSet)){
            if(_modes.value(sampleNumWoSet)->currentIndex() == 0){
                _sounds.value(sampleNum)->setLoops(1);
                _sounds.value(sampleNum)->play();
            }
            else if(_modes.value(sampleNumWoSet)->currentIndex() == 1){
                if(up){
                    _sounds.value(sampleNum)->stop();
                }
                else{
                    _sounds.value(sampleNum)->setLoops(QSound::Infinite);
                    _sounds.value(sampleNum)->play();
                }
            }
            else{
                if(!_sounds.value(sampleNum)->isFinished()){
                    _sounds.value(sampleNum)->stop();
                }
                else{
                    _sounds.value(sampleNum)->setLoops(QSound::Infinite);
                    _sounds.value(sampleNum)->play();
                }
            }
        }
    }
    else{
        qDebug("Error - no sample");
    }
}

QString SamplerWindow::LoadSample(int sampleNum)
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open Wave file"), "", tr("Wav Files (*.wav)"));
    if(!fileName.isEmpty()){
    if(_sounds.contains(sampleNum)){
            _sounds.remove(sampleNum);
         }
        _sounds.insert(sampleNum,new QSound(fileName));
        return fileName;
    }
    return "";
}


void SamplerWindow::on_nextSetBtn_pressed()
{
    _sampleSet++;
    ui->setLcdNumber->display(_sampleSet);
}


void SamplerWindow::on_prevSetBtn_pressed()
{
    _sampleSet--;
    if(_sampleSet < 0)
        _sampleSet = 0;

    ui->setLcdNumber->display(_sampleSet);
}

