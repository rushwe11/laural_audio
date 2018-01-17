#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QByteArray>
//#include <SoundTouch.h>
#include <qaudioinput.h>
#include<qaudiooutput.h>
#include <QBuffer>

namespace Ui {
    class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void initializeAudio();
    void createAudioInput();
    void createAudioOutput();

    int ApplyVolumeToSample(short iSample);

private slots:
    void readMore();
    void on_pushButton_clicked();
    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    QAudioDeviceInfo m_Inputdevice;
    QAudioDeviceInfo m_Outputdevice;
    QAudioFormat m_format;
    QAudioInput *m_audioInput;
    QAudioOutput *m_audioOutput;
    QIODevice *m_input;
    QIODevice *m_output;
    QByteArray m_buffer;
    int m_iVolume;

};

#endif // MAINWINDOW_H
