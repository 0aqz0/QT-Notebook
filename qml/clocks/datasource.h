#ifndef DATASOURCE_H
#define DATASOURCE_H

#include <QObject>

class DataSource : public QObject
{
    Q_OBJECT
public:
    explicit DataSource(QObject *parent = Q_NULLPTR);
    Q_INVOKABLE int test(){return 1;}
    // international time
    Q_INVOKABLE int getUTCHours();
    Q_INVOKABLE int getUTCMinutes();
    Q_INVOKABLE int getUTCSeconds();
    // local time
    Q_INVOKABLE int getHours();
    Q_INVOKABLE int getMinutes();
    void activate_thread();
Q_SIGNALS:

private slots:

private:
    void updateTime();
    int UTCHours;
    int UTCMinutes;
    int UTCSeconds;
    int Hours;
    int Minutes;
};

#endif // DATASOURCE_H
