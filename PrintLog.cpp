#include "PrintLog.h"


PrintLog::PrintLog()
{

}

PrintLog* PrintLog::p = NULL;
PrintLog* PrintLog::getInstance()
{
    if( p == NULL )
    {
        p = new PrintLog();
    }
    return p;
}

/************************************************************
 *
 * The interface to the print log for external calls.
 *
 * fun_name:function name
 * log_info:the information we will write into the file
 * log_file_name:this is log file name
 * is_qdebug:If true, we will print the information to the monitor,else not print.
 *
 ************************************************************/
void PrintLog::write_log_every_day(QString fun_name,QString log_info,QString log_file_name,bool is_qdebug)
{
    QDateTime time = QDateTime::currentDateTime();
    QString curr_time = time.toString("yyyy-MM-dd hh:mm:ss");
    QString debug_info = "[" + curr_time + "]" + "[" + fun_name + "] " + log_info;
    if(is_qdebug)
    {
        qDebug() << debug_info;
    }

    QString dir_name = time.toString("yyyy_MM_dd");
    QString file_name = log_file_name + "_" + dir_name + ".log";
    write_into_log_file(dir_name,file_name,debug_info);

}

/************************************************************
 *
 * step:
 * 1:Determine if the folder exists.
 * 2:Determine if the file exists.
 * 3:Write the information to the log file.
 *
 * dir_name : this is dir name
 * file_name : this is file name
 * info : this is debug info
 *
 ************************************************************/
void PrintLog::write_into_log_file(QString dir_name,QString file_name,QString info)
{
    QString url_dir = QCoreApplication::applicationDirPath() + "/log/" + dir_name;//set log dir path
    QString url_file = url_dir  + "/" + file_name ;//set file path
    if(isDirExist(url_dir))//Determine if the folder exists.
    {
        if(isFileExist(url_dir,file_name))//Determine if the file exists.
        {
            QFile file(url_file);
            QTextStream stream( &file );
           if ( file.open(QIODevice::WriteOnly|QIODevice::Append) )//Append data to log
           {
               stream << info << "\n";
               file.close();
           }
        }
    }
}

/************************************************************
 *
 * Create multi-level directory
 *
 ************************************************************/
bool PrintLog::isDirExist(QString fullPath)
{
    QDir dir(fullPath);
    if(dir.exists())
    {
      return true;
    }
    else
    {
       bool ok = dir.mkpath(fullPath);
       return ok;
    }
}

/************************************************************
 *
 * Create a file
 * step:
 * 1:Set the program execution path to the path.
 * 2:Check that the file exists.if true return.
 * 3:Create a file in the path
 * 4:Sets the program's current path to its original path.
 *
 ************************************************************/
bool PrintLog::isFileExist(QString filePath,QString fileName)
{
   QDir     tempDir;
   QString  currentDir = tempDir.currentPath();// get current dir
   QFile *  tempFile = new QFile; // init Qfile
   //step1
   tempDir.setCurrent(filePath);
   //step2
   if(tempFile->exists(fileName))
   {
        return true;
   }
   //step3
   tempFile->setFileName(fileName);
   //step4
   tempDir.setCurrent(currentDir);
   return true;
}
