#ifndef PRINTLOG_H
#define PRINTLOG_H

/***************************************************
 *
 * how to use it
 * m_pPrintLog         = PrintLog::getInstance();
 * m_pPrintLog->write_log_every_day("on_write_clicked","333","_write");
 *
 * *************************************************/
#include "printlog_global.h"

#include <QDateTime>
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QCoreApplication>

class PRINTLOGSHARED_EXPORT PrintLog
{
    public:
        static PrintLog* getInstance();
        //-- This function is called by the front end.--
        void        write_log_every_day(QString fun_name,QString log_info,QString log_file_name,bool is_qdebug = true);

    private:
        PrintLog();
        //--The process of adding data to a file.--
        void        write_into_log_file(QString dir_name,QString file_name,QString info);
        //--Determine if the folder exists.--
        bool        isDirExist(QString fullPath);
        //--Determine if the file exists.--
        bool        isFileExist(QString filePath,QString fileName);

    private:
        static  PrintLog*   p;

    signals:

    public slots:

};

#endif // PRINTLOG_H
