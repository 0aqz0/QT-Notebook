#include "datasource.h"
#include <thread>
#include <ctime>

DataSource::DataSource(QObject *parent) : QObject(parent)
{
    UTCHours = 0;
    UTCMinutes = 0;
    UTCSeconds = 0;
    Hours = 0;
    Minutes = 0;
}

int DataSource::getUTCHours()
{
    return UTCHours;
}

int DataSource::getUTCMinutes()
{
    return UTCMinutes;
}

int DataSource::getUTCSeconds()
{
    return UTCSeconds;
}

int DataSource::getHours()
{
    return Hours;
}

int DataSource::getMinutes()
{
    return Minutes;
}

void DataSource::updateTime()
{
    while(true)
    {
        // current time based on the current system
        time_t now = time(0);

        // update local time
        char* dt = ctime(&now);

        // update UTC time
        tm *gmtm = gmtime(&now);
        UTCHours = gmtm->tm_hour;
        UTCMinutes = gmtm->tm_min;
        UTCSeconds = gmtm->tm_sec;
    }
}

void DataSource::activate_thread()
{
    std::thread thread1([this] {updateTime();});
    thread1.detach();
}


